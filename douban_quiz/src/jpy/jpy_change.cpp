/*
 * jpy.cpp
 *
 *  Created on: 2013年7月9日
 *      Author: luo
 */
#include <iostream>
using namespace std;
int coin[]={1,5,10,50,100,500,1000,2000,5000};//第一个是1就行 后面顺序任意 否则 需要小改f(int,int)
int ans[10000][9]={0};
bool vis[1000][9]={0};
int f(int i,int j)
{
    if(j==0)return 1;
    if(vis[i][j]==true)return ans[i][j];
    int k;
    for(k=0;k*coin[j]<=i;k++)
        ans[i][j]+=f(i-k*coin[j],j-1);
    vis[i][j]=true;
    return ans[i][j];
}
int main()
{
    cout<<f(1000,8)<<endl;
    return 0;
}

