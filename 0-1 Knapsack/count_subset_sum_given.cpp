#include<bits/stdc++.h>

using namespace std;

int countSubsetSum(int arr[], int n, int s){
    
        int t[n+1][s+1];

        // Initialization

        for (int i=0; i<n+1; i++){
            for (int j=0; j<s+1; j++){
                if (i==0)
                    t[i][j] = 0;
                if (j==0)
                    t[i][j] = 1;
            }
        }

        for (int i=1; i<n+1; i++){
            for (int j=0; j<s+1; j++){
                if (arr[i-1]<=j)
                    t[i][j] = (t[i-1][j-arr[i-1]] + t[i-1][j]);
                else
                    t[i][j] = t[i-1][j];
            }
        }
        
        return t[n][s];
}


int main()
{
    int arr[] = {2, 3, 7, 8, 10};    
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 10;

    cout<<"Number of subsets be: \t"<<countSubsetSum(arr, n, sum)<<"\n";

}