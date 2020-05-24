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


void test_is_valid_ (int espuert,int espbit, int espmask, char port, int data)
{
    printf("%%TEST_STARTED%%  testis_valid_port (test)\n");
    
    int validpo, validbi,validmk;
    static n;
    static int testpass; 
    static int testfail;
    
    n++;
    validpo = is_a_valid_port(port, data);
    validbi = is_a_valid_bit(port, data);
    validmk = is_a_valid_mask(port,data);
    
    if (validpo == espuert && validbi == espbit && validmk  == espmask)
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


void testbitSet (int esperado, char puerto, int data)
{
    printf("%%TEST_STARTED%%  testbitSet (test)\n");
    static n;
    static int testpass; 
    static int testfail;
    n++;
    bitSet(puerto, data);
    if (esperado == p.portD.W)
    {
        testpass++;
        testpassglo++;   
    }
    else
    {
        testfail++;
        testfailglo++;
         printf("%%TEST_FAILED%% time=0 testname=testbitSet %d (test) message=esperado %d, actual %d\n",n, esperado, p.portD.W);
    }
     printf("%%TEST_FINISHED%% time=0 testbitSet testpass= %d  testfail = %d(test)\n", testpass, testfail);
}
void testbitClear (int esperado, char puerto, int data)
{
    printf("%%TEST_STARTED%%  testbitClear (test)\n");
    static n;
    static int testpass; 
    static int testfail;
    n++;  
    bitClear (puerto, data);
    if (esperado = p.portD.W)
    {
        testpass++;
        testpassglo++;
    }
    else
    {
        testfail++;
        testfailglo++;
        printf("%%TEST_FAILED%% time=0 testname=testbitClear %d (test) message=esperado %d, actual %d\n",n, esperado, p.portD.W);  
    }
    printf("%%TEST_FINISHED%% time=0 testbitClear testpass= %d  testfail = %d(test)\n", testpass, testfail);
}

void testbitToggle (int esperado, char puerto, int data)
{
    printf("%%TEST_STARTED%%  testbitToggle (test)\n");
    static n;
    static int testpass; 
    static int testfail;
    n++;  
    bitToggle (puerto, data);
    if (esperado = p.portD.W)
    {
        testpass++;
        testpassglo++;
    }
    else
    {
        testfail++;
        testfailglo++;
        printf("%%TEST_FAILED%% time=0 testname=testbitToggle %d (test) message=esperado %d, actual %d\n",n, esperado, p.portD.W);  
    }
    printf("%%TEST_FINISHED%% time=0 testbitToggle testpass= %d  testfail = %d(test)\n", testpass, testfail);
}
void testmaskOn (int esperado, char puerto, int data)
{
    printf("%%TEST_STARTED%%  testmaskOn (test)\n");
    static n;
    static int testpass; 
    static int testfail;
    n++;  
    bitmaskOn (puerto, data);
    if (esperado = p.portD.W)
    {
        testpass++;
        testpassglo++;
    }
    else
    {
        testfail++;
        testfailglo++;
        printf("%%TEST_FAILED%% time=0 testname=testmaskOn %d (test) message=esperado %d, actual %d\n",n, esperado, p.portD.W);  
    }
    printf("%%TEST_FINISHED%% time=0 testmaskOn testpass= %d  testfail = %d(test)\n", testpass, testfail);
}
void testmaskOff (int esperado, char puerto, int data)
{
    printf("%%TEST_STARTED%%  testmaskOff (test)\n");
    static n;
    static int testpass; 
    static int testfail;
    n++;  
    bitmaskOn (puerto, data);
    if (esperado = p.portD.W)
    {
        testpass++;
        testpassglo++;
    }
    else
    {
        testfail++;
        testfailglo++;
        printf("%%TEST_FAILED%% time=0 testname=testmaskOff %d (test) message=esperado %d, actual %d\n",n, esperado, p.portD.W);  
    }
    printf("%%TEST_FINISHED%% time=0 testmaskOff testpass= %d  testfail = %d(test)\n", testpass, testfail);
}