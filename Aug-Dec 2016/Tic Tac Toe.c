/*Tic-Tac-Toe Game using C Language*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void display(char []);

int main()
{
        int i,j,k,move,score[3],randno,temp,prev,next,avg;
        char input[30],output[10],me,eva;
        time_t t;
        srand((unsigned) time(&t));
        
        /*Resetting the Score*/
        for(i=0;i<3;i++)
        {
                score[i]=0;
        }
        
        do
        {
                /*Bringing the cursor to the last line of the console screen*/
                for(i=0;i<45;i++)
                {
                        printf("\n");
                }
                printf("Eva: Hey there... \nI'm Eva, your Personal Assistant :)\nLet's play Tic-Tac-Toe.\nTry to defeat me :p\nReady?\nGo00o0!\n");       
                /*Emptying the matrix for new round*/
                for(i=1;i<=9;i++)
                {
                        output[i]=0;
                }
                printf("What would you like to choose, X or O?\n\nYou: ");
                fgets(input,30,stdin);
                
                /*User's choice to select cross or plus.*/
                if(strstr(input,"X") || strstr(input,"x"))
                {
                        me='X';
                        eva='O';        
                }
                else if(strstr(input,"O") || strstr(input,"o"))
                {
                        me='O';
                        eva='X';
                }
                if(strstr(input,"X") || strstr(input,"x") || strstr(input,"O") || strstr(input,"o"))
                {
                        printf("Eva: Here's your deck -\n");
                        display(output);
                        
                        printf("Would you like to move first?\n\nYou: ");
                        fgets(input,30,stdin);
                        if(strstr(input,"Yes") || strstr(input,"yes") || strstr(input,"No") || strstr(input,"no"))
                        {
                                printf("Eva: Great choice! Waiting for your move :)\n\nYou: ");
                                scanf("%d",&move);
                                
                                /*User moves at one of the corners*/
                                if(output[move]=='\0')
                                {
                                        output[move]=me;
                                        output[5]=eva;
                                        printf("Eva: Here's your deck -\n");
                                        display(output);
                                        printf("\nYou: ");
                                        temp=move;
                                        prev=move;
                                        scanf("%d",&move);
                                        next=move;
                                        avg=(temp+move)/2;
                                        if((output[move]=='\0') && (((temp==1) && (move==3)) || ((temp==3) && (move==1)) || ((temp==7) && (move==1)) || ((temp==1) && (move==7)) || ((temp==9) && (move==7)) || ((temp==7) && (move==9)) || ((temp==9) && (move==3)) || ((temp==3) && (move==9))))
                                        {
                                                output[move]=me;
                                                output[(temp+move)/2]=eva;
                                                printf("Eva: Here's your deck -\n");
                                                display(output);
                                                printf("\nYou: ");
                                                temp=move;
                                                scanf("%d",&move);
                                                if(output[move]=='\0')
                                                {
                                                        output[move]=me;
                                                        if(avg==2)
                                                        {
                                                                if(output[8]=='\0')
                                                                {
                                                                        output[8]=eva;
                                                                        printf("Eva: Here's your deck -\n");
                                                                        display(output);
                                                                        printf("Yayayaaa... I won!\nThis is where we stand -\n");
                                                                        score[0]++;
                                                                        printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);
                                                                }
                                                                else
                                                                {
                                                                        randno=rand()%2;
                                                                        switch(randno)
                                                                        {
                                                                                case 0:
                                                                                        output[4]=eva;
                                                                                        printf("Eva: Here's your deck -\n");
                                                                                        display(output);
                                                                                        printf("\nYou: ");
                                                                                        scanf("%d",&move);
                                                                                        if((move!=6) && (output[move]=='\0'))
                                                                                        {
                                                                                                output[move]=me;
                                                                                                output[6]=eva;
                                                                                                printf("Eva: Here's your deck -\n");
                                                                                                display(output);
                                                                                                printf("Yayayaaa... I won!\nThis is where we stand -\n");
                                                                                                score[0]++;
                                                                                                printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);
                                                                                        }
                                                                                        else
                                                                                        {
                                                                                                output[move]=me;
                                                                                                output[9]=eva;
                                                                                                printf("Eva: Here's your deck -\n");
                                                                                                display(output);
                                                                                                printf("Hehe... If I coudnt win, so what? I made sure that you don't win either :)\nThis is where we stand -\n");
                                                                                                score[1]++;
                                                                                                printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);
                                                                                        }
                                                                                        break;
                                                                                case 1:
                                                                                        output[6]=eva;
                                                                                        printf("Eva: Here's your deck -\n");
                                                                                        display(output);
                                                                                        printf("\nYou: ");
                                                                                        scanf("%d",&move);
                                                                                        if((move!=4) && (output[move]=='\0'))
                                                                                        {
                                                                                                output[move]=me;
                                                                                                output[4]=eva;
                                                                                                printf("Eva: Here's your deck -\n");
                                                                                                display(output);
                                                                                                printf("Yayayaaa... I won!\nThis is where we stand -\n");
                                                                                                score[0]++;
                                                                                                printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);
                                                                                        }
                                                                                        else
                                                                                        {
                                                                                                output[move]=me;
                                                                                                output[7]=eva;
                                                                                                printf("Eva: Here's your deck -\n");
                                                                                                display(output);
                                                                                                printf("Hehe... If I coudnt win, so what? I made sure that you don't win either :)\nThis is where we stand -\n");
                                                                                                score[1]++;
                                                                                                printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);
                                                                                        }
                                                                                        break;
                                                                        }        
                                                                }
                                                        }
                                                        else if(avg==4)
                                                        {
                                                                if(output[6]=='\0')
                                                                {
                                                                        output[6]=eva;
                                                                        printf("Eva: Here's your deck -\n");
                                                                        display(output);
                                                                        printf("Yayayaaa... I won!\nThis is where we stand -\n");
                                                                        score[0]++;
                                                                        printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);
                                                                }
                                                                else
                                                                {
                                                                        randno=rand()%2;
                                                                        switch(randno)
                                                                        {
                                                                                case 0:
                                                                                        output[8]=eva;
                                                                                        printf("Eva: Here's your deck -\n");
                                                                                        display(output);
                                                                                        printf("\nYou: ");
                                                                                        scanf("%d",&move);
                                                                                        if((move!=2) && (output[move]=='\0'))
                                                                                        {
                                                                                                output[move]=me;
                                                                                                output[2]=eva;
                                                                                                printf("Eva: Here's your deck -\n");
                                                                                                display(output);
                                                                                                printf("Yayayaaa... I won!\nThis is where we stand -\n");
                                                                                                score[0]++;
                                                                                                printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);
                                                                                        }
                                                                                        else
                                                                                        {
                                                                                                output[move]=me;
                                                                                                output[6]=eva;
                                                                                                printf("Eva: Here's your deck -\n");
                                                                                                display(output);
                                                                                                printf("Hehe... If I coudnt win, so what? I made sure that you don't win either :)\nThis is where we stand -\n");
                                                                                                score[1]++;
                                                                                                printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);
                                                                                        }
                                                                                        break;
                                                                                case 1:
                                                                                        output[2]=eva;
                                                                                        printf("Eva: Here's your deck -\n");
                                                                                        display(output);
                                                                                        printf("\nYou: ");
                                                                                        scanf("%d",&move);
                                                                                        if((move!=8) && (output[move]=='\0'))
                                                                                        {
                                                                                                output[move]=me;
                                                                                                output[8]=eva;
                                                                                                printf("Eva: Here's your deck -\n");
                                                                                                display(output);
                                                                                                printf("Yayayaaa... I won!\nThis is where we stand -\n");
                                                                                                score[0]++;
                                                                                                printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);
                                                                                        }
                                                                                        else
                                                                                        {
                                                                                                output[move]=me;
                                                                                                output[9]=eva;
                                                                                                printf("Eva: Here's your deck -\n");
                                                                                                display(output);
                                                                                                printf("Hehe... If I coudnt win, so what? I made sure that you don't win either :)\nThis is where we stand -\n");
                                                                                                score[1]++;
                                                                                                printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);
                                                                                        }
                                                                                        break;
                                                                        }        
                                                                }
                                                        }
                                                        else if(avg==8)
                                                        {
                                                                if(output[2]=='\0')
                                                                {
                                                                        output[2]=eva;
                                                                        printf("Eva: Here's your deck -\n");
                                                                        display(output);
                                                                        printf("Yayayaaa... I won!\nThis is where we stand -\n");
                                                                        score[0]++;
                                                                        printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);
                                                                }
                                                                else
                                                                {
                                                                        randno=rand()%2;
                                                                        switch(randno)
                                                                        {
                                                                                case 0:
                                                                                        output[6]=eva;
                                                                                        printf("Eva: Here's your deck -\n");
                                                                                        display(output);
                                                                                        printf("\nYou: ");
                                                                                        scanf("%d",&move);
                                                                                        if((move!=4) && (output[move]=='\0'))
                                                                                        {
                                                                                                output[move]=me;
                                                                                                output[4]=eva;
                                                                                                printf("Eva: Here's your deck -\n");
                                                                                                display(output);
                                                                                                printf("Yayayaaa... I won!\nThis is where we stand -\n");
                                                                                                score[0]++;
                                                                                                printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);
                                                                                        }
                                                                                        else
                                                                                        {
                                                                                                output[move]=me;
                                                                                                output[1]=eva;
                                                                                                printf("Eva: Here's your deck -\n");
                                                                                                display(output);
                                                                                                printf("Hehe... If I coudnt win, so what? I made sure that you don't win either :)\nThis is where we stand -\n");
                                                                                                score[1]++;
                                                                                                printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);
                                                                                        }
                                                                                        break;
                                                                                case 1:
                                                                                        output[4]=eva;
                                                                                        printf("Eva: Here's your deck -\n");
                                                                                        display(output);
                                                                                        printf("\nYou: ");
                                                                                        scanf("%d",&move);
                                                                                        if((move!=6) && (output[move]=='\0'))
                                                                                        {
                                                                                                output[move]=me;
                                                                                                output[6]=eva;
                                                                                                printf("Eva: Here's your deck -\n");
                                                                                                display(output);
                                                                                                printf("Yayayaaa... I won!\nThis is where we stand -\n");
                                                                                                score[0]++;
                                                                                                printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);
                                                                                        }
                                                                                        else
                                                                                        {
                                                                                                output[move]=me;
                                                                                                output[3]=eva;
                                                                                                printf("Eva: Here's your deck -\n");
                                                                                                display(output);
                                                                                                printf("Hehe... If I coudnt win, so what? I made sure that you don't win either :)\nThis is where we stand -\n");
                                                                                                score[1]++;
                                                                                                printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);
                                                                                        }
                                                                                        break;
                                                                        }        
                                                                }
                                                        }
                                                        else if(avg==6)
                                                        {
                                                                if(output[4]=='\0')
                                                                {
                                                                        output[4]=eva;
                                                                        printf("Eva: Here's your deck -\n");
                                                                        display(output);
                                                                        printf("Yayayaaa... I won!\nThis is where we stand -\n");
                                                                        score[0]++;
                                                                        printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);
                                                                }
                                                                else
                                                                {
                                                                        randno=rand()%2;
                                                                        switch(randno)
                                                                        {
                                                                                case 0:
                                                                                        output[2]=eva;
                                                                                        printf("Eva: Here's your deck -\n");
                                                                                        display(output);
                                                                                        printf("\nYou: ");
                                                                                        scanf("%d",&move);
                                                                                        if((move!=8) && (output[move]=='\0'))
                                                                                        {
                                                                                                output[move]=me;
                                                                                                output[8]=eva;
                                                                                                printf("Eva: Here's your deck -\n");
                                                                                                display(output);
                                                                                                printf("Yayayaaa... I won!\nThis is where we stand -\n");
                                                                                                score[0]++;
                                                                                                printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);
                                                                                        }
                                                                                        else
                                                                                        {
                                                                                                output[move]=me;
                                                                                                output[7]=eva;
                                                                                                printf("Eva: Here's your deck -\n");
                                                                                                display(output);
                                                                                                printf("Hehe... If I coudnt win, so what? I made sure that you don't win either :)\nThis is where we stand -\n");
                                                                                                score[1]++;
                                                                                                printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);
                                                                                        }
                                                                                        break;
                                                                                case 1:
                                                                                        output[8]=eva;
                                                                                        printf("Eva: Here's your deck -\n");
                                                                                        display(output);
                                                                                        printf("\nYou: ");
                                                                                        scanf("%d",&move);
                                                                                        if((move!=2) && (output[move]=='\0'))
                                                                                        {
                                                                                                output[move]=me;
                                                                                                output[2]=eva;
                                                                                                printf("Eva: Here's your deck -\n");
                                                                                                display(output);
                                                                                                printf("Yayayaaa... I won!\nThis is where we stand -\n");
                                                                                                score[0]++;
                                                                                                printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);
                                                                                        }
                                                                                        else
                                                                                        {
                                                                                                output[move]=me;
                                                                                                output[1]=eva;
                                                                                                printf("Eva: Here's your deck -\n");
                                                                                                display(output);
                                                                                                printf("Hehe... If I coudnt win, so what? I made sure that you don't win either :)\nThis is where we stand -\n");
                                                                                                score[1]++;
                                                                                                printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);
                                                                                        }
                                                                                        break;
                                                                        }        
                                                                }
                                                        }
                                                }      
                                        }
                                        else if((output[move]=='\0') && (((prev==1) && (move==9)) || ((prev==9) && (move==1))))
                                        {
                                                if(((prev==1) && (move==9)) || ((prev==9) && (move==1)))
                                                {
                                                        output[move]=me;
                                                        randno=rand()%4;
                                                        switch(randno)
                                                        {
                                                                case 0:
                                                                        output[4]=eva;
                                                                        printf("Eva: Here's your deck -\n");
                                                                        display(output);
                                                                        printf("\nYou: ");
                                                                        scanf("%d",&move);
                                                                        if((move!=6) && (output[move]=='\0'))
                                                                        {
                                                                                output[move]=me;
                                                                                output[6]=eva;
                                                                                printf("Eva: Here's your deck -\n");
                                                                                display(output);
                                                                                printf("Yayayaaa... I won!\nThis is where we stand -\n");
                                                                                score[0]++;
                                                                                printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);       
                                                                        }
                                                                        else
                                                                        {
                                                                                if((move==6) && (output[move]=='\0'))
                                                                                {
                                                                                        output[move]=me;
                                                                                        output[3]=eva;
                                                                                        printf("Eva: Here's your deck -\n");
                                                                                        display(output);
                                                                                        printf("\nYou: ");
                                                                                        scanf("%d",&move);
                                                                                        if((move!=7) && (output[move]=='\0'))
                                                                                        {
                                                                                                output[move]=me;
                                                                                                output[7]=eva;
                                                                                                printf("Eva: Here's your deck -\n");
                                                                                                display(output);
                                                                                                printf("Yayayaaa... I won!\nThis is where we stand -\n");
                                                                                                score[0]++;
                                                                                                printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);        
                                                                                        }
                                                                                        else if((move==7) && (output[move]=='\0'))
                                                                                        {
                                                                                                output[move]=me;
                                                                                                output[8]=eva;
                                                                                                printf("Eva: Here's your deck -\n");
                                                                                                display(output);
                                                                                                printf("Hehe... If I coudnt win, so what? I made sure that you don't win either :)\nThis is where we stand -\n");
                                                                                                score[1]++;
                                                                                                printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);
                                                                                        }
                                                                                }
                                                                        }
                                                                        break;
                                                                case 1:
                                                                        output[2]=eva;
                                                                        printf("Eva: Here's your deck -\n");
                                                                        display(output);
                                                                        printf("\nYou: ");
                                                                        scanf("%d",&move);
                                                                        if((move!=8) && (output[move]=='\0'))
                                                                        {
                                                                                output[move]=me;
                                                                                output[8]=eva;
                                                                                printf("Eva: Here's your deck -\n");
                                                                                display(output);
                                                                                printf("Yayayaaa... I won!\nThis is where we stand -\n");
                                                                                score[0]++;
                                                                                printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);       
                                                                        }
                                                                        else
                                                                        {
                                                                                if((move==8) && (output[move]=='\0'))
                                                                                {
                                                                                        output[move]=me;
                                                                                        output[7]=eva;
                                                                                        printf("Eva: Here's your deck -\n");
                                                                                        display(output);
                                                                                        printf("\nYou: ");
                                                                                        scanf("%d",&move);
                                                                                        if((move!=3) && (output[move]=='\0'))
                                                                                        {
                                                                                                output[move]=me;
                                                                                                output[3]=eva;
                                                                                                printf("Eva: Here's your deck -\n");
                                                                                                display(output);
                                                                                                printf("Yayayaaa... I won!\nThis is where we stand -\n");
                                                                                                score[0]++;
                                                                                                printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);        
                                                                                        }
                                                                                        else if((move==3) && (output[move]=='\0'))
                                                                                        {
                                                                                                output[move]=me;
                                                                                                output[6]=eva;
                                                                                                printf("Eva: Here's your deck -\n");
                                                                                                display(output);
                                                                                                printf("Hehe... If I coudnt win, so what? I made sure that you don't win either :)\nThis is where we stand -\n");
                                                                                                score[1]++;
                                                                                                printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);
                                                                                        }
                                                                                }
                                                                        }
                                                                        break;
                                                                case 2:
                                                                        output[6]=eva;
                                                                        printf("Eva: Here's your deck -\n");
                                                                        display(output);
                                                                        printf("\nYou: ");
                                                                        scanf("%d",&move);
                                                                        if((move!=4) && (output[move]=='\0'))
                                                                        {
                                                                                output[move]=me;
                                                                                output[4]=eva;
                                                                                printf("Eva: Here's your deck -\n");
                                                                                display(output);
                                                                                printf("Yayayaaa... I won!\nThis is where we stand -\n");
                                                                                score[0]++;
                                                                                printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);       
                                                                        }
                                                                        else
                                                                        {
                                                                                if((move==4) && (output[move]=='\0'))
                                                                                {
                                                                                        output[move]=me;
                                                                                        output[7]=eva;
                                                                                        printf("Eva: Here's your deck -\n");
                                                                                        display(output);
                                                                                        printf("\nYou: ");
                                                                                        scanf("%d",&move);
                                                                                        if((move!=3) && (output[move]=='\0'))
                                                                                        {
                                                                                                output[move]=me;
                                                                                                output[3]=eva;
                                                                                                printf("Eva: Here's your deck -\n");
                                                                                                display(output);
                                                                                                printf("Yayayaaa... I won!\nThis is where we stand -\n");
                                                                                                score[0]++;
                                                                                                printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);        
                                                                                        }
                                                                                        else if((move==3) && (output[move]=='\0'))
                                                                                        {
                                                                                                output[move]=me;
                                                                                                output[2]=eva;
                                                                                                printf("Eva: Here's your deck -\n");
                                                                                                display(output);
                                                                                                printf("Hehe... If I coudnt win, so what? I made sure that you don't win either :)\nThis is where we stand -\n");
                                                                                                score[1]++;
                                                                                                printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);
                                                                                        }
                                                                                }
                                                                        }
                                                                        break;
                                                                case 3:
                                                                        output[8]=eva;
                                                                        printf("Eva: Here's your deck -\n");
                                                                        display(output);
                                                                        printf("\nYou: ");
                                                                        scanf("%d",&move);
                                                                        if((move!=2) && (output[move]=='\0'))
                                                                        {
                                                                                output[move]=me;
                                                                                output[2]=eva;
                                                                                printf("Eva: Here's your deck -\n");
                                                                                display(output);
                                                                                printf("Yayayaaa... I won!\nThis is where we stand -\n");
                                                                                score[0]++;
                                                                                printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);       
                                                                        }
                                                                        else
                                                                        {
                                                                                if((move==2) && (output[move]=='\0'))
                                                                                {
                                                                                        output[move]=me;
                                                                                        output[3]=eva;
                                                                                        printf("Eva: Here's your deck -\n");
                                                                                        display(output);
                                                                                        printf("\nYou: ");
                                                                                        scanf("%d",&move);
                                                                                        if((move!=7) && (output[move]=='\0'))
                                                                                        {
                                                                                                output[move]=me;
                                                                                                output[7]=eva;
                                                                                                printf("Eva: Here's your deck -\n");
                                                                                                display(output);
                                                                                                printf("Yayayaaa... I won!\nThis is where we stand -\n");
                                                                                                score[0]++;
                                                                                                printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);        
                                                                                        }
                                                                                        else if((move==7) && (output[move]=='\0'))
                                                                                        {
                                                                                                output[move]=me;
                                                                                                output[4]=eva;
                                                                                                printf("Eva: Here's your deck -\n");
                                                                                                display(output);
                                                                                                printf("Hehe... If I coudnt win, so what? I made sure that you don't win either :)\nThis is where we stand -\n");
                                                                                                score[1]++;
                                                                                                printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);
                                                                                        }
                                                                                }
                                                                        }
                                                                        break;
                                                        }
                                                }
                                        }
                                        else if((output[move]=='\0') && (((prev==3) && (move==7)) || ((prev==7) && (move==3))))
                                        {
                                                output[move]=me;
                                                randno=rand()%4;
                                                switch(randno)
                                                {
                                                        case 0:
                                                                output[4]=eva;
                                                                printf("Eva: Here's your deck -\n");
                                                                display(output);
                                                                printf("\nYou: ");
                                                                scanf("%d",&move);
                                                                if((move!=6) && (output[move]=='\0'))
                                                                {
                                                                        output[move]=me;
                                                                        output[6]=eva;
                                                                        printf("Eva: Here's your deck -\n");
                                                                        display(output);
                                                                        printf("Yayayaaa... I won!\nThis is where we stand -\n");
                                                                        score[0]++;
                                                                        printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);       
                                                                }
                                                                else if((move==6) && (output[move]=='\0'))
                                                                {
                                                                        output[move]=me;
                                                                        output[9]=eva;
                                                                        printf("Eva: Here's your deck -\n");
                                                                        display(output);
                                                                        printf("\nYou: ");
                                                                        scanf("%d",&move);
                                                                        if((move!=1) && (output[move]=='\0'))
                                                                        {
                                                                                output[move]=me;
                                                                                output[1]=eva;
                                                                                printf("Eva: Here's your deck -\n");
                                                                                display(output);
                                                                                printf("Yayayaaa... I won!\nThis is where we stand -\n");
                                                                                score[0]++;
                                                                                printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);        
                                                                        }
                                                                        else if((move==1) && (output[move]=='\0'))
                                                                        {
                                                                                output[move]=me;
                                                                                output[2]=eva;
                                                                                printf("Eva: Here's your deck -\n");
                                                                                display(output);
                                                                                printf("Hehe... If I coudnt win, so what? I made sure that you don't win either :)\nThis is where we stand -\n");
                                                                                score[1]++;
                                                                                printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);
                                                                        }
                                                                }
                                                                break;
                                                        case 1:
                                                                output[2]=eva;
                                                                printf("Eva: Here's your deck -\n");
                                                                display(output);
                                                                printf("\nYou: ");
                                                                scanf("%d",&move);
                                                                if((move!=8) && (output[move]=='\0'))
                                                                {
                                                                        output[move]=me;
                                                                        output[8]=eva;
                                                                        printf("Eva: Here's your deck -\n");
                                                                        display(output);
                                                                        printf("Yayayaaa... I won!\nThis is where we stand -\n");
                                                                        score[0]++;
                                                                        printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);       
                                                                }
                                                                else if((move==8) && (output[move]=='\0'))
                                                                {
                                                                        output[move]=me;
                                                                        output[9]=eva;
                                                                        printf("Eva: Here's your deck -\n");
                                                                        display(output);
                                                                        printf("\nYou: ");
                                                                        scanf("%d",&move);
                                                                        if((move!=1) && (output[move]=='\0'))
                                                                        {
                                                                                output[move]=me;
                                                                                output[1]=eva;
                                                                                printf("Eva: Here's your deck -\n");
                                                                                display(output);
                                                                                printf("Yayayaaa... I won!\nThis is where we stand -\n");
                                                                                score[0]++;
                                                                                printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);        
                                                                        }
                                                                        else if((move==1) && (output[move]=='\0'))
                                                                        {
                                                                                output[move]=me;
                                                                                output[4]=eva;
                                                                                printf("Eva: Here's your deck -\n");
                                                                                display(output);
                                                                                printf("Hehe... If I coudnt win, so what? I made sure that you don't win either :)\nThis is where we stand -\n");
                                                                                score[1]++;
                                                                                printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);
                                                                        }
                                                                }
                                                                break;
                                                        case 2:
                                                                output[6]=eva;
                                                                printf("Eva: Here's your deck -\n");
                                                                display(output);
                                                                printf("\nYou: ");
                                                                scanf("%d",&move);
                                                                if((move!=4) && (output[move]=='\0'))
                                                                {
                                                                        output[move]=me;
                                                                        output[4]=eva;
                                                                        printf("Eva: Here's your deck -\n");
                                                                        display(output);
                                                                        printf("Yayayaaa... I won!\nThis is where we stand -\n");
                                                                        score[0]++;
                                                                        printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);       
                                                                }
                                                                else if((move==4) && (output[move]=='\0'))
                                                                {
                                                                        output[move]=me;
                                                                        output[1]=eva;
                                                                        printf("Eva: Here's your deck -\n");
                                                                        display(output);
                                                                        printf("\nYou: ");
                                                                        scanf("%d",&move);
                                                                        if((move!=9) && (output[move]=='\0'))
                                                                        {
                                                                                output[move]=me;
                                                                                output[9]=eva;
                                                                                printf("Eva: Here's your deck -\n");
                                                                                display(output);
                                                                                printf("Yayayaaa... I won!\nThis is where we stand -\n");
                                                                                score[0]++;
                                                                                printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);        
                                                                        }
                                                                        else if((move==9) && (output[move]=='\0'))
                                                                        {
                                                                                output[move]=me;
                                                                                output[8]=eva;
                                                                                printf("Eva: Here's your deck -\n");
                                                                                display(output);
                                                                                printf("Hehe... If I coudnt win, so what? I made sure that you don't win either :)\nThis is where we stand -\n");
                                                                                score[1]++;
                                                                                printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);
                                                                        }
                                                                }
                                                                break;
                                                        case 3:
                                                                output[8]=eva;
                                                                printf("Eva: Here's your deck -\n");
                                                                display(output);
                                                                printf("\nYou: ");
                                                                scanf("%d",&move);
                                                                if((move!=2) && (output[move]=='\0'))
                                                                {
                                                                        output[move]=me;
                                                                        output[2]=eva;
                                                                        printf("Eva: Here's your deck -\n");
                                                                        display(output);
                                                                        printf("Yayayaaa... I won!\nThis is where we stand -\n");
                                                                        score[0]++;
                                                                        printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);       
                                                                }
                                                                else if((move==2) && (output[move]=='\0'))
                                                                {
                                                                        output[move]=me;
                                                                        output[1]=eva;
                                                                        printf("Eva: Here's your deck -\n");
                                                                        display(output);
                                                                        printf("\nYou: ");
                                                                        scanf("%d",&move);
                                                                        if((move!=9) && (output[move]=='\0'))
                                                                        {
                                                                                output[move]=me;
                                                                                output[9]=eva;
                                                                                printf("Eva: Here's your deck -\n");
                                                                                display(output);
                                                                                printf("Yayayaaa... I won!\nThis is where we stand -\n");
                                                                                score[0]++;
                                                                                printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);        
                                                                        }
                                                                        else if((move==9) && (output[move]=='\0'))
                                                                        {
                                                                                output[move]=me;
                                                                                output[6]=eva;
                                                                                printf("Eva: Here's your deck -\n");
                                                                                display(output);
                                                                                printf("Hehe... If I coudnt win, so what? I made sure that you don't win either :)\nThis is where we stand -\n");
                                                                                score[1]++;
                                                                                printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);
                                                                        }
                                                                }
                                                                break;
                                                }
                                        }  
                                        else if((output[move]=='\0') && (((prev==1) && (move==2)) || ((prev==2) && (move==1))))
                                        {
                                                output[move]=me;
                                                output[3]=eva;
                                                printf("Eva: Here's your deck -\n");
                                                display(output);
                                                printf("\nYou: ");
                                                scanf("%d",&move);
                                                if((move!=7) && (output[move]=='\0'))
                                                {
                                                        output[move]=me;
                                                        output[7]=eva;
                                                        printf("Eva: Here's your deck -\n");
                                                        display(output);
                                                        printf("Yayayaaa... I won!\nThis is where we stand -\n");
                                                        score[0]++;
                                                        printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);        
                                               }
                                               else if((move==7) && (output[move]=='\0'))
                                               {
                                                        output[move]=me;
                                                        output[4]=eva;
                                                        printf("Eva: Here's your deck -\n");
                                                        display(output);
                                                        printf("\nYou: ");
                                                        scanf("%d",&move);
                                                        if((move!=6) && (output[move]=='\0'))
                                                        {
                                                                output[move]=me;
                                                                output[6]=eva;
                                                                printf("Eva: Here's your deck -\n");
                                                                display(output);
                                                                printf("Yayayaaa... I won!\nThis is where we stand -\n");
                                                                score[0]++;
                                                                printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);        
                                                        }
                                                        else if((move==6) && (output[move]=='\0'))
                                                        {
                                                                output[move]=me;
                                                                output[9]=eva;
                                                                printf("Eva: Here's your deck -\n");
                                                                display(output);
                                                                printf("Hehe... If I coudnt win, so what? I made sure that you don't win either :)\nThis is where we stand -\n");
                                                                score[1]++;
                                                                printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);
                                                        }
                                               }
                                       }
                                       else if((output[move]=='\0') && (((prev==9) && (move==8)) || ((prev==8) && (move==9))))
                                       {
                                               output[move]=me;
                                               output[7]=eva;
                                               printf("Eva: Here's your deck -\n");
                                               display(output);
                                               printf("\nYou: ");
                                               scanf("%d",&move);
                                               if((move!=3) && (output[move]=='\0'))
                                               {
                                                       output[move]=me;
                                                       output[3]=eva;
                                                       printf("Eva: Here's your deck -\n");
                                                       display(output);
                                                       printf("Yayayaaa... I won!\nThis is where we stand -\n");
                                                       score[0]++;
                                                       printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);        
                                               }
                                               else if((move==3) && (output[move]=='\0'))
                                               {
                                                        output[move]=me;
                                                        output[6]=eva;
                                                        printf("Eva: Here's your deck -\n");
                                                        display(output);
                                                        printf("\nYou: ");
                                                        scanf("%d",&move);
                                                        if((move!=4) && (output[move]=='\0'))
                                                        {
                                                                output[move]=me;
                                                                output[4]=eva;
                                                                printf("Eva: Here's your deck -\n");
                                                                display(output);
                                                                printf("Yayayaaa... I won!\nThis is where we stand -\n");
                                                                score[0]++;
                                                                printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);        
                                                        }
                                                        else if((move==4) && (output[move]=='\0'))
                                                        {
                                                                output[move]=me;
                                                                output[2]=eva;
                                                                printf("Eva: Here's your deck -\n");
                                                                display(output);
                                                                printf("Hehe... If I coudnt win, so what? I made sure that you don't win either :)\nThis is where we stand -\n");
                                                                score[1]++;
                                                                printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);
                                                        }
                                                }
                                        }
                                        else if((output[move]=='\0') && (((prev==7) && (move==4)) || ((prev==4) && (move==7))))
                                        {
                                               output[move]=me;
                                               output[1]=eva;
                                               printf("Eva: Here's your deck -\n");
                                               display(output);
                                               printf("\nYou: ");
                                               scanf("%d",&move);
                                               if((move!=9) && (output[move]=='\0'))
                                               {
                                                       output[move]=me;
                                                       output[9]=eva;
                                                       printf("Eva: Here's your deck -\n");
                                                       display(output);
                                                       printf("Yayayaaa... I won!\nThis is where we stand -\n");
                                                       score[0]++;
                                                       printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);        
                                               }
                                               else if((move==9) && (output[move]=='\0'))
                                               {
                                                        output[move]=me;
                                                        output[8]=eva;
                                                        printf("Eva: Here's your deck -\n");
                                                        display(output);
                                                        printf("\nYou: ");
                                                        scanf("%d",&move);
                                                        if((move!=2) && (output[move]=='\0'))
                                                        {
                                                                output[move]=me;
                                                                output[2]=eva;
                                                                printf("Eva: Here's your deck -\n");
                                                                display(output);
                                                                printf("Yayayaaa... I won!\nThis is where we stand -\n");
                                                                score[0]++;
                                                                printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);        
                                                        }
                                                        else if((move==2) && (output[move]=='\0'))
                                                        {
                                                                output[move]=me;
                                                                output[6]=eva;
                                                                printf("Eva: Here's your deck -\n");
                                                                display(output);
                                                                printf("Hehe... If I coudnt win, so what? I made sure that you don't win either :)\nThis is where we stand -\n");
                                                                score[1]++;
                                                                printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);
                                                        }
                                                }
                                        }
                                        else if((output[move]=='\0') && (((prev==3) && (move==6)) || ((prev==6) && (move==3))))
                                        {
                                               output[move]=me;
                                               output[9]=eva;
                                               printf("Eva: Here's your deck -\n");
                                               display(output);
                                               printf("\nYou: ");
                                               scanf("%d",&move);
                                               if((move!=1) && (output[move]=='\0'))
                                               {
                                                       output[move]=me;
                                                       output[1]=eva;
                                                       printf("Eva: Here's your deck -\n");
                                                       display(output);
                                                       printf("Yayayaaa... I won!\nThis is where we stand -\n");
                                                       score[0]++;
                                                       printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);        
                                               }
                                               else if((move==1) && (output[move]=='\0'))
                                               {
                                                        output[move]=me;
                                                        output[2]=eva;
                                                        printf("Eva: Here's your deck -\n");
                                                        display(output);
                                                        printf("\nYou: ");
                                                        scanf("%d",&move);
                                                        if((move!=8) && (output[move]=='\0'))
                                                        {
                                                                output[move]=me;
                                                                output[8]=eva;
                                                                printf("Eva: Here's your deck -\n");
                                                                display(output);
                                                                printf("Yayayaaa... I won!\nThis is where we stand -\n");
                                                                score[0]++;
                                                                printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);        
                                                        }
                                                        else if((move==8) && (output[move]=='\0'))
                                                        {
                                                                output[move]=me;
                                                                output[4]=eva;
                                                                printf("Eva: Here's your deck -\n");
                                                                display(output);
                                                                printf("Hehe... If I coudnt win, so what? I made sure that you don't win either :)\nThis is where we stand -\n");
                                                                score[1]++;
                                                                printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);
                                                        }
                                                }
                                        }
                                        else if((output[move]=='\0') && (((prev==1) && (move==4)) || ((prev==4) && (move==1))))
                                        {
                                               output[move]=me;
                                               output[7]=eva;
                                               printf("Eva: Here's your deck -\n");
                                               display(output);
                                               printf("\nYou: ");
                                               scanf("%d",&move);
                                               if((move!=3) && (output[move]=='\0'))
                                               {
                                                       output[move]=me;
                                                       output[3]=eva;
                                                       printf("Eva: Here's your deck -\n");
                                                       display(output);
                                                       printf("Yayayaaa... I won!\nThis is where we stand -\n");
                                                       score[0]++;
                                                       printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);        
                                               }
                                               else if((move==3) && (output[move]=='\0'))
                                               {
                                                        output[move]=me;
                                                        output[2]=eva;
                                                        printf("Eva: Here's your deck -\n");
                                                        display(output);
                                                        printf("\nYou: ");
                                                        scanf("%d",&move);
                                                        if((move!=8) && (output[move]=='\0'))
                                                        {
                                                                output[move]=me;
                                                                output[8]=eva;
                                                                printf("Eva: Here's your deck -\n");
                                                                display(output);
                                                                printf("Yayayaaa... I won!\nThis is where we stand -\n");
                                                                score[0]++;
                                                                printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);        
                                                        }
                                                        else if((move==8) && (output[move]=='\0'))
                                                        {
                                                                output[move]=me;
                                                                output[6]=eva;
                                                                printf("Eva: Here's your deck -\n");
                                                                display(output);
                                                                printf("Hehe... If I coudnt win, so what? I made sure that you don't win either :)\nThis is where we stand -\n");
                                                                score[1]++;
                                                                printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);
                                                        }
                                                }
                                        }
                                        else if((output[move]=='\0') && (((prev==2) && (move==3)) || ((prev==3) && (move==2))))
                                        {
                                               output[move]=me;
                                               output[1]=eva;
                                               printf("Eva: Here's your deck -\n");
                                               display(output);
                                               printf("\nYou: ");
                                               scanf("%d",&move);
                                               if((move!=9) && (output[move]=='\0'))
                                               {
                                                       output[move]=me;
                                                       output[9]=eva;
                                                       printf("Eva: Here's your deck -\n");
                                                       display(output);
                                                       printf("Yayayaaa... I won!\nThis is where we stand -\n");
                                                       score[0]++;
                                                       printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);        
                                               }
                                               else if((move==9) && (output[move]=='\0'))
                                               {
                                                        output[move]=me;
                                                        output[6]=eva;
                                                        printf("Eva: Here's your deck -\n");
                                                        display(output);
                                                        printf("\nYou: ");
                                                        scanf("%d",&move);
                                                        if((move!=4) && (output[move]=='\0'))
                                                        {
                                                                output[move]=me;
                                                                output[4]=eva;
                                                                printf("Eva: Here's your deck -\n");
                                                                display(output);
                                                                printf("Yayayaaa... I won!\nThis is where we stand -\n");
                                                                score[0]++;
                                                                printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);        
                                                        }
                                                        else if((move==4) && (output[move]=='\0'))
                                                        {
                                                                output[move]=me;
                                                                output[8]=eva;
                                                                printf("Eva: Here's your deck -\n");
                                                                display(output);
                                                                printf("Hehe... If I coudnt win, so what? I made sure that you don't win either :)\nThis is where we stand -\n");
                                                                score[1]++;
                                                                printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);
                                                        }
                                                }
                                        }
                                        else if((output[move]=='\0') && (((prev==6) && (move==9)) || ((prev==9) && (move==6))))
                                        {
                                               output[move]=me;
                                               output[3]=eva;
                                               printf("Eva: Here's your deck -\n");
                                               display(output);
                                               printf("\nYou: ");
                                               scanf("%d",&move);
                                               if((move!=7) && (output[move]=='\0'))
                                               {
                                                       output[move]=me;
                                                       output[7]=eva;
                                                       printf("Eva: Here's your deck -\n");
                                                       display(output);
                                                       printf("Yayayaaa... I won!\nThis is where we stand -\n");
                                                       score[0]++;
                                                       printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);        
                                               }
                                               else if((move==7) && (output[move]=='\0'))
                                               {
                                                        output[move]=me;
                                                        output[8]=eva;
                                                        printf("Eva: Here's your deck -\n");
                                                        display(output);
                                                        printf("\nYou: ");
                                                        scanf("%d",&move);
                                                        if((move!=2) && (output[move]=='\0'))
                                                        {
                                                                output[move]=me;
                                                                output[2]=eva;
                                                                printf("Eva: Here's your deck -\n");
                                                                display(output);
                                                                printf("Yayayaaa... I won!\nThis is where we stand -\n");
                                                                score[0]++;
                                                                printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);        
                                                        }
                                                        else if((move==2) && (output[move]=='\0'))
                                                        {
                                                                output[move]=me;
                                                                output[4]=eva;
                                                                printf("Eva: Here's your deck -\n");
                                                                display(output);
                                                                printf("Hehe... If I coudnt win, so what? I made sure that you don't win either :)\nThis is where we stand -\n");
                                                                score[1]++;
                                                                printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);
                                                        }
                                                }
                                        }
                                        else if((output[move]=='\0') && (((prev==7) && (move==8)) || ((prev==8) && (move==7))))
                                        {
                                               output[move]=me;
                                               output[9]=eva;
                                               printf("Eva: Here's your deck -\n");
                                               display(output);
                                               printf("\nYou: ");
                                               scanf("%d",&move);
                                               if((move!=1) && (output[move]=='\0'))
                                               {
                                                       output[move]=me;
                                                       output[1]=eva;
                                                       printf("Eva: Here's your deck -\n");
                                                       display(output);
                                                       printf("Yayayaaa... I won!\nThis is where we stand -\n");
                                                       score[0]++;
                                                       printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);        
                                               }
                                               else if((move==1) && (output[move]=='\0'))
                                               {
                                                        output[move]=me;
                                                        output[4]=eva;
                                                        printf("Eva: Here's your deck -\n");
                                                        display(output);
                                                        printf("\nYou: ");
                                                        scanf("%d",&move);
                                                        if((move!=6) && (output[move]=='\0'))
                                                        {
                                                                output[move]=me;
                                                                output[6]=eva;
                                                                printf("Eva: Here's your deck -\n");
                                                                display(output);
                                                                printf("Yayayaaa... I won!\nThis is where we stand -\n");
                                                                score[0]++;
                                                                printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);        
                                                        }
                                                        else if((move==6) && (output[move]=='\0'))
                                                        {
                                                                output[move]=me;
                                                                output[2]=eva;
                                                                printf("Eva: Here's your deck -\n");
                                                                display(output);
                                                                printf("Hehe... If I coudnt win, so what? I made sure that you don't win either :)\nThis is where we stand -\n");
                                                                score[1]++;
                                                                printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);
                                                        }
                                                }
                                        }
                                        else if((output[move]=='\0') && (((prev==1) && (move==6)) || ((prev==6) && (move==1))))
                                        {
                                               output[move]=me;
                                               output[2]=eva;
                                               printf("Eva: Here's your deck -\n");
                                               display(output);
                                               printf("\nYou: ");
                                               scanf("%d",&move);
                                               if((move!=8) && (output[move]=='\0'))
                                               {
                                                       output[move]=me;
                                                       output[8]=eva;
                                                       printf("Eva: Here's your deck -\n");
                                                       display(output);
                                                       printf("Yayayaaa... I won!\nThis is where we stand -\n");
                                                       score[0]++;
                                                       printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);        
                                               }
                                               else if((move==8) && (output[move]=='\0'))
                                               {
                                                        output[move]=me;
                                                        output[3]=eva;
                                                        printf("Eva: Here's your deck -\n");
                                                        display(output);
                                                        printf("\nYou: ");
                                                        scanf("%d",&move);
                                                        if((move!=7) && (output[move]=='\0'))
                                                        {
                                                                output[move]=me;
                                                                output[7]=eva;
                                                                printf("Eva: Here's your deck -\n");
                                                                display(output);
                                                                printf("Yayayaaa... I won!\nThis is where we stand -\n");
                                                                score[0]++;
                                                                printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);        
                                                        }
                                                        else if((move==7) && (output[move]=='\0'))
                                                        {
                                                                output[move]=me;
                                                                output[9]=eva;
                                                                printf("Eva: Here's your deck -\n");
                                                                display(output);
                                                                printf("Hehe... If I coudnt win, so what? I made sure that you don't win either :)\nThis is where we stand -\n");
                                                                score[1]++;
                                                                printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);
                                                        }
                                                }
                                        }
                                        else if((output[move]=='\0') && (((prev==1) && (move==8)) || ((prev==8) && (move==1))))
                                        {
                                               output[move]=me;
                                               output[4]=eva;
                                               printf("Eva: Here's your deck -\n");
                                               display(output);
                                               printf("\nYou: ");
                                               scanf("%d",&move);
                                               if((move!=6) && (output[move]=='\0'))
                                               {
                                                       output[move]=me;
                                                       output[6]=eva;
                                                       printf("Eva: Here's your deck -\n");
                                                       display(output);
                                                       printf("Yayayaaa... I won!\nThis is where we stand -\n");
                                                       score[0]++;
                                                       printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);        
                                               }
                                               else if((move==6) && (output[move]=='\0'))
                                               {
                                                        output[move]=me;
                                                        output[3]=eva;
                                                        printf("Eva: Here's your deck -\n");
                                                        display(output);
                                                        printf("\nYou: ");
                                                        scanf("%d",&move);
                                                        if((move!=7) && (output[move]=='\0'))
                                                        {
                                                                output[move]=me;
                                                                output[7]=eva;
                                                                printf("Eva: Here's your deck -\n");
                                                                display(output);
                                                                printf("Yayayaaa... I won!\nThis is where we stand -\n");
                                                                score[0]++;
                                                                printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);        
                                                        }
                                                        else if((move==7) && (output[move]=='\0'))
                                                        {
                                                                output[move]=me;
                                                                output[9]=eva;
                                                                printf("Eva: Here's your deck -\n");
                                                                display(output);
                                                                printf("Hehe... If I coudnt win, so what? I made sure that you don't win either :)\nThis is where we stand -\n");
                                                                score[1]++;
                                                                printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);
                                                        }
                                                }
                                        }
                                        else if((output[move]=='\0') && (((prev==3) && (move==4)) || ((prev==4) && (move==3))))
                                        {
                                               output[move]=me;
                                               output[2]=eva;
                                               printf("Eva: Here's your deck -\n");
                                               display(output);
                                               printf("\nYou: ");
                                               scanf("%d",&move);
                                               if((move!=8) && (output[move]=='\0'))
                                               {
                                                       output[move]=me;
                                                       output[8]=eva;
                                                       printf("Eva: Here's your deck -\n");
                                                       display(output);
                                                       printf("Yayayaaa... I won!\nThis is where we stand -\n");
                                                       score[0]++;
                                                       printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);        
                                               }
                                               else if((move==8) && (output[move]=='\0'))
                                               {
                                                        output[move]=me;
                                                        output[9]=eva;
                                                        printf("Eva: Here's your deck -\n");
                                                        display(output);
                                                        printf("\nYou: ");
                                                        scanf("%d",&move);
                                                        if((move!=1) && (output[move]=='\0'))
                                                        {
                                                                output[move]=me;
                                                                output[1]=eva;
                                                                printf("Eva: Here's your deck -\n");
                                                                display(output);
                                                                printf("Yayayaaa... I won!\nThis is where we stand -\n");
                                                                score[0]++;
                                                                printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);        
                                                        }
                                                        else if((move==1) && (output[move]=='\0'))
                                                        {
                                                                output[move]=me;
                                                                output[7]=eva;
                                                                printf("Eva: Here's your deck -\n");
                                                                display(output);
                                                                printf("Hehe... If I coudnt win, so what? I made sure that you don't win either :)\nThis is where we stand -\n");
                                                                score[1]++;
                                                                printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);
                                                        }
                                                }
                                        }
                                        else if((output[move]=='\0') && (((prev==3) && (move==8)) || ((prev==8) && (move==3))))
                                        {
                                               output[move]=me;
                                               output[6]=eva;
                                               printf("Eva: Here's your deck -\n");
                                               display(output);
                                               printf("\nYou: ");
                                               scanf("%d",&move);
                                               if((move!=4) && (output[move]=='\0'))
                                               {
                                                       output[move]=me;
                                                       output[4]=eva;
                                                       printf("Eva: Here's your deck -\n");
                                                       display(output);
                                                       printf("Yayayaaa... I won!\nThis is where we stand -\n");
                                                       score[0]++;
                                                       printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);        
                                               }
                                               else if((move==4) && (output[move]=='\0'))
                                               {
                                                        output[move]=me;
                                                        output[1]=eva;
                                                        printf("Eva: Here's your deck -\n");
                                                        display(output);
                                                        printf("\nYou: ");
                                                        scanf("%d",&move);
                                                        if((move!=9) && (output[move]=='\0'))
                                                        {
                                                                output[move]=me;
                                                                output[9]=eva;
                                                                printf("Eva: Here's your deck -\n");
                                                                display(output);
                                                                printf("Yayayaaa... I won!\nThis is where we stand -\n");
                                                                score[0]++;
                                                                printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);        
                                                        }
                                                        else if((move==9) && (output[move]=='\0'))
                                                        {
                                                                output[move]=me;
                                                                output[7]=eva;
                                                                printf("Eva: Here's your deck -\n");
                                                                display(output);
                                                                printf("Hehe... If I coudnt win, so what? I made sure that you don't win either :)\nThis is where we stand -\n");
                                                                score[1]++;
                                                                printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);
                                                        }
                                                }
                                        }
                                        else if((output[move]=='\0') && (((prev==9) && (move==4)) || ((prev==4) && (move==9))))
                                        {
                                               output[move]=me;
                                               output[8]=eva;
                                               printf("Eva: Here's your deck -\n");
                                               display(output);
                                               printf("\nYou: ");
                                               scanf("%d",&move);
                                               if((move!=2) && (output[move]=='\0'))
                                               {
                                                       output[move]=me;
                                                       output[2]=eva;
                                                       printf("Eva: Here's your deck -\n");
                                                       display(output);
                                                       printf("Yayayaaa... I won!\nThis is where we stand -\n");
                                                       score[0]++;
                                                       printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);        
                                               }
                                               else if((move==2) && (output[move]=='\0'))
                                               {
                                                        output[move]=me;
                                                        output[3]=eva;
                                                        printf("Eva: Here's your deck -\n");
                                                        display(output);
                                                        printf("\nYou: ");
                                                        scanf("%d",&move);
                                                        if((move!=7) && (output[move]=='\0'))
                                                        {
                                                                output[move]=me;
                                                                output[7]=eva;
                                                                printf("Eva: Here's your deck -\n");
                                                                display(output);
                                                                printf("Yayayaaa... I won!\nThis is where we stand -\n");
                                                                score[0]++;
                                                                printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);        
                                                        }
                                                        else if((move==7) && (output[move]=='\0'))
                                                        {
                                                                output[move]=me;
                                                                output[1]=eva;
                                                                printf("Eva: Here's your deck -\n");
                                                                display(output);
                                                                printf("Hehe... If I coudnt win, so what? I made sure that you don't win either :)\nThis is where we stand -\n");
                                                                score[1]++;
                                                                printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);
                                                        }
                                                }
                                        }
                                        else if((output[move]=='\0') && (((prev==9) && (move==2)) || ((prev==2) && (move==9))))
                                        {
                                               output[move]=me;
                                               output[6]=eva;
                                               printf("Eva: Here's your deck -\n");
                                               display(output);
                                               printf("\nYou: ");
                                               scanf("%d",&move);
                                               if((move!=4) && (output[move]=='\0'))
                                               {
                                                       output[move]=me;
                                                       output[4]=eva;
                                                       printf("Eva: Here's your deck -\n");
                                                       display(output);
                                                       printf("Yayayaaa... I won!\nThis is where we stand -\n");
                                                       score[0]++;
                                                       printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);        
                                               }
                                               else if((move==4) && (output[move]=='\0'))
                                               {
                                                        output[move]=me;
                                                        output[7]=eva;
                                                        printf("Eva: Here's your deck -\n");
                                                        display(output);
                                                        printf("\nYou: ");
                                                        scanf("%d",&move);
                                                        if((move!=3) && (output[move]=='\0'))
                                                        {
                                                                output[move]=me;
                                                                output[3]=eva;
                                                                printf("Eva: Here's your deck -\n");
                                                                display(output);
                                                                printf("Yayayaaa... I won!\nThis is where we stand -\n");
                                                                score[0]++;
                                                                printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);        
                                                        }
                                                        else if((move==3) && (output[move]=='\0'))
                                                        {
                                                                output[move]=me;
                                                                output[1]=eva;
                                                                printf("Eva: Here's your deck -\n");
                                                                display(output);
                                                                printf("Hehe... If I coudnt win, so what? I made sure that you don't win either :)\nThis is where we stand -\n");
                                                                score[1]++;
                                                                printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);
                                                        }
                                                }
                                        }
                                        else if((output[move]=='\0') && (((prev==7) && (move==2)) || ((prev==2) && (move==7))))
                                        {
                                               output[move]=me;
                                               output[4]=eva;
                                               printf("Eva: Here's your deck -\n");
                                               display(output);
                                               printf("\nYou: ");
                                               scanf("%d",&move);
                                               if((move!=6) && (output[move]=='\0'))
                                               {
                                                       output[move]=me;
                                                       output[6]=eva;
                                                       printf("Eva: Here's your deck -\n");
                                                       display(output);
                                                       printf("Yayayaaa... I won!\nThis is where we stand -\n");
                                                       score[0]++;
                                                       printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);        
                                               }
                                               else if((move==6) && (output[move]=='\0'))
                                               {
                                                        output[move]=me;
                                                        output[9]=eva;
                                                        printf("Eva: Here's your deck -\n");
                                                        display(output);
                                                        printf("\nYou: ");
                                                        scanf("%d",&move);
                                                        if((move!=1) && (output[move]=='\0'))
                                                        {
                                                                output[move]=me;
                                                                output[1]=eva;
                                                                printf("Eva: Here's your deck -\n");
                                                                display(output);
                                                                printf("Yayayaaa... I won!\nThis is where we stand -\n");
                                                                score[0]++;
                                                                printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);        
                                                        }
                                                        else if((move==1) && (output[move]=='\0'))
                                                        {
                                                                output[move]=me;
                                                                output[3]=eva;
                                                                printf("Eva: Here's your deck -\n");
                                                                display(output);
                                                                printf("Hehe... If I coudnt win, so what? I made sure that you don't win either :)\nThis is where we stand -\n");
                                                                score[1]++;
                                                                printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);
                                                        }
                                                }
                                        }
                                        else if((output[move]=='\0') && (((prev==7) && (move==6)) || ((prev==6) && (move==7))))
                                        {
                                               output[move]=me;
                                               output[8]=eva;
                                               printf("Eva: Here's your deck -\n");
                                               display(output);
                                               printf("\nYou: ");
                                               scanf("%d",&move);
                                               if((move!=2) && (output[move]=='\0'))
                                               {
                                                       output[move]=me;
                                                       output[2]=eva;
                                                       printf("Eva: Here's your deck -\n");
                                                       display(output);
                                                       printf("Yayayaaa... I won!\nThis is where we stand -\n");
                                                       score[0]++;
                                                       printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);        
                                               }
                                               else if((move==2) && (output[move]=='\0'))
                                               {
                                                        output[move]=me;
                                                        output[1]=eva;
                                                        printf("Eva: Here's your deck -\n");
                                                        display(output);
                                                        printf("\nYou: ");
                                                        scanf("%d",&move);
                                                        if((move!=9) && (output[move]=='\0'))
                                                        {
                                                                output[move]=me;
                                                                output[9]=eva;
                                                                printf("Eva: Here's your deck -\n");
                                                                display(output);
                                                                printf("Yayayaaa... I won!\nThis is where we stand -\n");
                                                                score[0]++;
                                                                printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);        
                                                        }
                                                        else if((move==9) && (output[move]=='\0'))
                                                        {
                                                                output[move]=me;
                                                                output[3]=eva;
                                                                printf("Eva: Here's your deck -\n");
                                                                display(output);
                                                                printf("Hehe... If I coudnt win, so what? I made sure that you don't win either :)\nThis is where we stand -\n");
                                                                score[1]++;
                                                                printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);
                                                        }
                                                }
                                        }
                                        else if((output[move]=='\0') && (((prev==2) && (move==8)) || ((prev==8) && (move==2))))
                                        {
                                               output[move]=me;
                                               output[4]=eva;
                                               printf("Eva: Here's your deck -\n");
                                               display(output);
                                               printf("\nYou: ");
                                               scanf("%d",&move);
                                               if((move!=6) && (output[move]=='\0'))
                                               {
                                                       output[move]=me;
                                                       output[6]=eva;
                                                       printf("Eva: Here's your deck -\n");
                                                       display(output);
                                                       printf("Yayayaaa... I won!\nThis is where we stand -\n");
                                                       score[0]++;
                                                       printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);        
                                               }
                                               else if((move==6) && (output[move]=='\0'))
                                               {
                                                        output[move]=me;
                                                        output[9]=eva;
                                                        printf("Eva: Here's your deck -\n");
                                                        display(output);
                                                        printf("\nYou: ");
                                                        scanf("%d",&move);
                                                        if((move!=1) && (output[move]=='\0'))
                                                        {
                                                                output[move]=me;
                                                                output[1]=eva;
                                                                printf("Eva: Here's your deck -\n");
                                                                display(output);
                                                                printf("Yayayaaa... I won!\nThis is where we stand -\n");
                                                                score[0]++;
                                                                printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);        
                                                        }
                                                        else if((move==1) && (output[move]=='\0'))
                                                        {
                                                                output[move]=me;
                                                                output[3]=eva;
                                                                printf("Eva: Here's your deck -\n");
                                                                display(output);
                                                                printf("Hehe... If I coudnt win, so what? I made sure that you don't win either :)\nThis is where we stand -\n");
                                                                score[1]++;
                                                                printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);
                                                        }
                                                }
                                        }
                                        else if((output[move]=='\0') && (((prev==6) && (move==4)) || ((prev==4) && (move==6))))
                                        {
                                               output[move]=me;
                                               output[2]=eva;
                                               printf("Eva: Here's your deck -\n");
                                               display(output);
                                               printf("\nYou: ");
                                               scanf("%d",&move);
                                               if((move!=8) && (output[move]=='\0'))
                                               {
                                                       output[move]=me;
                                                       output[8]=eva;
                                                       printf("Eva: Here's your deck -\n");
                                                       display(output);
                                                       printf("Yayayaaa... I won!\nThis is where we stand -\n");
                                                       score[0]++;
                                                       printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);        
                                               }
                                               else if((move==8) && (output[move]=='\0'))
                                               {
                                                        output[move]=me;
                                                        output[9]=eva;
                                                        printf("Eva: Here's your deck -\n");
                                                        display(output);
                                                        printf("\nYou: ");
                                                        scanf("%d",&move);
                                                        if((move!=1) && (output[move]=='\0'))
                                                        {
                                                                output[move]=me;
                                                                output[1]=eva;
                                                                printf("Eva: Here's your deck -\n");
                                                                display(output);
                                                                printf("Yayayaaa... I won!\nThis is where we stand -\n");
                                                                score[0]++;
                                                                printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);        
                                                        }
                                                        else if((move==1) && (output[move]=='\0'))
                                                        {
                                                                output[move]=me;
                                                                output[3]=eva;
                                                                printf("Eva: Here's your deck -\n");
                                                                display(output);
                                                                printf("Hehe... If I coudnt win, so what? I made sure that you don't win either :)\nThis is where we stand -\n");
                                                                score[1]++;
                                                                printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);
                                                        }
                                                }
                                        }
                                        else if((output[move]=='\0') && (((prev==2) && (move==4)) || ((prev==4) && (move==2))))
                                        {
                                               output[move]=me;
                                               output[3]=eva;
                                               printf("Eva: Here's your deck -\n");
                                               display(output);
                                               printf("\nYou: ");
                                               scanf("%d",&move);
                                               if((move!=7) && (output[move]=='\0'))
                                               {
                                                       output[move]=me;
                                                       output[7]=eva;
                                                       printf("Eva: Here's your deck -\n");
                                                       display(output);
                                                       printf("Yayayaaa... I won!\nThis is where we stand -\n");
                                                       score[0]++;
                                                       printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);        
                                               }
                                               else if((move==7) && (output[move]=='\0'))
                                               {
                                                        output[move]=me;
                                                        output[1]=eva;
                                                        printf("Eva: Here's your deck -\n");
                                                        display(output);
                                                        printf("\nYou: ");
                                                        scanf("%d",&move);
                                                        if((move!=9) && (output[move]=='\0'))
                                                        {
                                                                output[move]=me;
                                                                output[9]=eva;
                                                                printf("Eva: Here's your deck -\n");
                                                                display(output);
                                                                printf("Yayayaaa... I won!\nThis is where we stand -\n");
                                                                score[0]++;
                                                                printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);        
                                                        }
                                                        else if((move==9) && (output[move]=='\0'))
                                                        {
                                                                output[move]=me;
                                                                output[8]=eva;
                                                                printf("Eva: Here's your deck -\n");
                                                                display(output);
                                                                printf("Hehe... If I coudnt win, so what? I made sure that you don't win either :)\nThis is where we stand -\n");
                                                                score[1]++;
                                                                printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);
                                                        }
                                                }
                                        }
                                        else if((output[move]=='\0') && (((prev==2) && (move==6)) || ((prev==6) && (move==2))))
                                        {
                                               output[move]=me;
                                               output[3]=eva;
                                               printf("Eva: Here's your deck -\n");
                                               display(output);
                                               printf("\nYou: ");
                                               scanf("%d",&move);
                                               if((move!=7) && (output[move]=='\0'))
                                               {
                                                       output[move]=me;
                                                       output[7]=eva;
                                                       printf("Eva: Here's your deck -\n");
                                                       display(output);
                                                       printf("Yayayaaa... I won!\nThis is where we stand -\n");
                                                       score[0]++;
                                                       printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);        
                                               }
                                               else if((move==7) && (output[move]=='\0'))
                                               {
                                                        output[move]=me;
                                                        output[9]=eva;
                                                        printf("Eva: Here's your deck -\n");
                                                        display(output);
                                                        printf("\nYou: ");
                                                        scanf("%d",&move);
                                                        if((move!=1) && (output[move]=='\0'))
                                                        {
                                                                output[move]=me;
                                                                output[1]=eva;
                                                                printf("Eva: Here's your deck -\n");
                                                                display(output);
                                                                printf("Yayayaaa... I won!\nThis is where we stand -\n");
                                                                score[0]++;
                                                                printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);        
                                                        }
                                                        else if((move==1) && (output[move]=='\0'))
                                                        {
                                                                output[move]=me;
                                                                output[4]=eva;
                                                                printf("Eva: Here's your deck -\n");
                                                                display(output);
                                                                printf("Hehe... If I coudnt win, so what? I made sure that you don't win either :)\nThis is where we stand -\n");
                                                                score[1]++;
                                                                printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);
                                                        }
                                                }
                                        }
                                        else if((output[move]=='\0') && (((prev==6) && (move==8)) || ((prev==8) && (move==6))))
                                        {
                                               output[move]=me;
                                               output[9]=eva;
                                               printf("Eva: Here's your deck -\n");
                                               display(output);
                                               printf("\nYou: ");
                                               scanf("%d",&move);
                                               if((move!=1) && (output[move]=='\0'))
                                               {
                                                       output[move]=me;
                                                       output[1]=eva;
                                                       printf("Eva: Here's your deck -\n");
                                                       display(output);
                                                       printf("Yayayaaa... I won!\nThis is where we stand -\n");
                                                       score[0]++;
                                                       printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);        
                                               }
                                               else if((move==1) && (output[move]=='\0'))
                                               {
                                                        output[move]=me;
                                                        output[3]=eva;
                                                        printf("Eva: Here's your deck -\n");
                                                        display(output);
                                                        printf("\nYou: ");
                                                        scanf("%d",&move);
                                                        if((move!=7) && (output[move]=='\0'))
                                                        {
                                                                output[move]=me;
                                                                output[7]=eva;
                                                                printf("Eva: Here's your deck -\n");
                                                                display(output);
                                                                printf("Yayayaaa... I won!\nThis is where we stand -\n");
                                                                score[0]++;
                                                                printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);        
                                                        }
                                                        else if((move==7) && (output[move]=='\0'))
                                                        {
                                                                output[move]=me;
                                                                output[4]=eva;
                                                                printf("Eva: Here's your deck -\n");
                                                                display(output);
                                                                printf("Hehe... If I coudnt win, so what? I made sure that you don't win either :)\nThis is where we stand -\n");
                                                                score[1]++;
                                                                printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);
                                                        }
                                                }
                                        }
                                        else if((output[move]=='\0') && (((prev==4) && (move==8)) || ((prev==8) && (move==4))))
                                        {
                                               output[move]=me;
                                               output[7]=eva;
                                               printf("Eva: Here's your deck -\n");
                                               display(output);
                                               printf("\nYou: ");
                                               scanf("%d",&move);
                                               if((move!=3) && (output[move]=='\0'))
                                               {
                                                       output[move]=me;
                                                       output[3]=eva;
                                                       printf("Eva: Here's your deck -\n");
                                                       display(output);
                                                       printf("Yayayaaa... I won!\nThis is where we stand -\n");
                                                       score[0]++;
                                                       printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);        
                                               }
                                               else if((move==3) && (output[move]=='\0'))
                                               {
                                                        output[move]=me;
                                                        output[1]=eva;
                                                        printf("Eva: Here's your deck -\n");
                                                        display(output);
                                                        printf("\nYou: ");
                                                        scanf("%d",&move);
                                                        if((move!=9) && (output[move]=='\0'))
                                                        {
                                                                output[move]=me;
                                                                output[9]=eva;
                                                                printf("Eva: Here's your deck -\n");
                                                                display(output);
                                                                printf("Yayayaaa... I won!\nThis is where we stand -\n");
                                                                score[0]++;
                                                                printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);        
                                                        }
                                                        else if((move==9) && (output[move]=='\0'))
                                                        {
                                                                output[move]=me;
                                                                output[6]=eva;
                                                                printf("Eva: Here's your deck -\n");
                                                                display(output);
                                                                printf("Hehe... If I coudnt win, so what? I made sure that you don't win either :)\nThis is where we stand -\n");
                                                                score[1]++;
                                                                printf("Me: %d | Draw: %d | You: %d",score[0],score[1],score[2]);
                                                        }
                                                }
                                        }    
                                }
                        }      
                }
                
                printf("\nFeeling high for another round? :D\n\nYou: ");
                fgets(input,30,stdin);
                fgets(input,30,stdin);
                
                if((strstr(input,"Yes")==0) || (strstr(input,"yes")==0))
                {
                        printf("Eva: It was nice playing with you (^^)\nWe shall meet again :s\nByyeee... Love Ya!\n\n");
                        printf("Eva, PURE IMAGINATION!\n- Shubham Mahajan\n");
                }
        }while(strstr(input,"Yes") || strstr(input,"yes"));
               
}

void display(char output[10])
{
        int i,j;
        for(i=0;i<11;i++)
        {
                printf("-");
        }
        printf("\n");
        for(i=1;i<=9;i++)
        {
                printf("| %c ",output[i]);
                if(i%3==0)
                {
                        printf("|\n");  
                        for(j=0;j<11;j++)
                        {
                                printf("-");
                        }       
                        printf("\n");        
                }
        }
}
