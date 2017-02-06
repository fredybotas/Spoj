#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

long long DP[300][300];
int coins[300];
int M;

long long rec(int N, int C){
    if(N == 0)
        return 1;
    if(N < 0)
        return 0;
    if(C < 0)
        return 0;
    if(DP[N][C] != -1)
        return DP[N][C];
    
    return DP[N][C] = rec(N - coins[C], C) + rec(N, C - 1);
}
int main() {
    int N;
    scanf("%d %d ", &N, &M);
    int i;
    memset(DP, -1, sizeof(DP));
    for(i = 0; i < M; i++){
        scanf("%d ", &coins[i]);    
    }
    long long  count = rec(N, M - 1);
    printf("%lld\n", count);
    return 0;
}
