#include<iostream>
using namespace std;
void merge(int a[],int l,int m,int r){
int temp[100];
int i=l, j=m+1,k=l;

while(i<=m && j<=r){
    if(a[i]<a[j])
    temp[k++]=a[i++];
    else
    temp[k++]=a[j++];
}

while(i<=m)
temp[k++]=a[i++];

while(j<=r)
temp[k++]=a[j++];

for(int i=l;i<=r;i++)
a[i]=temp[i];
}

void mergesort(int a[],int l,int r){
    if(l<r){
        int m=(l+r)/2;

        mergesort(a,l,m);
        mergesort(a,m+1,r);
        merge(a,l,m,r);
    }
}
int main(){
int n, a[100];

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    mergesort(a, 0, n - 1);

    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
return 0;
}