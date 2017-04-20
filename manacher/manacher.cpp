/*************************************************************************
	> File Name: manacher.cpp
	> Author: williamzhou
	> Mail: williamzhou.0330@foxmail.com 
	> Created Time: Mon 27 Mar 2017 04:06:28 AM PDT
 ************************************************************************/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main(int argc,char* argv[]){
	if(argc==1) {cout<<"not enough input!"<<endl;exit(1);};
	char* pchar=argv[1];
	string s(pchar);
	int manacher(string& s);
	cout<<"manacher: "<<manacher(s)<<endl;
	return 0;
}

int manacher(string& s){
	int N=s.length();
	string newstr(2*N+1,'#');
	for(int i=0;i<N;i++){
		newstr[2*i+1]=s[i];
	}
	cout<<newstr<<endl;
	int ptrans=0;
	cout<<"ptrans: "<<ptrans<<endl;
	int id=0,maxid=0,pos;
	vector<int> p(2*N+1,0);
	p[0]=1;
	for(int i=1;i<2*N+1;i++){
		if(i<maxid){
			p[i]=min(p[2*id-i],maxid-i);
		}
		else{
			p[i]=1;
		}
		while(newstr[i+p[i]]==newstr[i-p[i]]) ++p[i];
		if(i+p[i]>maxid){
			maxid=i+p[i];
			id=i;
		}
		if(p[i]>ptrans){
			ptrans=p[i];
			pos=i;
		}
	}
	for(int i=0;i<2*N+1;i++) cout<<p[i]<<" ";
	cout<<endl;
	cout<<"id: "<<pos<<" len: "<<ptrans<<endl;
	string rstr(ptrans-1,' ');
	for(int i=pos-ptrans+1,j=0;i<pos+ptrans;i++){
		if(newstr[i]!='#'){
			rstr[j++]=newstr[i];
		}
	}
	cout<<"huiwen substring: "<<rstr<<endl;
	return ptrans-1;
}
