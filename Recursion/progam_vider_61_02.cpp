#include<iostream>
#include<vector>
using namespace std;
void parenth(int n,int left,int right,vector<string>&ans, string &temp){
    
    if(left+right==2*n){
        ans.push_back(temp);
        return;
    }
    // left parenth
    if(left<n){
        temp.push_back('(');
        parenth(n,left+1,right,ans,temp);
        temp.pop_back();
    }
    if(right<left){
        temp.push_back(')');
        parenth(n,left,right+1,ans,temp);
        temp.pop_back();
        }
    }

int main(){
vector<string>ans;
string temp;
int n=3; // number of pairs of parenthesis
parenth(n, 0, 0, ans, temp);
return 0;
}