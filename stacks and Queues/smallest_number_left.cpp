#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> leftSmaller(vector<int> arr) {
        // code here
        int n=arr.size();
        stack<int>st;
        vector<int>ans(n,-1);
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&& arr[st.top()]>arr[i]){
                ans[st.top()]=arr[i];
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
int main(){
vector<int> arr = {8, 6, 4, 7, 4, 9, 10, 8, 12};
 vector<int> result = leftSmaller(arr);
 for(int val : result) {
        cout << val << " ";
    }
    cout << endl;
return 0;
}