#include<iostream>
#include<conio.h>
#include<ctype.h>
using namespace std;

class infix_to_postfix{
    char stack[20];
    int top;
    public:
    infix_to_postfix(){top=-1;};
    void scan(char[]);
    void push(char);
    char pop();

};

void infix_to_postfix::push(char x){
    top++;
    stack[top] = x;
}
char infix_to_postfix::pop(void){
    char r;
    r =stack[top];
    top--;
    return r;
}
int priority(char op){
    switch (op)
    {
    case '^':return 4; break;
    case '*':
    case '/':return 3; break;
    case '+':
    case '-':return 2; break;    
    default: return 0;
        break;
    }
}

void infix_to_postfix::scan(char exp[]){
      char ch,output[80],temp;
      int c = 0;
      for (int i = 0; exp[i]!='\0'; i++)
      {
        
        ch = exp[i];
        if (isalpha(ch)||isdigit(ch))
        {
            output[c] = ch;
             c++;
        }
        else if (ch=='(')
        {
            push(ch);
        }
        else if (ch==')')
        {
            temp = pop();
            while (temp!='(')
            {
                output[c]=temp;
                c++;
                temp = pop();
            }            
        }
        else if (ch=='^' ||ch=='*'||ch=='+'||ch=='-'||ch=='/')
        {
            if (top==-1)
            {
                push(ch);
            }
            else{
                int op_prec;
                op_prec = priority(ch);
                while (priority(stack[top])>= op_prec && top!=-1)
                {
                    temp = pop();
                    output[c] = temp;
                    c++;
                }
                push(ch);
                
            }
            
        } 
      }
       while (top >= 0) {
        output[c] = pop();
        c++;
    }
    output[c] = '\0';
    cout << "Postexpression = " << output << endl;
      
}


int main(){
  infix_to_postfix obj;
  char exp[100];
  cout<<"Enter infix expression without spcae :";
  cin>>exp;
  obj.scan(exp);
}