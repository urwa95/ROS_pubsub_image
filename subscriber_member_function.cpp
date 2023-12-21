#include <functional>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp"

using std::placeholders::_1;

class ImageSubscriber : public rclcpp::Node
{
public:
  ImageSubscriber()
  : Node("image_subscriber")
  {
    image_subscription_ = this->create_subscription<sensor_msgs::msg::Image>(
      "image_topic", 10, std::bind(&ImageSubscriber::image_callback, this, _1));
  }

private:
  void image_callback(const sensor_msgs::msg::Image::SharedPtr msg) const
  { 
    RCLCPP_INFO(this->get_logger(), "Received Image - Width: %d, Height: %d, Encoding: %s",
                msg->width, msg->height, msg->encoding.c_str()); 
    // Add your image processing logic here
  }

  rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr image_subscription_;
};

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<ImageSubscriber>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}