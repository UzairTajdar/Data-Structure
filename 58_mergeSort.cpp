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
    void merge(int *a,int *b,int *c,int m,int n){
        int  i,j,k;
        i=j=k=0;
     while (i<n && j<m)
     {
        if (a[i]<b[j])
        {
           c[k]=a[i];
           i++;
           k++;
        }
        else
        {
           c[k]=b[j];
           j++;
           k++;
        }   
     }
     while (i<n)
     {
        c[k]=a[i];
           i++;
           k++;
     }
     while (j<m)
     {
        c[k]=b[j];
           j++;
           k++;
     } 
    }
};
int main(){
    int a_arr[]={1,4,6,8,9};
    int n= sizeof(a_arr)/sizeof(a_arr[0]);
    int b_arr[]={2,3,10,12,15};
    int m = sizeof(b_arr)/sizeof(b_arr[0]);
    int q = m+n;
    int c_arr[q];
    MergeSort ms;
    ms.display(a_arr,n);
    ms.display(b_arr,m);
    ms.merge(a_arr,b_arr,c_arr,m,n);
    ms.display(c_arr,q);
}