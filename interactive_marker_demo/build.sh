#!/bin/bash

# 获取脚本所在目录
SCRIPT_DIR=$(cd "$(dirname "$0")" && pwd)
WORKSPACE_DIR=$(dirname "$SCRIPT_DIR")

# 编译交互式标记演示程序
echo "正在编译interactive_marker_demo..."
cd "$WORKSPACE_DIR" && colcon build --packages-select interactive_marker_demo

# 检查编译结果
if [ $? -eq 0 ]; then
    echo -e "\n编译成功！"
    echo "可以使用以下命令运行程序："
    echo "source install/setup.bash && ros2 run interactive_marker_demo interactive_marker_server"
else
    echo -e "\n编译失败，请检查错误信息！"
    exit 1
fi

# 添加执行权限
chmod +x "$SCRIPT_DIR/run.sh"
