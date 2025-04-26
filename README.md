# ROS2 学习示例项目

## 项目概述
本仓库包含一系列工作中用到的ROS2技术，学习记录之 。

## 当前功能包
- `interactive_marker_demo`: 交互式标记控制示例

## 通用环境要求
- ubuntu22.04
- ROS2 Humble
一键安装:
```
wget http://fishros.com/install -O fishros && bash fishros 
```
## 构建与使用
```bash
# 克隆仓库
git clone https://github.com/lichengguang/ros2_learning_examples.git

# 构建制定功能包
cd ros2_learning_examples
./interactive_marker_demo/build.sh

# 运行指定功能包
./interactive_marker_demo/run.sh

# 可视化
rviz2
```

## 项目结构
```
ros2_learning_examples/
├── interactive_marker_demo/  # 交互标记示例
│   ├── README.md             # 详细使用说明
│   └── ...                   # 功能包文件
└── ...                       # 其他功能包
```
