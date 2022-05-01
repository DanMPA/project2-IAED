/*-*-coding:utf-8 -*- 
 *Auto updated?
 *   Yes
 *File :
 *   datetime.c
 *Author :
 *   Daniel Martins Pão Alvo
 *
 *Created:
 *   April 19, 2022, 11:11:57 PM GMT+1
 *Last edited:
 *   April 20, 2022, 3:58:29 PM GMT+1
 *
 *Description:
 *   Date and Time Functions as decleared in "dateTime.h".
 *
 *Dependencies:
 *   ["dateTime.h"]
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "dateTime.h"

typedef unsigned int uint;

/* -------------------------- Date Time Functions --------------------------- */

int DateTimeToTimeStamp(uint year,uint month,uint day,
            uint hour, uint minutes,uint seconds){
    
    int timestamp;
    if(month <= 2){
        month += 12;
        year -= 1;
    }
    timestamp = (365 * year) + (year / 4) - (year / 100) + (year / 400);
    timestamp += (30 * month) + (3 * (month + 1) / 5) + day;
    timestamp -= 719561;
    timestamp *= 86400;
    
    timestamp += (3600 * hour) + (60 * minutes) + seconds;
    return timestamp;
} 

void PrintTimeStamp(int timestamp,char flag){
    int year, month, days, hours, minutes, seconds, a,b,c,d,e,f;

    if(timestamp < 1){
        timestamp = 0;
    }

    seconds = timestamp % 60;
    timestamp /= 60;

    minutes = timestamp % 60;
    timestamp /= 60;

    hours = timestamp % 24;
    timestamp /= 24;

    a = (uint) ((4 * timestamp + 102032) / 146097 + 15);
    b = (uint) (timestamp + 2442113 + a - (a / 4));
    c = (20 * b - 2442) / 7305;
    d = b - 365 * c - (c / 4);
    e = d * 1000 / 30601;
    f = d - e * 30 - e * 601 / 1000;

    if(e <= 13){
        c -= 4716;
        e -= 1;
    } else{
        c -= 4715;
        e -= 13;
    }

    year = c;
    month = e;
    days = f;

    if(flag == 'm'){
        printf("%02d-%02d-%04d %02d:%02d\n",days,month,year,hours,minutes);
    } else if(flag == 'd'){
        printf("%02d-%02d-%04d\n",days,month,year);
    } else if(flag == 't'){
        printf("%02d:%02d\n",hours,minutes);
    } else{
        printf("%02d-%02d-%04d %02d:%02d:%02d\n",days,month,year,hours,minutes,seconds);
    }
    
}

int TimeToTimeStamp(uint hour, uint minutes,uint seconds){
    return hour * 3600 + minutes * 60 + seconds;
}

int DateAdvancer(unsigned int curent_date){
    unsigned int day,month,year,timestamp;

    scanf("%u-%u-%u",&day,&month,&year);

    timestamp = DateTimeToTimeStamp(year,month,day,0,0,0);
    if (timestamp > (curent_date+SEC_IN_YEAR) || timestamp < curent_date){
        printf("invalid date\n");
        return curent_date;
    }
    
    PrintTimeStamp(timestamp,'d');
    return timestamp;
}

/* ------------------------------ End of File ------------------------------- */
