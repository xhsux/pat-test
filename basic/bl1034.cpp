#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int sgn(int a)
{
    return a>0?1:(a==0?0:-1);
}

long long sgn(long long a)
{
    return a>0?1:(a==0?0:-1);
}

int gcd(int a,int b)
{
    int c;
    if(!(a*b))
        return 1;   //if the numerator is 0, then either a or b is 0
    while(a%b)
    {
        c=a%b;
        a=b;
        b=c;
    }
    return b;
}

long long gcd(long long a,long long b)
{
    long long c;
    if(!(a*b))
        return 1;   //if the numerator is 0, then either a or b is 0
    while(a%b)
    {
        c=a%b;
        a=b;
        b=c;
    }
    return b;
}

void mixedfrac(int nmtr,int dntr,int prop)
{
    if(prop<0)        //transform a improper fraction to mixed fraction
    {
        cout<<'('<<prop;
        if(nmtr)
            cout<<' '<<nmtr<<'/'<<dntr;
        cout<<')';
    }
    else
        if(prop)
        {
            cout<<prop;
            if(nmtr)
                cout<<' '<<nmtr<<'/'<<dntr;
        }
        else
        {
            if(nmtr>0)
                cout<<nmtr<<'/'<<dntr;
            else
            {
                if(nmtr)
                    cout<<'('<<nmtr<<'/'<<dntr<<')';
                else
                    cout<<'0';
            }
        }
}

void getanswer(int a_nmtr,int a_dntr,int a_prop,int b_nmtr,int b_dntr,int b_prop,char optr)
{
    mixedfrac(a_nmtr,a_dntr,a_prop);
    cout<<' '<<optr<<' ';
    mixedfrac(b_nmtr,b_dntr,b_prop);
    cout<<" = ";
}

void frac(long long nmtr,long long dntr,int& frac_prop,long long& frac_nmtr,long long& frac_dntr)   //transform a improper fraction to proper form
{
    if(abs(nmtr)>abs(dntr))
    {
        frac_prop=abs(nmtr)/(dntr)*sgn(nmtr)*sgn(dntr);
        frac_nmtr=abs(nmtr)%abs(dntr);
    }
    else
        if(abs(nmtr)==abs(dntr))
        {
            frac_prop=sgn(nmtr)*sgn(dntr);
            frac_nmtr=0;
        }
        else
        {
            frac_prop=0;
            frac_nmtr=nmtr*sgn(dntr);
        }
    frac_dntr=abs(dntr);
}
void frac(int nmtr,int dntr,int& frac_prop,int& frac_nmtr,int& frac_dntr)   //transform a improper fraction to proper form
{
    if(abs(nmtr)>abs(dntr))
    {
        frac_prop=abs(nmtr)/(dntr)*sgn(nmtr)*sgn(dntr);
        frac_nmtr=abs(nmtr)%abs(dntr);
    }
    else
        if(abs(nmtr)==abs(dntr))
        {
            frac_prop=sgn(nmtr)*sgn(dntr);
            frac_nmtr=0;
        }
        else
        {
            frac_prop=0;
            frac_nmtr=nmtr*sgn(dntr);
        }
    frac_dntr=abs(dntr);
}
void addfrac(long long a_nm,long long a_dn,long long b_nm,long long b_dn,long long& ans_nm,long long& ans_dn)
{
    ans_dn=a_dn*b_dn;
    ans_nm=a_nm*b_dn+b_nm*a_dn;
}

void mulfrac(long long a_nm,long long a_dn,long long b_nm,long long b_dn,long long& ans_nm,long long& ans_dn)
{
    ans_dn=a_dn*b_dn;
    ans_nm=a_nm*b_nm;
}

void getgcd(int nm,int dn,int& gcdval)
{
    if(abs(nm)>=abs(dn))
        gcdval=gcd(abs(nm),abs(dn));
    else
        gcdval=gcd(abs(dn),abs(nm));
}

void getgcd(long long nm,long long dn,long long& gcdval)
{
    if(abs(nm)>=abs(dn))
        gcdval=gcd(abs(nm),abs(dn));
    else
        gcdval=gcd(abs(dn),abs(nm));
}

void printanswer(long long nm,long long dn,long long gcdval,int pr)
{
    getgcd(nm,dn,gcdval);
    nm/=gcdval;
    dn/=gcdval;
    if(dn)
    {
        frac(nm,dn,pr,nm,dn);
        mixedfrac(nm,dn,pr);
    }
    else
        cout<<"Inf";
    cout<<endl;
}

int main()
{
    int nmtr_a,nmtr_b,dntr_a,dntr_b;    //the numerator and denominator of the fractional number is denoted by nmtr and dntr
    int frac_a_prop,frac_a_nmtr,frac_a_dntr;
    int frac_b_prop,frac_b_nmtr,frac_b_dntr;
    int ans_prop;
    long long ans_nmtr,ans_dntr;
    ans_prop=0;
    scanf("%d/%d %d/%d",&nmtr_a,&dntr_a,&nmtr_b,&dntr_b);
    int gcd_a,gcd_b;
    long long gcd_ans;
    gcd_ans=0;
    getgcd(nmtr_a,dntr_a,gcd_a);
    getgcd(nmtr_b,dntr_b,gcd_b);
    nmtr_a/=gcd_a;                      //transform the fraction to its simplest form
    dntr_a/=gcd_a;
    nmtr_b/=gcd_b;
    dntr_b/=gcd_b;
    frac(nmtr_a,dntr_a,frac_a_prop,frac_a_nmtr,frac_a_dntr);
    frac(nmtr_b,dntr_b,frac_b_prop,frac_b_nmtr,frac_b_dntr);
    getanswer(frac_a_nmtr,frac_a_dntr,frac_a_prop,frac_b_nmtr,frac_b_dntr,frac_b_prop,'+');
    addfrac(nmtr_a,dntr_a,nmtr_b,dntr_b,ans_nmtr,ans_dntr);
    printanswer(ans_nmtr,ans_dntr,gcd_ans,ans_prop);
    getanswer(frac_a_nmtr,frac_a_dntr,frac_a_prop,frac_b_nmtr,frac_b_dntr,frac_b_prop,'-');
    addfrac(nmtr_a,dntr_a,nmtr_b*(-1),dntr_b,ans_nmtr,ans_dntr);
    printanswer(ans_nmtr,ans_dntr,gcd_ans,ans_prop);
    getanswer(frac_a_nmtr,frac_a_dntr,frac_a_prop,frac_b_nmtr,frac_b_dntr,frac_b_prop,'*');
    mulfrac(nmtr_a,dntr_a,nmtr_b,dntr_b,ans_nmtr,ans_dntr);
    printanswer(ans_nmtr,ans_dntr,gcd_ans,ans_prop);
    getanswer(frac_a_nmtr,frac_a_dntr,frac_a_prop,frac_b_nmtr,frac_b_dntr,frac_b_prop,'/');
    mulfrac(nmtr_a,dntr_a,dntr_b*sgn(nmtr_b),nmtr_b*sgn(nmtr_b),ans_nmtr,ans_dntr);
    printanswer(ans_nmtr,ans_dntr,gcd_ans,ans_prop);
    return 0;
}
