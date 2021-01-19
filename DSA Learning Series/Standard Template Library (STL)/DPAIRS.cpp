#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n,m;
    cin>>n>>m;
    
    /*vector <pair<long long,long long>> a(n);
    vector <pair<long long,long long>> b(m);*/
    
    vector <pair<int,int>> a(n);
    vector <pair<int,int>> b(m);
    
    for(long long i=0;i<n;i++)
    {
        cin>>a[i].first;
        a[i].second=i;
    }
    for(long long i=0;i<m;i++)
    {
        cin>>b[i].first;
        b[i].second=i;
    }
    
    vector <pair<int,int>> ans(n+m-1);
    vector <int> value(n+m-1);
    
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    
    /*for(int i=0;i<n;i++)
    {
        cout<<a[i].first<<" "<<a[i].second<<"\n";
    }
    
    cout<<"\n\n\n";
    
    for(int i=0;i<m;i++)
    {
        cout<<b[i].first<<" "<<b[i].second<<"\n";
    }
    
    cout<<"\n\n\n";*/
    
    int i=0,j=0,k=0;
    while(i!=n&&j!=m)
    {
        if(a[i].first<=b[j].first)
        {   
            value[k]=a[i].first+b[j].first;
            ans[k++]=make_pair(a[i].second,b[j].second);
            i++;
        }
        else
        {
             value[k]=a[i].first+b[j].first;
            ans[k++]=make_pair(a[i].second,b[j].second);
            j++;
        }
    }
    
    if(i==n)
    {
        i--;
        j++;
        while(j!=m)
        {
             value[k]=a[i].first+b[j].first;
            ans[k++]=make_pair(a[i].second,b[j].second);
            j++;   
        }
    }
    
    else
    {
        j--;
        i++;
        while(i!=n)
        {
            value[k]=a[i].first+b[j].first;
            ans[k++]=make_pair(a[i].second,b[j].second);
            i++;
        }
    }
    
 /*   for(int i=0;i<k;i++)
    {
        cout<<value[i]<<"\n";
    }*/
    
    for(int i=0;i<k;i++)
    {
        cout<<ans[i].first<<" "<<ans[i].second<<"\n";
    }

}