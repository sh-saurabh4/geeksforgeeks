#include<bits/stdc++.h>
using namespace std;
struct node{
  int data;
  int dp;
  struct node *left,*right;
};
node * new_node(int data){
  node *temp;
  temp = (node *)malloc(sizeof(node));
  temp->data = data;
  temp->left = temp->right = NULL;temp->dp = -1;
  return temp;
}
int ls(node *root){
  if(root == NULL)
    return 0;
  if(root->dp != -1)
    return root->dp;
  int temp1=0,temp2=0;
  if(root->left != NULL){
    temp1 += ls(root->left);
    temp2 += ls(root->left->left) + ls(root->left->right);
  }
  if(root->right != NULL){
    temp1 += ls(root->right);
    temp2 += ls(root->right->left)+ls(root->right->right);
  }
  return root->dp = max(temp1,1+temp2);
}
int main(){
  node *root;
  root = new_node(10);
  root->left = new_node(20);
  root->right = new_node(30);
  root->left->left = new_node(40);
  root->left->right = new_node(50);
  root->right->right = new_node(60);
  root->left->right->left = new_node(70);
  root->left->right->right = new_node(80);
  cout << ls(root);
  return 0;
}
