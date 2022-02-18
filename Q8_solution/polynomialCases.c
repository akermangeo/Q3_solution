#include "polynomials.h"
#include "polynomialCases.h"

/// <summary>
/// Evaluates the polynomial at the specified point x using Horner's method.
/// </summary>
/// <param name="p_poly">A pointer to the poltnomial to evaluate.</param>
/// <param name="x">Value at which to evaluate the polynomial.</param>
/// <returns>The result of the evaluation.</returns>
double evaluate(const struct polynomial* p_poly, double x);

void case_3(struct polynomial* p_poly_temp, const struct polynomial* p_poly_1, const struct polynomial* p_poly_2)
{
    struct polynomial* p_poly_temp2 = add(p_poly_1, p_poly_2);
    *p_poly_temp = *p_poly_temp2;
    printf("Sum = ");
    print_poly(p_poly_temp);
    free(p_poly_temp2);
}

void case_4(struct polynomial* p_poly_temp, const struct polynomial* p_poly_1, const struct polynomial* p_poly_2)
{
    printf("Which polynomial would you like to subract from the other?\n");
    printf("(1 - Subtract Polynomial 1 from 2, 2 - Subtract Polynomial 2 from 1)\n");
    int sub = 0;
    scanf_s("%d", &sub);

    struct polynomial* p_poly_temp2 = NULL;
    struct polynomial* p_poly_temp3 = NULL;

    struct polynomial p_poly_minus;
    p_poly_minus.coefficient = -1;
    p_poly_minus.exponent = 0;
    p_poly_minus.p_next = NULL;

    if (sub == 1)
    {
        p_poly_temp2 = multiply(p_poly_1, &p_poly_minus);
        p_poly_temp3 = add(p_poly_temp2, p_poly_2);
    }
    else if (sub == 2)
    {
        p_poly_temp2 = multiply(p_poly_2, &p_poly_minus);
        p_poly_temp3 = add(p_poly_1, p_poly_temp2);
    }
    else
    {
        printf("Invalid input.  Returning to options...");
        return;
    }

    *p_poly_temp = *p_poly_temp3;
    printf("Subtraction = ");
    print_poly(p_poly_temp);
    free_polynomial(p_poly_temp2);
    free(p_poly_temp3);
}

void case_5(struct polynomial* p_poly_temp, const struct polynomial* p_poly_1, const struct polynomial* p_poly_2)
{
    struct polynomial* p_poly_temp2 = multiply(p_poly_1, p_poly_2);
    *p_poly_temp = *p_poly_temp2;
    printf("Product = ");
    print_poly(p_poly_temp);
    free(p_poly_temp2);
}

void case_6(const struct polynomial* p_poly_1, const struct polynomial* p_poly_2)
{
    int poly_eval;
    printf("Which polynomial would you like to evaluate? (1/2) ");
    scanf_s("%d", &poly_eval);

    if (poly_eval != 1 && poly_eval != 2)
    {
        printf("Invalid polynomial index.  Returning to options...");
        return;
    }

    double val, result;
    printf("At what value would you like to evaluate polynomial %d? (input float) ", poly_eval);
    scanf_s("%lf", &val);

    if (poly_eval == 1)
    {
        result = evaluate(p_poly_1, val);
    }
    else if (poly_eval == 2)
    {
        result = evaluate(p_poly_2, val);
    }

    printf("Result = %f\n", result);
}

double evaluate(const struct polynomial* p_poly, double x)
{
    double value = 0;

    while (p_poly != NULL)
    {
        value += p_poly->coefficient;
        if (p_poly->exponent != 0)
        {
            value *= x;
        }
        p_poly = p_poly->p_next;
    }

    return value;
}