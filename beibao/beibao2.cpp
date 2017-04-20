/*************************************************************************
	> File Name: beibao.cpp
	> Author: williamzhou
	> Mail: williamzhou.0330@foxmail.com 
	> Created Time: Wed 29 Mar 2017 04:17:00 AM PDT
 ************************************************************************/

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int weight[10+1]={0,1,2,3,4,5,6,7,8,9,10};
int value[10+1]={0,1,5,8,9,10,17,17,20,24,30};
int dp[10+1][200+1]={{0}};

int beibao(int rw){
	for(int i=1;i<=10;i++){
		for(int j=0;j<=rw;j++){
			if(j<weight[i]) dp[i][j]=dp[i-1][j];
			else{
				if(dp[i-1][j-weight[i]]+value[i]>dp[i-1][j]){
					dp[i][j]=dp[i-1][j-weight[i]]+value[i];
				}
				else if(dp[i-1][j-weight[i]]+value[i]<=dp[i-1][j]){
					dp[i][j]=dp[i-1][j];
				}
			}
		}
	}
	/*for(int i=0;i<=10;i++){
		for(int j=0;j<=rw;j++) cout<<dp[i][j]<<" ";
		cout<<endl;
	}*/
	cout<<"which to select:"<<endl;
	stack<int> rque;
	int rwt=rw;
	for(int i=10;i>0;i--){
		if(rwt>=weight[i]&&dp[i-1][rwt-weight[i]]+value[i]>dp[i-1][rwt]){
			rque.push(weight[i]);
			rwt-=weight[i];
		}
	}
	while(!rque.empty()){
		cout<<rque.top()<<" ";
		rque.pop();
	}
	cout<<endl;
	return dp[10][rw];
}

int beibao2(int rw){
	for(int i=1;i<=10;i++){
		for(int j=0;j<=rw;j++){
			int k=j/weight[i];
			for(int c=0;c<=k;c++){
				if(j<c*weight[i]) dp[i][j]=dp[i-1][j];
				else{
					if(dp[i-1][j-c*weight[i]]+c*value[i]>dp[i-1][j]){
						dp[i][j]=dp[i-1][j-c*weight[i]]+c*value[i];
					}
					else if(dp[i-1][j-c*weight[i]]+c*value[i]<=dp[i-1][j]){
						dp[i][j]=dp[i-1][j];
					}
				}
			}
		}
	}
	/*for(int i=0;i<=10;i++){
		for(int j=0;j<=rw;j++) cout<<dp[i][j]<<" ";
		cout<<endl;
	}*/
	cout<<"which to select:"<<endl;
	stack<int> rque;
	int rwt=rw;
	for(int i=10;i>0;i--){
		int k=rwt/weight[i];
		for(int c=1;c<=k;c++){
			if(rwt>=weight[i]&&dp[i-1][rwt-weight[i]]+value[i]>dp[i-1][rwt]){
				rque.push(weight[i]);
				rwt-=weight[i];
			}
		}
	}
	while(!rque.empty()){
		cout<<rque.top()<<" ";
		rque.pop();
	}
	cout<<endl;
	return dp[10][rw];
}

int main(int argc,char* argv[]){
	int rw=0;
	while(cin>>rw){
		cout<<"weight is: "<<rw<<endl;
		cout<<"largest value: "<<beibao2(rw)<<endl;
	}	
	return 0;
}
