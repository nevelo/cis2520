/** CIS2520 Lab 1 fractions.c
 ** Author: Matt Saunders (0906453) **/

#include <stdio.h>
#include "fractions.h"

struct Fraction *createFraction (int numer, int denom)
{
    struct Fraction *frac;
    
    /* Zero cannot be a denominator. */
    if (denom == 0)
    {
        fprintf(stderr, "ERR: Divide by zero error.\n");
        return NULL;
    }
    
    /* No negative denominators. */
    if (denom < 0)
    {
        numer = numer * -1;
        denom = denom * -1; 
    }
    
    frac = malloc(sizeof(struct Fraction));
    if (frac == NULL)
        return NULL;
        
    frac->numer = numer;
    frac->denom = denom;
    
    return frac;
}

void destroyFraction (struct Fraction *frac)
{
    free(frac);
    return;
}

int getNumerator (struct Fraction *frac)
{
    if (frac != NULL)
        return frac->numer;
    
    fprintf(stderr, "ERR: Found null pointer... returning zero for numerator.\n");
    return 0;
}

int getDenominator (struct Fraction *frac)
{
    if (frac != NULL)
        return frac->denom;
    
    fprintf(stderr, "ERR: Found null pointer... returning zero for denominator.\n");
    return 0;
}

struct Fraction *addFraction (struct Fraction *one, struct Fraction *two)
{
    struct Fraction *result;
    int numer;
    int denom;
    
    if (one == NULL || two == NULL)
    {
        fprintf(stderr, "ERR: Cannot add a null fraction.\n");
        return NULL;
    }
    
    numer = ( one->numer * two->denom ) + ( two->numer * one->denom );
    denom = ( one->denom * two->denom );
    
    result = createFraction(numer, denom);
    
    return result;
}

struct Fraction *multiplyFraction (struct Fraction *one, struct Fraction *two)
{
    struct Fraction *result;
    int numer;
    int denom;
    
    if (one == NULL || two == NULL)
    {
        fprintf(stderr, "ERR: Cannot multiply a null fraction.\n");
        return NULL;
    }
    
    numer = one->numer * two->numer;
    denom = one->denom * two->denom;
    
    result = createFraction(numer, denom);
    
    return result;
}
