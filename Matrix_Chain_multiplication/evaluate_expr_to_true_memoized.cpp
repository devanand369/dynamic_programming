#include<bits/stdc++.h>

using namespace std;

unordered_map<string, int> mp;

int solve(string s, int i, int j, bool isTrue){
    // Base condition
    if(i>j)
        return false;
    if(i==j){
        if(isTrue==true)
            return s[i]=='T';
        else
            return s[i]=='F';
    }

    string temp = to_string(i);  // i
    temp.push_back(' ');   // i 
    temp.append(to_string(j)); // i j
    temp.push_back(' '); // i j 
    temp.append(to_string(isTrue)); // i j isTrue

    if(mp.find(temp)!=mp.end())
        return mp[temp];
    

    int ans = 0;
    for(int k=i+1; k<j; k+=2){

        // temperory answers
        int lT = solve(s, i, k-1, true);
        int lF = solve(s, i, k-1, false);
        int rT = solve(s, k+1, j, true);
        int rF = solve(s, k+1, j, false);

        // ans via processing tempans
        if(s[k]=='&'){
            if(isTrue==true)
                ans += lT*rT;
            else
                ans += lF*rT + lT*rF + lF*rF;
        }
        if(s[k]=='|'){
            if(isTrue==true)
                ans += lT*rT + lT*rF + lF*rT;
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

    return mp[temp] = ans;
}

int main() {
    string s = "T|T&F^T";
    int n = s.length();
    mp.clear();
    cout<<solve(s, 0, n-1, true)<<"\n";
}