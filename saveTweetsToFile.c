#include "headerA3.h"
#include "myHeader.h"

void saveTweetsToFile(tweet * tweetList){
    char filename[50];
    FILE * fptr;
    tweet * ptr = malloc(sizeof(tweet));
    ptr = tweetList;

    printf("Enter the filename where you would like to store your tweets: ");
    scanf("%s", filename);

    fptr = fopen(filename, "w");
    if (fptr == NULL) {
        printf("Could not open file.\n");         // print message if file did not open
    } else {
        while (ptr != NULL) {
            fprintf(fptr, "%d,%s,%s\n", ptr->id, ptr->user, ptr->text);      //add first message into file
            ptr = ptr->next;
        }

        fclose(fptr);
        printf("Output successful!\n");
    }

}