#!/bin/bash

PROJECT_NAME="seekCPP"
BUILD_DIR="build"
OUTPUT_DIR="output"

print_usage() {
    echo "用法: $0 [选项]"
    echo ""
    echo "选项:"
    echo "  build           编译项目（Debug模式）"
    echo "  build-release   编译项目（Release模式）"
    echo "  clean           清理构建和输出目录"
    echo "  run             运行程序"
    echo "  rebuild         清理并重新编译（Debug模式）"
    echo "  rebuild-release 清理并重新编译（Release模式）"
    echo "  all             清理、编译并运行（Debug模式）"
    echo "  help            显示帮助信息"
    echo ""
    echo "示例:"
    echo "  ./build.sh build        # 编译项目"
    echo "  ./build.sh run          # 运行程序"
    echo "  ./build.sh all          # 一键编译运行"
}

build_project() {
    local build_type="$1"
    echo "=== 正在配置项目 (${build_type}) ==="
    
    mkdir -p "${BUILD_DIR}"
    cd "${BUILD_DIR}" || exit 1
    
    if ! cmake .. "-DCMAKE_BUILD_TYPE=${build_type}"; then
        echo "CMake 配置失败"
        exit 1
    fi
    
    echo "=== 正在编译项目 ==="
    if ! make -j"$(nproc 2>/dev/null || echo 4)"; then
        echo "编译失败"
        exit 1
    fi
    
    cd ..
    echo "=== 编译成功 ==="
    echo "输出目录: ${OUTPUT_DIR}/"
    echo "  - 可执行文件: ${OUTPUT_DIR}/bin/"
    echo "  - 库文件: ${OUTPUT_DIR}/lib/"
}

clean_project() {
    echo "=== 正在清理构建和输出目录 ==="
    rm -rf "${BUILD_DIR}"
    rm -rf "${OUTPUT_DIR}"
    echo "=== 清理完成 ==="
}

run_project() {
    local exe_path="${OUTPUT_DIR}/bin/${PROJECT_NAME}"
    
    if [ ! -f "${exe_path}" ]; then
        echo "错误: 可执行文件不存在，请先编译"
        exit 1
    fi
    
    echo "=== 正在运行程序 ==="
    "${exe_path}"
    echo ""
    echo "=== 程序运行结束 ==="
}

case "$1" in
    build)
        build_project "Debug"
        ;;
    build-release)
        build_project "Release"
        ;;
    clean)
        clean_project
        ;;
    run)
        run_project
        ;;
    rebuild)
        clean_project
        build_project "Debug"
        ;;
    rebuild-release)
        clean_project
        build_project "Release"
        ;;
    all)
        clean_project
        build_project "Debug"
        run_project
        ;;
    help|--help|-h)
        print_usage
        ;;
    *)
        echo "错误: 未知选项 '$1'"
        echo ""
        print_usage
        exit 1
        ;;
esac