/*-*-coding:utf-8 -*- 
 *Auto updated?
 *   Yes
 *File :
 *   flightManipulators.h
 *Author :
 *   Daniel Martins Pão Alvo
 *
 *Created:
 *   April 19, 2022, 11:26:13 PM GMT+1
 *Last edited:
 *   April 20, 2022, 5:00:34 PM GMT+1
 *
 *Description:
 *   Definitions of functions for manipulating flights.
 *
 *Dependencies:
 *   ["airport.h","flight.h"]
**/

#include "airport.h"
#include "flight.h"

/* AirportIDFinder
 *  ~ Finds index of airport from id.
 * Args:
 *       ~ AirportST(pointer struct airport): Array where airports are stored.
 *       ~ airport_id(pointer char): Flight code. 
 * Raises:
 *       ~ "no such airport ID": If airport is not found.
 * Returns:
 *       ~ (int): If valid returns index, else -1.
 */
int AirportIDFinder(Airport AirportST[],char airport_id[],
        unsigned int airport_count);

/* SwapFlights
 *  ~ Swaps two flights.
 * Args:
 *       ~ FlightST1(pointer struct flight): Array where flight are stored.
 *       ~ FlightST2(pointer struct flight): Array where flight are stored.
 * Raises:
 *       ~ "no such airport ID": If airport is not found.
 * Returns:
 *       ~ <None>
 */
void SwapFlights(Flight *FlightST1, Flight *FlightST2);

/* DepartingFlightsSorter
 *  ~ Sorts Flights by departure date and time.
 * Args:
 *       ~ FlightST(pointer struct flight): Array where flight are stored.
 *       ~ num_flights(int): Number of flights.
 * Returns:
 *       ~ <None>
 */
void DepartingFlightsSorter(Flight FlightST[], int num_flights);

/* DepartingFlightsSorter
 *  ~ Sorts Flights by arriving date and time.
 * Args:
 *       ~ FlightST(pointer struct flight): Array where flight are stored.
 *       ~ num_flights(int): Number of flights.
 * Returns:
 *       ~ <None>
 */
void ArrivingFlightsSorter(Flight arr[], int num_flights);

/* FlightListSelector
 *  ~ Selects flights for sorting with a flag.
 * Args:
 *       ~ FlightST(pointer struct flight): Array where flight are stored.
 *       ~ TempFlightST(pointer struct flight): Temp array where flight are stored.
 *       ~ flight_count(int): Number of flights.
 *       ~ airport_id(pointer char): Number of flights.
 *       ~ flag(pointer char): Flag {"d": departure, "a":arival}.
 * Returns:
 *       ~ <None>
 */
void FlightListSelector(Flight FlightST[],Flight TempFlightST[],
        unsigned int flight_count,char airport_id[], char flag);

/* ListDepartingOrArrivingFlights
 *  ~ Takes care of listing departure and arrival flights.
 * Args:
 *       ~ AirportST(pointer struct airport): Array where airport are stored.
 *       ~ FlightST(pointer struct flight): Array where flight are stored.
 *       ~ airport_count(int): Number of flights.
 *       ~ flight_count(int): Number of flights.
 *       ~ airport_id(pointer char): Number of airports.
 *       ~ flag(pointer char): Flag {"d": departure, "a":arival}.
 * Returns:
 *       ~ <None>
 */    
void ListDepartingOrArrivingFlights(Airport AirportST[],Flight FlightST[],
        unsigned int airport_count, int flight_count,char flag);

/* ------------------------------ End of File ------------------------------- */
