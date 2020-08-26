#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vec1 vector<ll>
#define vec2 vector<vector<ll> >
ll mark[10001];

void bfs(vec2 &g,ll src,ll &coun)
{
    coun=0;
    memset(mark,0,sizeof(mark));

    mark[src]=1;
    queue<ll>q;
    q.push(src);

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
            }
        }
    }

    for(ll i=1;i<=10000;i++)
    {
        if(mark[i]==1) coun++;
    }



}

int main()
{
    ll t;
    cin>>t;


    for(ll tc=1;tc<=t;tc++)
    {
        ll k,n,m;
        cin>>k>>n>>m;

        vec2 g(10001);
        vec1 node(101);
        for(ll i=0;i<k;i++)
        {
            cin>>node[i];
        }

        ll u,v;
        for(ll i=0;i<m;i++)
        {
            cin>>u>>v;
            g[u].push_back(v);
        }

        ll coun,mini=1e9;
        for(ll i=0;i<k;i++)
        {
            bfs(g,node[i],coun);
            mini=min(mini,coun);
        }

        cout<<"Case "<<tc<<": "<<mini<<endl;

    }
}

/*
input:
1
2 4 4
2
3
1 2
1 4
2 3
3 4

output:
Case 1: 2
*/
