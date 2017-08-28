#include<bits/stdc++.h>
using namespace std;
struct node{
  int data;
  node *left,*right;
};
node * insert(node* root,int data){
  if(root == NULL){
    node *temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
  }
  else if(root->data < data)
    root->right = insert(root->right,data);
  else
    root->left = insert(root->left,data);
  return root;
}
void inorder(node *root){
  if(root == NULL)
    return;
  inorder(root->left);
  cout << root->data << " ";
  inorder(root->right);
}

int main(){
  int n;
  cin >> n;
  node *root = NULL;
  for(int i = 0; i < n; i++){
    int data;
    cin >> data;
    root = insert(root,data);
  }
  inorder(root);
  return 0;
}
