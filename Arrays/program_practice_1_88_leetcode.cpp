#include<iostream>
#include<vector>
using namespace std;
   void mergesortedarray(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            if(n == 0)return;
        int len1 = nums1.size();
        int end_idx = len1-1;
        while(n > 0 && m > 0){
            if(nums2[n-1] >= nums1[m-1]){
                nums1[end_idx] = nums2[n-1];
                n--;
            }else{
                nums1[end_idx] = nums1[m-1];
                m--;
            }
            end_idx--;
        }
        while (n > 0) {
            nums1[end_idx] = nums2[n-1];
            n--;
            end_idx--;
        }
    }
int main(){
vector<int>nums1;
vector<int>nums2;
nums1.push_back(1);
nums1.push_back(2);
nums1.push_back(3);
nums2.push_back(1);
nums2.push_back(2);
nums2.push_back(2);
nums2.push_back(3);
nums2.push_back(5);
nums2.push_back(6);
mergesortedarray(nums1,9,nums2,3);
return 0;
}