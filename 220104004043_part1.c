#include <stdio.h>
/*Global defined array that leads to encrypt*/
char alphabet[61] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k',
                     'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
                     '(', '<', '=', '+', ')', '[', '*', '/', ']', '{', '>', '!', '-', '}', '?',
                     '\\', '&', '|', '%', '_', ';', '"', '#', '.', '\'', '0', '1', '2', '3', '4',
                     '5', '6', '7', '8', '9'};

void my_encrypter(char dinamic_store, int my_key); /*function that encrypts read characters*/
void counter_writer(int counter, int my_key);      /*function that print counted comment characters */
int in_out_comment(int my_key);                    /*function that determine whether are we in comment or not*/

int main() /*Main function*/
{
    int my_key = 2; /*It is calculated %10 then /10 then sum of digits till reach one digit */
    char file_in;   /*variable that catch to read characters*/
    int index = 0;
    char dinamic_store = ' '; /*variable that catch to read characters(such a version of file_in)*/
    int counter = 0;          /*variable that */

    while (scanf("%c", &file_in) != EOF) /*this loop works untill reach to end of the file*/
    {
        if (file_in == '/') /*if this characters read means you may in comment*/
        {
            dinamic_store = file_in; /*store the chracters readed in to another variable since we can look for another character it can be a '*' */
            scanf("%c", &file_in);
            if (file_in == '*') /*check whether we are in comment or not*/
            {
                counter = in_out_comment(my_key); /*call the function that counts the characters in comment*/
                printf("@ ");                     /*print the mark*/
                counter_writer(counter, my_key);  /*after printing the mark print the counter. The counter encrypted by counter_writer function*/
            }
            else /*if we have possibility that it can be comment this else might work .if we are not in comment then encript the characters*/
            {
                my_encrypter(dinamic_store, my_key);
            }
        }
        else /*if we are not in comment then encript the characters*/
        {
            my_encrypter(file_in, my_key);
        }
    }
    return 0;
}

void my_encrypter(char dinamic_store, int my_key)
{
    int place_finder = 0; /*variable that determine where the readed characters in the alphabet array*/
    if ((dinamic_store == ' ') || (dinamic_store == '\n'))
    {
        printf("%c", dinamic_store);
    }
    else
    {
        for (place_finder = 0; place_finder < 61; place_finder++) /*looking for the read character where in the alphabet array*/
        {
            if (alphabet[place_finder] == dinamic_store) /*if founded then print it*/
            {
                place_finder += my_key; /*arrange array index with the key*/
                if (place_finder > 60)  /*if we want to go to at the beginning of the alphabet by this arithmetic */
                {
                    place_finder--;
                    place_finder = place_finder % 60;
                }
                printf("%c", alphabet[place_finder]);
                break;
            }
        }
    }
}

void counter_writer(int counter, int my_key)
{
    int digit_num = 0;         /*variable that catch the digits*/
    int divide_mode_num = 1;   /*variable that will be used to help in encrypting*/
    int old_counter = counter; /*temp variable to catch the value of counter*/
    while (counter != 0)       /*count the counter (how mant digits it is)*/
    {
        counter = counter / 10;
        digit_num++;
    }

    int i;
    for (i = 0; i < digit_num - 1; i++) /*calculate divide_mod_num that used in moding and dividing*/
    {
        divide_mode_num *= 10;
    }

    while (digit_num > 0) /*while the counter length*/
    {
        my_encrypter((old_counter / divide_mode_num) + '0', my_key); /*encrypt the first digit*/
        old_counter = old_counter % divide_mode_num;                 /*then the remove first digit by this arithmetic*/
        divide_mode_num = divide_mode_num / 10;                      /*update divide_mod_num such a decreasing*/
        digit_num--;                                                 /*decrease the length*/
    }
}

int in_out_comment(int my_key)
{
    int comment_counter = 0; /*variable that counts the characters in comment*/
    char file_in;            /*variable that catch the read character*/
    int comment_flag = 1;    /*this is a flag that tell us to stay or leave the comment*/

    while (comment_flag) /*while we are in comment*/
    {
        scanf("%c", &file_in);
        if (file_in == '*')
        {
            scanf("%c", &file_in);
            if (file_in == '/') /*if '*' and '/' comes after each other then the comment is finish*/
            {
                comment_flag = 0; /*then flag is off and get out of loop*/
            }
            else /*else count the characters in comment except space*/
            {
                if (file_in != ' ')
                {
                    comment_counter++;
                }
            }
        }
        else /*else count the characters in comment except the space*/
        {
            if (file_in != ' ')
            {
                comment_counter++;
            }
        }
    }
    return comment_counter; /*return the counter value to use it to encrypt it*/
}
