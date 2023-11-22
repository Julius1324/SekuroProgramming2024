#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
void lokasi(float x,float y){
    std::cout << std::setprecision(2) << std::fixed;
    cout<<"("<<x<<","<<y<<")"<<endl;
}
void gerak(float x2,float y2,float* x,float* y){
    *x += x2;
    *y += y2;
}
void gerak_2(float v, float t, float theta, float* x,float* y){
    float pi = 3.14159265359;
    *x += v*sin((theta*pi)/180)*t;
    *y += v*cos((theta*pi)/180)*t;

}


int main(){
    bool game_on=true;
    float x=0;float y=0;
    cout<<"lokasi: lokasi()"<<endl;
    cout<<"gerak: geraj(x,y)"<<endl;
    cout<<"gerak_2: gerak_2(v,t,theta)"<<endl;
    cout<<"exit: keluar dari program"<<endl;
    cout<<"Masukkan perintah"<<endl;
    while (game_on==true){
        string input;cin>>input;
        if (input=="lokasi"){
            lokasi(x,y);
        }
        if (input=="gerak"){
            float x2;float y2;
            cout<<"x y"<<endl;
            cin>>x2>>y2;
            gerak(x2,y2,&x,&y);
        }
        if (input=="gerak_2"){
            float v;float t;float theta;
            cout<<"v t theta"<<endl;
            cin>>v>>t>>theta;
            gerak_2(v,t,theta,&x,&y);
        }
        if (input=="exit"){
            break;
        }
        }
}
