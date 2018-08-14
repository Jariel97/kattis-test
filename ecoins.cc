#include<bits/stdc++.h>
using namespace std;
int MIN(int a,int b)
{return ((a)<(b)?(a):(b));}
 
struct ec
{	int c;
    int tech;
 }coin[50];
int solve(int n, int modu)
{
    int dp[301][301] = {}, tar = pow(modu,2);int i, j;
  for (i = 0; i <= modu; i++)
        for (j = 0; j <= modu; j++)
            dp[i][j] = 999;
 
    dp[0][0] = 0;
 
    for (i = 0; i < n; i++)
    {
        int c = coin[i].c, tech = coin[i].tech;
        for (int x = c; x*x + tech*tech <= tar; x++)
            for (int y = tech; x*x + y*y <= tar; y++)
                dp[x][y] = MIN(dp[x][y], dp[x - c][y - tech] + 1);
    }
 
    int min = 999;
    for (i = 0; i <= modu; i++)
        for (j = 0; j <= modu; j++)
            if (i*i + j*j == tar)
                if (min>dp[i][j])
                    min = dp[i][j];
 
    return min;
}
 
int main()
{
    int test, n, modu, i;;
    cin>>test;
    while (test--)
    {
      
        cin>>n>>modu;
        for (i = 0; i < n; i++)
            cin>>coin[i].c>>coin[i].tech;
 
        int ans = solve(n, modu);
        if (ans > 300)
            cout<<"not possible\n";
        else
            cout<<ans<<"\n";
    }
 
    return 0;
}
