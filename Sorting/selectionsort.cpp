#include <iostream>

using namespace std;

void swap(int *x, int *y)
{
    int t = *x;
    *x = *y;
    *y = t;
}

void sort(int arr[], int count)
{
    int i, j, min_idx;

    for(int i = 0; i < count - 1; i++)
    {
        min_idx = i;

        for(int j = i + 1; j < count; j++)
        {
            if(arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }

        //swap(&arr[i], &arr[min_idx]);

        if(min_idx != i)
        {
            swap(&arr[i], &arr[min_idx]);
        }
    }
}

void print(int arr[], int count)
{
    for(int i = 0; i < count; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = {23, 78, 45, 8, 32, 56};
    int count = sizeof(arr) / sizeof(arr[0]);
    sort(arr, count);
    print(arr, count);
}