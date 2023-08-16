#include <stdio.h>
#include <stdlib.h> // Include this header for the abs() function

void main() {
    int t[20], d[20], h, i, j, n, temp, k, atr[20], tot, p, sum = 0;
    printf("Enter the number of tracks to be traversed: ");
    scanf("%d", &n);
    printf("Enter the position of the head: ");
    scanf("%d", &h);
    t[0] = 0;
    t[1] = h;
    printf("Enter the tracks: ");
    for (i = 2; i < n + 2; i++)
        scanf("%d", &t[i]);

    t[n + 2] = 199; // Assuming disk size is 200, change it as needed

    for (i = 0; i < n + 2; i++) {
        for (j = 0; j < (n + 2) - i - 1; j++) {
            if (t[j] > t[j + 1]) {
                temp = t[j];
                t[j] = t[j + 1];
                t[j + 1] = temp;
            }
        }
    }

    for (i = 0; i < n + 2; i++) {
        if (t[i] == h) {
            j = i;
            k = i;
        }
    }

    p = 0;
    while (t[j] != 199) { // Change to match the disk size
        atr[p] = t[j];
        j++;
        p++;
    }
    atr[p] = t[j];

    atr[p + 1] = 0; // Assuming the first track is 0, change it as needed
    p++;

    for (j = 0; j < k; j++, p++)
        atr[p] = t[j];

    for (j = 0; j < n + 1; j++) {
        d[j] = abs(atr[j + 1] - atr[j]);
        sum += d[j];
    }

    printf("\nAverage header movements: %f\n", (float)sum / n);
}