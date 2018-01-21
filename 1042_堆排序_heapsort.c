#include <stdio.h>
#include <stdlib.h>

void quicksort(int *data, int left, int right);
void swap(int *a, int *b);

int main()
{
    int i, n, data[100001];

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &data[i]);
    }

    // 執行快速排序法
    quicksort(data, 0, n - 1);

    for (i = 0; i < n; i++)
    {
        printf("%d ", data[i]);
    }

    printf("\n");
    return 0;
}

void quicksort(int *data, int left, int right)
{
    int pivot, i, j;

    if (left >= right) { return; }

    pivot = data[left];

    i = left + 1;
    j = right;

    while (1)
    {
        while (i <= right)
        {
            if (data[i] > pivot)
            {
                break;
            }

            i = i + 1;
        }

        while (j > left)
        {
            if (data[j] < pivot)
            {
                break;
            }

            j = j - 1;
        }

        if (i > j) { break; }

        swap(&data[i], &data[j]);
    }

    swap(&data[left], &data[j]);

    quicksort(data, left, j - 1);
    quicksort(data, j + 1, right);
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

