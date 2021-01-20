#include <bits/stdc++.h>
using namespace std;
int l1;
int yconst(int x,int y)
{
    int p=0;
    int q=x;
    int mid;
    int ans;
    
    while(q>p)//not be ">="
    {
        mid=(p+q)/2;
        cout<<"? "<<mid<<" "<<y<<endl;
    
    /*    printf("? %d %d\n", mid, y);
	    fflush(stdout);*/
    
        //fflush(stdout);
        string str;
        cin>>str;
        /*cout<<"\nleft="<<p<<" right="<<q;
        cout<<"got it"<<str<<endl;*/
        if(str[0]=='Y') p=mid+1;
        else q=mid-1;
    }
    mid=p;
    cout<<"? "<<mid<<" "<<y<<endl;
    
    /*printf("? %d %d\n", mid, y);
	fflush(stdout);*/
    
    //fflush(stdout);
    string str;
    cin>>str;
    if(str[0]=='Y') ans=mid;
    else ans=mid-1;   
    
    return ans;
}

int xconst(int x,int y)
{
    int p=2*l1;
    int q=y;
    int mid;
    int ans;
    
    while(q>p)//not be ">="
    {
        mid=(p+q)/2;
        cout<<"? "<<x<<" "<<mid<<endl;
      //  fflush(stdout);
       
      /*  printf("? %d %d\n", x, mid);
	    fflush(stdout);*/
       
        string str;
        cin>>str;
       /* cout<<"\nleft="<<p<<" right="<<q;
        cout<<"got it"<<str<<endl;*/
        if(str[0]=='Y') p=mid+1;
        else q=mid-1;
    }
    mid=p;
    cout<<"? "<<x<<" "<<mid<<endl;
    
    /*printf("? %d %d\n", x, mid);
	fflush(stdout);*/
    
    //fflush(stdout);
    string str;
    cin>>str;
    if(str=="YES") ans=mid;
    else ans=mid-1;   
    
    return ans;
}

int main()
{
    /*ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);*/
    l1=yconst(1000,0);
    int l2=yconst(1000,2*l1);
    int h=xconst(0,1000);
    cout<<"! "<<((2*l1)*(2*l1))+(l2*(h-2*l1))<<endl;
}
