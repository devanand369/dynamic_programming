#include<bits/stdc++.h>

using namespace std;

int minimumSubsetSumDiff(int arr[], int n) {
    int r = 0;
    for (int i=0; i<n; i++)
        r += arr[i];

    bool t[n+1][r+1];

    for (int i=0; i<n+1; i++){
        for (int j=0; j<r+1; j++){
            if(i==0)
                t[i][j] = false;
            if(j==0)
                t[i][j] = true;
        }
    }

    for (int i=1; i<n+1; i++){
        for (int j=1; j<r+1; j++){
            if (arr[i-1]<=j)
                t[i][j] = (t[i-1][j-arr[i-1]] || t[i-1][j]);
            
            else
                t[i][j] = t[i-1][j];
        }
    }

    vector<int> v;
    for(int i=0; i<=r/2; i++){
        if(t[n][i])
            v.push_back(i);
    }

    int minm = INT_MAX;
    for (int i=0; i<v.size(); i++){
        minm = min(minm, r-2*v[i]);
    }


    return minm;
}

int main()
{
    int arr[] = {1, 2, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    cout<<"Minimum subset sum difference of a given set be: \t"<<minimumSubsetSumDiff(arr, n)<<"\n";
}