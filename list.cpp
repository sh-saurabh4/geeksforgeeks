#include<bits/stdc++.h>
using namespace std;
struct node{
  int data;
  node *next;
};
node* newnode(int data){
  node *p = (node*)malloc(sizeof(node));
  p->data = data;
  p->next = NULL;
  return p;
}
node* insert(node* head,int n){
  node *p,*q;
  while(n--){
    int data;
    cin >> data;
    if(head == NULL){
      q = head = newnode(data);
    }
    else{
      p = newnode(data);
      q->next = p;
      q = p;
    }
  }
  return head;
}

void print(node *head){
  while(head != NULL){
    cout << head->data;
    head = head->next;
  }
}

node * rev(node *head){
  if(head->next == NULL)
    return head;
  node *p = rev(head->next);
  head->next->next = head;
  head->next = NULL;
  return p;
}

int main(){
  int n;
  node *head = NULL;
  cin >> n;
  head = insert(head,n);
  head = rev(head);
  print(head);
  return 0;
}
