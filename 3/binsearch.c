#include <stdio.h>

int binsearch(int value, int array[], int len);

// -------------------------------- Main --------------------------------
int main(void) {
    int array[] = {0, 1, 1, 4, 5, 6, 9, 12, 12, 15};
    int len = 10;
    int value, key;

    printf("Value to find: ");
    scanf("%d", &value);
    key = binsearch(value, array, len);
    printf("%d\n", key);
}

// ---------------------------------------------------------
int binsearch(int value, int array[], int len) {
    int low = 0;
    int high = len - 1;

    while(low <= high) {
        int mid = (high + low) / 2;
        if (array[mid] < value)
            low = mid + 1;
        else if (array[mid] > value)
            high = mid - 1;
        else
            return mid;
    }
    return -1;
}