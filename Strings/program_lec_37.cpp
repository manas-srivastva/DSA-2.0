#include<iostream>
using namespace std;
string defangIPaddr(string address) {
        int index=0;
        string ans;
        while(index<address.size()){
            if(address[index]=='.')
            ans=ans+"[.]";
            else
            ans=ans+address[index];
            index++;
        }
        return ans;
    }
int main(){
string s="234.221.23";
cout<<defangIPaddr(s);
return 0;
}