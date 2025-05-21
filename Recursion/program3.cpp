
// Factorial Using recurion
// #include<iostream>
// using namespace std;
// int fact(int n)
// {
//     if(n==1 || n==0){
//         return 1;
//     }
//     return n*fact(n-1);
// }
// int main(){
// int n=5;
// cout<<fact(n);
// return 0;
// }




// sum using recursion

// #include<iostream>
// using namespace std;
// int sum(int n){
//     if(n==0 || n==1){
//         return n;
//     }
//     return n+sum(n-1);
// }
// int main(){
// int n=5;
// cout<<sum(n);
// return 0;
// }




         // power of 2 using recursion
// #include<iostream>
// using namespace std;
// int power(int n,int p){
//     if(p==0){
//         return 1;
//     }
//     if(p==1){
//         return n;
//     }
//     return n*power(n,p-1);
// }
// int main(){
// int n=5;
// cout<<power(n,4);
// return 0;
// }

// Sum of square of n naturnal numbers using recursion
#include<iostream>
using namespace std;
int sumSquare(int n){
    if(n==0 || n==1){
        return n;

    }
    return n*n+sumSquare(n-1);
}
int main(){
int n=5;
cout<<sumSquare(n);
return 0;
}