#include <stdio.h>
#include <stdlib.h>

struct Job {
    int deadline;
    int profit;
};

int compareJobs(const void *a, const void *b) {
    return ((struct Job *)b)->profit - ((struct Job *)a)->profit;
}

void jobSequencing(struct Job jobs[], int n) {
	int i, j;
    qsort(jobs, n, sizeof(struct Job), compareJobs);

    int maxDeadline = 0;
    for (i = 0; i < n; i++) {
        if (jobs[i].deadline > maxDeadline) {
            maxDeadline = jobs[i].deadline;
        }
    }

    int slot[maxDeadline];
    for (i = 0; i < maxDeadline; i++) {
        slot[i] = -1;
    }

    for (i = 0; i < n; i++) {
        for (j = jobs[i].deadline - 1; j >= 0; j--) {
            if (slot[j] == -1) {
                slot[j] = i;
                break;
            }
        }
    }

    printf("Job Sequence: ");
    for (i = 0; i < maxDeadline; i++) {
        if (slot[i] != -1) {
            printf("%d ", slot[i] + 1);
        }
    }
    printf("\n");
}

int main() {
    int n, i;
    struct Job jobs[100];

    printf("Enter the number of jobs: ");
    scanf("%d", &n);

    printf("Enter details for each job:\n");
    for (i = 0; i < n; i++) {
        printf("Job %d:\n", i + 1);
        printf("Deadline: ");
        scanf("%d", &jobs[i].deadline);
        printf("Profit: ");
        scanf("%d", &jobs[i].profit);
    }
    jobSequencing(jobs, n);

    return 0;
}

