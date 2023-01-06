#include "headerA3.h"
#include "myHeader.h"

void deleteTweet(tweet ** tweetList) {
    tweet * ptr = malloc(sizeof(tweet));
    ptr = *tweetList;
    int numTweets=0;
    int choice = 0;

    while(ptr != NULL) {        //loop to calculate number of tweets
        numTweets++;
        ptr = ptr->next;
    }

    printf("Currently there are %d tweets\n\n", numTweets);

    if (numTweets != 0) {
        printf("Which tweet do you wish to delete – enter a value between 1 and %d: ", numTweets);
        scanf("%d", &choice);
        while ((choice < 1) || (choice > numTweets)) {      //validation check
            printf("Error, Enter a valid choice\n");
            printf("Which tweet do you wish to delete – enter a value between 1 and %d: ", numTweets);
            scanf("%d", &choice);
        }
    }

    ptr = *tweetList;
    if (choice == 1) {      //deleting the first tweet in the list
        *tweetList = ptr->next;
        printf("Tweet %d deleted. There are now %d tweets left", ptr->id, numTweets-1);
        ptr = NULL;
    } else {
        for (int i=0; i<choice-2; i++) {
            ptr = ptr->next;
        }
        printf("Tweet %d deleted. There are now %d tweets left", ptr->next->id, numTweets-1);
        if (choice == numTweets) {      //deleting the last tweet from the list
            ptr->next = NULL;
        } else {        //deleting any other tweets
            ptr->next = ptr->next->next;
            ptr->next->next = NULL;
        }
    }
}