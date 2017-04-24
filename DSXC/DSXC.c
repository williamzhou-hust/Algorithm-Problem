/*************************************************************************
	> File Name: DSXC.c
	> Author: williamzhou
	> Mail: williamzhou.0330@foxmail.com 
	> Created Time: Sun 23 Apr 2017 11:25:58 PM PDT
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

void swap(void* a1,void* a2,int objectsize){
	if(a1==a2) return;
	void* temp=malloc(objectsize);
	memcpy(temp,a1,objectsize);
	memcpy(a1,a2,objectsize);
	memcpy(a2,temp,objectsize);
	free(temp);
	return;
}

void reverseNumber(char* s){
	int N=strlen(s);
	int i=0,j=N-1;
	while(i<j){
		swap(&s[i++],&s[j--],1);
	}
	return;
}

char* reducezero(char* s,char* flag){
	int i=0;
	while(i<strlen(s)&&s[i]==' ') ++i;
	if(flag!=NULL){
		if(s[i]=='-'){
			(*flag)='-';
			++i;
		}
		else if(s[i]=='+'){
			(*flag)='+';
			++i;
		}
		else if(s[i]<'0'||s[i]>'9')
			return NULL;
	}
	if(s[i]<'0'||s[i]>'9') return NULL;
	while(i<strlen(s)&&s[i]=='0') ++i;
	return s+i;
}

char* multForLargeNumber(char* a,char*b){
	char flag_a='+',flag_b='+';
	a=reducezero(a,&flag_a);
	b=reducezero(b,&flag_b);
	if(!a||!b) return NULL;
	int N=strlen(a),M=strlen(b);
	char* c=(char*)malloc((M+N)*sizeof(char));
	memset(c,'0',(M+N)*sizeof(char));
	reverseNumber(a);
	reverseNumber(b);
	//printf("a: %s\n",a);
	//printf("b: %s\n",b);
	//printf("flag_a:%c\n",flag_a);
	//printf("flag_b:%c\n",flag_b);
	int flag=0;
	int i=0,j=0;
	for(i=0;i<N;i++){
		int multflag=0,addflag=0;
		for(j=0;j<M;j++){
			int temp=(a[i]-'0')*(b[j]-'0')+multflag;
			multflag=temp/10;
			temp%=10;
			int temp2=(c[i+j]-'0')+temp+addflag;
			addflag=temp2/10;
			temp2%=10;
			c[i+j]=temp2+'0';
		}
		c[i+M]=c[i+M]+addflag+multflag+flag;
		flag=(c[i+M]-'0')/10;
		c[i+M]=(c[i+M]-'0')%10+'0';
	}
	reverseNumber(c);
	//printf("d: %s\n",c);
	char* c_old=c;
	c=reducezero(c,NULL);
	if(flag_a!=flag_b){
		char* ans=(char*)malloc((strlen(c)+1)*sizeof(char));
		ans[0]='-';
		memcpy(ans+1,c,strlen(c)*sizeof(char));
		free(c_old);
		return ans;
	}
	else{
		char* ans=(char*)malloc(strlen(c)*sizeof(char));
		memcpy(ans,c,strlen(c)*sizeof(char));
		free(c_old);
		return ans;
	}
	return NULL;
}

int main(){
	char* a=(char*)malloc(100*sizeof(char));
	char* b=(char*)malloc(100*sizeof(char));
	long long int aa=0,bb=0;
	while(scanf("%s %s %lld %lld",a,b,&aa,&bb)!=EOF){
		printf("a*b: (%s)*(%s)\n",a,b);
		char* c=NULL;
		printf("the mult of a*b: %s\n",!(c=multForLargeNumber(a,b))?"wrong input":c);
		printf("the mult for compare: %lld\n",aa*bb);
		printf("\n");
	}
	/*char test[]="00625";
	printf("test: %s\n",reducezero(test,NULL));*/
	free(a);
	free(b);
	return 0;
}
