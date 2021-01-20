#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
        long long int n;
        cin>>n;
        vector <long long int> a(n);
        multiset <long long int> st;
        
        for(long long int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        
        st.insert(a[0]);
        
        for(long long int i=1;i<n;i++)
        {
            auto it=st.upper_bound(a[i]);
            if(it!=st.end())
                st.erase(it);//dont dereference (it) <-- very very imp i got error due to it
            st.insert(a[i]);
        }
        
        cout<<st.size()<<" ";
        
        for(auto it:st)
            cout<<it<<" ";
        cout<<"\n";
    }
}