#include<stdio.h>
#include<malloc.h>
struct node{
	int data, hd;
	struct node  *left;
	struct node *right;
};
struct node * newnode(int data){
	struct node *p = (struct node *)malloc(sizeof(struct node));
	p->right = NULL;
	p->left = NULL;
	p->data = data;
	return p;
}

void calhd(struct node *root , int hd, struct node **arr){
	if(root != NULL){
		if(arr[hd + 10] == NULL)
			arr[hd + 10] = newnode(root->data);
		else { 
			struct node *p = arr[hd + 10];
			while (p -> right != NULL )
				p = p->right;
			p->right = newnode(root->data);
		}
		calhd(root->left,hd - 1,arr);
		calhd(root->right,hd + 1,arr);
	}
}
		
		

void print_vertical(struct node **arr){
	int i;
	struct node *p;
	for(i = 0; i < 20; i++){
		p = arr[i];
		while(p != NULL){
			printf("%d ",p->data);
			p = p->right;
		}
		if(arr[i] != NULL)
			printf("\n");
	}
}
		
	


int main(){
	struct node *arr[20]={NULL},i;
	struct node *root;
	root = newnode(1);
	root->left = newnode(2);
	root->right = newnode(3);
	root->left->left = newnode(4);
	root->left->right = newnode(5);
	root->right->left = newnode(6);
	root->right->right = newnode(7);
	root->right->left->right = newnode(8);
	root->right->right->right = newnode(9);
	calhd(root,0,arr);
	print_vertical(arr);
	return 0;
}
		
