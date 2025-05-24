#include <stdio.h>

char alphabet[61] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k',
                     'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
                     '(', '<', '=', '+', ')', '[', '*', '/', ']', '{', '>', '!', '-', '}', '?',
                     '\\', '&', '|', '%', '_', ';', '"', '#', '.', '\'', '0', '1', '2', '3', '4',
                     '5', '6', '7', '8', '9'};

int my_decrypter(char file_in, int my_key); /*function that decrypts read characters*/
void in_comment(char file_in, int my_key);  /*function that decrypts comment length*/

int main() /*Main function*/
{
    int my_key = 2;                      /*It is calculated %10 then /10 then sum of digits till reach one digit */
    char file_in;                        /*variable that catch to read characters*/
    while (scanf("%c", &file_in) != EOF) /*this loop works untill reach to end of the file*/
    {
        if (file_in == '@') /*if this characters read means now you are in comment*/
            in_comment(file_in, my_key);
        else
            my_decrypter(file_in, my_key); /*if you are not in comment then decrypt the read characters*/
    }
    return 0;
}

int my_decrypter(char file_in, int my_key)
{
    int place_finder = 0; /*variable that determine where the readed characters in the alphabet array*/
    if ((file_in == ' ') || (file_in == '\n'))
    {
        printf("%c", file_in);
    }
    else
    {
        for (place_finder = 0; place_finder < 61; place_finder++) /*looking for the read character where in alphabet array*/
        {
            if (alphabet[place_finder] == file_in) /*if founded then print it*/
            {
                place_finder = place_finder - my_key;
                if (place_finder < 0) /*if we want to go to end of the alphabet then this arithmetic */
                {
                    place_finder++;
                    place_finder += 60;
                }
                printf("%c", alphabet[place_finder]); /*print decrypted character*/
                return 0;                             /* after catch, print, and decrypt the character return (such a break) */
            }
        }

        printf("%c", file_in); /*if any character not found, print file_in */
    }
    return 0;
}

void in_comment(char file_in, int my_key)
{
    scanf(" %c", &file_in); /* ignore the space and read the length of the comment */
    printf("/* There is ");
    while (file_in != ' ' && file_in != '\n') /*if this characters read then the comment ends else decrypt them till end*/
    {
        my_decrypter(file_in, my_key);
        scanf("%c", &file_in);
    }
    printf(" characters as comment */\n");
}
