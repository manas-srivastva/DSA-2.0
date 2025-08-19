#include<stdio.h>
#include<conio.h>

int main(){
    int i,start,end,c=0,n,mid;
    int arr[10];
    printf("Enter the Elements in the array");
    for(i=0;i<10;i++){
        scanf("%d",&arr[i]);
    }

    printf("Enter the Elements to be searched");
    scanf("%d",&n);

    start=0;
    end=9;
    while(start<end){
        mid=(start+end)/2;
        if(arr[mid]<n){
            start=mid+1;
        }
        else if(arr[mid]==n)
        {
            
            c=1;
            break;
        }
        else if(arr[mid]>n){
            end=mid-1;
        }
    }
    if(c==1){
        printf(" Element Found at posistion %d",mid);
    }
    else{
        printf("Element Not found");
    }
}