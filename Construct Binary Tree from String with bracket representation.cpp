#include<bits/stdc++.h>
using namespace std;
struct node{
   // public:
    int data;
    node*left;
    node*right;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
node* st2tree(string s){
    stack<node*>q;
    node*root=new node(s[0]-'0');
    node*temp=root;
    q.push(root);
    for(int i=1;i<s.size();i++){
         if (s[i]==')'){
            q.pop();
        }else if(s[i]!='('){
            node*newn=new node(s[i]-'0');
            if(q.top()->left==NULL)
            q.top()->left=newn;
            else
               q.top()->right=newn;
            q.push(newn);
        }
    }
    return root;
}
void print(node* root){
    if (root == NULL)
        return;
    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
}
int main()
{   
    string s="4(2(3)(1))(6(5))";
    node*ans=st2tree(s);
    print(ans);
    return 0;
}
