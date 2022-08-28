#include<bits/stdc++.h>

using namespace std;

int minimumDeletionToMakePalindrome(string a, int n){
    string b;
    for(int i=n-1; i>=0; i--)
        b.push_back(a[i]);

    int t[n+1][n+1];

    for(int i=0; i<n+1; i++){
        for(int j=0; j<n+1; j++){
            if(i==0 || j==0)
                t[i][j] = 0;
        }
    }

    for(int i=1; i<n+1; i++){
        for(int j=1; j<n+1; j++){
            if(a[i-1]==b[j-1])
                t[i][j] = t[i-1][j-1] + 1;
            else
                t[i][j] = max(t[i][j-1], t[i-1][j]);
        }
    }

    return n-t[n][n];
}

int main()
{
    string s = "agbcba";
    int n = s.length();

    cout<<"Minimum number of deletions to make palindrome:\t"<<minimumDeletionToMakePalindrome(s, n)<<"\n";
}