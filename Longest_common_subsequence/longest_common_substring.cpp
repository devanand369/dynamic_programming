#include<bits/stdc++.h>

using namespace std;

int longestCommonSubstring(string a, string b, int m, int n){
    int t[m+1][n+1];

    // Initialization
    for(int i=0; i<m+1; i++){
        for(int j=0; j<n+1; j++){
            if(i==0 || j==0)
                t[i][j] = 0;
        }
    }

    // Choice Diagram
    int lcss = t[0][0];
    for(int i=1; i<m+1; i++){
        for(int j=1; j<n+1; j++){
            if(a[i-1]==b[j-1]){
                t[i][j] = t[i-1][j-1] + 1;
                lcss = max(lcss, t[i][j]);
            }
            else
                t[i][j] = 0;
        }
    }

    return lcss;
}

int main()
{
    string a = "abcde";
    string b = "abfce";
    int m = a.length();
    int n = a.length();

    cout<<"Length of Longest common substring:\t"<<longestCommonSubstring(a, b, m, n)<<"\n";
}