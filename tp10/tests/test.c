/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   test.c
 * Author: alito
 *
 * Created on May 23, 2020, 9:26 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "ports.h"
#include "definitions.h"

/*
 * Simple C Test Suite
 */
/*PROTOTIPOS DE FUNCIONES*/
void testglobal (int esperado, char port, int data); //esta funcion 
/*VARIABLES*/
int testpass, testfail, testpassglo, testfailglo; //creo estas varibles que son las quevan a contabilizar la cantidad de test que pasaron o fallaron 
                                                  //las distintas funciones y el total de las pruebas.
int main(int argc, char** argv) {
    printf("%%SUITE_STARTING%% test\n");
    printf("%%SUITE_STARTED%%\n");

    printf("%%TEST_STARTED%%  testPort_operations (test)\n");
    testPort_operations();
    printf("%%TEST_FINISHED%% time=0 testPort_operations  (test)\n");

    printf("%%SUITE_FINISHED%% time=0\n");

    return (EXIT_SUCCESS);
}


void testis_valid_ (int espuert,int espbit, char port, int data)
{
    printf("%%TEST_STARTED%%  testis_valid_port (test)\n");
    
    int validpo, validbi;
    static n;
    static int testpass; 
    static int testfail;
    
    n++;
    validpo = is_valid_port(port, data);
    validbi =is_valid_bit(port, data);
    
    if (validpo == espuert && validbi == espbit)
    {
        testpass++;
        testpassglo++;
        
    }
    else 
    {
        testfail++;
        testfailglo++;
        printf("%%TEST_FAILED%% time=0 testname=testis_valid_ %d (test) message=esperado %d, actual %d\n", esperado, valid);
        
    }
    printf("%%TEST_FINISHED%% time=0 testis_valid_ testpass= %d  testfail = %d(test)\n", testpass, testfail);

    
}


void testbiset (int esperado, char puerto, int data)
{
    printf("%%TEST_STARTED%%  testbitset (test)\n");
    static n;
    static int testpass; 
    static int testfail;
    n++
    bitset(puerto, data);
    if (esperado == p.portD.W)
    {
        testpass++;
        testpassglo++;   
    }
    else
    {
        testfail++;
        testfailglo++;
         printf("%%TEST_FAILED%% time=0 testname=testbitset %d (test) message=esperado %d, actual %d\n",n, esperado, p.portD.W);
    }
     printf("%%TEST_FINISHED%% time=0 testbitset testpass= %d  testfail = %d(test)\n", testpass, testfail);
}