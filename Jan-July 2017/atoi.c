/*
#include "stdio.h"
void main()
{
int atoi(char s[])
{
        int i, n ;
        n=0;
        for(i=0 ; s[i]>='0' && s[i]<= '9'; ++i)
        n = 10 * n + (s[i] - '0');
        return n;
}
}
*/


/*
 *      Few things...
 *          1. A Function can't be defined inside another function,
 *             maybe it's possible, But I don't know.
 *             
 *          2. atoi() is a standard library function... So, you cant modify it...
 *             Therefore, change your atoi() to something else like myatoi()...
 *             
 *          3. line int atoi(char s[]) means,
 *             atoi is a function which demands a string as input and will return some integer value.
 *             So,
 *             We need to pass the arguements/string to this function atoi()...
 */


# include "stdio.h"
# include "string.h"


// This is called Function Declaration, used to tell compiler in advance that,
// we will use this function somewhere else in the program...
int myatoi( char s[] );


void main() {


    int number;
    char s[100];


    // Giving your String some input... you can do this using scanf too.
    strcpy( s, "1234Hello" );


    // Now, need to call the myatoi() and store the value it returns....
   number = myatoi( s );


   printf( "%d", number );
}


int myatoi(char s[]) {


        int i, n ;
        n=0;
        
        
        for(i=0 ; s[i] >= '0' && s[i] <= '9'; ++i)
            n = 10 * n + (s[i] - '0');
        
        
        return n;
}
