#include<bits/stdc++.h>

using namespace std;

int minimumNumberOfCoin(int coin[], int n, int sum){
    int t[n+1][sum+1];
    
    // Initialization
    for(int i=0; i<n+1; i++){
        for(int j=0; j<sum+1; j++){
            if(i==0)
                t[i][j] = INT_MAX-1;
            if(j==0)
                t[i][j] = 0;
        }
    }

    for (int i=1; i<n+1; i++){
        for (int j=1; j<sum+1; j++){
            if (j%coin[0]==0)
                t[i][j] = j/coin[0];
            else    
                t[i][j] = INT_MAX-1;
        }
    }

    return t[n][sum];
}

int main()
{
    int coin[] = {1,2,3};
    int sum = 5;
    int n = sizeof(coin)/sizeof(coin[0]);

    cout<<"Minimum number of coin required be \t"<< minimumNumberOfCoin(coin, n, sum)<<"\n";
}