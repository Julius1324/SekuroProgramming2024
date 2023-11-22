#include <iostream>
#include <iomanip>
#include <math.h>
#include <vector>
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
void undo(vector<float>& vectx, vector<float>& vecty,float* x, float* y){
    *x = vectx[vectx.size()-1-1];
    *y = vecty[vectx.size()-1-1];
}
void history(vector<float>& vectx, vector<float>& vecty){
    cout<<"x: ";
    for (int i=0;i<vectx.size();i++){
        cout<<vectx[i]<<" ";
    }
    cout<<endl;
    cout<<"y: ";
    for (int i=0;i<vectx.size();i++){
        cout<<vecty[i]<<" ";
    }
    cout<<endl;
}
void undo(int* index){
    if (*index == 0){cout<<"Tidak dapat undo!"<<endl;}
    else{*index -= 1;}
}
void redo(int* index,vector<float>& vectx){
    if (*index==vectx.size()-1){cout<<"Tidak dapat redo!"<<endl;}
    else{*index += 1;}
}




int main(){
    bool game_on=true;
    float x=0;float y=0;
    vector <float> x_history={0};
    vector <float> y_history={0};
    int index = 0;
    cout<<"lokasi: lokasi()"<<endl;
    cout<<"gerak: geraj(x,y)"<<endl;
    cout<<"gerak_2: gerak_2(v,t,theta)"<<endl;
    cout<<"exit: keluar dari program"<<endl;
    cout<<"Masukkan perintah"<<endl;
    while (game_on==true){
        string input;cin>>input;
        x = x_history[index];
        y = y_history[index];
        if (input=="lokasi"){
            lokasi(x,y);
        }
        if (input=="gerak"){
            float x2;float y2;
            cout<<"x y"<<endl;
            cin>>x2>>y2;
            
            gerak(x2,y2,&x,&y);
            x_history.push_back(x);
            y_history.push_back(y);
            index += 1;
        }
        if (input=="gerak_2"){
            float v;float t;float theta;
            cout<<"v t theta"<<endl;
            cin>>v>>t>>theta;
            
            gerak_2(v,t,theta,&x,&y);
            x_history.push_back(x);
            y_history.push_back(y);
            index += 1;
        }
        if (input=="exit"){
            break;
        }
        if (input=="history"){
            history(x_history,y_history);
        }
        if (input=="undo"){
            undo(&index);
        }  
        if (input=="redo"){
            redo(&index,x_history);
        }  

        }
}
