#include <stdio.h>
#include <string.h>
// Function to encrypt the message using Caesar cipher
void caesarEncrypt(char message[], int shift) {
    int i;
    char ch;
    for(i = 0; message[i] != '\0'; ++i) {
        ch = message[i];
        // Encrypt uppercase letters
        if(ch >= 'A' && ch <= 'Z')
            message[i] = (ch + shift - 'A') % 26 + 'A';
        // Encrypt lowercase letters
        else if(ch >= 'a' && ch <= 'z')
            message[i] = (ch + shift - 'a') % 26 + 'a';
    }
}
int main() {
    char message[100];
    int shift;
    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);
    printf("Enter the shift value: ");
    scanf("%d", &shift);
    // Ensure shift is within the range of 0 to 25
    shift = shift % 26;
    caesarEncrypt(message, shift);
    printf("Encrypted message: %s\n", message);
    return 0;
}
