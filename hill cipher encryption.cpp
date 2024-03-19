#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 3 // Assuming a 3x3 key matrix
#define MOD 26 // Modulo for alphabetic characters

// Function to encrypt a message using Hill cipher
void hill_encrypt(const int *plaintext, int key[N][N], int n, int *ciphertext) {
    int i, j, k;
    int padded_len = n + (N - (n % N)); // Padding the plaintext if its length is not divisible by N
    int padded_plaintext[padded_len];
    memcpy(padded_plaintext, plaintext, n * sizeof(int));
    for (i = n; i < padded_len; i++) {
        padded_plaintext[i] = 'X' - 'A'; // Padding with 'X'
    }

    // Encrypting the padded plaintext
    for (i = 0; i < padded_len; i += N) {
        for (j = 0; j < N; j++) {
            int sum = 0;
            for (k = 0; k < N; k++) {
                sum += (key[j][k] * padded_plaintext[i + k]);
            }
            ciphertext[i + j] = (sum % MOD);
        }
    }
}

int main() {
    int cipher_text_len;
    printf("Enter the length of the ciphertext: ");
    scanf("%d", &cipher_text_len);

    int cipher[cipher_text_len];
    printf("Enter the ciphertext (in numbers): ");
    for (int i = 0; i < cipher_text_len; i++) {
        scanf("%d", &cipher[i]);
    }

    int key[N][N];
    printf("Enter the key matrix (3x3): ");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &key[i][j]);
        }
    }

    int plaintext[cipher_text_len];
    hill_encrypt(cipher, key, cipher_text_len, plaintext);

    printf("Decrypted text: ");
    for (int i = 0; i < cipher_text_len; i++) {
        printf("%c", plaintext[i] + 'A');
    }
    printf("\n");

    return 0;
}

