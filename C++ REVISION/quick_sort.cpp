#include<iostream>
using namespace std;
int partition(int arr[],int low,int high){
    int pivot=arr[low];
    int i=low+1;
    int j=high;

    while(i<j)
    {
        while(i<=high && arr[i]<pivot)
        i++;

        while(arr[j]>pivot)
        j--;

        if(i<j)
        swap(arr[i],arr[j]);
        else
        break;
    }

    swap(arr[low],arr[j]);
    return j;
}

// QUICKSORT FUNCTION
void quicksort(int arr[],int low, int high)
{
    if(low<high){
        int pi=partition(arr,low,high);
        quicksort(arr,low,pi-1);
        quicksort(arr,pi+1,high);
    }
}
