//泛化物品:对于每件物品分配x费用可以获得h(x)的价值
#include<bits/stdc++.h>
#define ll long long
#define myfor(c,a,b) for(int c=a;a<=b?c<=b:c>=b;a<=b?++c:--c)
#define sfor(a,b,c) for(int a=b;a<=c;++a)
#define nfor(a,b,c) for(int a=b;a>=c;--a)

using namespace std;
const ll maxn=1005;

int n,m;
ll a[105][105];

int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n>>m&&n&&m){
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                cin>>a[i][j];
            }
        }
        //寻找每一次选择的每个花费的最大价值。
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                a[i][j]=max(a[i][j],a[i][j-1]);
            }
        }
        //第n次选择的最优解已经在上面循环中求出
        for(int i=n-1;i>=1;--i){
            //逆序原因同一维数组的01背包
            for(int j=m;j>=1;--j){
                //对第i次选择分配k小时则对i+1次选择分配了j-k小时
                for(int k=0;k<=j-1;++k){
                    a[i][j]=max(a[i][j],a[i][k]+a[i+1][j-k]);
                }
            }
        }
        cout<<a[1][m]<<endl;
    }

    return 0;
}
