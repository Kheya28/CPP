#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll dx[]={1,-1,0,0};
ll dy[]={0,0,1,-1};
char g[21][21];
ll mark[21][21];
ll level[21][21];
ll r,c;

bool valid(ll xx,ll yy)
{
    if(xx>=0&&xx<r&&yy>=0&&yy<c&&mark[xx][yy]==0&&g[xx][yy]!='#'&&g[xx][yy]!='m')
    {
        return true;
    }

    return false;
}

void bfs(ll r1,ll c1)
{
    for(ll i=0;i<r;i++)
    {
        for(ll j=0;j<c;j++)
        {
            level[i][j]=0;
            mark[i][j]=0;
        }
    }

    mark[r1][c1]=1;
    level[r1][c1]=0;
    queue<pair<ll,ll> >q;
    q.push(make_pair(r1,c1));

    while(q.empty()==0)
    {
        ll x=q.front().first;
        ll y=q.front().second;

        q.pop();
        for(ll i=0;i<4;i++)
        {
            ll xx=x+dx[i];
            ll yy=y+dy[i];

            if(valid(xx,yy))
            {
                mark[xx][yy]=1;
                level[xx][yy]=level[x][y]+1;
                q.push(make_pair(xx,yy));
            }
        }
    }


}

int main()
{
    ll t;
    cin>>t;


    for(ll tc=1;tc<=t;tc++)
    {

        cin>>r>>c;

        ll a1,a2,b1,b2,c1,c2,h1,h2;
        for(ll i=0;i<r;i++)
        {
            for(ll j=0;j<c;j++)
            {
                cin>>g[i][j];
                if(g[i][j]=='a')
                {
                    a1=i;
                    a2=j;
                }

                if(g[i][j]=='b')
                {
                    b1=i;
                    b2=j;
                }

                if(g[i][j]=='c')
                {
                    c1=i;
                    c2=j;
                }

                if(g[i][j]=='h')
                {
                    h1=i;
                    h2=j;
                }
            }
        }

        bfs(a1,a2);
        ll a=level[h1][h2];

        bfs(b1,b2);
        ll b=level[h1][h2];

        bfs(c1,c2);
        ll c=level[h1][h2];

        ll maxi=max(a,max(b,c));

        cout<<"Case "<<tc<<": "<<maxi<<endl;
    }
}

/*
input:
1
6 8
########
#...c..#
#......#
#.a.h.b#
#......#
########

output:
Case 1: 2
*/
