#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// iterator
int main(){
list<int>l;
l.push_back(20);
l.push_back(30);
l.push_back(22);
l.push_back(12);
l.push_front(15);
// l.pop_back();
// l.pop_front();

// cout<<l.front()<<" "<<l.back()<<endl;
// cout<<l.size();


// it!=end is used as the l.end() points the iterator to the next of the last value
// auto is used because the type of iterator is not defined
// for(auto it=l.begin();it!=l.end();it++)
// cout<<*it<<" ";


// for reverse order
for(auto it=l.rbegin();it!=l.rend();it++)
cout<<*it<<" ";
return 0;
}