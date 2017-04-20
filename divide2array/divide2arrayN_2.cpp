/*************************************************************************
	> File Name: divide2arrayN_2.cpp
	> Author: williamzhou
	> Mail: williamzhou.0330@foxmail.com 
	> Created Time: Sat 25 Mar 2017 07:35:45 AM PDT
 ************************************************************************/

#include <iostream>
#include <set>
#include <vector>
using namespace std;

set<int> s[11][11];
int accsum[11];

int main(int argc,char* argv[]){
    int N;
	cin>>N;
	vector<int> v(N+1);
	for(int i=1;i<=N;i++){
		cin>>v[i];
	}
	void initAccSum(vector<int> v);
	initAccSum(v);
	for(int i=1;i<=N;i++){
		for(int j=1;j<=i;j++){
			s[i][1].insert(v[j]);
		}
		if(i!=1) s[i][i].insert(accsum[i]);
	}
	for(int i=2;i<=N;i++){
		for(int j=2;j<=i-1;j++){
			s[i][j].insert(s[i-1][j].begin(),s[i-1][j].end());
            for(set<int>::iterator ite=s[i-1][j-1].begin();ite!=s[i-1][j-1].end();ite++){
				s[i][j].insert(*ite+v[i]);
			}
		}
	}
	int maxnum=-1;
	for(set<int>::iterator ite=s[N][N/2].begin();ite!=s[N][N/2].end();ite++){
		if(*ite<=accsum[N]/2&&*ite>maxnum){
			maxnum=*ite;
		}
	}
	cout<<maxnum<<endl;
}

void initAccSum(vector<int> v){
	for(int i=1;i<v.size();i++){
		accsum[i]=accsum[i-1]+v[i];
		cout<<i<<" : "<<accsum[i]<<", ";
	}
	cout<<endl;
}

