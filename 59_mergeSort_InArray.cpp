#include<iostream>
using namespace std;

class MergeSort{
   public:
    void display(int *a, int n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    void merge(int *a,int low,int high,int mid,int n){
        int  i,j,k,b[n];
        i = low;
        j = mid+1;
        k = low;
     while (i<=mid && j<=high)
     {
        if (a[i]<a[j])
        {
           b[k]=a[i];
           i++;
           k++;
        }
        else
        {
           b[k]=a[j];
           j++;
           k++;
        }   
     }
     while (i<=mid)
     {
        b[k]=a[i];
           i++;
           k++;
     }
     while (j<=high)
     {
        b[k]=a[j];
           j++;
           k++;
     } 
     for (int i = low; i <= high; i++)
     {
        a[i] = b[i];
     }  
    }
    void merge_sort(int *a,int low ,int high,int n){
        int mid;
        if (low<high)
        {
            mid = (low + high) /2;
            merge_sort(a , low,mid,n);
            merge_sort(a ,mid+1,high,n);
            merge(a,low,high,mid,n);
        }
        
    }
};
int main(){
    int arr[]={5,2,3,1,4};
    int n= sizeof(arr)/sizeof(arr[0]);
    MergeSort ms;
    ms.display(arr,n);
    ms.merge_sort(arr,0,n-1,n);
    ms.display(arr,n);
}