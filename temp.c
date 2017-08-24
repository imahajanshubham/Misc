#include <stdio.h>
#include <string.h>

void escape ( char s[], char t[]);


void escape ( char s[] , char t[] ) {

    int i = 0, j = 0;

    while( s[i] != '\0' ) {

        switch ( s[i] ) {

            case '\t':
                t[j] = '\\';
                j++;
                t[j]  = 't';
                break;

            case '\n':
                t[j] = '\\';
                j++;
                t[j]  = 't';
                break;

            default:
                t[j] = s[i];
                break;
        }

        j++;
        i++;
    }
}

int main() {

    char s[100];
    char t[100];
   
    //s[0] = '\0';

    // strcat( s, "\nHello\tWorld.\n\n" );
    // fgets( s, 100, stdin );
    gets( s );

    escape(s,t);

    puts( t );
}
