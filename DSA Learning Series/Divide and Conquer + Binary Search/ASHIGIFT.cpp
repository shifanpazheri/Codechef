#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
        long long int dist,b;
        cin>>dist>>b;
        vector<pair<long long int,long long int>> a(b+1);
        long long int person=1;
        for(long long int i=0;i<b;i++)
        {
            long long int x,y;
            cin>>x>>y;
            a[i].first=x;
            a[i].second=y;
            //=make_pair(x,y);
            person+=y;
        }
        long long int c;
        cin>>c;
        if(c==0)
            cout<<person<<"\n";
        else
        {
            map<long long int,pair<long long int,long long int>>p;
            for(long long int i=0;i<c;i++)
            {
                long long int x,y,z;
                cin>>x>>y>>z;
                p[x]=make_pair(y,z);
            }
            sort(a.begin(),a.end()-1);
            //sort(p.begin(),p.end()-1);
            auto it=p.end();
            it--;
            //cout<<(*it).first+1;
            a[b].first=a[b-1].first+(*it).first+1;
            //cout<<endl<<" a[b]="<<a[b].first<<endl;
            p[a[b].first]=make_pair(-999,-999);
            //p[c].first=a[b-1].first+p[c-1].first+1;
            long long int low=1;
            long long int high=person;
            long long int mid,ans=0;
            
            /*for(auto it=p.begin();it!=p.end();it++)
            {
                cout<<(*it).first<<" ";
            }*/
            
            while(high>=low)
            {
                mid=(low+high)/2;
                //cout<<"mid start"<<mid<<endl;
                long long int i=0;
                auto it=p.begin();
                while((i<b||it->first!=a[b].first)&&mid!=0)
                {
                   // cout<<"a[i].first="<<a[i].first<<" (*it).first="<<(*it).first;
                    if(a[i].first>(*it).first)
                    {
                        //cout<<""<<""<<"";
                        if(mid>=(*it).second.first)
                        {
                            mid=mid+(*it).second.second;
                        }
                        it++;
                    }
                    else
                    {
                        mid=mid-a[i].second;
                        i++;
                    }
                 //   cout<<" mid="<<mid<<"\n";
                }
               // cout<<"mid end"<<mid<<endl;
                
                if(mid<=0) 
                {
                    low=((low+high)/2)+1;
                    //ans=low-1;
                }
                else 
                {
                    high=((low+high)/2)-1;
                    //ans=high+1;
                }
                //cout<<" ans="<<ans<<"\n";
            }
            mid=low;
            long long int i=0;
                it=p.begin();
                while((i<b||it->first!=a[b].first)&&mid!=0)
                {
                   // cout<<"a[i].first="<<a[i].first<<" (*it).first="<<(*it).first;
                    if(a[i].first>(*it).first)
                    {
                        //cout<<""<<""<<"";
                        if(mid>=(*it).second.first)
                        {
                            mid=mid+(*it).second.second;
                        }
                        it++;
                    }
                    else
                    {
                        mid=mid-a[i].second;
                        i++;
                    }
                 //   cout<<" mid="<<mid<<"\n";
                 if(mid>0) ans=low;
                 else ans=low-1;
            }
            
            cout<<ans<<"\n";
        }
    }
}