#include <stdio.h>
#include <stdbool.h>
 
int main() {
    int curr[5][5];
    int max_claim[5][5];
    int avl[5];
    int alloc[5] = {0, 0, 0, 0, 0};
    int max_res[5];
    int running[5];
 
    int i, j, exec, r, p;
    int count = 0;
    bool safe = false;
 
    printf("# of Resources : ");
    scanf("%d", &r);
 
    printf("# of Processes : ");
    scanf("%d", &p);
    for (i = 0; i < p; i++) {
        running[i] = 1;
        count++;
    }
 
    printf("Total : ");
    for (i = 0; i < r; i++)
        scanf("%d", &max_res[i]);
 
    printf("Resource : ");
    for (i = 0; i < p; i++) {
        for (j = 0; j < r; j++)
            scanf("%d", &curr[i][j]);
    }
 
    printf("Max : ");
    for (i = 0; i < p; i++) {
        for (j = 0; j < r; j++)
            scanf("%d", &max_claim[i][j]);
    }
 
    for (i = 0; i < p; i++)
        for (j = 0; j < r; j++)
            alloc[j] += curr[i][j];
 
    printf("Allocated resources: ");
    for (i = 0; i < r; i++)
        printf("%d ", alloc[i]);
    for (i = 0; i < r; i++)
        avl[i] = max_res[i] - alloc[i];
 
    printf("\nAvailable resources: ");
    for (i = 0; i < r; i++)
        printf("%d ", avl[i]);
    printf("\n");
 
    while (count != 0) {
        safe = false;
        for (i = 0; i < p; i++) {
            if (running[i]) {
                exec = 1;
                for (j = 0; j < r; j++) {
                    if (max_claim[i][j] - curr[i][j] > avl[j]) {
                        exec = 0;
                        break;
                    }
                }
 
                if (exec) {
                    printf("Process%d is on.\n", i);
                    running[i] = 0;
                    count--;
                    safe = true;
                    for (j = 0; j < r; j++)
                        avl[j] += curr[i][j];
                    break;
                }
            }
        }
 
        if (!safe) {
            printf("Process is unsafe.\n");
			return (0);
            break;
        }

        printf("Available is [");
        for (i = 0; i < r; i++)
            printf("%d ", avl[i]);
		printf("\b]\n");
    }
	printf("Process is safe.\n");
    return 0;
}