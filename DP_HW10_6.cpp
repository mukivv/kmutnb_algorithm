#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int> > a(60,vector<int> (60));
int x0,y0,x1,y1;
vector<vector<int> > memo(60,vector<int> (60,-1));

int sum(int x,int y){
	if (x==x0 && y==y0) return a[x][y];
	if (x<x0 || y<y0) return 999999;
	if (memo[x][y] != -1) return memo[x][y];
	return memo[x][y] = a[x][y] + min(sum(x-1,y),sum(x,y-1));
}

int main(){
	int m,n;
	cin >> m >> n;
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			cin >> a[i][j];
		}
	}
	cin >> x0 >> y0 >> x1 >> y1;

	cout << sum(x1,y1);
}
