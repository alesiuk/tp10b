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
    
    testbitset (0x2,FALSE, 'b', 1);     //
    testbitset(0x2,TRUE,'b',12);
    testbitset(0x4,TRUE,'f',2);
    testbitset(0x8000,FALSE,'d',15);
    testbitset(0x8000,TRUE,'A', 16);
    
    
  
    testPort_operations();
    printf("%%TEST_FINISHED%% time=0 testPort_operations  (test)\n");

    printf("%%SUITE_FINISHED%% time=0\n");

    return (EXIT_SUCCESS);
}




void testbitset (int esperado,int espvalid, char puerto, int data)
{
    
    printf("%%TEST_STARTED%%  testbitSet (test)\n");
    int valid;
    static n;
    static int testpass; 
    static int testfail;
   
    p.portD.W = 0;
   
    n++;
    valid = bitSet(puerto, data);
    test_is_valid_(espvalid, valid);
    
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
void testbitClear (int esperado,int espvalid, char puerto, int data)
{
    printf("%%TEST_STARTED%%  testbitClear (test)\n");
    int valid;
    static n;
    static int testpass; 
    static int testfail;
    n++;  
    
    valid = bitClear (puerto, data);
    test_is_valid_(espvalid, valid);
   
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

void test_is_valid_ (int esp,int actual)
{
    printf("%%TEST_STARTED%%  testis_valid_port (test)\n");
    
   
    static n;
    static int testpass; 
    static int testfail;
    
    n++;
   
    
    if (esp == actual)
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
