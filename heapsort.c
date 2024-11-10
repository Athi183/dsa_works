#include <stdio.h>

int a[50], b[50];
int n;

void heaptree(int n) {
    for (int i = 0; i < n; i++) {
        b[i] = a[i];
        int j = i;
        while (j > 0) {
            int parent = (j - 1) / 2;
            if (b[j] > b[parent]) {
                int temp = b[j];
                b[j] = b[parent];
                b[parent] = temp;
                j = parent;
            } else {
                break;
            }
        }
    }
}

void heapsort() {
    heaptree(n);

    for (int i = n - 1; i > 0; i--) {
        // Swap the root of the heap with the last element
        int temp = b[0];
        b[0] = b[i];
        b[i] = temp;

        // Heapify the root element to maintain the max-heap property
        int j = 0;
        int last = i;
        while (j < last / 2) {
            int max = 2 * j + 1;
            if (max + 1 < last && b[max] < b[max + 1]) {
                max = max + 1;
            }
            if (b[j] < b[max]) {
                int temp = b[j];
                b[j] = b[max];
                b[max] = temp;
                j = max;
            } else {
                break;
            }
        }
    }

    // Copy sorted elements back to array `a`
    for (int k = 0; k < n; k++) {
        a[k] = b[k];
    }
}

int main() {
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int m = 0; m < n; m++) {
        printf("a[%d] = ", m);
        scanf("%d", &a[m]);
    }

    heapsort();

    printf("Sorted array:\n");
    for (int m = 0; m < n; m++) {
        printf("%d ", a[m]);
    }
    printf("\n");

    return 0;
}

