#include <stdio.h>
#include <string.h>

/*=================================================
                    INVERT CASE
Description:
    This is a pipe-friendly program. In my opinion,
the key to implementing pipe-friendly program is to 
have it handle input on a line-by-line basis.

=================================================*/

void invert_case(char *string, char *out);

int main(int argc, const char *argv[])
{
    char c[20] = {0};
    char new_case[20] = {0};
    
    while (fgets(c, sizeof(c), stdin) != NULL) {
        invert_case(c, new_case);

        printf("%s\n", new_case);
        memset(c, 0, sizeof(c));
        memset(new_case, 0, sizeof(new_case));
    }
}

void invert_case(char *string, char *out)
{
    int cout;

    for (cout = 0; cout < sizeof(string); cout++) {
        if (string[cout] >= 65 && string[cout] <= 90) { /* Upper case */
            out[cout] = string[cout] + 32;
        } else if (string[cout] >= 97 && string[cout] <= 122) { /* Lower case */
            out[cout] = string[cout] - 32;
        }
    }
}