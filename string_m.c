#include <stdio.h>
#include <string.h>

/* strcopy() */
void strcopy(char *s1, char *s2) 
{
    while (*s2 != '\0') {
        *s1 = *s2;
        s1++;
        s2++;
    }
    *s1 = '\0';
}

/* strcomp() */
int strcomp(char *s1, char *s2) 
{
    while (*s1 != '\0' && *s2 != '\0') {
        if (*s1 != *s2)
            return (*s1 - *s2);
        s1++;
        s2++;
    }
    return (*s1 - *s2);
}

/* strconcat() */
void strconcat(char *s1, char *s2) 
{
    while (*s1 != '\0')
        s1++;
    while (*s2 != '\0') {
        *s1 = *s2;
        s1++;
        s2++;
    }
    *s1 = '\0';
}

/* Strreverse() */
void Strreverse(char *s1) 
{
    int i = 0, j, k = 0;
    char s3[50];
    char *temp = s1;

    while (*temp) {
        temp++;
        k++;
    }
    temp = s1;
    for (i = 0, j = k - 1; j >= 0; j--, i++) {
        s3[i] = temp[j];
    }
    s3[i] = '\0';
    strcopy(s1, s3);
}

int main() 
{
    char s1[80], s2[80], t1[80];
    int choice, result;

    printf("enter 2 strings\n");
    gets(s1); 
    gets(s2);

    strcopy(t1, s1);

    printf("--------- MENU ----------\n");
    printf("1. strcomp\n2. strcopy\n3. strconcat\n4. String reverse\n");

    for (;;) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            strcopy(s1, t1);
            result = strcomp(s1, s2);
            if (result > 0)
                printf("%s is greater than %s\n", s1, s2);
            else if (result < 0)
                printf("%s is greater than %s\n", s2, s1);
            else
                printf("strings are equal\n");
            break;

        case 2:
            strcopy(s1, t1);
            printf("Before copying: s1=%s, s2=%s\n", s1, s2);
            strcopy(s1, s2);
            printf("After copying:  s1=%s, s2=%s\n", s1, s2);
            break;

        case 3:
            strcopy(s1, t1);
            printf("Before concatenation: s1=%s, s2=%s\n", s1, s2);
            strconcat(s1, s2);
            printf("After concatenation:  s1=%s, s2=%s\n", s1, s2);
            break;

        case 4:
            strcopy(s1, t1);
            printf("Before reversing: s1=%s, s2=%s\n", s1, s2);
            printf("After reversing:\n");
            Strreverse(s1);
            printf("s1=%s\n", s1);
            strcopy(s1, s2);
            Strreverse(s1);
            printf("s2=%s\n", s1);
            break;

        default:
            return 0;
        }
    }
}