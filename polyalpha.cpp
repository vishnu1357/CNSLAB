#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to perform Vigenère cipher encryption
void vigenereEncrypt(char plaintext[], char key[]) {
    int i, j = 0;
    // Encrypt each character in the plaintext
    for (i = 0; i < strlen(plaintext); i++) {
        if (isalpha(plaintext[i])) {
            // Convert characters to uppercase
            plaintext[i] = toupper(plaintext[i]);
            // Calculate the shift based on the corresponding key character
            int shift = toupper(key[j]) - 'A';
            // Encrypt the character using the shift
            plaintext[i] = ((plaintext[i] - 'A' + shift) % 26) + 'A';
            // Move to the next character in the key (looping if necessary)
            j = (j + 1) % strlen(key);
        }
    }
}

// Function to perform Vigenère cipher decryption
void vigenereDecrypt(char ciphertext[], char key[]) {
    int i, j = 0;
    // Decrypt each character in the ciphertext
    for (i = 0; i < strlen(ciphertext); i++) {
        if (isalpha(ciphertext[i])) {
            // Convert characters to uppercase
            ciphertext[i] = toupper(ciphertext[i]);
            // Calculate the reverse shift based on the corresponding key character
            int shift = toupper(key[j]) - 'A';
            // Decrypt the character using the reverse shift
            ciphertext[i] = ((ciphertext[i] - 'A' - shift + 26) % 26) + 'A';
            // Move to the next character in the key (looping if necessary)
            j = (j + 1) % strlen(key);
        }
    }
}

int main() {
    char plaintext[100], ciphertext[100], key[100];
    int choice;

    printf("Enter the key: ");
    scanf("%s", key);

    printf("Enter the plaintext: ");
    scanf(" %[^\n]s", plaintext);

    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            vigenereEncrypt(plaintext, key);
            printf("Encrypted text: %s\n", plaintext);
            break;
        case 2:
            vigenereDecrypt(plaintext, key);
            printf("Decrypted text: %s\n", plaintext);
            break;
        default:
            printf("Invalid choice. Please enter 1 or 2.\n");
            return 1;
    }

    return 0;
}

