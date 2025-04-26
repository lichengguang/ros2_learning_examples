#include <memory>
#include <rclcpp/rclcpp.hpp>
#include <interactive_markers/interactive_marker_server.hpp>
#include <geometry_msgs/msg/pose.hpp>

using namespace std::placeholders;

class InteractiveMarkerNode : public rclcpp::Node {
public:
  InteractiveMarkerNode() : Node("interactive_marker_server") {
    server_ = std::make_shared<interactive_markers::InteractiveMarkerServer>(
      "interactive_marker",
      this->get_node_base_interface(),
      this->get_node_clock_interface(),
      this->get_node_logging_interface(),
      this->get_node_topics_interface(),
      this->get_node_services_interface()
    );

    createMarker();
  }

private:
  void createMarker() {
    visualization_msgs::msg::InteractiveMarker int_marker;
    int_marker.header.frame_id = "map";
    int_marker.name = "my_marker";
    int_marker.description = "2D Interactive Marker";
    int_marker.pose.position.z = 0; // Fixed Z position

    // Create a blue cube
    visualization_msgs::msg::Marker box_marker;
    box_marker.type = visualization_msgs::msg::Marker::CUBE;
    box_marker.scale.x = 0.5;
    box_marker.scale.y = 0.5;
    box_marker.scale.z = 0.5;
    box_marker.color.r = 0.0;
    box_marker.color.g = 0.0;
    box_marker.color.b = 1.0;
    box_marker.color.a = 1.0;

    // Create a non-interactive control which contains the box
    visualization_msgs::msg::InteractiveMarkerControl box_control;
    box_control.always_visible = true;
    box_control.markers.push_back(box_marker);
    int_marker.controls.push_back(box_control);

    // Add 3D controls
    add3DControls(int_marker);


    server_->insert(int_marker);
    server_->setCallback(int_marker.name, 
      std::bind(&InteractiveMarkerNode::processFeedback, this, _1));
    server_->applyChanges();
  }

  void add3DControls(visualization_msgs::msg::InteractiveMarker &int_marker) {
    // 1. X轴移动控制
    visualization_msgs::msg::InteractiveMarkerControl x_control;
    x_control.orientation.w = 0.707; x_control.orientation.x = 0;
    x_control.orientation.y = 0.707; x_control.orientation.z = 0;
    x_control.name = "move_x";
    x_control.interaction_mode = visualization_msgs::msg::InteractiveMarkerControl::MOVE_AXIS;
    int_marker.controls.push_back(x_control);

    // 2. Y轴移动控制
    visualization_msgs::msg::InteractiveMarkerControl y_control;
    y_control.orientation.w = 0.707; y_control.orientation.x = 0;
    y_control.orientation.y = 0; y_control.orientation.z = 0.707;
    y_control.name = "move_y";
    y_control.interaction_mode = visualization_msgs::msg::InteractiveMarkerControl::MOVE_AXIS;
    int_marker.controls.push_back(y_control);

    // 3. Z轴移动控制
    visualization_msgs::msg::InteractiveMarkerControl z_control;
    z_control.orientation.w = 1; z_control.orientation.x = 0;
    z_control.orientation.y = 0; z_control.orientation.z = 0;
    z_control.name = "move_z";
    z_control.interaction_mode = visualization_msgs::msg::InteractiveMarkerControl::MOVE_AXIS;
    int_marker.controls.push_back(z_control);
  }


  void processFeedback(
    const visualization_msgs::msg::InteractiveMarkerFeedback::ConstSharedPtr &feedback) {
    auto pose = feedback->pose;
    
    // 保持原有的位置限制逻辑
    if (feedback->event_type == 
        visualization_msgs::msg::InteractiveMarkerFeedback::POSE_UPDATE) {
        pose.position.z = 0;
        server_->setPose(feedback->marker_name, pose);
    }
    server_->applyChanges();
  }

  std::shared_ptr<interactive_markers::InteractiveMarkerServer> server_;
};

int main(int argc, char** argv) {
  rclcpp::init(argc, argv);
  auto node = std::make_shared<InteractiveMarkerNode>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
