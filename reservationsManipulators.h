/*-*-coding:utf-8 -*- 
 *Auto updated?
 *   Yes
 *File :
 *   reservationsManipulators.h
 *Author :
 *   Daniel Martins Pão Alvo
 *
 *Created:
 *   April 20, 2022, 11:11:26 PM GMT+1
 *Last edited:
 *   April 21, 2022, 5:40:45 PM GMT+1
 *
 *Description:
 *   Reservation auxiliary functions.
 *
 *Dependencies:
 *   ["flight.h","reservation.h"]
**/

#include "flight.h"
#include "reservation.h"

/* E_FlightExists_O1
 *  ~ Verifies if the flight exists. 
 * Args:
 *       ~ FlightsST(pointer struct flight): Array where flight are stored.
 *       ~ flight_code(pointer char): Flight code. 
 *       ~ date(unsigned int): Flight date. 
 *       ~ flight_count(unsigned int): Number of flights. 
 * Raises:
 *       ~ "[flight_code]: flight does not exist": If flight does not exist.
 * Returns:
 *       ~ (int): If valid returns 1, else 0.
 */
int E_FlightExists_O1(Flight FlightsST[],char flight_code[],unsigned int date,unsigned int flight_count);

/* E_ReservationExists
 *  ~ Verifies if the Reservation exists. 
 * Args:
 *       ~ FlightsST(pointer struct flight): Array where flight are stored.
 *       ~ flight_code(pointer char): Flight code. 
 *       ~ reservation_code(pointer char): Reservation code. 
 * Raises:
 *       ~ "[flight_code]: flight does not exist": If flight does not exist.
 * Returns:
 *       ~ (int): If valid returns 1, else 0.
 */
int E_ReservationExists(Flight FlightsST[],int flight_count,char reservation_code[]);

/* E_ReservationCapacityLimit
 *  ~ Verifies if the Reservation suffering capacity. 
 * Args:
 *       ~ FlightsST(pointer struct flight): Array where flight are stored.
 *       ~ flight_index(int): Flight index. 
 *       ~ reservation_capacity(int): Reservation capicity. 
 * Raises:
 *       ~ "too many reservations": If capacity is greater flight capacity.
 * Returns:
 *       ~ (int): If valid returns 1, else 0.
 */
int E_ReservationCapacityLimit(Flight FlightsST[],int flight_index,int reservation_capacity);

/* E_ValidReservationDate
 *  ~ Verifies if the Reservation date is in the past or greater than a year. 
 * Args:.
 *       ~ current_date(unsigned int): Current system date. 
 *       ~ reservation_date(unsigned int): Reservation capicity. 
 * Raises:
 *       ~ "too many reservations": If capacity is greater flight capacity.
 * Returns:
 *       ~ (int): If valid returns 1, else 0.
 */
int E_ValidReservationDate(unsigned int current_date,unsigned int reservation_date);

/* E_ValidReservationCapacity
 *  ~ Verifies if Capacity greater than 10. 
 * Args:.
 *       ~ reservation_capacity(int): Reservation Capacity. 
 * Raises:
 *       ~ "too many reservations": If capacity less 10.
 * Returns:
 *       ~ (int): If valid returns 1, else 0.
 */
int E_ValidReservationCapacity(int reservation_capacity);

/* GenericReservationErrorFunctions
 *  ~ Generic Error function that combines all errors functions for reserations.
 * Args:
 *       ~ FlightST(pointer struct Flight): Array where flights are stored.
 *       ~ flight_index(int): Flight index.
 *       ~ flight_code(pointer char): Flight Code.
 *       ~ flight_count(unsigned int): Number of flights.
 *       ~ flight_date(unsigned int): Reservation date.
 *       ~ reservation_code(pointer char): Reservation code.
 *       ~ reservation_capacity(int): Reservation capacity.
 *       ~ system_date(unsigned int): Current system date.
 * Returns:
 *       ~ (int): If no errors are raised returns 0, else 1.
 */
int GenericReservationErrorFunctions(Flight FlightsST[],
        int flight_index,char flight_code[],unsigned int flight_count,
        unsigned int flight_date,char reservation_code[],int reservation_capacity,
        unsigned int system_date);

/* AddReservation
 *  ~ Adds reservation to flight.
 * Args:
 *       ~ FlightST(pointer struct Flight): Array where flights are stored.
 *       ~ flight_index(int): Flight index.
 *       ~ temp_reservation(pointer(pointer Reservation)): Flight index.
 *       ~ temp_reservation_capacity(int): Reservation capacity.
 * Returns:
 *       ~ <None>
 */
void AddReservation(Flight FlightsST[],int flight_index,
        Reservation *temp_reservation,int temp_reservation_capacity);

/* ReservationAdder
 *  ~ Adds Reservation.
 * Args:
 *       ~ FlightST(pointer struct Flight): Array where flights are stored.
 *       ~ flight_count(unsigned int): Number of flights. 
 *       ~ current_date(unsigned int): Current system date.
 * Returns:
 *       ~ (int): New number of flights.
 */
int ReservationAdder(Flight FlightsST[],int flight_count,unsigned int current_date);

/* ------------------------------ End of File ------------------------------- */
