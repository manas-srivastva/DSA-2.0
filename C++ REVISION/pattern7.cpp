#include<iostream>
using namespace std;
int main(){
for(int i=0;i<2*5-1;i++){
    int stars=i;
    if(i>5)
    stars=2*5-i;
    for(int j=1;j<=stars;j++){
        cout<<"*";
    }
    cout<<endl;
}
return 0;
}