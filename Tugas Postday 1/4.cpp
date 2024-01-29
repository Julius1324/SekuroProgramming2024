#include <iostream>
using namespace std;
int main(){
    cout<<"Tentukan tahun kabisat"<<endl;
    int n;
    cout<<"Tahun: ";
    cin>>n;
    if (n%400 != 0){
        if(n%100 == 0){
            cout<<"Bukan Tahun Kabisat";
        }
        else if (n%100 != 0 | n%4 != 0){ 
            cout<<"Bukan Tahun Kabisat";
        }
    }
    else{
        cout<<"Tahun Kabisat";
    }
}