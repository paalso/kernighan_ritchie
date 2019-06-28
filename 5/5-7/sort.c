#include <string.h>

/* swap: поменять местами v[i] и v[j] */
void swap(char *v[], int i, int j)
{   
    char *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}


/* qsort: сортирует v[left]...v[right] по возрастанию */
void quicksort(char *v[], int left, int right) {
    if (left >= right)
        return;
    swap(v, left, (left + right) / 2);
    int margin_index = left;
    char *margin_value = v[left];

    for (int i = left + 1; i <= right; ++i)
        if (strcmp(v[i], margin_value) < 0)
            swap(v, ++margin_index, i);

    swap(v, left, margin_index);

    quicksort(v, left, margin_index - 1);
    quicksort(v, margin_index + 1, right);
}