#include "pbPlots.hpp"
#include "supportLib.hpp"
#include <stdlib.h>

int main(){
    StringReference *errorMessage = CreateStringReferenceLengthValue(0, L' ');
    RGBABitmapImageReference *imageReference = CreateRGBABitmapImageReference();
    std::vector<double> xs{-2, -1, 0, 1, 2};
    std::vector<double> ys{2, -1, -2, -1, 2};
    // Pembuatan grafik
    DrawScatterPlot(imageReference, 600, 400, &xs, &ys, errorMessage);
    // Simpan grafik dalam format PNG
    std::vector<double> *pngdata = ConvertToPNG(imageReference->image);
    WriteToFile(pngdata, "example1.png"); // simpan nama file "example1.png"
    DeleteImage(imageReference->image);
    FreeAllocations();
    return 0;
}