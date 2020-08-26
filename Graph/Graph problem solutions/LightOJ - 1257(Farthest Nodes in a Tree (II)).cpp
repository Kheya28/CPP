#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define vec2 vector<ll>
#define   zero(a)  memset(a,0,sizeof a)

ll n;
vec2 g[30002],cost[30002];
ll mark[30002];
ll dist1[30002],dist2[30002];

ll BFS1(ll source)
{
    zero(mark);
	dist1[source]=0;
	queue<ll>q;
	q.push(source);
	mark[source]=1;

	while(q.empty()==0)
	{
		ll p=q.front();
		q.pop();

		for(ll i=0;i<g[p].size();i++)
		{
			ll x=g[p][i];
			if(mark[x]==0)
			{
				q.push(x);
				mark[x]=1;
				dist1[x]=dist1[p]+cost[p][i];
			}
		}
	}


	ll index=0,maxi=INT_MIN;
    for(ll i=0;i<n;i++)
    {
        if(dist1[i]>maxi)
        {
            maxi=dist1[i];
            index=i;
        }
    }


    return index;
}

void BFS2(ll source)
{
    zero(mark);
	dist2[source]=0;
	queue<ll>q;
	q.push(source);
	mark[source]=1;

	while(q.empty()==0)
	{
		ll p=q.front();
		q.pop();

		for(ll i=0;i<g[p].size();i++)
		{
			ll x=g[p][i];
			if(mark[x]==0)
			{
				q.push(x);
				mark[x]=1;
				dist2[x]=dist2[p]+cost[p][i];
			}
		}
	}

}

int main()
{
    ll t;
    scanf("%lld",&t);

    ll u,v,c;
    for(ll tc=1;tc<=t;tc++)
    {

        scanf("%lld",&n);

        for(ll i=1;i<n;i++)
        {

            //cin>>u>>v>>c;
            scanf("%lld %lld %lld",&u,&v,&c);

            g[u].pb(v);
            g[v].pb(u);

            cost[u].pb(c);
            cost[v].pb(c);
        }

        ll p = BFS1(0);
        ll q = BFS1(p);
        BFS2(q);

        vector<ll>v;
        cout<<"Case "<<tc<<":"<<endl;
        for(ll i=0;i<n;i++)
        {
            ll maxi=max(dist1[i],dist2[i]);
            printf("%lld\n",maxi);
        }

        for( ll i = 0 ; i < n ; i ++ )
        {
            g[ i ].clear() ;
            cost[ i ].clear() ;

        }
        //v.clear();

    }

}
/*
input:
1

4
0 1 20
1 2 30
2 3 50

output:
Case 1:
100
80
50
100
*/

