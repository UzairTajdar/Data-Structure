#include <iostream>
using namespace std;

class QuickSort
{
public:
    void display(int *a, int n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }

    int partition (int *a, int low, int high){
        int pivot = a[low];
        int i = low+1;
        int j = high;
        int temp;
        do
        {
            while (a[i]<=pivot)
            {
                i++;
            }
            while (a[j]>pivot)
            {
                j--;
            }
            if (i<j)
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
            
            
        } while (i<j);

        temp = a[low];
        a[low] = a[j];
        a[j] = temp;
        return j;
        
    }
    void Quick_sort(int *a, int low, int high)
    {
        int partitionIndex;
        
        if (low < high)
        {
            partitionIndex = partition(a, low, high);
            //  display(a,12);
            Quick_sort(a, low, partitionIndex - 1);
            Quick_sort(a, partitionIndex + 1, high);
        }
    }
};

int main()
{
    int arr[] = {03, 05, 02, 13, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "The length of array is " << n << endl;
    QuickSort q;
    q.display(arr, n);
    q.Quick_sort( arr , 0 ,n-1);
    q.display(arr, n);
}