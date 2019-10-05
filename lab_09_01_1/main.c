#include <stdio.h>
#include <stdlib.h>
#include "calculating_matrix.h"
#include "resizing_matrix.h"
#include "user_interface.h"

int main()
{
    matrix a_m;
    matrix b_m;
    matrix m_m;
    int pheta = 0;
    int gamma = 0;

    if (read_matrix(&a_m) != OK)
        return ERROR;
    if (read_matrix(&b_m) != OK)
    {
        free(a_m.p);
        return ERROR;
    }
        

    if (normalize_matrix(&a_m) != OK)
    {
        free(a_m.p);
        free(b_m.p);
        return ERROR;
    }
    if (normalize_matrix(&b_m) != OK)
    {
        free(a_m.p);
        free(b_m.p);
        return ERROR;
    }
    
    equate_matrix(&a_m, &b_m);

    m_m.m = a_m.m;
    m_m.n = a_m.n;
    
    if (create_matrix(&m_m) != OK)
    {
        free(a_m.p);
        free(b_m.p);
        free(m_m.p);
        return ERROR;
    }

    if (read_exp(&pheta, &gamma) != OK)
    {
        free(a_m.p);
        free(b_m.p);
        free(m_m.p);
        return ERROR;
    }
    
    if (expo_matrix(&a_m, pheta) != OK)
    {
        free(a_m.p);
        free(b_m.p);
        free(m_m.p);
        return ERROR;
    }
    
    if (expo_matrix(&b_m, gamma) != OK)
    {
        free(a_m.p);
        free(b_m.p);
        free(m_m.p);
        return ERROR;
    }

    multiply_matrix(a_m, b_m, &m_m);
    print_matrix(m_m);

    free(a_m.p);
    free(b_m.p);
    free(m_m.p);
    return 0;
}
