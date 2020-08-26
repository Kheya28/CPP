#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vec2 vector<vector<ll> >
#define vec1 vector<ll>
ll maxNode=101;
ll total=0;
ll c[101][101];
ll mark[101];
ll ans;

ll s;

void bfs(vec2 &g)
{
        ll tot1=0;
		vector<ll>mark(maxNode);
		queue<ll>q;
		q.push(s);
		mark[s]=1;

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
					//cout<<"p"<<endl;
					tot1+=c[p][x];
				}
			}

		}
		//cout<<tot1<<endl;
		ans=min(tot1,total-tot1);

}


int main()
{
    ll t;
    cin>>t;

    for(ll tc=1;tc<=t;tc++)
    {
        total=0;
        ll n;
        cin>>n;

        vec2 g(101);

        for(ll i=0;i<=100;i++)
        {
            for(ll j=0;j<=100;j++)
            {
                c[i][j]=0;
            }
        }

        for(ll i=1;i<=n;i++)
        {
            ll x,y,z;
			cin>>x>>y>>z;
			total+=z;
			g[x].push_back(y);
			if(i==1)
			  s=y;
			else
			  g[y].push_back(x);
			c[y][x]=z;


        }

        //cout<<total<<endl;
        bfs(g);

        //cout<<ans<<endl;
        cout<<"Case "<<tc<<": "<<ans<<endl;
    }
}

/*
input:
2

3
1 3 1
1 2 1
3 2 1

3
1 3 1
1 2 5
3 2 1
output:
Case 1: 1
Case 2: 2
*/
