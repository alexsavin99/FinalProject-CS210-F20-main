#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
struct Words { 
    int size;
    char word[50]; 
}; 
  

struct Words choose_word(){
    struct Words w;
    FILE* inFile = NULL;
    inFile = fopen("dictionary.txt", "r");
    int r=rand() % 178692;
    int i=1;
    for (i=1; i<=r; i++){
        fscanf(inFile," %s", w.word);
        w.size=strlen(w.word);
    }
    fclose(inFile);
    return w;
}
void draw_initial(int lenght){
    FILE* outFile = NULL;
    outFile = fopen("hangman.txt", "w");
    int i=1;
    for (i=1;i<=lenght;i++){
        fprintf(outFile, "_");
    }
    fclose(outFile);
}
char ask_letter(){
    char letter;
    scanf(" %c", letter);
    if (letter>='a'&&letter<='z'){
        if(letter>='A'&&letter<='Z'){
            return letter;
        }
    }
    else{
        ask_letter();
    }
}
int occurance(char letter,char word[50]){
    int i=0;
    for(i=0;i<strlen(word);i++){
        if (word[i]==letter){
            return i;
        }
    }
 return -1;
}
void fill_blanks(int position, char letter){
    char line[50];
    FILE* inFile = NULL;
    inFile = fopen("dictionary.txt", "r");
    fscanf(inFile," %s", line);
    fclose(inFile);
    FILE* outFile = NULL;
    outFile = fopen("hangman.txt", "w");
    int i=1;
    for (i=1;i<position;i++){
        fprintf(outFile, " %c", line[i]);
    }
    fprintf(outFile, " %c", letter);
    for (i=position+1;i<strlen(line);i++){
    fprintf(outFile, " %c", line[i]);
    }
    fclose(outFile);
}