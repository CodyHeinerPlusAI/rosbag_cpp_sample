#include <rosbag/bag.h>
#include <std_msgs/Int32.h>
#include <std_msgs/String.h>

// Test if I can include Pcl stuff
#include <pcl/io/pcd_io.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/visualization/pcl_visualizer.h>

#include "my_util.h"

pcl::PointXYZI MakePointXYZI(float x, float y, float z, float intensity) {
    pcl::PointXYZI point;
    point.x = x;
    point.y = y;
    point.z = z;
    point.intensity = intensity;
    return point;
}

//ostream& operator<<(ostream& os, const pcl::PointXYZI& p) {
//    os << "{x: }" << p.x << ", y: " << p.y << ", z: " << p.z << ", i: " << p.intensity << "}";
//    return os;
//}

int main() {
    ros::Time::init();
    
    my_util::SayHello();

    std::cout << MakePointXYZI(1.f, 2.f, 3.f, 10.f) << std::endl;

    std::cout << "Writing some data to test.bag" << std::endl;

    rosbag::Bag bag;
    bag.open("test.bag", rosbag::bagmode::Write);

    std_msgs::String str;
    str.data = std::string("foo");

    std_msgs::Int32 i;
    i.data = 42;

    // bag.write(topic, timestamp, message)
    bag.write("chatter", ros::Time::now(), str);
    bag.write("numbers", ros::Time::now(), i);

    bag.close();
    
    std::cout << "Success!" << std::endl;
    
    return 0;
}
