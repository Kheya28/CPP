#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll level[20001];

ll BFS(vector<vector<ll> >&g,vector<ll>&mark)
{
    ll tot=0;
    for(ll i=1;i<=20000;i++)
    {
        if(mark[i]==0)
        {
            ll pos=i;
            mark[pos]=1;
            level[pos]=0;
            queue<ll> q;
            q.push(pos);
            ll even=1,odd=0;
            while(q.empty()==0)
            {
                ll p=q.front();
                q.pop();

                for(ll i=0;i<g[p].size();i++)
                {
                    ll x=g[p][i];

                    if(mark[x]==0)
                    {
                        //cout<<x<<endl;
                        mark[x]=1;
                        level[x]=level[p]+1;
                        q.push(x);
                        if(level[x]%2==0)
                        {
                            even++;
                            //cout<<even<<endl;
                        }
                        else
                        {
                            odd++;
                            //cout<<odd<<endl;
                        }

                    }
                }
            }

            tot+= max(even,odd);
        }

    }

    return tot;

}

int main()
{
    ll tc;
    cin>>tc;

    for(ll t=1;t<=tc;t++)
    {
        ll n;
        cin>>n;

        vector<ll>mark(20001);
        for(ll i=1;i<=20000;i++)
        {
            mark[i]=-1;
        }
        memset(level,0,sizeof(level));

        vector<vector<ll> >g(20001);
        for(ll i=1;i<=n;i++)
        {
            ll a,b;
            cin>>a>>b;
            g[a].push_back(b);
            g[b].push_back(a);
            mark[a]=0;
            mark[b]=0;
        }

        ll p=BFS(g,mark);

        cout<<"Case "<<t<<": "<<p<<endl;
    }
}
/*
input:
2

2

1 2

2 3

3

1 2

2 3

4 2
output:
Case 1: 2
Case 2: 3
*/
