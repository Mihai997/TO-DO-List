///\file Functions.c
///\brief C TO-DO LIST
/// Created by Birsan Maria Cristina
/**
*   Implements function for: displaying all tasks, creating a task, deleting a task,
*                         deleting or modifying the catergory, and sort tasks,
*                         and also for generating random tasks
*/

#include "main.h"
#include <stdio.h>
#include <stdlib.h>

///Files used for storage
FILE *tasksfile;
FILE *Auxiliar;

struct to_do_list{
        ///\brief The structure which contain task fields
        ///\param no - The task number
        ///\param task - The main text of the task
        ///\param category - The category of the task
        ///\param priority - The priority of the task

         int no;
         char task[200] ;
         char category[11] ;
         int priority ;

}tasks;


void create_task(){
        ///\brief The function for creating a task

        ///Prompts user to insert the data task
        printf("\n Enter task number : \n");
        scanf("%d",&tasks.no);

        printf("\n Enter task text : \n");
        fflush(stdin);           //memoreaza textul cu tot cu spatii
        gets(tasks.task);
        /// We used this for blank task
        if( (strcmp(tasks.task,"")) == 0  ){
                printf("\n\n Blank task!\n\n");
                return;
        }

        printf("\n Enter the task category from the following or NEW category : \n");
        printf(" Life / Family / Work / Fun \n");
        scanf("%s",tasks.category);

        printf("\n Enter the task priority from the following : \n");
        printf("  1 / 2 / 3 \n");
        scanf("%d",&tasks.priority);

        ///We open the file used for storage(append mode)
        tasksfile =fopen("tasksfile.txt","a+" );  //a+ de la append

        ///Store the data task in the file
        fprintf(tasksfile,"\n%d\t%s\t%s\t%d", tasks.no, tasks.task, tasks.category, tasks.priority);
        printf("\n\n Succesfull ! ! ! \n You added a new task to the list ! \n\n");

        ///We close the file used for storage
        fclose(tasksfile);

}

void print_tasks(){
        ///\brief The function for displaying all tasks
        printf("\n\nNumber      |    Task     |   Category | Priority\n");

        ///Variable used for traverse every character of the file
        int character;

        ///We open the file used for storage(read mode)
        FILE *tasksfile =fopen("tasksfile.txt","r" );      // r de la read
        if (tasksfile != NULL){
                character = fgetc(tasksfile);
                /// We traverse while the character isn't the end of file
                while (character != EOF){
                            putchar(character);
                            character = fgetc(tasksfile);
                }
                ///We close the file used for storage
                fclose(tasksfile);
        }

}

void delete_task(){
        /**
        *   \brief The function for deleting a task
        *   To do this, we prompts the user for the number of which task wants to delete,
        *             we search for the wanted task ( if exists ) and we store all tasks in a Auxiliar file
        *             and at the and we rename the Auxiliar file with our file name.
        */
        ///Variable used for the task number.
        int number;
        printf("Please insert the number of the task which you completed : ");
        scanf("%d", &number);
        ///We open the file used for storage(read mode)
        tasksfile = fopen("tasksfile.txt", "r");
        ///We open the Auxiliar file used for storage(write mode)
        Auxiliar = fopen("Auxiliar.txt", "w");
        /// We traverse the file while the entry isn't the end of file
        while((fscanf(tasksfile,"\n%d %[^\t]   %s   %d",  &tasks.no, tasks.task, tasks.category, &tasks.priority )) != EOF ){
                        if( tasks.no == number)
                                fscanf(tasksfile,"\n%d    %[^\t]   %s   %d",  &tasks.no, tasks.task, tasks.category, &tasks.priority) ;

                        fprintf(Auxiliar,"\n%d\t%s\t%s\t%d",  tasks.no, tasks.task, tasks.category, tasks.priority );
        }

        ///We close the files used for storage
        fclose(tasksfile);
        fclose(Auxiliar);
        remove("tasksfile.txt");
        rename("Auxiliar.txt", "tasksfile.txt");

        printf("\n\n       Succesful ! ! ! \n The task has been removed from the list ! ");


}


void delete_category(){
        /**
        *   \brief The function for deleting a category
        *   To do this, we prompts the user for the category which wants to delete,
        *             we store in a Auxiliar file all tasks excepts the tasks which have the wanted category
        *             and at the and we rename the Auxiliar file with our file name.
        */
        /// The string used for insert the wanted category
        char category[10];
        printf(" Please insert the category which you want to delete : ");
        scanf("%s", category);
        ///We open the file used for storage(read mode)
        tasksfile = fopen("tasksfile.txt", "r");
        ///We open the Auxiliar file used for storage(write mode)
        Auxiliar = fopen("Auxiliar.txt", "w");

        while((fscanf(tasksfile,"\n%d %[^\t]   %s   %d",  &tasks.no, tasks.task, tasks.category, &tasks.priority )) != EOF ){
                    while( strcmp(tasks.category, category) == 0 ){
                            ///We skip over the task which has wanted category
                            fscanf(tasksfile,"\n%d    %[^\t]   %s   %d",  &tasks.no, tasks.task, tasks.category, &tasks.priority) ;
                    }
                    fprintf(Auxiliar,"\n%d\t%s\t%s\t%d",  tasks.no, tasks.task, tasks.category, tasks.priority );
        }

        ///We close the files used for storage
        fclose(tasksfile);
        fclose(Auxiliar);
        remove("tasksfile.txt");
        rename("Auxiliar.txt", "tasksfile.txt");

        printf("       Succesful ! ! ! \n All tasks in this category have been deleted ! ");


    }


void modify_category(){
        /**
        *   \brief The function for modifying a category
        *   To do this, we prompts the user for the category which wants to modify and the new category,
        *             we store in a Auxiliar file all tasks,
        *             when a task has the wanted category we change with the new category
        *             and at the and we rename the Auxiliar file with our file name.
        */
        /// The string used for insert the wanted category
        char category[10];
        /// The string used for insert the new category
        char new_category[10];

        printf(" Please insert the category which you want to modify : ");
        scanf("%s", category);
        printf(" Please insert the NEW category : ");
        scanf("%s", new_category);

        ///We open the file used for storage(read mode)
        tasksfile = fopen("tasksfile.txt", "r");
        ///We open the Auxiliar file used for storage(write mode)
        Auxiliar = fopen("Auxiliar.txt", "w");;

        while((fscanf(tasksfile,"\n%d %[^\t]   %s   %d",  &tasks.no, &tasks.task, &tasks.category, &tasks.priority )) != EOF ){
                    while( strcmp(tasks.category, category) == 0 ){
                            ///We copy the new category in task category
                            strcpy(tasks.category, new_category);
                    }

                    fprintf(Auxiliar,"\n%d\t%s\t%s\t%d",  tasks.no, tasks.task, tasks.category, tasks.priority );
        }

        ///We close the files used for storage
        fclose(tasksfile);
        fclose(Auxiliar);
        remove("tasksfile.txt");
        rename("Auxiliar.txt", "tasksfile.txt");

        printf("\n\n       Succesful ! ! ! \n The catergory has been changed ! ");

}


void display_by_category(){
        /**
        *   \brief The function for displaying by category
        *   To do this, we prompts the user for the wanted category
        *             we traverse the file and display all ocurrances task which have wanted catergory
        */
        /// The string used for insert the wanted category
        char category[20];

        printf("\n Enter the category : ");
        scanf("%s", category);

        printf("\n     Tasks displayed depending on the category: \n");
        ///We open the file used for storage(read mode)
        FILE *tasksfile =fopen("tasksfile.txt","r" );

        /// We traverse the file while the entry isn't the end of file
        while ( fscanf(tasksfile, "\n%d %[^\t]   %s   %d", &tasks.no, tasks.task,tasks.category,&tasks.priority ) != EOF )
                if((strcmp(category, tasks.category)) == 0)
                        printf("\n%d\t%s\t%s\t%d",tasks.no, tasks.task, tasks.category, tasks.priority);

        ///We close the files used for storage
        fclose(tasksfile);

}

void sort_by_priority(){
        /**
        *   \brief The function for sorting by priority
        *   To do this, we traverse the file and display all tasks which have priority equal to 1
        *             after this we rewind the file and make same thing but for priority equal to 2 and 3.
        */

        printf("\n     Tasks displayed after sorting :\n");
        ///We open the file used for storage(read mode)
        tasksfile =fopen("tasksfile.txt","r" );

        while ( fscanf(tasksfile, "\n%d %[^\t]   %s   %d", &tasks.no, tasks.task, tasks.category,&tasks.priority ) != EOF )
                if ( tasks.priority == 1)
                        ///We display the task with priority equal to 1
                        printf("\n%d\t%s\t%s\t%d",tasks.no, tasks.task, tasks.category, tasks.priority);

        ///We rewind the file
        rewind(tasksfile);

        while ( fscanf(tasksfile, "\n%d %[^\t]   %s   %d", &tasks.no, tasks.task, tasks.category,&tasks.priority ) != EOF )
                if ( tasks.priority == 2)
                        ///We display the task with priority equal to 2
                        printf("\n%d\t%s\t%s\t%d",tasks.no, tasks.task, tasks.category, tasks.priority);

        ///We rewind the file again
        rewind(tasksfile);

        while ( fscanf(tasksfile, "\n%d %[^\t]   %s   %d", &tasks.no, tasks.task, tasks.category,&tasks.priority ) != EOF )
                if ( tasks.priority == 3)
                        ///We display the task with priority equal to 3
                        printf("\n\n%d\t%s\t%s\t%d", tasks.no, tasks.task, tasks.category, tasks.priority);

        ///We close the files used for storage
        fclose(tasksfile);

}


// R  A  N  D  O  M        F  U  N  C  T  I  O  N  S

char *randomtask(size_t length) {
         ///\brief The function for generating random text

        /// We intialize a string with alphabet letters
        static char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        /// In this string we create the random text
        char *randomString = NULL;
        /// A iterator for every letter of the random text
        int iterator;
        /// Variable used for a random number
        int key;
        if (length != 0) {
                ///We alloc space for random text
                randomString = malloc(sizeof(char) * (length +1));
                if (randomString) {
                        for (iterator= 0; iterator < length; iterator++) {
                                key = rand() % (int)(sizeof(charset) -1);
                                /// We copy in the randomstring at every position a random letter from charset
                                randomString[iterator] = charset[key];
                        }
                        randomString[length] = '\0';
                }
        }
        /// We return the random text
        return randomString;
}


void random_task(){
        ///\brief The function for generating random task
        tasks.no = rand() % 1000;

        strcpy(tasks.task , randomtask(20) );

        strcpy(tasks.category, randomtask(5));

        tasks.priority = rand() % 3;

        ///We open the file used for storage(append mode)
        tasksfile =fopen("tasksfile.txt","a+" );
        ///We store the random task in taskfile
        fprintf(tasksfile,"\n%d\t%s\t%s\t%d", tasks.no, tasks.task, tasks.category, tasks.priority);
        ///We close the files used for storage
        fclose(tasksfile);

}
