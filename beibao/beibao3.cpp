/*************************************************************************
	> File Name: beibao3.cpp
	> Author: williamzhou
	> Mail: williamzhou.0330@foxmail.com 
	> Created Time: Fri 31 Mar 2017 03:14:47 AM PDT
 ************************************************************************/

#include <iostream>
#include <queue>
#include <algorithm>
#include <functional>
#include <stack>
using namespace std;

int weight[10+1]={0,1,2,3,4,5,6,7,8,9,10};
int value[10+1]={0,1,5,8,9,10,17,17,20,24,30};
int dp[10+1][200+1]={{0}};
int dp3[200+1]={0};
void beibao3(int rw){
	for(int i=1;i<=10;i++){
		for(int j=0;j<=200;j++){
			if(j>=weight[i]){
				dp3[j]=max(dp3[j],dp3[j-weight[i]]+value[i]);
			}
		}
	}
	cout<<"beibao3: max value: "<<dp3[rw]<<endl;
	stack<int> mstk;
	int mrw=rw;
	for(int i=10;i>0;i--){
		int k=mrw/weight[i];
		for(int c=1;c<=k;c++){
			if(mrw>=weight[i]&&dp3[mrw]==dp3[mrw-weight[i]]+value[i]){
				mstk.push(weight[i]);
				mrw-=weight[i];
			}
		}
	}
	cout<<"which to select: "<<endl;
	while(!mstk.empty()){
		cout<<mstk.top()<<" ";
		mstk.pop();
	}
	cout<<endl;
}

int main(int argc,char* argv[]){
	int rw=0;
	while(cin>>rw){
		cout<<"total weight: "<<rw<<endl;
		beibao3(rw);
	}
}
