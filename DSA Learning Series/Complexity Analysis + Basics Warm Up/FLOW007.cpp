#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {long int n;
    cin>>n;
    long int ans=0;
    int len=-1;
    long int temp=n;
    while(temp>0)
    {
        temp=temp/10;
        len++;
    }
    while(n>0)
    {
        ans=ans+(n%10)*pow(10,len--);
        n=n/10;
    }
    cout<<ans<<"\n";
    }
}
