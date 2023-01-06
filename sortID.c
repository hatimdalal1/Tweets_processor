#include "headerA3.h"
#include "myHeader.h"

void sortID (tweet ** head){

    int swapped = 1;
    tweet * ptr = malloc(sizeof(tweet));
    int tempID;
    char tempUser[51];
    char tempText[141];

    if ( *head == NULL) {       //if list is empty exit
        return;     //exit
    }

    do {        //while list is not sorted
        swapped = 0;
        ptr = *head;
            while(ptr->next != NULL) {
            if ((ptr->id) > (ptr->next->id)) {      //if next node id is smaller swap
                tempID = ptr->id;       //swap statements
                strcpy(tempUser, ptr->user);
                strcpy(tempText, ptr->text);

                ptr->id = ptr->next->id;
                strcpy(ptr->user, ptr->next->user);
                strcpy(ptr->text, ptr->next->text);

                ptr->next->id = tempID;
                strcpy(ptr->next->user, tempUser);
                strcpy(ptr->next->text, tempText);

                swapped = 1;
            }
            ptr = ptr->next;        //go to next node
        }

    } while(swapped==1);
}