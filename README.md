# WordTsar

WordTsar is a modernized text editor inspired by the classic WordStar. This guide will help you install and build WordTsar on Linux and macOS (Unix).

## Prerequisites

Before you begin, ensure you have the following installed:

- Qt (version 5 or higher)
- GNU Make
- C++ Compiler (GCC or Clang)

## Installation Instructions

### Clone the Repository

First, clone the repository:

```bash
git clone https://github.com/lvitals/WordTsar.git
cd WordTsar
```

### For Linux

1. **Install Required Packages**:

Depending on your Linux distribution, you can install the necessary packages using your package manager. For example, on Ubuntu:

```bash
sudo apt update sudo apt install qt5-qmake qtbase5-dev build-essential
```

2. **Run qmake**:

Generate the Makefile with qmake:

```bash
qmake wordtsar.pro
```

3. **Build the Project**:

Use make to compile the project:

```bash
make
```

4. **Run WordTsar**:

After a successful build, you can run WordTsar:

```bash
./WordTsar
```

### For macOS (Unix)

1. **Install Required Packages**:

You can use Homebrew to install the necessary packages:

```bash
brew install qt
```

2. **Run qmake**:

Generate the Makefile with qmake:

```bash
qmake wordtsar.pro
```

3. **Build the Project**:

Use make to compile the project:

```bash
make
```

4. **Run WordTsar**:

After a successful build, you can run WordTsar:

```bash
./WordTsar
```

## License

This project is licensed under the MIT License. See the LICENSE file for details.

## Contributions

Contributions are welcome! Please feel free to submit a pull request or open an issue if you find any bugs or have suggestions for improvements.