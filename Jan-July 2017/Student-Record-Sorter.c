#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXNAME 30
#define MAXNUMBER 75
#define START 0
#define CHOICELENGTH 15

void getStudentData();
void getChoiceForHowToSort();

void sortAlongStudentID();
int makePartition(int, int);

void sortAlongStudentName();
void shorterNameFound();

void swapStudentRecords(int, int);
void showStudentRecord();

struct records {
    int studentId;
    char studentName[MAXNAME];
}noOfStudents[MAXNUMBER];

int counter, iterator, tempIterator, asciiValue, lowerIndex, higherIndex, tempStudentId;
char tempStudentName[MAXNAME], choice[CHOICELENGTH];

int main()
{
    counter = START;
    
    getStudentData();
        
    return 0;
}

void getStudentData()
{
    int addMore;
    system("clear");
    /*Getting the Student Record's Data from the User.*/            
    do {
        printf("Eva: Student - %d,\n",counter + 1);
        printf("     ID - ");    scanf("%d", &noOfStudents[counter].studentId);
        printf("     Name - ");    fgets(noOfStudents[counter].studentName, MAXNAME, stdin);    fgets(noOfStudents[counter++].studentName, MAXNAME, stdin);
                
        printf("\nEva: Want to add more?\nYou: ");    fgets(choice, CHOICELENGTH, stdin);    printf("\n");
    }while((strstr(choice,"Yes")) || (strstr(choice,"yes")));

    getChoiceForHowToSort();
}

void getChoiceForHowToSort()
{
    system("clear");
    
    /*Getting to know: How the User would like to Sort the Student Record.*/
    printf("Eva: How would you like to sort?\n     Student ID | Student Name.\n");
    printf("You: ");    fgets(choice, CHOICELENGTH, stdin);    printf("\n");
    
    if(strstr(choice, "Student ID")) {
        sortAlongStudentID(0, counter - 1);
        showStudentRecord();
    }
    
    else if(strstr(choice, "Student Name")) {
        sortAlongStudentName();
    }
}

void sortAlongStudentID(int lowerIndex, int higherIndex)
{
    int pivotIndex;
    
    /*Sorting the Student Record's Data using Quick Sort Algorithm.*/
    if (lowerIndex < higherIndex) {
        pivotIndex = makePartition(lowerIndex, higherIndex);
 
        sortAlongStudentID(lowerIndex, pivotIndex - 1);
        sortAlongStudentID(pivotIndex + 1, higherIndex);
    }
}

int makePartition(int lowerIndex, int higherIndex)
{
    int pivotValue, makePartitionCounter, makePartitionIterator;
    
    /*Partitioning the Student Record (just like Quick Sort in Arrays, but in this case, It's Structure).*/
    pivotValue = noOfStudents[higherIndex].studentId;
    makePartitionCounter = (lowerIndex - 1);
 
    for (int makePartitionIterator = lowerIndex; makePartitionIterator <= higherIndex - makePartitionIterator; makePartitionIterator++) {
        if (noOfStudents[makePartitionIterator].studentId <= pivotValue) {
            makePartitionCounter++;
            swapStudentRecords(makePartitionCounter, makePartitionIterator);
        }
    }
    
    swapStudentRecords(makePartitionCounter + 1, higherIndex);
    
    return (makePartitionCounter + 1);
}

void sortAlongStudentName()
{
    tempIterator = START;
                
    /*Sorting the Student Record's Data alphabetically (as Dictionary).*/
    for(iterator = START; iterator < counter - 1; iterator++) {
        
        /*If starting character of both the words are unequal, then they need to be sorted.*/
        if((asciiValue = noOfStudents[iterator].studentName[START]) > (asciiValue = noOfStudents[iterator+1].studentName[START])) {
            
            /*Swapping current and next Student Record's Data.*/
            swapStudentRecords(iterator, iterator + 1);
        }
        
        /*Otherwise, traversing till the unequal character is encountered or the string ends.*/
        else if((asciiValue = noOfStudents[iterator].studentName[START]) == (asciiValue = noOfStudents[iterator+1].studentName[START])) {
            
            /*Calling the function to traverse.*/
            shorterNameFound();
        }
    }
    
    showStudentRecord();
}

void shorterNameFound()
{
    /*Traversing till unequal or end of the string is encountered.*/
    while((asciiValue = noOfStudents[iterator].studentName[tempIterator]) == (asciiValue = noOfStudents[iterator+1].studentName[tempIterator])) {
        tempIterator++;
    }
    
    if((asciiValue = noOfStudents[iterator].studentName[tempIterator]) > (asciiValue = noOfStudents[iterator+1].studentName[tempIterator])) {
        
        /*Swapping current and next Student Record's Data.*/
        swapStudentRecords(iterator, iterator + 1);
    }
}

void swapStudentRecords(int previous, int next)
{
    /*Storing the current Student's ID and Name in Temporary ID and Name.*/
    tempStudentId = noOfStudents[previous].studentId;    strcpy(tempStudentName, noOfStudents[previous].studentName);
            
    /*Storing the next Student's ID and Name into current ones.*/
    noOfStudents[previous].studentId = noOfStudents[next].studentId; 
    strcpy(noOfStudents[previous].studentName, noOfStudents[next].studentName);
            
    /*Storing the Temporary ID and Name in next Student's ID and Name.*/
    noOfStudents[next].studentId = tempStudentId;
    strcpy(noOfStudents[next].studentName, tempStudentName);
    
    /*If Names are swapped, then they need to be checked with previous names too.*/
    iterator = -1;
}

void showStudentRecord()
{
    system("clear");
    
    /*Displaying Student Record's Data after sorting.*/
    printf("Eva: Here's your Data :)\n     ---\n");
    for(iterator = START; iterator < counter; iterator++) {
        printf("     %d.     %d\t",iterator + 1, noOfStudents[iterator].studentId);    puts(noOfStudents[iterator].studentName);
    }
    fflush(stdin);
}
