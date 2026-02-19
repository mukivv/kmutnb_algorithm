#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

struct Gift {
    int a, b;
    int Abs;
};

int n;

int partition(Gift a[], int l, int r) {
    int p=a[l].Abs;
    int i=l;
    for (int j=l+1;j<=r;j++) {
        if (a[j].Abs>p) { 
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[l],a[i]);
    return i;
}

void quickSort(Gift a[],int l,int r) {
    if (l<r) {
        int p = partition(a,l,r);
        quickSort(a,l,p-1);
        quickSort(a,p+1,r);
    }
}

int main() {
    cin >> n;
    Gift gift[n];
    
    for (int i = 0; i < n; i++) {
        cin >> gift[i].a >> gift[i].b;
        gift[i].Abs = abs(gift[i].a - gift[i].b);
    }

    quickSort(gift,0,n-1);

    int sumA=0,sumB=0;
    for (int i=0; i<n; i++) {
        int big = max(gift[i].a, gift[i].b);
        int small = min(gift[i].a, gift[i].b);
        
        // + bigG to small sum
        if (sumA <= sumB) {
            sumA += big;
            sumB += small;
        } else {
            sumB += big;
            sumA += small;
        }
    }
    cout << abs(sumA-sumB);
}
