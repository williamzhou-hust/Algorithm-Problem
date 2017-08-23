/*************************************************************************
	> File Name: ReplaceBlank.c
	> Author: williamzhou
	> Mail: williamzhou.0330@foxmail.com 
	> Created Time: Fri 28 Apr 2017 07:22:50 AM PDT
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

char* replaceBlank(char* string,char* repstr){
	int N=strlen(string),M=strlen(repstr);
	int i=0;
	int blankcnt=0;
	for(i=0;i<N;i++){
		if(string[i]==' ') ++blankcnt;
	}
	char* ans=(char*)malloc((N+(M-1)*blankcnt)*sizeof(char));
	i=N-1;
	int j=N+(M-1)*blankcnt-1;
	int c=0;
	while(i>=0){
		while(i>=0&&string[i]!=' '){
			ans[j]=string[i];
			--i;
			--j;
		}
		for(c=M-1;c>=0;c--){
			ans[j]=repstr[c];
			--j;
		}
		--i;
	}
	return ans;
}

int main(){
	char hello[]="hello world thank you";
	char repstr[]="%20";
	printf("after replace: %s\n",replaceBlank(hello,repstr));
	return 0;
}

