CC = gcc
CXX = g++
CFLAGS = -std=c17 -O2 -Wall -Wextra -Wpedantic -Werror
CXXFLAGS = -std=c++23 -O2 -Wall -Wextra -Wpedantic -Werror
C_SOURCES := $(wildcard chapters/*/main.c)
CXX_SOURCES := $(wildcard chapters/*/main.cpp)
GO_SOURCES := $(wildcard chapters/*/main.go)
TARGETS := $(patsubst chapters/%/main.c,build/%,$(C_SOURCES)) $(patsubst chapters/%/main.cpp,build/%,$(CXX_SOURCES)) $(patsubst chapters/%/main.go,build/%,$(GO_SOURCES))
.PHONY: all check clean
all: $(TARGETS)
build:
	mkdir -p $@
build/%: chapters/%/main.c | build
	$(CC) $(CFLAGS) $< -o $@
build/%: chapters/%/main.cpp | build
	$(CXX) $(CXXFLAGS) $< -o $@
build/%: chapters/%/main.go | build
	go build -o $@ $<
check: all
	bash scripts/check.sh
clean:
	rm -rf build
