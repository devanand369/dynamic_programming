#include<bits/stdc++.h>

using namespace std;

int static t[1001][1001];

bool isPalindrome(string s, int i, int j) {
    if(i==j)
        return true;
    if(i>j)
        return true;

    while(i<j){
        if(s[i]!=s[j])
            return false;
        i++;
        j--;
    }
    return true;
}

int solve(string s, int i, int j) {
    // Base condition
    if(i >= j)
        return 0;
    if(isPalindrome(s, i, j))
        return 0;

    // memoized
    if(t[i][j]!=-1)
        return t[i][j];

    int ans = INT_MAX;
    for(int k=i; k<j; k++){
        // optimization
        int left=0, right=0;
        if(t[i][k]!=-1)
            left = t[i][k];
        else{
            left = solve(s, i, k);
            t[i][k] = left;
        }
        if(t[k+1][j]!=-1)
            right = t[k+1][j];
        else{
            right = solve(s, k+1, j);
            t[k+1][j] = right;
        }
        int tempans = left + right + 1;
        ans = min(ans, tempans);
    }

    return ans;
}

int main()
{
    string s = "devanand";
    int n = s.length();
    memset(t, -1, sizeof(t));

    cout<<"Minimum palindromic partition:\t"<<solve(s, 0, n-1)<<"\n";
}