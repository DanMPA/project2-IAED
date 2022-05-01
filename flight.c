/*-*-coding:utf-8 -*- 
 *Auto updated?
 *   Yes
 *File :
 *   flight.c
 *Author :
 *   Daniel Martins Pão Alvo
 *
 *Created:
 *   April 19, 2022, 11:14:24 PM GMT+1
 *Last edited:
 *   April 24, 2022, 12:41:06 PM GMT+1
 *
 *Description:
 *   Flight related functions as decleared in "flight.h"
 *
 *Dependencies:
 *   ["bool.h","flight.h","dateTime.h"]
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "bool.h"
#include "flight.h"
#include "dateTime.h"

typedef unsigned int uint;

/* ------------------------- Flight Error Functions ------------------------- */

int E_FlightCodeVerifier(char flight_code[]){
    int counter;
    unsigned char num_of_letters = 2;
    for (counter = 0; counter < FLIGHT_CODE; counter++){
        if(flight_code[counter] == '\0'){
            break;
        }
        if(counter<num_of_letters){
            if(!isupper(flight_code[counter])){
                printf("invalid flight code\n");
                return FALSE;
            }
        }else{
            if(!isdigit(flight_code[counter]) || flight_code[2] == '0'){
                printf("invalid flight code\n");
                return FALSE;
                }            
        }
    } 
    return TRUE;
}

int E_FlightExists_O0(Flight FlightST[],char flight_code[],uint date_ref,
    int flight_count){
    int counter;
    for (counter = 0; counter < flight_count; counter++){
        if(!strcmp(FlightST[counter].flight_code,flight_code) 
            && FlightST[counter].date == date_ref){
                printf("flight already exists\n");
                return TRUE;
            }
    }
    return FALSE;
}

int E_ValidAirport(Airport AirportST[],char airport_ID[],int airport_count){
    int counter;
    for (counter = 0; counter < airport_count; counter++){
        if(!strcmp(AirportST[counter].id,airport_ID)){
            return TRUE;
        }
    }
    printf("%s: no such airport ID\n",airport_ID);
    return FALSE;
}

int E_MAXFlights(int flight_count){
    if(flight_count == MAX_FLIGHTS){
        printf("too many flights\n");
        return TRUE;
    }
    return FALSE;
}

int E_ValidFlightDate(uint current_date,uint date_ref){
    if(current_date <= date_ref && date_ref <= (current_date + SEC_IN_YEAR)){
        return TRUE;
    }
    printf("invalid date\n");
    return FALSE;
}

int E_ValidDuration(uint duration){
    if(duration > (VALID_FLIGHT_DURATION * 3600)){
        printf("invalid duration\n");
        return FALSE;
    }
    return TRUE;
}

int E_ValidCapacity(uint capacity){
    if(capacity >= FLIGHT_CAPACITY_MIN){
        return TRUE;
    }
    printf("invalid capacity\n");
    return FALSE;
}

int GenericFlightErrorHandler(Airport AirportST[], Flight FlightST[],char temp_flight_code[],
    uint temp_datetime_ref,uint temp_duration_ref,uint flight_count,
    uint airport_count,char temp_airport_departure[],char temp_airport_arrival[],
    uint current_date, uint temp_capacity){
    
    return E_FlightCodeVerifier(temp_flight_code) &&
        !E_FlightExists_O0(FlightST,temp_flight_code,temp_datetime_ref,flight_count) &&
        E_ValidAirport(AirportST,temp_airport_departure,airport_count) &&
        E_ValidAirport(AirportST,temp_airport_arrival,airport_count) &&
        !E_MAXFlights(flight_count) &&
        E_ValidFlightDate(current_date,temp_datetime_ref) &&
        E_ValidDuration(temp_duration_ref) &&
        E_ValidCapacity(temp_capacity);

}

/* ---------------------------- Flight Functions ---------------------------- */

void FlightPrinter(Flight FlightST){
    printf("%s %s %s ",FlightST.flight_code,FlightST.airport_departure,FlightST.airport_arrival);
    PrintTimeStamp(FlightST.datetime,'m');
}

int FlightFinderDate(Flight SystemFlightsST[],char flight_code[],uint 
                        date,uint flight_count){
    uint counter;
    for (counter = 0; counter < flight_count; counter++){
        
        if(!strcmp(SystemFlightsST[counter].flight_code,flight_code) &&
            SystemFlightsST[counter].date == date){
                return counter;
        }
    }
    return -1;
}

void ListFlights(Flight FlightST[],uint flight_count){
    uint counter;
    for (counter = 0; counter < flight_count; counter++){
            FlightPrinter(FlightST[counter]);
    }
}

int FlightAdder(Airport AirportST[], Flight FlightST[],uint current_date,
    uint airport_count,uint flight_count){
        
    char temp_flight_code[FLIGHT_CODE], temp_airport_departure[AIRPORT_ID],
        temp_airport_arrival[AIRPORT_ID],mode;

    uint temp_date_ref, temp_datetime_ref, temp_duration_ref,
            temp_day, temp_month, temp_year,
            temp_hour, temp_min,
            temp_duration_hour, temp_duration_min, temp_capacity,
            counter;

    if((mode = getchar()) == '\n'){
        ListFlights(FlightST,flight_count);
        return 0;
    }

    scanf("%s %s %s %u-%u-%u %u:%u %u:%u %u",temp_flight_code, 
        temp_airport_departure, temp_airport_arrival,
        &temp_day, &temp_month, &temp_year,&temp_hour,&temp_min,
        &temp_duration_hour, &temp_duration_min, &temp_capacity);

    temp_date_ref = DateTimeToTimeStamp(temp_year,temp_month,temp_day,0,0,0);
    temp_datetime_ref = DateTimeToTimeStamp(temp_year,temp_month,temp_day,temp_hour,temp_min,0);
    temp_duration_ref = TimeToTimeStamp(temp_duration_hour,temp_duration_min,0);

    if (GenericFlightErrorHandler(AirportST,FlightST,temp_flight_code,temp_date_ref,
            temp_duration_ref,flight_count,airport_count,temp_airport_departure,
            temp_airport_arrival,current_date,temp_capacity)){
            
            /* Copies Temp Flight Data over to Flight Array */
            strcpy(FlightST[flight_count].flight_code,temp_flight_code);
            strcpy(FlightST[flight_count].airport_departure,temp_airport_departure);
            strcpy(FlightST[flight_count].airport_arrival,temp_airport_arrival);

            FlightST[flight_count].date = temp_date_ref;
            FlightST[flight_count].datetime = temp_datetime_ref;
            FlightST[flight_count].flight_duration = temp_duration_ref;
            FlightST[flight_count].flight_capacity = temp_capacity;

            FlightST[flight_count].reservation_count = 0;

            for (counter = 0; counter < airport_count; counter++){
                if (!strcmp(AirportST[counter].id,temp_airport_departure)){
                    AirportST[counter].num_flights_departing +=1;
                }
                if(!strcmp(AirportST[counter].id,temp_airport_arrival)){
                    AirportST[counter].num_flights_arriving +=1;
                } 
            }

            return 1;
    } else {
        return 0;
    }
}

/* ------------------------------ End of File ------------------------------- */
