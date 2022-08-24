#include<bits/stdc++.h>

using namespace std;

int targetSum(int arr[], int n, int ts){
    int r = 0;
    for (int i=0; i<n; i++)
        r += arr[i];
    int s = (r+ts)/2;

    int t[n+1][s+1];

    for (int i=0; i<n+1; i++){
        for (int j=0; j<s+1; j++){
            if (i==0)
                t[i][j] = 0;
            if (j==0)
                t[i][j] = 1;
        }
    }

    for (int i=1; i<n+1; i++){
        for (int j=1; j<s+1; j++){
            if (arr[i-1]<=j)
                t[i][j] = t[i-1][j-arr[i-1]] + t[i-1][j];
            else
                t[i][j] = t[i-1][j];
        }
    }

    return t[n][s];
}

int main()
{
    int arr[] = {1,1,2,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int ts = 1;

    cout<<"Number of target sum be: "<<targetSum(arr, n, ts)<<"\n";
}