/*************************************************************************
	> File Name: isTreeAcontainsTreeB.c
	> Author: williamzhou
	> Mail: williamzhou.0330@foxmail.com 
	> Created Time: Mon 24 Apr 2017 06:58:57 AM PDT
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define false 0
#define true 1

struct __TreeNode{
	int value;
	struct __TreeNode* left;
	struct __TreeNode* right;
};

typedef struct __TreeNode TreeNode;

int __isTreeAcontainsTreeB(TreeNode* a,TreeNode* b){
	if(a==NULL&&b==NULL) return 1;
	if(a==NULL&&b!=NULL) return 0;
	if(a!=NULL&&b==NULL) return 0;
	if(a->value==b->value)
		return __isTreeAcontainsTreeB(a->left,b->left)&&__isTreeAcontainsTreeB(a->right,b->right);
	else
		return 0;
}

int isTreeAcontainsTreeB(TreeNode* rootA,TreeNode* rootB){
	if(rootA==NULL&&rootB==NULL) return 1;
	if(rootA==NULL&&rootB!=NULL) return 0;
	if(rootA!=NULL&&rootB==NULL) return 0;
	if(__isTreeAcontainsTreeB(rootA,rootB))
		return 1;
	else return __isTreeAcontainsTreeB(rootA->left,rootB)&&__isTreeAcontainsTreeB(rootA->right,rootB);
}

TreeNode node[8];
TreeNode subnode[3];
void initTree(){
	int i=0;
	for(i=0;i<8;i++){
		node[i].value=i;
		node[i].left=NULL;
		node[i].right=NULL;
		if(i<3){
			subnode[i].left=NULL;
			subnode[i].right=NULL;
		}
	}
	node[0].left=&node[1];
	node[0].right=&node[2];
	node[1].left=&node[3];
	node[1].left=&node[4];
	node[4].left=&node[5];
	node[4].left=&node[6];
	node[5].right=&node[7];
	node[5].right=NULL;
	subnode[0].right=&subnode[1];
	subnode[0].value=1;
	subnode[1].right=&subnode[2];
	subnode[1].value=5;
	subnode[2].value=6;
	return;
}

int main(){
	initTree();
	if(isTreeAcontainsTreeB(&node[0],&subnode[0]))
		printf("A contains B!\n");
	else printf("A isn't contains B\n");
	return 0;
}
