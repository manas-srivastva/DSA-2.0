#include<iostream>
using namespace std;
int main(){
    int space=2*(5-1);
for(int i=1;i<=5;i++){
// numbers
for(int j=1;j<=i;j++){
    cout<<j;
}
// spaces
for(int j=1;j<=space;j++){
    cout<<" ";
    
}
space-=2;
// numbers
for(int j=i;j>=1;j--){
    cout<<j;
}
cout<<endl;
 
}
return 0;
}