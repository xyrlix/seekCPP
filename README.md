# seekCPP

一个基于 CMake 的模块化 C++ 项目框架，用于学习和练习 C++ 编程。

## 项目结构

```
seekCPP/
├── CMakeLists.txt              # 主构建配置
├── build.sh                    # 一键构建脚本
├── src/
│   └── main.cpp                # 程序入口
├── modules/                    # 模块目录
│   ├── core/                   # 核心模块
│   │   ├── CMakeLists.txt
│   │   ├── include/core/
│   │   │   └── hello.hpp
│   │   └── src/
│   │       └── hello.cpp
│   ├── math/                   # 数学模块
│   │   ├── CMakeLists.txt
│   │   ├── include/math/
│   │   │   └── calculator.hpp
│   │   └── src/
│   │       └── calculator.cpp
│   └── io/                     # IO模块
│       ├── CMakeLists.txt
│       ├── include/io/
│       │   └── printer.hpp
│       └── src/
│           └── printer.cpp
├── tests/                      # 测试目录
│   ├── CMakeLists.txt
│   └── test_hello.cpp
└── build/                      # 构建输出目录（自动生成）
```

## 模块说明

### core 模块

提供核心功能，包含问候语生成类。

### math 模块

提供数学计算功能，包含加减乘除运算类。

### io 模块

提供输入输出功能，包含控制台打印类。

## 环境要求

- Linux / WSL (Ubuntu 推荐)
- CMake 3.16+
- GCC 7+ 或 Clang 6+
- Make

## 快速开始

### 使用构建脚本（推荐）

```bash
# 一键编译并运行
./build.sh all

# 仅编译（Debug模式）
./build.sh build

# 仅编译（Release模式）
./build.sh build-release

# 清理构建目录
./build.sh clean

# 运行程序
./build.sh run

# 重新编译
./build.sh rebuild
```

### 手动编译

```bash
# 创建构建目录
mkdir -p build && cd build

# 配置项目（Debug模式）
cmake .. -DCMAKE_BUILD_TYPE=Debug

# 配置项目（Release模式）
cmake .. -DCMAKE_BUILD_TYPE=Release

# 编译
make -j4

# 运行
./seekCPP
```

## 构建脚本命令

| 命令                         | 说明                          |
| ---------------------------- | ----------------------------- |
| `./build.sh build`           | 编译项目（Debug模式）         |
| `./build.sh build-release`   | 编译项目（Release模式）       |
| `./build.sh clean`           | 清理构建目录                  |
| `./build.sh run`             | 运行程序                      |
| `./build.sh rebuild`         | 清理并重新编译（Debug模式）   |
| `./build.sh rebuild-release` | 清理并重新编译（Release模式） |
| `./build.sh all`             | 清理、编译并运行（Debug模式） |
| `./build.sh help`            | 显示帮助信息                  |

## 添加新模块

1. 在 `modules/` 目录下创建新模块文件夹：

```bash
mkdir -p modules/new_module/include/new_module modules/new_module/src
```

2. 创建模块的 `CMakeLists.txt`：

```cmake
file(GLOB_RECURSE MODULE_SOURCES src/*.cpp)
file(GLOB_RECURSE MODULE_HEADERS include/*.hpp)

add_library(new_module ${MODULE_SOURCES})

target_include_directories(new_module
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_options(new_module PRIVATE -Wall -Wextra -Wpedantic -g)
else()
    target_compile_options(new_module PRIVATE -O2)
endif()
```

3. 在主 `CMakeLists.txt` 中添加模块：

```cmake
add_subdirectory(modules/new_module)
```

4. 在主程序中链接新模块：

```cmake
target_link_libraries(seekCPP
    PRIVATE
        core
        math
        io
        new_module
)
```

## 测试

项目集成了 Google Test 测试框架。

### 安装 Google Test（可选）

```bash
sudo apt install libgtest-dev
```

### 运行测试

```bash
cd build
make test
# 或
./tests/run_tests
```

## 代码规范

- 使用 C++17 标准
- 使用命名空间隔离模块代码
- 头文件使用 include guard（`#ifndef ... #define ... #endif`）
- 源文件放在 `src/` 目录，头文件放在 `include/<module>/` 目录
- 编译选项：Debug 模式启用 `-Wall -Wextra -Wpedantic -g`，Release 模式启用 `-O2`

## 许可证

MIT License
