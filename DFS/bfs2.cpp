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

class Node{
public:
	Node(int rvalue):value(rvalue),d(0),pi(-1),clr(WHITE){};
	Node():value(-1),d(0),pi(-1),clr(WHITE){};
	//set data
	//void setValue(int rvalue){value=rvalue;};
	void setDistance(int rd){d=rd;};
	void setFatherNode(int rpi){pi=rpi;};
	void setColor(nodeColor rclr){clr=rclr;};
	//get data
	int getValue(){return value;};
	int getDistance(){return d;};
    int getFatherNode(){return pi;};
    nodeColor getColor(){return clr;};
	//print property
	void printProperty(){
		cout<<value<<"th Node, "<<"distance: "<<d<<" ,fatherNode: "<<pi<<" ,color: "<<clr<<endl;
	};
private:
	int value;//the value th node
	int d;//distance
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
	int startNode=0;
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
	//after bfs
	cout<<"After BFS:"<<endl;
	for(int i=0;i<7;i++){
		mvec[i].printProperty();
	}
	return 0;
}
