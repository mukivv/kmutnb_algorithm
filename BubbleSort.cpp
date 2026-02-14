#include <iostream>
#include <algorithm>

using namespace std;

const int n = 8;
int a[n] = {2,3,49,48,50,30,44,8};
bool swapped;
int swapCount = 0;

int main(){
	/* OR for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (a[j] > a[j+1])
	*/
	do { //D kwa for + for 0-n
		swapped = false; //do until all for i not swap = sort done
		for (int i=1;i<n;i++){
			if (a[i-1] > a[i]){
				swap(a[i-1],a[i]);
				swapped = true;
				++swapCount;
			}
		}
	} while (swapped); //if have swap(true) = doesn't finish | else not swap(false) = finish
	
	for (int i=0;i<n;i++){
		cout << a[i] << " ";
	}
	cout << "\n" << swapCount << endl;
}
