/*************************************************************************
	> File Name: dsxj.cpp
	> Author: williamzhou
	> Mail: williamzhou.0330@foxmail.com 
	> Created Time: Thu 13 Apr 2017 07:17:36 PM PDT
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

void reverse(char* s){
	int N=strlen(s);
	int p=0,q=N-1;
	while(p<q){
		swap(s[p],s[q]);
		++p;
		--q;
	}
	return;
}

char* removezero(char* s){
	int N=strlen(s);
	if(s[0]!='0') return s;
	int i=0;
	while(i<N&&s[i]=='0') i++;
	return s+i;
}

void addForLargeNum(char* a,char* b){
	int N=strlen(a);
	int M=strlen(b);
	int Max=max(M,N);
	char* c=(char*)malloc(Max+2);
	memset(c,'0',Max+1);
	cout<<"c: "<<c<<endl;
	c[Max+1]='\0';
	char* a_t=(char*)malloc(Max+1);
	a_t[Max]='\0';
	strcpy(a_t,a);
	reverse(a_t);
	if(N<Max) a_t[N]='0';
	cout<<"a_t: "<<a_t<<endl;
	char* b_t=(char*)malloc(Max+1);
	b_t[Max]='\0';
	strcpy(b_t,b);
	reverse(b_t);
	if(M<Max) b_t[M]='0';
	cout<<"b_t: "<<b_t<<endl;
	int addflag=0;
	for(int i=0;i<Max;i++){
		int temp1=(a_t[i]-'0')+(b_t[i]-'0')+addflag;
		cout<<"a_t[i]: "<<a_t[i]<<" b_t[i]: "<<b_t[i]<<endl;
		addflag=temp1/10;
		cout<<"addflag: "<<addflag<<endl;
		temp1%=10;
		c[i]=temp1+'0';
		cout<<c[i]<<endl;
	}
	if(addflag){c[Max]=addflag+'0';}
	reverse(c);
	char* out=removezero(c);
	cout<<out<<endl;
	free(a_t);
	free(b_t);
	free(c);
	return;
}

int main(){
	char a[20];
	char b[20];
	while(scanf("%s%s",a,b)!=EOF){
		addForLargeNum(a,b);
	}
	return 0;
}
