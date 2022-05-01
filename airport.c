/*-*-coding:utf-8 -*- 
 *Auto updated?
 *   Yes
 *File :
 *   airport.c
 *Author :
 *   Daniel Martins Pão Alvo
 * 
 *Created:
 *   April 19, 2022, 11:05:58 PM GMT+1
 *Last edited:
 *   April 28, 2022, 11:30:46 PM GMT+1
 *
 *Description:
 *   Airport related functions as decleared in "airports.h"
 *
 *Dependencies:
 *   ["bool.h","airports.h"]
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "airport.h"
#include "bool.h"

/* ------------------------ Airport Error Functions ------------------------- */

int E_ValidAirportID(char id[]){
    int counter;
    for (counter = 0; counter < AIRPORT_ID-1; counter++){
        if(!isupper(id[counter])){
            printf("invalid airport ID\n");
            return FALSE;
        }
    }
    return TRUE;
}

int E_MAXAirports(int airport_count){
    if (airport_count == MAX_AIRPORTS){
        printf("too many airports\n");
        return TRUE;
    }
    return FALSE;
}

int E_DuplicateAirport(Airport AirportST[],char id[],int airport_count){
    int counter;
    for (counter = 0; counter < airport_count; counter++){
        if(!strcmp(AirportST[counter].id,id)){
            printf("duplicate airport\n");
            return TRUE;
        }
    }
    return FALSE;
}

int GenericAirportErrorHandler(Airport AirportST[],char temp_id[],int airport_count){
    return E_ValidAirportID(temp_id) && !E_MAXAirports(airport_count) 
        && !E_DuplicateAirport(AirportST,temp_id,airport_count);
}

/* --------------------------- Airport Functions ---------------------------- */

void SortsAirports(Airport AirportST[], int airport_count){
    /* Sorts Airports by Insertion Sort. */
	int i,j;
    Airport key;

    for (i = 0; i < airport_count; i++) {
        key = AirportST[i];
        j = i - 1;
			while (j >= 0 && strcmp(AirportST[j].id,key.id) > 0){
				AirportST[j + 1] = AirportST[j];
				j = j - 1;
			}
			AirportST[j + 1] = key;
    }
}

int AirportAdder(Airport AirportST[],int airport_count){
    char temp_id[AIRPORT_ID], temp_country[COUNTRY_NAME_SIZE],
         temp_city[CITY_NAME_SIZE];

    scanf("%s %s %[^\n]s",temp_id,temp_country,temp_city);

    if(GenericAirportErrorHandler(AirportST,temp_id,airport_count)){
        strcpy(AirportST[airport_count].id,temp_id);
        strcpy(AirportST[airport_count].country,temp_country);
        strcpy(AirportST[airport_count].city,temp_city);
        AirportST[airport_count].num_flights_departing = 0;
        AirportST[airport_count].num_flights_arriving = 0;
        
        SortsAirports(AirportST,airport_count);
        
        printf("airport %s\n",AirportST[airport_count].id); 
        return 1;
    } 
    return 0;
}

void AirportPrinter(Airport AirportST){
    printf("%s %s %s %d\n",AirportST.id,AirportST.city,
        AirportST.country,AirportST.num_flights_departing);
}

void ListAirport(Airport AirportST[],int airport_count){
    char temp_airportID[AIRPORT_ID];
    unsigned char temp_val;
    int counter;

    SortsAirports(AirportST,airport_count);

    temp_val = getchar();
    if(temp_val == '\n'){
        for (counter = 0; counter < airport_count; counter++){
        AirportPrinter(AirportST[counter]);
        } 
    } else {
        while (temp_val != '\n'){
            scanf("%s",temp_airportID);
            for (counter = 0; counter < airport_count; counter++){
                if(!strcmp(temp_airportID,AirportST[counter].id)){
                    AirportPrinter(AirportST[counter]);
                    break;
                }
                if(counter == airport_count - 1){
                    printf("%s: no such airport ID\n",temp_airportID);
                    break;
                }
            }
            temp_val = getchar();
        }
    }
}

/* ------------------------------ End of File ------------------------------- */
