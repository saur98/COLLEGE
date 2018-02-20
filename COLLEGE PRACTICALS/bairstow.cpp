#include<iostream>
#include<stdlib.h>
#include<cmath>
using namespace std;

void bc(float a [],float b[],float c[],float &p,float &q,int n);

void delta(float a[],float b[],float c[],float &p,float &q,int n)
{
    int i;
    float x,y,d;
    x=((b[3]*c[2])-(b[4]*c[1]))/((c[2]*c[2])-(c[1]*(c[3]-b[3])));
    y=((b[4]*c[2])-(b[3]*(c[3]-b[3])))/((c[2]*c[2])-(c[1]*(c[3]-b[3])));
    p=p+x;
    q=q+y;
//cout<<"p "<<p<<endl<<"q "<<q<<endl;
    if((p-q)<0)
    d=q-p;
    else
    d=p-q;
    if(d<0.005)
    {
        p=round(p);
        q=round(q);
        cout<<endl<<"EQUATION : "<<"X^2+"<<p<<"X+"<<q<<endl;
        if(((-p*-p)-(4*q))<0)
        {d=sqrt((4*q)-(-p*-p));

            cout<<-p/2<<"+"<<d/2<<"i"<<endl;
            cout<<-p/2<<"-"<<d/2<<"i"<<endl;
        }
        else
        {d=sqrt((-p*-p)-(4*q));

            cout<<((-p)+d)/2<<endl;
            cout<<((-p)-d)/2<<endl;
        }
    }
    else
    bc(a,b,c,p,q,n);
}

void bc(float a [],float b[],float c[],float &p,float &q,int n)
{
    int i;
    b[0]=a[0];
    b[1]=a[1]+b[0]*(-1*p);
    for(i=2;i<=n;i++)
    {
        b[i]=a[i]-((p*b[i-1])+(q*b[i-2]));
    }
    c[0]=b[0];
    c[1]=b[1]+c[0]*(-1*p);
    for(i=2;i<n;i++)
    {
        c[i]=b[i]-((p*c[i-1])+(q*c[i-2]));
    }
    delta(a,b,c,p,q,n);
}


int main()
{
    int n,i;
    cout<<"Enter degree"<<endl;
    cin>>n;
    float a[n+1];
    cout<<"Enter Coefficients"<<endl;
    for(i=n;i>=0;i--)
    {
        cout<<"Enter a"<<n-i<<endl;
        cin>>a[n-i];
    }
    cout<<"Enter P and Q"<<endl;
    float p,q;
    cin>>p>>q;
    float b[n+1],c[n];
    bc(a,b,c,p,q,n);


}
