package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func run() error {
	pid := "self"
	if len(os.Args) > 2 {
		return fmt.Errorf("usage: %s [PID|self]", os.Args[0])
	}
	if len(os.Args) == 2 {
		pid = os.Args[1]
	}
	if pid != "self" {
		n, err := strconv.Atoi(pid)
		if err != nil || n <= 0 {
			return fmt.Errorf("PID must be a positive integer or self")
		}
		pid = strconv.Itoa(n)
	}
	f, err := os.Open("/proc/" + pid + "/status")
	if err != nil {
		return err
	}
	defer f.Close()
	scanner := bufio.NewScanner(f)
	for scanner.Scan() {
		line := scanner.Text()
		key, _, _ := strings.Cut(line, ":")
		switch key {
		case "Name", "State", "Pid", "PPid", "Threads", "VmRSS":
			fmt.Println(line)
		}
	}
	return scanner.Err()
}

func main() {
	if err := run(); err != nil {
		fmt.Fprintln(os.Stderr, err)
		os.Exit(1)
	}
}
