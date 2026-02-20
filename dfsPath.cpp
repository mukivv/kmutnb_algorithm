#include <iostream>
#include <vector>

using namespace std;

int count = 0;
int start,stop;

void dfs(const vector<vector<int> >& graph, vector<int>& visited, int curr,vector<int>& path) {
    visited[curr] = 1;
    path.push_back(curr);
    
    if (curr == stop){
    	for (int i=0;i<path.size();i++){
    		cout << path[i] << " ";
		} cout << endl;
		count++;
	} else {
		for (int j = 0; j < graph[curr].size(); j++) {
        	if (!visited[graph[curr][j]]) {
        	    dfs(graph, visited, graph[curr][j],path);
        	}
		}
	}
	path.pop_back();
	visited[curr] = 0;
}

int main(){
	int v,e;
	cin >> v >> e;
	vector<int> visited(v,0);
	vector<vector<int> > graph(v);
	vector<int> path;
	
	for (int i=0;i<e;i++){
		int a,b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	
	cin >> start >> stop;
	
	dfs(graph,visited,start,path); //start,stop
	cout << "Count : "<< count;
}

