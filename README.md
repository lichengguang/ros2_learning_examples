# ROS2 学习示例项目

## 项目概述
本仓库包含一系列ROS2功能示例，用于演示各种ROS2特性和使用模式。

## 当前功能包
- `interactive_marker_demo`: 交互式标记控制示例

## 通用环境要求
- ROS2 Humble或更新版本
- 基础构建工具(colcon, cmake等)

## 构建与使用
```bash
# 克隆仓库
git clone https://github.com/your-repo/ros2_learning_examples.git

# 构建所有功能包
cd ros2_learning_examples
colcon build

# 运行特定功能包
source install/setup.bash
ros2 run [package_name] [executable_name]
```

## 项目结构
```
ros2_learning_examples/
├── interactive_marker_demo/  # 交互标记示例
│   ├── README.md             # 详细使用说明
│   └── ...                   # 功能包文件
└── ...                       # 其他功能包
```

## 贡献指南
欢迎通过Issue或Pull Request贡献新的示例功能包
