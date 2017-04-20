/*************************************************************************
	> File Name: divide2array.cpp
	> Author: williamzhou
	> Mail: williamzhou.0330@foxmail.com 
	> Created Time: Sat 25 Mar 2017 04:54:06 AM PDT
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dp[10][50000];

int main(int argc,char* argv[]){
	int n=0;
	cin>>n;
	vector<int> weight(n);
	int sum=0;
	for(int i=0;i<n;i++){
		cin>>weight[i];
		sum+=weight[i];
	}
	for(int i=1;i<n;i++){
		for(int j=0;j<50000;j++){
			if(j<weight[i]){
				dp[i][j]=dp[i-1][j];
			}
			else{
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-weight[i]]+weight[i]);
			}
		}
	}
	cout<<sum-dp[n-1][sum/2]<<endl;
}
