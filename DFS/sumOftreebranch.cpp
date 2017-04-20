/*************************************************************************
	> File Name: sumOftreebranch.cpp
	> Author: williamzhou
	> Mail: williamzhou.0330@foxmail.com 
	> Created Time: Thu 30 Mar 2017 04:48:09 AM PDT
 ************************************************************************/

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
using namespace std;

enum color{WHITE=1,GRAY=2,BLACK=3};
typedef color nodeColor;
//int mtime=0;//global time

struct Node{
	int value;
	Node* left;
	Node* right;
};

int mtime=0;

int main(int argc,char* argv[]){
	vector<Node> mvec(7);
	int x[7]={10,5,15,9,31,21,17};
	for(int i=0;i<7;i++){
		mvec[i].value=x[i];
		mvec[i].left=NULL;
		mvec[i].right=NULL;
	}
	mvec[0].left=&mvec[1];
	mvec[0].right=&mvec[2];
	mvec[1].left=&mvec[3];
	mvec[1].right=&mvec[4];
	mvec[2].left=&mvec[5];
	mvec[2].right=&mvec[6];
	void findSum(Node* root,int rsum);
	findSum(&mvec[0],46);
}

void findSum(Node* root,int rsum){
	stack<Node*> mstk;
	map<Node*,int> mapsum;
	mapsum.insert(pair<Node*,int>(root,root->value));
	map<Node*,Node*> mapfather;
	mapfather.insert(pair<Node*,Node*>(root,NULL));
	mstk.push(root);
	while(!mstk.empty()){
		Node* fron=mstk.top();
		mstk.pop();
		cout<<fron->value<<endl;
		if(fron->right!=NULL){
			mstk.push(fron->right);
			mapsum.insert(pair<Node*,int>(fron->right,mapsum[fron]+fron->right->value));
			mapfather.insert(pair<Node*,Node*>(fron->right,fron));
		}
		if(fron->left!=NULL){
			mstk.push(fron->left);
			mapsum.insert(pair<Node*,int>(fron->left,mapsum[fron]+fron->left->value));
			mapfather.insert(pair<Node*,Node*>(fron->left,fron));
		}
	}
	for(map<Node*,int>::iterator ite=mapsum.begin();ite!=mapsum.end();ite++){
		if(ite->second==rsum){
			Node* t=ite->first;
			cout<<++mtime<<"th path: ";
			stack<int> temp;
			while(t){
				temp.push(t->value);
				t=mapfather[t];
			}
			while(!temp.empty()){
				cout<<temp.top()<<" ";
				temp.pop();
			}
			cout<<endl;
		}
	}
}
