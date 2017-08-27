#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;

int dp[5001];

void solve(int* dp, int m, bool flag, vector<int>& temp, int remain){
	if (remain <= 3){
		for (int i = 0; i<m; i++){
			if (dp[i] != 0)
				temp.push_back(dp[i]);
		}
		return;
	}
	if (flag == true){
		int cnt = 1;
		for (int i = 0; i<m; i++){
			if (dp[i] == 0){
				continue;
			}
			else{
				if (cnt == 2){
					dp[i] = 0;
					cnt = 1;
				}
				else{
					cnt++;
				}
			}
		}
		remain = (remain % 2 == 0) ? remain / 2 : remain / 2 + 1;
		//cout << flag << " " << remain << endl;
	}
	else{
		int cnt = 1;
		for (int i = 0; i<m; i++){
			if (dp[i] == 0) continue;
			else{
				if (cnt == 3){
					dp[i] = 0;
					cnt = 1;
				}
				else{
					cnt++;
				}
			}
		}
		//cout << remain << endl;
		remain = (remain % 3 == 0) ? 2 * remain / 3 : 2 * remain / 3 + 1;
		//cout << flag << " " << remain << endl;
	}
	solve(dp, m, !flag, temp, remain);
}

int main(int argc, char* argv[]){
	int n = 0;
	cin >> n;
	vector<vector<int>> ans;
	for (int i = 0; i<n; i++){
		int m = 0;
		cin >> m;
		vector<int> temp;
		for (int i = 0; i<m; i++){
			dp[i] = i + 1;
		}
		bool flag = true;
		solve(dp, m, flag, temp, m);
		ans.push_back(temp);
	}
	for (int i = 0; i<n; i++){
		int j = 0;
		for (j = 0; j<ans[i].size() - 1; j++)
			cout << ans[i][j] << " ";
		cout << ans[i][j]<<endl;
	}
	return 0;
}

