/*************************************************************************
	> File Name: substring.cpp
	> Author: williamzhou
	> Mail: williamzhou.0330@foxmail.com 
	> Created Time: Sun 26 Mar 2017 05:43:51 AM PDT
 ************************************************************************/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int dpstr[200][200];
int dpseq[200][200];

int main(int argc,char* argv[]){
	string s1,s2;
	cin>>s1>>s2;
	int N1=s1.length(),N2=s2.length();
	for(int j=0;j<N2;j++){
		if(s1[0]==s2[j]){
			dpstr[0][j]=1;
		}
	}
	for(int i=0;i<N1;i++){
		if(s1[i]==s2[0]){
			dpstr[i][0]=1;
		}
	}
	int pos=0;
	while(s1[0]!=s2[pos]) {pos++;if(pos>N2-1) break;}
	for(int i=pos;i<N2;i++) dpseq[0][i]=1;
	pos=0;
	while(s1[pos]!=s2[0]) {pos++;if(pos>N1-1) break;}
	for(int i=pos;i<N1;i++) dpseq[i][0]=1;
	int len1=0,start1=0,end1=0;	
	for(int i=1;i<N1;i++)
		for(int j=1;j<N2;j++){
			if(s1[i]==s2[j]){
				dpstr[i][j]=dpstr[i-1][j-1]+1;
				if(dpstr[i][j]>len1){
					len1=dpstr[i][j];
					end1=i;
					start1=i-len1+1;
				}
				dpseq[i][j]=dpseq[i-1][j-1]+1;
			}
			else{
				dpstr[i][j]=0;
				dpseq[i][j]=max(dpseq[i-1][j],dpseq[i][j-1]);
			}
		}
	cout<<"substring: "<<s1.substr(start1,len1)<<" and length: "<<len1<<endl;
	cout<<"s1 "<<s1<<" s2 "<<s2<<endl;
	for(int i=0;i<N1;i++){
		for(int j=0;j<N2;j++){
		   cout<<dpseq[i][j]<<" ";
		}
		cout<<endl;
	}	
	cout<<"subsequence: ";
	string comm(dpseq[N1-1][N2-1],' ');
	int nc=dpseq[N1-1][N2-1]-1;
	int i=N1-1,j=N2-1;
	while(i>0&&j>0){
		if(dpseq[i][j]==dpseq[i-1][j-1]+1) {comm[nc]=s1[i];--i;--j;--nc;}
		else if(dpseq[i][j-1]>dpseq[i-1][j]) --j;
		else --i;
	}
	if(nc==0) comm[0]=s1[0];
	cout<<comm;
	cout<<" and length: "<<dpseq[N1-1][N2-1]<<endl;
}
