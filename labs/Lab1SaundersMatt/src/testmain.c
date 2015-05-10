/** CIS2520 Lab 1 testmain.c
 ** Author: Matt Saunders (0906453) **/

#include <stdio.h>
#include "fractions.h"

int main(void)
{
    /* Values to make fractions out of.  Will create some fractions with a
     * zero numerator, a zero denominator, and a zero in both places. */
    int num[10] = { 7, 1, 0, 3, 5, 30, 0, 3, 1, 3 };
    int denom[10] = { 12, 1, 7, 0, 7, 15, 0, 6, 3, 9 };
    int i;
    
    struct Fraction *frac[14];
    
    /* initialize fraction addresses */
    for (i = 0; i < 14; i++)
    {
        frac[i] = NULL;
    }
    
    printf("Testing suite for Fraction struct.\n\n");
    
    /* Testing the fraction creation. This determines if a valid block of memory
     * is returned by the createFraction function, and displays it for the programmer. */
    printf("Testing create fraction. Expecting valid memory...");
    
    frac[0] = createFraction(num[0], denom[0]);
    
    if (frac[0] == NULL)
        printf("failed.\n");
    
    else
        printf("returned memory address %lX (good)\n", (long unsigned int) frac[0]);
    
    /* Testing the getnumer and getdenom functions to see that they are returning the expected values. */
    printf("Fraction stored: %d/%d. Expected: %d/%d.\n", getNumerator(frac[0]), getDenominator(frac[0]), num[0], denom[0]);
    
    /* Some more quick tests of the fraction creation and display functions.
     * Testing cases where numerator is zero, denominator is zero, and both are zero.
     * Not shown: extremely large values -- gcc returns a warning:
     * "warning: overflow in implicit constant conversion" */
    printf("\nTesting other fractions...\n");
    for (i=1; i<10; i++)
    {
        printf("Testing %d/%d: ", num[i], denom[i]);
        frac[i] = createFraction(num[i], denom[i]);
        if (frac[i] == NULL)
            printf(" ... could not create.\n");
        
        else
            printf(" ... returned fraction %d/%d.\n", getNumerator(frac[i]), getDenominator(frac[i]));
    }
    
    /* Testing addition of fractions three ways: expected normal functionality,
     * known null fraction, and fraction with denominator of zero.  Though there
     * is no way to have a non-null zero denominator fraction using this library,
     * it's possible to create one by directly manipulating the data. */
    printf("\n\n Testing addition of fractions...\n");
    printf("1. Adding normal fractions.\n");
    printf("Adding %d/%d to %d/%d.\n", getNumerator(frac[0]), getDenominator(frac[0]), getNumerator(frac[4]), getDenominator(frac[4]));
    frac[10] = addFraction(frac[0], frac[4]);
    printf("Expecting 109/84... returned %d/%d.\n\n", getNumerator(frac[10]), getDenominator(frac[10]));
    
    printf("2. Adding known null fraction.\n");
    printf("Adding %d/%d to %d/%d.\n", getNumerator(frac[8]), getDenominator(frac[8]), getNumerator(frac[3]), getDenominator(frac[3]));
    frac[11] = addFraction(frac[8], frac[3]);
    printf("Expecting divide by zero error ( 0/0 )... returned %d/%d.\n\n", getNumerator(frac[11]), getDenominator(frac[11]));
    
    printf("3. Changing one fraction to denominator zero, then adding them.\n");
    frac[4]->denom = 0;
    printf("Adding %d/%d to %d/%d.\n", getNumerator(frac[0]), getDenominator(frac[0]), getNumerator(frac[4]), getDenominator(frac[4]));
    frac[12] = addFraction(frac[0], frac[4]);
    printf("Expecting divide by zero error ( 0/0 )... returned %d/%d.\n\n", getNumerator(frac[12]), getDenominator(frac[12]));
    
    /* Testing multiplication of fractions three ways: expected normal functionality,
     * known null fraction, and fraction with denominator zero.  Extremely large values
     * overflow and wrap around. */
    printf("\n\n Testing multiplication of fractions...\n");
    printf("1. Multiplying normal fractions.\n");
    printf("Multiplying %d/%d by %d/%d.\n", getNumerator(frac[0]), getDenominator(frac[0]), getNumerator(frac[0]), getDenominator(frac[0]));
    frac[10] = multiplyFraction(frac[0], frac[0]);
    printf("Expecting 49/144... returned %d/%d.\n\n", getNumerator(frac[10]), getDenominator(frac[10]));
    
    printf("2. Multiplying fraction with numerator zero.\n");
    printf("Multiplying %d/%d by %d/%d.\n", getNumerator(frac[0]), getDenominator(frac[0]), getNumerator(frac[2]), getDenominator(frac[2]));
    frac[11] = multiplyFraction(frac[0], frac[2]);
    printf("Expecting 0/84... returned %d/%d.\n\n", getNumerator(frac[11]), getDenominator(frac[11]));
    
    printf("3. Multiplying fraction with denominator zero.\n");
    printf("Multiplying %d/%d by %d/%d.\n", getNumerator(frac[0]), getDenominator(frac[0]), getNumerator(frac[4]), getDenominator(frac[4]));
    frac[12] = multiplyFraction(frac[0], frac[4]);
    printf("Expecting divide by zero error ( 0/0 )... returned %d/%d.\n\n", getNumerator(frac[12]), getDenominator(frac[12]));
    
    /* The destroyFraction function is a simple wrapper for the free() function.
     * Not particularly useful in this data structure because the Fraction struct
     * stores no pointers. It works as well as a call to free() would in its place.
     * Valgrind shows no memory leaks. */
    printf("Destroying fractions...\n");
    for (i=0; i<14; i++)
    {
        destroyFraction(frac[i]);
    }
    printf("Done.\n");

    return 0;
}
