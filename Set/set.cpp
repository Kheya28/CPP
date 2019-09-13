#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<ll,ll>
#define pb push_back

vector<pii>v;

int main()
{
    set<ll>s;
    ll n,a;
    cin>>n;

    for(ll i=0;i<n;i++)
    {
        cin>>a;
        s.insert(a);
        v.pb(pii(a,i));
    }

    sort(v.begin(),v.end());

    vector<ll>val,index,res;
    for(ll i=0;i<v.size();i++)
    {
        val.pb(v[i].first);
        index.pb(v[i].second);
    }

    set<ll>::iterator it;
    for(it=s.begin();it!=s.end();it++)
    {
        ll p=*it;
        ll loc=lower_bound(val.begin(),val.end(),p)-val.begin();
        res.pb(index[loc]);
    }

    if(res.size()<3)
    {
        cout<<"-1 -1 -1"<<endl;
        return 0;
    }

    for(ll i=0;i<3;i++)
    {
        cout<<res[i]+1<<" ";
    }
}

problem: https://codeforces.com/contest/1211/problem/A
