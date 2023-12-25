// Author Ajinkya Salunke
// Date: 25 Dec 2023

// Importing the standard libraries
#include<stdio.h>
#include<stdlib.h>

// Calculating the first day of every year
int get_1st_weekDay(int year){
    int day;
    day = (((year -1) * 365) + ((year - 1) / 4 ) - ((year -1 ) / 100) + ((year) / 400) + 1) % 7;
    return day; 
}



// Initializing main function
int main(){

    // Giving a grey color to the system display
    system("Color 3f");

    // Declaring the variables that we needed
    int year, month, day, daysInMonth, weekDay=0, startingDay;

    // Printing and taking year as input
    printf("\nEnter your desired year:");
    scanf("%d", &year);
    printf("\n\n********Calender of this %d year**********\n", year);

    // Character pointer array to store the names of months
    char *months[] = {"january", "Feburary", "March", "April", "May", "Jun", "July", "August", "September", "October", "November", "December"};

    // Deermining the dates in every month
    int monthDays[] = {31,28,31,30,31,30,31,31,30,31,30,31};



    // Reseting the february month value of every leap year
    if ((year%4==0 && year%100!=0) || (year%400==0)){
        monthDays[1] = 29;
        printf("\n\nThis is a leap year\n");
    }

    // Determining the starting day of the week
        startingDay = get_1st_weekDay(year);



    // Printing the months along with the days and dates
    for(month=0; month<12; month++){
        
        // setting the days in the particular months
        daysInMonth = monthDays[month];

        printf("\n\n-------------------%s--------------------\n", months[month]);
        printf("\n\n   Sun   Mon   Tue   Wed   Thu   Fri   Sat\n");



        // Initializing every day of the month
        for (weekDay=0; weekDay<startingDay; weekDay++){
            printf("      ");
        }



        // Printing Days in the month
        for(day=1; day<(daysInMonth+1); day++){
            printf("%6d", day);

            if (6 < ++weekDay){
                printf("\n");
                weekDay = 0;
            }
            startingDay = weekDay;
        }
    }

    // Returning 0 after sucessful execution
    return 0;
}