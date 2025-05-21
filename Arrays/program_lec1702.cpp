// #include<iostream>
// using namespace std;
// int main(){
// int aarr[5]={1,2,3,4,5};
// int start=0;
// int end=4;
// while(start<end){
//     swap(aarr[start],aarr[end]);
//     start++;
//     end--;
// }
// for(int i=0;i<5;i++){
//     cout<<aarr[i]<<" ";
// }
// return 0;
// }





// second largest element in an array
// #include<iostream>
// using namespace std;
// int secondLargest(int arr[],int n){
//     int ans=-1;
//     for(int i=0;i<n;i++){
//         if(arr[i]>ans)
//         ans=arr[i];
//     }
//     int secondlargest=-1;
//      for(int i=0;i<n;i++)
//      {
//         if(arr[i]!=ans){
//             secondlargest =max(secondlargest,arr[i]);
//         }
//      }
//      return secondlargest;
// }
// int main(){
// int arr[5]={22,33,44,33,22};
// int n=5;
// int secondlargest=secondLargest(arr,n);
// cout<<secondlargest;
// return 0;
// }

                    // Missing number in an array

//   #include<iostream>
//   using namespace std;
//   int MissingNumber(int arr[],int n){
//     int total=(n*(n+1)/2);
//     int sum=0;
//     for(int i=0;i<n-1;i++){
//         sum+=arr[i];
//     }
//     return total-sum;
//   }
//   int main(){
//   int arr[6]={1,2,3,4,5};
//   int n=6;
//   cout<<MissingNumber(arr,n);
//   return 0;
//   }           



// fibonacci series 

// #include<iostream>
// using namespace std;

// int main(){
// int n;
// cin>>n;
// int arr[1000];

// arr[0]=1;
// arr[1]=1;
// for(int i=2;i<=n;i++){
//     arr[i]=arr[i-1]+arr[i-2];
    
// }



// cout<<arr[n-1]<<" ";
// return 0;
// }



// rotate array by 1
#include<iostream>
using namespace std;
void rotate(int arr[],int n){
    int last=arr[n-1];
    for(int i=n-2;i>=0;i--){
        arr[i+1]=arr[i];
    }
    arr[0]=last;

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
int n=5;
int arr[5]={1,2,44,55,3};
rotate(arr,n);
return 0;
}