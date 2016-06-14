#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encoder();

int main(void)
{
    encoder();
    return 0;
}

void encoder(/*const char * s, char * encoded*/)
{
    char code1[] = "CUTSDIR";
    char code2[] = "abcdefg";
    char s[] = "CSITAdv";
    int i;
    int r = 0;
    int e = 0;
    char encoded[1000];

    for(i = 0; i < strlen(s); i++)
    {
        while(i < strlen(s))
        {
            if(s[i] == code1[r])
            {
                printf("(Code1) There is a match at the index %d, %c\n", r, s[i]);
                strncat(encoded, &code2[r], 1);
                break;
            }
            else if(s[i] == code2[e])
            {
                printf("(Code2) There is a match at the index %d, %c\n", e, s[i]);
                strncat(encoded, &code1[e], 1);
                break;
            }
            else if(r == 7 && e == 7)
            {
                strncat(encoded, &s[i], 1);
                break;
            }
            r++;
            e++;
        }
        r = 0;
        e = 0;
    }
    printf("The encoded message = %s.\n", encoded);
}
