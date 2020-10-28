#include <iostream>

using namespace std;


void insertionSort(int array[], int dim)
{
    for (int i = 1; i < dim; i++)
    {
        int j = i - 1;
        int pivot = array[i];
        while (j >= 0 && pivot < array[j])
        {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = pivot;
    }
}

void printArray(int array[], int dim)
{
    for (int i = 0; i < dim; i++)
    {
        cout << array[i] << " ";
    }
}


int main(int argc, const char *argv[])
{
    int array[] = {5, 6, 6878, 88, 5, 6, 18, 9};
    int size = sizeof(array)/sizeof(array[0]);
    printArray(array, size);

    cout << endl;

    insertionSort(array, size);
    printArray(array, size);

    return 0;
}