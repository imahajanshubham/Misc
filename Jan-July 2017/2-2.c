#include "stdio.h"
//#include "stdio"   - Better, use "stdio.h", It's an error in Linux.


#define LIM 1000


void main( void ) {


    char s[LIM];
    // String s was undeclared...


    int i, j, c;
    // i, j and c were undeclared..


    // You had wrote c! = '0'.... This is wrong.
    // It should be != i.e. c != '0'...


    for( i = 0; (i < LIM -1) * ( (c = getchar()) != '@' ) * (c != '\n') ; ++i )
    // for(i=0; i < LIM-1 * (c=getchar()) != '\n' * c! = '@'; ++1) 
        
        
        s[i]=c; // { - No brackets needed Here...


    s[i] = '\0';


       for(j=0; s[j] != '\0'; j++)
            printf("%c", s[j]);

       
    // for(j=0 ; j ! = '@' ; j++)         
        // printf("%d", i);


/*without using || */
        
/*      Observe the changes above and see what modifications to be made below :)
 
        for(i=0; ( i < LIM-1) + (c=getchar()) != '\n' + c! = '@'; ++1)
        s[i]=c;{
        for(j=0 ; j ! = '@' ; j++)
        printf("%c", c;)
    }
*/

    
 }
