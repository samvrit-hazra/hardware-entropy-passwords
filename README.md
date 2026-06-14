# Hardware Entropy Passwords
A password generator that uses CPU's **on-chip entropy sources**, such as thermal and electronic noise for highly random seed.

The program uses [RDRAND](https://en.wikipedia.org/wiki/RDRAND) CPU instruction which is supported by:
- Intel Ivy Bridge (3rd Generation Core) and newer processors
- AMD Bulldozer and newer processors

For unsupported systems, the program uses `/dev/random` or time-based seed.

(The following steps were tested only for Debian GNU/Linux)

[![asciicast](https://asciinema.org/a/WHln0xZYiH4k7m6t.svg)](https://asciinema.org/a/WHln0xZYiH4k7m6t)

## Usage

Default length (20)
```
passgen
```

Custom length
```
passgen <length>
```

## Installation

```
sudo apt update -y && sudo apt install git make -y
```

```
git clone https://github.com/samvrit-hazra/hardware-entropy-passwords
```

```
cd hardware-entropy-passwords/
```

```
make
```

```
sudo make install
```

## Uninstallation

```
sudo make uninstall
```

```
make clean
```

## Disclaimer

The project is entirely human-written with zero LLM-written code. However LLMs were used only for the purpose of technical reference and documentation.

This project is licensed under the GNU General Public License v3.0.

This software is distributed WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
