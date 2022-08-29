#include<bits/stdc++.h>

using namespace std;

int minimumInsertionToMakePalindrome(string a, int n){
    int t[n+1][n+1];

    string b;
    for(int i=0; i<n; i++)
        b.push_back(a[n-i-1]);

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
    string a = "aebcbda";
    int n = a.length();

    cout<<"Minimum number of insertion to make palindrome:\t"<<minimumInsertionToMakePalindrome(a, n)<<"\n";
}