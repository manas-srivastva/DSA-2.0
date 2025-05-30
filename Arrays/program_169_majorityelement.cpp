#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int majorityElement(vector<int>& nums) {
    // code 
    int n=nums.size();
         if(n == 0){
            return -1;
        }
        if(n == 1){
            return nums[0];
        }

        sort(nums.begin(),nums.end());
        int count = 1;
        
        for(int i = 0; i < n - 1; i++){
            if(nums[i] == nums[i + 1]){
                count++;
            } else {
                count = 1; // reset count when sequence breaks
            }
            if(count > n / 2){
                return nums[i];
            }
        }
        
        return -1;
    }
    
int main(){
vector<int>nums;
nums.push_back(3);
nums.push_back(2);
nums.push_back(3);

cout<<majorityElement(nums);
return 0;
}