#include <iostream>
#include <algorithm>

using namespace std;

struct Line {
    int start, end;
};

int partition(Line a[], int l, int r) {
    int p = a[l].start;
    int i = l;
    for (int j=l+1;j<=r;j++) {
        if (a[j].start<p) {
            i++;
            swap(a[i],a[j]);
        } else if (a[j].start==p && a[j].end>a[i].end) {
            swap(a[i],a[j]);
        }
    }
    swap(a[l],a[i]);
    return i;
}

void quickSort(Line a[],int l,int r) {
    if (l < r) {
        int p = partition(a,l,r);
        quickSort(a,l,p-1);
        quickSort(a,p+1,r);
    }
}

int main() {
    int n, targetStart, targetEnd;
    cin >> n;
    Line line[n];
    for (int i = 0; i < n; i++) 
		cin >> line[i].start >> line[i].end;
    cin >> targetStart >> targetEnd;

    quickSort(line,0,n-1);

    Line ans[n];
    int curr = targetStart, i = 0, count = 0;

    while (curr < targetEnd) {
        int bestEnd = -999999;
        int bestIndex = -1;
        while (i < n && line[i].start <= curr) {
            if (line[i].end > bestEnd) {
                bestEnd = line[i].end;
                bestIndex = i;
            }
            i++;
        }
        ans[count] = line[bestIndex];
        count++;
        curr = bestEnd;
    }
    
    cout << count << endl;
    for (int i=0;i<count;i++){
        cout << ans[i].start << " " << ans[i].end << endl;
	}
}
