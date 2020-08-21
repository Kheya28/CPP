#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
	ll n,i,j;
	ll a[10000];
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	ll low=0;
	ll hi=n-1;
	ll item,index;
	cin>>item;
	while(low<=hi)
	{
		ll mid=low+(hi-low)/2;
		if(a[mid]==item)
		{
			low=mid+1;
			index=mid;
		}
		else if(a[mid]<item)
		{
			low=mid+1;
		}
		else if(a[mid]>item)
		{
			hi=mid-1;
		}
	}
	
	cout<<index<<endl;
}
