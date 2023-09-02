/*
 * File: Task 3.c
 * Author: Aya Ashraf
 * Description: This program allows the user to view,add,remove and mark tasks as complete or incomplete (minions task manager)
 */

/* Header Files */
#include <stdio.h>  // Standard I/O functions
#include <stdlib.h> // Standard library functions



/* Function Declarations */
/**
 * @brief A function to allow user to add tasks
 * @param param1 the array in which the tasks are stored
 * @param param2 the number of tasks stored in the array
 * @return return nothing.
 */
void Add_Task(char arr[][50],int* counter);

/* Function Declarations */
/**
 * @brief A function that prints the tasks stored
 * @param param1 the array in which the tasks are stored
 * @param param2 the number of tasks stored in the array
 * @return return nothing.
 */
void View_Task(char arr[][50],int* counter);


/* Function Declarations */
/**
 * @brief A function that removes a task specified by the user
 * @param param1 the array in which the tasks are stored
 * @param param2 the number of tasks stored in the array
 * @return return nothing.
 */
void Remove_Task(char arr[][50],int* counter);


/* Function Declarations */
/**
 * @brief A function that mark the tasks as completed
 * @param param1 the array in which the completed tasks are stored
 * @param param2 the number of completed tasks
 * @return return nothing.
 */
void Mark_complete(char arr2[][50],int* counterMark);


/* Function Declarations */
/**
 * @brief A function that view the completed tasks
 * @param param1 the array in which the completed tasks are stored
 * @param param2 the number of completed tasks
 * @return return nothing.
 */
void View_Mark(char arr2[][50],int* counterMark);

/* Function Declarations */
/**
 * @brief A function that view the tasks in the form of table
 * @param param1 the array in which the tasks are stored
 * @param param2 the number of tasks
 * @return return nothing.
 */
void Table(char arr[][50],int* counter);



/* Function Definitions */
void Mark_complete(char arr2[][50],int* counterMark){
    printf("Enter the description of completed task:");
    scanf("%s",arr2[*counterMark]);
    (*counterMark)++;


}
/* Function Definitions */
void View_Mark(char arr2[][50],int* counterMark){

    for (int i=0;i<(*counterMark);i++){
            printf("Description:%s\n",arr2[i]);
        }
}


/* Function Definitions */
void Table(char arr[][50],int* counter){
           for(int i=0;i<*counter;i++){
           printf("Task ID:%d\t",i);
           printf("Description:%s\n",arr[i]);
           }
    }


/* Main Function */
int main() {
    int option=1; //variable for choosing the option you want to execute
    int counter=0;
    int counterMark=0;
    char arr[100][50];
    char arr2[100][50];
    while(counter<100){

        printf("\nMinions Task Manager\n1.Add Task\n2.View Tasks\n3.Remove Task\n4.Mark tasks as completed\n5.View Completed Tasks\n6.Table format\n7.Exit\n");
        printf("Select an option:");
        scanf("%d",&option);
        printf("\n");

/* Validation for entering the correct number*/
        while(option<1||option>7){
        printf("Incorrect input...Please enter a number from 1 to 5.");
        scanf("%d",&option);
    }


        switch (option){

            case 1:
                Add_Task(arr,&counter);
                break;

            case 2:
                View_Task(arr,&counter);
                break;

            case 3:
                Remove_Task(arr,&counter);
                break;

            case 4:
                Mark_complete(arr2,&counterMark);
                break;

            case 5:
                View_Mark(arr2,&counterMark);
                break;

             case 6:
                Table(arr,&counter);
                break;

            case 7:
                printf("Exiting Minions Task Manager. Have a great day!\n");
                exit(0);


    }
    }

    return 0;


}
/* Function Definitions */

void Add_Task(char arr[][50],int* counter){
    printf("Enter task description:");
    scanf("%s",arr[*counter]);
    if(*counter < 100) {
        (*counter)++;
}   else {
        printf("Task list is full!");
}
    printf("Task added successfully!\n");


}
/* Function Definitions */

void View_Task(char arr[][50],int* counter){
    printf("Current Tasks\n");
    for(int i=0;i<*counter;i++){
        printf("Task ID:%d\n",i);
        printf("Description:%s\n",arr[i]);
    }

}
/* Function Definitions */

void Remove_Task(char arr[][50],int* counter){
    int RemoveId;
    printf("Enter Task ID to remove:");
    scanf("%d",&RemoveId);

    /* Validation for the removal position */

    if(RemoveId < 0 || RemoveId > (*counter)-1)
    {
        printf("Invalid ID! Please enter a number from 0 to %d", *counter);
    }
    else
    {
        /* Copy next element value to current element */

        for(int i=RemoveId; i<*counter; i++)
        {
            arr[i][50] = arr[i + 1][50];
        }

        /* Decrement array size by 1 */
        (*counter)--;

        printf("Task removed successfully!\n");


}

/******* The Mark_Complete, View_Mark and Table functions are before the function main()*****/


}








