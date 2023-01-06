#include "headerA3.h"
#include "myHeader.h"

int searchTweetsByKeyword( tweet * tweetList) {

    char keyword[50];
    char keywordC[50];
    int found = 0;
    char text[141];

    printf("Enter a keyword to search: ");
    scanf("%s", keyword);
    while (strlen(keyword) == 0) {
        printf("Enter a keyword to search: ");
        scanf("%s", keyword);
    }
    strcpy(keywordC, keyword);
    for(int i = 0; i < strlen(keywordC); i++){
        keywordC[i] = tolower(keywordC[i]);
    }

    tweet * ptr = malloc(sizeof(tweet));
    ptr = tweetList;

    if (ptr == NULL) {
        printf("list is empty");        
        return found;
    }

    char *check;
    while (ptr != NULL) {
        strcpy(text, ptr->text);
        for(int j = 0; j < strlen(text); j++){
            text[j] = tolower(text[j]);
        }
        check = strstr(text, keywordC);
        if (check != NULL) {
            printf("Match found for '%s': %s wrote: '%s'\n", keyword, ptr->user, ptr->text);
            found = 1;
        }
        ptr = ptr->next;
    }

    return found;
}