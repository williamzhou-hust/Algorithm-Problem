/*************************************************************************
	> File Name: countSort.c
	> Author: williamzhou
	> Mail: williamzhou.0330@foxmail.com 
	> Created Time: Sat 22 Apr 2017 06:56:30 AM PDT
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>
#define VECTORLEN 200
#define pointer_a(i) (void*)((char*)a+(i)*a_object_size)

void swap(void* m1,void* m2,int objectsize){
	if(m1==m2) return;
	void* temp=malloc(objectsize);
	memcpy(temp,m1,objectsize);
	memcpy(m1,m2,objectsize);
	memcpy(m2,temp,objectsize);
	free(temp);
	return;
}

void quickSort(void* a,int a_object_size,int a_length,int (*islessthan)(const void* m1,const void* m2,int objectsize)){
	void __quickSort_aux(void* a,int a_object_size,int i,int j,int (*islessthan)(const void* m1,const void* m2,int objectsize));
	__quickSort_aux(a,a_object_size,0,a_length-1,islessthan);
	return;
}

void __quickSort_aux(void* a,int a_object_size,int i,int j,int (*islessthan)(const void* m1,const void* m2,int objectsize)){
	int partition(void* a,int a_object_size,int i,int j,int (*islessthan)(const void* m1,const void* m2,int objectsize));
	int m=partition(a,a_object_size,i,j,islessthan);
	if(i>=j) return;
	if(m>i) __quickSort_aux(a,a_object_size,i,m-1,islessthan);
	if(m<j) __quickSort_aux(a,a_object_size,m+1,j,islessthan);
	return;
}

int partition(void* a,int a_object_size,int i,int j,int (*islessthan)(const void* m1,const void* m2,int objectsize)){
	if(i>j){
		printf("Wrong Input!\n");
		return -1;
	}
	if(i==j) return i;
	int p=i,q=i;
	for(q=i;q<j;q++){
		if(islessthan(pointer_a(q),pointer_a(j),a_object_size)){
			swap(pointer_a(p),pointer_a(q),a_object_size);
			++p;
		}
	}
	swap(pointer_a(p),pointer_a(j),a_object_size);
	return p;
}

int islessthan_int(const void* m1,const void* m2,int objectsize){
	if(sizeof(int)!=objectsize){
		printf("Wrong input!\n");
		return 0;
	}
	//printf("m1 m2: %d %d\n",*((int*)m1),*((int*)m2));
	return *((int*)m1)<*((int*)m2);
}

int main(){
	int* a=(int*)malloc(VECTORLEN*sizeof(int));
	printf("Before sort!\n");
	time_t seed=time(NULL);
	srand((unsigned)seed);
	int i=0;
	for(i=0;i<VECTORLEN;i++){
		a[i]=rand()%VECTORLEN;
		//printf("%d ",a[i]);
	}
	printf("\nafter countSort: \n");
	void countSort(int* a,int len);
	countSort(a,VECTORLEN);
	FILE *fp=fopen("countsort.txt","w");
	for(i=0;i<VECTORLEN;i++){
		fprintf(fp,"%d ",a[i]);
	}
	printf("\n");
	//quicksort for compare
	printf("Before sort!\n");
	srand((unsigned)seed);
	for(i=0;i<VECTORLEN;i++){
		a[i]=rand()%VECTORLEN;
		//printf("%d ",a[i]);
	}
	printf("\nafter quickSort: \n");
	quickSort(a,sizeof(int),VECTORLEN,islessthan_int);
	fp=fopen("countsortcompare.txt","w");
	for(i=0;i<VECTORLEN;i++){
		fprintf(fp,"%d ",a[i]);
	}
	printf("\n");
	//free data
	free(fp);
	free(a);
	return 0;
}

void countSort(int* a,int len){
	int* count=(int*)malloc(len*sizeof(int));
	int* b=(int*)malloc(len*sizeof(int));
	memset(count,0,len*sizeof(int));
	memset(b,0,len*sizeof(int));
	int i=0;
	for(i=0;i<len;i++){
		++count[a[i]];
	}
	for(i=1;i<len;i++){
		count[i]+=count[i-1];
	}
	for(i=len-1;i>=0;i--){
		b[count[a[i]]-1]=a[i];
		--count[a[i]];
	}
	memcpy(a,b,len*sizeof(int));
	free(count);
	free(b);
}
