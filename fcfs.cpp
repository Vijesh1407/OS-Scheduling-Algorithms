#include<bits/stdc++.h>
using namespace std;
char person[]={'A','B','C','D','E'};
int at[]={0,2,5,6,7},bt[]={15,10,3,6,5},n=5;
int main()
{
    int wt[5],ct[5],ta[5],current=0,tta=0,twt=0;
    float avgta,avgwt;
    for(int i=0;i<n;i++)
    {
        if(current<at[i])
            current=at[i];
        ct[i]=current+bt[i];
        ta[i]=ct[i]-at[i];
        wt[i]=ta[i]-bt[i];
        tta+=ta[i];
        twt+=wt[i];
        current=ct[i];
    }
    cout<<"Person | AT | BT | CT | TA | WT |\n";
    for(int i=0;i<n;i++)
    {
        cout<<person[i]<<" | "<<at[i]<<" | "<<bt[i]<<" | "<<ct[i]<<" | "<<ta[i]<<" | "<<wt[i]<<" | \n";
    }
    avgta=(float)tta/n;
    avgwt=(float)twt/n;
    cout<<"Average Turnaround time:"<<setprecision(3)<<avgta<<endl;
    cout<<"Average Waiting time:"<<setprecision(3)<<avgwt<<endl;
    cout<<"Gantt chart:\n";
    cout<<"| ";
    for(int i=0;i<n;i++)
    {
        cout<<person[i]<<" | ";
    }
    cout<<endl<<"0 ";
    current=0;
    for(int i=0;i<n;i++)
    {
        if(current<at[i])
            current=at[i];
        current+=bt[i];
        cout<<" "<<current;
    }
    return 0;
}