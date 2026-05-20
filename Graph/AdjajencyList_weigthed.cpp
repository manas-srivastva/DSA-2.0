#include<iostream>
#include<vector>
using namespace std;
int main(){
int vertex,edges,weight;
cin>>vertex>>edges>>weight;
vector<pair<int,int>>Adjlist[vertex];
int u,v;
for(int i=0;i<edges;i++)
{
    cin>>u>>v>>weight;
    Adjlist[u].push_back(make_pair(v,weight));
    Adjlist[v].push_back(make_pair(u,weight));
}

for(int i=0;i<vertex;i++){
    cout<<i<<"-> ";
    for(int j=0;j<Adjlist[i].size();j++)
    cout<<Adjlist[i][j].first<<" "<<Adjlist[i][j].second<<" ";
      cout<<endl;
}
return 0;
}