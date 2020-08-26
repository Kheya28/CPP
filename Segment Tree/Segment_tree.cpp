#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mx 100001
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
	tree[node]=tree[Lnode]+tree[Rnode];

}

ll query(ll node,ll left,ll right,ll Lrange,ll Rrange)
{
	if(Lrange>right||Rrange<left)
		return 0;
	if(left>=Lrange&&right<=Rrange)
		return tree[node];

	ll mid=(left+right)/2;
	ll Lnode=node*2;
	ll Rnode=(node*2)+1;
	ll p1=query(Lnode,left,mid,Lrange,Rrange);
	ll p2=query(Rnode,mid+1,right,Lrange,Rrange);
	return p1+p2;

}

void update(ll node,ll left,ll right,ll pos,ll newvalue)
{
	if(pos<left||pos>right)
		return;
	if(left==right&&left==pos)
	{
		tree[node]=newvalue;
		return;
	}
	ll mid=(left+right)/2;
	ll Lnode=node*2;
	ll Rnode=(node*2)+1;
	update(Lnode,left,mid,pos,newvalue);
	update(Rnode,mid+1,right,pos,newvalue);
	tree[node]=tree[Lnode]+tree[Rnode];

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

	update(1,1,n,2,0);
	cout<<query(1,1,n,1,3)<<endl;
	update(1,1,n,2,2);
	cout<<query(1,1,n,2,2)<<endl;

	for(ll i=1;i<=n;i++)
	{
		cout<<tree[i]<<" ";
	}

	return 0;
}

/*
input:
8
2 1 4 3 2 1 5 1

output:
6
2
20 11 9 4 7 3 6 2
*/
