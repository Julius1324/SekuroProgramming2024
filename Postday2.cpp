#include <iostream>
#include <iomanip>
using namespace std;
void lokasi(float x,float y){
    std::cout << std::setprecision(2) << std::fixed;
    cout<<"("<<x<<","<<y<<")"<<endl;
}
void gerak(float x2,float y2,float* x,float* y){
    *x += x2;
    *y += y2;
}

int main(){
    bool game_on=true;
    float x=0;float y=0;
    while (game_on==true){
        string input;
        cin>>input;
        lokasi(x,y);
        float x1,x2,xpointer,ypointer;
        cin>>x1>>x2;

        gerak(x1,x2,&x,&y);
        lokasi(x,y);
        cout<<"selesai"<<endl;
    }
    

}
