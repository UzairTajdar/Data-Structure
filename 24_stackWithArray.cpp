#include<iostream>
using namespace std;

struct stack{
    int top ;
    int size;
    int * arr;
};
int emptyStack(struct stack * ptr){
    if(ptr->top==-1){
        return 1;
    }
    else{
      return 0;
    }
}
int fullStack(struct stack * ptr){
    if(ptr->top == ptr->size-1){
        return 1;
    }
    else{
      return 0;
    }
}

int main(){
    struct stack *s = new (stack);
    s->size=6;
    s->top=-1;
    s->arr = new int(s->size);
    // Pushing Element  
    s->arr[0]=7;
    s->top++;

    if(emptyStack(s)){
        cout<<"Stack is empty"<<endl;
    }
    else{
        cout<<"Stack is not empty";
    }
    
}