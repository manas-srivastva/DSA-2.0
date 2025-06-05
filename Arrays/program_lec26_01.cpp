#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
  int aggressiveCows(vector<int> &stalls, int k) {

        // Write your code here(
        sort(stalls.begin(),stalls.end());
        int count =0;
        int n=stalls.size();
        int start=1,end=stalls[n-1]-stalls[0],mid,ans;
        while(start<=end){
            mid=start+(end-start)/2;
            int count=1,pos=stalls[0];
            for(int i=1;i<n;i++){
                if((pos+mid)<=stalls[i]){
                    count++;
                    pos=  stalls[i];

                }
            }
                if(count<k)
                end=mid-1;
                else
                {
                    ans=mid;
                    start=mid+1;
                }
            }
            return ans;
        }

int main(){
vector<int>cows;
cows.push_back(1);
cows.push_back(2);
cows.push_back(4);
cows.push_back(8);
cows.push_back(9);
int k=3;
cout<<aggressiveCows(cows,k);
return 0;
}

