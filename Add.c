//Author: Chase Rodie
//Date: 06/11/23
//Purpose: Reads a file and takes inputs and adds them
#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define MAX_SIZE 1000
#define FILE_NAME "Programming-Project-1.txt"

//function prototypes
void displayHexadecimalValue(FILE*);

int main(){
    char string[MAX_SIZE];
    FILE* dest_fp;
    dest_fp = fopen(FILE_NAME,"r");
    if(dest_fp==NULL){
        printf("Can't open file.\n");
    }
    else{
     displayHexadecimalValue(dest_fp);
     fclose(dest_fp);
    }
    return 0;
}

void displayHexadecimalValue(FILE* fptr) {
    char string[MAX_SIZE];
    while (fgets(string, sizeof(string), fptr) != NULL) {
        string[strcspn(string, "\n")] = '\0';

        // Parsing hexadecimal values
        uint32_t num1, num2;
        sscanf(string, "ADD %*s %x %*s %x", &num1, &num2);

        // Performing addition
        uint32_t sum = num1 + num2;

        // Displaying the result
        printf("ADD %*s %#10x %*s %#10x: ", 10, "", num1, 10, "", num2);
        printf("%#10x\n", sum);
    }
}