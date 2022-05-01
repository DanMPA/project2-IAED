/*-*-coding:utf-8 -*- 
 *Auto updated?
 *   Yes
 *File :
 *   eliminator.h
 *Author :
 *   Daniel Martins Pão Alvo
 *
 *Created:
 *   April 19, 2022, 11:23:10 PM GMT+1
 *Last edited:
 *   April 20, 2022, 4:18:51 PM GMT+1
 *
 *Description:
 *   Functions that eliminate flight and reservations.
 *
 *Dependencies:
 *   ["flight.h"]
**/

#include "flight.h"

/* FlightRemover
 *  ~ Removes all flights with the same flight code from the system.
 * Args:
 *       ~ FlightST(pointer struct Flight): Array where flights are stored.
 *       ~ code(pointer char): Flight code.
 *       ~ flight_count(int): Number of flights in system.
 * Raises:
 *       ~ "not found" If flights is not found.
 * Returns:
 *       ~ (int): New flight code.
 */
int FlightRemover(Flight FlightST[],char code[],int flight_count);

/* ReservationRemover
 *  ~ Removes all reservations from a flight.
 * Args:
 *       ~ FlightST(pointer struct Flight): Array where flights are stored.
 *       ~ code(pointer char): Flight code.
 *       ~ flight_count(int): Number of flights in system.
 * Raises:
 *       ~ "not found" If Reservation is not found.
 * Returns:
 *       ~ <None>
 */
void ReservationRemover(Flight FlightST[],char code[],int flight_count);

/* SystemEliminator
 *  ~ Removes flights or reservations the system.
 * Args:
 *       ~ FlightST(pointer struct Flight): Array where flights are stored.
 *       ~ flight_count(int): Number of flights in system.
 * User Input:
 *       ~ [<Flight Code>(char)]
 *       ~ [<Reservation Code>(char)]
 * Returns:
 *       ~ (int): New flight code.
 */
int SystemEliminator(Flight FlightST[],unsigned int flight_count);

/* ------------------------------ End of File ------------------------------- */
