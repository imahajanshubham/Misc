#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

/*Sorting Functions*/
int selectionsort();
void merge(int arr[], int , int , int );
void mergeSort(int arr[], int , int );
void swap(int* a, int* b);
int partition (int arr[], int low, int high);
void quickSort(int arr[], int low, int high);
void printArray(int A[], int size);

/*Anybase to Anybase Conversion*/
int base2dec(int, int);
int dec2base(int, int);

/*Stacks and Queues using Arrays*/
void push();
void pop();
void view();
void insert(int q[],int);
void delet(int q[],int);

/*Stacks and Queues using Linked Lists*/
int frontelement();
void enq(int data);
void deq();
void empty();
void display();
void create();
void queuesize();
int qcount = 0;
struct node
{
    int info;
    struct node *ptr;
}*pfront,*prear,*ptemp,*pfront1;

int stk[40],top=-1;
int b,q[30],k,front=-1,rear=-1,item;

int main()
{
        int j,frombase,tobase,no,value,temp;
        int size,arr[30],c,qno, qch, qe,swap;
        int n,array[30],i,d,t,bubble[100];
        float cur;
        char input[30];
        for(i=0;i<45;i++)
        {
                printf("\n");
        }
        printf("Hey there... \nI'm Eva, your Personal Assistant\nHow can I help?\n\nYou: ");
        fgets(input,30,stdin);
        while(strstr(input,"./Quit")==0)
        {       
                /*Sorting Elements*/
                if(strstr(input,"Sort the Elements"))
                {
                        printf("Eva: How would you like to perform the Sorting?\n");
                        printf("I can use\n");
                        printf("Selection Sort | Insertion Sort | Merge Sort\nQuick Sort | Bubble Sort\n\nYou: ");
                        fgets(input,30,stdin);
                        if(strstr(input,"Selection Sort"))
                        {
                                selectionsort();
                        }
                        else if(strstr(input,"Quick Sort"))
                        {
                                printf("Eva: How many Elements would you like to enter?\n\nYou: ");
                                scanf("%d",&size);
                                printf("Eva: Okie, Now Enter your %d numbers.\n\nYou: ", size);
                 
                                for (c=0;c<size;c++)
                                {
                                    scanf("%d", &arr[c]);
                                }
                                quickSort(arr,0,size-1);
                                printArray(arr,size);
                        }
                        else if(strstr(input,"Bubble Sort"))
                        {
                                printf("Eva: How many elements you would like to enter?\n\nYou: ");
                                scanf("%d", &n);
                                printf("Eva: Great choice! Now, Enter your %d integers.\n\nYou: ", n);
                                for (c=0;c<n;c++)
                                        scanf("%d", &bubble[c]);
                                for (c=0;c<(n-1); c++)
                                {
                                        for (d=0;d<n-c-1;d++)
                                        {
                                                if (bubble[d] > bubble[d+1]) /* For decreasing order use < */
                                                {
                                                        swap = bubble[d];
                                                        bubble[d] = bubble[d+1];
                                                        bubble[d+1] = swap;
                                                }
                                        }
                                }
                                printf("Eva: Here you go -\n");
                                for (c=0;c<n-1;c++)
                                        printf("%d | ", bubble[c]);
                                printf("%d\n\n", bubble[c]);
                        }
                        else if(strstr(input,"Merge Sort"))
                        {
                            printf("Eva: How many Elements would you like to enter?\n\nYou: ");
                            scanf("%d",&size);
                            printf("Eva: Okie, Now Enter your %d numbers.\n\nYou: ", size);
         
                            for (c=0;c<size;c++)
                            {
                                scanf("%d", &arr[c]);
                            }
                            mergeSort(arr,0,size-1);
                            printArray(arr, size);
                        }
                        else if(strstr(input,"Insertion Sort"))
                        {
                                  printf("Eva: How many Elements would you like to enter?\n\nYou: ");
                                  scanf("%d", &n);
                                 
                                  printf("Eva: Okie, Now Enter your %d numbers.\n\nYou: ", n);
                                 
                                  for (c=0;c<n;c++)
                                  {
                                    scanf("%d", &array[c]);
                                  }
                                 
                                  for (c=1;c<=n-1;c++)
                                  {
                                    d = c;
                                 
                                    while ( (d>0) && (array[d]<array[d-1]))
                                    {
                                      t=array[d];
                                      array[d]=array[d-1];
                                      array[d-1]=t;
                                 
                                      d--;
                                    }
                                  }
                                 
                                  printf("Eva: Here you go...\n");
         
                                  for(c=0;c<n-1;c++)
                                      printf("%d | ", array[c]);
                                      printf("%d\n\n",array[c]);
                        }
                        
                        fgets(input,30,stdin);
                }
                /*STACKS using Arrays*/
                else if(strstr(input,"Play with Stacks"))
                {
                        do
                        {
                                        printf("Eva: What would you like to perform?\nInsertion");
                                        printf(" | Deletion | View Stack | Leave\n\nYou: ");
                                        
                                        fgets(input,30,stdin);
                                        
                                if(strstr(input,"Insert an Element"))
                                {
                                        push();
                                }
                                else if(strstr(input,"Delete an Element"))
                                {
                                        pop();
                                }
                                else if(strstr(input,"View the Stack"))
                                {
                                        view();
                                }
                                
                        }while(strstr(input,"./Exit")==0);
                }
                /*QUEUES using Arrays*/
                else if(strstr(input,"Play with Queues"))
                {
                        do
                        {
                                        printf("Eva: What would you like to perform?\nInsertion");
                                        printf(" | Deletion | Leave\n\nYou: ");
                                        
                                        fgets(input,30,stdin);
                                        
                                if(strstr(input,"Insert an Element"))
                                {
                                        insert(q,b);
                                }
                                else if(strstr(input,"Delete an Element"))
                                {
                                        delet(q,b);
                                }
                                
                        }while(strstr(input,"./Exit")==0);
                }
                /*Queues using Linked Lists*/
                else if(strstr(input,"Play with Q Linked Lists"))
                {
                        do
                        {
                                        printf("Eva: What would you like to perform?\nEnque (Create)");
                                        printf(" | Deque (Delete) | Front Element\n | Empty | Display | Queue Size\n\nYou: ");
                                        
                                        fgets(input,30,stdin);
                                        
                                if(strstr(input,"Perform Enque"))
                                {
                                        printf("Eva: Okies,\nEnter the value -\n\nYou: ");
                                        scanf("%d", &qno);
                                        enq(qno);
                                        fgets(input,30,stdin);
                                }
                                else if(strstr(input,"Perform Deque"))
                                {
                                        deq();
                                }
                                else if(strstr(input,"Find The Front Element"))
                                {
                                        qe = frontelement();
                                    if (qe != 0)
                                        printf("Eva: The front element is %d\n", qe);
                                    else
                                        printf("Eva: There is no front element in Queue as Queue is empty.\n");
                                }
                                else if(strstr(input,"Empty the Queue"))
                                {
                                        empty();
                                }
                                else if(strstr(input,"Display the Queue"))
                                {
                                        display();
                                }
                                else if(strstr(input,"Queue Size"))
                                {
                                        queuesize();
                                }
                                
                        }while(strstr(input,"./Exit")==0);
                }
                /*Anybase - Anybase Conversion*/
                else if(strstr(input,"Do Anybase No. Conversion"))
                {
                        printf("Eva: What is your number?\n\nYou: ");
                        scanf("%d",&no);
                        printf("Eva: What is it's Base?\n\nYou: ");
                        scanf("%d",&frombase);
                        printf("Eva: In what Base, should I convert it into?\n\nYou: ");
                        scanf("%d",&tobase);
                        /*The number is an Integer*/
                        if(tobase==10)
                        {
                                value=base2dec(no,frombase);
                        }
                        else
                        {
                                if(frombase==10)
                                {
                                        value=dec2base(no,tobase);
                                }
                                else
                                {
                                        temp=base2dec(no,frombase);
                                        value=dec2base(temp,tobase);
                                }
                        }
                        printf("Eva: Number equals to %d\n\n",value);
                        fgets(input,30,stdin);
                }
                /*Rupee Conversion*/
                else if(strstr(input,"Convert Euro to Rupee"))
                {
                        printf("Eva: How many Euros you would like to convert?\n\nYou: ");
                        scanf("%f",&cur);
                        printf("Eva: %f Euro equals to %f Rupee.\n\n",cur,cur*71.30351);
                        fgets(input,30,stdin);
                }
                else if(strstr(input,"Convert Rupee to Euro"))
                {
                        printf("Eva: How many Rupees you would like to convert?\n\nYou: ");
                        scanf("%f",&cur);
                        printf("Eva: %f Rupee equals to %f Euro.\n\n",cur,cur/71.30351);
                        fgets(input,30,stdin);
                }
                else if(strstr(input,"Convert Dollar to Rupee"))
                {
                        printf("Eva: How many Dollars you would like to convert?\n\nYou: ");
                        scanf("%f",&cur);
                        printf("Eva: %f Dollar equals to %f Rupee.\n\n",cur,cur*67.80800);
                        fgets(input,30,stdin);
                }
                else if(strstr(input,"Convert Rupee to Dollar"))
                {
                        printf("Eva: How many Rupees you would like to convert?\n\nYou: ");
                        scanf("%f",&cur);
                        printf("Eva: %f Rupee equals to %f Dollar.\n\n",cur,cur/67.80800);
                        fgets(input,30,stdin);
                }
                else if(strstr(input,"Convert Yen to Rupee"))
                {
                        printf("Eva: How many Yens you would like to convert?\n\nYou: ");
                        scanf("%f",&cur);
                        printf("Eva: %f Yen equals to %f Rupee.\n\n",cur,cur*0.57925);
                        fgets(input,30,stdin);
                }
                else if(strstr(input,"Convert Rupee to Yen"))
                {
                        printf("Eva: How many Rupees you would like to convert?\n\nYou: ");
                        scanf("%f",&cur);
                        printf("Eva: %f Rupee equals to %f Yen.\n\n",cur,cur/0.57925);
                        fgets(input,30,stdin);
                }
                else if(strstr(input,"Convert Pound to Rupee"))
                {
                        printf("Eva: How many Pounds you would like to convert?\n\nYou: ");
                        scanf("%f",&cur);
                        printf("Eva: %f Pound equals to %f Rupee.\n\n",cur,cur*83.64996);
                        fgets(input,30,stdin);
                }
                else if(strstr(input,"Convert Rupee to Pound"))
                {
                        printf("Eva: How many Rupees you would like to convert?\n\nYou: ");
                        scanf("%f",&cur);
                        printf("Eva: %f Rupee equals to %f Pound.\n\n",cur,cur/83.64996);
                        fgets(input,30,stdin);
                }
                else if(strstr(input,"Convert Franc to Rupee"))
                {
                        printf("Eva: How many Francs you would like to convert?\n\nYou: ");
                        scanf("%f",&cur);
                        printf("Eva: %f Franc equals to %f Rupee.\n\n",cur,cur*66.51103);
                        fgets(input,30,stdin);
                }
                else if(strstr(input,"Convert Rupee to Franc"))
                {
                        printf("Eva: How many Rupees you would like to convert?\n\nYou: ");
                        scanf("%f",&cur);
                        printf("Eva: %f Rupee equals to %f Franc.\n\n",cur,cur/66.51103);
                        fgets(input,30,stdin);
                }
                
                /*Dollar Conversion*/
                if(strstr(input,"Convert Euro to Dollar"))
                {
                        printf("Eva: How many Euros you would like to convert?\n\nYou: ");
                        scanf("%f",&cur);
                        printf("Eva: %f Euro equals to %f Dollar.\n\n",cur,cur*1.05155);
                        fgets(input,30,stdin);
                }
                else if(strstr(input,"Convert Dollar to Euro"))
                {
                        printf("Eva: How many Dollars you would like to convert?\n\nYou: ");
                        scanf("%f",&cur);
                        printf("Eva: %f Dollar equals to %f Euro.\n\n",cur,cur/1.05155);
                        fgets(input,30,stdin);
                }
                else if(strstr(input,"Convert Yen to Dollar"))
                {
                        printf("Eva: How many Yens you would like to convert?\n\nYou: ");
                        scanf("%f",&cur);
                        printf("Eva: %f Yen equals to %f Dollar.\n\n",cur,cur*0.00854);
                        fgets(input,30,stdin);
                }
                else if(strstr(input,"Convert Dollar to Yen"))
                {
                        printf("Eva: How many Dollars you would like to convert?\n\nYou: ");
                        scanf("%f",&cur);
                        printf("Eva: %f Dollar equals to %f Yen.\n\n",cur,cur/0.00854);
                        fgets(input,30,stdin);
                }
                else if(strstr(input,"Convert Pound to Dollar"))
                {
                        printf("Eva: How many Pounds you would like to convert?\n\nYou: ");
                        scanf("%f",&cur);
                        printf("Eva: %f Pound equals to %f Dollar.\n\n",cur,cur*1.23363);
                        fgets(input,30,stdin);
                }
                else if(strstr(input,"Convert Dollar to Pound"))
                {
                        printf("Eva: How many Dollars you would like to convert?\n\nYou: ");
                        scanf("%f",&cur);
                        printf("Eva: %f Dollar equals to %f Pound.\n\n",cur,cur/1.23363);
                        fgets(input,30,stdin);
                }
                else if(strstr(input,"Convert Franc to Dollar"))
                {
                        printf("Eva: How many Francs you would like to convert?\n\nYou: ");
                        scanf("%f",&cur);
                        printf("Eva: %f Franc equals to %f Dollar.\n\n",cur,cur*0.98087);
                        fgets(input,30,stdin);
                }
                else if(strstr(input,"Convert Dollar to Franc"))
                {
                        printf("Eva: How many Dollars you would like to convert?\n\nYou: ");
                        scanf("%f",&cur);
                        printf("Eva: %f Dollar equals to %f Franc.\n\n",cur,cur/0.98087);
                        fgets(input,30,stdin);
                }
                
                /*Pound Conversion*/
                if(strstr(input,"Convert Euro to Pound"))
                {
                        printf("Eva: How many Euros you would like to convert?\n\nYou: ");
                        scanf("%f",&cur);
                        printf("Eva: %f Euro equals to %f Pound.\n\n",cur,cur*0.85173);
                        fgets(input,30,stdin);
                }
                else if(strstr(input,"Convert Pound to Euro"))
                {
                        printf("Eva: How many Pounds you would like to convert?\n\nYou: ");
                        scanf("%f",&cur);
                        printf("Eva: %f Pound equals to %f Euro.\n\n",cur,cur/0.85173);
                        fgets(input,30,stdin);
                }
                else if(strstr(input,"Convert Yen to Pound"))
                {
                        printf("Eva: How many Yens you would like to convert?\n\nYou: ");
                        scanf("%f",&cur);
                        printf("Eva: %f Yen equals to %f Pound.\n\n",cur,cur*0.00692);
                        fgets(input,30,stdin);
                }
                else if(strstr(input,"Convert Pound to Yen"))
                {
                        printf("Eva: How many Pounds you would like to convert?\n\nYou: ");
                        scanf("%f",&cur);
                        printf("Eva: %f Pound equals to %f Yen.\n\n",cur,cur/0.00692);
                        fgets(input,30,stdin);
                }
                else if(strstr(input,"Convert Franc to Pound"))
                {
                        printf("Eva: How many Francs you would like to convert?\n\nYou: ");
                        scanf("%f",&cur);
                        printf("Eva: %f Franc equals to %f Pound.\n\n",cur,cur*0.79448);
                        fgets(input,30,stdin);
                }
                else if(strstr(input,"Convert Pound to Franc"))
                {
                        printf("Eva: How many Pounds you would like to convert?\n\nYou: ");
                        scanf("%f",&cur);
                        printf("Eva: %f Pound equals to %f Franc.\n\n",cur,cur/0.79448);
                        fgets(input,30,stdin);
                }
                
                /*Euro Conversion*/
                else if(strstr(input,"Convert Yen to Euro"))
                {
                        printf("Eva: How many Yens you would like to convert?\n\nYou: ");
                        scanf("%f",&cur);
                        printf("Eva: %f Yen equals to %f Euro.\n\n",cur,cur*0.00812);
                        fgets(input,30,stdin);
                }
                else if(strstr(input,"Convert Euro to Yen"))
                {
                        printf("Eva: How many Euros you would like to convert?\n\nYou: ");
                        scanf("%f",&cur);
                        printf("Eva: %f Euro equals to %f Yen.\n\n",cur,cur/0.00812);
                        fgets(input,30,stdin);
                }
                else if(strstr(input,"Convert Franc to Euro"))
                {
                        printf("Eva: How many Francs you would like to convert?\n\nYou: ");
                        scanf("%f",&cur);
                        printf("Eva: %f Franc equals to %f Euro.\n\n",cur,cur*0.93193);
                        fgets(input,30,stdin);
                }
                else if(strstr(input,"Convert Euro to Franc"))
                {
                        printf("Eva: How many Euros you would like to convert?\n\nYou: ");
                        scanf("%f",&cur);
                        printf("Eva: %f Euro equals to %f Franc.\n\n",cur,cur/0.93193);
                        fgets(input,30,stdin);
                }
                
                /*Franc Conversion*/
                else if(strstr(input,"Convert Yen to Franc"))
                {
                        printf("Eva: How many Yens you would like to convert?\n\nYou: ");
                        scanf("%f",&cur);
                        printf("Eva: %f Yen equals to %f Franc.\n\n",cur,cur*0.00870);
                        fgets(input,30,stdin);
                }
                else if(strstr(input,"Convert Franc to Yen"))
                {
                        printf("Eva: How many Francs you would like to convert?\n\nYou: ");
                        scanf("%f",&cur);
                        printf("Eva: %f Franc equals to %f Yen.\n\n",cur,cur/0.00870);
                        fgets(input,30,stdin);
                }
                else if(strstr(input,"What Time is it right now?"))
                {
                        time_t rawtime;
                        struct tm *info;
                        char buffer[80];
                        time(&rawtime);
                        info=localtime(&rawtime);
                        printf("Eva: Right Now?\nIt's ");
                        strftime(buffer, 80,"%I:%M %p",info);
                        printf("%s.",buffer);
                        printf("\n\n");
                }
                else if(strstr(input,"What Date is Today?"))
                {
                        time_t rawtime;
                        struct tm *info;
                        char buffer[80];
                        time(&rawtime);
                        info=localtime(&rawtime);
                        printf("Eva: Today,\nIt's ");
                        strftime(buffer, 80,"%x",info);
                        printf("%s.",buffer);
                        printf("\n\n");
                }
                else if(strstr(input,"./Shut Down"))
                {
                        system("shutdown -P now");
                }
                else if(strstr(input,"Hello Eva!"))
                {
                        printf("Eva: Hello friend :)\n\n");
                }
                else if(strstr(input,"What Place is this?"))
                {
                        printf("Eva: This is Advance Programming Lab,\n");
                        printf("ITS Engg College,\n");
                        printf("Greater Noida.\n\n");
                }
                else if(strstr(input,"Who is Neha Ma'am?"))
                {
                        printf("Eva: Shame on you!!!\n");
                        printf("How come you are still in 2nd Year?\n");
                        printf("Gooo... Look in your Time-Table (^^)\n\n");
                }
                else if(strstr(input,"Who are you?"))
                {
                        time_t rawtime;
                        struct tm *info;
                        char buffer[80];
                        time(&rawtime);
                        info=localtime(&rawtime);
                        printf("Eva: PURE IMAGINATION\n");
                        printf("That's what I would call it...\n");
                        printf("I was executed by Ubuntu.\n");
                        printf("I was born on ");     
                        strftime(buffer, 80,"%x - %I:%M %p",info);
                        printf("%s.",buffer);
                        printf("\n\n");
                }
                else if(strstr(input,"What can you do?"))
                {
                        printf("Eva: I've been programmed to\n\n");
                        printf("1. Shut Down - <./Shut Down>\n");
                        printf("2. Quit the Program - <./Quit>\n");
                        printf("3. Sort elements (Insertion, Selection and Merge Sort) - <Sort Elements>\n");
                        printf("4. Convert a No. from one Base to another - <Do Anybase No. Conversion>\n");
                        printf("5. Convert Currency (Euro, Rupee, Dollar, Franc and Yen) - <Convert (FROM) to (TO)>\n");
                        printf("6. Show Time - <What Time is it right now?>\n");
                        printf("7. Show Date - <What Date is Today?>\n");
                        printf("8. Play Chat-Chat :) - \n<Hello Eva!> | <What Place is this?> | <Who is Neha Ma'am?>\n");
                        printf("<Who is Neha Ma'am?> | <Who are you?> | <What can you do?>\n\n");
                        
                }
                printf("You: ");
                fgets(input,30,stdin);
        }
}

int selectionsort()
{
           int array[100], n, c, d, position, swap;
         
           printf("Eva: How many numbers you would like to Sort?\n\nYou: ");
           scanf("%d", &n);
         
           printf("Eva: Okie, Now Enter your %d numbers.\n\nYou: ", n);
         
           for (c=0;c<n;c++)
              scanf("%d", &array[c]);
         
           for (c=0;c<(n-1);c++)
           {
              position=c;
         
              for ( d=c+1;d<n;d++)
              {
                 if (array[position]>array[d])
                    position=d;
              }
              if (position!=c)
              {
                 swap=array[c];
                 array[c]=array[position];
                 array[position]=swap;
              }
           }
         
           printf("Eva: Here you go...\n");
         
           for (c=0;c<n-1;c++)
              printf("%d | ", array[c]);
              printf("%d\n\n",array[c]);
         
           return 0;
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    int L[n1], R[n2];
 
    for (i=0;i<n1;i++)
        L[i]=arr[l+i];
    for (j=0;j<n2;j++)
        R[j]=arr[m+1+j];
 
    i = 0;
    j = 0;
    k = l;
    while (i<n1&&j<n2)
    {
        if(L[i]<=R[j])
        {
            arr[k]=L[i];
            i++;
        }
        else
        {
            arr[k]=R[j];
            j++;
        }
        k++;
    }

    while (i<n1)
    {
        arr[k]=L[i];
        i++;
        k++;
    }

    while (j<n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l<r)
    {

        int m = l+(r-l)/2;
 
        // Sort first and second halves
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
 
        merge(arr,l,m,r);
    }
}
 

void printArray(int A[], int size)
{
    int i;
    printf("Eva: Here you go...\n");
    for(i=0;i<size-1;i++)
        printf("%d | ",A[i]);
    printf("%d\n\n",A[i]);
}

int base2dec(int no, int frombase)
{
        int k,op,s,p;
        op=0;
        k=no;
        p=1;
        while(k!=0)
        {
                s=k%10;
                k=k/10;
                op=op+s*p;
                p=p*no;
        }
        
        return op;
}
int dec2base(int value, int tobase)
{
        int k,op,s,p;
        op=0;
        k=value;
        p=1;
        while(k!=0)
        {
                s=k%tobase;
                k=k/tobase;
                op=op+s*p;
                p=p*10;
        }
        
        return op;
}

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
 
    for (int j = low; j <= high- 1; j++)
    {

        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {

        int pi = partition(arr, low, high);
 
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void push()
{
        int item,i;
        if(top==40-1)
        {
                printf("Eva: Tummy is full, Can't store anymore :(\n");
        }
        else
        {
                printf("Eva: What's in store for me Today?\n\nYou: ");
                scanf("%d",&item);
                stk[++top]=item;
        }
}

void pop()
{
        int i;
        if(top==-1)
        {
                printf("Eva: There's nothing in Inventory, Can't Delete.\n");
        }
        else
        {
                printf("Eva: Okies, Element moved to Trash :)\n");
                top=top-1;
        }
}

void view()
{
        int i;
        if(top==-1)
        {
                printf("Eva: Nothing for you in Inventory.\n");
        }
        else
        {
                printf("Eva: Here's your Inventory -\n");
                for(i=0;i<top;i++)
                        printf(" %d |",stk[i]);
                printf(" %d\n",stk[top]);
        }
}

void insert(int q[],int item)
{
        if(rear+1<30)
        {
                printf("Eva: Enter the element for the Queue -\n\nYou: ");
                scanf("%d",&item);
                if((front==-1)&&(rear==-1))
                {
                        rear=0;
                        front=0;
                }
                else
                {
                        rear=rear+1;
                }
                q[rear]=item;
                printf("Here's your Queue -\n");
                for(k=front;k<rear;k++)
                {
                        printf("%d | ",q[k]);
                }
                printf(" %d\n",q[rear]);
        }
        else
        {
                printf("Eva: Tummy is full, Can't store anymore :(\n");
        }
}

void delet(int q[],int item)
{
        if(front!=-1)
        {
                item=q[front];
                if(front==rear)
                {
                        front=-1;
                        rear=-1;
                }
                else
                {
                        front=front+1;
                }
                printf("Eva: Okies, Element moved to Trash :)\n");
                printf("Here's your Queue -\n");
                for(k=front;k<rear;k++)
                {
                        printf("%d | ",q[k]);
                }
                printf(" %d\n",q[rear]);
        }
        else
        {
        printf("Eva: Inventory is Empty.\n");
        }
}

void create()
{
    pfront = prear = NULL;
}

void queuesize()
{
    printf("Eva: The Queue is %d units long!!!\n", qcount);
}

void enq(int data)
{
    if (prear == NULL)
    {
        prear = (struct node *)malloc(sizeof(struct node));
        prear->ptr = NULL;
        prear->info = data;
        pfront = prear;
    }
    else
    {
        ptemp=(struct node *)malloc(sizeof(struct node));
        prear->ptr = ptemp;
        ptemp->info = data;
        ptemp->ptr = NULL;
 
        prear = ptemp;
    }
    qcount++;
}

void display()
{
    pfront1 = pfront;
 
    if ((pfront1 == NULL) && (prear == NULL))
    {
        printf("Eva: The Queue is empty.\n");
        return;
    }
    while (pfront1 != prear)
    {
        printf("%d | ", pfront1->info);
        pfront1 = pfront1->ptr;
    }
    if (pfront1 == prear)
        printf("%d", pfront1->info);
    printf("\n");
}

void deq()
{
    pfront1 = pfront;
 
    if (pfront1 == NULL)
    {
        printf("Eva: The Queue is empty.\n");
        return;
    }
    else
        if (pfront1->ptr != NULL)
        {
            pfront1 = pfront1->ptr;
            printf("Eva: Dequed value : %d\n", pfront->info);
            free(pfront);
            pfront = pfront1;
        }
        else
        {
            printf("Eva: Dequed value : %d\n", pfront->info);
            free(pfront);
            pfront = NULL;
            prear = NULL;
        }
        qcount--;
}

int frontelement()
{
    if ((pfront != NULL) && (prear != NULL))
        return(pfront->info);
    else
        return 0;
}

void empty()
{
     if ((pfront == NULL) && (prear == NULL))
        printf("Eva: The Queue is now empty.\n");
    else
       printf("Eva: The Queue is not empty.\n");
}
