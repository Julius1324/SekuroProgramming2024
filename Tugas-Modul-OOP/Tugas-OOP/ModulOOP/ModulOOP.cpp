#include "ModulOOP.h"
#include <iostream>
#include <math.h>

Matrix::Matrix(){}

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

//SWERVE

Swerve::Swerve(vector<vector<float>> vin){
    this->pers1_mat = Matrix(vin);
}


void Swerve::velocityCommands(float vxi, float vyi, float wi){
    Matrix pers2_mat(vector<vector<float>>{{vxi},{vyi},{wi}});
    Matrix hasil = pers1_mat*pers2_mat;
    v1x=hasil.v[0][0];
    v1y=hasil.v[1][0];
    v2x=hasil.v[2][0];
    v2y=hasil.v[3][0];
    v3x=hasil.v[4][0];
    v3y=hasil.v[5][0];
    v4x=hasil.v[6][0];
    v4y=hasil.v[7][0];

    v1 = sqrt((pow(v1x,2)+pow(v1y,2)));
    v2 = sqrt((pow(v2x,2)+pow(v2y,2)));
    v3 = sqrt((pow(v3x,2)+pow(v3y,2)));
    v4 = sqrt((pow(v4x,2)+pow(v4y,2)));
    hasil.display();}
void Swerve::updatePose(float deltaTime){
    Matrix pose1(vector<vector<float>>{{x},{y},{teta}});
    Matrix t_mat(vector<vector<float>>{{deltaTime}});
    Matrix kec(vector<vector<float>>{{vx},{vy},{omega}});
    Matrix hasil = pose1 + kec*t_mat;

    x = hasil.v[0][0];
    y = hasil.v[1][0];
    teta = hasil.v[2][0];
}