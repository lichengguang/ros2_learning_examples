#!/bin/bash

# 获取脚本所在目录的父目录(工作空间目录)
SCRIPT_DIR=$(cd "$(dirname "$0")" && pwd)
WORKSPACE_DIR=$(dirname "$SCRIPT_DIR")

# Source ROS2 environment (保持绝对路径)
source /opt/ros/humble/setup.bash

# Source workspace (使用相对路径)
source "$WORKSPACE_DIR/install/setup.bash"

# Run the interactive marker server
ros2 run interactive_marker_demo interactive_marker_server
