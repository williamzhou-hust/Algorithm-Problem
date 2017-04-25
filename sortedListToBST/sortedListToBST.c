/*************************************************************************
	> File Name: sortedListToBST.c
	> Author: williamzhou
	> Mail: williamzhou.0330@foxmail.com 
	> Created Time: Mon 24 Apr 2017 07:40:30 AM PDT
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

struct __ListNode{
	int value;
	struct __ListNode* next;
};

typedef struct __ListNode ListNode;

struct __TreeNode{
	int value;
	struct __TreeNode* left;
	struct __TreeNode* right;
};

typedef struct __TreeNode TreeNode;

void swap(int* a,int* b){
	if(a==b) return;
	int temp=*a;
	*a=*b;
	*b=temp;
	return;
}

ListNode* mergeSortList(ListNode* ls){
	if(!ls||!ls->next) return ls;
	if(!ls->next->next){
		if(ls->value>ls->next->value){
			swap(&ls->value,&ls->next->value);
		}
		return ls;
	}
	ListNode* p=ls;
	while(p){
		printf("%d ",p->value);
		p=p->next;
	}
	printf("\n");
	ListNode* __mergeSortList(ListNode* a,ListNode* b);
	ListNode* pslow=ls;
	ListNode* pquick=ls->next;
	/*while(pquick){
		if(pquick)
			pquick=pquick->next;
		if(pquick)
			pquick=pquick->next;
		else break;
		if(pslow)
			pslow=pslow->next;
	}*/
	while(pslow->next&&pquick->next&&pquick->next->next){
		pquick=pquick->next->next;
		pslow=pslow->next;
	}
	printf("outloop\n");
	printf("pslow:%d pslow->next:%d\n",pslow->value,pslow->next->value);
	pquick=pslow->next;
	pslow->next=NULL;
	ls=mergeSortList(ls);
	pquick=mergeSortList(pquick);
	ls=__mergeSortList(ls,pquick);
	return ls;
}

ListNode* __mergeSortList(ListNode* a,ListNode* b){
	if(a==NULL) return b;
	if(b==NULL) return a;
	//ListNode* result=NULL;
	if(a->value<b->value){
		//result=a;
		a->next=__mergeSortList(a->next,b);
		return a;
	}
	else{
		//iresult=b;
		b->next=__mergeSortList(a,b->next);
		return b;
	}
	return NULL;
}

void quicksort(ListNode* ls){
	void __quicksort_aux(ListNode* ls,ListNode* lsend);
	__quicksort_aux(ls,NULL);
	return;
}

void __quicksort_aux(ListNode* ls,ListNode* lsend){
	if(ls==lsend||ls->next==lsend){
		return;
	}
	ListNode* patition(ListNode* ls,ListNode* lsend);
	ListNode* pend=NULL;
	ListNode* pstart=NULL;
	pend=patition(ls,lsend);
	pstart=pend->next;
	__quicksort_aux(ls,pend);
	__quicksort_aux(pstart,lsend);
	return;
}

ListNode* patition(ListNode* ls,ListNode* lsend){
	if(ls==lsend||ls->next==lsend) return ls;
	ListNode* p=ls;
	int flag=ls->value;
	ListNode* q=ls->next;
	while(q!=lsend){
		if(q->value<flag){
			p=p->next;
			swap(&p->value,&q->value);
		}
		q=q->next;
	}
	swap(&ls->value,&p->value);
	return p;
}

int shuff[7]={0,3,4,2,1,5,6};
int ind=6;

int shuffle(){
	int ans=0,j=0;
	if(ind>0){
		j=rand()%ind;
		ans=shuff[j];
		swap(shuff+j,shuff+ind);
	}
	else if(ind==0) ans=shuff[0];
	--ind;
	if(ind==-1) ind=6;
	return ans;
}

ListNode node[7];
void initnode(){
	int i=0;
	printf("Before Sort:\n");
	for(i=0;i<7;i++){
		node[i].value=shuffle();
		printf("%d ",node[i].value);
		if(i<6)
			node[i].next=&node[i+1];
		else
			node[i].next=NULL;
	}
	printf("\n");
}

int main(){
	initnode();
	ListNode* p=node;
	while(p){
		printf("%d ",p->value);
		p=p->next;
	}
	printf("\nstart sort!\n");
	p=mergeSortList(node);
	//quicksort(node);
	//p=node;
	printf("After sort:\n");
	int vnode[7];
	int i=0;
	for(i=0;i<7;i++){
		printf("%d ",p->value);
		vnode[i]=p->value;
		p=p->next;
	}
	TreeNode* sortedListToBST(int* v,int i,int j);
	void printTreeNode(TreeNode* root);
	printf("\nbinary search tree:\n");
	printTreeNode(sortedListToBST(vnode,0,6));
	printf("\n");
	return 0;
}

TreeNode* sortedListToBST(int* v,int i,int j){
	int mid=i+(j-i)/2;
	TreeNode* proot=(TreeNode*)malloc(sizeof(TreeNode));
	memset(proot,0,sizeof(TreeNode));
	proot->value=v[mid];
	proot->left=NULL;
	proot->right=NULL;
	if(i==j)
		return proot;
	if(i>j) return NULL;
	proot->left=sortedListToBST(v,i,mid-1);
	proot->right=sortedListToBST(v,mid+1,j);
	return proot;
}

void printTreeNode(TreeNode* root){
	if(root==NULL) return;
	printf("%d ",root->value);
	if(root->left) printTreeNode(root->left);
	if(root->right) printTreeNode(root->right);
	free(root);
	return;
}
