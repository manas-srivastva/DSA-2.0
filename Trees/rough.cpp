#include<iostream>
using namespace std;
int main(){
int a[] = {1200, 200, 2300, 1230, 1543};
int b[] = {12, 14, 16, 18, 20};
int res = 0;

for (int i = 0; i < 5; i++) res += a[i];  // sums all elements of a
for (int i = 0; i < 4; i++) res += b[i];  // sums first 4 elements of b

cout << res;
return 0;
}