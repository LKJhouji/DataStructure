const int N = 1e6 + 10;

int arr[N];

void quickSort(int* arr, int l, int r)
{
    if(l >= r) return;

    int i = l - 1, j = r + 1, x = arr[(l + r) >> 1];
    while(i < j)
    {
        do i++; while(arr[i] < x);
        do j--; while(arr[j] > x);
        if(i < j) swap(arr[i], arr[j]);
    }

    quickSort(arr, l, j), quickSort(arr, j + 1, r);
}

