#include<bits/stdc++.h>
using namespace std;
// int sum(int num1, int num2){
//     int num3=num1+num2;
//     return num3;
// }


void doSomething(int arr[],int n){
    arr[0]+=100;
    cout<<"Value inside function is: "<<arr[0]<<endl;
}
int main(){
// int x;
// cin>>x;
// cout<<"The value of x :" <<x;

// string str;
// getline(cin,str);
// cout<<str;

// string s="Striver";
// int len= s.size();
// s[len-1]='z';
// cout<<s[len-1];


// int num1,num2;
// cin>>num1>>num2;
// int a= sum(num1,num2);
// cout<<"the sum is" <<" " <<a;

int n=5;
int arr[n];
for(int i=0;i<n;i++){
    cin>>arr[i];
}
doSomething(arr,n);
cout<<"Value inside "<< arr[0]<<endl;
return 0;
}