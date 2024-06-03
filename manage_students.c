/**
 * @file manage_students.c
 * @brief This file contains the function definitions for managing students' information by using linked list.
 *
 * The file includes the function definitions for managing students' information by using linked list.
 * The functions is_List_Exist, is_ID_Exist, and is_Name_Exist check if the list, ID, and name exist, respectively.
 * The function showStudentInfo displays the information of a student.
 *
 * @author Viet Ha Nguyen
 * @date 4/15/2024
 */
/*******************************************************************************
 * Include
 ******************************************************************************/
#include "manage_students.h"    /* Include header file of this function file */

/*******************************************************************************
 * Variables
 ******************************************************************************/
Student_t *head = NULL;      /* This variable is used to store the head of the linked list. */

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/**
 * @brief Displays the information of a student.
 *
 * This function displays the information of a student.
 * It takes a pointer to a student as an argument.
 *
 * @param student The pointer to the student whose information is to be displayed.
 */
static void showStudentInfo(Student_t *student);

/*******************************************************************************
 * Code
 ******************************************************************************/
/**
 * @brief Checks if the list exists.
 *
 * This function checks if the list exists.
 * It returns 1 if the list exists, 0 otherwise.
 *
 * @return 1 if the list exists, 0 otherwise.
 */
int32_t is_List_Exist(void)
{
    int32_t is_exist = 0;           /* Initialize is_exist to 0 */

    /* If head is NULL, set is_exist to 0 */
    if (head == NULL)
    {
        is_exist = 0;
    }
    /* If head is not NULL, set is_exist to 1 */
    else
    {
        is_exist = 1;
    }
    /* Return the value of is_exist */
    return is_exist;
}

/**
 * @brief Checks if the input ID exists.
 *
 * This function checks if the input ID exists.
 * It returns 1 if the ID exists, 0 otherwise.
 *
 * @param ID The ID to be checked.
 * @return 1 if the ID exists, 0 otherwise.
 */
int32_t is_ID_Exist(int8_t *ID)
{
    int32_t is_exist = 0;       /* Initialize is_exist to 0 */
    Student_t *temp = head;     /* Temporary pointer to traverse the list */

    /* Traverse the linked list */
    while (temp != NULL)
    {
        /* If the ID of temp is equal to the input ID */
        if (strcmp(temp->ID, ID) == 0)
        {
            /* Set is_exist to 1 */
            is_exist = 1;
        }
        else
        {
            /* Do nothing */
        }
        /* Move to the next node of linked list */
        temp = temp->next;
    }
    /* Return the value of is_exist */
    return is_exist;
}

/**
 * @brief Checks if the input name exists.
 *
 * This function checks if the input name exists.
 * It returns 1 if the name exists, 0 otherwise.
 *
 * @param name The name to be checked.
 * @return 1 if the name exists, 0 otherwise.
 */
int32_t is_Name_Exist(int8_t *name)
{
    int32_t is_exist = 0;       /* Initialize is_exist to 0 */
    Student_t *temp = head;     /* Temporary pointer to traverse the list */

    /* Traverse the linked list */
    while (temp != NULL)
    {
        /* If the name of temp is equal to the input name */
        if (strcmp(temp->name, name) == 0)
        {
            /* Set is_exist to 1 */
            is_exist = 1;
        }
        else
        {
            /* Do nothing */
        }
        /* Move to the next node of linked list */
        temp = temp->next;
    }
    /* Return the value of is_exist */
    return is_exist;
}

/**
 * @brief Checks if the input account exists.
 *
 * This function checks if the input account exists.
 * It returns 1 if the account exists, 0 otherwise.
 *
 * @param account The account to be checked.
 * @return 1 if the account exists, 0 otherwise.
 */
int32_t is_Account_Exist(int8_t *account)
{
    int32_t is_exist = 0;       /* Initialize is_exist to 0 */
    Student_t *temp = head;     /* Temporary pointer to traverse the list */

    /* Traverse the linked list */
    while (temp != NULL)
    {
        /* If the account of temp is equal to the input account */
        if (strcmp(temp->account, account) == 0)
        {
            /* Set is_exist to 1 */
            is_exist = 1;
        }
        else
        {
            /* Do nothing */
        }
        /* Move to the next node of linked list */
        temp = temp->next;
    }
    /* Return the value of is_exist */
    return is_exist;
}

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
Student_t *createStudentInfo(int8_t *ID, int8_t *name, int8_t *account, float average_score)
{
    Student_t *new_student = (Student_t *)malloc(sizeof(Student_t));  /* Allocate memory for the new_student */

    /* Copy the ID to the new_student */
    strcpy(new_student->ID, ID);
    /* Copy the name to the new_student */
    strcpy(new_student->name, name);
    /* Copy the account to the new_student */
    strcpy(new_student->account, account);
    /* Set the average score of the new_student */
    new_student->average_score = average_score;

    /* Set the next pointer of the new_student to NULL */
    new_student->next = NULL;

    /* Return a pointer to the new_student */
    return new_student;
}

/**
 * @brief Clears the list of students.
 *
 * This function checks if the head of the list is not NULL.
 * If it is not NULL, it prints a message to the console.
 * It then sets the head of the list to NULL.
 */
void clearList(void)
{
    /* If the head of the list is not NULL */
    if (head != NULL)
    {
        printf("\nDeleting previous list of students . . .\n\n");
        printf("You can re-create a new studnet list now . . .\n");
    }
    /* If the head of the list is NULL */
    else
    {
        printf("\nProceed to create a new student list . . .\n");
    }
    /* Set the head of the list to NULL */
    head = NULL;
}

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
void addStudentInfoToList(Student_t *student)
{
    /* If the head of the linked list is NULL */
    if (head == NULL)
    {
        /* Set the head to the new student */
        head = student;
    }
    /* If the head of the list is not NULL */
    else
    {
        Student_t *temp = head;             /* Temporary pointer to traverse the list */

        /* Traverse the list to find the last student */
        while (temp->next != NULL)
        {
            /* Move to the next student */
            temp = temp->next;
        }
        /* Set the next pointer of the last student to the new student */
        temp->next = student;
    }
}

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
void deleteStudentInfo(int8_t *ID)
{
    Student_t *temp = head;          /* Temporary pointer to traverse the list */
    Student_t *pre_temp = NULL;      /* Pointer before temp to adjust node connection of linked list */

    /* In case the node to be deleted is the first node */
    if (temp != NULL && (strcmp(temp->ID, ID) == 0))
    {
        /* Set the head to the next node */
        head = temp->next;
        /* Free the memory of the first node */
        free(temp);
    }
    else
    {
        /* Traverse the list to find the node to delete and the pointer before it */
        while ((temp != NULL) && (strcmp(temp->ID, ID) != 0))
        {
            /* Set pre_temp to temp */
            pre_temp = temp;
            /* Move to the next node */
            temp = temp->next;
        }
        /* Set the next pointer of the node before the node which to be deleted
           to the next node of the node which to be deleted */
        pre_temp->next = temp->next;
        /* Free the memory of the node which to be deleted */
        free(temp);
    }
}

/**
 * @brief Sorts the linked list by student's average score.
 *
 * This function sorts the linked list by student's average score in descending order.
 * It uses the bubble sort algorithm to compare the average scores of each student.
 * If the average score of the current student is less than the average score of the next student,
 * it swaps the average scores of the two students.
 */
void sortByScore(void)
{
    Student_t* current = head;       /* Initialize current variable to head of linked list */
    Student_t* next_current = NULL;  /* Initialize variable next_current to NULL */
    float temp = 0;                  /* Temporary variable to store student's average score used for swapping data */

    /* Traverse the linked list */
    while (current != NULL)
    {
        /* Set next_current to the next student */
        next_current = current->next;

        /* While next_current is not NULL */
        while (next_current != NULL)
        {
            /* If the average score of current is less than the average score of next_current */
            if (current->average_score < next_current->average_score)
            {
                /* Set temp to the average score of current student */
                temp = current->average_score;
                /* Set the average score of current student to the average score of next student */
                current->average_score = next_current->average_score;
                /* Set the average score of next student to temp */
                next_current->average_score = temp;
            }
            else
            {
                /* Do nothing */
            }
            /* Move to the next student */
            next_current = next_current->next;
        }
        /* Move to the next student */
        current = current->next;
    }
}

/**
 * @brief Sorts the linked list by student's name.
 *
 * This function sorts the list of students by their name in ascending order.
 * It uses the bubble sort algorithm to compare the names of each student.
 * If the name of the current student is greater than the name of the next student,
 * it swaps the names of the two students.
 */
void sortByName(void)
{
    Student_t* current = head;          /* Initialize current variable to head of linked list */
    Student_t* next_current = NULL;     /* Initialize next_current variable to NULL */
    int8_t temp[100];                   /* Temporary variable to store student's name used for swapping data */

    /* Traverse the linked list */
    while (current != NULL)
    {
        /* Set next_current to the next student */
        next_current = current->next;

        /* While next_current is not NULL */
        while (next_current != NULL)
        {
            /* If the name of current is more than the name of next_current */
            if (strcmp(current->name, next_current->name) > 0)
            {
                /* Copy the name of next student to temp */
                strcpy(temp, next_current->name);
                /* Copy the name of current student to the name of next student */
                strcpy(next_current->name, current->name);
                /* Copy the data of temp to the name of current student */
                strcpy(current->name, temp);
            }
            else
            {
                /* Do nothing */
            }
            /* Move to the next student */
            next_current = next_current->next;
        }
        /* Move to the next student */
        current = current->next;
    }
}

/**
 * @brief Searching for an student's information by their ID.
 *
 * This function searches for a student's information by their ID.
 * If the ID of the current student is equal to the input ID,
 * it displays the information of the student.
 *
 * @param ID The ID of the student to be searched.
 */
void searchInfoByID(int8_t *ID)
{
    Student_t* temp = head;        /* Temporary pointer to traverse the list */

    /* Traverse the linked list */
    while (temp != NULL)
    {
        /* If the ID of temp is equal to the input ID */
        if (strcmp(temp->ID, ID) == 0)
        {
            /* Display the information of the student */
            showStudentInfo(temp);
        }
        else
        {
            /* Do nothing */
        }
        /* Move to the next student */
        temp = temp->next;
    }
}

/**
 * @brief Searching for an student's information by their name.
 *
 * This function searches for an student's information by their name.
 * If the name of the current student is equal to the input name,
 * it displays the information of the student.
 *
 * @param name The name of the student to be searched.
 */
void searchInfoByName(int8_t *name)
{
    Student_t* temp = head;        /* Temporary pointer to traverse the list */

    /* Traverse the linked list */
    while (temp != NULL)
    {
        /* If the name of temp is equal to the input name */
        if (strcmp(temp->name, name) == 0)
        {
            /* Display the information of the student */
            showStudentInfo(temp);
        }
        else
        {
            /* Do nothing */
        }
        /* Move to the next student */
        temp = temp->next;
    }
}

/**
 * @brief Searching for an student's information by their account.
 *
 * This function searches for an student's information by their account.
 * If the account of the current student is equal to the input account,
 * it displays the information of the student.
 *
 * @param account The account of the student to be searched.
 */
void searchInfoByAcc(int8_t *account)
{
    Student_t* temp = head;        /* Temporary pointer to traverse the list */

    /* Traverse the linked list */
    while (temp != NULL)
    {
        /* If the account of temp is equal to the input account */
        if (strcmp(temp->account, account) == 0)
        {
            /* Display the information of the student */
            showStudentInfo(temp);
        }
        else
        {
            /* Do nothing */
        }
        /* Move to the next student */
        temp = temp->next;
    }
}

/**
 * @brief Displays the information of a student.
 *
 * This function displays the information of a student.
 * It takes a pointer to a student as an argument.
 *
 * @param student The pointer to the student whose information is to be displayed.
 */
static void showStudentInfo(Student_t *student)
{
    printf("\n-----\n");
    printf("ID: %s\n", student->ID);
    printf("Name: %s\n", student->name);
    printf("Account: %s\n", student->account);
    printf("Average score: %.2f\n", student->average_score);
    printf("-----\n");
}

/**
 * @brief Displays the list of students.
 *
 * This function displays the list of students that includes student's ID, student's name,
 * student's account and student's average score.
 * It traverses the linked list and calls the showStudentInfo function for each student (node).
 */
void showListStudents(void)
{
    Student_t *student = head;
    while (student != NULL)
    {
        showStudentInfo(student);
        student = student->next;
    }
} /* EOF */

