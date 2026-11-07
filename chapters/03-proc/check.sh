set -eu
build/03-proc self
if build/03-proc ../etc/passwd; then exit 1; fi
if build/03-proc 999999999; then exit 1; fi
