/*************************************************************************
	> File Name: findReverseNumbers.cpp
	> Author: williamzhou
	> Mail: williamzhou.0330@foxmail.com 
	> Created Time: Mon 03 Apr 2017 06:57:00 AM PDT
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

int main(){
	string s;
	cin>>s;
	int N=s.size();
	int* countA=new int[N];
	int* countB=new int[N];
	int* countC=new int[N];
	int* countD=new int[N];
	//for(int i=0;i<N-1;i++) cout<<countA[i]<<" ";
	//cout<<endl;
	int ans=0;
	for(int i=N-1;i>=0;i--){
		if(i==N-1){
			switch(s[i]){
			case 'A':
			{
				countA[i]=1;			
				break;
			}
			case 'B':
			{
				countB[i]=1;
				break;
			}
			case 'C':
			{
				countC[i]=1;
				break;
			}
			case 'D':
			{
				countD[i]=1;
				break;
			}
			}
		}
		else{
			switch(s[i]){
			case 'A':
			{
				countA[i]=countA[i+1]+1;			
				countB[i]=countB[i+1];
				countC[i]=countC[i+1];
				countD[i]=countD[i+1];
				break;
			}
			case 'B':
			{
				ans+=(countA[i+1]);
				countB[i]=countB[i+1]+1;
				countA[i]=countA[i+1];			
				countC[i]=countC[i+1];
				countD[i]=countD[i+1];
				break;
			}
			case 'C':
			{
				ans+=(countA[i+1]+countB[i+1]);
				countC[i]=countC[i+1]+1;
				countA[i]=countA[i+1];			
				countB[i]=countB[i+1];
				countD[i]=countD[i+1];
				break;
			}
			case 'D':
			{
				ans+=(countA[i+1]+countB[i+1]+countC[i+1]);
				countD[i]=countD[i+1]+1;
				countA[i]=countA[i+1];			
				countB[i]=countB[i+1];
				countC[i]=countC[i+1];
				break;
			}
			}
		}
	}
	cout<<"countA[i] countB[i] countC[i] countD[i]"<<endl;
	for(int i=0;i<4;i++){
		cout<<countA[i]<<"        "<<countB[i]<<"        "<<countC[i]<<"        "<<countD[i]<<endl;
	}
	cout<<"answer is: "<<ans<<endl;
}
