#include <iostream>
#include <vector>

int n,m,x,y,countV;

using namespace std;

void dfs(const vector<vector<char> >& graph, vector<vector<int> >& visited,int X,int Y){
	if (X < 1 || Y < 1 || X > n || Y > m ) return;
	if (graph[X][Y] != graph[x][y] || visited[X][Y]) return;

	visited[X][Y] = 1;
	countV++;

	dfs(graph,visited,X-1,Y);
	dfs(graph,visited,X+1,Y);
	dfs(graph,visited,X,Y-1);
	dfs(graph,visited,X,Y+1);
}

int main(){
	cin >> n >> m;
	vector<vector<char> > graph(n+1,vector<char>(m+1));
	vector<vector<int> > visited(n+1,vector<int>(m+1));
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			cin >> graph[i][j];
			visited[i][j];
		}
	}
	cin >> x >> y;
	dfs(graph,visited,x,y);
	cout << countV;
}
