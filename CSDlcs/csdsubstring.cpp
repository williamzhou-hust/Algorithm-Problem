/*************************************************************************
	> File Name: csdsubstring.cpp
	> Author: williamzhou
	> Mail: williamzhou.0330@foxmail.com 
	> Created Time: Thu 06 Apr 2017 06:30:09 AM PDT
 ************************************************************************/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int dpstr[20][20]={{0}};
int dpseq[20][20]={{0}};

int lcsstring(const string& s1,const string& s2){
	int N=s1.length();
	int M=s2.length();
	for(int j=0;j<M;j++){
		if(s2[j]==s1[0]){
			dpstr[0][j]=1;
		}
	}
	for(int i=0;i<N;i++){
		if(s1[i]==s2[0]){
			dpstr[i][0]=1;
		}
	}
	int maxlen=0,index=0;
	for(int i=1;i<N;i++){
		for(int j=1;j<M;j++){
			if(s1[i]==s2[j]){
				dpstr[i][j]=dpstr[i-1][j-1]+1;
				if(dpstr[i][j]>maxlen){
					maxlen=dpstr[i][j];
					index=i;
				}
			}
			else{
				dpstr[i][j]=0;
			}
		}
	}
	cout<<"longest common substring:"<<endl;
	cout<<s1.substr(index-maxlen+1,maxlen)<<endl;
	return maxlen;
}

int lcssequence(const string& s1,const string& s2){
	int N=s1.length(),M=s2.length();
	dpseq[0][0]=(s1[0]==s2[0]?1:0);
	for(int j=1;j<M;j++){
		if(s2[j]==s1[0]){
			dpseq[0][j]=1;
		}
		else{
			dpseq[0][j]=dpseq[0][j-1];
		}
	}
	for(int i=1;i<N;i++){
		if(s1[i]==s2[0]){
			dpseq[i][0]=1;
		}
		else{
			dpseq[i][0]=dpseq[i-1][0];
		}
	}
	for(int i=1;i<N;i++){
		for(int j=1;j<M;j++){
			if(s1[i]==s2[j]){
				dpseq[i][j]=dpseq[i-1][j-1]+1;
			}
			else{
				dpseq[i][j]=max(dpseq[i-1][j],dpseq[i][j-1]);
			}
		}
	}
	void printlcssequence(const string& s1,int i,const string& s2,int j);
	cout<<"longest common sequence:"<<endl;
	printlcssequence(s1,N-1,s2,M-1);
	cout<<endl;
	return dpseq[N-1][M-1];
}

void printlcssequence(const string& s1,int i,const string& s2,int j){
	if(dpseq[i][j]==0) return;
	if(s1[i]==s2[j]){
		printlcssequence(s1,i-1,s2,j-1);
		cout<<s1[i];
	}
	else if(dpseq[i-1][j]>dpseq[i][j-1]){
		printlcssequence(s1,i-1,s2,j);
	}
	else{
		printlcssequence(s1,i,s2,j-1);
	}
	return;
}

int main(){
	string s1("AABCDEF");
	string s2("DEFAA");
	string s3("DFAA");
	s1+=s1;
	cout<<"s1: "<<s1<<endl;
	int lcsstring(const string& s1,const string& s2);
	int lcssequence(const string& s1,const string& s2);
	if((int)s2.length()==lcsstring(s1,s2)){
		cout<<"s2 is contained!"<<endl;
	}
	else{
		cout<<"s2 isn't contained!"<<endl;
	}
	cout<<"common sequence length of s1 and s3: "<<lcssequence(s1,s2)<<endl;
	if((int)s3.length()==lcsstring(s1,s3)){
		cout<<"s3 is contained!"<<endl;
	}
	else{
		cout<<"s3 isn't contained!"<<endl;
	}
	cout<<"common sequence length of s1 and s3: "<<lcssequence(s1,s3)<<endl;
	return 0;
}
