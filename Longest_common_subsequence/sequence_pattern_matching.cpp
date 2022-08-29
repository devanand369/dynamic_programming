#include<bits/stdc++.h>

using namespace std;

int sequencePatternMatching(string a, string b, int m, int n){
    int t[m+1][n+1];
    
    // Initialization
    for(int i=0; i<m+1; i++){
        for(int j=0; j<n+1; j++){
            if(i==0 || j==0)
                t[i][j] = 0;
        }
    }

    // Choice Diagram
    for(int i=1; i<m+1; i++){
        for(int j=1; j<n+1; j++){
            if(a[i-1]==b[j-1])
                t[i][j] = t[i-1][j-1] + 1;
            else
                t[i][j] = max(t[i][j-1], t[i-1][j]);
        }
    }

    return t[m][n]==m?true:false;
}

int main()
{
    string a = "AXY";
    string b = "ADXCPY";
    int m = a.length();
    int n = b.length();

    cout<<"Longest Repeating subsequence:\t";
    sequencePatternMatching(a, b, m, n)?cout<<"True\n":cout<<"False\n";
}