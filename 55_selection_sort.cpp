#include<iostream>
using namespace std;

class SelectionSort{
    public:
    void display(int *a ,int n){
       for (int i = 0; i < n; i++)      
       {
        cout<<a[i]<<" ";
       }
       cout<<endl;
       
    }
    void Selection_sort(int *a,int n){
        int indexOfMin , temp;
        for (int i = 0; i < n-1; i++)
        {
           indexOfMin = i ;
           for (int j = i+1; j < n; j++)
           {
            if (a[j] < a[indexOfMin] )
            {
                indexOfMin = j;
            }
            
           }

           //Swap
           temp = a[i];
           a[i] = a[indexOfMin];
           a[indexOfMin] = temp;
           
        }
        
    }
};

int main(){
    int arr[] = {12, 05, 4, 11, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"The length of array is "<<n<<endl;
    SelectionSort s;
    s.display(arr,n);
    // b.sorted(arr,n);
    s.Selection_sort(arr,n);
    s.display(arr,n);


    //Example 
    // Input Array (There will be total n-1 passes. 5-1 = 4 in this case!)
    //  00  01  02  03  04
    // |03, 05, 02, 13, 12

    // After first pass
    //  00  01  02  03  04
    //  02,|05, 03, 13, 12

    // After second pass
    // 00  01  02  03  04
    // 02, 03,|05, 13, 12

    // After third pass
    // 00  01  02  03  04
    // 02, 03, 05,|13, 12

    // After fourth pass
    // 00  01  02  03  04
    // 02, 03, 05, 12,|13
}