/*-*-coding:utf-8 -*- 
 *Auto updated?
 *   Yes
 *File :
 *   eliminator.c
 *Author :
 *   Daniel Martins Pão Alvo
 *
 *Created:
 *   April 19, 2022, 11:09:01 PM GMT+1
 *Last edited:
 *   May 2, 2022, 4:20:04 PM GMT+1
 *
 *Description:
 *   Functions related to removing flights and reservations as declared
 *   in "eliminator.h"
 *
 *Dependencies:
 *   ["dateTime.h","systemCore.h","airport.h","bool.h","flight.h", 
 *    "reservation.h"]
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "dateTime.h"
#include "systemCore.h"
#include "airport.h"
#include "bool.h"
#include "flight.h"
#include "reservation.h"

/* -------------------------- Elimation Functions --------------------------- */

int FlightRemover(Flight FlightST[],char code[],int flight_count){
    int index,counter;
    counter = 0;

    for (index = 0; index < flight_count; index++){
        if(!strcmp(FlightST[index].flight_code,code)){
            DeleteList(FlightST[index].flight_reservations);
            FlightST[index].flight_reservations = NULL;
            counter +=1;
        } else{
            FlightST[index - counter] = FlightST[index]; 
        }
    }
    if(!counter){
        printf("not found\n");
        return flight_count;
    } else {
        return flight_count - counter;
    }
}

void ReservationRemover(Flight FlightST[],char code[],int flight_count){
    int index;
    LinkList temp;
     
    for (index = 0; index < flight_count;index++){
        temp = Lookup(&FlightST[index].flight_reservations,code);
        if(temp){
            FlightST[index].reservation_capacity -= temp->reservation.numPassangers;
            Delete(&FlightST[index].flight_reservations,temp->reservation);
            return;
        }
    }
    free(temp);
    printf("not found\n");
}

int SystemEliminator(Flight FlightST[],unsigned int flight_count){
    char temp_Code[MAX_INPUT];
    int len_code;

    scanf("%s",temp_Code);
    len_code = strlen(temp_Code);
    if(len_code <= 7){
        flight_count = FlightRemover(FlightST,temp_Code,flight_count);
        return flight_count;
    } else{
        ReservationRemover(FlightST,temp_Code,flight_count);
    }
    return flight_count;
}

/* ------------------------------ End of File ------------------------------- */