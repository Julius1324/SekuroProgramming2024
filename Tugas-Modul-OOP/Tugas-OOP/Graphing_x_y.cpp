#include <iostream>
#include "ModulOOP/ModulOOP.h"
#include <math.h>
#include "pbplots/pbPlots.hpp"
#include "pbplots/supportLib.hpp"
using namespace std;

int main(){
   float t = 0;
   std::vector<double> y_vec(630);
   std::vector<double> x_vec(630);
   std::vector<double> t_vec(630);
   Swerve temp({{1,0,-0.26363},{0,1,0.26363},{1,0,-0.26363},{0,1,0.26363},{1,0,-0.26363},{0,1,0.26363},{1,0,-0.26363},{0,1,0.26363}});



   temp.x = 0;
   temp.y = 5;
   for (int i=0;i<630;i++){
      temp.vx = 48*cos(t)*pow(sin(t),2);
      temp.vy = 4*sin(4*t)+6*sin(3*t)+10*sin(2*t)-13*sin(t);
      temp.omega = 0;
      temp.updatePose(0.01);
      y_vec[i]= temp.y;
      x_vec[i]= temp.x;
      t_vec[i]= t;
      t += 0.01;
      cout<<t<<endl;
   }
   StringReference *errorMessage = CreateStringReferenceLengthValue(0, L' ');
   RGBABitmapImageReference *imageReference = CreateRGBABitmapImageReference();
   std::vector<double> xs= x_vec;
   std::vector<double> ys = y_vec;
   // Pembuatan grafik
   DrawScatterPlot(imageReference, 600, 400, &xs, &ys, errorMessage);
   // Simpan grafik dalam format PNG
   std::vector<double> *pngdata = ConvertToPNG(imageReference->image);
   WriteToFile(pngdata, "test.png"); // simpan nama file "example1.png"
   DeleteImage(imageReference->image);
   FreeAllocations();
return 0;

   
   return 0;
   
   }
