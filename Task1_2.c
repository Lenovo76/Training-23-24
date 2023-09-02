#include <stdio.h>
#include <stdlib.h>
/* This program counts down starting from the input taken from user till 1*/
int main()
{
    int count;
    scanf("%d",&count);

    // validation to ensure the input is positive
    while (count<=0){
        printf("Please enter a positive integer");
        scanf("%d",&count);
    }

    //Counter loop
    for(int i=count;i>=1;i--){
        printf("%d\n",i);
        sleep(1);
    }

    printf("Blast off to the moon!");

    return 0;
}
