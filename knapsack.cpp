#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> a;
int maxW = 7,num = 4;
int w[5] = {-1,1,3,4,5};
int v[5] = {-1,1,4,5,7};

int sum(int n,int W){
	int s[num+1][maxW+1];
	for (int i=0;i<=n;i++){
		s[i][0] = 0;
	}
	for (int i=1;i<=W;i++){
		s[0][i] = 0;
	}
	for (int i=1;i<=num;i++){
		for (int j=1;j<=maxW;j++){
			if (j < w[i]) s[i][j] = s[i-1][j]; //no
			else s[i][j] = max(v[i] + s[i-1][j-w[i]] , s[i-1][j]); //y or n
		}
	}
	
	return s[n][W];
}

int main(){
	cout << sum(num,maxW);
}
