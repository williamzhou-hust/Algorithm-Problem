/*************************************************************************
	> File Name: traverse_tree.cpp
	> Author: williamzhou
	> Mail: williamzhou.0330@foxmail.com 
	> Created Time: Wed 23 Aug 2017 12:11:23 AM PDT
 ************************************************************************/

#include <iostream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

typedef struct node{
	char data;
	node* left;
	node* right;
} node;

typedef node* Tree;

void createBitree(Tree& root){
	char ch=' ';
	scanf("%c",&ch);
	if(ch==' '){
		root=NULL;
		return;
	}
	else{
		root=(node*)malloc(sizeof(node));
		root->left=NULL;
		root->right=NULL;
		if(!root) exit(1);
		else{
			root->data=ch;
			createBitree(root->left);
			createBitree(root->right);
		}
	}
}

void preorderTree(Tree root){
	if(!root) return;
	else{
		printf("%c",root->data);
		preorderTree(root->left);
		preorderTree(root->right);
	}
}

void inorderTree(Tree root){
	if(!root) return;
	else{
		inorderTree(root->left);
		printf("%c",root->data);
		inorderTree(root->right);
	}
}

void postorderTree(Tree root){
	if(!root) return;
	else{
		postorderTree(root->left);
		postorderTree(root->right);
		printf("%c",root->data);
	}
}

void preorderTree_2(Tree root){
	if(!root){
		printf("this is a empty tree!");
		return;
	}
	stack<node*> stk;
	while(root||!stk.empty()){
		while(root){
			printf("%c",root->data);
			stk.push(root);
			root=root->left;
		}
		node* top=stk.top();
		stk.pop();
		root=top->right;
	}
}

void inorderTree_2(Tree root){
	if(!root){
		printf("this tree is a empty tree!");
		return;
	}
	stack<node*> stk;
	while(root||!stk.empty()){
		while(root){
			stk.push(root);
			root=root->left;
		}
		node* top=stk.top();
		printf("%c",top->data);
		stk.pop();
		root=top->right;
	}
}

void postorderTree_2(Tree root){
	if(!root){
		printf("this tree is a empty tree!");
		return;
	}
	int isTravel[100];
	for(int i=0;i<100;i++){
		isTravel[i]=0;
	}
	stack<node*> stk;
	while(root){
		stk.push(root);
		isTravel[stk.size()]=0;
		root=root->left;
	}
	while(!stk.empty()){
		root=stk.top();
		while(root->right && isTravel[stk.size()]==0){
			isTravel[stk.size()]=1;
			root=root->right;
			if(root){
				stk.push(root);
				isTravel[stk.size()]=0;
			}
			while(root->left){
				stk.push(root->left);
				isTravel[stk.size()]=0;
				root=root->left;
			}
		}
		root=stk.top();
		printf("%c",root->data);
		stk.pop();
	}
}

void postOrderTraverse(Tree T){
	int flag[20];
	stack<Tree> stk;
	if(!T){
		printf("Empty Tree!");
		return;
	}
	while(T){
		stk.push(T);
		flag[stk.size()]=0;
		T=T->left;
	}
	while(!stk.empty()){
		T=stk.top();
		while(T->right&&flag[stk.size()]==0){
			flag[stk.size()]=1;
			T=T->right;
			if(T){
				stk.push(T);
				flag[stk.size()]=0;
			}
			while(T->left){
				stk.push(T->left);
				flag[stk.size()]=0;
				T=T->left;
			}
		}
		T=stk.top();
		printf("%c",T->data);
		stk.pop();
	}
}

int main(int argc,char* argv[]){
	Tree root;
	createBitree(root);
	preorderTree(root);
	printf("\n");
	preorderTree_2(root);
	printf("\n");
	inorderTree(root);
	printf("\n");
	inorderTree_2(root);
	printf("\n");
	postorderTree(root);
	printf("\n");
	postorderTree_2(root);
	printf("\n");
	return 0;
}
