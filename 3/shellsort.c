#include <stdio.h>

int shellsort(int*, int);
void swap(int*, int, int);
void print_int_arr(int*, int);

// -------------------------------- Main --------------------------------
int main(void) {
    int array[] = {5, 15, 0, 1, 12, 0, 7, 5, 6, 2, 4, 1};
    int len = 12;

    printf("Original array:\n");    
    print_int_arr(array, len);

    shellsort(array, len);
    printf("\nSorted array:\n");    
    print_int_arr(array, len);

    return 0;
}

// ---------------------------------------------------------
int shellsort(int array[], int len) {
    int iters = 0;
    for (int gap = len / 2; gap > 0; gap /= 2)
        for (int i = gap; i < len; ++i)
            for (int j = i - gap; j >= 0 && array[j + gap] < array[j]; --j) {
                swap(array, j + gap, j);
                printf("iters: %2d, gap = %2d   : ", ++iters, gap);
                print_int_arr(array, len);
            }

}


// ---------------------------------------------------------
void print_int_arr(int *array, int size) {
    for (int *array_end = array + size; array < array_end; ++array)
        printf("%d   ", *array);
        printf("\n");
} 

// ---------------------------------------------------------
void swap(int *array, int i, int j) {
    int tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
}