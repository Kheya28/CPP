#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll dx[]={1,-1,0,0};
ll dy[]={0,0,1,-1};
char g[12][12];
ll mark[12][12];
ll level[12][12];

ll s1,s2;
ll d=0,n;
string s="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char ch;

bool valid(ll xx,ll yy)
{
    if(xx>=0 && xx<n && yy>=0 && yy<n && mark[xx][yy]==0 && (g[xx][yy]==ch||g[xx][yy]=='.'))
    {
       return true;

    }

    return false;
}


void bfs(ll r1,ll c1)
{

    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<n;j++)
        {
            level[i][j]=-1;
            mark[i][j]=0;
        }
    }


    mark[r1][c1]=1;
    level[r1][c1]=0;

    queue<pair<ll,ll> >q;
    q.push(make_pair(r1,c1));

    while(q.empty()==0)
    {
        ll x=q.front().first;
        ll y=q.front().second;

        q.pop();

        //if(g[x][y]==ch) return;

        for(ll i=0;i<4;i++)
        {
            ll xx=x+dx[i];
            ll yy=y+dy[i];

            if(valid(xx,yy))
            {
                mark[xx][yy]=1;
                level[xx][yy]=level[x][y]+1;
                q.push(make_pair(xx,yy));
            }
        }
    }

    //return level[s1][s2];
}

int main()
{
    ll t;
    cin>>t;


    for(ll tc=1;tc<=t;tc++)
    {

        cin>>n;

        ll coun=0;
        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<n;j++)
            {
                cin>>g[i][j];

                if(g[i][j]>='A'&&g[i][j]<='Z')
                    coun++;

                if(g[i][j]=='A')
                {
                    s1=i;
                    s2=j;
                }
            }
        }

        ll sum=0,flag=0;


        for(ll c=0;c<coun;c++)
        {
            ch=s[c];
             bfs(s1,s2);

             for(ll i=0;i<n;i++)
             {
                for(ll j=0;j<n;j++)
                {
                    if(g[i][j]==ch)
                    {
                        s1=i;
                        s2=j;
                        g[i][j]='.';

                    }
                }
             }


             if(level[s1][s2]==-1)
             {
                 flag=1;
                 break;

             }

            sum=sum+level[s1][s2];

        }

        if(flag==0)
            cout<<"Case "<<tc<<": "<<sum<<endl;
        else
            cout<<"Case "<<tc<<": "<<"Impossible"<<endl;
    }

}
/*
input:
2

5
A....
####.
..B..
.####
C.DE.

2
AC
.B
output:
Case 1: 15
Case 2: 3
*/


