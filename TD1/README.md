## TD 1
### Question 1 
```console
$ ros2 topic pub -r N (Hz frequency) /topic_name std_msgs/String "data: whatever you want"
```
For example, 10Hz frequency, topic named "The Roof" :
```console
$ ros2 topic pub -r 10 /TheRoof std_msgs/String "data: Je passe enfin des marrons"
```
### Question 2
```console
$ ros2 interface show std_msgs/msg/Float64
```
```console
$ ros2 interface show sensor_msgs/srv/Imu
```
```console
$ ros2 interface show std_srvs/srv/Trigger
```
### Question 3
```console
$ ros2 topic pub -r 1 /cap std_msgs/Float64 "data: 90"
```
### Question 4/5
This command counts all the active nodes (including the hidden ones)
```console
$ ros2 node list -a | wc -l
```
### Question 6
```console
$ sudo apt install tree
$ tree
```
![tree](https://github.com/Gougaaate/ROS-2-Adam-GOUX--GATEAU/blob/main/TD1/tree1.png?raw=true)

### Question 7/8
Same command : 
```console
$ tree
```
![tree](https://github.com/Gougaaate/ROS-2-Adam-GOUX--GATEAU/blob/main/TD1/tree2.png?raw=true)

### Question 9

```console
$ colcon build
```
Then in another shell :
```console
$ ros2 run tp1 nodeA
```

### Question 10

```            message.data = 90 * sin(this -> now().seconds());   // Fills the message content.```
