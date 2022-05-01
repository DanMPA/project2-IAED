/*-*-coding:utf-8 -*- 
 *Auto updated?
 *   Yes
 *File :
 *   systemCore.h
 *Author :
 *   Daniel Martins Pão Alvo
 *
 *Created:
 *   April 19, 2022, 11:28:01 PM GMT+1
 *Last edited:
 *   April 20, 2022, 7:28:17 PM GMT+1
 *
 *Description:
 *   Definitions of functions for system initialise and continuation work.
 *
 *Dependencies:
 *   ["airport.h","flight.h"]
**/

#include "airport.h"
#include "flight.h"
 
/* SystemLoop
 *  ~ Main function reponsible for protestant system loop, 
 *    calling action functions and terminating procces. 
 * Args:
 *       ~ AirportsST(struct Airports): A pointer to a Structor of Airports 
 *       ~ FlightsST(struct Flights): A pointer to a Structor of Flights
 *       ~ SystemDate(int SystemDate): A integer representing the date time. 
 * Returns:
 *       ~ (int): Returns 0 to indicate loop termination.
 */
int SystemLoop(Airport AirportsST[],Flight FlightsST[],int SystemDate);

/* SystemLoop
 *  ~ Initializes system critical variables and calls main loop.
 * Args:
 *       ~ <None>
 * Returns:
 *       ~ (int): Returns 0 to indicate termination of proccess.
 */
int SystemStartAndInitializer();

/* MemoryChecker
 *  ~ Cheaks if there is memory available.
 * Args:
 *       ~ mallocVal(void pointer) 
 * Raises:
 *       ~ "No memory.": If mallocVal is 0.
 * Returns:
 *       ~ (void pointer)
 */
void *MemoryChecker(void *mallocVal);

/* SystemCleanUp
 *  ~ Frees all allocated memory.
 * Args:
 *       ~ SystemFlightsST(pointer struct flight): Array where flight are stored 
 *       ~ flight_count(int): Number of flights in system. 
 * Returns:
 *       ~ <None>
 */
void SystemCleanUp(Flight SystemFlightsST[],unsigned int flight_count);

/* SystemTerminate
 *  ~ Terminates Programe.
 * Args:
 *       ~ <None>
 * Returns:
 *       ~ <None>
 */
void SystemTerminate();

/* ------------------------------ End of File ------------------------------- */

