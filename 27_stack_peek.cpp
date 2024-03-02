#include<iostream>
using namespace std;

struct stack {
    int top;
    int size;
    int *arr;
};
int isempty(struct stack * ptr){
    if(ptr->top==-1){
        return 1;
    }
    else
    {
        return 0;
    }
}
int isfull(struct stack * ptr){
    if(ptr->top == ptr->size-1){
        return 1;
    }
    else 
    {
        return 0;
    }
};

void push(struct stack * ptr ,int val){
    if(isfull(ptr)){
        cout<<"Stack is Overflow. Can't push at "<<val<<endl;
    }
    else
    {
        ptr->top ++;
        ptr->arr[ptr->top] =val;

    }
}

 int pop(struct stack * ptr ){
    if(isempty(ptr)){
        cout<<"Stack is underflow."<<endl;
        return -1;
    }
    else
    {
        int val;
        val = ptr->arr[ptr->top];
        ptr->top=ptr->top -1;
        cout<<"Pop value is "<<val<<endl;

    }
}

int peek(struct stack * ptr , int i){
    int formula = ptr->top - i + 1;
    if(formula<0){
        cout<<"Not a valid position in stack"<<endl;
        return -1;
    }else
    {
        return ptr->arr[formula];
    }
}
int main(){
    struct stack *s = new (stack);
    s->size=20;
    s->top=-1;
    s->arr = new int(s->size); 

    push(s,6);
    push(s,7);
    push(s,15);
    push(s,8);
    push(s,12);
    push(s,34);
    push(s,40);
    push(s,34);
    

    // Peek operation
   for (int j = 1; j <= s->top + 1; j++)
   {
    cout<<"The Value at given position "<<j<<" is "<< peek(s,j)<<endl;
   }
}