#include <stdio.h>
#pragma warning(disable: 4996)
#include <stdlib.h> 

int count_var(char* argv);
int check_input(char* argv);

int main(int argc, char** argv) {
    /*
    if ((argc != 2) || check_input(str)) {
        printf("input must be one with only 1 and 0\n");
        return (0);
    }*/
    printf("Enter value : ");
    char str[128] = { 0, };
    scanf("%s", &str);

    int count = count_var(str);

    printf("input             : ");
    for (int i = 0; i < count; i++)
        printf("  %c ", str[i]);

    printf("\nManchester        : ");//Manchester
    if (str[0] == '0')//first signal, first row
        printf("--o ");
    else if (str[0] == '1')
        printf("  o-");
    for (int i = 1; i < count; i++) {//mid signal
        if (str[i] == '0' && str[i - 1] == '0')
            printf("o-o ");
        else if (str[i] == '1' && str[i - 1] == '1')
            printf("o o-");
        else {
            if (str[i] == '0')
                printf("--o ");
            else if (str[i] == '1')
                printf("  o-");
        }
    }

    for (int j = 0; j < 2; j++) {//mid row
        printf("\n                    ");
        printf("  | ");
        for (int i = 1; i < count; i++) {
            if (str[i - 1] == str[i])
                printf("| | ");
            else
                printf("  | ");
        }
    }


    printf("\n                    ");
    if (str[0] == '0')//last row
        printf("  o-");
    else if (str[0] == '1')
        printf("--o ");
    for (int i = 1; i < count; i++) {//mid signal
        if (str[i] == '0' && str[i - 1] == '0')
            printf("o o-");
        else if (str[i] == '1' && str[i - 1] == '1')
            printf("o-o ");
        else if (str[i] == '1' && str[i - 1] == '0')
            printf("--o ");
        else
            printf("  o-");
    }


    printf("\nDifferential");        //Differential
    printf("\nManchester        : ");//Manchester
    int up_down = 1;                 //counter

    printf("  o-");//first row
    for (int i = 1; i < count; i++) {//mid signal
        if (up_down == 1) {
            if (str[i] == '1') {
                printf("--o ");
                up_down = 0;
            }
            else if (str[i] == '0')
                printf("o o-");
        }
        else if (up_down == 0) {
            if (str[i] == '1') {
                printf("  o-");
                up_down = 1;
            }
            else if (str[i] == '0') {
                printf("o-o ");
            }
        }
    }

    for (int j = 0; j < 2; j++) {//mid row
        printf("\n                    ");
        printf("  | ");
        for (int i = 1; i < count; i++) {//mid signal
            if (str[i] == '0')
                printf("| | ");
            else if (str[i] == '1')
                printf("  | ");
        }
    }

    printf("\n                    ");
    printf("--o ");//last row
    up_down = 1;
    for (int i = 1; i < count; i++) {//mid signal
        if (up_down == 1) {
            if (str[i] == '1') {
                printf("  o-");
                up_down = 0;
            }
            else if (str[i] == '0')
                printf("o-o ");
        }
        else if (up_down == 0) {
            if (str[i] == '1') {
                printf("--o ");
                up_down = 1;
            }
            else if (str[i] == '0') {
                printf("o o-");
            }
        }
    }

    printf("\n");
    for(int i = 5; i > 0; i--) {
        printf("program closes in %d\n", i);
        _sleep(1000);
    }
}

int count_var(char* argv) {
    int i = 0;
    while (argv[i])
        i++;
    return (i);
}

int check_input(char* argv) {
    int i = 0;
    while (argv[i] != '\0') {
        if (argv[i] == '0' || argv[i] == '1')
            i++;
        else
            return (1);
    }
    return (0);
}