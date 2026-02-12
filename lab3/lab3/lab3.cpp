#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <math.h>
using namespace std;

void bubble_sort(int* const arr, const int n) {
    for (int j = 0; j < n - 1; j++) {
        for (int i = j + 1; i < n; i++) {
            if (arr[i] < arr[j]) {
                swap(arr[j], arr[i]);
            }
        }
    }
}

void SelectionSort(int A[], int n) {
    int count, key;
    for (int i = 0; i < n - 1; i++) {
        count = A[i]; key = i;
        for (int j = i + 1; j < n; j++)
            if (A[j] < A[key]) key = j;
        if (key != i) {
            A[i] = A[key];
            A[key] = count;
        }
    }
}

void quickSort(int* array, int low, int high) {
    int i = low;
    int j = high;
    int ot = array[(i + j) / 2];
    int temp;

    while (i <= j) {
        while (array[i] < ot)
            i++;
        while (array[j] > ot)
            j--;
        if (i <= j) {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j--;
        }
    }
    if (j > low)
        quickSort(array, low, j);
    if (i < high)
        quickSort(array, i, high);
}

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    int menufor = 1;

    system("cls");

    char n;
    clock_t start_shaker, start_bubble, end_shaker, end_bubble, start_selection, end_selection, start_fast, end_fast;
    double time_bubble, time_shaker, time_selection, time_fast;

    int arr_n;
    cout << " Введите количество элементов в массиве\n";
    cin >> arr_n;

    static int* arrA = new int[arr_n];
    for (int i = 0; i < arr_n; i++) {
        arrA[i] = rand() % 100;
    }

    for (int i = 0; i < arr_n; i++) {
        cout << "элемент[" << i << "] = " << arrA[i] << "\n";
    }

    static int* arrB = new int[arr_n];
    static int* arrC = new int[arr_n];
    static int* arrD = new int[arr_n];
    static int* arrE = new int[arr_n];
    for (int i = 0; i < arr_n; i++) {
        arrB[i] = arrA[i];
        arrC[i] = arrA[i];
        arrD[i] = arrA[i];
        arrE[i] = arrA[i];
    }

    start_bubble = clock();
    bubble_sort(arrB, arr_n);
    cout << "\n Отсортированный массив(пузырьковая сортировка):\n";
    for (int i = 0; i < arr_n; i++) {
        cout << "элемент[" << i << "] = " << arrB[i] << "\n";
    }
    end_bubble = clock();
    unsigned int bubble_sort_time = end_bubble - start_bubble;

    start_selection = clock();
    SelectionSort(arrC, arr_n);
    cout << "\nОтсортированный массив(сортировка выбором):\n";
    for (int i = 0; i < arr_n; i++) {
        cout << "элемент[" << i << "] = " << arrC[i] << "\n";
    }
    end_selection = clock();
    unsigned int Selection_sort_time = end_selection - start_selection;

    start_fast = clock();
    quickSort(arrE, 0, arr_n);
    cout << "\nОтсортированный массив(Быстрая сортировка):\n";
    end_fast = clock();
    for (int i = 1; i < arr_n + 1; i++) {
        cout << "элемент[" << i - 1 << "] = " << arrE[i] << "\n";
    }
    unsigned int quick_sort_time = end_fast - start_fast;

    start_shaker = clock();
    insertionSort(arrD, arr_n);
    cout << "\nОтсортированный массив(сортировка вставкой):\n";
    for (int i = 0; i < arr_n; i++) {
        cout << "элемент[" << i << "] = " << arrD[i] << "\n";
    }
    end_shaker = clock();
    unsigned int insertion_sort_time = end_shaker - start_shaker;

    cout << "\nВремя сортировки пузырьком: " << bubble_sort_time << " мс.\n";
    cout << "\nВремя сортировки выбором: " << Selection_sort_time << " мс.\n";
    cout << "\nВремя быстрой сортировки: " << quick_sort_time << " мс.\n";
    cout << "\nВремя сортировки вставкой: " << insertion_sort_time << " мс.\n\n";

    return 0;
}
