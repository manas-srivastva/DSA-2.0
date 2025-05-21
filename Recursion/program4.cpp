// #include<iostream>
// using namespace std;
// int fibonnaci(int n){
//     if(n==0 || n==1){
//         return n;
//     }
//     return fibonnaci(n-1)+fibonnaci(n-2);
// }
// int main(){
// int n=10;
// cout<<fibonnaci(n);

// return 0;
// }


// #include<iostream>
// using namespace std;
// int NthStair(int n){
//     if(n<=1){
//         return 1;

//     }
//     return NthStair(n-1)+NthStair(n-2);
// }
// int main(){
// int n=5;
// cout<<NthStair(n);
// return 0;
// }



// #include<iostream>
// using namespace std;
// int GCD(int a,int b){
//     if(b==0){
//         return a;

//     }
//     return GCD(b,a%b);
// }
// int main(){
// int a=48,b=16;
// cout<<GCD(a,b);
// return 0;
// }



//               Nth stair using loops
#include<iostream>
using namespace std;
int climbstair(int n)
{
    if(n<=2){
        return n;
    }
    int s1=1;
    int s2=2;
    for(int i=3;i<=n;i++){
        int temp=s1+s2;
        s1=s2;
        s2=temp;
    }
    return s2;
}
int main(){
int n=5;
cout<<climbstair(n);
return 0;
}