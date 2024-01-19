#include "ros/ros.h"
#include "tp4_1_pkg/Magnitude_m.h"



int main(int argc,char ** argv){
    ros::init(argc,argv,"Client_Node");

    
    ros::NodeHandle nh;
    
    ros::ServiceClient client = nh.serviceClient<tp4_1_pkg::Magnitude_m>("hitung_magnitude");

    tp4_1_pkg::Magnitude_m srv;
    srv.request.x = 3;
    srv.request.y = 4;
    srv.request.z = 5;

    if (client.call(srv)){
        ROS_INFO("Magnitude: %lf", srv.response.magnitude);
    }
    else{
        ROS_INFO("Gagal memanggil service");
        return 1;
    }

    return 0;
}