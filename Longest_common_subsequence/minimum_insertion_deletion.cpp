#include<bits/stdc++.h>

using namespace std;

pair<int, int> minimumInsertionDeletion(string a, string b, int m, int n){
    int t[m][n];

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

    pair<int, int> ans;
    ans.first = n-t[m][n];
    ans.second = m-t[m][n];

    return ans;
}

int main()
{
    string a = "heap";
    string b = "pea";
    int m = a.length();
    int n = b.length();

    cout<<"Minimum number of Insertion:\t"<<minimumInsertionDeletion(a, b, m, n).first<<"\n";
    cout<<"Minimum number of Deletion:\t"<<minimumInsertionDeletion(a, b, m, n).second<<"\n";

}