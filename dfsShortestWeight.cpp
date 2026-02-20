#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int count = 0 , sumW = 0 , minW = INT_MAX;
int start,stop,v,e;
vector<int> shortpath;

void dfs(const vector<vector<int> >& graph, vector<int>& visited, int curr,vector<int>& path) {
    visited[curr] = 1;
    path.push_back(curr);
    
    if (curr == stop){
    	for (int i=0;i<path.size();i++){
    		cout << path[i] << " ";
			if (i<path.size()-1) cout << "--(" << graph[i][i+1] << ")-->" << " ";
		} cout << " | weight = " << sumW << endl;
		
		if (sumW < minW){
			minW = sumW;
			shortpath = path;
		}
	} 
	
	else {
		for (int j = 0; j < v; j++) {
        	if (graph[curr][j] != 0 && visited[j] == 0) {
        		sumW += graph[curr][j];
            	dfs(graph, visited, j, path);
            	sumW -= graph[curr][j];
        	}
    	}
	}
	
	path.pop_back();
	visited[curr] = 0;
}

int main(){
	cin >> v >> e;
	vector<int> visited(v,0);
	vector<vector<int> > graph(v,vector<int>(v,0));
	vector<int> path;
	
	for (int i=0;i<e;i++){
		int a,b,w;
		cin >> a >> b >> w;
		graph[a][b] = w;
		graph[b][a] = w;
	}
	
	cin >> start >> stop;
	
	dfs(graph,visited,start,path); //start,stop
	
	cout << endl;
	for (int i=0;i<v;i++){
		cout << i << " :   ";
		for (int j=0;j<v;j++){
			cout << graph[i][j] << " ";
		} cout << endl;
	}
	
	cout << endl;
	for (int i=0;i<shortpath.size();i++){
    	cout << shortpath[i] << " ";
	} cout << " | weight = " << minW << endl;
}

//shortest weight path

