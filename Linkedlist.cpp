#include <iostream>
#include <vector>

using namespace std;

int main(){
	int v,e;
	cin >> v >> e;
	vector<int> graph[v]; //array 2D but each row size !=
	
	for (int i=0;i<e;i++){
		int a,b;
		cin >> a >> b;
		graph[a].push_back(b);
	}
	
	for (int i=0;i<v;i++){
		cout << i << " :   ";
		for (int j=0;j<graph[i].size();j++){
			cout << graph[i][j] << " ";
		} cout << endl;
	}
}

/*
5 10
0 0
0 1
0 2
1 3
2 0
2 1
2 4
3 2
3 4
4 1
*/
