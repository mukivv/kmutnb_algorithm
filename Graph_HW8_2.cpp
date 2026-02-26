#include <iostream>
#include <vector>

using namespace std;
int n,k;

void dfs(const vector<vector<int> >& graph, vector<int>& visited,int curr){
	visited[curr] = 1;
	
	for (int i=0;i<graph[curr].size();i++){
		if (visited[graph[curr][i]] == 0){
			dfs(graph,visited,graph[curr][i]);
		}
	}
}
int main(){
	cin >> n;
	vector<vector<int> > graph(n+1);
	for (int i=0;i<n;i++){
		int p,q;
		cin >> p >> q;
		while(q != 0){
			graph[p].push_back(q);
			cin >> q;
		}
	}
	
	cin >> k;
	vector<int> start(k);
	for (int i=0;i<k;i++){
		cin >> start[i];
	}
	for (int i=0;i<k;i++){
		vector<int> visited(n+1,0);
		dfs(graph,visited,start[i]);

		bool have = false;
		for (int j=1;j<visited.size();j++){
			if (visited[j] == 0){
				cout << j << " ";
				have = true;
			}
		}
		if (!have) {
			cout << "0";
		}
		cout << endl;
	}
}
