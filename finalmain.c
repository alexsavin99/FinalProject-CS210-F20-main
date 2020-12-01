struct Words { 
    int size;
    char word[50]; 
}; 
  
typedef struct  Words Struct;
int main() {
    struct Words w = choose_word();
    draw_initial(w.size);
    char letter=ask_letter();
    int o=occurance(letter, w.word);
    if (o!=-1){
        fill_blanks(o, letter);
    }
    
    return 0;
}