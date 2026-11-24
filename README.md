# StudentAnalyzer

A simple C++17 command-line application for reading, validating, sorting, and analyzing student scores from CSV files.

## Features

- Read student records from CSV files.
- Validate score values (0–100).
- Handle invalid score formats and out-of-range integers.
- Sort students by score in descending order.
- Calculate maximum, minimum, and average scores.
- Export sorted results to a new CSV file.

## Technologies

- C++17
- STL (`vector`, `sort`, `string`)
- File I/O (`ifstream`, `ofstream`)
- Exception handling
- CMake
- Git

## Project Structure

```text
StudentAnalyzer/
├── CMakeLists.txt
├── include/
│   └── student.h
├── src/
│   ├── main.cpp
│   └── student.cpp
├── data/
│   └── student.csv
└── README.md
```

The `build/` and `output/` directories are generated locally and excluded from Git.

## Build

Requirements: a C++17-compatible compiler and CMake 3.16 or later.

```bash
cmake -S . -B build
cmake --build build
```

## Usage

Run the application from the project root directory:

```bash
mkdir -p output
./build/StudentAnalyzer
```

Input file: `data/student.csv`

Output file: `output/result.csv`

Example input:

```csv
name,score
Zhang,85
Li,92
Wang,76
```

Example output:

```csv
name,score
Li,92
Zhang,85
Wang,76
```

## Project Purpose

This project was developed as a C++ learning exercise to practice file operations, object-oriented programming, STL algorithms, exception handling, modular functions, and CMake-based builds.