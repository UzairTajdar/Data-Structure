#include<iostream>
using namespace std;

class searching{
    public:

    int binarysearch(int arr[] ,int right,int left, int element){
        while (left <= right) {
            int mid =( left + right )/ 2;

            if (arr[mid] == element) {
                return mid; // Element found, return its index
            } else if (arr[mid] < element) {
                left = mid + 1; // Search the right half
            } else {
                right = mid - 1; // Search the left half
            }
        }

        return -1; // Element not found
     }

};
int main(){
     searching obj;
     int arr[] = {1,3,5,7,9,45,76};
     int size = sizeof(arr)/sizeof(int);
     int right =size - 1;
     int left = 0; 
     int ele =45;
     int searchNum = obj.binarysearch(arr,right,left,ele);
     cout<<"The element "<<ele<<" is found at index "<<searchNum<<endl;
}
