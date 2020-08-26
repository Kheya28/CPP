#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vec2 vector<vector<ll> >
#define vec1 vector<ll>
vec1 level(101);
ll mark[101];

void bfs(vec2 &g,ll src)
{

    memset(mark,0,sizeof(mark));
    for(ll i=0;i<=100;i++)
    {
        level[i]=0;
    }
    mark[src]=1;
    level[src]=0;
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
                level[x]=level[p]+1;
            }
        }
    }

}

int main()
{

    ll tc;
    cin>>tc;

    for(ll t=1;t<=tc;t++)
    {

        ll n,e;
        cin>>n>>e;

        vec2 g(101);
        ll u,v;
        for(ll i=0;i<e;i++)
        {
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        ll st,des;
        cin>>st>>des;
        vec1 src_level(101),des_level(101),sum_level(101);

        bfs(g,st);
        src_level=level;

        bfs(g,des);
        des_level=level;

        for(ll i=0;i<=100;i++)
        {
            sum_level[i]=src_level[i]+des_level[i];
        }

        sort(sum_level.begin(),sum_level.end());

        cout<<"Case "<<t<<": "<<sum_level.back()<<endl;


    }
}

/*
input:
2

4
3
0 1
2 1
1 3
0 3

2
1
0 1
1 0

output:
Case 1: 4
Case 2: 1
*/
