//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int equalPartition(int n, int arr[])
    {
        int s=0;
        for (int i=0; i<n; i++)
            s += arr[i];

        if (s%2 != 0)
            return false;
            
        s /= 2;
        
        bool t[n+1][s+1];
        
        for (int i=0; i<n+1; i++){
            for (int j=0; j<s+1; j++){
                if (i==0)
                    t[i][j] = false;
                if (j==0)
                    t[i][j] = true;
            }
        }
        
        for (int i=1; i<n+1; i++){
            for (int j=0; j<s+1; j++){
                if (arr[i-1]<=j)
                    t[i][j] = (t[i-1][j-arr[i-1]] || t[i-1][j]);
                else
                    t[i][j] = t[i-1][j];
            }
        }
        
        return t[n][s];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends