#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mp make_pair

ll n;
ll level[100][100];
ll mark[100][100];

bool valid(ll xx,ll yy)
{
    if(xx>=0&&xx<n&&yy>=0&&yy<n&&mark[xx][yy]==0)
    {
        return true;
    }

    return false;
}

void BFS(ll x,ll y)
{
    queue<pair<ll,ll> >q;
    ll fx[]={x,x,-x,-x,y,y,-y,-y};
    ll fy[]={y,-y,y,-y,x,-x,x,-x};

    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<n;j++)
        {
            level[i][j]=0;
            mark[i][j]=0;
        }
    }

	q.push(mp(0,0));

	level[0][0]=0;
	mark[0][0]=1;

	while(q.empty()==0)
	{
		ll c=q.front().first;
		ll d=q.front().second;

		q.pop();

		for(ll i=0;i<8;i++)
		{
            ll xx=c+fx[i];
            ll yy=d+fy[i];

            if(valid(xx,yy))
            {
                mark[xx][yy]=1;
                level[xx][yy]=level[c][d]+1;
                q.push(make_pair(xx,yy));

            }
		}
	}
	if(level[n-1][n-1]==0)
        cout<<"-1"<<" ";
    else
        cout<<level[n-1][n-1]<<" ";
}

int main()
{

    cin>>n;

    for(ll i=1;i<n;i++)
    {
       for(ll j=1;j<n;j++)
       {
           BFS(i ,j);
       }
       cout<<endl;
    }
}

/*
input:
5
output:
4 4 2 8
4 2 4 4
2 4 -1 -1
8 4 -1 1
*/
