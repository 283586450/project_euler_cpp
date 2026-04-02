# Contributing

Thanks for helping improve `project_euler_cpp`.

## What This Repository Optimizes For

- Clear mathematical explanations
- One primary solution per problem
- Small reusable helpers when they genuinely improve multiple problems
- Cross-platform builds and tests
- Documentation that stays easy to read in Chinese by default

## Before Opening a PR

- Prefer small, focused changes.
- Keep the existing C++23 baseline and warning settings in mind.
- Add or update tests when behavior changes.
- Update the matching problem write-up when a problem implementation changes.
- Run the relevant build and test presets locally.

## Adding a New Problem

1. Copy `problems/problem_template.cpp` into a new zero-padded file such as `problems/p0006.cpp`.
2. Register the file in `problems/CMakeLists.txt` with `project_euler_add_problem(...)`.
3. Add the write-up in `docs/problems/`.
4. Add or update tests if the problem introduces reusable logic.
5. If the problem needs supporting images, place them under `assets/problems/<problem-id>/`.

## Code Style

- Follow the existing formatting and naming conventions.
- Prefer `constexpr` and `noexcept` when they accurately describe the code.
- Keep helper functions small and local when the logic is only used once.
- Avoid introducing extra abstraction unless it simplifies multiple problem solutions.

## Review Checklist

- Build passes on the supported platforms.
- Tests pass.
- Problem output matches the known answer.
- Documentation explains the reasoning, not just the final formula.

## Commit Messages

- Use short, descriptive commit messages.
- Mention the problem number when the change is problem-specific.

