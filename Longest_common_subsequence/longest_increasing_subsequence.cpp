#include<bits/stdc++.h>

using namespace std;

int lis(const vector<int> &v) {

    // Base case
    if (v.size() == 0) // boundary case
        return 0;
 
    vector<int> tail(v.size(), 0);
    int length = 1; // always points empty slot in tail
 
    tail[0] = v[0];
 
    for (int i = 1; i < v.size(); i++) {
 
        // Do binary search for the element in
        // the range from begin to begin + length
        auto b = tail.begin(), e = tail.begin() + length;
        auto it = lower_bound(b, e, v[i]);
 
        // If not present change the tail element to v[i]
        if (it == tail.begin() + length)
            tail[length++] = v[i];
        else
            *it = v[i];
    }
 
    return length;

}


int main()
{
    vector<int> A = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
    
    cout<<"Longest Increasing subsequnce:\t"<<lis(A)<<"\n";
    
}