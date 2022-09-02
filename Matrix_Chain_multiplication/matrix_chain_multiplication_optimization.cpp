#include<bits/stdc++.h>

using namespace std;

int static t[1001][1001];

int solve(int arr[], int i, int j){
    // Base condition 
    if (i >= j)
        return 0;

    // memoized
    if(t[i][j]!=-1)
        return t[i][j];
    

    int ans = INT_MAX;
    for(int k=i; k<=j-1; k++){
        // optimization
        int left=0, right=0;
        if(t[i][k]!=-1)
            left = t[i][k];
        else{
            left = solve(arr, i, k);
            t[i][k] = left;
        }
        if(t[k+1][j]!=-1)
            right = t[k+1][j];
        else{
            right = solve(arr, k+1, j);
            t[k+1][j] = right;
        }
        int tempname = left+ right+ arr[i-1]*arr[k]*arr[j];
        ans = min(ans, tempname);
    }

    return t[i][j] = ans;
}

int main()
{
       int arr[] ={40,20,30,10,30};
       int n = sizeof(arr)/sizeof(arr[0]);
       memset(t, -1, sizeof(t));
       
       cout<<"Minimum cost of matrix chain multiplication:\t"<<solve(arr, 1, n-1)<<"\n";
}