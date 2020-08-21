#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll n,c;
bool fun(ll mid,ll arr[]);
ll bins(ll arr[]);

vector<ll>v;
int main()
{
    ll tc;
    cin>>tc;
    for(ll i=1;i<=tc;i++)
    {
         cin>>n>>c;
         ll arr[n];
         for(ll i=0;i<n;i++)
         cin>>arr[i];
         sort(arr,arr+n);
         ll ans=bins(arr);
         //cout<<ans<<endl;
        sort(v.begin(),v.end());
        cout<<v[0]<<endl;
    }
}
ll bins(ll arr[])
{
     ll left=0,mid,res=-1;
     ll right=arr[n-1];
     while(right>left)
    {
         mid=left+(right-left)/2;
         if(fun(mid,arr))
         {
             if(mid>res)
             res=mid;
             left=mid+1;
          }
         else
         {
             right=mid;
         }
     }
     return res;
}

bool fun(ll mid,ll arr[])
{
    vector<ll>v1;
    ll cnt=1;
    ll sig=arr[0];
    for(ll i=1;i<n;i++)
    {
       if(arr[i]-sig>=mid)
       {
           v1.push_back(arr[i]-sig);
           sig=arr[i];
           cnt++;
        }
       if(cnt==c)
       {
           v=v1;
           return true;
       }

     }
     return false;
}

/*
Input:
1
5 3
1 2 8 4 9

Output:
3
*/
