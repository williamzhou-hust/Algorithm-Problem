/*************************************************************************
	> File Name: divide2arrayN.cpp
	> Author: williamzhou
	> Mail: williamzhou.0330@foxmail.com 
	> Created Time: Sat 25 Mar 2017 05:48:35 AM PDT
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;
int isOK[10+1][50000];

int main(int argc,char* argv[]){
	//isOK[0][0]=1;
	int N=0;
	cin>>N;
	vector<int> value(N);
	int sum=0;
	for(int i=0;i<N;i++){
		cin>>value[i];
		sum+=value[i];
	}
	isOK[0][value[0]]=1;
	isOK[0][0]=1;
	for(int i=1;i<N;i++){
		for(int j=0;j<50000;j++){
			if(j>=value[i]){
				isOK[i][j]=isOK[i-1][j-value[i]]||isOK[i-1][j];
			}
			else{
				isOK[i][j]=isOK[i-1][j];
			}
		}
	}
	cout<<"sum="<<sum<<endl;
	int n=sum/2;
	cout<<"n="<<n<<endl;
	while(!isOK[N-1][n]) --n;
	cout<<n<<" "<<sum-n<<endl;
	for(int i=0;i<11;i++){
		for(int j=0;j<30;j++){
			cout<<isOK[i][j]<<" ";
		}
		cout<<endl;
	}
}
