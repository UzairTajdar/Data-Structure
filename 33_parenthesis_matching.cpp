#include<iostream>
using namespace std;

struct stack {
    int top;
    int size;
    char *arr;
};
char isempty(struct stack * ptr){
    if(ptr->top==-1){
        return 1;
    }
    else
    {
        return 0;
    }
}
char isfull(struct stack * ptr){
    if(ptr->top == ptr->size-1){
        return 1;
    }
    else 
    {
        return 0;
    }
};

void push(struct stack * ptr ,char val){
    if(isfull(ptr)){
        cout<<"Stack is Overflow. Can't push at "<<val<<endl;
    }
    else
    {
        ptr->top ++;
        ptr->arr[ptr->top] =val;

    }
}
char pop(struct stack * ptr ){
    if(isempty(ptr)){
        cout<<"Stack is underflow."<<endl;
        return -1;
    }
    else
    {
        char val;
        val = ptr->arr[ptr->top];
        ptr->top=ptr->top -1;
        // cout<<"Pop value is "<<val<<endl;

    }
}

char match(char a,char b){
    if (a=='['&&b==']')
    {
        return 1;
    }
    if (a=='{'&&b=='}')
    {
        return 1;
    }
    if (a=='('&&b==')')
    {
        return 1;
    }
    return 0;
    
}
int parenthesis (char* exp){
    struct stack * s =new(stack);
    s->size=100;
    s->top=-1;
    s->arr = new char(s->size);
    for (int i = 0; exp[i]!='\0'; i++)
    {
        if (exp[i]=='('|| exp[i]=='{' || exp[i]=='[')
        {
           push(s,exp[i]);
        }
        else if(exp[i]==')'|| exp[i]=='}' || exp[i]==']')
        {
            if (isempty(s))
            {
                return 0;
            }
            char popped_item;
            popped_item=pop(s);
            if (match(popped_item,exp[i]))
            {
                return 1;
            }
            
            
        }
        
        
    }
    if (isempty(s))
    {
       return 1;
    }
    else{
    return 0;
    }
    
}
int main()
{

    char exp[] = "{3*64{()} ([7*]7)}";

    if (parenthesis(exp))
    {
        cout<<"The parenthesis are balanced"<<endl;
    }
    else
        cout<<"The parenthesis are not balanced"<<endl;
    return 0;
}
