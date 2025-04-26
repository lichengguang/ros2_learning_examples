#!/bin/bash

# 设置环境
SCRIPT_DIR=$(cd "$(dirname "$0")" && pwd)
WORKSPACE_DIR=$(dirname "$SCRIPT_DIR")
source /opt/ros/humble/setup.bash
source "$WORKSPACE_DIR/install/setup.bash"

# 显示C++示例菜单
echo "请选择要运行的C++示例:"
echo "1. Basic Controls (基本控制)"
echo "2. Cube (立方体)"
echo "3. Selection (选择)" 
echo "4. Simple Marker (简单标记)"
echo "5. Menu (菜单)"
echo "6. Pong Game (乒乓球游戏)"
read -p "输入选项(1-6): " choice

# 运行选择的示例
case $choice in
    1) ros2 run interactive_marker_tutorials basic_controls ;;
    2) ros2 run interactive_marker_tutorials cube ;;
    3) ros2 run interactive_marker_tutorials selection ;;
    4) ros2 run interactive_marker_tutorials simple_marker ;;
    5) ros2 run interactive_marker_tutorials menu ;;
    6) ros2 run interactive_marker_tutorials pong ;;
    *) echo "无效选项" ;;
esac
