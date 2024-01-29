#include <iostream>
using namespace std;
int main(){
    int n;
    float total=0.0;
    cout<<"jumlah bilangan: ";
    cin>>n;
    for (int i=1;i<=n;i++){
        float a=0;

        cout<<"bilangan "<<i<<": ";
        cin>> a;
        total += a;
    }
    total /= n;
    cout<<"RATA- RATA "<<total;
}