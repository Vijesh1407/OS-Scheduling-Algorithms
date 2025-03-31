#include<bits/stdc++.h>
using namespace std;
char person[]={'A','B','C','D','E'};
int at[]={0,1,3,6,8},priority[]={5,3,1,2,4},bt[]={15,5,12,25,2},n=5;
void priority_np()
{
    int ct[n],wt[n],ta[n],tta=0,twt=0,current=0,completed=0;
    float avgta,avgwt;
    bool is[n]={false};
    cout<<"Non-preemptive Priority Gantt chart:\n0";
    while(completed<n)
    {
        int in=-1,min_p=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(!is[i] and at[i]<=current and priority[i]<min_p)
            {
                in=i;
                min_p=priority[i];
            }
        }
        if(in==-1)
        {
            current++;
            cout<<"-"<<current;
            continue;
        }
        ct[in]=current+bt[in];
        ta[in]=ct[in]-at[in];
        wt[in]=ta[in]-bt[in];
        tta+=ta[in];
        twt+=wt[in];
        current=ct[in];
        completed++;
        is[in]=true;
        cout<<" | "<<person[in]<<" | "<<current;
    }
    cout<<"\nPerson | AT | BT | CT | TA | WT |\n";
    for(int i=0;i<n;i++)
    {
        cout<<person[i]<<" | "<<at[i]<<" | "<<bt[i]<<" | "<<ct[i]<<" | "<<ta[i]<<" | "<<wt[i]<<endl;
    }
    avgta=(float)tta/n;
    avgwt=(float)twt/n;
    cout<<"Average Turnaround time:"<<setprecision(3)<<avgta;
    cout<<"\nAverage Waiting time:"<<setprecision(3)<<avgwt;
}
void priority_p()
{
    int ct[n],ta[n],wt[n],rt[n],current=0,completed=0,tta=0,twt=0;
    float avgwt,avgta;
    for(int i=0;i<n;i++)
        rt[i]=bt[i];
    cout<<"\nPreemptive Priority Gantt chart:\n0";
    while(completed<n)
    {
        int min_p=INT_MAX,in=-1;
        for(int i=0;i<n;i++)
        {
            if(at[i]<=current and rt[i]>0 and priority[i]<min_p)
            {
                in=i;
                min_p=priority[i];
            }
        }
        if(in==-1)
        {
            current++;
            cout<<"-"<<current;
            continue;
        }
        rt[in]--;
        if(rt[in]==0)
        {
            ct[in]=current+1;
            ta[in]=ct[in]-at[in];
            wt[in]=ta[in]-bt[in];
            tta+=ta[in];
            twt+=wt[in];
            completed++;
        }
        current++;
        cout<<" | "<<person[in]<<" | "<<current;
    }
    cout<<"\nPerson | AT | BT | CT | TA | WT |\n";
    for(int i=0;i<n;i++)
    {
        cout<<person[i]<<" | "<<at[i]<<" | "<<bt[i]<<" | "<<ct[i]<<" | "<<ta[i]<<" | "<<wt[i]<<endl;
    }
    avgta=(float)tta/n;
    avgwt=(float)twt/n;
    cout<<"Average Turnaround time:"<<setprecision(3)<<avgta;
    cout<<"\nAverage Waiting time:"<<setprecision(3)<<avgwt;
}
int main()
{
    priority_np();
    priority_p();
    return 0;
}
