#include<bits/stdc++.h>

using namespace std;

int lcs(string X, string Y, int m, int n){
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

    return t[m][n];
}

int main()
{
    string X = "abcdgh";
    string Y = "abedfhr";
    int m = X.length();
    int n = Y.length();

    cout<<"Longest Common Subsequence be \t"<<lcs(X, Y, m, n)<<"\n";
}