#include <iostream>
#include <vector>

using namespace std;

int n;

void dfs(const vector<vector<int> >& graph, vector<int>& visited, int i) {
    visited[i] = 1;
    cout << i << " ";
    for (int j = 0; j < graph[i].size(); j++) {
        if (!visited[graph[i][j]]) {
            dfs(graph, visited, graph[i][j]);
        }
    }
}

int main(){
	int v,e;
	cin >> v >> e;
	vector<int> visited(v,0);
	vector<vector<int> > graph(v);
	
	for (int i=0;i<e;i++){
		int a,b;
		cin >> a >> b;
		graph[a].push_back(b);
	}
	
	dfs(graph,visited,0);
}
