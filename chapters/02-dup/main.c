#define _POSIX_C_SOURCE 200809L
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
    char path[] = "/tmp/linux-mentor-dup-XXXXXX";
    int fd = mkstemp(path);
    if (fd == -1) { perror("mkstemp"); return 1; }
    int separate = open(path, O_RDONLY);
    unlink(path); /* Son descriptor kapanınca geçici dosya da kaybolur. */
    int copy = dup(fd);
    int result = 1;
    if (separate == -1 || copy == -1) { perror("open/dup"); goto done; }
    if (write(fd, "abcdef", 6) != 6 || lseek(fd, 0, SEEK_SET) == -1) {
        perror("write/lseek"); goto done;
    }
    char a[3] = {0}, b[3] = {0}, c[3] = {0};
    if (read(fd, a, 2) != 2 || read(copy, b, 2) != 2 || read(separate, c, 2) != 2) {
        perror("read"); goto done;
    }
    printf("original=%s duplicate=%s independent=%s\n", a, b, c);
    result = 0;
done:
    if (copy != -1) close(copy);
    if (separate != -1) close(separate);
    close(fd);
    return result;
}
