#include<bits/stdc++.h>

using namespace std;

//subset sum problem
bool subsetSum(int arr[], int n, int sum){
    bool t[n+1][sum+1];
    memset(t, false, sizeof(t));

    // Base condition
    if (n==0)
        return false;
    
    if (t[n][sum] != false);
        return t[n][sum];
    
    // Choice Diagram
    if (arr[n-1] <= sum)
        t[n][sum] = (t[n-1][sum-arr[n-1]] || t[n-1][sum]);

    else
        t[n][sum] = t[n-1][sum];

}

int main()
{
    int arr[] = {2, 3, 7, 8, 10};    
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 11;

    subsetSum(arr, n, sum)? cout<<"True"<<"\n" : cout<<"False"<<"\n";

}