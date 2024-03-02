#include<iostream>
#include<limits.h>
using namespace std;

class CountSort{
    public:
     void display(int *a, int n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    int maximum(int *a,int n){
      int max = INT_MIN;
      for (int i = 0; i < n; i++)
      {
        if (max<a[i])
        {
            max = a[i];
        }
      }
     return max;
    }
    void Count_Array(int * a,int n){
        int max = maximum(a,n);

        int *count = new int(max+1);

        for (int i = 0; i <= max; i++)
        {
           count[i] = 0;
        }
        for (int j = 0; j < n; j++)
        {
            count[a[j]] = count[a[j]] +1;
        }

        int k ,p;
        k=0;
        p=0;
        while (k <= max)
        {
           if (count[k]>0)
           {
            a[p] = k;
            count[k] = count[k] -1;
            p++;
           }
           else{
            k++;
           }
           
        }
        
        
    }
};
int main(){
    int arr[] = {03, 05, 02, 13, 12 ,45,0,7,8,8,12,34};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "The length of array is " << n << endl;
    CountSort c;
    c.display(arr, n);
    c.Count_Array(arr,n);
    c.display(arr, n);
}