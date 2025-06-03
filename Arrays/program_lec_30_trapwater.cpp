#include<iostream>
#include<vector>
using namespace std;
int trap(vector<int>& height) {
        int n=height.size();
        int maxleft=0,maxright=0,water=0;
      int maxHeight=height[0],index=0;
        for(int i=1;i<n;i++){
            if(height[i]>maxHeight)
            {
                maxHeight=height[i];
            index=i;
            }
        }
        // left part
        for(int i=0;i<index;i++){
            if(maxleft>height[i])
            water+=maxleft-height[i];
            else
            maxleft=height[i];
        }

        // right part
           for(int i=n-1;i>index;i--){
            if(maxright>height[i])
            water+=maxright-height[i];
            else
            maxright=height[i];
        }
        return water;
    }
int main(){
    // [0,1,0,2,1,0,1,3,2,1,2,1]
vector<int>height;
height.push_back(0);
height.push_back(1);
height.push_back(0);
height.push_back(2);
height.push_back(1);
height.push_back(0);
height.push_back(1);
height.push_back(3);
height.push_back(2);
height.push_back(1);
height.push_back(2);
height.push_back(1);
cout<<trap(height);
return 0;
}