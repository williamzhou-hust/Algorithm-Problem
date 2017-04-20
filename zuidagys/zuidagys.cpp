/*************************************************************************
	> File Name: zuidagys.cpp
	> Author: williamzhou
	> Mail: williamzhou.0330@foxmail.com 
	> Created Time: Sun 26 Mar 2017 04:52:50 AM PDT
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

int zuidagys(int m,int n){
	if(m<n) swap(m,n);
	return (!n)?m:zuidagys(n,m%n);
}

int zuidagys_2(int m,int n){
	if(m<n) swap(m,n);
	return (!n)?m:zuidagys_2(n,m-n);
}

int zuidagys_3(int m,int n){
    if(m<n) swap(m,n);
	int answer=0;
	if(n==0) return m;
	if((!(m&0x1))&&(!(n&0x1))){
		answer=2*zuidagys_3(m>>1,n>>1);
	}
	if((!(m&0x1))&&(n&0x1)){
		answer=zuidagys_3(m>>1,n);
	}
	if((m&0x1)&&(!(n&0x1))){
		answer=zuidagys_3(m,n>>1);
	}
	if((m&0x1)&&(n&0x1)){
		answer=zuidagys_3(n,m-n);
	}
	return answer;
}

int main(int argc, char* argv[]){
	int m,n;
	cin>>m>>n;
	cout<<"func1: "<<zuidagys(m,n)<<endl;
	cout<<"func2: "<<zuidagys_2(m,n)<<endl;	
	cout<<"func3: "<<zuidagys_3(m,n)<<endl;	
}
