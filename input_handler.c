/**
 * @file input_handler.c
 * @brief This file contains the function definitions for input handling.
 *
 * The file includes the necessary standard libraries and defines the function definitions for input handling.
 * The function isWholeNumber checks if the input is a whole number.
 * The function isFloatingNumber checks if the input is a floating point number.
 * The function clear_console clears the console screen and prompts the user to press any key to continue.
 *
 * @author Viet Ha Nguyen
 * @date 4/15/2024
 */

/*******************************************************************************
 * INCLUDE
 ******************************************************************************/
#include "input_handler.h"		/* Include header file of this function file */

/*******************************************************************************
 * Code
 ******************************************************************************/
/**
 * @brief Checks if the input is a whole number.
 *
 * This function checks if the input is a whole number.
 * It returns 1 if the input is a whole number, 0 otherwise.
 *
 * @param input The input to be checked.
 * @return 1 if the input is a whole number, 0 otherwise.
 */
int32_t isWholeNumber(int8_t input[])
{
    int32_t is_valid_input = 1;				/* Initialize is_valid_input to 1 */
    int32_t i = 0;						/* Declare variable to index each element of input string */

    /* Check if the first character is '+' or '-' */
    if (input[0] == '+' || input[0] == '-')
    {
        i = 1;
    }
    else
    {
        /* Do nothing */
    }

    while (input[i] != '\0')
    {
        /* If the current character is not a digit, set is_valid_input to 0 */
        if (!isdigit(input[i]))
        {
            is_valid_input = 0;
        }
        /* Increment i */
        i++;
    }
    /* Return the value of is_valid_input */
    return is_valid_input;
}

/**
 * @brief Checks if the input is a floating point number.
 *
 * This function checks if the input is a floating point number.
 * It returns 1 if the input is a floating point number, 0 otherwise.
 *
 * @param input The input to be checked.
 * @return 1 if the input is a floating point number, 0 otherwise.
 */
int32_t isFloatingNumber(int8_t input[])
{
    int32_t is_valid_input = 1;		    /* Initialize is_valid_input to 1 */
    int32_t i = 0;						/* Declare variable to index each element of input string */
    int16_t count_point_character = 0;  /* Declare variable to count number of '.' character of input */

    /* Check if the first character is '+' or '-' */
    if (input[0] == '+' || input[0] == '-')
    {
        /* Start index at second character */
        i = 1;
    }
    /* Check if the first character is '.' */
    else if (input[0] == '.')
    {
        is_valid_input = 0;
    }
    else
    {
        /* Do nothing */
    }

    while (input[i] != '\0')
    {
        /* If the current character is not a digit */
        if (!isdigit(input[i]))
        {
            /* If the current character is not a '.' character */
            if (input[i] != '.')
            {
                /* Set is_valid_input = 0 */
                is_valid_input = 0;
            }
            /* If the current character is a '.' character */
            if (input[i] == '.')
            {
                /* Increment count_point_character  */
                count_point_character += 1;
            }
            else
            {
                /* Do nothing */
            }
        }
        /* Increment i */
        i++;
    }
    /* If input has more than 1 '.' character */
    if (count_point_character > 1)
    {
        is_valid_input = 0;
    }
    /* Return the value of is_valid_input */
    return is_valid_input;
}

/**
 * @brief Clears the console screen.
 *
 * This function prompting the user to press any key to continue.
 * It then clears the input buffer, waits for a key press, and clears the console screen.
 */
void clearConsole(void)
{
    printf("\n-------------------------------");
    printf("\nPress ANY key to Continue . . .");
    fflush(stdin);
    getch();
    system("cls");
} /* EOF */

