/*************************************************************************
	> File Name: exactDecimal.c
	> Author: williamzhou
	> Mail: williamzhou.0330@foxmail.com 
	> Created Time: Mon 24 Apr 2017 04:03:32 AM PDT
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
	if(count>1) return 0;
	int64 result=0;
	while(i<N){
		if(s[i]<'0'||s[i]>'9') return 0;
		result=result*10+s[i]-'0';
		if(result>MAXNUM) return MAXNUM;
		++i;
	}
	return flag*result;
}

int64 __zuidagys_aux(int64 m,int64 n){
	if(m<n){
		int64 temp=m;
		m=n;
		n=temp;
	}
	if(n==0) return m;
	return __zuidagys_aux(m,m-n);
}

int64 zuidagys(int64 m,int64 n){
	if(m<n){
		int64 temp=m;
		m=n;
		n=temp;
	}
	if(n==0) return m;
	if(m%n==0) return n;
	int64 ans=0;
	if(!(m&0x1)&&!(n&0x1))
		ans=2*zuidagys(m>>1,n>>1);
	if((m&0x1)&&!(n&0x1))
		ans=zuidagys(m,n>>1);
	if(!(m&0x1)&&(n&0x1))
		ans=zuidagys(m>>1,n);
	if((m&0x1)&&(n&0x1))
		ans=zuidagys(m,m-n);
	return ans;
}

typedef char charvec[20];
int64 mypow(int64 base,int64 index){
	if(index==1) return base;
	else if(index&0x1) return base*mypow(base,(index-1)/2)*mypow(base,(index-1)/2);
	else return mypow(base,index/2)*mypow(base,index/2);
	return 0;
}
void exactDecimal(char* s){
	charvec M,a,b;
	int i=0,p=0;
	while(s[p]!='.'){
		M[p-i]=s[p];
		++p;
	}
	M[p-i]='\0';
	i=++p;
	while(s[p]!='('){
		a[p-i]=s[p];
		++p;
	}
	a[p-i]='\0';
	i=++p;
	while(s[p]!=')'){
		b[p-i]=s[p];
		++p;
	}
	b[p-i]='\0';
	++p;
	if(p!=strlen(s)){
		printf("wrong input!\n");
		return;
	}
	printf("M:%s a:%s b:%s\n",M,a,b);
	int64 nM=myatoi(M),na=myatoi(a),nb=myatoi(b);
	int64 temp1=na*(mypow(10,strlen(b))-1)+nb;
	int64 temp2=mypow(10,strlen(a))*(mypow(10,strlen(b))-1);
	printf("temp1:%lld temp2:%lld\n",temp1,temp2);
	int64 zdgys=zuidagys(temp1,temp2);
	printf("%lld+(%lld/%lld)\n",nM,temp1/zdgys,temp2/zdgys);
	return;
}

int main(){
	/*char* p=(char*)malloc(2*sizeof(char));
	p[0]='h';
	p[1]='l';
	printf("test p: %s\n",p);*/
	char s[100];
	while(scanf("%s",s)!=EOF){
		exactDecimal(s);
	}
	return 0;
}
