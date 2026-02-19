#include <iostream>
#include <stdio.h>

using namespace std;

int n, maxW;

struct Item{
	int num, weight , value;
	double vw;
};

void swap(Item &a,Item &b){
	Item t = a;
	a = b;
	b = t;
}

int partition(Item a[], int l, int r) {
    double pivot = a[l].vw;
    int i = l;
    
    for (int j = l+1; j <= r; j++) {
        if (a[j].vw > pivot) { 
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[l], a[i]);
    return i;
}

void quickSort(Item a[],int l,int r){
	if (l<r){
		int p = partition(a,l,r);
		quickSort(a,l,p-1);
		quickSort(a,p+1,r);
	}
}

int main(){
	cin >> n >> maxW;
	Item item[n];
	
	for (int i=0;i<n;i++){
		cin >> item[i].weight;
		item[i].num = i;
	}
	for (int i=0;i<n;i++){
		cin >> item[i].value;
		item[i].vw = (double)item[i].value / item[i].weight;
	}
	
	quickSort(item,0,n-1);
	
	double sumW=0 , sumV = 0 , amount[n] = {0};
	for (int i=0;i<n;i++){
		double *Amount = &amount[item[i].num];
		if (sumW + item[i].weight < maxW){
			sumW += item[i].weight;
			sumV += item[i].value;
			*Amount = 1.0;
		} else {
            *Amount = (double)(maxW - sumW) / item[i].weight;
            sumV += item[i].value * *Amount;
            sumW = maxW;
		}
	}
	
	for (int i=0;i<n;i++){
		printf("%.2f ",amount[i]);
	}
	printf("\n%.2f ",sumV);
}
