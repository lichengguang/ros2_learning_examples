# ROS2 学习示例项目

## 项目概述
本仓库包含一系列工作中用到的ROS2技术，学习记录之 。

## 当前功能包
- `interactive_marker_tutorials`: 交互式标记教程(多个示例，主要研究C++实现)

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

# 构建功能包
cd ros2_learning_examples
bash interactive_marker_tutorials/build.sh

# 运行功能包
bash interactive_marker_tutorials/run.sh

# 可视化
rviz2
```

## 项目结构
```
ros2_learning_examples/
├── interactive_marker_tutorials/ # 交互标记教程(C++)
│   ├── README.md                 # 详细使用说明
│   └── build.sh                  # 编译脚本
│   └── run.sh                    # 运行脚本
│   └── ...                    
└── ...                           # 其他功能包
```
