	// Header Files.

#include "time.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

	// Macros.

#define MAXLEN      150

#define RESET       0
#define BRIGHT      1
#define DIM         2
#define UNDERLINE   3
#define BLINK       4
#define REVERSE     7
#define HIDDEN      8

#define BLACK       0
#define RED         1
#define GREEN       2
#define YELLOW      3
#define BLUE        4
#define MAGENTA     5
#define CYAN        6
#define WHITE       7

#define ANSI_COLOR_RESET   "\x1b[0m"

	// Functions.
		// 1. Sorting.

int selectionsort();
void merge(int arr[], int , int , int );
void mergeSort(int arr[], int , int );
void swap(int* a, int* b);
int partition (int arr[], int low, int high);
void quickSort(int arr[], int low, int high);
void printArray(int A[], int size);

		// 2. Anybase to anybase conversion.

int base2dec(int, int);
int dec2base(int, int);
void push();
void pop();
void view();
void insert(int q[],int);
void delet(int q[],int);

		// 3. Stacks n Queues using linked lists.

int frontelement();
void enq(int data);
void deq();
void empty();
void display();
void create();
void queuesize();
int qcount = 0;


	// Structures.

struct node
{
    int info;
    struct node *ptr;
}*pfront, *prear, *ptemp, *pfront1;


int stk[40], top = -1;
int b, q[30], k, front = -1, rear = -1, item;









    // UI Boxes.

void textcolor( int attr, int fg, int bg )
{   
    char command[13];

    sprintf(command, "%c[%d;%d;%dm", 0x1B, attr, fg + 30, bg + 40);
    printf("%s", command);
}





void printErrorUIBoxes( int limit )
{
    static int count;

    for( count = 0; count < limit; count++ ) {
        printf( " " );
    }

    printf( "\033[0m\n" );
}


void printErrorUIBoxesTag()
{
    textcolor(BRIGHT, WHITE, WHITE);
    printf( " \033[0m" );
    textcolor(BRIGHT, WHITE, MAGENTA);
}


void printUIBoxes( int limit )
{
    static int count;

    for( count = 0; count < limit; count++ ) {
        printf( " " );
    }

    printf( "\033[0m\n" );
} 

void printMeHeader()
{
    printf( "\033[0m\n" );
    textcolor(BRIGHT, BLUE, BLUE);
    printf( " " );
    printf("\033[0;0m" );
}

void printUIBoxesTag()
{
    textcolor(BRIGHT, MAGENTA, MAGENTA);
    printf( " \033[0m" );
    textcolor(BRIGHT, BLACK, WHITE);
}






	// Sending an Email.

char usrEmail[ MAXLEN ], usrSubject[ MAXLEN ], usrMessage[ MAXLEN ], emailCmnd[ MAXLEN ];

void sendEmailQuerry()
{
	system( emailCmnd );
    printUIBoxesTag();
    printUIBoxes( 25 );

    printUIBoxesTag();
    printUIBoxes( 25 - printf("  Eva: Message sent! " ) );

    printUIBoxesTag();
    printUIBoxes( 25 );
}


void generateMailSendCommand()
{
	strcat( emailCmnd, "echo \"" );
	strcat( emailCmnd, usrMessage );
	strcat( emailCmnd, "\" | mutt \"" );
	strcat( emailCmnd, usrEmail );
	strcat( emailCmnd, "\" -s \"" );
	strcat( emailCmnd, usrSubject );
	strcat( emailCmnd, "\"" );
}


void getEmailMessage()
{
	printf( "       " );
    textcolor(BRIGHT, BLACK, GREEN);
    printf(" Message \033[0;0m " );
	fgets( usrMessage, MAXLEN, stdin );
    printf( "\n" );
}


void getEmailSubject()
{
    printf( "       " );
    textcolor(BRIGHT, BLACK, GREEN);
    printf(" Subject \033[0;0m " );
	fgets( usrSubject, MAXLEN, stdin );
    printf( "\n" );
}


void getEmailAddress()
{
    printUIBoxesTag();
    printUIBoxes( 40 );

    printUIBoxesTag();
    printUIBoxes( 40 - printf("  Eva: Sure, fill the details please :) " ) );

    printUIBoxesTag();
    printUIBoxes( 40 );


	printMeHeader();
    printf( "  Me: ");

    printf( "     " );
    textcolor(BRIGHT, BLACK, GREEN);
    printf(" To \033[0;0m " );
	fgets( usrEmail, MAXLEN, stdin );
    printf( "\n" );
}


void initiateMailSendProcedure()
{
	getEmailAddress();
	getEmailSubject();
	getEmailMessage();
	

	generateMailSendCommand();
	sendEmailQuerry();
}











int main()
{
        int j,frombase,tobase,no,value,temp;
        int size,arr[30],c,qno, qch, qe,swap;
        int n,array[30],i,d,t,bubble[100];
        float cur;
        char input[30];
        
		
		for(i=0;i<45;i++) {
                printf("\n");
        }
        
		
        printUIBoxesTag();
        printUIBoxes( 40 );

        printUIBoxesTag();
        printUIBoxes( 40 - printf("  Hey there... " ) );

        printUIBoxesTag();
        printUIBoxes( 40 - printf( "  I'm Eva, your Personal Assistant.") );

        printUIBoxesTag();
        printUIBoxes( 40 - printf( "  How can I help?") );

        printUIBoxesTag();
        printUIBoxes( 40 );

        printMeHeader();
        printf( "  Me: ");

        fgets(input,30,stdin);
        printf( "\n" );
        
        while(strstr(input,"./Quit")==0)
        {       
                /*Sorting Elements*/
                if(strstr(input,"Sort") || strstr(input,"sort") )
                {
                        printUIBoxesTag();
                        printUIBoxes( 55 );

                        printUIBoxesTag();
                        printUIBoxes( 55 - printf("  Eva: How would you like to perform the Sorting?" ) );

                        printUIBoxesTag();
                        printUIBoxes( 55 );

                        printf( "\n        " );
                        textcolor(BRIGHT, BLACK, GREEN);
                        printf(" Selection Sort \033[0;0m " );
                        textcolor(BRIGHT, BLACK, GREEN);
                        printf(" Insertion Sort \033[0;0m " );
                        textcolor(BRIGHT, BLACK, GREEN);
                        printf(" mergeSort Sort \033[0;0m " );

                        printf( "\n\n        " );
                        textcolor(BRIGHT, BLACK, GREEN);
                        printf(" Quick Sort \033[0;0m " );
                        textcolor(BRIGHT, BLACK, GREEN);
                        printf(" Bubble Sort \033[0;0m\n" );

                        printMeHeader();
                        printf( "  Me: ");

                        fgets(input,30,stdin);
                        printf( "\n" );

                        if(strstr(input,"Selection Sort") || strstr(input,"selection sort"))
                        {
                                selectionsort();
                        }
                        else if(strstr(input,"Quick Sort") || strstr(input,"quick sort"))
                        {
                            printf( "       " );
                            textcolor(BRIGHT, BLACK, GREEN);
                            printf(" QTY \033[0;0m " );

                            scanf("%d",&size);
                            printf( "\n" );

                            for (c=0;c<size;c++) {
                                printf( "       %d. ", c+1 );
                                scanf("%d", &arr[c]);
                            }

                            printf( "\n" );

                            quickSort(arr,0,size-1);
                            printArray(arr,size);
                        }
                        else if(strstr(input,"Bubble Sort") || strstr(input,"bubble sort"))
                        {
                                printf( "       " );
                                textcolor(BRIGHT, BLACK, GREEN);
                                printf(" QTY \033[0;0m " );

                                scanf("%d", &n);
                                printf( "\n" );
								
								for (c=0;c<n;c++) {
                                    printf( "       %d. ", c+1 );
                                    scanf("%d", &bubble[c]);
                                }
                                printf( "\n" );
                                
								
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
                                
                            printUIBoxesTag();
                            printUIBoxes( 30 );

                            printUIBoxesTag();
                            printUIBoxes( 30 - printf("  Eva: Here you go..." ) );

                            printUIBoxesTag();
                            printUIBoxes( 30 );

                            printf( "\n        " );
                            for (c=0;c<n-1;c++) {
                                textcolor(BRIGHT, BLACK, GREEN);
                                printf(" %d \033[0;0m ", bubble[c] );
                            }

                            textcolor(BRIGHT, BLACK, GREEN);
                            printf(" %d \033[0;0m\n\n", bubble[c] );
                        }
                        else if(strstr(input,"Merge Sort") || strstr(input,"merge sort"))
                        {
                            printf( "       " );
                            textcolor(BRIGHT, BLACK, GREEN);
                            printf(" QTY \033[0;0m " );

                            scanf("%d",&size);
                            printf( "\n" );
         
                            for (c=0;c<size;c++)
                            {
                                printf( "       %d. ", c+1 );
                                scanf("%d", &arr[c]);
                            }
                            printf( "\n" );

                            mergeSort(arr,0,size-1);
                            printArray(arr, size);
                        }
                        else if(strstr(input,"Insertion Sort") || strstr(input,"insertion sort"))
                        {
                            printf( "       " );
                            textcolor(BRIGHT, BLACK, GREEN);
                            printf(" QTY \033[0;0m " );
                            
                            scanf("%d", &n);
                            printf( "\n" );

                              for (c=0;c<n;c++)
                              {
                                printf( "       %d. ", c+1 );
                                scanf("%d", &array[c]);
                              }
                              printf( "\n" );
                             
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
                             
                            printUIBoxesTag();
                            printUIBoxes( 30 );

                            printUIBoxesTag();
                            printUIBoxes( 30 - printf("  Eva: Here you go..." ) );

                            printUIBoxesTag();
                            printUIBoxes( 30 );

                            printf( "\n        " );
                            for(c=0;c<n-1;c++) {
                                textcolor(BRIGHT, BLACK, GREEN);
                                printf(" %d \033[0;0m ", array[c] );
                            }
                                textcolor(BRIGHT, BLACK, GREEN);
                                printf(" %d \033[0;0m\n\n", array[c] );
                        }
                        
                        fgets(input,30,stdin);
                }


				// Sending an Email.
				else if( strstr( input, "Email" ) || strstr( input, "email" )  ) {					
					initiateMailSendProcedure();


					printMeHeader();
                    printf( "  Me: ");

                	fgets(input,30,stdin);
					continue;
				}

				
				// Edit a text file.
				else if( strstr( input, "File" ) || strstr( input, "file" )  ) {					


					system( "gcc -Wall editor.c -o editor && ./editor" );
					

					for(i=0;i<45;i++)
						printf("\n");


					printMeHeader();
                    printf( "  Me: ");
					fgets(input,30,stdin);
					continue;
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
                else if(strstr(input,"Euros to Rupees") || strstr(input,"euros to rupees") )
                {
					printf( "       " );
                    textcolor(BRIGHT, BLACK, GREEN);
                    printf(" Euros \033[0;0m " );
                    scanf("%f",&cur);
                    printf( "\n" );


                    printUIBoxesTag();
                    printUIBoxes( 55 );

                    printUIBoxesTag();
                    printUIBoxes( 55 - printf("  Eva: %f Euros equals to %f Rupees.", cur, cur*71.30351 ) );

                    printUIBoxesTag();
                    printUIBoxes( 55 );

                    fgets(input,30,stdin);
                }
                else if(strstr(input,"Rupees to Euros") || strstr(input,"rupees to euros") )
                {
                    printf( "       " );
                    textcolor(BRIGHT, BLACK, GREEN);
                    printf(" Rupees \033[0;0m " );
                    scanf("%f",&cur);
                    printf( "\n" );


                    printUIBoxesTag();
                    printUIBoxes( 55 );

                    printUIBoxesTag();
                    printUIBoxes( 55 - printf("  Eva: %f Rupees equals to %f Euros.", cur, cur / 71.30351 ) );

                    printUIBoxesTag();
                    printUIBoxes( 55 );

                    fgets(input,30,stdin);
                }
                else if( strstr(input,"Dollars to Rupees") || strstr(input,"dollars to rupees") )
                {
                    printf( "       " );
                    textcolor(BRIGHT, BLACK, GREEN);
                    printf(" Dollars \033[0;0m " );
                    scanf("%f",&cur);
                    printf( "\n" );


                    printUIBoxesTag();
                    printUIBoxes( 55 );

                    printUIBoxesTag();
                    printUIBoxes( 55 - printf("  Eva: %f Dollars equals to %f Rupees.", cur, cur * 67.80800 ) );

                    printUIBoxesTag();
                    printUIBoxes( 55 );

                    fgets(input,30,stdin);
                }
                else if(strstr(input,"Rupees to Dollars") || strstr(input,"rupees to dollars"))
                {
                    printf( "       " );
                    textcolor(BRIGHT, BLACK, GREEN);
                    printf(" Rupees \033[0;0m " );
                    scanf("%f",&cur);
                    printf( "\n" );


                    printUIBoxesTag();
                    printUIBoxes( 55 );

                    printUIBoxesTag();
                    printUIBoxes( 55 - printf("  Eva: %f Rupees equals to %f Dollars.", cur, cur / 67.80800 ) );

                    printUIBoxesTag();
                    printUIBoxes( 55 );

                    fgets(input,30,stdin);
                }
                else if(strstr(input,"Yens to Rupees") || strstr(input,"yens to rupees"))
                {
                    printf( "       " );
                    textcolor(BRIGHT, BLACK, GREEN);
                    printf(" Yens \033[0;0m " );
                    scanf("%f",&cur);
                    printf( "\n" );


                    printUIBoxesTag();
                    printUIBoxes( 55 );

                    printUIBoxesTag();
                    printUIBoxes( 55 - printf("  Eva: %f Yens equals to %f Rupees.", cur, cur * 0.57925 ) );

                    printUIBoxesTag();
                    printUIBoxes( 55 );

                    fgets(input,30,stdin);
                }
                else if(strstr(input,"Rupees to Yens") || strstr(input,"rupees to yens"))
                {
                    printf( "       " );
                    textcolor(BRIGHT, BLACK, GREEN);
                    printf(" Rupees \033[0;0m " );
                    scanf("%f",&cur);
                    printf( "\n" );


                    printUIBoxesTag();
                    printUIBoxes( 55 );

                    printUIBoxesTag();
                    printUIBoxes( 55 - printf("  Eva: %f Rupees equals to %f Yens.", cur,cur/0.57925 ) );

                    printUIBoxesTag();
                    printUIBoxes( 55 );

                    fgets(input,30,stdin);
                }
                else if(strstr(input,"Pounds to Rupees") || strstr(input,"pounds to rupees"))
                {
                    printf( "       " );
                    textcolor(BRIGHT, BLACK, GREEN);
                    printf(" Pounds \033[0;0m " );
                    scanf("%f",&cur);
                    printf( "\n" );


                    printUIBoxesTag();
                    printUIBoxes( 55 );

                    printUIBoxesTag();
                    printUIBoxes( 55 - printf("  Eva: %f Pounds equals to %f Rupees.", cur,cur*83.64996 ) );

                    printUIBoxesTag();
                    printUIBoxes( 55 );
                    
                    fgets(input,30,stdin);
                }
                else if(strstr(input,"Rupees to Pounds") || strstr(input,"rupees to pounds"))
                {
                    printf( "       " );
                    textcolor(BRIGHT, BLACK, GREEN);
                    printf(" Rupees \033[0;0m " );
                    scanf("%f",&cur);
                    printf( "\n" );


                    printUIBoxesTag();
                    printUIBoxes( 55 );

                    printUIBoxesTag();
                    printUIBoxes( 55 - printf("  Eva: %f Rupees equals to %f Pounds.", cur,cur/83.64996 ) );

                    printUIBoxesTag();
                    printUIBoxes( 55 );
                    
                    fgets(input,30,stdin);
                }
                else if(strstr(input,"Francs to Rupees") || strstr(input,"francs to rupees"))
                {
                    printf( "       " );
                    textcolor(BRIGHT, BLACK, GREEN);
                    printf(" Francs \033[0;0m " );
                    scanf("%f",&cur);
                    printf( "\n" );


                    printUIBoxesTag();
                    printUIBoxes( 55 );

                    printUIBoxesTag();
                    printUIBoxes( 55 - printf("  Eva: %f Francs equals to %f Rupees.", cur,cur*66.51103 ) );

                    printUIBoxesTag();
                    printUIBoxes( 55 );
                    
                    fgets(input,30,stdin);
                }
                else if(strstr(input,"Rupees to Francs") || strstr(input,"rupees to francs"))
                {
                    printf( "       " );
                    textcolor(BRIGHT, BLACK, GREEN);
                    printf(" Rupees \033[0;0m " );
                    scanf("%f",&cur);
                    printf( "\n" );


                    printUIBoxesTag();
                    printUIBoxes( 55 );

                    printUIBoxesTag();
                    printUIBoxes( 55 - printf("  Eva: %f Rupees equals to %f Francs.", cur,cur/66.51103 ) );

                    printUIBoxesTag();
                    printUIBoxes( 55 );
                    
                    fgets(input,30,stdin);
                }
                
                /*Dollar Conversion*/
                if(strstr(input,"Euros to Dollars") || strstr(input,"euros to dollars"))
                {
                    printf( "       " );
                    textcolor(BRIGHT, BLACK, GREEN);
                    printf(" Euros \033[0;0m " );
                    scanf("%f",&cur);
                    printf( "\n" );


                    printUIBoxesTag();
                    printUIBoxes( 55 );

                    printUIBoxesTag();
                    printUIBoxes( 55 - printf("  Eva: %f Euros equals to %f Dollars.", cur,cur*1.05155 ) );

                    printUIBoxesTag();
                    printUIBoxes( 55 );
                    
                    fgets(input,30,stdin);
                }
                else if(strstr(input,"Dollars to Euros") || strstr(input,"dollars to euros"))
                {
                    printf( "       " );
                    textcolor(BRIGHT, BLACK, GREEN);
                    printf(" Dollars \033[0;0m " );
                    scanf("%f",&cur);
                    printf( "\n" );


                    printUIBoxesTag();
                    printUIBoxes( 55 );

                    printUIBoxesTag();
                    printUIBoxes( 55 - printf("  Eva: %f Dollars equals to %f Euros.", cur,cur/1.05155 ) );

                    printUIBoxesTag();
                    printUIBoxes( 55 );
                    
                    fgets(input,30,stdin);
                }
                else if(strstr(input,"Yens to Dollars") || strstr(input,"yens to dollars"))
                {
                    printf( "       " );
                    textcolor(BRIGHT, BLACK, GREEN);
                    printf(" Yens \033[0;0m " );
                    scanf("%f",&cur);
                    printf( "\n" );


                    printUIBoxesTag();
                    printUIBoxes( 55 );

                    printUIBoxesTag();
                    printUIBoxes( 55 - printf("  Eva: %f Yens equals to %f Dollars.", cur,cur*0.00854 ) );

                    printUIBoxesTag();
                    printUIBoxes( 55 );
                    
                    fgets(input,30,stdin);
                }
                else if(strstr(input,"Dollars to Yens") || strstr(input,"dollars to yens"))
                {
                    printf( "       " );
                    textcolor(BRIGHT, BLACK, GREEN);
                    printf(" Dollars \033[0;0m " );
                    scanf("%f",&cur);
                    printf( "\n" );


                    printUIBoxesTag();
                    printUIBoxes( 55 );

                    printUIBoxesTag();
                    printUIBoxes( 55 - printf("  Eva: %f Dollars equals to %f Yens.", cur,cur/0.00854 ) );

                    printUIBoxesTag();
                    printUIBoxes( 55 );
                    
                    fgets(input,30,stdin);
                }
                else if(strstr(input,"Pounds to Dollars") || strstr(input,"pounds to dollars"))
                {
                    printf( "       " );
                    textcolor(BRIGHT, BLACK, GREEN);
                    printf(" Pounds \033[0;0m " );
                    scanf("%f",&cur);
                    printf( "\n" );


                    printUIBoxesTag();
                    printUIBoxes( 55 );

                    printUIBoxesTag();
                    printUIBoxes( 55 - printf("  Eva: %f Pounds equals to %f Dollars.", cur,cur*1.23363 ) );

                    printUIBoxesTag();
                    printUIBoxes( 55 );
                    
                    fgets(input,30,stdin);
                }
                else if(strstr(input,"Dollars to Pounds") || strstr(input,"dollars to pounds"))
                {
                    printf( "       " );
                    textcolor(BRIGHT, BLACK, GREEN);
                    printf(" Dollars \033[0;0m " );
                    scanf("%f",&cur);
                    printf( "\n" );


                    printUIBoxesTag();
                    printUIBoxes( 55 );

                    printUIBoxesTag();
                    printUIBoxes( 55 - printf("  Eva: %f Dollars equals to %f Pounds.", cur,cur/1.23363 ) );

                    printUIBoxesTag();
                    printUIBoxes( 55 );
                    
                    fgets(input,30,stdin);
                }
                else if(strstr(input,"Francs to Dollars") || strstr(input,"francs to dollars"))
                {
                    printf( "       " );
                    textcolor(BRIGHT, BLACK, GREEN);
                    printf(" Francs \033[0;0m " );
                    scanf("%f",&cur);
                    printf( "\n" );


                    printUIBoxesTag();
                    printUIBoxes( 55 );

                    printUIBoxesTag();
                    printUIBoxes( 55 - printf("  Eva: %f Francs equals to %f Dollars.", cur,cur*0.98087 ) );

                    printUIBoxesTag();
                    printUIBoxes( 55 );
                    
                    fgets(input,30,stdin);
                }
                else if(strstr(input,"Dollars to Francs") || strstr(input,"dollars to francs"))
                {
                    printf( "       " );
                    textcolor(BRIGHT, BLACK, GREEN);
                    printf(" Dollars \033[0;0m " );
                    scanf("%f",&cur);
                    printf( "\n" );


                    printUIBoxesTag();
                    printUIBoxes( 55 );

                    printUIBoxesTag();
                    printUIBoxes( 55 - printf("  Eva: %f Dollars equals to %f Francs.", cur,cur/0.98087 ) );

                    printUIBoxesTag();
                    printUIBoxes( 55 );
                    
                    fgets(input,30,stdin);
                }
                
                /*Pound Conversion*/
                if(strstr(input,"Euros to Pounds") || strstr(input,"euros to pounds"))
                {
                    printf( "       " );
                    textcolor(BRIGHT, BLACK, GREEN);
                    printf(" Euros \033[0;0m " );
                    scanf("%f",&cur);
                    printf( "\n" );


                    printUIBoxesTag();
                    printUIBoxes( 55 );

                    printUIBoxesTag();
                    printUIBoxes( 55 - printf("  Eva: %f Euros equals to %f Pounds.", cur,cur*0.85173 ) );

                    printUIBoxesTag();
                    printUIBoxes( 55 );
                    
                    fgets(input,30,stdin);
                }
                else if(strstr(input,"Pounds to Euros") || strstr(input,"pounds to euros"))
                {
                    printf( "       " );
                    textcolor(BRIGHT, BLACK, GREEN);
                    printf(" Pounds \033[0;0m " );
                    scanf("%f",&cur);
                    printf( "\n" );


                    printUIBoxesTag();
                    printUIBoxes( 55 );

                    printUIBoxesTag();
                    printUIBoxes( 55 - printf("  Eva: %f Pounds equals to %f Euros.", cur,cur/0.85173 ) );

                    printUIBoxesTag();
                    printUIBoxes( 55 );
                    
                    fgets(input,30,stdin);
                }
                else if(strstr(input,"Yens to Pounds") || strstr(input,"yens to pounds"))
                {
                    printf( "       " );
                    textcolor(BRIGHT, BLACK, GREEN);
                    printf(" Yens \033[0;0m " );
                    scanf("%f",&cur);
                    printf( "\n" );


                    printUIBoxesTag();
                    printUIBoxes( 55 );

                    printUIBoxesTag();
                    printUIBoxes( 55 - printf("  Eva: %f Yens equals to %f Pounds.", cur,cur*0.00692 ) );

                    printUIBoxesTag();
                    printUIBoxes( 55 );
                    
                    fgets(input,30,stdin);
                }
                else if(strstr(input,"Pounds to Yens") || strstr(input,"pounds to yens"))
                {
                    printf( "       " );
                    textcolor(BRIGHT, BLACK, GREEN);
                    printf(" Pounds \033[0;0m " );
                    scanf("%f",&cur);
                    printf( "\n" );


                    printUIBoxesTag();
                    printUIBoxes( 55 );

                    printUIBoxesTag();
                    printUIBoxes( 55 - printf("  Eva: %f Pounds equals to %f Yens.", cur,cur/0.00692 ) );

                    printUIBoxesTag();
                    printUIBoxes( 55 );
                    
                    fgets(input,30,stdin);
                }
                else if(strstr(input,"Francs to Pounds") || strstr(input,"francs to pounds"))
                {
                    printf( "       " );
                    textcolor(BRIGHT, BLACK, GREEN);
                    printf(" Francs \033[0;0m " );
                    scanf("%f",&cur);
                    printf( "\n" );


                    printUIBoxesTag();
                    printUIBoxes( 55 );

                    printUIBoxesTag();
                    printUIBoxes( 55 - printf("  Eva: %f Francs equals to %f Pounds.", cur,cur*0.79448 ) );

                    printUIBoxesTag();
                    printUIBoxes( 55 );
                    
                    fgets(input,30,stdin);
                }
                else if(strstr(input,"Pounds to Francs") || strstr(input,"pounds to francs"))
                {
                    printf( "       " );
                    textcolor(BRIGHT, BLACK, GREEN);
                    printf(" Pounds \033[0;0m " );
                    scanf("%f",&cur);
                    printf( "\n" );


                    printUIBoxesTag();
                    printUIBoxes( 55 );

                    printUIBoxesTag();
                    printUIBoxes( 55 - printf("  Eva: %f Pounds equals to %f Francs.", cur,cur/0.79448 ) );

                    printUIBoxesTag();
                    printUIBoxes( 55 );
                    
                    fgets(input,30,stdin);
                }
                
                /*Euro Conversion*/
                else if(strstr(input,"Yens to Euros") || strstr(input,"yens to euros"))
                {
                    printf( "       " );
                    textcolor(BRIGHT, BLACK, GREEN);
                    printf(" Yens \033[0;0m " );
                    scanf("%f",&cur);
                    printf( "\n" );


                    printUIBoxesTag();
                    printUIBoxes( 55 );

                    printUIBoxesTag();
                    printUIBoxes( 55 - printf("  Eva: %f Yens equals to %f Euros.", cur,cur*0.00812 ) );

                    printUIBoxesTag();
                    printUIBoxes( 55 );
                    
                    fgets(input,30,stdin);
                }
                else if(strstr(input,"Euros to Yens") || strstr(input,"euros to yens"))
                {
                    printf( "       " );
                    textcolor(BRIGHT, BLACK, GREEN);
                    printf(" Euros \033[0;0m " );
                    scanf("%f",&cur);
                    printf( "\n" );


                    printUIBoxesTag();
                    printUIBoxes( 55 );

                    printUIBoxesTag();
                    printUIBoxes( 55 - printf("  Eva: %f Euros equals to %f Yens.", cur,cur/0.00812 ) );

                    printUIBoxesTag();
                    printUIBoxes( 55 );
                    
                    fgets(input,30,stdin);
                }
                else if(strstr(input,"Francs to Euros") || strstr(input,"francs to euros"))
                {
                    printf( "       " );
                    textcolor(BRIGHT, BLACK, GREEN);
                    printf(" Francs \033[0;0m " );
                    scanf("%f",&cur);
                    printf( "\n" );


                    printUIBoxesTag();
                    printUIBoxes( 55 );

                    printUIBoxesTag();
                    printUIBoxes( 55 - printf("  Eva: %f Francs equals to %f Euros.", cur,cur*0.93193 ) );

                    printUIBoxesTag();
                    printUIBoxes( 55 );
                    
                    fgets(input,30,stdin);
                }
                else if(strstr(input,"Euros to Francs") || strstr(input,"euros to francs"))
                {
                    printf( "       " );
                    textcolor(BRIGHT, BLACK, GREEN);
                    printf(" Euros \033[0;0m " );
                    scanf("%f",&cur);
                    printf( "\n" );


                    printUIBoxesTag();
                    printUIBoxes( 55 );

                    printUIBoxesTag();
                    printUIBoxes( 55 - printf("  Eva: %f Euros equals to %f Francs.", cur,cur/0.93193 ) );

                    printUIBoxesTag();
                    printUIBoxes( 55 );
                    
                    fgets(input,30,stdin);
                }
                
                /*Franc Conversion*/
                else if(strstr(input,"Yens to Francs") || strstr(input,"yens to francs"))
                {
                    printf( "       " );
                    textcolor(BRIGHT, BLACK, GREEN);
                    printf(" Yens \033[0;0m " );
                    scanf("%f",&cur);
                    printf( "\n" );


                    printUIBoxesTag();
                    printUIBoxes( 55 );

                    printUIBoxesTag();
                    printUIBoxes( 55 - printf("  Eva: %f Yens equals to %f Francs.", cur,cur*0.00870 ) );

                    printUIBoxesTag();
                    printUIBoxes( 55 );
                    
                    fgets(input,30,stdin);
                }
                else if(strstr(input,"Francs to Yens") || strstr(input,"francs to yens"))
                {
                    printf( "       " );
                    textcolor(BRIGHT, BLACK, GREEN);
                    printf(" Francs \033[0;0m " );
                    scanf("%f",&cur);
                    printf( "\n" );


                    printUIBoxesTag();
                    printUIBoxes( 55 );

                    printUIBoxesTag();
                    printUIBoxes( 55 - printf("  Eva: %f Francs equals to %f Yens.", cur,cur/0.00870 ) );

                    printUIBoxesTag();
                    printUIBoxes( 55 );
                    
                    fgets(input,30,stdin);
                }
                else if(strstr(input,"time") || strstr(input,"Time") )
                {
                        time_t rawtime;
                        struct tm *info;
                        char buffer[80];
                        time(&rawtime);
                        info=localtime(&rawtime);
                        strftime(buffer, 80,"%I:%M %p",info);

                    printUIBoxesTag();
                    printUIBoxes( 35 );

                    printUIBoxesTag();
                    printUIBoxes( 35 - printf("  Eva: Right now, It's %s!", buffer ) );

                    printUIBoxesTag();
                    printUIBoxes( 35 );
                }
                else if(strstr(input,"date") || strstr(input,"Date") )
                {
                        time_t rawtime;
                        struct tm *info;
                        char buffer[80];
                        time(&rawtime);
                        info=localtime(&rawtime);
                        strftime(buffer, 80,"%x",info);

                    printUIBoxesTag();
                    printUIBoxes( 30 );

                    printUIBoxesTag();
                    printUIBoxes( 30 - printf("  Eva: Today, It's %s!", buffer ) );

                    printUIBoxesTag();
                    printUIBoxes( 30 );
                }
                else if( strstr( input, "Shut Down" ) )
                {
                    printUIBoxesTag();
                    printUIBoxes( 35 );

                    printUIBoxesTag();
                    printUIBoxes( 35 - printf( "  Eva: Shutting down... Good-Bye!" ) );

                    printUIBoxesTag();
                    printUIBoxes( 35 );

                    system("shutdown -P now");
                }
                else if(strstr(input,"Hello Eva!"))
                {
                    printUIBoxesTag();
                    printUIBoxes( 25 );

                    printUIBoxesTag();
                    printUIBoxes( 25 - printf( "  Eva: Hello Human :)" ) );

                    printUIBoxesTag();
                    printUIBoxes( 25 );
                }
                else if(strstr(input,"What Place is this?"))
                {
                    printUIBoxesTag();
                    printUIBoxes( 50 );

                    printUIBoxesTag();
                    printUIBoxes( 50 - printf( "  Eva: This place is called \"Mother Earth\"!" ) );

                    printUIBoxesTag();
                    printUIBoxes( 50 );
                }
                else if(strstr(input,"Who is Neha Ma'am?"))
                {
                    printUIBoxesTag();
                    printUIBoxes( 50 );

                    printUIBoxesTag();
                    printUIBoxes( 50 - printf( "  Eva: Shame on you!!!" ) );
                    printUIBoxesTag();
                    printUIBoxes( 50 - printf( "       How come you are still in 2nd Year?" ) );
                    printUIBoxesTag();
                    printUIBoxes( 50 - printf( "       Gooo... Look in your Time-Table (^^)" ) );

                    printUIBoxesTag();
                    printUIBoxes( 50 );
                }
                else if(strstr(input,"Who are you?"))
                {
                        time_t rawtime;
                        struct tm *info;
                        char buffer[80];
                        time(&rawtime);
                        info=localtime(&rawtime);
                        strftime(buffer, 80,"%x - %I:%M %p",info);


                    printUIBoxesTag();
                    printUIBoxes( 65 );

                    printUIBoxesTag();
                    printUIBoxes( 65 - printf( "  Eva: PURE IMAGINATION!" ) );
                    printUIBoxesTag();
                    printUIBoxes( 65 - printf( "       That's how I would present myself..." ) );
                    printUIBoxesTag();
                    printUIBoxes( 65 - printf( "       I was executed from Ubuntu on %s!", buffer ) );

                    printUIBoxesTag();
                    printUIBoxes( 65 );
                }
                else if(strstr(input,"What can you do?"))
                {
                    printUIBoxesTag();
                    printUIBoxes( 80 );

                    printUIBoxesTag();
                    printUIBoxes( 80 - printf("  Eva: I can do much more... Just type in any one of the following command." ) );

                    printUIBoxesTag();
                    printUIBoxes( 80 );

                    printf( "\n        " );
                    textcolor(BRIGHT, BLACK, GREEN);
                    printf(" Shut Down - <./Shut Down> \033[0;0m\n\n" );

                    printf( "        " );
                    textcolor(BRIGHT, BLACK, GREEN);
                    printf(" Quit the Program - <./Quit> \033[0;0m\n\n" );

                    printf( "        " );
                    textcolor(BRIGHT, BLACK, GREEN);
                    printf(" Sort elements (Insertion, Selection and Merge Sort) - <Sort Elements> \033[0;0m\n\n" );

                    printf( "        " );
                    textcolor(BRIGHT, BLACK, GREEN);
                    printf(" Convert a No. from one Base to another - <Do Anybase No. Conversion> \033[0;0m\n\n" );

                    printf( "        " );
                    textcolor(BRIGHT, BLACK, GREEN);
                    printf(" Convert Currency (Dollar, Rupee etc.) - <Convert (FROM) to (TO)> \033[0;0m\n\n" );
                        
                    printf( "        " );
                    textcolor(BRIGHT, BLACK, GREEN);
                    printf(" Show Time - <What Time is it right now?> \033[0;0m\n\n" );

                    printf( "        " );
                    textcolor(BRIGHT, BLACK, GREEN);
                    printf(" Show Date - <What Date is Today?> \033[0;0m\n\n" );

                    printf( "        " );
                    textcolor(BRIGHT, BLACK, GREEN);
                    printf(" Chat: Hello Eva! | What Place is this? | Who is Neha Ma'am? \033[0;0m\n\n" );
                        
                    printf( "        " );
                    textcolor(BRIGHT, BLACK, GREEN);
                    printf(" Who is Neha Ma'am? | Who are you? | What can you do? \033[0;0m\n\n" );

                    printf( "        " );
                    textcolor(BRIGHT, WHITE, MAGENTA);
                    printf(" Google Search - coming soon! \033[0;0m\n\n" );
                        
                }
                else if( strstr( input, "clear") || strstr( input, "Clear") ) {
                    for(i=0;i<45;i++) {
                        printf("\n");
                    }
                }
                // else {
                //     printErrorUIBoxesTag();
                //     printErrorUIBoxes( 60 );

                //     printErrorUIBoxesTag();
                //     printErrorUIBoxes( 60 - printf("  Eva: I don't understand this yet... But soon will :D" ) );

                //     printErrorUIBoxesTag();
                //     printErrorUIBoxes( 60 );
                // }

                printMeHeader();
                printf( "  Me: ");

                fgets(input,30,stdin);
                printf( "\n" );
        }

        printUIBoxesTag();
        printUIBoxes( 35 );

        printUIBoxesTag();
        printUIBoxes( 35 - printf("  Eva: See you soon, Good-Bye!" ) );

        printUIBoxesTag();
        printUIBoxes( 35 );

        printf( "\n" );
}

int selectionsort()
{
           int array[100], n, c, d, position, swap;

            printf( "       " );
            textcolor(BRIGHT, BLACK, GREEN);
            printf(" QTY \033[0;0m " );

            scanf("%d",&n);
            printf( "\n" );
         
           for (c=0;c<n;c++) {
                printf( "       %d. ", c+1 );
                scanf("%d", &array[c]);
           }
            printf( "\n" );

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
         


            printUIBoxesTag();
            printUIBoxes( 30 );

            printUIBoxesTag();
            printUIBoxes( 30 - printf("  Eva: Here you go..." ) );

            printUIBoxesTag();
            printUIBoxes( 30 );

            printf( "\n        " );
            for (c=0;c<n-1;c++) {
                textcolor(BRIGHT, BLACK, GREEN);
                printf(" %d \033[0;0m ", array[c] );
            }

            textcolor(BRIGHT, BLACK, GREEN);
            printf(" %d \033[0;0m\n\n", array[c] );
         
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
    
    printUIBoxesTag();
    printUIBoxes( 30 );

    printUIBoxesTag();
    printUIBoxes( 30 - printf("  Eva: Here you go..." ) );

    printUIBoxesTag();
    printUIBoxes( 30 );

    printf( "\n        " );
    for(i=0;i<size-1;i++) {
        textcolor(BRIGHT, BLACK, GREEN);
        printf(" %d \033[0;0m ", A[i] );
    }

    textcolor(BRIGHT, BLACK, GREEN);
    printf(" %d \033[0;0m\n\n", A[i] );
 
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
