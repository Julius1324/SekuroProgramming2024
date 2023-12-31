#include <iostream>
#include "OOP/ModulOOP.h"
#include <math.h>
#include "pbPlots.hpp"
#include "supportLib.hpp"
using namespace std;

int main(){
   float t = 0;
   vector<double> v1_vec(630);
   vector<double> t_vec(630);
   Swerve temp({{1,0,-0.26363},{0,1,0.26363},{1,0,-0.26363},{0,1,0.26363},{1,0,-0.26363},{0,1,0.26363},{1,0,-0.26363},{0,1,0.26363}});

   for (int i=0;i<630;i++){
        temp.velocityCommands(48*cos(t)*pow(sin(t),2),4*sin(4*t)+6*sin(3*t)+10*sin(2*t)-13*sin(t),0);
        v1_vec[i]= temp.v1;
        t_vec[i]= t;
        t += 0.01;
   }

   StringReference *errorMessage = CreateStringReferenceLengthValue(0, L' ');
   RGBABitmapImageReference *imageReference = CreateRGBABitmapImageReference();
   std::vector<double> xs= t_vec;
   std::vector<double> ys = v1_vec;
   // Pembuatan grafik
   DrawScatterPlot(imageReference, 600, 400, &xs, &ys, errorMessage);
   // Simpan grafik dalam format PNG
   std::vector<double> *pngdata = ConvertToPNG(imageReference->image);
   WriteToFile(pngdata, "test.png"); // simpan nama file "example1.png"
   DeleteImage(imageReference->image);
   FreeAllocations();
return 0;

   
   }
