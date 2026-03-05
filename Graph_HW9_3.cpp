#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define inf 50000

using namespace std;

vector<int> dijkstra(int n,vector<pair<int,int> > graph[],const vector<int>& hospital){
	priority_queue<pair<int,int> , vector<pair<int,int> >,greater<pair<int,int> > > pq;
	vector<int> dist(n+1,inf);
	
	for (int i=0;i<hospital.size();i++){
		dist[hospital[i]] = 0;
		pq.push({0,hospital[i]});
	}
	while(!pq.empty()){
		int d = pq.top().first;
		int u = pq.top().second;
		pq.pop();
		
		if (d > dist[u]) continue;
		
		for (int j=0;j<graph[u].size();j++){
			int v = graph[u][j].first;
			int w = graph[u][j].second;
			if (dist[u] + w < dist[v]){
				dist[v] = dist[u] + w;
				pq.push({dist[v],v});			
			}	
		}
	}
	
	return dist;
}

int main(){
	int f,n,k,s,t,w,maxNode=0;
	cin >> f >> n;
	vector<int> oldHospital(f);
	vector<int> haveHospital(101,0);
	vector<pair<int,int> > graph[101];
	for (int i=0;i<f;i++){
		cin >> k;
		oldHospital[i] = k;
		haveHospital[k] = 1;
	}
	for (int i=0;i<n;i++){
		cin >> s >> t >> w;
		graph[s].push_back({t,w});
		graph[t].push_back({s,w});
		maxNode = max(maxNode, max(s, t));
	}
	
	int best = -1;
	int minDist = inf;
	
	for (int i=1;i<=maxNode;i++){
		if (haveHospital[i]) continue;
		vector<int> placeHos = oldHospital;
		placeHos.push_back(i);
		vector<int> dist = dijkstra(maxNode, graph, placeHos);
		
		int currMax = 0;
		for (int j=1;j<=maxNode;j++){
			if (dist[j] != inf) currMax = max(currMax,dist[j]);
		}
		
		if (currMax < minDist) {
            minDist = currMax;
            best = i;
        } else if (currMax == minDist) {
            if (best == -1 || i < best) best = i;
        }
	}
	
	cout << best << endl;
	return 0;
}
