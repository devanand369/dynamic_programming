#include<bits/stdc++.h>

using namespace std;

string printLCS(string X, string Y, int m, int n){
    int t[m+1][n+1];

    // Initialization
    for(int i=0; i<m+1; i++){
        for(int j=0; j<n+1; j++){
            if(i==0 || j==0)
                t[i][j] = 0;
        }
    }

    // Choice diagram
    for(int i=1; i<m+1; i++){
        for(int j=1; j<n+1; j++){
            if(X[i-1]==Y[j-1])
                t[i][j] = 1 + t[i-1][j-1];
            else
                t[i][j] = max(t[i][j-1], t[i-1][j]);
        }
    }

    string revlcs;
    int i=m, j=n;
    while(i>0 && j>0){
        if(X[i-1]==Y[j-1]){
            revlcs.push_back(X[i-1]);
            i--;
            j--;
        }
        else {
            if(t[i][j-1]>t[i-1][j])
                j--;
            else
                i--;
        }
    }
    string lcs;
    for(int i=revlcs.length()-1; i>=0; i--){
        lcs.push_back(revlcs[i]);
    }
    return lcs;
}


int main()
{
    string X = "abcdgh";
    string Y = "abedfhr";
    int m = X.length();
    int n = Y.length();

    cout<<"Longest Common Subsequence: "<<printLCS(X, Y, m, n)<<"\n";
}