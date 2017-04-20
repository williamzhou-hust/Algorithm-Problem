/*************************************************************************
	> File Name: bfs.cpp
	> Author: williamzhou
	> Mail: williamzhou.0330@foxmail.com 
	> Created Time: Tue 28 Mar 2017 05:58:01 AM PDT
 ************************************************************************/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

enum color{WHITE=1,GRAY=2,BLACK=3};
typedef color nodeColor;
int mtime=0;//global time

class Node{
public:
	Node(int rvalue):value(rvalue),d(0),f(0),pi(-1),clr(WHITE){};
	Node():value(-1),d(0),f(0),pi(-1),clr(WHITE){};
	//set data
	//void setValue(int rvalue){value=rvalue;};
	void setDistance(int rd){d=rd;};
	void setf(int rf){f=rf;};
	void setFatherNode(int rpi){pi=rpi;};
	void setColor(nodeColor rclr){clr=rclr;};
	//get data
	int getValue(){return value;};
	int getDistance(){return d;};
	int getf(){return f;};
    int getFatherNode(){return pi;};
    nodeColor getColor(){return clr;};
	//print property
	void printProperty(){
		cout<<value<<"th Node, "<<"distance: "<<d<<" f: "<<f<<" ,fatherNode: "<<pi<<" ,color: "<<clr<<endl;
	};
private:
	int value;//the value th node
	int d;//time to visit
	int f;//time when have down
	int pi;//father node
	nodeColor clr;
};

int Table[7][7]={{0,1,1,1,1,0,0},
				 {1,0,1,0,0,1,0},
				 {1,1,0,1,0,1,0},
				 {1,0,1,0,1,1,1},
				 {1,0,0,1,0,0,1},
				 {0,1,1,1,0,0,1},
				 {0,0,0,1,1,1,0}};

int main(int argc,char* argv[]){
	cout<<"color test: "<<"WHITE: "<<WHITE<<" GRAY: "<<GRAY<<" BLACK: "<<BLACK<<endl;
	vector<Node> mvec(7);
	cout<<"initial Node:"<<endl;
	for(int i=0;i<7;i++){
		mvec[i]=Node(i);
		mvec[i].printProperty();
	}
	void bfs(vector<Node>& mvec,int startNode);
	void dfs(vector<Node>& mvec,int startNode);
	dfs(mvec,4);
	//after dfs
	cout<<"After DFS:"<<endl;
	for(int i=0;i<7;i++){
		mvec[i].printProperty();
	}
	return 0;
}

void bfs(vector<Node>& mvec,int startNode){
	mvec[startNode].setColor(GRAY);
	queue<int> mqueue;
	mqueue.push(mvec[startNode].getValue());
	while(!mqueue.empty()){
		int uValue=mqueue.front();
		cout<<"u: ";
		mvec[uValue].printProperty();
		mqueue.pop();
		cout<<"uValue: "<<uValue<<endl;
		for(int i=0;i<7;i++){
			if(Table[uValue][i]){
				if(mvec[i].getColor()==WHITE){
					mvec[i].setColor(GRAY);
					mvec[i].setDistance(mvec[uValue].getDistance()+1);
					mvec[i].setFatherNode(mvec[uValue].getValue());
					mqueue.push(mvec[i].getValue());
				}
			}
		}
		mvec[uValue].setColor(BLACK);
	}
}

void dfs(vector<Node>& mvec,int startNode){
	++mtime;
	mvec[startNode].setDistance(mtime);
	mvec[startNode].setColor(GRAY);
	for(int i=0;i<7;i++){
		if(Table[startNode][i]==1&&mvec[i].getColor()==WHITE){
			mvec[i].setFatherNode(startNode);
			dfs(mvec,i);
		}
	}
	mvec[startNode].setColor(BLACK);
	++mtime;
	mvec[startNode].setf(mtime);
}
