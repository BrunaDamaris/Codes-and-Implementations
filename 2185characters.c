#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    char words[1000],biggestword[1000];
    int size = 0,i = 0,j = 0,max = 0,carriage = 0;
    scanf("%s",words);
    while(!strcmp(words,"0") == 0){
        printf("%d",strlen(words));
        if(strlen(words) > max){
            max = strlen(words);
            for(i = 0;i < strlen(words);i++) biggestword[i] = words[i];
        }
        scanf("%s",words);
        if(words[strlen(words)-1] == '\n') printf("\n");
        else printf("-");
    }
    printf("\nMaior palavra: %s\n",biggestword);
	return 0;
}
