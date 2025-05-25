// Print sum of each column in 2d array
// #include<iostream>
// using namespace std;
// void sumofeachcolumn(int arr[][3],int row,int col){
//    int  sum=0;
//    for(int i=0;i<row;i++){
//    sum=0;
//    for(int j=0;j<col;j++){
//      sum+=arr[j][i];
//    }
//    cout<<"Sum of column is "<<sum<<endl;
//    }
// }
// int main(){
// int arr[3][3]={1,2,3,4,5,6,7,8,9};
// int row=3;
// int col=3;
// sumofeachcolumn(arr,row,col);
// return 0;
// }

//              print sum of diagonal remove the common middle element
#include<iostream>
using namespace std;
void printsumofdiag(int arr[][3],int row,int col){
    int sum1=0,sum2=0;
    int sum3=0;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++)
        {
            if(i==j)
            sum1+=arr[i][i];
        }
        
    }

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if((i+j)==2&& i!=j ){
                sum2+=arr[i][j];
            }
        }
    }
    sum3=sum1+sum2;
    cout<<"The sum of  Diagonal is "<<" "<<sum3<<endl;
    

}
int main(){
int arr[3][3]={1,2,3,4,5,6,7,8,9};
int row=3;
int col=3;
printsumofdiag(arr,row,col);
return 0;
}