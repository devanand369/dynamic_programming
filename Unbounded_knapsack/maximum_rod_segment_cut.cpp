// TO-DO
#include<bits/stdc++.h>

using namespace std;

// Recursive Implementation
int maximuxRodSegmentCut(int L, int x, int y, int z){
    // TO-DO
    vector<int> cut;
    // Base Condition
    vector<int> segment;
    if(L==0)
        segment.push_back(cut.size());
    if(L>=x){
        cut.push_back(x);
        maximuxRodSegmentCut(L-x, x, y, z);
    }
    if(L>=y){
        cut.push_back(y);
        maximuxRodSegmentCut(L-y, x, y, z);
    }
    if(L>=x){
        cut.push_back(z);
        maximuxRodSegmentCut(L-z, x, y, z);
    }

    int maxm = INT_MIN;
    for(int i=0; i<segment.size(); i++)
        maxm = max(maxm, segment[i]);
    
    return maxm;

}

int main()
{
    int x=2;
    int y=1;
    int z=1;
    int L = 4;
    cout<<"Maximum number of segments be cut \t"<<maximuxRodSegmentCut(L,x,y,z)<<"\n";
}