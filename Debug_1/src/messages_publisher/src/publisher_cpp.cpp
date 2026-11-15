#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <vector>
#include <rclcpp/rclcpp.hpp>
#include <ament_index_cpp/get_package_share_directory.hpp>
#include <messages_cpp/msg/item_info.hpp>
#include <yaml-cpp/yaml.h>

using namespace std::chrono_literals;

class ItemInfoPublisher : public rclcpp::Node
{
public:
  ItemInfoPublisher()
      : Node("item_info_publisher"), next_item_index_(0), publish_count_(0)
  {
    load_items();
    if (items_.empty())
    {
      RCLCPP_ERROR(this->get_logger(), "No items were loaded");
      return;
    }

    publisher_ = this->create_publisher<messages_cpp::msg::ItemInfo>("item_info", 10);
    timer_ = this->create_wall_timer(
        1000ms, std::bind(&ItemInfoPublisher::timer_callback, this));

    RCLCPP_INFO(this->get_logger(), "ItemInfo Publisher started, loaded %zu items", items_.size());
  }

private:
  void load_items()
  {
    std::string config_path =
        ament_index_cpp::get_package_share_directory("messages_publisher") +
        "/config/items.yaml";
    RCLCPP_INFO(this->get_logger(), "Try load yaml: %s", config_path.c_str());

    try
    {
      YAML::Node config = YAML::LoadFile(config_path);
      if (!config["items"])
      {
        RCLCPP_ERROR(this->get_logger(), "yaml no [items] key");
        return;
      }
      YAML::Node items_node = config["items"];
      for (auto && n : items_node)
      {
        if (!n["id"] || !n["name"] || !n["info"])
        {
          RCLCPP_WARN(this->get_logger(), "skip invalid item, missing field");
          continue;
        }
        messages_cpp::msg::ItemInfo msg;
        msg.id = n["id"].as<int32_t>();
        msg.name = n["name"].as<std::string>();
        msg.info = n["info"].as<std::string>();
        items_.push_back(msg);

        if (items_.size() >= 20) break; 
      }
    }
    catch (const YAML::Exception & e)
    {
      RCLCPP_ERROR(this->get_logger(), "yaml load error: %s", e.what());
    }
  }

  void timer_callback()
  {
    if (items_.empty()) return;
    auto message = items_[next_item_index_];

    RCLCPP_INFO(this->get_logger(),
                "Publishing: ID=%d, Name='%s', Info='%s', count=%d",
                static_cast<int>(message.id),
                message.name.c_str(),
                message.info.c_str(),
                publish_count_);

    publisher_->publish(message);
    next_item_index_ = (next_item_index_ + 1) % items_.size();
    publish_count_++;
  }

  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<messages_cpp::msg::ItemInfo>::SharedPtr publisher_;
  std::vector<messages_cpp::msg::ItemInfo> items_;
  size_t next_item_index_;
  int publish_count_;
};

int main(int argc, char *argv[])
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<ItemInfoPublisher>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}

