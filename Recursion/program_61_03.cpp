#include<iostream>
#include<vector>
using namespace std;
// sum of all subsequences
void subsequence(int arr[],int index,int n, vector<vector<int>>&ans,vector<int>temp)
{
    if(index==n){
        ans.push_back(temp);
        return;
    }

    // not included
    subsequence(arr,index+1,n,ans,temp);
    // included
    temp.push_back(arr[index]);
    subsequence(arr,index+1,n,ans,temp);
    temp.pop_back(); // for O(n) space complexity 
}

int main(){
int arr[]={1,2,3};
int n=sizeof(arr)/sizeof(arr[0]);
vector<vector<int>>ans;
vector<int>temp;
subsequence(arr,0,n,ans,temp);
int sum=0;
for(int i=0;i<ans.size();i++){
     cout << "Subsequence: [ ";
    for(int j=0;j<ans[i].size();j++){
          cout << ans[i][j] << " ";
        sum+=ans[i][j];
    }
     cout << "] --> Sum = " << sum << endl;
    sum=0;
   
}
return 0;
}