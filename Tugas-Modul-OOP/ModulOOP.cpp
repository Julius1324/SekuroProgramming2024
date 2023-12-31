#include <iostream>
#include<vector>
using namespace std;
class Matrix{
private:
    vector<vector<int>> v;
    int baris;
    int kolom;
public:
    Matrix(vector<vector<int>> vin){
        this ->v=vin;
        this-> baris = vin.size();
        this->kolom = vin[0].size();
    }
    Matrix(int b, int k){
        v = vector<vector<int>> (b,vector<int>(k));
        this->baris=b;
        this->kolom=k;
    }
    void display(){
        for (int i=0; i<v.size();i++){
            for (int j=0;j<v[0].size();j++){
                cout<<v[i][j]<<" ";}
            cout<<endl;}
    }
    
    Matrix operator+ (Matrix a){
        if (a.v.size() != v.size() || a.v[0].size() != v[0].size()){
            cout << "The matrix dimension is not valid!"<<endl;
        }
        else{
            Matrix temp(v.size(),v[0].size());
    
            for (int i=0;i<v.size();i++){
                for (int j=0;j<v[0].size();j++){
                    temp.v[i][j] = v[i][j] + a.v[i][j];}}        
        
            return temp;}
    }

    Matrix operator- (Matrix a){
        if (a.v.size() != v.size() || a.v[0].size() != v[0].size()){
            cout << "The matrix dimension is not valid!"<<endl;
        }
        else{
            Matrix temp(v.size(),v[0].size());
    
            for (int i=0;i<v.size();i++){
                for (int j=0;j<v[0].size();j++){
                    temp.v[i][j] = v[i][j] - a.v[i][j];}}        
        
            return temp;}
    }
};
int main(){
    Matrix test({{1,2,3,4,5,6},{0,9,8,7,6,5}});
    test.display();
    cout << "test2"<<endl;
    Matrix test2({{1,1,1,1,1},{1,1,1,1,1}});
    test2.display();
    cout << "Penjumlahan"<<endl;
    Matrix c = test - test2;
    c.display();
}