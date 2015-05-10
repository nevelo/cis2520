/** CIS2520 Lab 1 fractions.h
 ** Author: Matt Saunders (0906453) **/

#ifndef __MSAUND05_FRACTIONSH
#define __MSAUND05_FRACTIONSH

#include <stdlib.h>

struct Fraction {
    int numer;
    int denom;
};

/* Creates a fraction from a numerator and denominator. Stores it in newly-
 * allocated memory. Returns NULL on failure, memory pointer on success. 
 * PRE: Requires a numerator and a denominator to be sent.
 * POST: Will always return either a pointer to a fraction, or NULL. If a
 *       zero is sent as a denominator, it will print an error to STDERR. */
struct Fraction *createFraction (int numer, int denom);

/* Destroys a fraction variable by deallocating its memory.
 * PRE: Must send it a pointer (or null).
 * POST: The memory pointed to by the sent pointer will no longer be accessible. */
void destroyFraction (struct Fraction *frac);

/* Returns the integer value of the numerator from the fraction.
 * PRE: Must be sent a valid fraction.
 * POST: Will return the numerator unless the fraction is NULL, in which case
 * it returns zero and prints an error to STDERR.*/
int getNumerator (struct Fraction *frac);

/* Returns the integer value of the denominator from the fraction.
 * PRE: Must be sent a valid fraction.
 * POST: Will return the denominator unless the fraction is NULL, in which case
 * it returns zero and prints an error to STDERR.*/
int getDenominator (struct Fraction *frac);

/* Adds two fractions. Returns a third, new fraction (with newly allocated
 * memory) containing the result. 
 * PRE: Must be sent two valid fractions.
 * POST: Will return the addition of the two fractions with a denominator made
 *       by multiplying the two denominators. (This may not be the lowest common
 *       denominator.)  Will return a NULL pointer if an invalid fraction is
 *       passed; either a NULL fraction or one with a denominator of zero.
 *       A call to createFraction is made internal to the function; the memory
 *       it allocates must be freed.  */
struct Fraction *addFraction (struct Fraction *one, struct Fraction *two);

/* Multiplies two fractions. Returns a third, new fraction (with newly
 * allocated memory) containing the result.
 * PRE: Must be sent two valid fractions.
 * POST: Will return the crude multiplication of the two fractions with a 
 *       denominator made by multiplying the two input denominators. (This may
 *       not be the lowest common denominator.)  Will return a NULL pointer if
 *       an invalid fraction is passed; either a NULL fraction or one with a
 *       denominator of zero. A call to createFraction is made internal to the
 *       function; the memory it allocates must be freed.  */
struct Fraction *multiplyFraction (struct Fraction *one, struct Fraction *two);

#endif
