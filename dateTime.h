/*-*-coding:utf-8 -*- 
 *Auto updated?
 *   Yes
 *File :
 *   dateTime.h
 *Author :
 *   Daniel Martins Pão Alvo
 * 
 *Created:
 *   April 19, 2022, 11:22:34 PM GMT+1
 *Last edited:
 *   April 19, 2022, 11:22:47 PM GMT+1
 *
 *Description:
 *   Definitions of DateTime and respective auxiliary functions.
 *
 *Dependencies:
 *   <None>
**/

#define SEC_IN_YEAR 31536000

#ifndef DateTime_H
#define DateTime_H

/* DateTimeToTimeStamp
 *  ~ Converts a date and time to seconds (unix time). 
 * Args:
 *       ~ year(unsigned int): A positive integer representing the year. 
 *       ~ month(unsigned int): A positive integer representing the month. 
 *       ~ day(unsigned int): A positive integer representing the day. 
 *       ~ hour(unsigned int): A positive integer representing the hour. 
 *       ~ minutes(unsigned int): A positive integer representing the minutes. 
 *       ~ seconds(unsigned int): A positive integer representing the seconds.
 * Returns:
 *       ~ timestamp(int):A integer value of date and time 
 *                        represented in seconds (unix time).
 *                         Positive after 01-01-1970 00:00:00.  
 *                         Negative before 01-01-1970 00:00:00.  
 */
int DateTimeToTimeStamp(unsigned int year, unsigned int month, unsigned int day, 
    unsigned int hour, unsigned int minutes, unsigned int seconds);

/* PrintTimeStamp
 *  ~ Prints date time representation according to flag. 
 * Args:
 *       ~ timestamp(int): Unix time value. 
 *       ~ flag(char): Flag {'m': Date and Time (Without seconds),
 *                           'd': Date, 't': Time}
 *                     If not one predefined returns Date and Time (Full).
 * Returns:
 *       ~ <None>
 */
void PrintTimeStamp(int timestamp, char flag);

/* TimeToTimeStamp
 *  ~ Converts a time to seconds (unix time). 
 * Args:
 *       ~ hour(unsigned int): A positive integer representing the hour. 
 *       ~ minutes(unsigned int): A positive integer representing the minutes. 
 *       ~ seconds(unsigned int): A positive integer representing the seconds.
 * Returns:
 *       ~ timestamp(int): A integer value time represented in seconds (unix time).
 */
int TimeToTimeStamp(unsigned int hour, unsigned int minutes, unsigned int seconds);

/* DateAdvancer
 *  ~ Advances system date time. 
 * Args:
 *       ~ curent_date(unsigned int): An integer representing the 
 *         current system date in seconds. 
 * User Input:
 *       ~ <day>(unsigned int): A positive integer representing the day. 
 *       ~ <month>(unsigned int): A positive integer representing the month. 
 *       ~ <year>(unsigned int): A positive integer representing the year. 
 * Raises:
 *       ~ "invalid date": If the date time is greater than a year.
 * Returns:
 *       ~ timestamp(int): Updated system date, else current date.
 */
int DateAdvancer(unsigned int curent_date);

#endif /* DateTime_H */
