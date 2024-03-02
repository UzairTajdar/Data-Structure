#include<iostream>
using namespace std;

class searching{
     int arr[1000] = {1,3,5,7,9,45,36,654,3576,445,8675,432,24,678,2,};
     int size = sizeof(arr)/sizeof(int);
     public:
     int searchNum(int element){
          for (int i = 0; i < size; i++)
          {
               if (arr[i]==element){
                    return i;
               }
          }
          return -1;
          
     }

};
int main(){
     searching obj;
     int ele =767;
     int searchNum = obj.searchNum(ele);
     cout<<"The element "<<ele<<" is found at index "<<searchNum<<endl;
}