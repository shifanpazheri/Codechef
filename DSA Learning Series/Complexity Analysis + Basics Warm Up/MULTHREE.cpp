#include<bits/stdc++.h>
using namespace std;

//NOTE if you use "int" instead of "long long int" all testcases will not pass

int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
        long long int k,d0,d1,tot;
        cin>>k>>d0>>d1;
        if(k==2) 
            tot=d0+d1;
        else
        {
            long long int no_cycles=(k-3)/4;
            long long int s=(d0+d1)%10;
            long long int each_cycle=(2*s)%10+(4*s)%10+(8*s)%10+(6*s)%10;
            tot=each_cycle*no_cycles+d0+d1+s;
           // cout<<"no="<<no_cycles<<" s="<<s<<" each_cycle="<<each_cycle<<" tot"<<tot<<"\n";
            if((k-3)%4==1)
                tot+=(2*s)%10;
            if((k-3)%4==2)
                tot+=(2*s)%10+(4*s)%10;
            if((k-3)%4==3)
                tot+=(2*s)%10+(4*s)%10+(8*s)%10;
        }
       // cout<<tot;
        if(tot%3==0)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}