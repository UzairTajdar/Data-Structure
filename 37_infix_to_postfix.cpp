#include<iostream>
using namespace std;

struct stack {
    int top;
    int size;
    char *arr;
};

int stackTop(struct stack * sp){
    return sp->arr[sp->top];
}

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
        return val;
    }
};

int isOperator(char ch){
    if (ch=='+' || ch=='-' || ch=='*'|| ch=='/')
    {
        return 1;
    }else{
        return 0;
    }
    
};
int precedence(char ch){
    if (ch=='*'|| ch=='/')
    {
        return 2;
    }
    else if (ch=='+'|| ch=='-')
    {
        return 1;
    }
    else{
        return 0;
    }
    
};


char * infixToPostfix (char * infix){
    struct stack * s =new(stack);
    s->size=25;
    s->top=-1;
    s->arr = new char[s->size];
    char *postfix = new char(s->size+1);
    int i = 0;
    int j = 0;
    while (infix[i]!='\0')
    {
        if (!isOperator(infix[i]))
        {
            postfix[j] =infix[i];
            i++;
            j++;
        }
        else {
            if
            (!isempty(s) && precedence(infix[i]) <= precedence(stackTop(s))) {
            postfix[j] = pop(s);
            j++;
        }else{
        if (infix[i] == ')') {
                    while (stackTop(s) != '(') {
                        postfix[j] = pop(s);
                        j++;
                    }
                    pop(s); // Pop '('
                } else {
                    push(s, infix[i]);
                }
                i++;
        }
        }
        
    }
    while(!isempty(s)){
        postfix[j]=pop(s);
        j++;
    }
    postfix[j]='\0';
    return postfix;
    
};
int main()
{

    char  infix[] = "4*9/((3-5)+8)-7+2";
    cout<<"The postfix is "<<infixToPostfix(infix)<<endl;

}
