/*************************************************************************
	> File Name: bubbleSort.c
	> Author: williamzhou
	> Mail: williamzhou.0330@foxmail.com 
	> Created Time: Fri 21 Apr 2017 06:51:59 AM PDT
 ************************************************************************/

#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define pointer_a(i) (void*)((char*)a+(i)*a_object_size)
#define pointer_temp(i) (void*)((char*)temp+(i)*a_object_size)

void swap(void* m1,void* m2,int objectsize){
	if(m1==m2) return;
	void* temp=malloc(objectsize);
	memcpy(temp,m1,objectsize);
	memcpy(m1,m2,objectsize);
	memcpy(m2,temp,objectsize);
	free(temp);
	return;
}

void bubbleSort(void* a,int a_object_size,int a_length,int (*islessthan)(const void* m1,const void* m2,int objectsize)){
	int i=0,j=0;
	for(j=a_length-1;j>=0;j--){
		for(i=0;i<j;i++){
			if(!islessthan(pointer_a(i),pointer_a(i+1),a_object_size)){
				swap(pointer_a(i),pointer_a(i+1),a_object_size);		
			}
		}
	}
	return;
}

void setmax(void* max,int objectsize){
	memset(max,0xFF,objectsize);
	char *p=((char*)max+objectsize-1);
	*p&=0x7F;
}

void setmin(void* min,int objectsize){
	memset(min,0x00,objectsize);
	char *p=((char*)min+objectsize-1);
	*p|=0x80;
}

void selectSort(void* a,int a_object_size,int a_length,int (*islessthan)(const void* m1,const void* m2,int objectsize)){
	void* temp=malloc(a_object_size);
	int i=0,j=0;
	int max_i=0;
	for(j=a_length-1;j>=0;j--){
		setmin(temp,a_object_size);
		//printf("temp: %d\n",*((int*)temp));
		for(i=0;i<=j;i++){
			if(!islessthan(pointer_a(i),temp,a_object_size)){
				memcpy(temp,pointer_a(i),a_object_size);
				max_i=i;
			}
		}
		//printf("max_i: %d ",max_i);
		swap(pointer_a(max_i),pointer_a(j),a_object_size);
	}
	free(temp);
	return;
}

void insertSort(void* a,int a_object_size,int a_length,int (*islessthan)(const void* m1,const void* m2,int objectsize)){
	/*int i=0,j=0;
	for(j=1;j<a_length;j++){
		i=j-1;
		while(i>=0&&!islessthan(pointer_a(i),pointer_a(i+1),a_object_size)){
			swap(pointer_a(i),pointer_a(i+1),a_object_size);
			--i;
		}
	}
	return;*/
	void* temp=malloc(a_object_size);
	int i=0,j=0;
	for(j=1;j<a_length;j++){
		i=j-1;
		while(i>=0&&!islessthan(pointer_a(i),pointer_a(j),a_object_size)){
			--i;
		}
		//printf("\ni: %d\n",i);
		memcpy(temp,pointer_a(j),a_object_size);
		int k=0;
		for(k=j-1;k>=i+1;k--){
			memcpy(pointer_a(k+1),pointer_a(k),a_object_size);
		}
		memcpy(pointer_a(i+1),temp,a_object_size);
		//for(i=0;i<a_length;i++) printf("%d ",*((int*)pointer_a(i)));
	}
	free(temp);
	return;
}

void shellSort(void* a,int a_object_size,int a_length,int (*islessthan)(const void* m1,const void* m2,int objectsize)){
	int i=0,j=0,cap=0;
	for(cap=a_length/2;cap>0;cap/=2){
		for(i=cap;i<a_length;i++){
			for(j=i-cap;j>=0;j-=cap){
				if(!islessthan(pointer_a(j),pointer_a(j+cap),a_object_size)){
					swap(pointer_a(j),pointer_a(j+cap),a_object_size);
				}
			}
		}
	}
}

void mergeSort(void* a,int a_object_size,int a_length,int (*islessthan)(const void* m1,const void* m2,int objectsize)){
	void __mergeSort_aux(void* a,int a_object_size,int i,int j,int (*islessthan)(const void* m1,const void* m2,int objectsize));
	__mergeSort_aux(a,a_object_size,0,a_length-1,islessthan);
	return;
}

void __mergeSort_aux(void* a,int a_object_size,int i,int j,int (*islessthan)(const void* m1,const void* m2,int objectsize)){
	if(i>=j) return;
	if(j-i==1&&!islessthan(pointer_a(i),pointer_a(j),a_object_size)){
		swap(pointer_a(i),pointer_a(j),a_object_size);
		return;
	}
	else{
		int k=i+(j-i)/2;
		__mergeSort_aux(a,a_object_size,i,k,islessthan);
		__mergeSort_aux(a,a_object_size,k+1,j,islessthan);
		void* temp=malloc((j-i+1)*a_object_size);
		int p=i,q=k+1;
		int c=0;
		while(p<=k&&q<=j){
			if(islessthan(pointer_a(p),pointer_a(q),a_object_size)){
				memcpy(pointer_temp(c),pointer_a(p),a_object_size);
				++p;
				++c;
			}
			else{
				memcpy(pointer_temp(c),pointer_a(q),a_object_size);
				++q;
				++c;
			}
		}
		while(p<=k){
			memcpy(pointer_temp(c),pointer_a(p),a_object_size);
			++p;
			++c;
		}
		while(q<=j){
			memcpy(pointer_temp(c),pointer_a(q),a_object_size);
			++q;
			++c;
		}
		memcpy(pointer_a(i),temp,(j-i+1)*a_object_size);
		free(temp);
		return;
	}
	return;
}

void maxheapSort(void* a,int a_object_size,int a_length,int (*islessthan)(const void* m1,const void* m2,int objectsize)){
	void bulidmaxheap(void* a,int a_object_size,int a_length,int (*islessthan)(const void* m1,const void* m2,int objectsize));
	void maxheapihy(void* a,int a_object_size,int i,int j,int (*islessthan)(const void* m1,const void* m2,int objectsize));
	bulidmaxheap(a,a_object_size,a_length,islessthan);
	int j=0;
	for(j=a_length-1;j>0;j--){
		swap(pointer_a(0),pointer_a(j),a_object_size);
		maxheapihy(a,a_object_size,0,j-1,islessthan);
	}
}

void maxheapihy(void* a,int a_object_size,int i,int j,int (*islessthan)(const void* m1,const void* m2,int objectsize)){
	int index_i=i;
	if(2*i+1<=j&&!islessthan(pointer_a(2*i+1),pointer_a(i),a_object_size)){
		index_i=2*i+1;
	}
	if(2*i+2<=j&&!islessthan(pointer_a(2*i+2),pointer_a(index_i),a_object_size)){
		index_i=2*i+2;
	}
	if(index_i!=i){
		swap(pointer_a(i),pointer_a(index_i),a_object_size);
		maxheapihy(a,a_object_size,index_i,j,islessthan);
	}
}

void bulidmaxheap(void* a,int a_object_size,int a_length,int (*islessthan)(const void* m1,const void* m2,int objectsize)){
	int i=0;
	for(i=(a_length-1)/2;i>=0;i--){
		maxheapihy(a,a_object_size,i,a_length-1,islessthan);
	}
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

#define RUNTIME 1
#define VECTORLEN 200

void initinputfile(){
	int* a=(int*)malloc(sizeof(int)*VECTORLEN);
	srand((unsigned)time(NULL));
	FILE *fp=fopen("input.txt","w");
	if(fp==NULL) printf("file is not open!\n");
	int i=0;
	for(i=0;i<VECTORLEN;i++){
		a[i]=rand()%VECTORLEN;
		//printf("a[i]: %d ",a[i]);
	}
	for(i=0;i<VECTORLEN;i++){
		fprintf(fp,"%d\n",a[i]);
	}
	free(a);
	fclose(fp);
}

typedef void (*Sort)(void* a,int a_object_size,int a_length,int (*islessthan)(const void* m1,const void* m2,int objectsize));
void testForSort(const char* s,Sort funcsort){
	//int a[VECTORLEN];
	int* a=(int*)malloc(sizeof(int)*VECTORLEN);
	//printf("Before %s.\n",s);
	//srand((unsigned)time(NULL));
	FILE* fp=fopen("input.txt","rt");
	int i=0;
	for(i=0;i<VECTORLEN;i++){
		//a[i]=rand()%VECTORLEN;
		fscanf(fp,"%d",&a[i]);
		//printf("%d ",a[i]);
	}
	//printf("\n");
	clock_t start_time=clock();
	for(i=0;i<RUNTIME;i++)
		funcsort((void*)a,sizeof(int),VECTORLEN,islessthan_int);
	clock_t end_time=clock();
	printf("after %s:\n",s);
	fp=fopen(s,"wt+");
	for(i=0;i<VECTORLEN;i++){
		fprintf(fp,"%d ",a[i]);
		if(i%100==99) fprintf(fp,"\n");
	}
	fclose(fp);
	//printf("\n");
	printf("Pall Time = %fs\n",(double)(end_time-start_time)/CLOCKS_PER_SEC);
	free(a);
	return;
}

int main(){
	initinputfile();
	testForSort("bubbleSort",bubbleSort);
	testForSort("selectSort",selectSort);
	testForSort("insertSort",insertSort);
	testForSort("shellSort",shellSort);
	testForSort("mergeSort",mergeSort);
	testForSort("maxheapSort",maxheapSort);
	testForSort("quickSort",quickSort);
	return 0;
}
