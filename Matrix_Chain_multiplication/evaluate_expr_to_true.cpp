#include<bits/stdc++.h>

using namespace std; 

int solve(string s, int i, int j, bool isTrue){
    // Base condition
    if(i > j)
        return false;
    if(i==j){
        if(isTrue==true)
            return s[i]=='T';

        else
            return s[i]=='F';
    }

    int ans = 0;
    for(int k=i+1; k<j; k+=2){
        int lT = solve(s, i, k-1, true);
        int lF = solve(s, i, k-1, false);
        int rT = solve(s, k+1, j, true);
        int rF = solve(s, k+1, j, false);

        if(s[k]=='&'){
            if(isTrue==true)
                ans += lT*rT;
            else
                ans += lF*rT + lT*rF + lF*rF;
        }

        if(s[k]=='|'){
            if(isTrue==true)
                ans += lT*rT + lF*rT + lT*rF;
            else
                ans += lF*rF;
        }

        if(s[k]=='^'){
            if(isTrue==true)
                ans += lT*rF + lF*rT;
            else
                ans += lT*rT + lF*rF;
        }

    }

    return ans;

}

int main() {
    string s = "T|T&F^T";
    int n = s.length();
    cout<<solve(s, 0, n-1, true)<<"\n";
}