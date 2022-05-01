/*-*-coding:utf-8 -*- 
 *Auto updated?
 *   Yes
 *File :
 *   reservation.h
 *Author :
 *   Daniel Martins Pão Alvo
 *
 *Created:
 *   April 19, 2022, 11:27:09 PM GMT+1
 *Last edited:
 *   April 20, 2022, 11:45:09 PM GMT+1
 *
 *Description:
 *   Definitions of Reservations and Link List functions.
 *
 *Dependencies:
 *   <None>
**/

#define RESERVATION_CODE_LEN 10
#define MAX_INPUT 65536

#ifndef Reservations_H
#define Reservations_H

/* 16 bytes */
typedef struct reservation{
    char *code;
    unsigned int numPassangers;
} Reservation;

/* 8 bytes */
typedef struct node{
    Reservation reservation;
    struct node *next;  
} *LinkList;

/* NewReservation
 *  ~ Creates new reservation.
 * Args:
 *       ~ code(pointer char): Reservation code.
 *       ~ numberOfPassangers(unsigned int): Number of people passengers.
 * Memory Allocate:
 *       ~ reservation[pointer struct node]
 *       ~ code[pointer char] <- No Fixed length!
 * Returns:
 *       ~ (pointer struct Reservation): Pointer to new Reservation.
 */  
Reservation *NewReservation(char code[],unsigned int numberOfPassangers);

/* NewLink
 *  ~ Creates new node for the link list.
 * Args:
 *       ~ reservation(pointer struct Reservation): New Reservation.
 * Memory Allocate:
 *       ~ reservation[pointer struct node]
 * Returns:
 *       ~ (pointer struct LinkList): Pointer to new Linklist node.
 */ 
LinkList NewLink(Reservation * reservation);

/* FreeNode
 *  ~ Frees allocated memory of a node.
 * Args:
 *       ~ head(pointer struct LinkList): A Link list Node.
 * Memory Deallocate:
 *       ~ code[pointer char]
 *       ~ reservation[pointer struct LinkList]
 * Returns:
 *       ~ <None>
 */ 
void FreeNode(LinkList head);

/* Lookup
 *  ~ Findes the node with that reservation.
 * Args:
 *       ~ head(pointer (pointer struct LinkList)): Flight Reservation Linklist.
 *       ~ head(pointer struct LinkList): A Node.
 * Returns:
 *       ~ (pointer struct LinkList): Pointer to node with that reservation.
 */
LinkList Lookup(LinkList *head, char code[]);

/* Delete
 *  ~ Delets a node from a link list.
 * Args:
 *       ~ head(pointer (pointer struct LinkList)): Flight Reservation Linklist.
 *       ~ reservation(struct Reservation): A Reservation.
 * Returns:
 *       ~ <None>
 */
void Delete(LinkList *head,Reservation reservation);

/* DeleteList
 *  ~ Delets the hole link list.
 * Args:
 *       ~ head(pointer struct LinkList): Flight Reservation Linklist.
 * Returns:
 *       ~ <None>
 */
void DeleteList(LinkList head);

/* SortedInsert
 *  ~ Inserts new Nodes sorted by lexicographic order.
 * Args:
 *       ~ sorted(pointer(pointer struct LinkList)): Flight Reservation Linklist.
 *       ~ reservation(pointer struct Reservation): Reservation.
 * Returns:
 *       ~ <None>
 */
void SortedInsert(LinkList *sorted,Reservation *reservation);

/* PrintReservation
 *  ~ Prints out reservations.
 * Args:
 *       ~ head(pointer(pointer struct LinkList)): Flight Reservation Linklist.
 * Returns:
 *       ~ <None>
 */
void PrintReservation(LinkList *head);

#endif /* Reservations_H */

/* ------------------------------ End of File ------------------------------- */
