#include<bits/stdc++.h>

using namespace std;

int matrixChainMultiplication(int arr[], int i, int j){
    // Base condition 
    if(i >= j)
        return 0;

    int ans = INT_MAX;
    for(int k=i; k<=j-1; k++){
        int tempans = matrixChainMultiplication(arr, i, k) +
                        matrixChainMultiplication(arr, k+1, j) +
                        arr[i-1]*arr[k]*arr[j];
        ans = min(ans, tempans);
    }
    
    return ans;
}

int main()
{
       int arr[] ={40,20,30,10,30};
       int n = sizeof(arr)/sizeof(arr[0]);
       
       cout<<"Minimum cost of matrix chain multiplication:\t"<<matrixChainMultiplication(arr, 1, n-1)<<"\n";
}