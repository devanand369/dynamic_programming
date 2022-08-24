#include<iostream>
#include<cstring>

using namespace std;

// this knapsack algorithm implementation using iteration
int knapsack(int wt[], int val[], int w, int n)
{ 
    int t[n+1][w+1];

	// Initialization
	for (int i=0; i<n+1; i++){
        for (int j=0; j<w+1; j++){
            if (i==0 || j==0)
                t[i][j] = 0;
        }
        
    }

    for (int i=1; i<n+1; i++){
        for (int j=1; j<w+1; j++){
            // Choice diagram
            if (wt[i-1] <= j)
                t[i][j] = max(val[i-1]+ t[i-1][j-wt[i-1]], t[i-1][j]);
            else
                t[i][j] = t[i-1][j];
        }
    }

    return t[n][w];
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
