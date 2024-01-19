#include "ros/ros.h"
#include "tp4_1_pkg/Pesan.h"

void callbackHandler(const tp4_1_pkg::Pesan::ConstPtr &msg){
    ROS_INFO("\nSaya mendengar: \n");
    ROS_INFO("usia: %ld\n",msg->usia);
    ROS_INFO("tinggi: %lf\n",msg->tinggi);
    ROS_INFO("nama: %s\n",msg->nama.c_str());
    ROS_INFO("kehadiran: %d\n",msg->kehadiran);
}

int main(int argc,char ** argv){
    ros::init(argc,argv,"subscriber");

    
    ros::NodeHandle nh;
    
    ros::Subscriber data_subscriber = nh.subscribe("TOPIK", 1000,callbackHandler);

    ros::spin();

    return 0;
}