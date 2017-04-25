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

char* addForLargeNum(char* a,char* b){
	int N=strlen(a);
	int M=strlen(b);
	int Max=max(M,N);
	char* c=(char*)malloc(Max+2);
	memset(c,'0',Max+1);
	//cout<<"c: "<<c<<endl;
	c[Max+1]='\0';
	char* a_t=(char*)malloc(Max+1);
	a_t[Max]='\0';
	strcpy(a_t,a);
	reverse(a_t);
	if(N<Max) a_t[N]='0';
	//cout<<"a_t: "<<a_t<<endl;
	char* b_t=(char*)malloc(Max+1);
	b_t[Max]='\0';
	strcpy(b_t,b);
	reverse(b_t);
	if(M<Max) b_t[M]='0';
	//cout<<"b_t: "<<b_t<<endl;
	int addflag=0;
	for(int i=0;i<Max;i++){
		int temp1=(a_t[i]-'0')+(b_t[i]-'0')+addflag;
		//cout<<"a_t[i]: "<<a_t[i]<<" b_t[i]: "<<b_t[i]<<endl;
		addflag=temp1/10;
		//cout<<"addflag: "<<addflag<<endl;
		temp1%=10;
		c[i]=temp1+'0';
		//cout<<c[i]<<endl;
	}
	if(addflag){c[Max]=addflag+'0';}
	reverse(c);
	char* out=removezero(c);
	//cout<<out<<endl;
	char* ans=(char*)malloc(strlen(out));
	memcpy(ans,out,strlen(out));
	free(a_t);
	free(b_t);
	free(c);
	return ans;
}

char* predeal(char* s,int* flag){
	int N=strlen(s);
	int i=0;
	while(i<N&&s[i]==' ') ++i;
	if(flag){
		if(s[i]=='-'){
			*flag=-1;
			++i;
		}
		else if(s[i]=='+'){
			*flag=1;
			++i;
		}
		else
			*flag=1;
		while(i<N){
			if(s[i]=='0')	
				++i;
			else if(s[i]<'0'||s[i]>'9') 
				return NULL;
			else break;
		}
		return s+i;
	}
	else{
		while(s[i]=='0') ++i;
	}
	if(i==N) return s+N-1;
	return s+i;
}

void borrow1fromhigh(char* s){
	if(!s) return;
	int N=strlen(s);
	int i=0;
	while(i<N&&s[i]=='0'){
		s[i]='9';
		++i;
	}
	s[i]-=1;
	return;
}

char* largesubsmall(char* large,char* small){
	int N=strlen(large);
	int M=strlen(small);
	reverse(large);
	reverse(small);
	//cout<<"large: "<<large<<endl;
	//cout<<"small: "<<small<<endl;
	int i=0;
	char* ans=(char*)malloc(N*sizeof(char));
	memset(ans,'0',N*sizeof(char));
	while(i<min(N,M)){
		if(large[i]<small[i]){
			borrow1fromhigh(large+i+1);
			ans[i]=large[i]+10-small[i]+'0';
		}
		else{
			ans[i]=large[i]-small[i]+'0';
		}
		++i;
	}
	while(i<N){
		ans[i]=large[i];
		++i;
	}
	reverse(ans);
	//cout<<"ans: "<<ans<<endl;
	char* tp=predeal(ans,NULL);
	char* re=(char*)malloc(sizeof(char)*strlen(tp));
	//cout<<"tp: "<<tp<<endl;
	memcpy(re,tp,sizeof(char)*strlen(tp));
	free(ans);
	return re;
}

int compareNum(char* a,char* b){
	if(strlen(a)==strlen(b)) return strcmp(a,b);
	else if(strlen(a)>strlen(b)) return 1;
	return -1;
}

char* add(char* a,char* b){
	cout<<"a: "<<a<<"b: "<<b<<endl;
	int flag_a=0,flag_b=0;
	char* ra=predeal(a,&flag_a);
	char* rb=predeal(b,&flag_b);
	if(!ra||!rb){
		cout<<"wrong input!"<<endl;
		return NULL;
	}
	cout<<"flag_a: "<<flag_a<<"flag_b: "<<flag_b<<"a: "<<ra<<"b: "<<rb<<endl;
	if(flag_a==1&&flag_b==1){
		return addForLargeNum(ra,rb);
	}
	if(flag_a==-1&&flag_b==-1){
		char* tmp=addForLargeNum(ra,rb);
		char* ans=(char*)malloc(sizeof(char)*strlen(tmp));
		ans[0]='-';
		memcpy(ans+1,tmp,sizeof(char)*strlen(tmp));
		free(tmp);
		return ans;
	}
	if(flag_a==-1&&flag_b==1){
		if(compareNum(ra,rb)>0){
			char* tmp=largesubsmall(ra,rb);
			char* ans=(char*)malloc(sizeof(char)*strlen(tmp));
			ans[0]='-';
			memcpy(ans+1,tmp,sizeof(char)*strlen(tmp));
			free(tmp);
			return ans;
		}
		else if(compareNum(ra,rb)<0){
			return largesubsmall(rb,ra);
		}
	}
	else if(flag_a==1&&flag_b==-1){
		if(compareNum(ra,rb)>0){
			return largesubsmall(ra,rb);
		}
		else if(compareNum(ra,rb)<0){
			char* tmp=largesubsmall(rb,ra);
			char* ans=(char*)malloc(sizeof(char)*strlen(tmp));
			ans[0]='-';
			memcpy(ans+1,tmp,sizeof(char)*strlen(tmp));
			free(tmp);
			return ans;
		}
	}
	else if(flag_a==-1&&flag_b==-1){
		char* tmp=addForLargeNum(ra,rb);
		char* ans=(char*)malloc(sizeof(char)*strlen(tmp));
		ans[0]='-';
		memcpy(ans+1,tmp,sizeof(char)*strlen(tmp));
		free(tmp);
		return ans;
	}
	return NULL;
}

#define DEBUGADD
#ifdef DEBUGADD
int main(){
	char a[20];
	char b[20];
	while(scanf("%s%s",a,b)!=EOF){
		char* answer=add(a,b);
		if(answer){
			printf("the answer: %s\n",answer);
			free(answer);
		}
	}
	return 0;
}
#endif

//#define TEST
#ifdef TEST
int main(){
	char a[10]="-79";
	char b[10]="60";
	cout<<"a+b="<<add(a,b)<<endl;
	cout<<"compare answer b>a: "<<compareNum(b,a)<<endl;
	return 0;
}
#endif
