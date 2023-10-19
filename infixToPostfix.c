#include <stdio.h>
#include <ctype.h>  /* for isdigit */
#include <string.h> /* for strncmp */

/* Stack structure definition */
#define SIZE 50
char stack[SIZE];
int top = -1;

/* Function to push characters into stack */
void push(char item) 
{
    if(top >= SIZE-1)
    {
        printf("\nStack Overflow.");
    } 
    else 
    {
        stack[++top] = item;
    }
}

/* Function to remove or pop elements from stack */
char pop() 
{
    char item;

    if(top <0)
    {
        printf("Stack underflow.");
        return 0;
    }
    else 
    {
        item = stack[top--];
        return(item);
    }
}

/* Function to define the precedence of operators */
int is_operator(char symbol) 
{
    switch(symbol)
    {
        case '^':
        case '*':
        case '/':
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}

/* Function to convert infix to postfix notation */
void infix_to_postfix(char infix_exp[], char postfix_exp[]) 
{
    int i, j;
    char item;
    char x;

    i=0;
    j=0;
    item=infix_exp[i++];
  
   /* Continues until the end of the infix expression */
   while(item != '\0') 
    {
        switch(item)
        {
            case '(': 
                push(item);
                break;
            case ')':
                while((x = pop()) != '(')
                    postfix_exp[j++] = x;
                break;
            case '^': case '*': case '/': case '+': case '-':
                while(is_operator(stack[top]) >= is_operator(item))
                    postfix_exp[j++] = pop();
                push(item);
                break;
            default:
                postfix_exp[j++] = item;
        }

        item = infix_exp[i++]; 
    }

    /* Pop remaining elements from stack */
    while(top>-1)
    {
        postfix_exp[j++] = pop();
    }

    /* End postfix expression with '\0' to signify end of string */
    postfix_exp[j] = '\0'; 
}

/* Main function */
int main()
{
    char infix[SIZE], postfix[SIZE]; /declare infix string and postfix string/

   /* Take input of infix expression */
    printf("\nEnter Infix expression : ");
    gets(infix);

    infix_to_postfix(infix,postfix); /* call to function */
    
    /* Output of postfix expression */
    printf("Postfix Expression: ");
    puts(postfix);

    return 0;
}
