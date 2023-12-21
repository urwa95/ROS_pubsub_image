#include <chrono>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp" // Update with actual package name

using namespace std::chrono_literals;

class MinimalImagePublisher : public rclcpp::Node
{
public:
  MinimalImagePublisher()
  : Node("minimal_image_publisher"), count_(0)
  {
    image_publisher_ = this->create_publisher<sensor_msgs::msg::Image>("image_topic", 10);
    timer_ = this->create_wall_timer(
      500ms, std::bind(&MinimalImagePublisher::timer_callback, this));
  }

private:
  void timer_callback()
  {
    auto image_msg = sensor_msgs::msg::Image();  // Create an Image message
    // Set image data, width, height, encoding, etc.
      image_msg.data = {1, 2, 3, 4, 5, 6};  // Sample image data
      image_msg.width = 2;
      image_msg.height = 1;
      image_msg.encoding = "mono8";  // Sample encoding
      image_publisher_->publish(image_msg);

    RCLCPP_INFO(this->get_logger(), "Published Image");
  }

  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr image_publisher_;
  size_t count_;
};

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<MinimalImagePublisher>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
