#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll i,j;
ll mxnode=20001;
vector<vector<ll> >g(mxnode);
vector<ll>level(mxnode);
vector<ll>mark(mxnode);
vector<ll>parent(mxnode);
queue<ll>q;

void BFS(ll source,ll des)
{
	ll i,j;
	q.push(source);
	level[source]=0;
	mark[source]=1;
	parent[source]=-1;
	
	while(q.empty()==0)
	{
		ll p=q.front();
		q.pop();
		
		for(i=0;i<g[p].size();i++)
		{
			ll x=g[p][i];
			if(mark[x]==0)
			{
				q.push(x);
				mark[x]=1;
				level[x]=level[p]+1;
				parent[x]=p;
			}
		}
	}
	while(des>1)
	{
		cout<<des<<"-> "<<parent[des]<<endl;
		des=parent[des];
	}
	
}

int main()
{
	ll n,p,x,y,a;
	cin>>n;
	
	for(i=1;i<=n;i++)
	{
		cin>>x>>y;
	
		
		g[x].push_back(y);
	
		
	}
	cin>>a;
	BFS(1,a);
	
}
