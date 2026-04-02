# project_euler_cpp

[![CI](https://github.com/283586450/project_euler_cpp/actions/workflows/ci.yml/badge.svg)](https://github.com/283586450/project_euler_cpp/actions/workflows/ci.yml)

`project_euler_cpp` 是一个面向学习者的现代 C++23 Project Euler 解题仓库。

本项目强调三件事：

- 可靠的实现
- 清晰的数学推导
- 持续一致的中文文档

每道题都尽量写成一页可复用的学习笔记：

- 问题概述
- 核心思路与推导
- 一个主方案
- 简短的其他思路
- 现代 C++ 实现要点
- 复杂度分析
- 必要时补充图示或注记

## 原则

- 重质量，不重题量
- 每题保留一个主方案
- 有其他可行方案时，简要说明取舍
- 以 C++23 为构建基线，遵循现代 C++ 最佳实践
- 保持仓库可读、可维护、可扩展
- 默认使用中文撰写说明文档

## 仓库结构

- `include/`：共享公共头文件
- `src/`：共享实现代码
- `problems/`：每道 Euler 题一个可执行程序
- `tests/`：公共核心的轻量回归测试
- `docs/`：题解正文与模板
- `assets/`：图示和辅助素材
- `cmake/`：可复用的 CMake 辅助模块

## 题目索引

题目正文请统一查看 [docs/problems/README.md](docs/problems/README.md)，这里不再重复维护完整列表。

## 参与贡献

见 [CONTRIBUTING.md](CONTRIBUTING.md)，里面写了贡献流程、代码风格和题目提交清单。

如果你想提 bug 或建议新主题，可以直接使用 `.github/ISSUE_TEMPLATE/` 里的模板。

## 构建

配置：

```bash
cmake --preset debug
```

编译：

```bash
cmake --build --preset debug
```

测试：

```bash
ctest --preset debug
```

发布版使用对应的 `release` preset。

CI 还会对公共代码和题目源码执行 `clang-format` 与 `clang-tidy` 检查。

## 添加新题

1. 将 `problems/problem_template.cpp` 复制为新的零填充文件，例如 `problems/p0001.cpp`。
2. 在 `problems/CMakeLists.txt` 中使用 `project_euler_add_problem(...)` 注册。
3. 在 `docs/problems/` 中补写题解。
4. 如果需要图片，把素材放到 `assets/problems/<problem-id>/` 下。

## 许可证

本项目采用 MIT License。详见 [LICENSE](LICENSE)。
