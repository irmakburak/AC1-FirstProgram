#include <vector>

template <typename T, typename Compare>
void bubbleSort(std::vector<T>& v, Compare comp) {
    int n = v.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (!comp(v[j], v[j + 1])) {
                std::swap(v[j], v[j + 1]);
            }
        }
    }
}

template <typename T, typename Compare>
void bubbleSortWithFlag(std::vector<T>& v, Compare comp) {
    int n = v.size();
    for (int i = 0; i < n - 1; i++) {
        bool sorted = true;
        for (int j = 0; j < n - 1 - i; j++) {
            if (!comp(v[j], v[j + 1])) {
                std::swap(v[j], v[j + 1]);
                sorted = false;
            }
        }
        if (sorted) break;
    }
}

template <typename T, typename Compare>
void selectionSort(std::vector<T>& v, Compare comp) {
    int n = v.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (!comp(v[minIndex], v[j])) {
                minIndex = j;
            }
        }
        std::swap(v[i], v[minIndex]);
    }
}

template <typename T, typename Compare>
void insertionSort(std::vector<T>& v, Compare comp) {
    int n = v.size();
    for (int i = 1; i < n; i++) {
        T key = v[i];
        int j = i - 1;
        while (j >= 0 && !comp(v[j], key)) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = key;
    }
}

// ------------------------------
// HOARE PARTITION (GIVEN)
// ------------------------------
template <typename T, typename Compare>
int hoarePartition(std::vector<T>& arr, int low, int high, Compare comp) {
    T pivot = arr[low];
    int i = low - 1;
    int j = high + 1;

    while (true) {
        do { i++; } while (comp(arr[i], pivot));
        do { j--; } while (comp(pivot, arr[j]));

        if (i >= j) return j;

        std::swap(arr[i], arr[j]);
    }
}

// ------------------------------
// QUICK SORT (FIRST ELEMENT PIVOT)
// ------------------------------
template <typename T, typename Compare>
int partitionFirst(std::vector<T>& v, int low, int high, Compare comp) {
    T pivot = v[low];
    int i = low - 1;
    int j = high + 1;

    while (true) {
        do { i++; } while (comp(v[i], pivot));
        do { j--; } while (comp(pivot, v[j]));

        if (i >= j) return j;

        std::swap(v[i], v[j]);
    }
}

template <typename T, typename Compare>
void quickSortFirst(std::vector<T>& v, int low, int high, Compare comp) {
    if (low < high) {
        int p = partitionFirst(v, low, high, comp);
        quickSortFirst(v, low, p, comp);
        quickSortFirst(v, p + 1, high, comp);
    }
}

// ------------------------------
// QUICK SORT (MIDDLE ELEMENT PIVOT)
// ------------------------------
template <typename T, typename Compare>
int partitionMiddle(std::vector<T>& v, int low, int high, Compare comp) {
    T pivot = v[(low + high) / 2];
    int i = low - 1;
    int j = high + 1;

    while (true) {
        do { i++; } while (comp(v[i], pivot));
        do { j--; } while (comp(pivot, v[j]));

        if (i >= j) return j;

        std::swap(v[i], v[j]);
    }
}

template <typename T, typename Compare>
void quickSortMiddle(std::vector<T>& v, int low, int high, Compare comp) {
    if (low < high) {
        int p = partitionMiddle(v, low, high, comp);
        quickSortMiddle(v, low, p, comp);
        quickSortMiddle(v, p + 1, high, comp);
    }
}
