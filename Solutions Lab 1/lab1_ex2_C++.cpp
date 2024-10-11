#include <stdio.h>
#include <iostream>

using namespace std;

class Sorter{
    // kept private
    void swap(int* a , int* b){
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    int partitionDescending(int arr[], int low, int high){
        int pivot = arr[high];
        int i = low - 1;
        for(int j = low; j <= high - 1; j++){
            if(arr[j] > pivot){
                i++;
                swap(&arr[i], &arr[j]);
            }
        }
        swap(&arr[i+1], &arr[high]);
        return (i+1);
    }
    void quickSortDescending(int arr[], int low, int high){
        if(low < high){
            int pi = partitionDescending(arr, low, high);
            quickSortDescending(arr, low, pi - 1);
            quickSortDescending(arr, pi + 1, high);
        }
    }
public:
    void sortingAlg(int arr[], int n)
    {
        //TO DO
        quickSortDescending(arr, 0, n-1);
    }
    void printArray(int arr[], int n)
    {
        int i;
        for (i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

};

int main()
{
    int arr[5] = { 40, 8, 11, 2, 99 };
    int n = 5;
    Sorter sorting;
    sorting.sortingAlg(arr, n);
    sorting.printArray(arr, n);

    return 0;
}
