#include <iostream>

using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print(int x[], int end)
{
    for (int i = 1; i <= end; i++){
    	if ( (x[i] == 1 && x[i+1] == 2) || (x[i] == 2 && x[i+1] == 1) )
        x[0]++;    	
	}

}

void permute(int x[], int start, int end)
{
    if (start == end)
        print(x, end);

    for (int i = start; i <= end; i++)
    {
        swap(&x[start], &x[i]);
        permute(x, start + 1, end);
        swap(&x[start], &x[i]);
    }
}

int main()
{
    int n;
    cin >> n;
    if (n <= 10 && n >= 2){
    	int x[n + 1];
    	for (int i = 0; i <= n; i++)
			x[i] = i;
    	permute(x, 1, n);
    	cout << x[0] << endl;
	}
}

