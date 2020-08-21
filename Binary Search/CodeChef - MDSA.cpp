#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll n;

ll fun(ll mid,ll a[])
{
    ll sum=0;
    for(ll i=0;i<n;i++)
    {
        sum+=max(a[i]-mid,(ll)0);
    }
    return sum;
}

int main()
{
    ll tc;
    cin>>tc;

    ll th;
    while(tc--)
    {
        cin>>n>>th;
        ll a[n];

        for(ll i=0;i<n;i++)
        {
           cin>>a[i];
        }

        ll lo=0;
        ll hi=1000000000;
        ll mid,index,sum;

        while(lo<=hi)
        {
            mid=lo+(hi-lo)/2;

            ll p=fun(mid,a);
            //cout<<p<<endl;
            if(p>=th)
            {
                index=mid;
                sum=p;
                lo=mid+1;
            }

            else
            {
                hi=mid-1;
            }
        }

        cout<<index<<" "<<sum<<endl;
    }
}
