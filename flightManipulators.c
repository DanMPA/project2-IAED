/*-*-coding:utf-8 -*- 
 *Auto updated?
 *   Yes
 *File :
 *   flightManipulators.c
 *Author :
 *   Daniel Martins Pão Alvo
 *
 *Created:
 *   April 19, 2022, 11:16:03 PM GMT+1
 *Last edited:
 *   April 24, 2022, 12:41:39 PM GMT+1
 *
 *Description:
 *   Flight manipulators related functions as decleared in "flightManipulators.h".
 *
 *Dependencies:
 *   ["dateTime.h","flightManipulators.h"]
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "dateTime.h"
#include "flightManipulators.h"

typedef unsigned int uint;

/* ---------------------- Flight Manipulator Functions ---------------------- */

int AirportIDFinder(Airport AirportST[],char airport_id[],
        uint airport_count){
    uint index;
    for (index = 0; index < airport_count; index++){
        if(!strcmp(AirportST[index].id,airport_id)){
            return index;
        }
    }
    printf("%s: no such airport ID\n",airport_id);
    return -1;
}

void SwapFlights(Flight *FlightST1, Flight *FlightST2){
    Flight temp = *FlightST1;
    *FlightST1 = *FlightST2;
    *FlightST2 = temp;
}

void DepartingFlightsSorter(Flight FlightST[], int num_flights){
    int i, j;
     for (i = 0; i < num_flights-1; i++){     
        for (j = 0; j < num_flights-i-1; j++){
            if ((FlightST[j].datetime) > 
                (FlightST[j+1].datetime)){
                SwapFlights(&FlightST[j], &FlightST[j+1]);
            }
        }
    }
}

void ArrivingFlightsSorter(Flight FlightST[], int num_flights){
   int i, j;
   for (i = 0; i < num_flights-1; i++)     
       for (j = 0; j < num_flights-i-1; j++)
           if ((FlightST[j].datetime + FlightST[j].flight_duration) > 
           (FlightST[j+1].datetime + FlightST[j+1].flight_duration))
              SwapFlights(&FlightST[j], &FlightST[j+1]);
}

/* -------------- Functions For Departing and Arriving Flight --------------- */

void FlightListSelector(Flight FlightST[],Flight TempFlightST[],
        uint flight_count,char airport_id[], char flag){

    uint counter,counter1;
    char * temp_airport_id;
    temp_airport_id = NULL;

    for (counter = 0,counter1 = 0; counter < flight_count; counter++){
        if(flag == 'd'){
            temp_airport_id = FlightST[counter].airport_departure;
        }else if(flag == 'a'){
            temp_airport_id = FlightST[counter].airport_arrival;
        }
        if(!strcmp(temp_airport_id,airport_id)){
                TempFlightST[counter1] = FlightST[counter];
                counter1 ++;
        }
}
}

void ListDepartingOrArrivingFlights(Airport AirportST[],Flight FlightST[],
        uint airport_count, int flight_count,char flag){
    uint counter,num_flights;

    Flight TempFlightST[MAX_FLIGHTS];
    int airport_id_position;
    char temp_airport_id[AIRPORT_ID];
    
    scanf("%s",temp_airport_id);
    airport_id_position = AirportIDFinder(AirportST,temp_airport_id,airport_count);
    if(airport_id_position == -1){
        return;
    }

    if(flag == 'd'){
        num_flights = AirportST[airport_id_position].num_flights_departing;

        FlightListSelector(FlightST,TempFlightST,flight_count,temp_airport_id,flag);

        DepartingFlightsSorter(TempFlightST,num_flights);

        for (counter = 0; counter < num_flights; counter++){
            printf("%s %s ",TempFlightST[counter].flight_code,TempFlightST[counter].airport_arrival);
            PrintTimeStamp(TempFlightST[counter].datetime,'m');
        }
    } else if(flag == 'a'){
        num_flights = AirportST[airport_id_position].num_flights_arriving;

        FlightListSelector(FlightST,TempFlightST,flight_count,temp_airport_id,flag);

        ArrivingFlightsSorter(TempFlightST,num_flights);
        
        for (counter = 0; counter < num_flights; counter++){
        printf("%s %s ",TempFlightST[counter].flight_code,TempFlightST[counter].airport_departure);
        PrintTimeStamp(TempFlightST[counter].datetime+TempFlightST[counter].flight_duration,'m');
        }
    }
}

/* ------------------------------ End of File ------------------------------- */
