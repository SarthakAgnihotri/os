#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Process {
    int id;
    int burstTime;
    int turnaroundTime;
    int waitingTime;
};

bool compareByBurstTime(const Process &a, const Process &b) {
    return a.burstTime < b.burstTime;
}

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<Process> processes(n);

    for (int i = 0; i < n; i++) {
        cout << "Enter burst time for Process " << i + 1 << ": ";
        cin >> processes[i].burstTime;
        processes[i].id = i + 1;
    }

    // Sort processes based on burst time (SJF)
    sort(processes.begin(), processes.end(), compareByBurstTime);

    // Calculate turnaround time and waiting time
    int totalWaitingTime = 0;
    for (int i = 0; i < n; i++) {
        processes[i].waitingTime = totalWaitingTime;
        processes[i].turnaroundTime = processes[i].waitingTime + processes[i].burstTime;
        totalWaitingTime += processes[i].burstTime;
    }

    cout << "Scheduling order (SJF):" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Process " << processes[i].id << " ";
    }
    cout << endl;

    cout << "Process\tBurst Time\tTurnaround Time\tWaiting Time" << endl;
    for (int i = 0; i < n; i++) {
        cout << processes[i].id << "\t" << processes[i].burstTime << "\t"
             << processes[i].turnaroundTime << "\t" << processes[i].waitingTime << endl;
    }

    return 0;
}
