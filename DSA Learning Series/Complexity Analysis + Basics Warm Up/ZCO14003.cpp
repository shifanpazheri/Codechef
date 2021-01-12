#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int n;
    cin>>n;
    
    vector <long long int> a;
    a.resize(n);
    
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    
    sort(a.begin(),a.end());
    
  /*  for(int i=0;i<n;i++)
    {
        cout<<a[i]<<"\n";
    }*/
    
    long long int maxm=INT_MIN;
    long long int value;
    for(int i=0;i<n;i++)
    {
        value=a[i];
        maxm=max(maxm,value*(n-i));
    }
    cout<<maxm;
}