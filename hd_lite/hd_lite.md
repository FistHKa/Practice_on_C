# hd-lite

**hd-lite** is a minimalist hexdump tool written in C, created as a hands-on project for learning the language’s core features and idioms. It displays the contents of files in hexadecimal and ASCII formats, similar to classic UNIX hexdump utilities, but with a focus on clarity and readability in both code and output.

## Features

- Reads and prints file contents in 16-byte lines

- Displays byte offsets in hexadecimal, aligned hex rows, and ASCII columns

- Robust error handling and user-friendly CLI usage

- Simple, portable C codebase — ideal for newcomers and learners

## Usage

./hd-lite <filename>

**Example output:**

00000000  48 65 6c 6c 6f 2c 20 77  6f 72 6c 64 21 0a        Hello, world!.

## Building

To build with gcc:

gcc -std=c99 -Wall -Wextra -o hd-lite hd-lite.c

## Project Goals

- **Educational:** Step-by-step learning of C fundamentals: CLI parsing, file I/O, data manipulation, formatting, and error handling.

## Future Ideas

- Support for reading from standard input

- Option to set bytes per line as a CLI parameter

- Better handling for large files (buffering strategies)

- Property-based and unit tests

## Why hd-lite?

hd-lite is intentionally “lite”—it’s not designed to be a full-featured hexdump replacement, but to serve as a practical, approachable entry point to C programming and the foundations of systems tooling.

## License

MIT License