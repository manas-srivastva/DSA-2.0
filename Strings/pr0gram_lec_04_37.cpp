#include<iostream>
#include<vector>
using namespace std;
string sort(string s) {
    
   
    vector<int>alpha(26,0);
    for(int i=0;i<s.size();i++){
   
    alpha[s[i]-'a']++;
    }
    
    string ans;
    for(int i=0;i<26;i++){
        char c='a'+i;
        while(alpha[i]){
            ans+=c;
            alpha[i]--;
        }
       
    }
     return ans;
}
int main(){
string a="abrwdc";
cout<<sort(a);
return 0;
}
//         brute force using bubble sort
// #include <iostream>
// #include <cstring> // For strlen

// using namespace std;

// int main() {
//     char str[100];
//     char temp;

//     // Input the string
//     cout << "Enter a string: ";
//     cin.getline(str, 100);

//     int len = strlen(str);

//     // Bubble sort algorithm
//     for (int i = 0; i < len - 1; i++) {
//         for (int j = 0; j < len - i - 1; j++) {
//             if (str[j] > str[j + 1]) {
//                 // Swap characters
//                 temp = str[j];
//                 str[j] = str[j + 1];
//                 str[j + 1] = temp;
//             }
//         }
//     }

//     // Output the sorted string
//     cout << "Sorted string: " << str << endl;

//     return 0;
// }
