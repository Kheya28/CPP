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

ll BFS(ll source)
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

	sort(level.begin(),level.end());
	return level.back()+1;
}

int main()
{
	ll n,p;
	cin>>n;
	vector<ll>root;
	for(i=1;i<=n;i++)
	{
		cin>>p;
		if(p==-1) root.push_back(i);
		else
		{
			g[i].push_back(p);
			g[p].push_back(i);
		}
	}

	ll mx=0;
	for(i=0;i<root.size();i++)
	{
		mx=max(mx,BFS(root[i]));
	}

	cout<<mx<<endl;
}

/*
input:
5
-1
1
2
1
-1
output: 3
*/
