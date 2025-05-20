// #include<iostream>
// using namespace std;
// void pattern(int n){
//     for(int i=0;i<n;i++){
//         for(int j=0;j<=i;j++){
//             cout<<"*";

//         }
//         cout<<endl;
//     }
// }
// int main(){
// int m=6;
// pattern(m);
// return 0;
// }

// pattern 2.0

// #include<iostream>
// using namespace std;
// void pattern(int n){
//     for(int i=0;i<n;i++){
//         for(int j=5;j>=i;j--){
//             cout<<"*";

//         }
//         cout<<endl;
//     }
// }
// int main(){
// int m=6;
// pattern(m);
// return 0;
// }

// pattern 2.0.0
#include<iostream>
using namespace std;
void pattern(int n){
    for(int i=n;i>0;i--){
        for(int j=0;j<=i;j++){
            cout<<j+1<<" ";

        }
        cout<<endl;
    }
}
int main(){
int m=6;
pattern(m);
return 0;
}
