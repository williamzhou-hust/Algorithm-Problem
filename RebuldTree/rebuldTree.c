/*************************************************************************
	> File Name: rebuldTree.c
	> Author: williamzhou
	> Mail: williamzhou.0330@foxmail.com 
	> Created Time: Mon 24 Apr 2017 11:29:05 PM PDT
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct __TreeNode{
	int value;
	struct __TreeNode* left;
	struct __TreeNode* right;
};
typedef struct __TreeNode TreeNode;

int main(){
	int preorder[10]={4,5,7,9,8,10,11,6,12};
	int inorder[10]={9,7,5,10,8,11,4,6,12};
	TreeNode* rebulidTree(int* pre,int i,int j,int* in,int k,int m);
	void printTreeAftorder(TreeNode* root);
	TreeNode* root=rebulidTree(preorder,0,9,inorder,0,9);
	printf("cout the tree with aft order\n");
	printTreeAftorder(root);
	printf("\n");
	return 0;
}

TreeNode* rebulidTree(int* pre,int i,int j,int* in,int k,int m){
	if(i>j||k>m) return NULL;
	TreeNode* root=(TreeNode*)malloc(sizeof(TreeNode));
	root->value=pre[i];
	root->left=NULL;
	root->right=NULL;
	if(i==j&&k==m) return root;
	int p=0; 
	for(p=k;p<=m;p++){
		if(in[p]==root->value)
			break;
	}
	int q=i+p-k;
	root->left=rebulidTree(pre,i+1,q,in,k,p-1);
	root->right=rebulidTree(pre,q+1,j,in,p+1,m);
	return root;
}

void printTreeAftorder(TreeNode* root){
	if(root==NULL) return;
	if(root->left) printTreeAftorder(root->left);
	if(root->right) printTreeAftorder(root->right);
	printf("%d ",root->value);
	return;
}
