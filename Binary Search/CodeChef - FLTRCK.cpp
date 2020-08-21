#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll n,m,q;

    cin>>n>>q;
    ll a[n];

    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }

    sort(a,a+n);

    for(ll i=1;i<n;i++)
    {
        a[i]=a[i-1]+a[i];
    }

    while(q--)
    {
        cin>>m;
        ll p=upper_bound(a,a+n,m)-a;
        cout<<p<<endl;
    }
}

/*
input:
10 2
1 1 8 2 5 1 6 6 1 2
3 8
output:
3 6
*/
