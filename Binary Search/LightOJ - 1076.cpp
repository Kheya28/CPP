#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll n,m;
ll a[1002];

bool valid(ll mid)
{
    ll cnt=1;
    ll p=0;
    for(ll i=1;i<=n;i++)
    {
        if(p+a[i]<=mid)
        {
            p=p+a[i];
        }
        else
        {
            p=a[i];
            cnt++;
        }

    }

    if(cnt>m)
        return false;
    else
        return true;
}


int main()
{
    ll t;
    cin>>t;


    for(ll tc=1;tc<=t;tc++)
    {

        cin>>n>>m;

        a[0]=0;
        ll sum=0,maxi=0;
        for(ll i=1;i<=n;i++)
        {
           cin>>a[i];
           sum+=a[i];
           if(a[i]>maxi)
           {
              maxi=a[i];
           }
        }

        ll low=maxi;
        ll hi=sum;

        ll index;
        while(low<=hi)
        {
            ll mid=low+(hi-low)/2;
            if(valid(mid))
            {
                hi=mid-1;
                index=mid;
            }
            else
            {
                low=mid+1;
            }
        }
        cout<<"Case "<<tc<<": "<<index<<endl;


    }
}

/*
Input
2
5 3
1 2 3 4 5
3 2
4 78 9
Output
Case 1: 6
Case 2: 82
*/
