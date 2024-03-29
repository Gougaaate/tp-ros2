#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <math.h>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "std_msgs/msg/float64.hpp"
#include "example_interfaces/srv/add_two_ints.hpp"

using namespace std::chrono_literals;
/*
 * Class that inherits from the rclcpp::Node object.
 * You can choose to separate your class into an .hpp and .cpp file.
 */

class NodeA : public rclcpp::Node {
    public:
        /* Constructor of your node with the name "nodeA" */

        NodeA() : Node("nodeA") {
            // Creates a publisher of type std_msgs/msg/String on the "/cap" topic, with a maximum queue size of 10 messages.

            publisher_ = this->create_publisher<std_msgs::msg::Float64>("/cap", 10);
            timer_ = this->create_wall_timer(500ms, std::bind(&NodeA::timer_callback, this));     // Creates a timer that calls the time_callback function every 500ms.

            // Note that there are several possible time bases.
        }

    private:
        /* Timer callback function */

        void timer_callback() {

            auto message = std_msgs::msg::Float64();               // Creates a message object of type Float64.
            message.data = 90 * sin(this -> now().seconds());      // Fills the message content.

            // Prints a log message to the console (fprintf format).
            // It is also possible to use RCLCPP_WARN.
            // Outside a node, rclcpp::get_logger("rclcpp") can be used.

            RCLCPP_INFO(this->get_logger(), "Publishing: '%f'", message.data);
            publisher_->publish(message);    // Publishes the message using the publisher object.
        }
        rclcpp::TimerBase::SharedPtr timer_; // Timer object.
        rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr publisher_;
     };


int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("add_two_ints_server");

    rclcpp::spin(node);     //This puts the node on hold by listening for potential service requests.
    rclcpp::shutdown();
}
