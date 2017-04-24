/*************************************************************************
	> File Name: myatoi.c
	> Author: williamzhou
	> Mail: williamzhou.0330@foxmail.com 
	> Created Time: Mon 24 Apr 2017 03:26:30 AM PDT
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXNUM 0x7FFFFFFFFFFFFFFF
typedef long long int int64;
int64 myatoi(char* s){
	if(s==NULL) return 0;
	int N=strlen(s);
	int i=0;
	int flag=1;
	int count=0;
	while(i<N&&s[i]==' ') ++i;
	while(i<N&&(s[i]<'0'||s[i]>'9')){
		if(s[i]=='-'){
			flag=-1;
			++count;
		}
		else if(s[i]=='+'){
			flag=1;
			++count;
		}
		else return 0;
		++i;
	}
	//printf("i:%d\nflag:%d\n",i,flag);
	if(count!=1) return 0;
	int64 result=0;
	while(i<N){
		if(s[i]<'0'||s[i]>'9') return 0;
		result=result*10+s[i]-'0';
		if(result>MAXNUM) return MAXNUM;
		++i;
	}
	return flag*result;
}

int main(){
	char* s=(char*)malloc(100*sizeof(char));
	while(scanf("%s",s)!=EOF){
		printf("string to change: %s\n",s);
		printf("number be changed: %lld\n",myatoi(s));
		printf("\n");
	}
	free(s);
	return 0;
}
