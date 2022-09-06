#include<bits/stdc++.h>

using namespace std;



// unordered_map<string, int> mp;
int static t[51][51];
int isScramble(const string A, const string B) {
    //mp.clear();
    memset(t, -1, sizeof(t));
    if(A.length()!=B.length())
        return false;
    if(A.length()==0 && B.length()==0)
        return true;
    if(A.compare(B)==0)
        return true;
    if(A.length()<=1)
        return false;
        
    int n = A.length();
        
    // string key = A;
    // key.push_back(' ');
    // key.append(B);
    // if (mp.find(key)!=mp.end())
    //     return mp[key];
    
    if(t[A.length()][B.length()]!=-1)
        return t[A.length()][B.length()];
    
    
    bool flag = false;
    
    for(int i=1; i<n; i++){
        bool p, q, r, s;
        
        // if(mp.find(A.substr(0, i)+' '+B.substr(n-i, i))!=mp.end())
        //     p = mp[A.substr(0, i)+' '+B.substr(n-i, i)];
        // else{
        //     p = isScramble(A.substr(0, i), B.substr(n-i, i));
        //     mp[A.substr(0, i)+' '+B.substr(n-i, i)] = p;
        // }
        
        // if(mp.find(A.substr(i, n-i)+' '+B.substr(0, n-i))!=mp.end())
        //     q = mp[A.substr(i, n-i)+' '+B.substr(0, n-i)];
        // else{
        //     q = isScramble(A.substr(i, n-i), B.substr(0, n-i));
        //     mp[A.substr(i, n-i)+' '+B.substr(0, n-i)] = q;
        // }
        
        // if(mp.find(A.substr(0, i)+' '+B.substr(0, i))!=mp.end())
        //     r = mp[A.substr(0, i)+' '+B.substr(0, i)];
        // else{
        //     r = isScramble(A.substr(0, i), B.substr(0, i));
        //     mp[A.substr(0, i)+' '+B.substr(0, i)] = r;
        // }
        
        // if(mp.find(A.substr(i, n-i)+' '+B.substr(i, n-i))!=mp.end())
        //     s = mp[A.substr(i, n-i)+' '+B.substr(i, n-i)];
        // else{
        //     s = isScramble(A.substr(i, n-i), B.substr(i, n-i));
        //     mp[A.substr(i, n-i)+' '+B.substr(i, n-i)] = s;
        // }
        
        if(t[i][n-i]!=-1)
            p = t[i][n-i];
        else{
            p = isScramble(A.substr(0, i), B.substr(n-i, i));
            t[i][n-i] = p;
        }
        
        if(t[n-2*i][n-i]!=-1)
            q = t[n-2*i][n-i];
        else{
            q = isScramble(A.substr(i, n-i), B.substr(0, n-i));
            t[n-2*i][n-i] = q;
        }
        
        if(t[i][i]!=-1)
            r = t[i][i];
        else{
            r = isScramble(A.substr(0, i), B.substr(0, i));
            t[i][i] = r;
        }
        
        if(t[n-i][n-i]!=-1)
            s = t[n-i][n-i];
        else{
            s = isScramble(A.substr(i, n-i), B.substr(i, n-i));
            t[n-i][n-i] = s;
        }
            
        // case 1 swapping done
        bool cond1 = p && q;
        
    
        // case 2 swapping not done
        bool cond2 = r && s;
    
        if(cond1 || cond2){
            flag = true;
            break;
        }
        
    }
    
    // return mp[key] = flag;
    return t[A.length()][B.length()] = flag;
        
    
}




// unordered_map<string, int> mp;
// int isScramble(const string A, const string B) {
//     mp.clear();
//     if(A.length()!=B.length())
//         return false;
//     if(A.length()==0 && B.length()==0)
//         return true;
//     if(A.compare(B)==0)
//         return true;
//     if(A.length()<=1)
//         return false;
        
//     int n = A.length();
        
//     string key = A;
//     key.push_back(' ');
//     key.append(B);
//     if (mp.find(key)!=mp.end())
//         return mp[key];
    
//     bool flag = false;
    
//     for(int i=1; i<n; i++){
//         int p, q, r, s;
        
//         if(mp.find(A.substr(0, i)+' '+B.substr(n-i, i))!=mp.end())
//             p = mp[A.substr(0, i)+' '+B.substr(n-i, i)];
//         else{
//             p = isScramble(A.substr(0, i), B.substr(n-i, i));
//             mp[A.substr(0, i)+' '+B.substr(n-i, i)] = p;
//         }
        
//         if(mp.find(A.substr(i, n-i)+' '+B.substr(0, n-i))!=mp.end())
//             q = mp[A.substr(i, n-i)+' '+B.substr(0, n-i)];
//         else{
//             q = isScramble(A.substr(i, n-i), B.substr(0, n-i));
//             mp[A.substr(i, n-i)+' '+B.substr(0, n-i)] = q;
//         }
        
//         if(mp.find(A.substr(0, i)+' '+B.substr(0, i))!=mp.end())
//             r = mp[A.substr(0, i)+' '+B.substr(0, i)];
//         else{
//             r = isScramble(A.substr(0, i), B.substr(0, i));
//             mp[A.substr(0, i)+' '+B.substr(0, i)] = r;
//         }
        
//         if(mp.find(A.substr(i, n-i)+' '+B.substr(i, n-i))!=mp.end())
//             s = mp[A.substr(i, n-i)+' '+B.substr(i, n-i)];
//         else{
//             s = isScramble(A.substr(i, n-i), B.substr(i, n-i));
//             mp[A.substr(i, n-i)+' '+B.substr(i, n-i)] = s;
//         }
        
//         // case 1 swapping done
//         bool cond1 = p && q;
        
    
//         // case 2 swapping not done
//         bool cond2 = r && s;
    
//         if(cond1 || cond2){
//             flag = true;
//             break;
//         }
        
//     }
    
//     return mp[key] = flag;
        
    
// }

int main()
{
    string A = "abbbcbaaccacaacc";
    string B = "acaaaccabcabcbcb";

    // string A = "nxnwslefciojqzpnkqfs";
    // string B = "nlwekcsfzjoqxspninfq";


    cout<<isScramble(A, B)<<"\n";
}
