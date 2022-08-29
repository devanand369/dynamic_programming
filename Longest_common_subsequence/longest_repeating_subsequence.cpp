#include<bits/stdc++.h>

using namespace std;

int longestRepeatingSubsequence(string s, int n){
    int t[n+1][n+1];
    
    // Initialization
    for(int i=0; i<n+1; i++){
        for(int j=0; j<n+1; j++){
            if(i==0 || j==0)
                t[i][j] = 0;
        }
    }

    // Choice Diagram
    for(int i=1; i<n+1; i++){
        for(int j=1; j<n+1; j++){
            if((s[i-1]==s[j-1]) && (i!=j))
                t[i][j] = t[i-1][j-1] + 1;
            else
                t[i][j] = max(t[i][j-1], t[i-1][j]);
        }
    }

    return t[n][n];
}

int main()
{
    string s = "AABEBCDD";
    int n = s.length();

    cout<<"Longest Repeating subsequence:\t"<<longestRepeatingSubsequence(s, n)<<"\n";
}