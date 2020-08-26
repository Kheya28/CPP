#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll S,T;
vector<vector<ll> >g(1001);
vector<ll> primes(200);
ll level[1001],mark[1001];

void sieve()
{
    vector<bool> isPrime(1001,true);

    primes[0]=2;
    ll pos=1;

    for(ll i=3;i<=1000;i+=2)
    {
        if(isPrime[i])
        {
            for(ll j=i*i;j<=1000;j+=i)
            {
                isPrime[j]=false;
            }

            primes[pos]=i;
            ++pos;
        }
    }
    //cout<<pos<<endl;

}

void factors()
{
    for(ll i=1;i<=1000;i++)
    {
        ll num=i;
        ll p=0;
        for(ll pos=0;primes[pos]*primes[pos]<=num&&pos<200;++pos)
        {
            ll flag=0;
            while(num%primes[pos]==0)
            {
                flag=1;
                p=1;
                num/=primes[pos];
            }
            if(flag) g[i].push_back(primes[pos]);
        }

        if(num>1) g[i].push_back(num);
        if(p==0) g[i].clear();
    }
}


ll bfs()
{
    //memset(mark,0,sizeof(mark));
    memset(level,-1,sizeof(level));

    level[S]=0;
    queue<ll>q;
    q.push(S);

    while(q.empty()==0)
    {
        ll p=q.front();
        q.pop();

        for(ll i=0;i<g[p].size();i++)
        {
            ll x=p+g[p][i];
            if(x<=T&&level[x]==-1)
            {
                //mark[x]=1;
                level[x]=level[p]+1;
                q.push(x);
                if(x==T)
                {
                    return level[T];
                }
            }

        }
    }

    return level[T];


}

int main()
{
    ll t;
    cin>>t;

    sieve();
    factors();
    for(ll tc=1;tc<=t;tc++)
    {
        cin>>S>>T;

        cout<<"Case "<<tc<<": "<<bfs()<<endl;
    }
}

/*
input:
2
6 12
6 13
output:
Case 1: 2
Case 2: -1
*/
