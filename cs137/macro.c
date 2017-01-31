/**
 * Macros
 * - Can use macros to simplify repeated text
 * eg. #define INT(x) (*(int *) (x))
 *
 * - Use brackets around macro arguments
 * eg. #define MULT(x, y) x * y
 * int z = MULT (3 + 2, 4 + 2) // z = 13 = 3 + 2 * 4 + 2
 * Therefore, we want to use () around the macro body!
 *
 * eg. #define INC (x) x + 1
 * int z = INC (5) * 2 = 7 = 5 + 1 * 2
 * eg. #define INC (x) (x + 1)
 * int z = INC (5) * 2 = 12 = (5 + 1) * 2
 */
