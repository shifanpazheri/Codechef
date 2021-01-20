#include <bits/stdc++.h>
using namespace std;
long long int count1=0;

void merge(long long int a[],long long int p,long long int q,long long int r)
{
    //long long int l1=q-p+1,l2=r-q;
    vector<long long int>left;
    vector<long long int>right;
    long long int sent=0;
    for(long long int i=p;i<=q;i++)
    {
      //  cout<<"p is"<<a[i]<<endl;
        sent+=a[i];
        left.push_back(a[i]);
    }
    //cout<<endl;
    for(long long int i=q+1;i<=r;i++)
    {
      //  cout<<"q is"<<a[i]<<endl;
        sent+=a[i];
        right.push_back(a[i]);
    }
    //cout<<endl;
    //left.push_back(sent);
    //right.push_back(sent);
    
    long long int i=0,j=0,k=p;
    while(i<left.size()&&j<right.size())
    {
        //cout<<" left="<<left[i]<<" right="<<right[i];
        if(left[i]<=right[j])
        {
            a[k++]=left[i++];
        }
        else
        {
                //cout<<"swap"<<endl;
            count1=count1+left.size()-i;
            a[k++]=right[j++];
        }
    }
        while(i<left.size()) a[k++]=left[i++];
        while(j<right.size()) a[k++]=right[j++];
       // cout<<" count1="<<count1<<endl;
    
}

void mergesort(long long int a[],long long int p,long long int q)
{
    if(p<q)
    {
        long long int mid=(p+q)/2;
        mergesort(a,p,mid);
        mergesort(a,mid+1,q);
        merge(a,p,mid,q);
    }
}

int main()
{
    long long int n;
    cin>>n;
    long long int a[n];
    for(long long int i=0;i<n;i++)
        cin>>a[i];
    /*for(long long int i=0;i<n;i++)
        cout<<a[i]<<" ";*/
    mergesort(a,0,n-1);
    /*for(long long int i=0;i<n;i++)
        cout<<a[i]<<" ";*/
    cout<<endl;
    cout<<count1;
}