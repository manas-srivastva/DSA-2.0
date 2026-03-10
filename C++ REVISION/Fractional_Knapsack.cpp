#include<iostream>
#include<iomanip>
using namespace std;

double maxWorth(int n,int weight[],int value[],int capacity){
    double ratio[n];

    for(int i=0;i<n;i++)
        ratio[i]=(double)value[i]/weight[i];
        
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(ratio[i]<ratio[j])
                {
                    swap(ratio[i],ratio[j]);
                    swap(weight[i],weight[j]);
                    swap(value[i],value[j]);
                }
            }
        }
        double total=0.0;
        for(int i=0;i<n;i++){
            if(capacity>=weight[i]){
                total+=value[i];
                capacity-=weight[i];
            }
            else{
                total+=ratio[i]*capacity;
                break;
            }
        }
        return total;

    
}

int main(){
int n;
    cin >> n;

    int weight[n], value[n];

    for(int i = 0; i < n; i++)
        cin >> weight[i];

    for(int i = 0; i < n; i++)
        cin >> value[i];

    int capacity;
    cin >> capacity;

    double result = maxWorth(n, weight, value, capacity);

    cout << "Objects worth Rs." << fixed << setprecision(2) << result;
return 0;
}