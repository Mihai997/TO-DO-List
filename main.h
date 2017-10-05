///\file main.h
///\brief C TO-DO LIST
/// Created by Birsan Maria Cristina
/**
*Implements function for: displaying all tasks, creating a task, deleting a task,
*                         deleting or modifying the catergory, and sort tasks,
*                         and also for generating random tasks
*/


#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

struct to_do_list;
void create_task();
void print_tasks();
void delete_task();
void delete_category();
void modify_category();
void display_by_category();
void sort_by_priority();
char *randomtask( length);
void random_task();

#endif // FUNCTIONS_H_INCLUDED
