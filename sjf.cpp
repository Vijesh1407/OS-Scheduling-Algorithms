#include<bits/stdc++.h>
using namespace std;
char person[]={'A','B','C','D','E'};
int at[]={0,1,2,4,6},bt[]={10,7,2,5,20},n=5;
void sjfnp()
{
    int ct[5],ta[5],wt[5],current=0,completed=0;
    bool is[5]={false};
    float tta=0,twt=0,avgta,avgwt;
    cout<<"Non-preemptive SJF Gantt chart:\n0";
    while(completed<n)
    {
        int in=-1,minbt=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(!is[i] and bt[i]<minbt and at[i]<=current)
            {
                minbt=bt[i];
                in=i;
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
        is[in]=true;
        completed++;
        current=ct[in];
        cout<<"|"<<person[in]<<"|"<<current;
    }
    cout<<"\nPerson | AT | BT | CT | TA | WT |\n";
    for(int i=0;i<n;i++)
    {
        cout<<person[i]<<" | "<<at[i]<<" | "<<bt[i]<<" | "<<ct[i]<<" | "<<ta[i]<<" | "<<wt[i]<<" | "<<endl;
    }
    avgta=(float)tta/n;
    avgwt=(float)twt/n;
    cout<<"Average Turnaround time:"<<setprecision(3)<<avgta;
    cout<<"\nAverage Waiting time:"<<setprecision(3)<<avgwt<<endl;
}
void sjfp()
{
    int ct[5],ta[5],wt[5],rt[5],tta=0,twt=0,current=0,completed=0;
    float avgwt,avgta;
    bool is[5]={false};
    for(int i=0;i<n;i++)
        rt[i]=bt[i];
    cout<<"\nPreemptive SJF Gantt chart:\n0";
    while(completed<n)
    {
        int in=-1,minrt=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(at[i]<=current and rt[i]>0 and rt[i]<minrt)
            {
                minrt=rt[i];
                in=i;
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
            is[in]=true;
            completed++;
        }
        current++;
        cout<<"|"<<person[in]<<"|"<<current;
    }
    cout<<"\nPerson | AT | BT | CT | TA | WT |\n";
    for(int i=0;i<n;i++)
    {
        cout<<person[i]<<" | "<<at[i]<<" | "<<bt[i]<<" | "<<ct[i]<<" | "<<ta[i]<<" | "<<wt[i]<<" | "<<endl;
    }
    avgta=(float)tta/n;
    avgwt=(float)twt/n;
    cout<<"Average Turnaround time:"<<setprecision(3)<<avgta;
    cout<<"\nAverage Waiting time:"<<setprecision(3)<<avgwt<<endl;
}
int main()
{
    sjfnp();
    sjfp();
    return 0;
}