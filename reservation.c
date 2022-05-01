/*-*-coding:utf-8 -*- 
 *Auto updated?
 *   Yes
 *File :
 *   reservation.c
 *Author :
 *   Daniel Martins Pão Alvo
 *
 *Created:
 *   April 20, 2022, 11:38:13 PM GMT+1
 *Last edited:
 *   April 20, 2022, 11:47:34 PM GMT+1
 *
 *Description:
 *   Reservation and LinkList functions.
 *
 *Dependencies:
 *   ["systemCore.h","airport.h","bool.h","dateTime.h","flight.h",
 *    "reservation.h","eliminator.h"]
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "systemCore.h"
#include "airport.h"
#include "bool.h"
#include "dateTime.h"
#include "flight.h"
#include "reservation.h"
#include "eliminator.h"

/* ---------------------------- Reservation Core ---------------------------- */

Reservation *NewReservation(char code[],unsigned int numberOfPassangers){
    /* Allocating memory */
    Reservation *nReservation = MemoryChecker(malloc(sizeof(struct node)));
    nReservation->code = MemoryChecker(malloc(sizeof(char)*(strlen(code)+1)));

    /* Copping over information */
    strcpy(nReservation->code,code);
    nReservation->numPassangers = numberOfPassangers;

    return nReservation; 
}

LinkList NewLink(Reservation * reservation){
    /* Allocating memory */
    LinkList nReservation = MemoryChecker(malloc(sizeof(struct node)));
    nReservation->reservation.code = reservation->code;
    nReservation->reservation.numPassangers = reservation->numPassangers;

    nReservation->next = NULL;
    return nReservation; 
}

void FreeNode(LinkList head){
    free(head->reservation.code);
    free(head);
}

LinkList Lookup(LinkList *head, char code[]){
    LinkList temp;
    for (temp = *head; temp != NULL; temp=temp->next){
        if(!strcmp(temp->reservation.code,code)){
            return temp;
        }
    }
    return NULL;
}

void Delete(LinkList *head,Reservation reservation){
    LinkList temp, prev;
    for (temp = *head, prev = NULL; temp != NULL;prev = temp, temp=temp->next){
        if (!strcmp(temp->reservation.code,reservation.code)){
            if(temp == *head){
                *head = temp->next;
            } else{
                prev->next = temp->next;
            }
            FreeNode(temp);
        }
    }
}

void DeleteList(LinkList head){
    LinkList temp;
    while (head != NULL){
        temp = head;
        head = head->next;
        FreeNode(temp);
    }
    free(head);
} 

void SortedInsert(LinkList *sorted,Reservation *reservation){
    /* Sorts Reservations by Insertion Sort. */
    LinkList newnode,temp;
    newnode = NewLink(reservation);
    temp = *sorted;

    /* Special case for the head end */
    if (sorted == NULL || 
        strcmp(temp->reservation.code,newnode->reservation.code) >= 0) {
        newnode->next = temp;
        *sorted = newnode;
    }else {
        LinkList current = *sorted;
        /* Locate the node before the point of insertion*/
        while (current->next != NULL && 
            strcmp(current->next->reservation.code,newnode->reservation.code) < 0) {
            current = current->next;
        }
        newnode->next = current->next;
        current->next = newnode;
    }
}

void PrintReservation(LinkList *head){
    LinkList temp;
    for(temp = *head; temp != NULL; temp = temp->next){
        printf("%s %d\n",temp->reservation.code,temp->reservation.numPassangers);
    }
}

/* ------------------------------ End of File ------------------------------- */
