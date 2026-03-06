#include <iostream>
#include <vector>

using namespace std;

vector<int> x;
vector<float> mean(5000, -1);

float tdMean(int n) { //5
    if (n == 1) return (float)x[0];
    if (mean[n] != -1) return mean[n];
    return mean[n] = (tdMean(n - 1)*(n-1) + x[n-1]) / n;
}

int main() {
    int ne;
    int n = 0; 

    while (cin >> ne && ne != -1) {
        x.push_back(ne);
        n++;
        cout << "Mean : "<< tdMean(n) << endl;
    }
    return 0;
}
