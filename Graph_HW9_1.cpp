#include <iostream>
#include <vector>
#include <queue>
#define inf 50000

using namespace std;

int dijkstra (vector<pair<int,int> > graph[], int v,int s,int t){
	priority_queue< pair<int,int> , vector <pair<int,int> > , greater< pair<int,int> > > pq;
	
	vector<int> dist(v,inf);
	vector<int> parent(v,-1);
	vector<bool> intree(v,false);
	
	pq.push( {0,s} );
	dist[s] = 0;
	while(!pq.empty()){
		int u = pq.top().second;
		intree[u]  = true;
		pq.pop();
		for (int j=0;j<graph[u].size();j++){
			int v = graph[u][j].first;
			int w = graph[u][j].second;
			
			if (intree[v] == false && dist[u] + w < dist[v]){
				dist[v] = dist[u] + w;
				pq.push( {dist[v],v} );
				parent[v] = u;
			}
		}
	}
	return dist[t];
}

int main(){
	int c,n,m,s,t,a,b,w;
	cin >> c;
	for (int i=0;i<c;i++){
		cin >> n >> m >> s >> t;
		vector<pair<int, int> > graph[n];
		for (int j=0;j<m;j++){
			cin >> a >> b >> w;
			graph[a].push_back({ b,w });
			graph[b].push_back({ a,w });
		}
		cout << dijkstra(graph,n,s,t) << endl;
	}
}
