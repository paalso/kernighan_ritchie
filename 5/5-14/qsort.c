// --- swap ---------------------------------------------------------
// меняет местами два указателя
void swap(void *v[], int i, int j)
{
    void *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}


// --- quicksort ---------------------------------------------------------
// сортирует v[left]...v[right]: range = 1 - по возрастанию, 0 - по убыванию
void quicksort(void *v[], int left, int right,
        int (*comp)(void *, void *), int order)
{
    int i, last;
    void swap(void *v[], int, int);
    if (left >= right) /* ничего не делается, если */
        return;        /* в массиве менее двух элементов */

    swap(v, left, (left + right)/2);
    last = left;
    for (i = left+1; i <= right; i++)
        if (order) {
            if ((*comp)(v[i], v[left]) < 0)
                swap(v, ++last, i);
        }
        else {
            if ((*comp)(v[i], v[left]) > 0)
                swap(v, ++last, i);
        }
    swap(v, left, last);
    quicksort(v, left, last-1, comp, order);
    quicksort(v, last+1, right, comp, order);
}
