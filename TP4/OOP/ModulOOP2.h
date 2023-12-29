#ifndef ModulOOP_H
#define ModulOOP_H
#include <vector>
using namespace std;

class Matrix{
    private:
        int baris;
        int kolom;
    public:
        vector<vector<float>> v;
        Matrix();
        Matrix(vector<vector<float>> vin);
        Matrix(int b, int k);
        void display();
        void get_baris();
        void get_kolom();
        Matrix operator+ (Matrix a);
        Matrix operator- (Matrix a);
        Matrix operator* (Matrix a);
        };

class Swerve{
    private:
    Matrix pers1_mat;
    public:
    float v1x,v1y,v2x,v2y,v3x,v3y,v4x,v4y;
    float v1,v2,v3,v4;
    float x,y,teta;
    Swerve(vector<vector<float>> vin);
    void velocityCommands(float v_x, float v_y, float w1);
    void updatePose(float deltaTime,float vxi, float vyi, float wi);
};

#endif