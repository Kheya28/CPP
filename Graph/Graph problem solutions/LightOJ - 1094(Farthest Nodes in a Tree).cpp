#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vec1 vector<ll>
#define vec2 vector<vector<ll> >
ll maxi,pos;

void addEdge(ll a,ll b,vec2 &g)
{
    g[a].push_back(b);
    g[b].push_back(a);
}

void addCost(ll a,ll b,ll cost,vec2 &c)
{
   c[a].push_back(cost);
   c[b].push_back(cost);
}

void bfs(vec2 &g,vec1 &dis,ll src,vec2 &c)
{
    vec1 mark(30001);
    mark[src]=1;
    dis[src]=0;
    queue<ll>q;
    q.push(src);

    maxi=0,pos=0;
    while(q.empty()==0)
    {
        ll p=q.front();
        q.pop();
        for(ll i=0;i<g[p].size();i++)
        {
            ll x=g[p][i];

            if(mark[x]==0)
            {
                mark[x]=1;
                q.push(x);
                dis[x]=dis[p]+c[p][i];
                if(dis[x]>maxi)
                {
                    maxi=dis[x];
                    pos=x;
                }
            }
        }
    }
}

int main()
{
    ll tc;
    cin>>tc;

    for(ll i=1;i<=tc;i++)
    {
        ll n;
        cin>>n;

        vec2 g(30001);
        vec2 c(30001);

        ll e=n-1;
        for(ll j=1;j<=e;j++)
        {
            ll a,b,cost;
            cin>>a>>b>>cost;

            addEdge(a,b,g);
            addCost(a,b,cost,c);
        }

        vec1 dis(30001);
        bfs(g,dis,0,c);

        ll maxi1=maxi;
        ll pos1=pos;

        bfs(g,dis,pos1,c);

        ll maxi2=maxi;
        ll pos2=pos;

        ll ans=max(maxi1,maxi2);
        cout<<"Case "<<i<<": "<<ans<<endl;
    }
}
/*
input:
2

4

0 1 20

1 2 30

2 3 50

5

0 2 20

2 1 10

0 3 29

0 4 50

output:
Case 1: 100
Case 2: 80
*/
