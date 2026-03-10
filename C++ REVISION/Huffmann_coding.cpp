#include<iostream>
#include<queue>
#include<map>
using namespace std;
struct node {
    char ch;
    int freq;
    node *left,*right;
};
node* createNode(char c,int f){
    node* temp=new node();
    temp->ch=c;
    temp->freq=f;
    temp->left=temp->right=NULL;
    return temp;
}

void printCodes(node* root, string code, map<char,string> &huff){
    if(root==NULL) return;
    if(root->left==NULL && root->right==NULL)
    huff[root->ch]=code;

    printCodes(root->left,code+"0",huff);
    printCodes(root->right,code+"1",huff);
}

int main(){
int n;
cin>>n;
priority_queue<pair<int,node*>,vector<pair<int,node*>>,greater<pair<int,node*>>>pq;
for(int i=0;i<n;i++){
    char ch;
    int f;
    cin>>ch>>f;
    pq.push({f,createNode(ch,f)});
}

while(pq.size()>1){
    node* left=pq.top().second; pq.pop();
    node* right=pq.top().second; pq.pop();

    node* parent=createNode('$',left->freq+right->freq);
    parent->left=left;
    parent->right=right;
    pq.push({parent->freq,parent});
}
 node* root = pq.top().second;

    map<char,string> huff;
    printCodes(root, "", huff);

    string msg;
    cin >> msg;

    string encoded = "";

    for(char c : msg) {
        cout << c << ": " << huff[c] << endl;
        encoded += huff[c];
    }

    cout << encoded;
return 0;
}