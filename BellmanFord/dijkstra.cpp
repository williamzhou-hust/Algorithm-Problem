/*************************************************************************
	> File Name: bellmanford.cpp
	> Author: williamzhou
	> Mail: williamzhou.0330@foxmail.com 
	> Created Time: Mon 03 Apr 2017 08:36:18 AM PDT
 ************************************************************************/

#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#define M 0x3FFFFFFF
using namespace std;

enum color{WHITE=1,GRAY=2,BLACK=3};
typedef color nodeColor;

int globtime=0;

class Node{
public:
	Node(int rindex):index(rindex),d(0),f(0),pi(-1),clr(WHITE){};
	Node():index(-1),d(0),f(0),pi(-1),clr(WHITE){};
	//set data
	//void setIndex(int rindex){index=rindex;};
	void setDistance(int rd){d=rd;};
	void setF(int rf){f=rf;};
	void setFatherNode(int rpi){pi=rpi;};
	void setColor(nodeColor rclr){clr=rclr;};
	//get data
	int getIndex(){return index;};
	int getDistance(){return d;};
	int getF(){return f;};
    int getFatherNode(){return pi;};
    nodeColor getColor(){return clr;};
	//print property
	void printProperty(){
		cout<<index<<"th Node, "<<"distance: "<<d<<" ,finished time: "<<f<<" ,fatherNode: "<<pi<<" ,color: "<<clr<<endl;
	};
private:
	int index;//the value th node
	int d;//distance
	int f;//finish time
	int pi;//father node
	nodeColor clr;
};

int Table[7][7]={{M,10,M,5,M,M,M},
	{M,M,1,2,M,M,M},
	{M,M,M,M,4,M,M},
	{M,3,9,M,2,3,4},
	{7,M,6,M,M,M,1},
	{M,M,M,M,M,M,1},
	{M,M,M,M,M,M,M}};

void dfs(vector<Node>& mvec,int u){
	int N=mvec.size();
	++globtime;
	mvec[u].setDistance(globtime);
	mvec[u].setColor(GRAY);
	for(int j=0;j<N;j++){
		if(Table[u][j]!=M&&mvec[j].getColor()==WHITE){
			mvec[j].setFatherNode(u);
			dfs(mvec,j);
		}
	}
	mvec[u].setColor(BLACK);
	++globtime;
	mvec[u].setF(globtime);
}

void initializeSigleSourse(vector<Node>& mvec,int s){
	int N=mvec.size();
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

#define BELLMANFORD
#ifdef BELLMANFORD
bool bellmanford(vector<Node> mvec,int start){
	int N=mvec.size();
	bool answer=true;
	initializeSigleSourse(mvec,start);
	cout<<"after initial: "<<endl;
	for(int i=0;i<N;i++) mvec[i].printProperty();
	for(int l=1;l<N;l++){
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				if(i!=j&&Table[i][j]!=M){
					relax(mvec,i,j);
				}
			}
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(i!=j&&mvec[i].getDistance()+Table[i][j]<mvec[j].getDistance()){
				answer=false;
			}
		}
	}
	cout<<"after bellmanford: "<<endl;
	for(int i=0;i<N;i++) mvec[i].printProperty();
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
	return answer;
}
#endif

bool isShorterNode(const pair<int,int>& u,const pair<int,int>& v){
	return u.second>v.second;
}

//don't have loop
#define DGASHORTEST
#ifdef DGASHORTEST
void dgashortestpaths(vector<Node> mvec,int start){
	int N=mvec.size();
	//bool answer=true;
	//dfs tuopu sort
	dfs(mvec,start);
	for(int i=0;i<N;i++){
		if(mvec[i].getColor()==WHITE){
			dfs(mvec,i);
		}
	}
	cout<<"after dfs: "<<endl;
	for(int i=0;i<N;i++) mvec[i].printProperty();
	vector<pair<int,int>> order;
	for(int i=0;i<N;i++){
		//order.push_back(make_pair(i,mvec[i].getF()));
		order.emplace_back(i,mvec[i].getF());
	}
	cout<<"order: "<<endl;
	for(int i=0;i<N;i++) cout<<order[i].first<<":"<<order[i].second<<" ";
	cout<<endl;
	sort(order.begin(),order.end(),isShorterNode);
	cout<<"after sort order: "<<endl;
	for(int i=0;i<N;i++) cout<<order[i].first<<":"<<order[i].second<<" ";
	cout<<endl;
	initializeSigleSourse(mvec,start);
	cout<<"after initial: "<<endl;
	for(int i=0;i<N;i++) mvec[i].printProperty();
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(order[i].first!=j&&Table[order[i].first][j]!=M){
				relax(mvec,order[i].first,j);
			}
		}
	}
	/*for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(i!=j&&mvec[i].getDistance()+Table[i][j]<mvec[j].getDistance()){
				answer=false;
			}
		}
	}*/
	cout<<"after dgashortestpaths: "<<endl;
	for(int i=0;i<5;i++) mvec[i].printProperty();
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
	return;
}
#endif

void dijkstra(vector<Node> mvec,int start){
	int N=mvec.size();
	vector<int> S;
	initializeSigleSourse(mvec,start);
	cout<<"after initial: "<<endl;
	for(int i=0;i<N;i++) mvec[i].printProperty();
	//initial
	mvec[start].setColor(BLACK);
	for(int j=0;j<N;j++){
		/*if(Table[start][j]!=M){
			mvec[j].setDistance(Table[start][j]);
			mvec[j].setFatherNode(start);
		}*/
		if(j!=start) relax(mvec,start,j);
	}
	cout<<"step1: "<<endl;
	for(int i=0;i<N;i++) mvec[i].printProperty();
	S.push_back(start);
	bool flag=true;
	while(flag){
		int u=*(S.end()-1);
		cout<<"u: "<<u<<endl;
		int mintmp=M;
		int tempj=0;
		flag=false;
		for(int j=0;j<N;j++){
			if(Table[u][j]<mintmp&&mvec[j].getColor()==WHITE){
				mintmp=Table[u][j];
				tempj=j;
				flag=true;
			}
		}
		if(flag){
			cout<<"tempj: "<<tempj<<endl;
			mvec[tempj].setDistance(mvec[u].getDistance()+mintmp);
			mvec[tempj].setColor(BLACK);
			S.push_back(tempj);
			for(int j=0;j<N;j++){
				if(Table[tempj][j]!=M){
					relax(mvec,tempj,j);
				}
			}
		}
		else{
			for(int j=0;j<N;j++){
				if(mvec[j].getDistance()<mintmp&&mvec[j].getColor()==WHITE){
					mintmp=mvec[j].getDistance();
					tempj=j;
					flag=true;
				}
			}
			mvec[tempj].setColor(BLACK);
			S.push_back(tempj);
			for(int j=0;j<N;j++){
				if(Table[tempj][j]!=M){
					relax(mvec,tempj,j);
				}
			}
		}
	}
	cout<<"after dijkstra: "<<endl;
	for(int i=0;i<N;i++) mvec[i].printProperty();
	cout<<"min dest to 1: "<<endl;
	printMinPath(mvec,1);
	cout<<endl;
	cout<<"min dest to 4: "<<endl;
	printMinPath(mvec,4);
	cout<<endl;
	return;
}

int main(){
	vector<Node> mvec;
	for(int i=0;i<7;i++){
		mvec.emplace_back(i);
	}
	cout<<"bellmanford: "<<endl;
	bellmanford(mvec,0);
	//cout<<"dgashortestpaths: "<<endl;
	//dgashortestpaths(mvec,0);
	cout<<"dijkstra: "<<endl;
	dijkstra(mvec,0);
}
