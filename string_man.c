#include<stdio.h>

void str_cpy(char *str1,char *str2){

    while(*str2 != '\0'){
        *str1 = *str2;
        str1++;
        str2++;
    }
    *str1 = '\0';
}

int strcomp(char *str1,char *str2){
    while(*str1!='\0' && *str2!='\0'){
        if(*str1 != *str2){
            return (*str1-*str2);
        }
        str1++;
        str2++;
    }
    return (*str1-*str2);
}

void strconcat(char *str1,char *str2){
    while(*str1 != '\0'){
        str1++;
    }while(*str2 != '\0'){
        *str1 = *str2;
        str1++;
        str2++;
    }
    *str1 = '\0';
}

void reverse(char *s1)
{
    char *start = s1;
    char *end = s1;
    char temp;

    while(*end != '\0'){
        end++;
    }
    end--;
    while(start<end){
        temp = *start;
        *start = *end;
        *end = temp;
    
    start++;
    end--;
    }
}

int main(){
    char s1[30],s2[30],t1[80];
    int choice,result;
    printf("Enter two strings\n");
    gets(s1);
    gets(s2);

    strcopy(t1,s1);

    printf("*Menu");
    printf("1.string copy\n,2.string compare\n,3.String concatenate\n,4.string reverse\n");
    
    while(1){
    printf("Enter your choice:");
    scanf("%d",&choice);

    switch (choice){
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
                str_cpy(s1, s2);
                printf("After copy, S1: %s\n", s1);
                break;
            case 3:
                strconcat(s1, s2);
                printf("After concatenation, S1: %s\n", s1);
                break;
            case 4:
                reverse(s1);
                printf("After reverse, S1: %s\n", s1);
                break; 
            case 5:
                return 0;
            default:
                printf("Invalid choice!\n");
    }
    }
    return 0;
}