#include<iostream>
#include<vector>
using namespace std;
int minEatingSpeed(vector<int>& piles, int h) {
        int start=0,end=0,mid,ans,n=piles.size();
        long long sum=0;
        for(int i=0;i<n;i++){
            sum+=piles[i];
            end=max(end,piles[i]);
        }
        start=sum/h;
        if(!start)
        start=1;
        while(start<=end){
            mid =start+(end-start)/2;
            // mid amount of banana to consume in 1 hr
            int totaltime=0;
            for(int i=0;i<n;i++){
                totaltime+=piles[i]/mid;
                if(piles[i]%mid){
                    totaltime++;
                }
            }
            if(totaltime>h){
                start=mid+1;
            }
            else{
                ans=mid;
                end=mid-1;
            }
        }
        return ans;
    }
int main(){
vector<int>koko;
koko.push_back(1);
koko.push_back(2);
koko.push_back(4);
koko.push_back(8);
koko.push_back(9);
int h=9;
cout<<minEatingSpeed(koko,h);
return 0;
}