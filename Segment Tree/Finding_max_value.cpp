#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mx 50001
ll tree[mx*3];
ll arr[mx];

void init(ll node,ll left,ll right)
{
	if(left==right)
	{
		tree[node]=arr[left];
		return;
	}
	ll mid=(left+right)/2;
	ll Lnode=node*2;
	ll Rnode=(node*2)+1;
	init(Lnode,left,mid);
	init(Rnode,mid+1,right);
	tree[node]=max(tree[Lnode],tree[Rnode]);

}

ll query(ll node,ll left,ll right,ll Lrange,ll Rrange)
{
	if(Lrange>right||Rrange<left)
		return INT_MIN;
	if(left>=Lrange&&right<=Rrange)
		return tree[node];

	ll mid=(left+right)/2;
	ll Lnode=node*2;
	ll Rnode=(node*2)+1;
	ll p1=query(Lnode,left,mid,Lrange,Rrange);
	ll p2=query(Rnode,mid+1,right,Lrange,Rrange);
	return max(p1,p2);

}

int main()
{
	ll n;
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		cin>>arr[i];
	}

	init(1,1,n);
    ll m;
    cin>>m;
    while(m--)
    {
        ll x,y;
        cin>>x>>y;
        cout<<query(1,1,n,x,y)<<endl;
    }


	return 0;
}

/*
input:
8
2 1 4 3 2 1 5 1
4
1 5
7 8
1 8
3 4

output:
4
5
5
4
*/
