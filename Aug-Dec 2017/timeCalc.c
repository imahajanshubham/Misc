# include <iostream>


using namespace std;


/*
 *      Calculating Total Time of Two Different Class Objects using C++.
 *                               ----------
 *          
 *          Core Logics - 1. Values are assigned to 'data members' using Class Constructors.
 *                        2. In Case of No Value, Default Values are used.
 *                        3. A 'friend function' that processes/adds the Time of both the Objects.
 *                        4. Finnaly, print the Values of the third Object.
 */


class timeCalc {

    int hours, minutes;

    public:

    timeCalc ( int hrs = 0, int min = 0 ) {

        hours = hrs, minutes = min ;
    }

    friend timeCalc processTime( timeCalc currDay, timeCalc nextDay ) ;

    void displayTotalTime( void ) {

        cout << "\nHours - "   << hours   ;
        cout << "\nMinutes - " << minutes ;
    }
};


timeCalc processTime ( timeCalc currDay, timeCalc nextDay ) {

    timeCalc totalTime;

    totalTime.hours   = currDay.hours   + nextDay.hours   ;
    totalTime.minutes = currDay.minutes + nextDay.minutes ;

    for ( ; totalTime.minutes >= 60; totalTime.minutes -= 60 ) {

        totalTime.hours += 1;
    }

    return totalTime;
}


int main ( void ) {

    timeCalc currDay ( 3, 69 ), nextDay ( 3, 167 );

    timeCalc totalTime = processTime ( currDay, nextDay );

    totalTime.displayTotalTime ();
}
