#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int> nextLargerElement(vector<int> &arr) {
        // code here
        int n= arr.size();
        stack<int>st;
        vector<int>a(n,-1);
        for(int i=0;i<2*n;i++){
             while (!st.empty() && arr[st.top()] < arr[i % n]){
                a[st.top()]=arr[i%n];
                st.pop();
            }
            if(i<n)
            st.push(i%n);
        }
        return a;
    }
int main(){
 vector<int> arr = {8, 6, 4, 7, 4, 9, 10, 8, 12};
     vector<int> result = nextLargerElement(arr);
    
    for(int val : result) {
        cout << val << " ";
    }
    cout << endl;
return 0;
}