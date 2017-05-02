/*************************************************************************
	> File Name: fullsort.c
	> Author: williamzhou
	> Mail: williamzhou.0330@foxmail.com 
	> Created Time: Fri 28 Apr 2017 12:06:43 AM PDT
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void swap(int* a,int* b){
	ir(a==b) return;
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

int NumOfFullSortKLTN(int n){
	void permutation(int* a,int n,int k,int start,int end);
}

void permutation(int* a,int n,int k,int start,int end){
	if(!a){
		printf("wrong input!\n");
	}
	static int LTKcount=0;
	if(start==end&&isHaveKLTN(a,n,k)) ++LTKcount;
	else{
		
	}

}
