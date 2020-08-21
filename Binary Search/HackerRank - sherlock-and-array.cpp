#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll a[100002];
int main()
{
	ll n;
	ll t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		ll d=0;
		for(ll i=1;i<=n;i++)
		{
			cin>>a[i];
			if(a[i]!=0) d++;
		}
		if(d==1)
		{
		    cout<<"YES"<<endl;
		    continue;
		}

		if(n==1)
		{
			cout<<"YES"<<endl;
			continue;
		}

		ll p=a[1],i=1;
		ll q=a[n],j=n;
		ll b=0;

		while(i<j-1)
		{
			if(p<q)
			{
				i++;
				if(i<j-1)
				p=p+a[i];
		    }
		    else if(q<p)
		    {
		    	j--;
		    	if(i<j-1)
		    	q=q+a[j];
		    }

		    else
		    {
		    	if(j-i==2)
		    	{
    				break;
    				b=1;
    			}
		    	i++;
		    	j--;
		    	if(i<j-1)
		    	{
    				p=p+a[i];
    				q=q+a[j];
    			}
		    }
		    if(b==1) break;
		}
	  //cout<<i<<" "<<j<<endl;
	    if((p-q)==0)
	    {
	  	 cout<<"YES"<<endl;
	    }
	    else
	    cout<<"NO"<<endl;
	  }
}

/*
 2
 3
 1 2 3
 4
 1 2 3 3
*/
