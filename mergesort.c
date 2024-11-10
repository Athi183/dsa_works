#include <stdio.h>

int a[50], b[50];

void merge(int low, int mid, int high) {
    int i = low, j = mid + 1, k = low;

    // Merging the two halves into the temporary array `b`
    while (i <= mid && j <= high) {
        if (a[i] <= a[j]) {
            b[k] = a[i];
            i++;
        } else {
            b[k] = a[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements from the left half, if any
    while (i <= mid) {
        b[k] = a[i];
        i++;
        k++;
    }

    // Copy remaining elements from the right half, if any
    while (j <= high) {
        b[k] = a[j];
        j++;
        k++;
    }

    // Copy the sorted subarray back to the original array `a`
    for (i = low; i <= high; i++) {
        a[i] = b[i];
    }
}

void mergesort(int low, int high) {
    if (low < high) {  // Base case for recursion
        int mid = (low + high) / 2;
        mergesort(low, mid);       // Sort the left half
        mergesort(mid + 1, high);  // Sort the right half
        merge(low, mid, high);     // Merge the sorted halves
    }
}

int main() {
    int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int m = 0; m < n; m++) {
        printf("a[%d] = ", m);
        scanf("%d", &a[m]);
    }

    mergesort(0, n - 1);

    printf("Sorted array:\n");
    for (int m = 0; m < n; m++) {
        printf("%d ", a[m]);
    }
    printf("\n");

    return 0;
}

