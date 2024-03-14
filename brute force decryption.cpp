#include <stdio.h>
#include <string.h>

void decrypt(char *text) {
    int i, j;
    for (i = 0; i < 26; i++) {
        printf("Shift %d: ", i);
        for (j = 0; j < strlen(text); j++) {
            char ch = text[j];
            if (ch >= 'A' && ch <= 'Z') {
                ch = 'A' + ((ch - 'A' - i + 26) % 26);
            } else if (ch >= 'a' && ch <= 'z') {
                ch = 'a' + ((ch - 'a' - i + 26) % 26);
            }
            printf("%c", ch);
        }
        printf("\n");
    }
}

int main() {
    char text[100];
    
    printf("Enter the ciphertext to decrypt: ");
    fgets(text, sizeof(text), stdin);
    
    printf("\nBrute-force decryption:\n");
    decrypt(text);
    
    return 0;
}

