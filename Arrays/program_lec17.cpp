#include<iostream>
using namespace std;
int search(int arr[],int n,int key){
    if(arr[0]==key){
        return 1;
    }

    for(int i=0;i<n;i++){
        if(arr[i]==key)
        return i;
    }
    return -1;
    }

int main(){
int arr[5]={1,2,3,4,5};
int n=5;
int key=3;
int index=search(arr,n,key);
if(index==-1){
    cout<<"ELEMENT NOT FOUND";
}
else
cout<<"ELEMENT FOUND AT INDEX"<<index;

return 0;
}