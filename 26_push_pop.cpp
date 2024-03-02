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
int main(){
    struct stack *s = new (stack);
    s->size=8;
    s->top=-1;
    s->arr = new int(s->size); 
    cout<<"Before Pushing"<<endl;
    cout<<isfull(s)<<endl;
    cout<<isempty(s)<<endl;
    cout<<"After Pushing"<<endl;
    push(s,6);
    push(s,7);
    push(s,15);
    push(s,8);
    push(s,12);
    push(s,34);
    push(s,40);
    push(s,34);
    cout<<isfull(s)<<endl;
    cout<<isempty(s)<<endl;
    
    pop(s);
    pop(s);
}