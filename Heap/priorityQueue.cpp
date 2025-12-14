#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){

    // Max Heap Implementation
// priority_queue<int>p;
// p.push(10);
// p.push(40);
// p.push(30);
// p.push(50);
// p.push(11);
// cout<<p.top()<<" ";

// while(!p.empty()){
//     cout<<p.top()<<" ";
//     p.pop();
// }



// Min Heap Implementation
priority_queue<int, vector<int> ,greater<int> >p;
 p.push(10);
 p.push(40);
 p.push(30);
 p.push(50);
 p.push(11);
 cout<<p.top()<<" ";

 while(!p.empty()){
     cout<<p.top()<<" ";
     p.pop();
 }

return 0;
}