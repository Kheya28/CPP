#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll i,j;
ll maxnode=20001;
vector<vector<ll> >graph(maxnode);
vector<ll>mark(maxnode),level(maxnode),parent(maxnode);
queue<ll>q;

void addEdge(ll x,ll y)
{
	graph[x].push_back(y);

}

void BFS(ll source,ll m)
{

	q.push(source);
	level[source]=0;
	mark[source]=1;
	parent[source]=-1;

	while(q.empty()==0)
	{
		ll p=q.front();


		for(i=0;i<graph[p].size();i++)
		{
			ll x=graph[p][i];
			if(mark[x]==0)
			{
				q.push(x);
				mark[x]=1;
				level[x]=level[p]+1;
				parent[x]=p;
			}
		}
		q.pop();
	}
	cout<<level[m]<<endl;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	for(i=1;i<=10000;i++)
	{
		addEdge(i,i*2);
	}

	for(i=1;i<=10000;i++)
	{
		addEdge(i,i-1);
	}
	ll n,m;
	cin>>n>>m;
	BFS(n,m);
}

/*
input: 4 6
output: 2
*/

