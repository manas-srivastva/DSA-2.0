


// *************   2D ARRAY USING A VECTOR**********************

// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;
// int main(){
// // Create a 2D vector
//  vector<vector<int> >matrix(3,vector<int>(4,1));
//  for(int i=0;i<3;i++){
//     for(int j=0;j<4;j++){
//         cout<<matrix[i][j]<<" ";
//     }
//  }
//  cout<<endl;
//  cout<<"ROWS= "<<matrix.size();
//  cout<<endl;
//  cout<<"Cols = "<<matrix[0].size();
// return 0;
// }

#include<iostream>
using namespace std;
void spiralmatrix(int arr[][4],int row,int col){
    int top=0;
    int ans[4][4];
    
    int bottom=row-1,left=0,right=col-1;
    while(top<=bottom&&left<=right){
        // print top
        for(int j=left;j<=right;j++)
        cout<<arr[top][j]<< " ";
        top++;

        // print right
        for(int i=top;i<=bottom;i++)
        cout<<arr[i][right]<<" ";
        right--;

        // print bottom
        if(top<=bottom){
            for(int j=right;j>=left;j--){
                 cout<<arr[bottom][j]<<" ";
                
            }
            bottom--;
        }
        // print left
        if(left<=right){
            for(int i=bottom;i>=top;i--){
                cout<<arr[i][left]<<" ";
               
            }
             left++;
        }
    }
}
int main(){
int arr[4][4]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
int row=4;
int col=4;
spiralmatrix(arr,row,col);
return 0;
}