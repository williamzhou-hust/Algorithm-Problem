/*************************************************************************
	> File Name: divide2arrayN_3.cpp
	> Author: williamzhou
	> Mail: williamzhou.0330@foxmail.com 
	> Created Time: Sat 25 Mar 2017 08:28:36 AM PDT
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

int isOK[11][11][1001];
int accnum[11];

int main(int argc,char* argv[]){
	int N;
	cin>>N;
	vector<int> value(N+1);
	int sum=0;
	for(int i=1;i<=N;i++){
		cin>>value[i];
		sum+=value[i];
		accnum[i]=sum;
	}
	for(int i=1;i<=N;i++){
		for(int j=1;j<=i;j++) isOK[i][1][value[j]]=1;
		isOK[i][0][0]=1;
		isOK[i][i][accnum[i]]=1;
	}
	isOK[0][0][0]=1;
	for(int k=2;k<=N;k++)
		for(int j=2;j<=k-1;j++)
			for(int v=0;v<=1000;v++){
				isOK[k][j][v]=isOK[k-1][j][v]||isOK[k-1][j-1][v-value[k]];
			}
	int nn=sum/2;
	while(!isOK[N][N/2][nn]) nn--;
	cout<<nn<<" "<<sum-nn<<endl;
}
