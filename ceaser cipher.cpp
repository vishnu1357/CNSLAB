#include <stdio.h>

void encrypt(char *text, int shift) {
    while (*text) {
        if (*text >= 'A' && *text <= 'Z')
            *text = ((*text - 'A' + shift) % 26) + 'A';
        else if (*text >= 'a' && *text <= 'z')
            *text = ((*text - 'a' + shift) % 26) + 'a';
        text++;
    }
}

void decrypt(char *text, int shift) {
    while (*text) {
        if (*text >= 'A' && *text <= 'Z')
            *text = ((*text - 'A' - shift - 26) % 26) + 'A';
        else if (*text >= 'a' && *text <= 'z')
            *text = ((*text - 'a' - shift - 26) % 26) + 'a';
        text++;
    }
}

int main() {
    char text[100];
    int shift;
    
    printf("Enter a message to encrypt: ");
    fgets(text, sizeof(text), stdin);
    
    printf("Enter the shift value: ");
    scanf("%d", &shift);
    
    shift = shift % 26;
    
    encrypt(text, shift);
    
    printf("Encrypted message: %s\n", text);
    
    decrypt(text, shift); // Decrypting the message
    printf("Decrypted message: %s\n", text);
    
    return 0;
}

