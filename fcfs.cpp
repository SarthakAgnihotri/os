

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    int arrivalTime[n], burstTime[n], completionTime[n], turnaroundTime[n], waitingTime[n];

    cout << "Enter arrival time and burst time for each process:\n";
    for (int i = 0; i < n; i++) {
        cout << "Process " << i + 1 << " Arrival Time: ";
        cin >> arrivalTime[i];
        cout << "Process " << i + 1 << " Burst Time: ";
        cin >> burstTime[i];
    }

    // Calculate completion time
    int currentTime = 0;
    for (int i = 0; i < n; i++) {
        if (currentTime < arrivalTime[i]) {
            currentTime = arrivalTime[i];
        }
        completionTime[i] = currentTime + burstTime[i];
        currentTime = completionTime[i];
    }

    // Calculate turnaround time and waiting time
    for (int i = 0; i < n; i++) {
        turnaroundTime[i] = completionTime[i] - arrivalTime[i];
        waitingTime[i] = turnaroundTime[i] - burstTime[i];
    }

    // Display results
    cout << "\nProcess\tAT\tBT\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << i + 1 << "\t" << arrivalTime[i] << "\t" << burstTime[i] << "\t" << completionTime[i] << "\t" << turnaroundTime[i] << "\t" << waitingTime[i] << endl;
    }

    return 0;
}
