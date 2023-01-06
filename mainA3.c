#include "headerA3.h"
#include "myHeader.h"


int main () {

    int choice = 0;
    int keywordFound;

    tweet * start = malloc(sizeof(tweet));
    start = NULL;

    do {
        printf ("\nHere is the menu \n\n");
        printf ("1. Create a new tweet\n");
        printf ("2. Display tweets\n");
        printf ("3. Search a tweet (by keyword)\n");
        printf ("4. Find how many words are “stop words”\n");
        printf ("5. Delete the nth tweet\n");
        printf ("6. Save tweets to a file\n");
        printf ("7. Load tweets from a file\n");
        printf ("8. Sort the given linked list on userid.\n");
        printf ("9. Exit\n");
        
        printf ("Choose a menu option: ");
        scanf ("%d", &choice);
        
        switch (choice) {
            case 1:
                start = createTweet(start);

                break;
            case 2:
                displayTweets(start);

                break;
            case 3:
                keywordFound = searchTweetsByKeyword(start);
                if (keywordFound == 0) {
                    printf("not found\n");
                } else if (keywordFound == 1) {
                    printf("found\n");
                }

                break;
            case 4:
                countStopWords(start);
                break;
            case 5:
                deleteTweet( &start);
                break;
            case 6:
                saveTweetsToFile(start);
                break;
            case 7:
                loadTweetsFromFile(&start);
                break;                                
            case 8:
                sortID(&start);
                break;                
            case 9:
                printf("Exiting\n");
                free(start);
                break;

            default: printf ("That is an invalid choice\n");
                
        }
        
    } while (choice != 9);

    return 0;
}