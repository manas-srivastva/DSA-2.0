#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// name age weight
int main(){
// pair<string,int>p;
// two method
// p=make_pair("rohit",30);

// second method
// p.first="rohit";
// p.second=30;

pair<string,pair<int,int> >p;
// p.first="rohit";
// p.second.first=25;
// p.second.second=80;

// second method
p=make_pair("rohit",make_pair(25,80));
cout<<p.first<<" "<<p.second.first<<" ";

return 0;
}