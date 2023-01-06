#include "headerA3.h"
#include "myHeader.h"

void displayTweets(tweet * tweetList) {
    tweet *ptr = tweetList;
    if (ptr == NULL) {
        printf("List is empty\n");
    }
    while (ptr != NULL) {       // go through all the nodes in the linked list
        printf("%d: Created by %s: %s\n", ptr->id, ptr->user, ptr->text);       //print each node
        ptr = ptr->next;        //go to next node
    }
}