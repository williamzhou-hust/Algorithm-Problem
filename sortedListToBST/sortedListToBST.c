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
void swap(int* a,int* b){
	if(a==b) return;
	int temp=*a;
	*a=*b;
	*b=temp;
	return;
}

void mergeSortList(ListNode* ls){
	if(!ls||!ls->next) return;
	if(!ls->next->next){
		if(ls->value>ls->next->value){
			swap(&ls->value,&ls->next->value);
		}
	}
	ListNode* __mergeSortList(ListNode* a,ListNode* b);
	ListNode* pslow=ls;
	ListNode* pquick=ls;
	while(pquick){
		int i=0;
		for(i=0;i<1;i++){
			if(pquick)
				pquick=pquick->next;
		}
		if(pslow)
			pslow=pslow->next;
	}
	pquick=pslow->next;
	pslow->next=NULL;
	mergeSortList(ls);
	mergeSortList(pquick);
	ls=__mergeSortList(ls,pquick);
	return;
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
		if(i<6) node[i].next=&node[i+1];
	}
	node[i].next=NULL;
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
	mergeSortList(node);
	printf("After merge sort:\n");
	int i=0;
	for(i=0;i<7;i++){
		printf("%d ",node[i].value);
	}
	printf("\n");
	return 0;
}
