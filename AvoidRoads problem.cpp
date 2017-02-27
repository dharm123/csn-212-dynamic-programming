#include<iostream>
#include <bits/stdc++.h>

#define in(x) scanf("%d",&x)

#define pii pair<int,int>
#define F first

#define m_p make_pair

using namespace std;
map<pair<pii,pii>,bool>mp;
int main()
{
    ios::sync_with_stdio(0);
    cout<<"enter the height and width\n";
    int x,y;
    cin>>x>>y;
    cout<<"enter the number of bad paths\n";
    int n;
    cin>>n;
    cout<<"enter the bad paths \n";
    int a,b,c,d;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b>>c>>d;
        if(a+b==c+d+1)
            mp[m_p(m_p(a,b),m_p(c,d))]=1;
        else
            mp[m_p(m_p(c,d),m_p(a,b))]=1;
    }
    int dp[x+1][y+1];
    for(int i=0;i<=x;i++) for(int j=0;j<=y;j++) dp[i][j]=0;
    dp[0][0]=1;
    for(int i=0;i<=x;i++)
    {
        for(int j=0;j<=y;j++)
        {
            pair<pii,pii> ver=m_p(m_p(i,j),m_p(i,j-1));
            if(j>=1&&!mp[ver])
                dp[i][j]+=dp[i][j-1];
            pair<pii,pii> hor=m_p(m_p(i,j),m_p(i-1,j));
            if(i>=1&&!mp[hor])
                dp[i][j]+=dp[i-1][j];
        }
    }
    cout<<"ans\n";
    cout<<dp[x][y]<<endl;

    return 0;
}
