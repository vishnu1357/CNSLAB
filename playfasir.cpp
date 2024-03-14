#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 5

// Function to prepare the key matrix
void prepareKey(char key[], char keyMatrix[SIZE][SIZE]) {
    int i, j, k, flag = 0;
    char alphabet[26] = "ABCDEFGHIKLMNOPQRSTUVWXYZ"; // Note: 'J' is removed

    // Copy the key into the key matrix
    for (i = 0; i < strlen(key); i++) {
        if (key[i] == 'J')
            continue; // Skip 'J' as per Playfair cipher rules
        for (j = 0; j < 26; j++) {
            if (key[i] == alphabet[j]) {
                keyMatrix[flag / SIZE][flag % SIZE] = key[i];
                alphabet[j] = ' '; // Mark the used alphabet as empty
                flag++;
                break;
            }
        }
    }

    // Fill the remaining cells of the key matrix with the remaining alphabets
    for (k = 0; k < 26; k++) {
        if (alphabet[k] != ' ') {
            keyMatrix[flag / SIZE][flag % SIZE] = alphabet[k];
            flag++;
        }
    }
}

// Function to find the position of a character in the key matrix
void findPosition(char keyMatrix[SIZE][SIZE], char ch, int *row, int *col) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (keyMatrix[i][j] == ch) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

// Function to encrypt a pair of letters using Playfair cipher
void encryptPair(char keyMatrix[SIZE][SIZE], char a, char b, char encryptedPair[2]) {
    int row1, col1, row2, col2;

    // Find positions of both letters in the key matrix
    findPosition(keyMatrix, a, &row1, &col1);
    findPosition(keyMatrix, b, &row2, &col2);

    // If both letters are in the same row, replace them with the letters to their immediate right
    if (row1 == row2) {
        encryptedPair[0] = keyMatrix[row1][(col1 + 1) % SIZE];
        encryptedPair[1] = keyMatrix[row2][(col2 + 1) % SIZE];
    }
    // If both letters are in the same column, replace them with the letters below them
    else if (col1 == col2) {
        encryptedPair[0] = keyMatrix[(row1 + 1) % SIZE][col1];
        encryptedPair[1] = keyMatrix[(row2 + 1) % SIZE][col2];
    }
    // If letters form a rectangle, replace them with the letters on the same row but at the opposite corners of the rectangle
    else {
        encryptedPair[0] = keyMatrix[row1][col2];
        encryptedPair[1] = keyMatrix[row2][col1];
    }
}

// Function to encrypt a plaintext using Playfair cipher
void playfairEncrypt(char keyMatrix[SIZE][SIZE], char plaintext[], char encryptedtext[]) {
    int i, j = 0;
    char encryptedPair[2];

    for (i = 0; i < strlen(plaintext); i += 2) {
        // If plaintext has an odd number of characters, add 'X' at the end
        if (i + 1 == strlen(plaintext)) {
            plaintext[i + 1] = 'X';
            plaintext[i + 2] = '\0';
        }
        encryptPair(keyMatrix, plaintext[i], plaintext[i + 1], encryptedPair);
        encryptedtext[j++] = encryptedPair[0];
        encryptedtext[j++] = encryptedPair[1];
    }
    encryptedtext[j] = '\0';
}

int main() {
    char key[SIZE * SIZE], plaintext[100], encryptedtext[100];
    char keyMatrix[SIZE][SIZE];

    printf("Enter the key (maximum 25 characters): ");
    scanf("%s", key);

    printf("Enter the plaintext: ");
    scanf("%s", plaintext);

    // Remove any spaces from the plaintext
    for (int i = 0; i < strlen(plaintext); i++) {
        if (plaintext[i] == ' ')
            strcpy(&plaintext[i], &plaintext[i + 1]);
    }

    // Convert key and plaintext to uppercase
    for (int i = 0; i < strlen(key); i++)
        key[i] = toupper(key[i]);
    for (int i = 0; i < strlen(plaintext); i++)
        plaintext[i] = toupper(plaintext[i]);

    // Prepare the key matrix
    prepareKey(key, keyMatrix);

    // Encrypt the plaintext
    playfairEncrypt(keyMatrix, plaintext, encryptedtext);

    printf("Encrypted text: %s\n", encryptedtext);

    return 0;
}

