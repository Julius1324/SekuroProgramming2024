#include <iostream>
#include <iomanip>
#include <math.h>
#include <vector>
using namespace std;
void lokasi(float x,float y){
    std::cout << std::setprecision(2) << std::fixed;
    cout<<"("<<x<<","<<y<<")"<<endl;
}
void gerak(float x2,float y2,float* x,float* y, vector<float>& vectx, vector<float>& vecty,int* index){
    *x += x2;
    *y += y2;
    
    //Memotong vector x dan vector y, dan membuang elemen jika berada diposisi setelah index
    vectx.resize(*index+1);
    vecty.resize(*index+1);

    //Menambahkan x dan y ke vector
    vectx.push_back(*x);
    vecty.push_back(*y);
    
    *index += 1;
}
void gerak_2(float v, float t, float theta, float* x,float* y,vector<float>& vectx, vector<float>& vecty,int* index){
    float pi = 3.14159265359;
    *x += v*cos((theta*pi)/180)*t;
    *y += v*sin((theta*pi)/180)*t;

    //Memotong vector x dan vector y, dan membuang elemen jika berada diposisi setelah index
    vectx.resize(*index+1);
    vecty.resize(*index+1);
    
    //Menambahkan x dan y ke vector
    vectx.push_back(*x);
    vecty.push_back(*y);
    
    *index += 1;
}
void history(vector<float>& vectx, vector<float>& vecty){   //Melihat history koordinat
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
    if (*index == 0){cout<<"Tidak dapat undo!"<<endl;}//Berada di awal
    else{*index -= 1;}
}
void redo(int* index,vector<float>& vectx){
    if (*index==vectx.size()-1){cout<<"Tidak dapat redo!"<<endl;}   //Berada di akhir
    else{*index += 1;}
}
void p_index(int* index){cout<<*index<<endl;}   //Mencetak index saat ini




int main(){
    bool game_on=true;//bool sebagai penanda program masih berjalan
    float x=0;float y=0;
    vector <float> x_history={0};   //vector history x
    vector <float> y_history={0};   //vector histort y
    int index = 0;

    //Mencetak pilihan instruksi
    cout<<"lokasi: lokasi()"<<endl;
    cout<<"gerak: geraj(x,y)"<<endl;
    cout<<"gerak_2: gerak_2(v,t,theta)"<<endl;
    cout<<"exit: keluar dari program"<<endl;
    cout<<"Masukkan perintah"<<endl;

    while (game_on==true){
        string input;cin>>input;    //instruksi yang dipilih
        x = x_history[index]; //x sebagai nilai vektor x diposisi index
        y = y_history[index];//y sebagai nilai vektor y diposisi index
        
        if (input=="lokasi"){
            lokasi(x,y);
        }
        if (input=="gerak"){
            float x2;float y2;
            cout<<"x: ";cin>>x2; 
            cout<<"y: ";cin>>y2;
            
            gerak(x2,y2,&x,&y,x_history,y_history,&index);
        }
        if (input=="gerak_2"){
            float v;float t;float theta;
            cout<<"v: ";cin>>v; 
            cout<<"t: ";cin>>t;
            cout<<"theta: ";cin>>theta;
    
            gerak_2(v,t,theta,&x,&y,x_history,y_history,&index);
        }
        if (input=="exit"){//Keluar dari program
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
        if (input=="index"){p_index(&index);}   //Mencetak index saat ini
        }
}
