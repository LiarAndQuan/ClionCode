void bubbleSort(int arr[], int n) {
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 1; j < i + 1; j++) {
            if (arr[j - 1] > arr[j]) {
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
    }
}