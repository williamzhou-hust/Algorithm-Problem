/*************************************************************************
	> File Name: multOfNsub1.cpp
	> Author: williamzhou
	> Mail: williamzhou.0330@foxmail.com 
	> Created Time: Mon 27 Mar 2017 05:58:40 AM PDT
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc,char* argv[]){
	int N=0;
	cin>>N;
	vector<int> mv(N+1);
	long long P=1,Q=1;
	int numOf0=0;
	int maxneg=0x80000000,minneg=0x00000000;
	int minpos=0x7FFFFFFF;
	for(int i=1;i<N+1;i++) {
		cin>>mv[i];
		P=P*mv[i];
		if(mv[i]==0){
			numOf0++;
		}else if(mv[i]>0){
			Q=Q*mv[i];
			minpos=min(mv[i],minpos);
		}
		else if(mv[i]<0){
			maxneg=max(maxneg,mv[i]);
			minneg=min(minneg,mv[i]);
			Q=Q*mv[i];
		}
	}
	cout<<"P: "<<P<<" Q: "<<Q<<" numOf0: "<<numOf0<<endl;
	cout<<"maxneg: "<<maxneg<<" minneg: "<<minneg<<endl;
	if(numOf0==2) cout<<"maxNumofMult: "<<0<<endl;
	if(numOf0==1) cout<<"maxNumofMult: "<<max(Q,(long long)0)<<endl;
	if(P>0){
		cout<<"maxNumofMult: "<<(!minneg?P/minpos:P/minneg)<<endl;
	}
	else if(P<0){
		cout<<"maxNumofMult: "<<P/maxneg<<endl;
	}
	return 0;
}
