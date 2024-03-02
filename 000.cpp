#include <iostream>
using namespace std;

class Sort
{
public:
    int partitionIndex(int a[], int low, int high)
    {
        int pivot = a[low];
        int i = low + 1;
        int j = high;
        int temp;
        do
        {
            while (a[i] <= pivot)
            {
                i++;
            }
            while (a[j] > pivot)
            {
                j--;
            }
            if (i < j)
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        } while (i < j);
        temp = a[low];
        a[low] = a[j];
        a[j] = temp;
        return j;
    }

    void quickSort(int a[], int low, int high)
    {
        int partitionIndexx;
        if (low < high)
        {
            partitionIndexx = partitionIndex(a, low, high);
            quickSort(a, low, partitionIndexx - 1);
            quickSort(a, partitionIndexx + 1, high);
        }
    }
};

int main()
{
    Sort so;
    int n = 4;
    int a[] = {3, 17, 2, 1};
    so.quickSort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}
