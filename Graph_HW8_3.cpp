#include <iostream>
#include <vector>

using namespace std;

int v,v1,v2,s,m;
int countV , maxV = 0;

void dfs(const vector<vector<int> >& graph, vector<int>& visited, vector<int>& visitedAll,int curr){
	visited[curr] = 1;
	visitedAll[curr] = 1;
	
	if (countV == m){
		return;
	} else {
		for (int i=0;i<graph[curr].size();i++){
			if (!visited[graph[curr][i]]){
				countV++;
				dfs(graph,visited,visitedAll,graph[curr][i]);
				countV--;
			}
		}
	}
	
	visited[curr] = 0;
}

int main(){
	cin >> v;
	vector<vector<int> > graph(v+1);
	vector<int> visited(v+1,0);
	vector<int> visitedAll(v+1,0);
	cin >> v1 >> v2;
	while ( v1 != 0 || v2 != 0 ){
		graph[v1].push_back(v2);
		cin >> v1 >> v2;
	}
	cin >> s >> m;
	dfs(graph,visited,visitedAll,s);
	for (int i=1;i<visitedAll.size();i++){
		if (visitedAll[i] == 0){
			maxV++;
		}
	} cout << maxV;
}
