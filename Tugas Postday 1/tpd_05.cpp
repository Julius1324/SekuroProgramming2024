#include <iostream>
using namespace std;
int main(){
    int n;
    cout<<"Input satu angka bulat: ";
    cin>>n;
    bool p = true;
    for (int i=2;i<n;i++){
        if (n%i ==  0){
            p = false;
        }
    }
    if (p==true){
        cout<<n<<" angka prima";
    }
    else{
        cout<<n<<" bukan angka prima";
    }
}