#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, direction;

    printf("Enter the number of requests: ");
    scanf("%d", &n);

    int *requests = malloc(n * sizeof(int));
    printf("Enter the requests: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }

    printf("Enter the starting head position: ");
    scanf("%d", &head);

    printf("Enter the direction (0 for left, 1 for right): ");
    scanf("%d", &direction);

    int total_distance = 0;
    if (direction == 0) {
        // Sort the requests in ascending order
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (requests[j] > requests[j + 1]) {
                    int temp = requests[j];
                    requests[j] = requests[j + 1];
                    requests[j + 1] = temp;
                }
            }
        }

        // Moving left from the starting head position
        for (int i = head; i >= 0; i--) {
            printf("%d ", i);
            total_distance += i;
        }

        // Moving right to the last request
        for (int i = 0; i < n; i++) {
            printf("%d ", requests[i]);
            total_distance += requests[i];
        }
    } else {
        // Sort the requests in descending order
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (requests[j] < requests[j + 1]) {
                    int temp = requests[j];
                    requests[j] = requests[j + 1];
                    requests[j + 1] = temp;
                }
            }
        }

        // Moving right from the starting head position
        for (int i = head; i <= 199; i++) {
            printf("%d ", i);
            total_distance += i;
        }

        // Moving left to the last request
        for (int i = 0; i < n; i++) {
            printf("%d ", requests[i]);
            total_distance += requests[i];
        }
    }

    printf("\nTotal distance: %d\n", total_distance);

    free(requests);

    return 0;
}
