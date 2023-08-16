#include <stdio.h>

void calculateTimes(int n, int burstTime[], int arrivalTime[], int completionTime[], int turnaroundTime[], int waitingTime[]) {
    int remainingTime[n];
    for (int i = 0; i < n; i++) {
        remainingTime[i] = burstTime[i];
    }

    int completed = 0;
    int currentTime = 0;
    int shortestJob = 0;
    int minBurstTime = 9999;
    int check = 0;

    while (completed != n) {
        for (int i = 0; i < n; i++) {
            if (arrivalTime[i] <= currentTime && remainingTime[i] < minBurstTime && remainingTime[i] > 0) {
                shortestJob = i;
                minBurstTime = remainingTime[i];
                check = 1;
            }
        }

        if (check == 0) {
            currentTime++;
            continue;
        }

        remainingTime[shortestJob]--;

        minBurstTime = remainingTime[shortestJob];
        if (minBurstTime == 0) {
            minBurstTime = 9999;
        }

        if (remainingTime[shortestJob] == 0) {
            completed++;
            completionTime[shortestJob] = currentTime + 1;
            turnaroundTime[shortestJob] = completionTime[shortestJob] - arrivalTime[shortestJob];
            waitingTime[shortestJob] = turnaroundTime[shortestJob] - burstTime[shortestJob];
        }

        currentTime++;
    }
}

void printTable(int n, int burstTime[], int arrivalTime[], int completionTime[], int turnaroundTime[], int waitingTime[]) {
    printf("Process\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, arrivalTime[i], burstTime[i],
               completionTime[i], turnaroundTime[i], waitingTime[i]);
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int burstTime[n], arrivalTime[n], completionTime[n], turnaroundTime[n], waitingTime[n];

    printf("Enter arrival time and burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &arrivalTime[i]);
        printf("Burst Time: ");
        scanf("%d", &burstTime[i]);
    }

    calculateTimes(n, burstTime, arrivalTime, completionTime, turnaroundTime, waitingTime);
    printTable(n, burstTime, arrivalTime, completionTime, turnaroundTime, waitingTime);

    // Calculate average waiting time and average turnaround time
    double avgWaitingTime = 0, avgTurnaroundTime = 0;
    for (int i = 0; i < n; i++) {
        avgWaitingTime += waitingTime[i];
        avgTurnaroundTime += turnaroundTime[i];
    }
    avgWaitingTime /= n;
    avgTurnaroundTime /= n;

    printf("Average Waiting Time: %.2lf\n", avgWaitingTime);
    printf("Average Turnaround Time: %.2lf\n", avgTurnaroundTime);

    return 0;
}

