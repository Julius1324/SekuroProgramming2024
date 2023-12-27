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
        Matrix(vector<vector<float>> vin);
        Matrix(int b, int k);
        void display();
        void get_baris();
        void get_kolom();
        Matrix operator+ (Matrix a);
        Matrix operator- (Matrix a);
        Matrix operator* (Matrix a);

};

class Swerve : public Matrix{
    private:
    float v1x,v1y,v2x,v2y,v3x,v3y,v4x,v4y;
    float v1,v2,v3,v4;
    float r1x,r1y,r2x,r2y,r3x,r3y,r4x,r4y;
    float r = 0.26363;
    float vx,vy,w;

    public:
    void velocityCommand(float v_x, float v_y, float w1);
    void get_v1();
};

#endif