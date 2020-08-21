 #include <bits/stdc++.h>
using namespace std;
int n,c;
bool fun(int mid,int arr[]);
int bins(int arr[]);

vector<int>v;
int main()
{

         cin>>n>>c;
         int arr[n];
         for(int i=0;i<n;i++)
         cin>>arr[i];
         sort(arr,arr+n);
         int ans=bins(arr);
         //cout<<ans<<endl;
   sort(v.begin(),v.end());
    cout<<v[0]<<endl;
}
int bins(int arr[])
{
     int left=0,mid,res=-1;
     int right=arr[n-1];
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

bool fun(int mid,int arr[])
{
    vector<int>v1;
     int cnt=1; int sig=arr[0];
    for(int i=1;i<n;i++)
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
