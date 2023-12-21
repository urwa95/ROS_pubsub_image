# ROS 2 Image Communication Package

## Description
This ROS 2 package includes two nodes: `MinimalImagePublisher` and `ImageSubscriber`, demonstrating basic image data handling and communication in ROS 2. The `MinimalImagePublisher` node publishes synthetic image data at regular intervals, including image dimensions and encoding details. The `ImageSubscriber` node subscribes to this data and logs the received image details. This setup showcases the publisher-subscriber pattern in ROS 2, utilizing the `sensor_msgs/msg/Image` message type.

## File Structure

your_package/
|-- src/
| |-- minimal_image_publisher.cpp
| |-- image_subscriber.cpp
|-- CMakeLists.txt
|-- package.xml

css


- **src/**: Contains the source files.
  - **minimal_image_publisher.cpp**: Implements the image publisher node.
  - **image_subscriber.cpp**: Implements the image subscriber node.
- **CMakeLists.txt**: CMake file for configuring the build of the ROS 2 package.
- **package.xml**: Provides metadata and dependencies of the package.

## Build Instructions
1. **Place the Package**: Copy your package directory into the `src` folder of your ROS 2 workspace.

2. **Compile the Package**:
   - Navigate to the root of your ROS 2 workspace.
   - Execute `colcon build --packages-select your_package_name` to build your package. Replace `your_package_name` with the actual name of your package.
   - Source the setup script after building: `source install/setup.bash`.

3. **Run the Nodes**:
   - Start the publisher node with `ros2 run your_package_name minimal_image_publisher`.
   - In a separate terminal (after sourcing the setup script), start the subscriber node with `ros2 run your_package_name image_subscriber`.

4. **Verify Operation**: Check the output in the subscriber node's terminal to confirm it is correctly receiving and logging the image data published by the publisher node.

This package is ideal for those starting with ROS 2 and image processing in robotics. It serves as a basic yet practical example of handling image data using ROS 2's communication mechanisms.
