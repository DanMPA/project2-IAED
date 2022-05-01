/*-*-coding:utf-8 -*- 
 *Auto updated?
 *   Yes
 *File :
 *   systemCore.c
 *Author :
 *   Daniel Martins Pão Alvo
 *
 *Created:
 *   April 19, 2022, 11:19:50 PM GMT+1
 *Last edited:
 *   April 24, 2022, 12:50:04 PM GMT+1
 *
 *Description:
 *   System Core related functions as decleared in "systemCore.h"
 *
 *Dependencies:
 *   ["systemCore.h","dateTime.h","airport.h","flight.h","flightManipulators.h",
 *    "reservationsManipulators.h","eliminator.h"]
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "systemCore.h"
#include "dateTime.h"
#include "airport.h"
#include "flight.h"
#include "flightManipulators.h"
#include "reservationsManipulators.h"
#include "eliminator.h"

/* ---------------------------- System Functions ---------------------------- */

int SystemStartAndInitializer(){
    int SystemDate = DateTimeToTimeStamp(2022,1,1,0,0,0);
    Airport SystemAirports[MAX_AIRPORTS];
    Flight SystemFlights[MAX_FLIGHTS];

    SystemLoop(SystemAirports,SystemFlights,SystemDate);

    return 0;
}

int SystemLoop(Airport SystemAirportsST[],Flight SystemFlightsST[],
    int SystemDate){
        
    unsigned char command;
    unsigned int airport_count = 0,flight_count = 0;

    while ((command = getchar()))
    {
        switch (command){
        case 'a':   /*  Adds New Airport  */
            airport_count += AirportAdder(SystemAirportsST,airport_count);
            break;
        case 'l':   /*  List Airports Recorded  */
            ListAirport(SystemAirportsST,airport_count);
            break;
        case 'v':   /*  Adds New Flight  */
            flight_count += FlightAdder(SystemAirportsST,SystemFlightsST,
                                SystemDate,airport_count,flight_count);
            break;
        case 'p':    /*  Lists Flights Departing from an Airport  */
            ListDepartingOrArrivingFlights(SystemAirportsST,SystemFlightsST,
                airport_count,flight_count,'d');
            break;
        case 'c':   /*  lists flights Arriving at an airport  */
            ListDepartingOrArrivingFlights(SystemAirportsST,SystemFlightsST,
                airport_count,flight_count,'a');
            break;
        case 't':   /*  Advance the System Date  */
            SystemDate = DateAdvancer(SystemDate);
            break;
        case 'r':   /*  Adds Reservation  */
            ReservationAdder(SystemFlightsST,flight_count,
                SystemDate);
            break;
        case 'e':   /*  Advance the System Date  */
            flight_count = (unsigned int)SystemEliminator(SystemFlightsST,
                                            flight_count);
            break;
        case 'q':   /*  Advance the System Date  */
            SystemTerminate(SystemFlightsST,flight_count);
            break;
        default:
            break;
        }
    }
  return 0;
}

void SystemCleanUp(Flight SystemFlightsST[],unsigned int flight_count){
    unsigned int counter;
    for (counter = 0; counter < flight_count; counter++){
        DeleteList(SystemFlightsST[counter].flight_reservations);
    }
}

void SystemTerminate(Flight SystemFlightsST[],unsigned int flight_count){
    SystemCleanUp(SystemFlightsST,flight_count);
    exit(0);
}

void *MemoryChecker(void *mallocVal){
    if (!mallocVal){
        printf("No memory.\n");
        exit(1);
    }
    return mallocVal;
}

/* ------------------------------ End of File ------------------------------- */
