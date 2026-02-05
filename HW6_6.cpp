#include <iostream>
#include <algorithm>

using namespace std;

void print(char x[], int end)
{
    for (int i = 1; i <= end; i++){
    	cout << x[i];   	
	}
	cout << endl;
}

void permute(char x[], int start, int end)
{
    if (start == end)
        print(x, end);

    for (int i = start; i <= end; i++)
    {
    	sort(x + start, x + end + 1);
        swap(x[start], x[i]);
        permute(x, start + 1, end);
        swap(x[start], x[i]);
    }
}

int main()
{
    int n;
    cin >> n;
    
    if (n <= 26 && n >= 3){
    	char x[n + 1];
    	for (int i = 1; i <= n; i++)
			cin >> x[i];
    	permute(x, 1, n);
	}
}
