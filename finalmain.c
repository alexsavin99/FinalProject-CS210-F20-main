struct Words { 
    int size;
    char word[50]; 
}; 
  
typedef struct  Words Struct;//used struct to return multiple variables from a function
int main() {
    int status=0;
    char letter;
    int* o;//occurance variable that determines if a letter occurs and what the position of that letter is
    struct Words w = choose_word();
    draw_initial(w.size);
    while(status<5){
        letter=ask_letter();
        o=occurance(letter, w.word);
        if (o[0]!=-1){
            fill_blanks(o, letter);
        }
        else{
            status++;//status incremented before calling the function because it uses 
            draw_hangman(status);  
        }
    }
    
    return 0;
}