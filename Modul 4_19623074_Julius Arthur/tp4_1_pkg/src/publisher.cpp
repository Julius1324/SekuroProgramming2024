#include "ros/ros.h"
#include "tp4_1_pkg/Pesan.h"

int main(int argc, char**argv){
    ros::init(argc,argv,"publisher");

    ros::NodeHandle nh;

    ros::Publisher data_publisher = nh.advertise<tp4_1_pkg::Pesan>("TOPIK",1000);

    ros::Rate loop_rate(1);

    while(ros::ok()){
        tp4_1_pkg::Pesan data;

        data.usia = 12;
        data.tinggi = 170.5;
        data.nama = "James";
        data.kehadiran = true;

        data_publisher.publish(data);
        ros::spinOnce();
        loop_rate.sleep();
    }
return 0;
}