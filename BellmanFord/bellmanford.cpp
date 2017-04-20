/*************************************************************************
	> File Name: bellmanford.cpp
	> Author: williamzhou
	> Mail: williamzhou.0330@foxmail.com 
	> Created Time: Mon 03 Apr 2017 08:36:18 AM PDT
 ************************************************************************/

#include <iostream>
#include <queue>
#include <vector>
#define M 0x3FFFFFFF
using namespace std;

enum color{WHITE=1,GRAY=2,BLACK=3};
typedef color nodeColor;

class Node{
public:
	Node(int rindex):index(rindex),d(0),pi(-1),clr(WHITE){};
	Node():index(-1),d(0),pi(-1),clr(WHITE){};
	//set data
	//void setIndex(int rindex){index=rindex;};
	void setDistance(int rd){d=rd;};
	void setFatherNode(int rpi){pi=rpi;};
	void setColor(nodeColor rclr){clr=rclr;};
	//get data
	int getIndex(){return index;};
	int getDistance(){return d;};
    int getFatherNode(){return pi;};
    nodeColor getColor(){return clr;};
	//print property
	void printProperty(){
		cout<<index<<"th Node, "<<"distance: "<<d<<" ,fatherNode: "<<pi<<" ,color: "<<clr<<endl;
	};
private:
	int index;//the value th node
	int d;//distance
	int pi;//father node
	nodeColor clr;
};

int Table[5][5]={{M,6,M,7,M},
	{M,M,5,8,-4},
	{M,-2,M,M,M},
	{M,M,-3,M,9},
	{2,M,7,M,M}};

void initializeSigleSourse(vector<Node>& mvec,int N,int s){
	for(int i=0;i<N;i++){
		mvec[i].setFatherNode(-1);
		mvec[i].setDistance(M);
	}
	mvec[s].setDistance(0);
}

void relax(vector<Node>& mvec,int u,int v){
	if(mvec[u].getDistance()+Table[u][v]<mvec[v].getDistance()){
		mvec[v].setDistance(mvec[u].getDistance()+Table[u][v]);
		mvec[v].setFatherNode(u);
	}
}

void printMinPath(vector<Node>& mvec,int x){
	//if(x==0){cout<<x<<" ";return;}
	if(x>=0){
		int t=mvec[x].getFatherNode();
		printMinPath(mvec,t);
		cout<<x<<" ";
	}
	return;
}

int main(){
	vector<Node> mvec;
	for(int i=0;i<5;i++){
		mvec.emplace_back(i);
	}
	bool answer=true;
	initializeSigleSourse(mvec,5,0);
	for(int i=0;i<5;i++) mvec[i].printProperty();
	for(int l=1;l<5;l++){
		for(int i=0;i<5;i++){
			for(int j=0;j<5;j++){
				if(i!=j&&Table[i][j]!=M){
					relax(mvec,i,j);
				}
			}
		}
	}
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			if(i!=j&&mvec[i].getDistance()+Table[i][j]<mvec[j].getDistance()){
				answer=false;
			}
		}
	}
	cout<<"after bellmanford: "<<endl;
	for(int i=0;i<5;i++) mvec[i].printProperty();
	cout<<"isn't have negtive loop: "<<boolalpha<<answer<<endl;
	//cout<<"min dest to 1: "<<endl;
	//int x=1;
	//intwhile(x>=0){
	//int	cout<<x<<" ";
	//int	x=mvec[x].getFatherNode();
	//int}
	//cout<<endl;
	cout<<"min dest to 1: "<<endl;
	printMinPath(mvec,1);
	cout<<endl;
	cout<<"min dest to 4: "<<endl;
	printMinPath(mvec,4);
	cout<<endl;
}
