#include "ModulOOP2.h"
#include <iostream>
#include <math.h>

Matrix::Matrix(vector<vector<float>> vin){
    this ->v=vin;
    this-> baris = vin.size();
    this->kolom = vin[0].size();
}

Matrix::Matrix(int b, int k){
    this->v = vector<vector<float>> (b,vector<float>(k));
    this->baris=b;
    this->kolom=k;
    }

void Matrix::display(){
    for (int i=0; i<v.size();i++){
        for (int j=0;j<v[0].size();j++){
            cout<<v[i][j]<<" ";}
        cout<<endl;}
    }

void Matrix::get_baris(){cout<< baris<<endl;}

void Matrix::get_kolom(){cout<< kolom<<endl;}

Matrix Matrix::operator+ (Matrix a){
     if (a.v.size() != v.size() || a.v[0].size() != v[0].size()){
        cout << "The matrix dimension is not valid!"<<endl;
        Matrix temp(1,1);
        return temp;
    }
    else{
        Matrix temp(v.size(),v[0].size());

        for (int i=0;i<v.size();i++){
            for (int j=0;j<v[0].size();j++){
                temp.v[i][j] = v[i][j] + a.v[i][j];}}        
    
        return temp;}
}

Matrix Matrix::operator- (Matrix a){
     if (a.v.size() != v.size() || a.v[0].size() != v[0].size()){
        cout << "The matrix dimension is not valid!"<<endl;\
        Matrix temp(1,1);
        return temp;
    }
    else{
        Matrix temp(v.size(),v[0].size());

        for (int i=0;i<v.size();i++){
            for (int j=0;j<v[0].size();j++){
                temp.v[i][j] = v[i][j] - a.v[i][j];}}        
    
        return temp;}
}

Matrix Matrix::operator*(Matrix a){

    if (kolom != a.baris){
        Matrix temp(1,1);
        cout<<"Multiplication cannot be done. The number of columns in the first matrix should be equal to the number of rows in the second"<<endl;
        return temp;
    }
    else{
    Matrix temp(baris,a.kolom);
    for (int i=0;i<baris;i++){
        for (int j=0;j<a.baris;j++){
                        for (int k=0;k<kolom;k++){
                temp.v[i][j] += v[i][k] * a.v[k][j];
            }
        }
    }
    return temp;
    }
}


void Swerve::velocityCommand(float v_x, float v_y, float w1){
    Matrix rumus1({{1,0,-r},{0,1,r},{1,0,-r},{0,1,r},{1,0,-r},{0,1,r},{1,0,-r},{0,1,r}});
    Matrix rumus2({{v_x},{v_y},{w1}});
    Matrix temp = rumus1 * rumus2;
    this->v1x=temp.v[0][0];
    this->v1y=temp.v[1][0];
    this->v2x=temp.v[2][0];
    this->v2y=temp.v[3][0];
    this->v3x=temp.v[4][0];
    this->v3y=temp.v[5][0];
    this->v4x=temp.v[6][0];
    this->v4y=temp.v[7][0];

    this->v1 = sqrt(pow(v1x,2)+pow(v1y,2));
    cout<<v1<<endl;
}
void Swerve::get_v1(){cout<<r<<" "<<v1y<<endl;}