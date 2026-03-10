#include<iostream>
#include<string>
#include<queue>
#include<vector>
using namespace std;

struct Plane {
    string flight;
    int fuel;
};

struct Compare {
    bool operator()(Plane a, Plane b){
        return a.fuel >b.fuel;
    }
};
int main(){
int N;
cin>>N;
priority_queue<Plane,vector<Plane>,Compare>pq;
for(int i=0;i<N;i++){
    Plane p;
    cin>>p.flight>>p.fuel;
    pq.push(p);
}
while(!pq.empty())
{
    Plane p=pq.top();
    pq.pop();
    cout<<p.flight<<" "<<p.fuel<<endl;
}
return 0;
}