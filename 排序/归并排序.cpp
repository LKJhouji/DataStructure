const int N = 1e6 + 10;
int arr[N], tmp[N];
void mergeSort(int* arr, int l, int r) {
    if (l >= r) return;
    int mid = (l + r) >> 1;
    mergeSort(arr, l, mid), mergeSort(arr, mid + 1, r);
    int i = l, j = mid + 1, t = 0;
    while (i <= mid && j <= r) {
        if (arr[i] <= arr[j]) tmp[t++] = arr[i++];
        else tmp[t++] = arr[j++];
    }
    while (i <= mid) tmp[t++] = arr[i++];
    while (j <= r) tmp[t++] = arr[j++];
    
    for (i = 0, j = l; j <= r; i++, j++) {
        arr[j] = tmp[i];
    }
}


void mergesort()