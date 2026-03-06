#include <iostream>
#include <vector>

using namespace std;

struct C{
	vector<vector<float> > c;
	C(int n){
		c.assign(n+1, vector<float>(n+1,-1));
	}
	
	float tdc(int n,int k){ //3
		if (n==k) return 1;
		if (k==0) return 1;
		if (c[n][k] != -1) return c[n][k];
		return c[n][k] = tdc(n-1,k-1) + tdc(n-1,k);
	}
	
	float buc(int n,int k){ //4
		for (int i=0;i<n;i++){
			c[i][i] = 1;
			c[i][0] = 1;
		}
		for (int i=2;i<n;i++){
			for (int j=1;j<i;j++){
				c[i][j] = c[i-1][j-1] + c[i-1][j];
			}
		}
		return c[n][k];
	}
};

int main(){
	int n=20,k=6;
	C choose(n);
	cout << choose.tdc(n,k) << endl;
	cout << choose.buc(n,k);
}
