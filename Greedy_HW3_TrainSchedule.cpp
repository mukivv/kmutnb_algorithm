#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int partition(double a[], int l, int r) {
    double p = a[l];
    int i = l;
    for (int j = l+1; j <= r; j++) {
        if (a[j] < p) { 
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[l], a[i]);
    return i;
}

void quickSort(double a[], int l, int r) {
    if (l < r) {
        int p = partition(a,l,r);
		quickSort(a,l,p-1);
		quickSort(a,p+1,r);
    }
}

int main() {
    int n;
    cin >> n;

    double in[n];
    double out[n];

    for (int i = 0; i < n; i++) {
        cin >> in[i] >> out[i];
    }

    quickSort(in, 0, n - 1);
    quickSort(out, 0, n - 1);

    int station = 0 ,maxStation = 0;
    int i = 0, j = 0;

    while (i < n && j < n) {
        if (in[i] < out[j]) {
            station++;
            i++;
            if (station > maxStation) 
				maxStation = station;
        } 
        else {
            station--;
            j++;
        }
    }
    cout << maxStation << endl;
}
