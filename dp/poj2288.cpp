/*
 * poj2288.cpp
 *
 *
 *  Created on: 2013Äê7ÔÂ7ÈÕ
 *      Author: luo
 */


#include <algorithm>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <queue>
#include <map>

using namespace std;

typedef __int64 lld;
const int MAX = 13;
const int MOD = 7000000;
const int INF = 1000000000;
const double PI = acos(-1.0);
const double EPS = 1.0e-16;

int dp[1<<MAX][MAX][MAX];
int cnt[1<<MAX][MAX][MAX];
bool con[MAX][MAX];
int v[MAX];

int main() {
	int n, m;
	int i, j, k;
	int T;

	scanf("%d", &T);
	for(; T > 0; T--){
		scanf("%d%d", &n, &m);
		for(i = 0; i < n; ++i)
			scanf("%d", &v[i]);
		memset(con, false, sizeof(con));
		for(; m > 0; m--){
			scanf("%d%d", &i, &j);
			i--;
			j--;
			if(i == j) continue;
			con[i][j] = con[j][i] = true;
		}

		if(n == 1) {
			printf("%d %d\n", v[0], 1);
			continue;
		}

		int full = 1 << n;
		for( i=0; i < full; ++i){
			for(j = 0; j < n; ++j){
				for(k=0; k <n; ++k){
					dp[i][j][k] = -1;
					cnt[i][j][k] = 0;
				}
			}
		}
		for(j=0; j < n; ++j){
			for(k=0; k <n; ++k){
				if(con[j][k]){
					dp[(1<<j)|(1<<k)][j][k] = v[j] + v[k] + v[j]*v[k];
					cnt[(1<<j)|(1<<k)][j][k] += con[j][k];
				}
			}
		}
		int t;
		int tmp;
		for(i=0; i < full; ++i){
			for( j = 0; j < n; ++j){
				if((1<<j)&i){
					for(k=0; k < n; ++k){
						if(dp[i][j][k] == -1) continue;
						 for(t=0;t<n;t++)
						{
							if(((1<<t)&i)||con[k][t]==false)continue;
							tmp=dp[i][j][k]+v[t]+v[t]*v[k];
							if(con[j][t])tmp+=v[j]*v[k]*v[t];

							if(tmp>dp[i|(1<<t)][k][t])
							{
								dp[i|(1<<t)][k][t]=tmp;
								cnt[i|(1<<t)][k][t]=cnt[i][j][k];
							}
							else if(tmp==dp[i|(1<<t)][k][t])
							{
								cnt[i|(1<<t)][k][t]+=cnt[i][j][k];
							}
						}
					}
				}
			}
		}
		int ans=-1;
		lld sum=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(dp[full-1][i][j]>ans)
				{
					ans=dp[full-1][i][j];
				}
			}
		}

		if(ans==-1)
		{
			puts("0 0");
			continue;
		}

		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(dp[full-1][i][j]==ans)
				{
					sum+=cnt[full-1][i][j];
				}
			}
		}

		printf("%d %I64d\n",ans,sum/2);
	}
	return 0;
}
