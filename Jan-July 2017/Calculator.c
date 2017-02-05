/*Command line calculator using C Language :D*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/*This function will seperate out the operators and operands (no.s) from
the string and put them into two different STACKS using Doubly-Linked Lists.*/
void createstack();

/*When createstack() has created two different STACKS, this function will traverse from start
in stack[] string till end, it will read the operators and asks perform() to do the matching operation
on the two values. Plus, It will also look for braces, if encountered, first those operations inside it
are performed.*/
void traverse();

/*This function will simply perform the mathematical operations on the values
stored inside the Doubly-Linked Lists.*/
void perform();

/*This function will delete the contents of stack[] one-by-one as soon as their operation has been done.*/
void delete();

/*Structure named "node" used to create Doubly-Linked Lists containing
two pointers (one to store link of previous and another to store the link of the
next node) and a variable named "operand" to store float value to be operated on later.*/
struct node
{
        struct node *prev;
        double operand;
        struct node *next;
}*front,*del,*temp,*new;

/*Global Variables.
1. input[100] - takes the input expression from the user innitially.
2. stack[100] - stores only operators (^,/,*,+,-) and braces in their original order.
3. value[75] - stores only no. from input[] string in char form.*/
int i,j,k,l,x,pos,y,count;
char input[100],stack[100],value[75];

int main()
{
        /*Getting the expression in the form of string from the user.*/
        printf("Me: ");
        fgets(input,100,stdin);
        
        /*Calling the function to seperate out the no. and operators.*/
        createstack();
        
        /*Calling the function to perform the operations on operators and operands.*/
        traverse();
        
        temp=front;
        printf("Eva: Answer equals to - ");
        printf("%.10f",front->operand);
        printf("\n");
        
        return 0;
}

void createstack()
{
        i=j=k=l=0;
        /*STACK starts with '('.*/
        stack[j]='(';
        j++;
        
        while(input[i]!='\0')
        {
                if((input[i]=='(') || (input[i]=='/') || (input[i]=='*') || (input[i]=='+') || (input[i]=='-') || (input[i]=='^') || (input[i]==')'))
                {
                        /*Sperate string named STACK stores only operators and braces in
                        their original order to perform operations accordingly later.*/
                        stack[j]=input[i];
                        
                        /*Nodes are created only when any of the five operators are encountered. At this time,
                        Temporary string value[] holding the no. in char form is converted to it's equivalent float
                        value using atof() and stored in the respective node.*/
                        if((stack[j]=='/') || (stack[j]=='*') || (stack[j]=='+') || (stack[j]=='-') || (stack[j]=='^'))
                        {
                                /*If the list is empty.*/
                                if(front==NULL)
                                {
                                        new=(struct node*)malloc(sizeof(struct node));
                                        new->prev=NULL;
                                        new->operand=atof(value);
                                        new->next=NULL;
                                        front=new;
                                        temp=new;
                                }
                                /*If the list is not empty, new node is created and it's linked
                                after the previous node... just like in STACKS.*/
                                else
                                {
                                        new=(struct node*)malloc(sizeof(struct node));
                                        new->prev=temp;
                                        temp->next=new;
                                        new->operand=atof(value);
                                        new->next=NULL;
                                        temp=new;
                                }
                                /*As, the no. in char form has been converted and stored in float form in the new node...
                                So, emptying or simply setting value[] string to '\0' so that new no. can be stored from start.*/
                                value[0]='\0';
                                k=0;
                                l++;
                        }
                        j++;
                }
                else
                {
                        /*Temporary string continuously stores only the no. (integer/float)
                        seperated out from input[] string. Later on, this string is then converted
                        into it's equivalent float value using atof().*/
                        value[k]=input[i];
                        k++;
                }
                i++;
        }
        
        /*Creating the node for last float/integer value.*/
        new=(struct node*)malloc(sizeof(struct node));
        new->prev=temp;
        temp->next=new;
        new->operand=atof(value);
        new->next=NULL;
        temp=new;
        l++;
              
        /*Expression ends with ')'.*/   
        i--;                                                                                                      
        stack[j]=')';
        input[i]=')';
}

void traverse()
{
        /*Checking if the user used any braces or not.*/
        i=count=0;
        while(stack[i]!='\0')
        {
                if(stack[i]==')')
                {
                        count++;
                }
                i++;
        }
        /*If the user didn't used any Braces... then simply solving the expression.*/
        if(count==1)
        {
                i=0;
                while(stack[i]!='\0')
                {
                        if((stack[i]=='/') || (stack[i]=='*') || (stack[i]=='+') || (stack[i]=='-') || (stack[i]=='^'))
                        {
                                pos++;
                                /*First, evaluating only Power/Divide/Multiply operators due to their higher priority.*/
                                while(stack[i]!=')')
                                {
                                        if((stack[i]=='/') || (stack[i]=='*') || (stack[i]=='^'))
                                        {
                                                perform();
                                                delete();
                                        }
                                        else
                                        {
                                                i++;
                                                pos++;
                                        }
                                }
                                /*Going back to fist operator.*/
                                while(stack[i-1]!='(')
                                {
                                        i--;
                                        pos--;
                                }
                                /*Now, again evaluating for Addition or Subtraction due to their lower priority.*/
                                while(stack[i]!=')')
                                {
                                        if((stack[i]=='+') || (stack[i]=='-'))
                                        {
                                                perform();
                                                delete();
                                        }
                                        else
                                        {
                                                i++;
                                                pos++;
                                        }
                                }
                        }
                        i++;
                }
        }
        /*If the user used any no. of braces, then solving according to priority of the braces.*/
        else
        {
                i=j=k=l=pos=0;
                while(stack[i]!='\0')
                {
                        if((stack[i]=='/') || (stack[i]=='*') || (stack[i]=='+') || (stack[i]=='-') || (stack[i]=='^'))
                        {
                                pos++;
                                if(stack[i+1]==')')
                                {
                                        while(stack[i-1]!='(')
                                        {
                                                i--;
                                                pos--;
                                        }
                                        /*First, evaluating only Power/Divide/Multiply operators due to their higher priority.*/
                                        while(stack[i]!=')')
                                        {
                                                if((stack[i]=='/') || (stack[i]=='*') || (stack[i]=='^'))
                                                {
                                                        perform();
                                                        delete();
                                                }
                                                else
                                                {
                                                        i++;
                                                        pos++;
                                                }
                                        }
                                        /*Going back to fist operator.*/
                                        while(stack[i-1]!='(')
                                        {
                                                i--;
                                                pos--;
                                        }
                                        /*Now, again evaluating for Addition or Subtraction due to their lower priority.*/
                                        while(stack[i]!=')')
                                        {
                                                if((stack[i]=='+') || (stack[i]=='-'))
                                                {
                                                        perform();
                                                        delete();
                                                }
                                                else
                                                {
                                                        i++;
                                                        pos++;
                                                }
                                        }
                                        /*CASE - When expression becomes like a/b()+1... the empty braces needs to be removed out from the stack.*/
                                        if(stack[i]==')')
                                        {
                                                i--;
                                                delete();
                                                delete();
                                                if(pos!=0)
                                                {
                                                        while(stack[i]!='(')
                                                        {
                                                                i--;
                                                                pos--;
                                                        }
                                                }
                                        }
                                }
                        }
                        i++;
                }
        }
}

void perform()
{
        temp=front;
        for(x=1;x<pos;x++)
        {
                temp=temp->next;
        }

        switch(stack[i])
        {
                case '^':
                        temp->operand=pow(temp->operand,temp->next->operand);
                        break;
                case '/':
                        temp->operand=temp->operand/temp->next->operand;
                        break;
                case '*':
                        temp->operand=temp->operand*temp->next->operand;
                        break;
                case '+':
                        temp->operand=temp->operand+temp->next->operand;
                        break;
                case '-':
                        temp->operand=temp->operand-temp->next->operand;
                        break;
        }
        temp->next=temp->next->next;
}

void delete()
{
        y=i;
        while(stack[y+1]!='\0')
        {
                stack[y]=stack[y+1];
                y++;
        }
        stack[y]='\0';
}
