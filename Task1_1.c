#include <stdio.h>
#include <stdlib.h>

//This code prints the string "GRU" and in asterisks
int main()
{
    printf("GRU\n");

  /* The word in asterisks*/
    for (int i=0; i<5;i++){
        switch (i){
            case 0:
                printf("*****    ****     *    *\n");
                break;
            case 1:
                printf("*        *   *    *    *\n");
                break;
            case 2:
                printf("*  **    ****     *    *\n");
                break;
            case 3:
                printf("*   *    *   *    *    *\n");
                break;
            case 4:
                printf("*****    *    *   ******\n");
                break;
        }
    }
    return 0;
}

