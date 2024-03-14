#include <stdio.h>
#include <math.h>

// Function to calculate power in modular arithmetic
int power(int base, int exponent, int modulus) {
    int result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1)
            result = (result * base) % modulus;
        base = (base * base) % modulus;
        exponent = exponent / 2;
    }
    return result;
}

int main() {
    // Publicly agreed prime number
    int prime = 23;
    // Publicly agreed primitive root of prime
    int base = 5;

    // Alice's private key
    int privateA = 6;
    // Bob's private key
    int privateB = 15;

    // Calculate public keys
    int publicA = power(base, privateA, prime);
    int publicB = power(base, privateB, prime);

    // Shared secret calculation
    int secretA = power(publicB, privateA, prime);
    int secretB = power(publicA, privateB, prime);

    printf("Alice's public key: %d\n", publicA);
    printf("Bob's public key: %d\n", publicB);
    printf("Shared secret calculated by Alice: %d\n", secretA);
    printf("Shared secret calculated by Bob: %d\n", secretB);

    return 0;
}

