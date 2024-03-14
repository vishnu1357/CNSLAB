#include<stdio.h>


void decrypt(char *text, int shift) {
    while (*text) {
        if (*text >= 'A' && *text <= 'Z')
            *text = ((*text - 'A' - shift) % 26) + 'A';
        else if (*text >= 'a' && *text <= 'z')
            *text = ((*text - 'a' - shift) % 26) + 'a';
        text++;
    }
}
int main(){
	char text[100];
	int shift;
	
	printf("Enter a message to decrypt: ");
	fgets(text,sizeof(text),stdin);
	
	printf("Enter the shift value: ");

	scanf("%d",&shift);
	
	shift = shift %26;
	
	decrypt(text,shift);
	
	printf("Decrpted message: %s\n",text);
	
	return 0;
}
