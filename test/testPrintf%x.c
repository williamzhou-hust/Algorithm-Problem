/*************************************************************************
	> File Name: testPrintf%x.c
	> Author: williamzhou
	> Mail: williamzhou.0330@foxmail.com 
	> Created Time: Mon 03 Apr 2017 06:27:05 AM PDT
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#define MAXLEN 1000

int main(int argc,char* argv[]){
	char s[MAXLEN];
	scanf("%s",s);
	int N=strlen(s)/16;
	int i=0;
	for(i=0;i<N;i++){
		printf("%08x  ",i*16);
		int j=0;
		for(j=0;j<16;j++) printf("%x ",s[i*16+j]);
		for(j=0;j<16;j++) printf("%c",s[i*16+j]);
		printf("\n");
	}
	return 0;
}

