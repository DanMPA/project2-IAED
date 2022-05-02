/*-*-coding:utf-8 -*- 
 *Auto updated?
 *   Yes
 *File :
 *   reservationsManipulators.c
 *Author :
 *   Daniel Martins Pão Alvo
 *
 *Created:
 *   April 19, 2022, 11:17:20 PM GMT+1
 *Last edited:
 *   May 2, 2022, 4:18:49 PM GMT+1
 *
 *Description:
 *   Reservation related functions as decleared in "reservation.h"
 *
 *Dependencies:
 *   ["systemCore.h","airport.h","bool.h","dateTime.h","flight.h",
 *    "reservation.h"]
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "systemCore.h"
#include "airport.h"
#include "bool.h"
#include "dateTime.h"
#include "flight.h"
#include "reservation.h"
#include "eliminator.h"

/* ---------------------- Reservation Error Functions ----------------------- */

int E_ValidReservationCode(char reservation_code[]){
    int counter,code_length;
    code_length = strlen(reservation_code);
    if(code_length < RESERVATION_CODE_LEN){
        printf("invalid reservation code\n");
        return FALSE;
    }
    for (counter = 0; counter < code_length; counter++){
        if(isalnum(reservation_code[counter])){
            if(!isdigit(reservation_code[counter])){
                if(!isupper(reservation_code[counter])){
                    printf("invalid reservation code\n");
                    return FALSE;
                }
            }
        }else{
            printf("invalid reservation code\n");
            return FALSE;
        }
    }
    return TRUE;
}

int E_FlightExists_O1(Flight FlightsST[],char flight_code[],unsigned int date,
        unsigned int flight_count){
            
    if(FlightFinderDate(FlightsST,flight_code,date,flight_count) == -1){
        printf("%s: flight does not exist\n",flight_code);
        return TRUE;
    }
    return FALSE;
}

int E_ReservationExists(Flight FlightsST[],int flight_count,
        char reservation_code[]){
            
    LinkList temp;
    int index;
    
    for(index = 0; index < flight_count;index++){
        temp = Lookup(&FlightsST[index].flight_reservations,reservation_code);
        if(temp){
            printf("%s: flight reservation already used\n",reservation_code);
            return TRUE;
        }
    }
    return FALSE;
}

int E_ReservationCapacityLimit(Flight FlightsST[],int flight_index,
        int reservation_capacity){
            
    if((FlightsST[flight_index].reservation_capacity + reservation_capacity) 
        > FlightsST[flight_index].flight_capacity){
        printf("too many reservations\n");
        return TRUE;
    }
    return FALSE;
}

int E_ValidReservationDate(unsigned int current_date,
        unsigned int reservation_date){
    
    if(current_date > reservation_date || 
        reservation_date >= reservation_date+SEC_IN_YEAR){
            printf("invalid date\n");
            return FALSE;
        }
    return TRUE;
}

int E_ValidReservationCapacity(int reservation_capacity){
    if(reservation_capacity <= 0){
        printf("invalid passenger number\n");
        return FALSE;
    }
    return TRUE;
}

int GenericReservationErrorFunctions(Flight FlightsST[],
        int flight_index,char flight_code[],unsigned int flight_count,
            unsigned int flight_date,
        char reservation_code[],int reservation_capacity,
        unsigned int system_date){

    if(E_ValidReservationCode(reservation_code) &&
       !E_FlightExists_O1(FlightsST,flight_code,flight_date,flight_count) &&
       !E_ReservationExists(FlightsST,flight_count,reservation_code) &&
       E_ValidReservationCapacity(reservation_capacity) &&
       !E_ReservationCapacityLimit(FlightsST,flight_index,reservation_capacity) &&
       E_ValidReservationDate(system_date,flight_date)){
           return TRUE;
    }
    return FALSE;
}

/* ----------------------- Reservation Adder Function ----------------------- */

void AddReservation(Flight FlightsST[],int flight_index,
        Reservation *temp_reservation,int temp_reservation_capacity){

    LinkList temp_link;

    if(!FlightsST[flight_index].flight_reservations){
        temp_link = NewLink(temp_reservation);
        FlightsST[flight_index].flight_reservations = temp_link;
        free(temp_reservation);
        FlightsST[flight_index].reservation_capacity += temp_reservation_capacity;
    } else if(FlightsST[flight_index].flight_reservations){
        SortedInsert(&FlightsST[flight_index].flight_reservations,temp_reservation);
        free(temp_reservation);
        FlightsST[flight_index].reservation_capacity += temp_reservation_capacity;
        FlightsST[flight_index].reservation_count += 1;
    }
    
}

int ReservationAdder(Flight FlightsST[],int flight_count,
                     unsigned int current_date){

    int day,month,year,flight_index, temp_reservation_capacity, date;
    char temp_flight_code[FLIGHT_CODE], temp_reservation_code[MAX_INPUT];
    
    Reservation * temp_reservation;

    scanf("%s %d-%d-%d",temp_flight_code,&day,&month,&year);

    date = DateTimeToTimeStamp(year,month,day,0,0,0);
    flight_index = FlightFinderDate(FlightsST,temp_flight_code,date,flight_count);
  
    if((getchar()) == '\n'){
        if(flight_index == -1){
            printf("%s: flight does not exist\n",temp_flight_code);
            return 0;
        }
        if(E_ValidReservationDate(current_date,date)){
            PrintReservation(&FlightsST[flight_index].flight_reservations);
        }
        return 0;
    }
    scanf("%s %d",temp_reservation_code,&temp_reservation_capacity);

    if(GenericReservationErrorFunctions(FlightsST,flight_index,temp_flight_code,
        flight_count,date,temp_reservation_code,temp_reservation_capacity,
        current_date)){

        temp_reservation = NewReservation(temp_reservation_code,temp_reservation_capacity);
        AddReservation(FlightsST,flight_index,temp_reservation,temp_reservation_capacity);

        return 1;
    }
    return 0;
}

/* ------------------------------ End of File ------------------------------- */
