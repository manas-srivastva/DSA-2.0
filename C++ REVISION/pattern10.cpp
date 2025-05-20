#include<iostream>
using namespace std;
void printpattern1(int n){

    int num=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<num;
            num++;
            cout<<" ";
        }
        cout<<endl;
    }
}

void printpattern2(int n){
    for(int i=1;i<=n;i++){
        for(char ch='A';ch<='A'+i-1;ch++){
              cout<<ch<<" ";
        }
        cout<<endl;
    }
}

void printpattern3(int n){
    
    for(int i=0;i<n;i++){
        int start=1;
        for(char ch='A';ch<='A'+(n-i-1);ch++){
              cout<<ch<<" ";
              start++;
        }
        cout<<endl;
    }
}

void printpattern4(int n){
for(int i=0;i<n;i++){
    char ch='A'+i;
    for(int j=0;j<=i;j++){
        cout<<ch<<" ";
    }
    cout<<endl;
}
}
int main(){
int n=5;
printpattern1(n);
printpattern2(n);
cout<<endl;
printpattern3(n);
printpattern4(n);
return 0;
}