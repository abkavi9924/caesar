#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
bool only_digits(string c);
string caesared(string text, int k);
int main(int argc, string argv[])
{
    if (argc != 2)//check if there are 2 arguments only (./caesar and the key)
    {
        printf("Usage: ./caesar key\n");
        return (1); //if not print this
    }
    else
    {
        bool Check = only_digits(argv[1]);//check if 2nd arguement is only an integer
        if (Check == true) //if yes then proceeds
        {
            int key = atoi(argv[1]);//convert the key(initially string) to int.
            string Plain_text = get_string("plaintext:  ");//get input
            string rotate = caesared(Plain_text, key);//rotate the word
            printf("ciphertext: %s\n", Plain_text);
        }
        if (Check == false)//if not then print this
        {
            printf("Warning: Key should be a integer\n");
            return (1);
        }
    }
}







bool only_digits(string c)//fuction returns true or false if input is int or not
{
    bool v;
    int i = 0, len = strlen(c);
    while (i < len)
    {

        if (isdigit(c[i]))
        {
            v = true;
        }
        else
        {
            v = false;
        }
        i++;

    }
    return (v);
}


//funtion 2:
string caesared(string text, int k)
{
    int i = 0, len = strlen(text);
    while (i < len)
    {
        int ckey = 0;
        if (isupper(text[i])) //checks the case
        {
            ckey = ((text[i] - 'A') + k) % 26; //formula
            char Upper_case[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
            text[i] = Upper_case[ckey];//returns from the above array
        }
        if (islower(text[i])) //same follows here
        {
            ckey = ((text[i] - 'a') + k) % 26;
            char lower_case[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
            text[i] = lower_case[ckey];
        }
        if (ispunct(text[i])) //check if puncuations are ther to keep them same
        {
            text[i] = text[i];
        }
        if (isspace(text[i])) //check if spaces are ther to keep the same
        {
            text[i] = text[i];
        }
        i++;
    }

    return (text);
}
