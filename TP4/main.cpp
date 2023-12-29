#include <iostream>
#include "OOP/ModulOOP2.h"
#include <math.h>
using namespace std;

int main(){

   float t = 0;
   float t_2 =0;
   std::vector<float> vx_vec{};
   std::vector<float> t_vec{};
   Swerve temp({{1,0,-0.26363},{0,1,0.26363},{1,0,-0.26363},{0,1,0.26363},{1,0,-0.26363},{0,1,0.26363},{1,0,-0.26363},{0,1,0.26363}});

   while (t<=6.3){
      temp.velocityCommands(48*cos(t)*pow(sin(t),2),4*sin(4*t)+6*sin(3*t)+10*sin(2*t)-13*sin(t),0);
      vx_vec.push_back(temp.v1);
      t += 0.01;
      cout<<vx_vec[0]<<endl;
  }
   cout<<"t: "<<t_vec.size()<<endl;

   temp.velocityCommands(2*1,1,0);   
   temp.velocityCommands(2*3,1,0);
   
   return 0;
   
   }
