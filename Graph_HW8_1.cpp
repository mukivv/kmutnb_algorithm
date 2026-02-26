#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int n,s,d;
int Min = INT_MAX;
int Count = 0;

void dfs(const vector<vector<int> >& graph, vector<int>& visited, int curr){
	visited[curr] = 1;
	
	if (curr == d) {
		if (Count < Min){
			Min = Count;
		}
	} else {
		for (int i=0;i<graph[curr].size();i++){
			if (visited[graph[curr][i]] == 0) {
				Count++;
				dfs(graph,visited,graph[curr][i]);
				Count--;
			}
		}
	}
	
	visited[curr] = 0;
}

int main(){
	cin >> n;
	vector<vector<int> > graph(n+1);
	vector<int> visited(n+1,0);
	for (int i=0;i<n;i++){
		int p,q;
		cin >> p >> q;
		while (q != 0){
			graph[p].push_back(q);
			cin >> q;
		}
	}
	cin >> s >> d;
	dfs(graph,visited,s);
	cout << Min;
}
