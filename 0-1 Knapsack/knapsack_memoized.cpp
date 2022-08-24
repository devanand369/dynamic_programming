#include<iostream>
#include<cstring>

using namespace std;

// this knapsack algorithm implementation using recursion + memoization
int knapsack(int wt[], int val[], int w, int n)
{
    // Memoization 
    int t[n+1][w+1];
    memset(t, -1, sizeof(t));

	// Base condition
	if (n == 0 || w == 0)
		return 0;

    if (t[n][w] != -1)
        return t[n][w];

    // Choice diagram
    if (wt[n-1] <= w)
        return t[n][w] = max(val[n-1]+ knapsack(wt, val, w-wt[n-1], n-1),
        knapsack(wt, val, w, n-1));
    else
        return t[n][w] = knapsack(wt, val, w, n-1);
	
}

int main()
{
	int n = 4;
	int wt[] = {1,3,4,5 };
	int val[] = { 1,4,5,7 };
	int w = 7;

	cout << "Maximum Profit be : " << knapsack(wt, val, w, n) << "\n";
	return 0;
}