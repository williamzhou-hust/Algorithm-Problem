/*************************************************************************
	> File Name: lis.cpp
	> Author: williamzhou
	> Mail: williamzhou.0330@foxmail.com 
	> Created Time: Sat 01 Apr 2017 06:52:04 AM PDT
 ************************************************************************/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int dp[20]={0};
int prepos[20]={0};

int main(int argc,char* argv[]){
	vector<int> mvec={1,-13,-12,-11,2,3,4,-9,-8,-7,7,-6,8,10,-5,-4,11,-3};
	int N=mvec.size();
	void lis(vector<int>& mvec,int endpos);
	lis(mvec,N-1);
	lis(mvec,N-2);
	lis(mvec,N-3);
}

void lis(vector<int>& mvec,int endpos){
	int maxnum=0;
	int maxpos=0;
	for(int i=0;i<20;i++){ 
		prepos[i]=-1;
		dp[i]=1;
	}
	for(int i=1;i<=endpos;i++){
		int maxtmp=0x80000000;
		for(int j=0;j<=i-1;j++){
			if(mvec[j]<mvec[i]){//&&dp[j]+1>maxtmp){
				dp[i]=dp[j]+1;
				prepos[i]=j;
			}
		}
		//dp[i]=maxtmp;
		if(dp[i]>maxnum) {
			maxnum=dp[i];
			maxpos=i;
		}
	}
	cout<<"max lis: "<<maxnum<<endl;
	stack<int> stkans;
	stkans.push(mvec[maxpos]);
	int x=prepos[maxpos];
	while(x>=0){
		stkans.push(mvec[x]);
		x=prepos[x];
	}
	while(!stkans.empty()){
		cout<<stkans.top()<<" ";
		stkans.pop();
	}
	cout<<endl;
}
