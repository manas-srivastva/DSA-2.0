// pattern 4+ pattern 5
#include<iostream>
using namespace std;
int main(){
for(int i=0;i<5;i++){
    // space loop
    for(int j=0;j<=5-i-1;j++){
        cout<<" ";

    }
    // star
    for(int j=0;j<2*i+1;j++)
    {
        cout<<"*";
    }
    for(int j=0;j<5-i-1;j++){
        cout<<" ";
    }
    cout<<endl;
}



for(int i=5;i>=0;i--){
    // space loop
    for(int j=0;j<=5-i-1;j++){
        cout<<" ";

    }
    // star
    for(int j=0;j<2*i+1;j++)
    {
        cout<<"*";
    }
    for(int j=0;j<5-i-1;j++){
        cout<<" ";
    }
    cout<<endl;
}
return 0;
}