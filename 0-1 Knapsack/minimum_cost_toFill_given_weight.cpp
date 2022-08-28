//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
#include <bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.

class Solution{
		

	public:
	int minimumCost(int cost[], int N, int W) 
	{ 
        int t[N+1][W+1];
        int wt[N];
        for(int i=0; i<N; i++)
            wt[i] = i+1;
        
    
    // Initialization
    for(int i=0; i<N+1; i++){
        for(int j=0; j<W+1; j++){
            if(i==0 || j==0)
                t[i][j] = 0;
            
        }
    }


    for (int i=1; i<N+1; i++){
        for (int j=1; j<W+1; j++){
            if (wt[i-1]<=j && cost[i-1]!=-1)
                t[i][j] = min(cost[i-1]+t[i-1][j-wt[i-1]], t[i-1][j]);
            else    
                t[i][j] = t[i-1][j];
        }
    }

    return t[N][W];
	} 
};


//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, w;
        cin >> n >> w;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minimumCost(a, n, w) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends