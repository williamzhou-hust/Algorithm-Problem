/*************************************************************************
	> File Name: numOf1.cpp
	> Author: williamzhou
	> Mail: williamzhou.0330@foxmail.com 
	> Created Time: Fri 31 Mar 2017 05:50:00 AM PDT
 ************************************************************************/

#include <iostream>
using namespace std;

int main(int argc,char* argv[]){
	int rnum=0;
	int numOfone(int rnum);
	int numOfone2(int rnum);
	while(cin>>rnum){
		cout<<"number="<<rnum<<endl;
		cout<<"number of 1: (for check)"<<numOfone(rnum)<<endl;
		cout<<"number of 1: "<<numOfone2(rnum)<<endl;
	}
}

int numOfone(int rnum){
	int count=0;
	int bit1Ofnum(int i);
	for(int i=0;i<=rnum;i++) count+=bit1Ofnum(i);
	return count;
}

int bit1Ofnum(int i){
	int bcnt=0;
	while(i){
		if(i%10==1) ++bcnt;
		i/=10;
	}
	return bcnt;
}

int numOfone2(int rnum){
	int scale=10;
	int count=0;
	int lenOfnum(int rnum);
	int len=lenOfnum(rnum);
	for(int i=1;i<=len;i++){
		int nn=rnum/scale;
		int mm=rnum-nn*scale;
		count=count+nn*scale/10;
		if(mm*10/scale>1) count+=scale/10;
		else if(mm*10/scale==1) {
			//if(i!=1)
				count+=mm%(scale/10)+1;
			//else count+=1;
		}
		scale*=10;
	}
	return count;
}

int lenOfnum(int rw){
	if(rw>=0&&rw<=9) return 1;
	else if(rw>=10) return 1+lenOfnum(rw/10);
	return 0;
}
