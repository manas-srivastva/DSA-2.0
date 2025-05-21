
// printing from 1 to N using recursion
// #include<iostream>
// using namespace std;
// void print2(int i, int n){
//     if(i>n){
//         return;
//     }
//     cout<<i<<" ";
//     print2(i+1,n);
// }
// int main(){
// int n=5;
// print2(1,n);
// return 0;
// }





// printing from N to 1 using recursion
#include<iostream>
using namespace std;
void print3(int n, int i){
    if(i<1){
        return;
    }
    cout<<i<<" ";
    print3(n,i-1);
}
int main(){
int n=5;
print3(n,n);
return 0;
}