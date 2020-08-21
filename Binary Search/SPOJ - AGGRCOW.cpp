#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll c,n;


ll F(ll x,ll a[])
{
	ll cowplaced=1,lastpos=a[0];
	for(ll i=1;i<n;i++)
	{
		if(a[i]-lastpos>=x)
		{
			cowplaced++;
			lastpos=a[i];
		}
		if(cowplaced==c)
            return true;

	}
	return false;
}

int main()
{
	ll t;

	cin>>t;

	while(t--)
	{
		cin>>n>>c;
		ll a[n];
		for(ll i=0;i<n;i++)
		{
			cin>>a[i];
		}
		sort(a,a+n);

		ll ans;
		ll beg=0,end=a[n-1],mid;
		while(beg<=end)
		{
			mid=(beg+end)/2;
			if(F(mid,a))
            {
                beg=mid+1;
                ans=mid;
            }
			else end=mid-1;

		}
		cout<<ans<<endl;
		//return beg;
	}
	return 0;

}

/*
1
5 3
1
2
8
4
9
output:
3
*/
