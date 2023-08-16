#include <stdio.h>

void main() {
    int t[20], n, i, j, tohm[20], tot = 0;
    float avhm;
    
    printf("Enter the number of tracks: ");
    scanf("%d", &n);
    
    printf("Enter the tracks to be traversed:\n");
    for (i = 1; i <= n; i++)
        scanf("%d", &t[i]);
    
    t[0] = 0;  // Set the starting track to 0
    
    for (i = 1; i <= n; i++) {
        tohm[i] = t[i] - t[i - 1];
        if (tohm[i] < 0)
            tohm[i] = -tohm[i];
        tot += tohm[i];
    }
    
    avhm = (float)tot / n;
    
    printf("Tracks traversed\tDifference between tracks\n");
    for (i = 1; i <= n; i++)
        printf("%d\t\t\t%d\n", t[i], tohm[i]);
    
    printf("\nAverage header movements: %f", avhm);
}
