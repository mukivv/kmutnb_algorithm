#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,total,minn=999999,totalCount;
bool ton(vector<pair<int,int> > &coin, vector<int> &save){
	int check=0;
	int totalCount = 0;
	for (int i=0;i<n;i++){
		int count;
		if (total / coin[i].first != 0){
			count = total / coin[i].first;
			check=1;
			if (count > coin[i].second){
				total -= coin[i].second * coin[i].first;
				save[i] = coin[i].second;
			} else {
				total -= count * coin[i].first;
				save[i] = count;
			}
			totalCount += save[i];
		}
	}
	minn = min(minn,totalCount);
	if (total != 0) check = 0;
	return check;
}

int main(){
	cin >> n;
	int v[n],num[n];
	vector<pair<int,int> > coin(n);
	vector<int> save(n,0);
	for (int i=0;i<n;i++){
		cin >> v[i];
	}
	for (int i=0;i<n;i++){
		cin >> num[i];
	}
	
	for (int i=0;i<n;i++){
		coin[i] = {v[i],num[i]};
	}
	
	cin >> total;
	sort(coin.begin(), coin.end(), greater<pair<int,int> >());
	
	if (ton(coin,save)){
		cout << minn << endl;
		for (int i=0;i<n;i++){
			if (save[i] != 0){
				cout << coin[i].first << ":" << save[i] << endl;
			}
		}
	} else {
		cout << "impossible";
	}
}
