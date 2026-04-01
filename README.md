# project_euler_cpp

[![CI](https://github.com/283586450/project_euler_cpp/actions/workflows/ci.yml/badge.svg)](https://github.com/283586450/project_euler_cpp/actions/workflows/ci.yml)

`project_euler_cpp` is a modern C++23 Project Euler solution repository aimed at learners.

The project focuses on high-quality implementations, clear mathematical reasoning, and
consistent documentation. Each problem is intended to read like a reusable study note:

- problem introduction
- core idea and derivation
- one best-practice primary solution
- short notes on alternate approaches
- modern C++ implementation
- complexity analysis
- supporting diagrams or visual notes when useful

## Principles

- Prefer quality over raw solution count
- Keep one primary solution per problem
- Add brief comparisons for alternate approaches when they exist
- Follow modern C++ best practices from C++11 through C++23, with C++23 as the build baseline
- Keep the repository readable, maintainable, and easy to extend
- Write documentation in Chinese by default

## Repository Layout

- `include/` shared public headers
- `src/` shared implementation code
- `problems/` one executable per Euler problem
- `tests/` lightweight smoke tests for the reusable core
- `docs/` problem write-ups and templates
- `assets/` diagrams and other supporting media
- `cmake/` reusable CMake helpers

## Implemented Problems

- [Problem 0001](docs/problems/0001.md)
- [Problem 0002](docs/problems/0002.md)
- [Problem 0003](docs/problems/0003.md)
- [Problem 0004](docs/problems/0004.md)
- [Problem 0005](docs/problems/0005.md)

## Build

Configure:

```bash
cmake --preset debug
```

Build:

```bash
cmake --build --preset debug
```

Test:

```bash
ctest --preset debug
```

Release builds use the matching `release` preset.

## Adding a Problem

1. Copy `problems/problem_template.cpp` to a new zero-padded file such as `problems/p0001.cpp`.
2. Register the new file in `problems/CMakeLists.txt` with `project_euler_add_problem(...)`.
3. Write the explanation in `docs/problems/`.
4. Add diagrams or figures under `assets/problems/<problem-id>/` if needed.

## License

This project is released under the MIT License. See [LICENSE](LICENSE).
