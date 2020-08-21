
void dfs(ll src)
{
	mark[src]=1;
	for(i=0;i<g[src].size();i++)
	{
		ll x=g[src][i];
		if(mark[x]==0)
		{
			dfs(x);
		}
	}
}
