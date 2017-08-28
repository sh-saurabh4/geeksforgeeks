#include<bits/stdc++.h>
using namespace std;
struct node{
  int data;
  node * left,*right;
  int dp;
};
node * new_node(int data){
  node *temp = (node *)malloc(sizeof(node));
  temp->data = data;
  temp->left = temp->right = NULL;
  temp->dp = -1;
  return temp;
}
int find(node *root){
  if(root == NULL)
    return 0;
  if(root->dp != -1)
    return root->dp;
  int t1 = 1+find(root->left)+find(root->right);
  int t2 = 0;
  if(root->left != NULL)
    t2 += 1 + find(root->left->left)+find(root->left->right);
  if(root->right != NULL)
    t2 += 1 + find(root->right->left)+find(root->right->left);
  return root->dp = min(t1,t2);
}
int main(){
      node *root = NULL;
      root = new_node(10);
      root->left = new_node(20);
      root->right = new_node(30);
      root->left->left = new_node(40);
      root->left->right = new_node(50);
      root->right->right = new_node(60);
      root->left->right->left = new_node(70);
      root->left->right->right = new_node(80);
      cout << find(root);
      return 0;
}
