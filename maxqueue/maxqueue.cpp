/*************************************************************************
	> File Name: maxqueue.cpp
	> Author: williamzhou
	> Mail: williamzhou.0330@foxmail.com 
	> Created Time: Sun 09 Apr 2017 05:50:40 AM PDT
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

class maxstack{
	public:
		maxstack():maxnum(0x80000000){};
		void push(int rvar){
			mstk.push(rvar);
			if(rvar>maxnum){
				maxnum=rvar;
			}
			maxdata.push(maxnum);
		};
		void pop(){
			mstk.pop();
			maxdata.pop();
		};
		int top(){
			return !mstk.empty()?mstk.top():0x80000000;
		};
		bool empty(){
			return mstk.empty();
		};
		int stackmax(){
			return !maxdata.empty()?maxdata.top():0x80000000;
		};
		~maxstack(){};
	private:
		int maxnum;
		stack<int> mstk;
		stack<int> maxdata;
};

class maxqueue{
	public:
		maxqueue():frontdata(0),stka(),stkb(){};
		void push(int rvar){
			frontdata=rvar;
			stka.push(rvar);
		};
		void pop(){
			if(!stkb.empty()){
				stkb.pop();
			}
			else{
				while(!stka.empty()){
					int t=stka.top();
					stka.pop();
					stkb.push(t);
				}
				stkb.pop();
			}
		};
		int front(){
			return frontdata;
		};
		int queuemax(){
			return std::max(stka.stackmax(),stkb.stackmax());
		};
		bool empty(){
			return stka.empty()&&stkb.empty();
		};
		~maxqueue(){};
	private:
		int frontdata;
		maxstack stka;
		maxstack stkb;
};

int main(){
	maxqueue mq;
	cout<<"what to insert:"<<endl;
	for(int i=0;i<15;i++){
		int t=rand()%100;
		mq.push(t);
		cout<<t<<" ";
	}
	cout<<endl;
	for(int i=0;i<15;i++){
		cout<<15-i<<": maxnum: "<<mq.queuemax()<<endl;
		mq.pop();
	}
	return 0;
}
