/*-*-coding:utf-8 -*- 
 *Auto updated?
 *   Yes
 *File :
 *   flight.h
 *Author :
 *   Daniel Martins Pão Alvo
 *
 *Created:
 *   April 19, 2022, 11:24:46 PM GMT+1
 *Last edited:
 *   April 20, 2022, 11:58:50 PM GMT+1
 *
 *Description:
 *   Definations of a Flight and respective auxiliary functions.
 *
 *Dependencies:
 *   ["airport.h","reservation.h"]
**/

#include "airport.h"
#include "reservation.h"

#define FLIGHT_CODE 7

#define VALID_FLIGHT_DURATION 12
#define FLIGHT_CAPACITY_MIN 10
#define FLIGHT_CAPACITY_MAX 100

#define MAX_FLIGHTS 30000

#ifndef Flight_H
#define Flight_H

/* 48 bytes */
typedef struct Flight {
    char flight_code[FLIGHT_CODE];
    char airport_departure[AIRPORT_ID];
    char airport_arrival[AIRPORT_ID];
    
    unsigned int date;
    unsigned int datetime;
    unsigned int flight_duration;
    unsigned int flight_capacity;

    unsigned int reservation_capacity;
    unsigned int reservation_count;
    LinkList flight_reservations;
}Flight;

/* ------------------------- Flight Error Functions ------------------------- */

/* E_FlightCodeVerifier
 *  ~ Verifies if valid flight code. 
 * Args:
 *       ~ flight_code(pointer char): Flight code. 
 * Raises:
 *       ~ "invalid flight code": If Flight code not composed of three uppercase
 *          letter and any trailing number between and including 1-9999.
 * Returns:
 *       ~ (int): If valid returns 1, else 0.
 */
int E_FlightCodeVerifier(char flight_code[]);

/* E_FlightExists_O0
 *  ~ Verifies if valid flight code. 
 * Args:
 *       ~ FlightST(pointer struct flight): Array where flight are stored.
 *       ~ flight_code(pointer char): Flight code. 
 *       ~ date_ref(unsigned int): Flight date. 
 *       ~ flight_count(int): Number of flights in system. 
 * Raises:
 *       ~ "flight already exists": If flight has the same day as an 
 *                                  existing flight.
 *         in the system.
 * Returns:
 *       ~ (int): If valid returns 1, else 0.
 */
int E_FlightExists_O0(Flight FlightST[],char flight_code[],unsigned int date_ref,
    int flight_count);

/* E_ValidAirport
 *  ~ Verifies if Airport exist in system. 
 * Args:
 *       ~ AirportST(pointer struct Airport): Array where airports are stored.
 *       ~ id(pointer char): Airport ID.
 *       ~ airport_count(int): Number of airports in system.
 * Raises:
 *       ~ "no such airport ID": If airport does not exit in system.
 * Returns:
 *       ~ (int): If valid returns 1, else 0.
 */
int E_ValidAirport(Airport AirportST[],char airport_ID[],int airport_count);

/* E_MAXFlights
 *  ~ Verifies if valid flight code. 
 * Args:
 *       ~ flight_count(int): Number of flights in system. 
 * Raises:
 *       ~ "too many flights": If number of flights excedes max declared. 
 * Returns:
 *       ~ (int): If valid returns 1, else 0.
 */
int E_MAXFlights(int flight_count);

/* E_ValidFlightDate
 *  ~ Verifies if date is valid. 
 * Args:
 *       ~ current_date(unsigned int): Current system date. 
 *       ~ date_ref(unsigned int): Date. 
 * Raises:
 *       ~ "invalid date": If date is in the past or a year in advance. 
 * Returns:
 *       ~ (int): If valid returns 1, else 0.
 */
int E_ValidFlightDate(unsigned int current_date,unsigned int date_ref);

/* E_ValidDuration
 *  ~ Verifies if duration is not greater than 12 hours. 
 * Args:
 *       ~ duration(unsigned int): The duration of the flight. 
 * Raises:
 *       ~ "invalid duration": If duration greater than 12 hours. 
 * Returns:
 *       ~ (int): If valid returns 1, else 0.
 */
int E_ValidDuration(unsigned int duration);

/* E_ValidCapacity
 *  ~ Verifies if capacity is greater than 10. 
 * Args:
 *       ~ capacity(unsigned int): The capacity of the flight. 
 * Raises:
 *       ~ "invalid capacity": If capacity smaller than 10. 
 * Returns:
 *       ~ (int): If valid returns 1, else 0.
 */
int E_ValidCapacity(unsigned int capacity);

/* GenericFlightErrorHandler
 *  ~ Generic Error function that combines all errors functions for flights.
 * Args:
 *       ~ AirportST(pointer struct Airport): Array where airports are stored.
 *       ~ FlightST(pointer struct Flight): Array where flights are stored.
 *       ~ temp_flight_code(pointer char): Flight Code.
 *       ~ temp_datetime_ref(unsigned int): Flight Date and time.
 *       ~ temp_duration_ref(unsigned int): Flight duration.
 *       ~ flight_count(unsigned int): Number of flights.
 *       ~ airport_count(unsigned int): Number of airports.
 *       ~ temp_airport_departure(pointer char): Airport Departure ID.
 *       ~ temp_airport_arrival(pointer char): Airport Arrival ID.
 *       ~ current_date(unsigned int): Current system date.
 *       ~ temp_capacity(unsigned int): Flight capacity.
 * Returns:
 *       ~ (int): If no errors are raised returns 0, else 1.
 */
int GenericFlightErrorHandler(Airport AirportST[], Flight FlightST[],
    char temp_flight_code[],unsigned int temp_datetime_ref,
    unsigned int temp_duration_ref,unsigned int flight_count,
    unsigned int airport_count,char temp_airport_departure[],
    char temp_airport_arrival[],unsigned int current_date, 
    unsigned int temp_capacity);

/* ---------------------------- Flight Functions ---------------------------- */

/* FlightPrinter
 *  ~ Prints Flights. 
 * Args:
 *       ~ FlightST(pointer struct Flight): Array where flights are stored.
 * Returns:
 *       ~ <None>
 */
void FlightPrinter(Flight FlightST);

/* FlightPrinter
 *  ~ Prints Flights. 
 * Args:
 *       ~ FlightST(pointer struct Flight): Array where flights are stored.
 *       ~ flight_code(pointer char): Flight Code.
 *       ~ date(unsigned int): Flight Date and time.
 *       ~ flight_count(unsigned int): Number of flights.
 * Returns:
 *       ~ (int): The index of the flight or -1 if not found.
 */
int FlightFinderDate(Flight SystemFlightsST[],char flight_code[],
        unsigned int date,unsigned int flight_count);

/* ListFlights
 *  ~ Lists Flights. 
 * Args:
 *       ~ FlightST(pointer struct Flight): Array where flights are stored.
 *       ~ flight_count(unsigned int): Number of flights.
 * Returns:
 *       ~ <None>
 */
void ListFlights(Flight FlightST[],unsigned int flight_count);

/* FlightAdder
 *  ~ Adds Flights to system. 
 * Args:
 *       ~ AirportST(pointer struct Airport): Array where airports are stored.
 *       ~ FlightST(pointer struct Flight): Array where flights are stored.
 *       ~ current_date(unsigned int): Current system date. 
 *       ~ airport_count(unsigned int): Number of Airport.
 *       ~ flight_count(unsigned int): Number of flights.
 * Returns:
 *       ~ (int): The index of the flight or -1 if not found.
 */
int FlightAdder(Airport AirportST[], Flight FlightST[],
    unsigned int current_date,unsigned int airport_count,
    unsigned int flight_count);

#endif /* Flight_H */

/* ------------------------------ End of File ------------------------------- */
