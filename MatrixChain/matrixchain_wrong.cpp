/*************************************************************************
	> File Name: matrixchain.cpp
	> Author: williamzhou
	> Mail: williamzhou.0330@foxmail.com 
	> Created Time: Sun 02 Apr 2017 05:07:36 AM PDT
 ************************************************************************/

#include <iostream>
#include <string>
#define MAXLEN 20
using namespace std;

int dp[MAXLEN+1][MAXLEN+1]={{0}};
int p[7]={30,35,15,5,10,20,25};
int s[MAXLEN+1][MAXLEN+1]={{0}};
string matrix("A1A2A3A4A5A6");

int main(int argc,char* argv[]){
	int N=6;//matrix A1,A2,A3,A4,A5,A6
	for(int i=1;i<N;i++){
		for(int j=i+1;j<=N;j++){
			dp[i][j]=0x7FFFFFFF;
			for(int k=i;k<j;k++){
				int t=dp[i][k]+dp[k+1][j]+p[i-1]*p[k]*p[j];
				if(t<dp[i][j]){
					dp[i][j]=t;//dp[i][k]+dp[k+1][j]+p[i-1]*p[k]*p[j];
					s[i][j]=k;
				}
			}
		}
	}
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"the min mult times: "<<dp[1][6]<<endl;
	void printMatrixChain(int i,int j);
	printMatrixChain(1,N);
}

void printMatrixChain(int i,int j){
	if(i>j){
		cout<<"wrong input!"<<endl;
		return;
	}
	if(i==j) cout<<matrix.substr(2*(i-1),2);
	if(i<j){
		cout<<'(';
		printMatrixChain(i,s[i][j]);
		printMatrixChain(s[i][j]+1,j);
		cout<<')';
	}
	return;
}
