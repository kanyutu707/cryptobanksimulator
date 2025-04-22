# Crypto Bank Simulation

This is a C++ console-based banking simulation project that allows users to:

- View account details
- Deposit and withdraw money
- Buy and sell cryptocurrencies
- Track transaction history

Cryptocurrency transactions include a random luck factor when purchasing to simulate market unpredictability.

## Features

- Account management (deposit, withdrawal)
- Basic crypto trading simulation
- Randomized buying success (based on luck)
- Persistent transaction history (with optional clear)
- Menu-based interface

## Technologies Used

- C++
- Standard Library (`<iostream>`, `<vector>`, `<ctime>`, etc.)
- CMake (for building the project)

---

## Getting Started

### Prerequisites

- A C++ compiler (e.g., `g++`, `clang++`)
- CMake 3.10 or higher

### Build Instructions

1. Clone the repository or copy the source code into a directory.

2. Create a `CMakeLists.txt` in the project root:

```cmake
cmake_minimum_required(VERSION 3.10)

project(project1)

set(CMAKE_CXX_STANDARD 14)

add_executable(CryptoBank main.cpp)
