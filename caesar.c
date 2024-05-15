#include <stdio.h>
#include <string.h>

void caesarEnc(char message[], int shift) {
    int i;
    char chr;
    for(i = 0; message[i] != '\0'; ++i) {
        chr = message[i];
        if(chr >= 'A' && chr <= 'Z')
            message[i] = (chr + shift - 'A') % 26 + 'A';
        else if(chr >= 'a' && chr <= 'z')
            message[i] = (chr + shift - 'a') % 26 + 'a';
    }
}
int main() {
    char message[100];
    int shift;
    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);
    printf("Enter the shift value: ");
    scanf("%d", &shift);
    shift = shift % 26;
    caesarEnc(message, shift);
    printf("Encrypted message: %s\n", message);
    return 0;
}
