#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void parlor(pair<ll,ll>p[],ll n,ll m)
{
       ll a,b;
        for(ll i=0;i<m-1;i++)
        {

            ll flag=0;
            ll low=i+1;
            ll hi=m-1;
            ll item=n-p[i].first,index,mid;
            while(low<=hi)
            {
                mid=low+(hi-low)/2;
                if(p[mid].first==item)
                {
                    hi=mid-1;
                    index=mid;
                    flag=1;
                }
                else if(p[mid].first<item)
                {
                    low=mid+1;
                }
                else if(p[mid].first>item)
                {
                    hi=mid-1;
                }
            }

            //cout<<index<<endl;
            if(flag==1)
            {
                a=p[i].second;
                b=p[index].second;
                break;
            }
        }
        if(a<b)
           cout<<a+1<<" "<<b+1<<endl;
        else
           cout<<b+1<<" "<<a+1<<endl;

}

int main()
{
    ll t;
    cin>>t;

    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        pair<ll,ll>p[m];

        for(ll i=0;i<m;i++)
        {
            cin>>p[i].first;
            p[i].second=i;
        }

        sort(p,p+m);


        parlor(p,n,m);


    }
}
