#include<bits/stdc++.h>

using namespace std;

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

    int ans = INT_MAX;
    for(int k=i; k<j; k++){
        int tempans = solve(s, i, k) + solve(s, k+1, j) + 1;
        ans = min(ans, tempans);
    }

    return ans;
}

int main()
{
    string s = "devanand";
    int n = s.length();

    cout<<"Minimum palindromic partition:\t"<<solve(s, 0, n-1)<<"\n";
}