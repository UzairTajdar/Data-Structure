#include<iostream>
using namespace std;

class insertion{
    int arr[100]={7,9,14,26,40};
    int size;
    public:
    insertion(int s){
      size = s;
    }
    void display(){
      for (int i = 0; i < size; i++)
      {
        cout<<arr[i]<<" ";
      }
      cout<<endl;
      
    }
    int insert(int element , int capacity ,int index){
        if(size>=capacity){
            return -1;
        }
        for (int i = size-1 ; i >=index ; i--)
        {
            arr[i+1]=arr[i];
        }
        arr[index]=element;

        size +=1;    
        return 1;
    
    }
};
int main()
{
    insertion obj(5);
    obj.display();
    obj.insert(23,100,3);
    obj.display();
}