//add to include path   
//C:\Program Files (x86)\Intel\oneAPI\mkl\<installed version>\include\
//
//add to library path 
// C:\Program Files (x86)\Intel\oneAPI\mkl\<installed version>\lib\intel64\
// C:\Program Files (x86)\Intel\oneAPI\compiler\latest\windows\compiler\lib\intel64_win\
//
//add libraries
// "mkl_intel_lp64.lib" "mkl_intel_thread.lib" "mkl_core.lib" "libiomp5md.lib" 


#define min(x,y) (((x) < (y)) ? (x) : (y))
#include <intrin.h>
#include <stdio.h>
#include <stdlib.h>
#include "mkl.h"

void printMatrix(double* M, int m, int n)
{
    int i, j;
    for (i = 0; i < min(m, 6); i++) {
        for (j = 0; j < min(n, 6); j++) {
            printf("%12.5G", M[j + i * n]);
        }
        printf("\n");
    }
}

double compareMatrix(double* A, double* B, int m, int n)
{
    int i, j;
    double diff = 0.0f;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            double d;
            d = A[j + i * n] - B[j + i * n];
            if (d < 0) d = -d;
            if (d > diff) diff = d;
        }
    }
    return diff;
}

//task is to implement matrix multiplication
void reference_dgemm(double* A, double* B, double* C, int m, int n, int p)
{
//develop matrix multiplication here
//A = m*p matrix
//B = p*n matrix
//C = A*B matrix
}

int main()
{
    double *A, *B, *C, *D;
    int m, n, p, i, j;
    double alpha, beta;

    printf("\n This example computes real matrix C=A*B using Intel(R) MKL function dgemm");

    m = 1024, p = 1024, n = 1024;
    //m = 2, p = 3, n = 3;
    printf(" Initializing data for matrix multiplication C=A*B for matrix \n"
        " A(%ix%i) and matrix B(%ix%i)\n\n", m, p, p, n);
    
    //dgemm is  C = alpha * A*B + beta * C
    //but we assume alpha =1 beta=0 to get C=A*B 
    alpha = 1.0; beta = 0.0;
    //
    printf(" Allocating memory for matrices aligned on 64-byte boundary for better \n"
        " performance \n\n");
    A = (double *)mkl_malloc(m*p * sizeof(double), 64);
    B = (double *)mkl_malloc(p*n * sizeof(double), 64);
    C = (double *)mkl_malloc(m*n * sizeof(double), 64);
    D = (double *)mkl_malloc(m*n * sizeof(double), 64);
    if (A == NULL || B == NULL || C == NULL) {
        printf("\n ERROR: Can't allocate memory for matrices. Aborting... \n\n");
        mkl_free(A);
        mkl_free(B);
        mkl_free(C);
        return 1;
    }

    printf(" Intializing matrix data \n\n");
    for (i = 0; i < (m*p); i++) {
        A[i] = (double)(i + 1);
    }
    for (i = 0; i < (p*n); i++) {
        B[i] = (double)(-i - 1);
    }
    for (i = 0; i < (m*n); i++) {
        C[i] = 0.0;
    }
    for (i = 0; i < (m*n); i++) {
        D[i] = 0.0;
    }

    printf(" Computing matrix product using Intel(R) MKL dgemm function via CBLAS interface \n");
    cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,
        m, n, p, alpha, A, p, B, n, beta, C, n);
    printf("\n Computations completed.\n\n");

    printf(" Top left corner of matrix A: \n");
    printMatrix(A, m, n);

    printf("\n Top left corner of matrix B: \n");
    printMatrix(B, m, n);

    printf("\n Top left corner of matrix C: \n");
    printMatrix(C, m, n);

    printf(" \nComputing matrix product using reference dgemm function \n");

    reference_dgemm(A, B, D, m, n, p);

    printf(" Top left corner of matrix D: \n");
    printMatrix(D, m, n);

    printf(" Validate results \n");
    double diff = compareMatrix(C, D, m, n);
    if (diff > 0.1) {
        printf(" Test fail! diff=%f\n", diff);
    }
    else {
        printf(" Test Ok!\n");
    }
//bench
//disable this for debugging
    if (1)
    {
        double start, stop, perf_ref, perf_mkl;
        int nloops = 10;
        printf("Benchmarking reference\n");
        start = (double)__rdtsc();
        for (i = 0; i < nloops; i++) {
            reference_dgemm(A, B, D, m, n, p);
        }
        stop = (double)__rdtsc();
        perf_ref = (stop - start) / nloops;
        printf("Benchmarking  MKL\n");
        start = (double)__rdtsc();
        for (i = 0; i < nloops; i++) {
            cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, m, n, p, alpha, A, p, B, n, beta, C, n);
        }
        stop = (double)__rdtsc();
        perf_mkl = (stop - start) / nloops;
        printf("Time reference = %20.3f cycles\n", perf_ref);
        printf("Time       mkl = %20.3f cycles\n", perf_mkl);
        printf("Ratio ref/mkl  = %20.3fX\n", perf_ref / perf_mkl);
    }

    //printf("\n Deallocating memory \n\n");
    mkl_free(A);
    mkl_free(B);
    mkl_free(C);

    printf(" Completed. \n\n");
    return 0;
}