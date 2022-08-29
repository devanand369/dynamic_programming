#include<bits/stdc++.h>

using namespace std;

string printSCS(string a, string b, int m, int n){
    int t[m+1][n+1];

    for(int i=0; i<m+1; i++){
        for(int j=0; j<n+1; j++){
            if(i==0 || j==0)
                t[i][j] = 0;
        }
    }

    for(int i=1; i<m+1; i++){
        for(int j=1; j<n+1; j++){
            if(a[i-1]==b[j-1])
                t[i][j] = t[i-1][j-1] + 1;
            else
                t[i][j] = max(t[i][j-1], t[i-1][j]);
        }
    }

    int i=m, j=n;
    string revscs;
    while(i>0 && j>0){
        if(a[i-1]==b[j-1]){
            revscs.push_back(a[i-1]);
            i--;
            j--;
        }
        else{
            if(t[i][j-1]>t[i-1][j]){
                revscs.push_back(b[j-1]);
                j--;
            }
            else{
                revscs.push_back(a[i-1]);
                i--;
            }
        }
    }

    string scs;
    int p = revscs.length();
    for(int i=0; i<p; i++){
        scs.push_back(revscs[p-i-1]);
    }

    return scs;
    
}

int main()
{
    string a = "acbcf";
    string b = "abcdaf";
    int m = a.length();
    int n = b.length();

    cout<<"Print shortest common supersequence:\t"<<printSCS(a, b, m, n)<<"\n";
}