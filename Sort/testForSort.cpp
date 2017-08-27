/*************************************************************************
	> File Name: testForSort.cpp
	> Author: williamzhou
	> Mail: williamzhou.0330@foxmail.com 
	> Created Time: Thu 03 Aug 2017 08:16:29 AM PDT
 ************************************************************************/

#include <iostream>
#include <vector>
#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define pointer_a(i) (void*)((char*)a+(i)*a_object_size)
#define pointer_temp(i) (void*)((char*)temp+(i)*a_object_size)
using namespace std;


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

typedef struct student{
	int id;
	int a;
	int b;
	int sum;
} student;

int islessthan_student(const void* m1,const void* m2,int objectsize){
	if(sizeof(student)!=objectsize){
		printf("Wrong input!\n");
		return 0;
	}
	//printf("m1 m2: %d %d\n",*((int*)m1),*((int*)m2));
	if((*((student*)m1)).sum!=(*((student*)m2)).sum)
		return (*((student*)m1)).sum<(*((student*)m2)).sum;
	else return (*((student*)m1)).id<(*((student*)m2)).id;
}

int main(int argc,char* argv[]){
	int id[10]={0,1,2,3,4,5,6,7,8,9};
	int a[10]={9,7,10,23,4,7,18,2,3,5};
	int b[10]={3,5,2,12,56,9,8,34,22,25};

	vector<student> stu;
	for(int i=0;i<10;i++){
		student temp;
		temp.id=id[i];
		temp.a=a[i];
		temp.b=b[i];
		temp.sum=a[i]+b[i];
		stu.push_back(temp);
	}

	quickSort(&stu[0],sizeof(student),stu.size(),islessthan_student);
	for(int i=0;i<10;i++){
		cout<<stu[i].id<<" "<<stu[i].a<<" "<<stu[i].b<<" "<<stu[i].sum<<endl;
	}

	return 0;
}

