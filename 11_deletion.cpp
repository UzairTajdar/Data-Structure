#include<iostream>
using namespace std;

class deletion{
    int arr[100]={7,9,14,26,40};
    int size;
    public:
    deletion(int s){
      size = s;
    }
    void display(){
      for (int i = 0; i < size; i++)
      {
        cout<<arr[i]<<" ";
      }
      cout<<endl;
      
    }
    int dlt(int index){
        for (int i = index ; i < size-1 ; i++)
        {
            arr[i]=arr[i+1];
        }
        size -= 1;    
    
    }
};
int main()
{
    deletion obj(5);
    obj.display();
    obj.dlt(2);
    obj.display();
}