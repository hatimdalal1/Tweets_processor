#include "headerA3.h"
#include "myHeader.h"

void countStopWords(tweet * tweetList) {

    int numTweets = 0;
    int numStop = 0;
    char * text=malloc(sizeof(char)*142);
    tweet * ptr;
    char stopArr[25][10] = {"a","an","and","are","as","at","be","by","for","from","has","he","in","is","it","its","of","on","that","the","to","was","were","will","with"};
    char * token;
    char s[2] = " ";


    ptr = tweetList;
    while (ptr != NULL) {           //go through the linked list
        numTweets++;
        strcpy(text, ptr->text);

        token = strtok(text, s);
        for (int i=0; i<strlen(text); i++) {
            text[i] = tolower(text[i]);
        }
        while( token != NULL ) {
            for (int i=0; i<25; i++) {
                if (strcmp(token, stopArr[i]) == 0) {       //compare each stop word with words in the tweet
                    numStop++;
                }
            }
            token = strtok(NULL, s);
            for (int i=0; i<strlen(text); i++) {
                text[i] = tolower(text[i]);
            }
        }
        ptr = ptr->next;
    }    

    printf("Across %d tweets, %d stop words were found\n", numTweets, numStop);

}