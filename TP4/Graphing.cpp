#include <iostream>
#include "OOP/ModulOOP2.h"
#include <math.h>
#include "pbPlots.hpp"
#include "supportLib.hpp"
using namespace std;

int main(){
   float t = 0;
   std::vector<double> y_vec(630);
   std::vector<double> x_vec(630);
   std::vector<double> t_vec(630);
   Swerve temp({{1,0,-0.26363},{0,1,0.26363},{1,0,-0.26363},{0,1,0.26363},{1,0,-0.26363},{0,1,0.26363},{1,0,-0.26363},{0,1,0.26363}});

   temp.x = 0;
   temp.y = 0;
   for (int i=0;i<630;i++){
      temp.updatePose(0.01,48*cos(t)*pow(sin(t),2),4*sin(4*t)+6*sin(3*t)+10*sin(2*t)-13*sin(t),0);
      y_vec[i]= temp.y;
      x_vec[i]= temp.x;
      t_vec[i]= t;
      t += 0.01;
   }

   cout<<"x: "<<x_vec.size()<<endl;
   cout<<"y: "<<y_vec.size()<<endl;
   

   StringReference *errorMessage = CreateStringReferenceLengthValue(0, L' ');
   RGBABitmapImageReference *imageReference = CreateRGBABitmapImageReference();
   std::vector<double> xs= t_vec;
   std::vector<double> ys = y_vec;
   // Pembuatan grafik
   DrawScatterPlot(imageReference, 600, 400, &xs, &ys, errorMessage);
   // Simpan grafik dalam format PNG
   std::vector<double> *pngdata = ConvertToPNG(imageReference->image);
   WriteToFile(pngdata, "y_t.png"); // simpan nama file "example1.png"
   DeleteImage(imageReference->image);
   FreeAllocations();
return 0;

   
   return 0;
   
   }
