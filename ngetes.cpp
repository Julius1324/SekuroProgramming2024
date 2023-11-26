#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> v1={1,2,3,4,5,6,7,8};
    v1.push_back(12);
    v1.resize(8);
    for (auto i=v1.begin();i != v1.end();i++){
        cout<<*i;
    cout<<"hello"<<endl;
    }
}

// 1 2 3 
//index 4