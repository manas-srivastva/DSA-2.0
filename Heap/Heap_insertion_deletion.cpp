#include<iostream>
using namespace std;
class MaxHeap{
    int *arr;
    int size;// total elements in heap
    int total_size; // total size of the array

    public:
    MaxHeap(int n){
        arr=new int[n];
        size=0;
        total_size=n;
    }

    // Insert into the heap

    void insert(int value){
        // if heap is avliable or not
        if(size==total_size){
            cout<<"Heap Underflow\n";
            return;
        }
          arr[size]=value;
          int index=size;
          size++;

          // compare it with its parent
          while(index>0&& arr[(index-1)/2]<arr[index])
          {
            swap(arr[index],arr[(index-1)/2]);
            index=(index-1)/2;
          }

          cout<<arr[index]<<"is inserted into the heap\n";

    }


    void print(){
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";

            cout<<endl;
        }
    }
    
    void Heapify(int index){
        int largest=index;
        int left=2*index+1;
        int right=2*index+2;


        if(left<size&&arr[left]>arr[largest])
        largest=left;
          if(right<size&&arr[right]>arr[largest])
        largest=right;

        if(largest!=index){
            swap(arr[index],arr[largest]);
            Heapify(largest);
        }



    }



    void Delete(){
        if(size==0)
        {
            cout<<"Heap Underflow\n";
            return;
        }
        cout<<arr[0]<<" deleted from the heap\n";
        arr[0]=arr[size-1];
        size--;

        if(size==0)
        return;

        Heapify(0);
    }
};

int main(){
MaxHeap H1(6);
H1.insert(9);
H1.insert(3);
H1.insert(2);
H1.insert(44);
H1.insert(4);
H1.Delete();
H1.print();
return 0;
}