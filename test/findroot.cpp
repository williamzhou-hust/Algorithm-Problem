/*************************************************************************
	> File Name: findroot.cpp
	> Author: williamzhou
	> Mail: williamzhou.0330@foxmail.com 
	> Created Time: Mon 03 Apr 2017 06:43:43 AM PDT
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int k=0;
	int a=0,b=0,c=0;
	while(cin>>k>>a>>b>>c){
		int minnum=min(a,min(b,c));
		int maxnum=max(a,max(b,c));
		int root=1<<(k-1);
		int kk=k;
		for(int i=0;i<k;i++){
			while(root<minnum){
				root+=1<<(kk-2);
				kk--;
			}
			while(root>maxnum){
				root-=1<<(kk-2);
				kk--;
			}
			if(root>=minnum&&root<=maxnum) break;
		}
		cout<<"root: "<<root<<endl;
		void func2(int k,int minnum,int maxnum);
		cout<<"for check: ";
		func2(k,minnum,maxnum);
		cout<<endl;
	}
}

void func2(int k,int minnum,int maxnum){
	int left=1,right=(1<<k)-1;
	int mid=0;
	while(left<=right){
		mid=(left+right)/2;
		if(mid>maxnum) right=mid-1;
		if(mid<minnum) left=mid+1;
		if(minnum<=mid&&mid<=maxnum)
			break;
	}
	cout<<mid;
}

