void BFS(ll source)
{
	ll i,j;
	queue<ll>q;
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
}
