#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, weight;
};

bool compareEdge(Edge a, Edge b) {
    return a.weight < b.weight;
}

struct DisjointSet {
    vector<int> parent;
    
    DisjointSet(int n) {
        parent.resize(n + 1);
        for (int i = 1; i <= n; i++) parent[i] = -1;
    }
    int find(int i) {
        if (parent[i] == -1) return i;
        return find(parent[i]);
    }
    void uni(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) parent[root_i] = root_j;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edge;
    for (int i=0;i<m;i++) {
        int u,v,w;
        cin >> u >> v >> w;
        edge.push_back({u, v, w});
    }

    sort(edge.begin(), edge.end(), compareEdge);

    DisjointSet ds(n);
	int totalw = 0;
    int count = 0;

    for (int i=0;i<m;i++) {
        if (ds.find(edge[i].u) != ds.find(edge[i].v)) {
            ds.uni(edge[i].u, edge[i].v);
            totalw += edge[i].weight;
            count++;
            
            if (count == n - 1) break;
        }
    }

    cout << totalw - count << endl;

    return 0;
}
