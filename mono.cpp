#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to perform monoalphabetic substitution encryption
void monoalphabeticEncrypt(char plaintext[], char key[]) {
    int i;
    // Encrypt each character in the plaintext
    for (i = 0; i < strlen(plaintext); i++) {
        if (isalpha(plaintext[i])) {
            // Convert character to uppercase
            plaintext[i] = toupper(plaintext[i]);
            // Encrypt the character using the substitution key
            if (plaintext[i] >= 'A' && plaintext[i] <= 'Z') {
                plaintext[i] = key[plaintext[i] - 'A'];
            }
        }
    }
}

// Function to perform monoalphabetic substitution decryption
void monoalphabeticDecrypt(char ciphertext[], char key[]) {
    int i;
    // Decrypt each character in the ciphertext
    for (i = 0; i < strlen(ciphertext); i++) {
        if (isalpha(ciphertext[i])) {
            // Convert character to uppercase
            ciphertext[i] = toupper(ciphertext[i]);
            // Decrypt the character using the substitution key
            if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z') {
                // Find the index of the character in the key and replace with the corresponding plaintext character
                ciphertext[i] = 'A' + strchr(key, ciphertext[i]) - key;
            }
        }
    }
}

int main() {
    char plaintext[100], ciphertext[100], key[26];
    int choice;

    printf("Enter the substitution key (26 unique uppercase letters): ");
    scanf("%s", key);

    // Check if the key contains 26 unique uppercase letters
    if (strlen(key) != 26) {
        printf("Invalid key length. Please enter 26 unique uppercase letters.\n");
        return 1;
    }
    for (int i = 0; i < 26; i++) {
        if (!isalpha(key[i]) || !isupper(key[i])) {
            printf("Invalid key format. Please enter 26 unique uppercase letters.\n");
            return 1;
        }
        for (int j = i + 1; j < 26; j++) {
            if (key[i] == key[j]) {
                printf("Duplicate letters found in the key. Please enter 26 unique uppercase letters.\n");
                return 1;
            }
        }
    }

    printf("Enter the plaintext: ");
    scanf(" %[^\n]s", plaintext);

    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            monoalphabeticEncrypt(plaintext, key);
            printf("Encrypted text: %s\n", plaintext);
            break;
        case 2:
            monoalphabeticDecrypt(plaintext, key);
            printf("Decrypted text: %s\n", plaintext);
            break;
        default:
            printf("Invalid choice. Please enter 1 or 2.\n");
            return 1;
    }

    return 0;
}

