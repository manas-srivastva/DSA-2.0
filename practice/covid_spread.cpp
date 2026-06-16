#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int r;
int c;
bool valid (int i,int j)
{
    return i>=0&&i<r&&j>=0&&j<c;
}
int covide_spreaddd(vector<vector<int>>hospital)
{
r=hospital.size();
c=hospital[0].size();
// BFS
queue<pair<int,int>>q;
for(int i=0;i<r;i++)
for(int j=0;j<c;j++)
if(hospital[i][j]==2)
q.push(make_pair(i,j));

int timer=0;

while(!q.empty())
{
    timer++;
    int curr_patient=q.size();
    while(curr_patient--)
    {
        int i=q.front().first;
        int j=q.front().second;
        q.pop();

        int row[4]={-1,1,0,0};
        int col[4]={0,0,-1,1};
        for(int k=0;k<4;k++){
            if(valid(1+row[k],j+col[k])&& hospital[1+row[k]][j+col[k]]==1)
            {
                hospital[i+row[k]][j+col[k]]=2;
                q.push(make_pair(i+row[k],j+col[k]));
            }
        }
    }
}
for(int i=0;i<r;i++)
for(int j=0;j<c;j++)
if(hospital[i][j]==1)
return -1;

return timer-1;
}
int main(){
    vector<vector<int>> hospital = {
        {2, 1, 0, 2, 1},
        {1, 0, 1, 2, 1},
        {1, 0, 0, 2, 1}
    };

    int ans = covide_spreaddd(hospital);

    if(ans == -1)
        cout << "All patients cannot be infected." << endl;
    else
        cout << "Time required to infect all patients = " << ans << endl;
return 0;
}