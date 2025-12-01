#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct {
    int *arr;
    int l, r;
} thread_data_t;

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int i = 0; i < n2; i++) R[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void *mergeSortThread(void *arg);

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        pthread_t tid1, tid2;
        thread_data_t data1 = {arr, l, m};
        thread_data_t data2 = {arr, m + 1, r};
        pthread_create(&tid1, NULL, mergeSortThread, &data1);
        pthread_create(&tid2, NULL, mergeSortThread, &data2);
        pthread_join(tid1, NULL);
        pthread_join(tid2, NULL);
        merge(arr, l, m, r);
    }
}

void *mergeSortThread(void *arg) {
    thread_data_t *data = (thread_data_t *)arg;
    mergeSort(data->arr, data->l, data->r);
    pthread_exit(NULL);
}

int main() {
    int n;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Invalid number of elements\n");
        return 1;
    }

    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            fprintf(stderr, "Invalid input for element %d\n", i);
            return 1;
        }
    }

    mergeSort(arr, 0, n - 1);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
