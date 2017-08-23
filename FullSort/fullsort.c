/*************************************************************************
	> File Name: fullsort.c
	> Author: williamzhou
	> Mail: williamzhou.0330@foxmail.com 
	> Created Time: Fri 28 Apr 2017 12:06:43 AM PDT
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void swap(int* a,int* b){
	if(a==b) return;
	int temp=*a;
	*a=*b;
	*b=temp;
	return;
}

int isHaveKLTN(int* a,int n,int k){
	int count=0;
	int i=0;
	for(i=0;i<n;i++){
		if(a[i]<a[i+1]){
			++count;
		}
		if(count>k){
			return 0;
		}
	}
	if(count==k) return 1;
	else return 0;
}

void NumOfFullSortKLTN(int n,int k){
	int* a=(int*)malloc(n*sizeof(int));
	int i=0;
	for(i=0;i<n;i++) a[i]=i+1;
	void permutation(int* a,int n,int k,int start,int end);
	permutation(a,n,k,0,n-1);
	free(a);
	return; 
}

int LTKcount=0;

void permutation(int* a,int n,int k,int start,int end){
	if(!a){
		printf("wrong input!\n");
	}
	if(start>end) return;
	if(start==end&&isHaveKLTN(a,n,k)) ++LTKcount;
	else if(start<=end){
		int i=0;
		for(i=start;i<=end;i++){
			swap(a+start,a+i);
			permutation(a,n,k,i,end);
			swap(a+start,a+i);
		}
	}
	return;
}

int main(){
	int n,k;
	while(scanf("%d %d",&n,&k)){
		LTKcount=0;
		NumOfFullSortKLTN(n,k);
		printf("n's permutation have %d lessthannumber\n",LTKcount);
	}
}
