# gol

A Game of Life implementation in C++

## Installation

Linux and macOS:

- Clone this repo:

```bash
git clone https://github.com/alex-laycalvert/gol
cd gol
```

- Build the project
```bash
make
```

- Profit
```bash
./build/gol [options]
```

## Usage

```bash
./gol [options]
```

### Options

- `-h`: Displays the help menu
- `-f <filename>`: File to read board from (***required***)
- `-n <number>`: Number of evolutions to go through (default: 5000)
- `-s <number>`: Speed of each evolution in milliseconds (default: 250)
- `-c <character>`: Character to print for occupied cells (accepts UNICODE, default: 'o')

### GOL Files

To create your own file for `gol` to run, create any text file and place non-empty characters
where you want occupied cells to be. Any character can be used and they do not have to be the
same. Some example files are included in the `examples/` directory with the `.gol` extension.
