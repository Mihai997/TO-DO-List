///\file main.c
///\brief C TO-DO LIST
/// Created by Birsan Maria Cristina

#include "main.h"
#include <stdio.h>
#include <stdlib.h>

///Files used for storage
FILE *tasksfile;
FILE *Auxiliar;

/// MAIN PROGRAM
int main(){

        ///When you want to insert random tasks
        /*
        // Variable used for iterate
        int i;
        // Initilalize the time
        srand(time(NULL));
        for(i=0; i<= 1; i++)
                // We call function for random task;
                random_task();
        */

        ///\var x - The variable for switch function
        int x;

        printf( "           TO DO LIST ");
        printf( "\n                   by Maria Birsan");

        Back:

        /// Display the menu
        printf("\n\n\n 0) Display all tasks \n");
        printf(" 1) Create a task \n");
        printf(" 2) Complete a task \n");
        printf(" 3) Delete a category \n");
        printf(" 4) Modify a category \n");
        printf(" 5) Sort tasks by priority \n");
        printf(" 6) Display by category \n");
        printf(" 7) LEGEND \n");

        printf( "\n Press the desired key :");
        scanf("%d", &x);

        ///Function for commands menu
        switch( x ){
        case 0:
                print_tasks();
                goto Back;
        case 1:
                create_task();
                goto Back;
        case 2:
                delete_task();
                goto Back;
        case 3:
                delete_category();
                goto Back;
        case 4:
                modify_category();
                goto Back;
        case 5:
                sort_by_priority();
                goto Back;
        case 6:
                display_by_category();
                goto Back;
        case 7:
                ///We display the legends of comands
                printf("\n -- LEGEND --");
                printf(" \n\n Initial we have four categories : Life , Family , Work , Fun. \n If you want to add more categories write this when you create a task \n ");
                printf(" And three priorities : \n\t 1-Do now \n\t 2-Do Tomorrow \n\t 3-Do when you get some extra time \n\n");
                printf(" -- LEGEND END--");
                goto Back;
        default :
                printf(" \n ! ! ! This command doesn't exists ! ! ! \n");
                goto Back;

        }


        return 0;
}
