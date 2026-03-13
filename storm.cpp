#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int r,c;
int countV,countMax=0,totalMax;

void dfs(const vector<vector<char> > &graph, vector<vector<int> > &visited,int X,int Y){
	if (X < 0 || Y < 0 || X >= r || Y >= c ) return;
	if (graph[X][Y] == '.' || visited[X][Y]) return;
	
	visited[X][Y] = 1;
	countV++;
	
	dfs(graph,visited,X-1,Y);
	dfs(graph,visited,X+1,Y);
	dfs(graph,visited,X,Y+1);
	dfs(graph,visited,X,Y-1);
}

int main(){
	cin >> r >> c;
	vector<vector<char> > graph(r,vector<char>(c));
	vector<vector<int> > visited(r,vector<int>(c));
	for (int i=0;i<r;i++){
		for (int j=0;j<c;j++){
			cin >> graph[i][j];
		}
	}
	
	for (int i=0;i<r;i++){
		for (int j=0;j<c;j++){
			
			if (graph[i][j] == '#' && visited[i][j] == 0){
				countV=0;
				dfs(graph,visited,i,j);
				
				if (countMax == countV) totalMax++;
				else if (countV  > countMax){
					countMax = countV;
					totalMax=1;
				}
			}
			
		}
	}
	
	cout << countMax << " " << totalMax;
}
