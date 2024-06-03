/**
 * @file input_handler.h
 * @brief This file contains the function prototypes for input handling.
 *
 * The file includes the necessary standard libraries and defines the function prototypes for input handling.
 * The function isWholeNumber checks if the input is a whole number.
 * The function clear_console clears the console screen and prompts the user to press any key to continue.
 *
 * @author Viet Ha Nguyen
 * @date 4/15/2024
 */

/*******************************************************************************
 * INCLUDE
 ******************************************************************************/
#include <stdio.h>          /* Include standard input and output library for printf, scanf, ... */
#include <stdlib.h>         /* For system("cls") function. */
#include <ctype.h>          /* For isdigit() function. */
#include <stdint.h>         /* Include standard integer types library for fixed-width integers like int8_t, uint64_t, etc. */
#include <conio.h>          /* For getch() function. */

/*******************************************************************************
 * Header guards
 ******************************************************************************/
#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

/*******************************************************************************
 * Prototype
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
int32_t isWholeNumber(int8_t input[]);

/**
 * @brief Checks if the input is a floating point number.
 *
 * This function checks if the input is a floating point number.
 * It returns 1 if the input is a floating point number, 0 otherwise.
 *
 * @param input The input to be checked.
 * @return 1 if the input is a floating point number, 0 otherwise.
 */
int32_t isFloatingNumber(int8_t input[]);

/**
 * @brief Clears the console screen.
 *
 * This function prompting the user to press any key to continue.
 * It then clears the input buffer, waits for a key press, and clears the console screen.
 */
void clearConsole(void);

#endif /* INPUT_HANDLER_H */

