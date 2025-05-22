
// palindrome using recursion

// #include<iostream>
// using namespace std;
// bool checkpal(string str,int start,int end){
//     if(start>=end){
//         return 1;
//     }
//     if(str[start]!=str[end]){
//         return 0;
//     }
//     return checkpal(str,start+1,end-1);
// }
// int main(){
// string s="madam";
// int n=s.length();
// bool ans=checkpal(s,0,n-1);
// cout<<ans;
// return 0;
// }

//              count vowels using recursion
// #include<iostream>
// using namespace std;
// int count(string str,int index){
//     if(index==-1){
//         return 0;
//     }
//     if(str[index]=='a'||str[index]=='e'||str[index]=='i'||str[index]=='o'||str[index]=='u'){
//         return 1+count(str,index-1);
//     }
//     else{
//         return count(str,index-1);
//     }
// }
// int main(){
// string s="madam";
// int n=s.length();
// int ans=count(s,n-1);
// cout<<ans;
// return 0;
// }

//           LowerCase to UpperCase using recursion
// #include<iostream>
// using namespace std;
// void LowerToUpper(string str,int index){
//     if(index==-1)
//     return ;

//     str[index]='A'+str[index]-'a';
//     LowerToUpper(str,index-1);
//     cout<<str[index];
// }
// int main(){
// string s="madam";
// int n=s.length();
// LowerToUpper(s,n-1);

// return 0;
// }



// reverse a string using recursion
#include<iostream>
using namespace std;
void  rev(string &str,int start,int end){
if(start>=end){
    return;
}
char c=str[start];
str[start]=str[end];
str[end]=c;
rev(str,start+1,end-1);
}
int main(){
string str="rohit";
rev(str,0,4);
cout<<str<<endl;
return 0;
}