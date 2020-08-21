#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll a[10002];

int main()
{
    ll n,m;
    ll d=1;
    while(1)
    {
        cin>>n>>m;
        if(n==0&&m==0) break;

        for(ll i=1;i<=n;i++)
        {
            cin>>a[i];
            //cout<<i<<" "<<n<<endl;
        }

        sort(a+1,a+n+1);
        ll b;
        cout<<"CASE# "<<d<<":"<<endl;
        for(ll i=1;i<=m;i++)
        {
            cin>>b;
            ll p=lower_bound(a+1,a+n+1,b)-a;

            if(a[p]==b)
            {
                cout<<b<<" found at "<<p<<endl;
            }

            else
                cout<<b<<" not found"<<endl;
        }

        d++;
    }
}

/*
input:
5 2
1
3
3
3
1
2
3
0 0
output:
CASE# 1:
2 not found
3 found at 3
*/
