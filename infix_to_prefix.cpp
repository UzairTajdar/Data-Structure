#include<iostream>
#include<conio.h>
#include<ctype.h>
#include<string.h>
using namespace std;

char*reverse(char *);
int priority(char);

class infix_to_prefix{
    char stack[20];
    int top;
    public:
    infix_to_prefix(){top=-1;};
    void scan(char[]);
    void push(char);
    char pop();

};

char *reverse(char *exp){
     char temp[100],temp_stk[100],i,j,t=-1;
     for (i = 0; exp[i]!='\0'; i++)
     {
       t++;
       temp_stk[t] = exp[i];
     }
     for (i=t,j=0; i>=0; i--,j++)
       temp[j] = temp_stk[i];     
     temp[j]='\0';
     
     return temp;
}

void infix_to_prefix::push(char x){
    top++;
    stack[top] = x;
}
char infix_to_prefix::pop(void){
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

void infix_to_prefix::scan(char exp[]){
      char ch,output[80],temp,rev_output[100];
      int c = 0;
      for (int i = 0; exp[i]!='\0'; i++)
      {
        
        ch = exp[i];
        if (isalpha(ch)||isdigit(ch))
        {
            output[c] = ch;
             c++;
        }
        else if (ch==')')
        {
            push(ch);
        }
        else if (ch=='(')
        {
            temp = pop();
            while (temp!=')')
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
       int j;      
       for (int j = c; top>=0; j++){
        output[j]=pop();
       }
    output[j] = '\0';

    strcpy(rev_output,reverse(output));
    cout << "Prefix expression = " << rev_output << endl;
      
}


int main(){
  infix_to_prefix obj;
  char exp[100];
  char rev_exp[100];
  cout<<"Enter infix expression without spcae :";
  cin>>exp;

  strcpy(rev_exp,reverse(exp));
  obj.scan(exp);
}