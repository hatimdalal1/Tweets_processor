#include "headerA3.h"
#include "myHeader.h"

void loadTweetsFromFile(tweet ** tweetList) {

    FILE * fptr;
    tweet * ptr = malloc(sizeof(tweet));
    tweet * new = malloc(sizeof(tweet));
    char filename[50];
    int id;
    char username[51];
    char text[141];
    char line[200];
    char * token;

    printf("Enter a filename to load from: ");      //get file name
    scanf("%s", filename);

    fptr = fopen(filename, "r");

    if (fptr == NULL) {
        printf("Failed import");
    } else {
        ptr = *tweetList;
        while (!feof(fptr)) {
            fgets(line,141,fptr);       //read one line

            token = strtok(line, ",");        //split string for userid
            id = atoi(token);

            token = strtok(NULL, ",");      //split string to get username
            strcpy(username, token);  
        
            token = strtok(NULL, "\0");         //split string to get the tweet
            for (int i=strlen(token); i>0; i--) {       //reverse loop to remove the comma ',' at the end of the string
                if (token[i] == ',') {
                    token[i] = '\0';
                    i = -5;
                }
            }
            strcpy(text, token);

            if (ptr == NULL) {      //if this is the first tweet in the linked list
                new->id = id;       //assign values to nodes
                strcpy(new->text, text);
                strcpy(new->user, username);
                new->next = malloc(sizeof(tweet));
                new->next = NULL;       //allocate memory for next pointer and make it null
                ptr = new;
                *tweetList = ptr;
            } else {
                while(ptr->next != NULL) {      //find the last node
                    ptr = ptr->next;
                }
                ptr->next = malloc(sizeof(tweet));      //allocate memory for new node
                ptr->next->id = id;
                strcpy(ptr->next->text, text);
                strcpy(ptr->next->user, username);
                ptr->next->next = NULL;
            }

        }
        printf("Tweets imported!\n");
    }

    fclose(fptr);
}