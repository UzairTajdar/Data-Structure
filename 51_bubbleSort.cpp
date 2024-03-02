#include<iostream>
using namespace std;

class BubbleSort{
    public:
    void display(int *a ,int n){
       for (int i = 0; i < n; i++)      
       {
        cout<<a[i]<<" ";
       }
       cout<<endl;
       
    }
    void sorted(int *a,int n){
        int temp;
        for (int i = 0; i < n-1; i++)         //Number of passes
        {
            for (int j = 0; j < n-1-i; j++)    //Number of comparison
            {
                if(a[j]>a[j+1]){
                 temp = a[j];
                 a[j] = a[j+1];
                 a[j+1] = temp;
                }
            }
            
        }
        
    }
    void sortedAdapted(int *a,int n){
        int temp;
        int issorted = 0 ;
        
        for (int i = 0; i < n-1; i++)         //Number of passes
        {
            issorted = 1;
            cout<<"The passing Number is "<<i+1<<endl;
            for (int j = 0; j < n-1-i; j++)    //Number of comparison
            {
                if(a[j]>a[j+1]){
                 temp = a[j];
                 a[j] = a[j+1];
                 a[j+1] = temp;
                 issorted = 0;
                }
            }
            if (issorted)
            {
                return;
            }
            
            
        }
        
    }
};

int main(){
    int arr[] = {99,5,56,57,48,49,80,4,7,2,1,66,77,88,43,22,67,22,12,34};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"The length of array is "<<n<<endl;
    BubbleSort b;
    b.display(arr,n);
    // b.sorted(arr,n);
    b.sortedAdapted(arr,n);
    b.display(arr,n);

}