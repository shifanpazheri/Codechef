#include <bits/stdc++.h>
using namespace std;
// usage of priority_queue is amazing-> time complexity issues
int main()
{
    long long t;
    cin>>t;
    while(t--)
    {
        long long k,query;
        cin>>k>>query;
       
        vector<long long>p(k);
        vector<long long>q(k);
       
        for(long long i=0;i<k;i++) cin>>p[i];
        for(long long i=0;i<k;i++) cin>>q[i];
        
        sort(p.begin(),p.end());
        sort(q.begin(),q.end());
        
        priority_queue<long long> pq;
        for(int i=0;i<k;i++){
            for(int j=0;j<k;j++){
                if(pq.size()<10000){
                     pq.push(p[i]+q[j]);
                }
                else if(pq.top()>p[i]+q[j]){
                    pq.pop();
                    pq.push(p[i]+q[j]);
                }
                else
                    break;
            }
        }
        
        priority_queue<long long,vector<long long>,greater<long long>> tempmain,temp;
        while(!pq.empty())
        {
            tempmain.push(pq.top());
           // cout<<" values are"<<pq.top()<<" ";
            pq.pop();
        }
        for(int i=0;i<query;i++)
        {
            long long ans;
            long long value;
            cin>>value;
            while(!tempmain.empty())
            {
                //cout<<" inside"<<tempmain.top()<<endl;
                temp.push(tempmain.top());
                value-=1;
                ans=tempmain.top();
                tempmain.pop();
                if(value<=0) break;
            }
            cout<<ans<<endl;
            while(!temp.empty())
            {
                tempmain.push(temp.top());
                temp.pop();
            }
        }
     }
}
    
    
