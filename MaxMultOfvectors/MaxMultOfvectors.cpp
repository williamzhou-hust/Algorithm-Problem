/*************************************************************************
	> File Name: MaxMultOfvectors.cpp
	> Author: williamzhou
	> Mail: williamzhou.0330@foxmail.com 
	> Created Time: Sat 01 Apr 2017 08:18:22 AM PDT
 ************************************************************************/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int dpmax[20]={0};
int dpmin[20]={0};

int dpmax1[20][20+1]={{0}};
int dpmin1[20][20+1]={{0}};

int main(int argc,char* argv[]){
	vector<int> mvec={1,-13,-12,-11,2,3,4,-9,-8,-7,7,-6,8,10,-5,-4,11,-3};
	int N=mvec.size();
	cout<<"mvec: "<<endl;
	for(int i=0;i<N;i++) cout<<mvec[i]<<" ";
	for(int i=0;i<20;i++){
		dpmax[i]=dpmin[i]=1;
	}
	cout<<endl;
	int mult=1;
	for(int i=0;i<N;i++){
		mult*=mvec[i];
	}
	cout<<"mult: "<<mult<<endl;
	dpmax[0]=dpmin[0]=mvec[0];
	for(int i=1;i<N;i++){
		dpmax[i]=max(dpmax[i-1]*mvec[i],dpmin[i-1]*mvec[i]);
		dpmin[i]=min(dpmax[i-1]*mvec[i],dpmin[i-1]*mvec[i]);
	}
	cout<<"max mult of serious vectors: "<<dpmax[N-1]<<endl;
	//i number choose j
	for(int i=0;i<20;i++){
		for(int j=0;j<=20;j++){
			if(j<=i+1){
				dpmax1[i][j]=1;
				dpmin1[i][j]=1;
			}
			else{
				dpmax1[i][j]=0x80000000;
				dpmin1[i][j]=0x7FFFFFFF;
			}
		}
	}
	dpmax1[0][1]=dpmin1[0][1]=mvec[0];
	for(int i=1;i<N;i++){
		for(int j=1;j<=i+1;j++){
			dpmax1[i][j]=max(dpmax1[i-1][j],max(dpmax1[i-1][j-1]*mvec[i],dpmin1[i-1][j-1]*mvec[i]));
			dpmin1[i][j]=min(dpmin1[i-1][j],min(dpmax1[i-1][j-1]*mvec[i],dpmin1[i-1][j-1]*mvec[i]));
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<=N;j++){
			cout<<dpmax1[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"N="<<N<<endl;
	for(int j=1;j<=20;j++){
		cout<<"max j: "<<j<<" dpmax1[N-1][j]: "<<dpmax1[N-1][j]<<endl;
		cout<<"min j: "<<j<<" dpmin1[N-1][j]: "<<dpmin1[N-1][j]<<endl;
	}
}
