/**
 * @file manage_students.h
 * @brief This file contains the function prototypes and data structures for managing students' information
 *
 * This file contains the function prototypes and data structures for managing students' information by
 * using linked list.
 *
 * @author Viet Ha Nguyen
 * @date 4/15/2024
 */

/*******************************************************************************
 * Include
 ******************************************************************************/
#include <stdio.h>   /* Include standard input and output library for printf, scanf, ... */
#include <stdint.h>  /* Include standard integer types library for fixed-width integers like int8_t, uint64_t, etc. */
#include <stdlib.h>  /* For malloc(), free() functions*/
#include <string.h>  /* For strcpy(), strcmp() functions*/

/*******************************************************************************
 * Header guards
 ******************************************************************************/
#ifndef MANAGE_STUDENTS_H
#define MANAGE_STUDENTS_H

/*******************************************************************************
 * Declarations
 ******************************************************************************/
/**
 * @struct Student
 * @brief This structure represents a student.
 *
 * This structure represents a student. Each students of the list of students consider as
 * each node of the linked list.
 * It contains the ID, name, account, average score of the student and
 * a pointer to the next student in the list.
 */
typedef struct Student
{
    int8_t ID[30];          /* The ID of the student */
    int8_t name[100];       /* The name of the student */
    int8_t account[30];     /* The account of the student */
    float average_score;    /* The average score of the student */
    struct Student *next;   /* Pointer to the next student in the list */
} Student_t;

/*******************************************************************************
 * Prototype
 ******************************************************************************/
/**
 * @brief Checks if the list exists.
 *
 * This function checks if the list exists.
 * It returns 1 if the list exists, 0 otherwise.
 *
 * @return 1 if the list exists, 0 otherwise.
 */
int32_t is_List_Exist(void);

/**
 * @brief Checks if the input ID exists.
 *
 * This function checks if the input ID exists.
 * It returns 1 if the ID exists, 0 otherwise.
 *
 * @param ID The ID to be checked.
 * @return 1 if the ID exists, 0 otherwise.
 */
int32_t is_ID_Exist(int8_t *ID);

/**
 * @brief Checks if the input name exists.
 *
 * This function checks if the input name exists.
 * It returns 1 if the name exists, 0 otherwise.
 *
 * @param name The name to be checked.
 * @return 1 if the name exists, 0 otherwise.
 */
int32_t is_Name_Exist(int8_t *name);

/**
 * @brief Checks if the input account exists.
 *
 * This function checks if the input account exists.
 * It returns 1 if the account exists, 0 otherwise.
 *
 * @param account The account to be checked.
 * @return 1 if the account exists, 0 otherwise.
 */
int32_t is_Account_Exist(int8_t *account);

/**
 * @brief Creates a new student information (create new node of linked list).
 *
 * This function creates a new student information.
 * It returns a pointer to the new student (new node).
 *
 * @param ID The ID of the student.
 * @param name The name of the student.
 * @param account The account of the student.
 * @param average_score The average score of the student.
 * @return A pointer to the new student (new node).
 */
Student_t *createStudentInfo(int8_t *ID, int8_t *name, int8_t *account, float average_score);

/**
 * @brief Clears the list of students.
 *
 * This function checks if the head of the list is not NULL.
 * If it is not NULL, it prints a message to the console.
 * It then sets the head of the list to NULL.
 */
void clearList(void);

/**
 * @brief Adds a new student to the list (add a new node to linked list).
 *
 * This function adds a new student to the list.
 * If the head of the list is NULL, it sets the head to the new student.
 * If the head of the list is not NULL, it traverses the list to find the last student and sets
 * the next pointer of the last student to the new student.
 *
 * @param student The new student to be added to the list.
 */
void addStudentInfoToList(Student_t *student);

/**
 * @brief Deletes a student from the list.
 *
 * This function deletes a student from the list.
 * It takes the ID of the student to be deleted as an argument.
 * If the node to be deleted is the first node, it sets the head to the next node and
 * frees the memory of the first node.
 * If the node to be deleted is not the first node, it traverses the list to find the node
 * to delete and the pointer before it.
 * It then sets the next pointer of the node before the node to be deleted to the next node of the node
 * to be deleted and frees the memory of the node to be deleted.
 *
 * @param ID The ID of the student to be deleted.
 */
void deleteStudentInfo(int8_t *ID);

/**
 * @brief Sorts the linked list by student's average score.
 *
 * This function sorts the linked list by student's average score in descending order.
 * It uses the bubble sort algorithm to compare the average scores of each student.
 * If the average score of the current student is less than the average score of the next student,
 * it swaps the average scores of the two students.
 */
void sortByScore(void);

/**
 * @brief Sorts the linked list by student's name.
 *
 * This function sorts the list of students by their name in ascending order.
 * It uses the bubble sort algorithm to compare the names of each student.
 * If the name of the current student is greater than the name of the next student,
 * it swaps the names of the two students.
 */
void sortByName(void);

/**
 * @brief Searching for an student's information by their ID.
 *
 * This function searches for a student's information by their ID.
 * If the ID of the current student is equal to the input ID,
 * it displays the information of the student.
 *
 * @param ID The ID of the student to be searched.
 */
void searchInfoByID(int8_t *ID);

/**
 * @brief Searching for an student's information by their name.
 *
 * This function searches for an student's information by their name.
 * If the name of the current student is equal to the input name,
 * it displays the information of the student.
 *
 * @param name The name of the student to be searched.
 */
void searchInfoByName(int8_t *name);

/**
 * @brief Searching for an student's information by their account.
 *
 * This function searches for an student's information by their account.
 * If the account of the current student is equal to the input account,
 * it displays the information of the student.
 *
 * @param account The account of the student to be searched.
 */
void searchInfoByAcc(int8_t *account);

/**
 * @brief Displays the list of students.
 *
 * This function displays the list of students that includes student's ID, student's name,
 * student's account and student's average score.
 * It traverses the linked list and calls the showStudentInfo function for each student (node).
 */
void showListStudents(void);

#endif /* MANAGE_STUDENTS_H */

