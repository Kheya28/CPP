#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll a[10002];
int main()
{
    ll n;
    while(scanf("%lld",&n)!=EOF)
    {
        for(ll i=1;i<=n;i++)
        {
            cin>>a[i];
        }

        ll money;
        cin>>money;
        sort(a+1,a+n+1);

        ll c,d;
        for(ll i=1;i<=n;i++)
        {
            if(a[i]>=money) break;
            ll p=money-a[i];

            ll q=upper_bound(a+i+2,a+n+1,p)-a;
            if(a[q-1]==p)
            {

                c=i;
                d=q-1;
                //cout<<c<<" "<<d<<endl;
            }
        }

        ll c1=min(a[c],a[d]);
        ll d1=max(a[c],a[d]);
        cout<<"Peter should buy books whose prices are "<<c1<<" and "<<d1<<"."<<endl;
        cout<<endl;
    }
}

/*
input:
1
40 40
80
output:
Peter should buy books whose prices are 40 and 40.

*/
