/**
 * @file main.c
 * @brief This file contains the main function of the program.
 *
 * This file contains the main function of the program manage students' information using linked list.
 * It includes the necessary header files, initializes the variables, and provides the user with a menu
 * to interact with the program.
 * The program allows the user to manage a list of students in a class, including initializing the list,
 * adding and deleting students' information, sorting the list, and searching for student information.
 *
 * @author Viet Ha Nguyen
 * @date 15/4/2024
 */

/*******************************************************************************
 * Include
 ******************************************************************************/
#include <stdio.h>           /* Include standard input and output library for printf, scanf, ... */
#include <stdint.h>          /* Include standard integer types library for fixed-width integers like int8_t, uint64_t, etc. */
#include "manage_students.h" /* Include header file for managing students' information by using linked list */
#include "input_handler.h"   /* Include input handler header file for handling user input */

/*******************************************************************************
 * Code
 ******************************************************************************/
/**
 * @brief The main function of the program.
 *
 * This function is the main function of the program. It initializes the variables and provides
 * the user with a menu to interact with the program.
 * The program allows the user to manage a list of students in a class, including initializing the list,
 * adding and deleting students' information, sorting the list, and searching for student information.
 *
 * @return 0 if the program runs successfully.
 */
int main(void)
{
    int32_t choice = 0;          /* Initialize variable to store user choice */
    int32_t num_students = 0;    /* Initialize variable to store the number of students */
    int32_t i = 0;               /* Initialize temporary variable */
    int32_t is_valid_input = 1;  /* Initialize variable as a flag to check if input valid */
    int8_t buffer[100];          /* Declare buffer to store input temporarily */

    int8_t ID[30];               /* Declare character array to store student's ID */
    int8_t name[100];            /* Declare character array to store student's name */
    int8_t account[30];          /* Declare character array to store student's account */
    float average_score = 0;     /* Initialize variable to store student's average score */

    do
    {
        /* Reset the choice variable to 0 */
        choice = 0;

        /* Show the menu of program for user choosing */
        printf("\n");
        printf("*--------------------- PROGRAM TO MANAGE LIST OF STUDENTS IN CLASS ------------------*\n");
        printf("|                                                                                    |\n");
        printf("| 1. Initialize list of students                                                     |\n");
        printf("| 2. Add an new student's information to list                                        |\n");
        printf("| 3. Delete an student's information from list by their ID                           |\n");
        printf("| 4. Sort the list by either student's average score or student's name               |\n");
        printf("| 5. Search information of student by either their ID or their name or their account |\n");
        printf("| 6. Display list of students                                                        |\n");
        printf("| 7. Exit program                                                                    |\n");
        printf("|____________________________________________________________________________________|\n");
        printf("\n");

        /* Ask user enter their choice */
        printf("Please select your desired function: ");
        /* Clear buffer */
        fflush(stdin);
        /* Read user's choice */
        scanf("%d", &choice);

        /* Switch statement for user choice */
        switch (choice)
        {
            case 1:
            {
                /* Clear the list of students */
                clearList();

                /* Ask the user to enter the number of students */
                printf("\nEnter the number of students: ");
                fflush(stdin);
                scanf("%d", &num_students);

                /* Loop through the number of students */
                for (i = 0; i < num_students; i++)
                {
                    /* Ask the user to enter the information of each student */
                    printf("\n-----\n");
                    printf("Enter information of student %d:\n\n", i + 1);

                    /* Do while loop to check if the input ID is valid */
                    do
                    {
                        is_valid_input = 1;

                        /* Ask the user to enter the student's ID */
                        printf("ID: ");
                        fflush(stdin);
                        scanf(" %[^\n]s", ID);

                        /* If the ID already exists in the list */
                        if (is_ID_Exist(ID))
                        {
                            /* Set the validity of the input to 0 */
                            is_valid_input = 0;
                            /* Ask the user to re-enter another ID */
                            printf("\nID already exists. Please re-enter another ID!!!\n\n");
                        }
                        else
                        {
                            /* Do nothing */
                        }
                    } /* Continue the loop until the input ID is valid */
                    while (!is_valid_input);

                    /* Ask the user to enter the student's name */
                    printf("Name: ");
                    fflush(stdin);
                    scanf(" %[^\n]s", name);

                    /* Do while loop to check if the input account is valid */
                    do
                    {
                        is_valid_input = 1;

                        /* Ask the user to enter the account */
                        printf("Account: ");
                        fflush(stdin);
                        scanf(" %[^\n]s", account);

                        /* If the account already exists in the list */
                        if (is_Account_Exist(account))
                        {
                            /* Set the validity of the input to 0 */
                            is_valid_input = 0;
                            /* Ask the user to re-enter another account */
                            printf("\nAccount already exists. Please re-enter another account!!!\n\n");
                        }
                        else
                        {
                            /* Do nothing */
                        }
                    } /* Continue the loop until the input account is valid */
                    while (!is_valid_input);

                    /* Do while loop to check if the input average score is valid */
                    do
                    {
                        is_valid_input = 1;

                        /* Ask the user to enter the average score */
                        printf("Average score (0 <= score <= 10): ");
                        fflush(stdin);
                        scanf("%s", buffer);

                        /* If the input is not a floating number */
                        if (!isFloatingNumber(buffer))
                        {
                            /* Set the validity of the input to 0 */
                            is_valid_input = 0;
                            /* Display an error message and asking user re-enter the average score */
                            printf("\nYour input is not valid.\n");
                            printf("Please re-enter a floating-point number!!!\n\n");
                        }
                        /* If the input is a floating number */
                        else
                        {
                            /* Convert the input from string to a floating number by using atof function */
                            average_score = atof(buffer);
                            /* If the average score is less than 0 */
                            if (average_score < (float)0)
                            {
                                /* Set the validity of the input to 0 */
                                is_valid_input = 0;
                                /* Ask the user to re-enter the average score */
                                printf("\nScore must not less than 0. Please enter again\n\n");
                            }
                            /* If the average score is more than 10 */
                            else if (average_score > (float)10)
                            {
                                /* Set the validity of the input to 0 */
                                is_valid_input = 0;
                                /* Ask the user to re-enter the average score */
                                printf("\nScore must not more than 10. Please enter again\n\n");
                            }
                            /* If the average score is between 0 and 10 */
                            else
                            {
                                /* Do nothing */
                            }
                        }
                    } /* Continue the loop until the input average score is valid */
                    while (!is_valid_input);

                    /* Create a new student object (new node) with the input information */
                    Student_t *student = createStudentInfo(ID, name, account, average_score);
                    /* Add the new student to the list */
                    addStudentInfoToList(student);
                }
                /* Display a message that the list of students is initialized */
                printf("\n--> List of students is initialized . . .\n");
                /* Clear the console */
                clearConsole();
                /* Break the switch statement */
                break;
            }
            case 2:
            {
                /* If the list of students does not exist */
                if(!is_List_Exist())
                {
                    /* If the list does not exist, inform the user */
                    printf("\nYou have not initialized list of students, please initialize it first!!!\n\n");
                }
                /* If the list of students exists */
                else
                {
                    printf("\nEnter information of this student: \n");

                    /* Do while loop to check if the input ID is valid */
                    do
                    {
                        is_valid_input = 1;

                        /* Ask user input the ID */
                        printf("ID: ");
                        fflush(stdin);
                        scanf(" %[^\n]s", ID);

                        /* If the ID already exists in the list */
                        if (is_ID_Exist(ID))
                        {
                            /* Set the validity of the input to 0 and display an error message */
                            is_valid_input = 0;
                            printf("\nID already exists. Please re-enter another ID!!!\n\n");
                        }
                        else
                        {
                            /* Do nothing */
                        }
                    } /* Continue the loop until the input ID is valid */
                    while (!is_valid_input);

                    /* Ask the user to enter the student's name */
                    printf("Name: ");
                    fflush(stdin);
                    scanf(" %[^\n]s", name);

                    /* Do while loop to check if the input account is valid */
                    do
                    {
                        is_valid_input = 1;

                        /* Ask the user to enter the account */
                        printf("Account: ");
                        fflush(stdin);
                        scanf(" %[^\n]s", account);

                        /* If the account already exists in the list */
                        if (is_Account_Exist(account))
                        {
                            /* Set the validity of the input to 0 and display an error message */
                            is_valid_input = 0;
                            printf("\nAccount already exists. Please re-enter another account!!!\n\n");
                        }
                        else
                        {
                            /* Do nothing */
                        }
                    } /* Continue the loop until the input account is valid */
                    while (!is_valid_input);

                    /* Do while loop to check if the input average score is valid */
                    do
                    {
                        is_valid_input = 1;

                        /* Ask the user to enter the average score */
                        printf("Average score (score >= 0): ");
                        fflush(stdin);
                        scanf("%s", buffer);

                        /* If the input is not a floating number */
                        if (!isFloatingNumber(buffer))
                        {
                            /* Set the validity of the input to 0 */
                            is_valid_input = 0;
                            /* Display an error message and ask user re-enter a floating number */
                            printf("\nYour input is not valid.\n");
                            printf("Please re-enter a floating-point number!!!\n\n");
                        }
                        /* If the input is a floating number */
                        else
                        {
                            /* Convert the input from string to a floating number by using atof function */
                            average_score = atof(buffer);
                            /* If the average score is less than 0 */
                            if (average_score < (float)0)
                            {
                                /* Set the validity of the input to 0 */
                                is_valid_input = 0;
                                /* Ask the user to re-enter the average score */
                                printf("\nScore must not less than 0. Please enter again\n\n");
                            }
                            /* If the average score is more than 10 */
                            else if (average_score > (float)10)
                            {
                                /* Set the validity of the input to 0 */
                                is_valid_input = 0;
                                /* Ask the user to re-enter the average score */
                                printf("\nScore must not more than 10. Please enter again\n\n");
                            }
                            /* If the average score is between 0 and 10 */
                            else
                            {
                                /* Do nothing */
                            }
                        }
                    } /* Continue the loop until the input average score is valid */
                    while (!is_valid_input);

                    /* Create a new student object (new node) with the input information */
                    Student_t *new_student = createStudentInfo(ID, name, account, average_score);
                    /* Add new student to the list */
                    addStudentInfoToList(new_student);
                    /* Print an message to indicate that new student is added to list */
                    printf("\n--> Added an new student's information to list . . .\n");
                }
                /* Clear the console */
                clearConsole();
                /* Break switch statement */
                break;
            }
            case 3:
            {
                /* If the list of students does not exist */
                if (!is_List_Exist())
                {
                    /* If the list does not exist, inform the user */
                    printf("\nYou have not initialized list of students, please initialize it first!!!\n\n");
                }
                else
                {
                    /* Ask the user to enter the ID of the student to be deleted */
                    printf("\nEnter student's ID that you want delete: ");
                    fflush(stdin);
                    scanf(" %[^\n]s", ID);

                    /* Check if the ID exists in the list */
                    if (!is_ID_Exist(ID))
                    {
                        printf("\nID '%s' is not on the list!!!\n", ID);
                    }
                    else
                    {
                        /* Delete the student information with the given ID */
                        deleteStudentInfo(ID);
                        printf("\n--> Deleted student's information with ID '%s' from the list . . .\n", ID);
                    }
                }
                /* Clear the console */
                clearConsole();
                /* Break switch statement */
                break;
            }
            case 4:
            {
                /* If the list of students does not exist */
                if(!is_List_Exist())
                {
                    /* If the list does not exist, inform the user */
                    printf("\nYou have not initialized list of students, please initialize it first!!!\n\n");
                }
                else
                {
                    /* If the list exists, show menu for the user to choose a sort option */
                    printf("\n");
                    printf("---* Input '1' to sort the list by student's average score in descending order *---\n");
                    printf("---* Input '2' to sort the list by student's name in ascending order           *---\n\n");

                    /* Do while loop to check if choice is valid */
                    do
                    {
                        /* Reset choice to 0 */
                        choice = 0;

                        /* Ask user enter their option */
                        printf("Enter your option: ");
                        fflush(stdin);
                        scanf("%d", &choice);

                        /* Switch statement for user choice */
                        switch (choice)
                        {
                            case 1:
                            {
                                printf("\nSorting your list by student's average score in descending . . .\n");
                                /* Sort the list by the students' average score in descending order */
                                sortByScore();
                                printf("\n--> The list is successfully sorted!!!\n");
                                /* Break switch statement */
                                break;
                            }
                            case 2:
                            {
                                printf("\nSorting your list by student's name in ascending . . .\n");
                                /* Sort the list by the students' name in ascending order */
                                sortByName();
                                printf("\n--> The list is successfully sorted!!!\n");
                                /* Break switch statement */
                                break;
                            }
                            /* If user enter a invalid choice, then ask them re-enter their choice */
                            default:
                            {
                                printf("\nYour input is not valid!!!\n\n");
                                printf("Please enter again . . .\n");
                            }
                        }
                    } /* Continue the loop until the input choice is valid */
                    while (!(choice == 1 || choice == 2));
                }
                /* Clear the console */
                clearConsole();
                /* Break switch statement */
                break;
            }
            case 5:
            {
                /* Check if the list of students exists */
                if(!is_List_Exist())
                {
                    /* If the list does not exist, inform the user */
                    printf("\nYou have not initialized list of students, please initialize it first!!!\n\n");
                }
                else
                {
                    /* If the list exists, show the menu for the user to choose a search option */
                    printf("\n");
                    printf("---* Input '1' to search students's information by their's ID      *---\n");
                    printf("---* Input '2' to search students's information by their's name    *---\n");
                    printf("---* Input '3' to search students's information by their's account *---\n\n");

                    /* Do while loop to check if choice is valid */
                    do
                    {
                        /* Reset choice to 0 */
                        choice = 0;

                        /* Ask user to enter their option */
                        printf("Enter your option: ");
                        fflush(stdin);
                        scanf("%d", &choice);

                        /* Switch statement for user choice */
                        switch (choice)
                        {
                            case 1:
                            {
                                /* If the user chooses to search by ID, prompt them to enter the ID */
                                printf("\nEnter student's ID that you want to search information: ");
                                fflush(stdin);
                                scanf(" %[^\n]s", ID);

                                /* Check if the ID exists in the list */
                                if (!is_ID_Exist(ID))
                                {
                                    printf("\nID '%s' is not on the list!!!\n", ID);
                                }
                                else
                                {
                                    /* If the ID exists, display the information of the student with that ID */
                                    printf("\n--> Information of student having ID '%s': \n", ID);
                                    searchInfoByID(ID);
                                }
                                /* Break switch statement */
                                break;
                            }
                            case 2:
                            {
                                /* If the user chooses to search by name, prompt them to enter the name */
                                printf("\nEnter student's name that you want to search information: ");
                                fflush(stdin);
                                scanf(" %[^\n]s", name);

                                /* Check if the name exists in the list */
                                if (!is_Name_Exist(name))
                                {
                                    printf("\nStudent's name '%s' is not on the list!!!\n", name);
                                }
                                else
                                {
                                    /* If the name exists, display the information of the student(s) with that name */
                                    printf("\n--> Information of student(s) having name '%s': \n", name);
                                    searchInfoByName(name);
                                }
                                /* Break switch statement */
                                break;
                            }
                            case 3:
                            {
                                /* If the user chooses to search by account, prompt them to enter the account */
                                printf("\nEnter student's account that you want to search information: ");
                                fflush(stdin);
                                scanf(" %[^\n]s", account);

                                /* Check if the account exists in the list */
                                if (!is_Account_Exist(account))
                                {
                                    printf("\nAccount '%s' is not on the list!!!\n", account);
                                }
                                else
                                {
                                    /* If the account exists, display the information of the student with that account */
                                    printf("\n--> Information of student having account '%s': \n", account);
                                    searchInfoByAcc(account);
                                }
                                /* Break switch statement */
                                break;
                            }
                            /* If user enter a invalid choice, then ask them re-enter their choice */
                            default:
                            {
                                printf("\nYour input is not valid!!!\n\n");
                                printf("Please enter again . . .\n");
                            }
                        }
                    } /* Continue the loop until the input choice is valid */
                    while (!(choice == 1 || choice == 2 || choice == 3));
                }
                /* Clear the console */
                clearConsole();
                /* Break switch statement */
                break;
            }
            case 6:
            {
                /* Check if the list of students exists */
                if(!is_List_Exist())
                {
                    /* If the list does not exist, inform the user */
                    printf("\nYou have not initialized list of students, please initialize it first!!!\n\n");
                }
                else
                {
                    /* If the list exists, display the list of students */
                    printf("\nLIST OF STUDENTS IN CLASS: \n");
                    showListStudents();
                }
                /* Clear the console */
                clearConsole();
                /* Break the switch statement */
                break;
            }
            case 7:
            {
                /* Print a message indicating the program has exited */
                printf("\n--- EXITED PROGRAM ---\n");
                printf("\nSEE YOU AGAIN . . .\n");
                /* Break the switch statement */
                break;
            }
            /* If the user's input is not valid */
            default:
            {
                /* Print a message indicating input is not valid, ask user re-enter theri choice */
                printf("\nYour input is not valid!!!\n\n");
                printf("Please enter again . . .\n");
                /* Clear the console */
                clearConsole();
            }
        }
    } /* Keep the program running until the user chooses to exit program */
    while (choice != 7);
    /* Return 0 to indicate successful program execution */
    return 0;
} /* EOF */

