#include<bits/stdc++.h>
using namespace std;
char person[]={'A','B','C','D','E','F'};
int at[]={0,1,3,6,8},bt[]={20,7,3,12,8},n=5;
void roundrobin(int tq)
{
    int ct[n],rt[n],ta[n],wt[n],completed=0,current=0,tta=0,twt=0;
    float avgta,avgwt;
    queue<int> q;
    for(int i=0;i<n;i++)
        rt[i]=bt[i];
    cout<<"Round Robin (Time quantum = "<<tq<<"):\nGantt chart:\n0";
    int i=0;
    while(i<n and at[i]<=current)
        q.push(i++);
    while(completed<n)
    {
        if(q.empty())
        {
            current++;
            cout<<"-"<<current;
            while(i<n and at[i]<=current) q.push(i++);
            continue;
        }
        int in=q.front();
        q.pop();
        if(rt[in]>tq)
        {
            current+=tq;
            rt[in]-=tq;
        }
        else
        {
            current+=rt[in];
            rt[in]=0;
            ct[in]=current;
            ta[in]=ct[in]-at[in];
            wt[in]=ta[in]-bt[in];
            tta+=ta[in];
            twt+=wt[in];
            completed++;
        }
        cout<<" | "<<person[in]<<" | "<<current;
        while(i<n and at[i]<=current) q.push(i++);
        if(rt[in]>0) q.push(in);
    }
    cout<<"\nPerson | AT | BT | CT | TA | WT |\n";
    for(int i=0;i<n;i++)
    {
        cout<<person[i]<<" | "<<at[i]<<" | "<<bt[i]<<" | "<<ct[i]<<" | "<<ta[i]<<" | "<<wt[i]<<endl;
    }
    avgta=(float)tta/n;
    avgwt=(float)twt/n;
    cout<<"Average Turnaround time:"<<setprecision(3)<<avgta;
    cout<<"\nAverage Waiting time:"<<setprecision(3)<<avgwt<<endl;
}
int main()
{
    roundrobin(4);
    roundrobin(2);
    return 0;
}