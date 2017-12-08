//Program that reads in a set of rainfall figures for a city, particularly
//average monthly rainfall and actual monthly rainfall figures for each month 
//of the year, and displays a formatted table showing the average rainfall 
//for each month and how much above or below average the actual monthly 
//rainfall was.
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cmath>
using namespace std;

void inputRainFallFigures(double avgRFF[], double actlRFF[], int months[], int arraySize, int& input);
//Precondition: arraySize >= 1 && <= 12. 
//Postcondition: avgRFF[] and actlRFF[] have been filled with values read in from the keyboard. 

void displayTable( int months[], const double avgRFF[], const double actlRFF[], int arraySize, int currentMonth); 
//Precondition: a[] is not changed by this function.
//Postcondition: Displays a formatted table showing the monthly averge rainfall
//for each month and how much above or below average the actual monthly rainfall was.

void rearrangeTwelveMonths(int currentMonth, int m[], int arraySize); 
//Precondition: currentMonth <= 1 && >= 12. All indexed variables of array m 
//have been initialized. arraySize >= 1 && <= 12.
//Postcondition: Rearranges values of the indexed variables of array m.

void monthString(int monthNumber);
//Precondition: monthNumber >= 1 && <= 12
//Postcondition: Outputs the corresponding month name to monthNumber.

int previousMonthIndex(int m[], int i, int arraySize, int& previousMonth);
//Precondition: The array month has been completely filled. i >= 1 && <= 11.
//arraySize == 12. cM >= 1 && <= 12.
//Postcondition: Returns the previous month number starting from the 
//number preceding cM.

void swap(int& m1, int& m2);
//Preconditon: m1 and m2 >= 1 && <= 12.
//Postcondition: Interchanges values between m1 and m2.

void printTable(int month[], const double avgRFF[], const double actlRFF[], int sIndex, int eIndex, int orgIndex);
//Precondition: The arrays month, avgRFF and actlRFF are filled. sIndex
//is either 0, 4 or 8. eIndex is either 4, 8, or 12. orgIndex is either 1, 2 or 3.
//Postcondition: Prints out the month name, average and actual monthly rainfall for each month.

const int NUMBER_OF_MONTHS = 12;

int main()
{
    int cM, m[12] = {1,2,3,4,5,6,7,8,9,10,11,12};
    double avgRFF[12], actlRFF[12];

    inputRainFallFigures(avgRFF, actlRFF, m, NUMBER_OF_MONTHS, cM);
    displayTable(m, avgRFF, actlRFF, NUMBER_OF_MONTHS, cM);

    return 0;
}

void inputRainFallFigures(double avgRFF[], double actlRFF[], int months[], int arraySize, int& input)
{
    cout<<"Enter average monthly rainfall figures for each month (enter -1 when finished):\n";

    int index = 0;
    double next; 

    cin>>next;

    while (next >=0 && index < arraySize)
    {
        avgRFF[index] = next;
        index++;
        cin>>next;
    }

    cout<<"\nWhat is the current month? ";
    cin>>input;

    int index2 = 0;
    double next2;

    cout<<"\nEnter actual monthly rainfall figures for each month (enter -1 when finished):\n";
    cin>>next2;

    while (next2 >= 0 && index2 < arraySize)
    {
        actlRFF[index2] = next2;
        index2++;
        cin>>next2;
    }

    cout<<"\n\n\n\n";
}

void rearrangeTwelveMonths(int currentMonth, int months[], int arraySize)
{
    int indexOfPreviousMonth, previousMonth = currentMonth - 1;

    for (int index = arraySize - 1; index >= 0; index--)
    {
        indexOfPreviousMonth = previousMonthIndex(months, index, arraySize, previousMonth);
        swap(months[index], months[indexOfPreviousMonth]);
        --previousMonth;
    }
}

void swap(int& m1, int& m2)
{
    if (m1 == m2)
        return;

    int temp = m1;
    m1 = m2; 
    m2 = temp;
}

int previousMonthIndex(int m[], int i, int arraySize, int& previousMonth)
{
    if (previousMonth < 1)
        previousMonth = 12;

    int j;
    for (j = i; j >= 0; j--)
    {
        if (m[j] == previousMonth)
            break;
    }
    return j;
}

void displayTable(int months[], const double avgRFF[], const double actlRFF[], int arraySize, int currentMonth)
{
    cout<<setw(55)<<"Monthly Rainfall Figures Table\n\n";
    cout<<setw(55)<<"______________________________\n\n";

    if (currentMonth > 1)
        rearrangeTwelveMonths(currentMonth, months, arraySize);

    for (int i = 0; i < 3; i++)
        printTable(months, avgRFF, actlRFF, 0, 4, i);

    cout<<endl;

    for (int i = 0; i < 3; i++)
        printTable(months, avgRFF, actlRFF, 4, 8, i);

    cout<<endl;

    for (int i = 0; i < 3; i++)
        printTable(months, avgRFF, actlRFF, 8, arraySize, i);

    cout<<"\n\n";
}

void monthString(int monthNumber)
{
    switch(monthNumber)
    {
        case 1:
            cout<<setw(16)<<"January";
            break;
        case 2:
            cout<<setw(16)<<"February";
            break;
        case 3:
            cout<<setw(16)<<"March";
            break;
        case 4:
            cout<<setw(16)<<"April";
            break;
        case 5: 
            cout<<setw(16)<<"May";
            break;
        case 6:
            cout<<setw(16)<<"June";
            break;
        case 7:
            cout<<setw(16)<<"July";
            break;
        case 8:
            cout<<setw(16)<<"August";
            break;
        case 9:
            cout<<setw(16)<<"September";
            break;
        case 10:
            cout<<setw(16)<<"October";
            break;
        case 11:
            cout<<setw(16)<<"November";
            break;
        case 12:
            cout<<setw(16)<<"December";
            break;
        default:
            {
                cout<<"Fatal Error: Aborting program.";
                cout<<monthNumber;
                system("pause");
                exit(1);
                break;
            }
    }
}

void printTable(int months[], const double avgRFF[], const double actlRFF[], int sIndex, int eIndex,
        int orgIndex)
{
    cout.setf(ios::showpoint);
    cout.setf(ios::fixed);
    cout.precision(1);

    for (int h = sIndex; h < eIndex; h++)
    {
        if (orgIndex == 0)
            monthString(months[h]);
        else if (orgIndex == 1)
            cout<<setw(16)<<actlRFF[h];
        else
        {
            if (actlRFF[h] > avgRFF[h])
                cout<<setw(5)<<actlRFF[h] - avgRFF[h]<<" abv average.";
            else
                cout<<setw(5)<<avgRFF[h] - actlRFF[h]<<" blw average.";
        }
    }

    cout<<endl;
}
