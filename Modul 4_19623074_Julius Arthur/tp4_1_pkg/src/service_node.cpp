#include "ros/ros.h"
#include "tp4_1_pkg/Magnitude_m.h"
#include "math.h"

bool get_mag(tp4_1_pkg::Magnitude_m::Request &req,tp4_1_pkg::Magnitude_m::Response &res){
    res.magnitude = sqrt(pow(req.x,2)+pow(req.y,2)+pow(req.z,2));
    return true;
}

int main(int argc,char ** argv){
    ros::init(argc,argv,"Service_Node");

    
    ros::NodeHandle nh;
    
    ros::ServiceServer service = nh.advertiseService("hitung_magnitude",get_mag);

    ros::spin();

    return 0;
}