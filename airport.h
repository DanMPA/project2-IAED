/*-*-coding:utf-8 -*- 
 *Auto updated?
 *   Yes
 *File :
 *   airport.h
 *Author :
 *   Daniel Martins Pão Alvo
 *
 *Created:
 *   April 19, 2022, 11:21:17 PM GMT+1
 *Last edited:
 *   April 19, 2022, 11:21:36 PM GMT+1
 *
 *Description:
 *   Definations of an Airport and respective auxiliary functions.
 *
 *Dependencies:
 *   <None>
**/

#define MAX_AIRPORTS 40

#define AIRPORT_ID 4 
#define COUNTRY_NAME_SIZE 31
#define CITY_NAME_SIZE 51

#ifndef Airport_H
#define Airport_H

/* 96bytes */
typedef struct{
    char id[AIRPORT_ID];
    char country[COUNTRY_NAME_SIZE];
    char city[CITY_NAME_SIZE];
    int num_flights_departing;
    int num_flights_arriving;
} Airport;

/* E_ValidAirportID
 *  ~ Verifies if the Airport ID is Valid. 
 * Args:
 *       ~ id(pointer char): Airport ID. 
 * Raises:
 *       ~ "invalid airport ID" If not 3 uppercase letters.
 * Returns:
 *       ~ (int): If valid returns 1, else 0.
 */
int E_ValidAirportID(char *id);

/* E_MAXAirports
 *  ~ Verifies if there is space for more airports.
 * Args:
 *       ~ airport_count(int): Number of airports in system.
 * Raises:
 *       ~ "too many airports" If number of airports excedes max declared.
 * Returns:
 *       ~ (int): If valid returns 0, else 1.
 */
int E_MAXAirports(int airport_count);

/* E_DuplicateAirport
 *  ~ Verifies if there is no duplicate airports in system.
 * Args:
 *       ~ AirportST(pointer struct Airport): Array where airports are stored.
 *       ~ id(pointer char): Airport ID.
 *       ~ airport_count(int): Number of airports in system.
 * Raises:
 *       ~ "duplicate airport" If duplicate airports is found.
 * Returns:
 *       ~ (int): If valid returns 1, else 0.
 */
int E_DuplicateAirport(Airport *AirportST, char *id, int airport_count);

/* GenericAirportErrorHandler
 *  ~ Generic Error function that combines all errors functions for airports.
 * Args:
 *       ~ AirportST(pointer struct Airport): Array where airports are stored.
 *       ~ temp_id(pointer char): Airport ID.
 *       ~ airport_count(int): Number of airports in system.
 * Returns:
 *       ~ (int): If no errors are raised returns 0, else 1.
 */
int GenericAirportErrorHandler(Airport *AirportST, char *temp_id, int airport_count);

/* SortsAirports
 *  ~ Sorts airports by id alphabetically.
 * Args:
 *       ~ AirportST(pointer struct Airport): Array where airports are stored.
 *       ~ airport_count(int): Number of airports in system.
 * Returns:
 *       ~ <None>
 */
void SortsAirports(Airport AirportST[], int airport_count);

/* AirportAdder
 *  ~ Adds new valid airport.
 * Args:
 *       ~ AirportST(pointer struct Airport): Array where airports are stored.
 *       ~ airport_count(int): Number of airports in system.
 * User Input:
 *       ~ <Airport ID>(char)
 *       ~ <City>(char)
 *       ~ <Country>.(char)
 * Returns:
 *       ~ (int): Retruns 1 if airport was added successfully, else 0.  
 */
int AirportAdder(Airport AirportST[],int airport_count);

/* AirportPrinter
 *  ~ Prints airport in foramt <Airport ID> <City> <Country>.
 * Args:
 *       ~ AirportST(pointer struct Airport): Array where airports are stored.
 * Returns:
 *       ~ <None>  
 */
void AirportPrinter(Airport AirportST);

/* ListAirport
 *  ~ Prints Airports according to user input. If nothing is passed through, all
      airports will be printed in alphabetic order, else prints airports according
      to space separeded list of airports ID. 
 * Args:
 *       ~ AirportST(pointer struct Airport): Array where airports are stored.
 *       ~ airport_count(int): Number of airports in system.
* User Input:
 *       ~ <None>: <\n> 
 *       ~ <Airport ID>(char) <...> : Space separated list of airport ID.
 * Raises:
 *       ~ "no such airport ID" If airport ID does not exist in system.
 * Returns:
 *       ~ <None>
 */
void ListAirport(Airport AirportST[],int airport_count);

#endif /* Airport_H */
