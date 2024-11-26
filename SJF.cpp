#include <bits/stdc++.h>
using namespace std;
struct process
{
    int pid;
    int arrival_time;
    int burst_time;
    int completion_time;
    int turn_around_time;
    int waiting_time;
};
void sortat(process arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j].arrival_time > arr[j + 1].arrival_time)
            {
                swap(arr[j].arrival_time, arr[j + 1].arrival_time);
                swap(arr[j].burst_time, arr[j + 1].burst_time);
                swap(arr[j].pid, arr[j + 1].pid);
            }
        }
    }
}
void sortbt(process arr[], int n)
{
    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 1; j < n - i - 1; j++)
        {
            if (arr[j].burst_time > arr[j + 1].burst_time)
            {
                swap(arr[j].arrival_time, arr[j + 1].arrival_time);
                swap(arr[j].burst_time, arr[j + 1].burst_time);
                swap(arr[j].pid, arr[j + 1].pid);
            }
        }
    }
}
void sortpid(process arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j].pid > arr[j + 1].pid)
            {
                swap(arr[j].arrival_time, arr[j + 1].arrival_time);
                swap(arr[j].burst_time, arr[j + 1].burst_time);
                swap(arr[j].pid, arr[j + 1].pid);
            }
        }
    }
}
void getCT(process arr[], int n)
{
    arr[0].completion_time = arr[0].burst_time;
    for (int i = 1; i < n; i++)
    {
        arr[i].completion_time = arr[i - 1].completion_time + arr[i].burst_time;
    }
}
void getTAT(process arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        arr[i].turn_around_time = arr[i].completion_time - arr[i].arrival_time;
    }
}
void getWT(process arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        arr[i].waiting_time = arr[i].turn_around_time - arr[i].burst_time;
    }
}
void findSJF(process arr[], int n)
{
    getCT(arr, n);
    getTAT(arr, n);
    getWT(arr, n);
}
void display(process arr[], int n)
{
    int count = 0;
    float wt = 0;
    float tat = 0;
    cout << "\t\t\t\tFCFS TABLE" << endl;
    cout << "Process ID   Arrival Time   Burst Time  Completion Time  Turn Around Time  Waiting Time" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i].pid << "\t\t" << arr[i].arrival_time << "\t\t" << arr[i].burst_time << "\t\t" << arr[i].completion_time << "\t\t" << arr[i].turn_around_time << "\t\t" << arr[i].waiting_time << endl;
        count++;
        wt += arr[i].waiting_time;
        tat += arr[i].turn_around_time;
    }
    cout << "The average waiting time is " << (wt / count) << endl;
    cout << "The average turn around time is " << (tat / count) << endl;
}
int main()
{
    int n;
    cout << "Enter the number of processes" << endl;
    cin >> n;
    process arr[n];
    cout << "Enter Pid\tArrival Time\tBurst Time" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].pid >> arr[i].arrival_time >> arr[i].burst_time;
    }
    sortat(arr, n);
    arr[0].completion_time = arr[0].burst_time;
    arr[0].waiting_time = 0;
    arr[0].turn_around_time = arr[0].waiting_time + arr[0].burst_time;
    sortbt(arr, n);
    findSJF(arr, n);
    sortpid(arr, n);
    display(arr, n);
    return 0;
}