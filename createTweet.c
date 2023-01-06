#include "headerA3.h"
#include "myHeader.h"

tweet * createTweet( tweet * tweetList) {

    tweet *new = malloc(sizeof(tweet));
    tweet * ptr = malloc(sizeof(tweet));
    int userid = 0;
    int unique = 0;
    char username[51];
    char tweet[141];
    
    printf("Enter a username: ");           //getting user input
    scanf("%s", username);
    while (strlen(username) == 0) {
        printf("Enter a user name: ");
        scanf("%s", username);
    }

    printf("Enter the user's tweet: ");
    getchar();
    fgets(tweet, 141, stdin);
    while (strlen(tweet) == 0) {
        printf("Enter a user name: ");
        fgets(tweet, 141, stdin);
    }
    tweet[strlen(tweet)-1] = '\0';      //remove new line

    userid = strlen(tweet);       //calculate user id
    
    for (int i=0; i < strlen(username); i++) {
        userid += username[i];      //further calculation for user id
    }
    
    srand(time(0));
   
    do {        //loop to check if same user id already exists is the linked list 
        ptr = tweetList;
        unique = 1;
        while (ptr != NULL) {
            if (userid == ptr->id) {        //if user id exits
                userid += (rand() % 1000);      //calculate new user id
                unique = 0;
            }
            ptr = ptr->next;
        }
    } while(unique != 1);
    
    printf("Your computer-generated userid is %d.\n", userid);

    /*ptr = tweetList;
    if (ptr == NULL) {
        ptr = head;
        head->id = userid;
        strcpy(head->text, tweet);
        strcpy(head->user, username);
        head->next = NULL;
    } else {
        ptr = tweetList->next;
    }
    */

    ptr = tweetList;
    if (ptr == NULL) {      //if this is the first tweet in the linked list
        new->id = userid;       //assign values to nodes
        strcpy(new->text, tweet);
        strcpy(new->user, username);
        new->next = malloc(sizeof(tweet));
        new->next = NULL;       //allocate memory for next pointer and make it null
        ptr = new;
        tweetList = ptr;  
        return tweetList;
    } else {
        while(ptr->next != NULL) {      //find the last node
            ptr = ptr->next;
        }
        ptr->next = malloc(sizeof(tweet));      //allocate memory for new node
        ptr->next->id = userid;
        strcpy(ptr->next->text, tweet);
        strcpy(ptr->next->user, username);
        ptr->next->next = NULL;
    }




    return tweetList;
}