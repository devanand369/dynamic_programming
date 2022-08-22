#include<bits/stdc++.h>

using namespace std;

int knapsack(vector<int> wt, vector<int> val, int w, int n)
{
	// Base condition
	if (n == 0 || w == 0)
		return 0;
	
	// Choice diagram
	if (wt[n - 1] <= w)
		return max(val[n - 1] + knapsack(wt, val, w - wt[n - 1], n - 1),
			knapsack(wt, val, w, n - 1));
	else
		return knapsack(wt, val, w, n - 1);
}

int main()
{
	int n = 4;
	vector<int> wt = { 1,3,4,5 };
	vector<int> val = { 1,4,5,7 };
	int w = 7;

	cout << "Maximum Profit be : " << knapsack(wt, val, w, n) << "\n";
	return 0;
}