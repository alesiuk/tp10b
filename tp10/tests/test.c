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
BOOLEAN * bitSet (char port, int data);		//Setea (pone en 1) un bit de un puerto determinado
BOOLEAN * bitClear (char port, int data);		//Limpia (pone en 0) un bit de un puerto determinado
BOOLEAN * bitToggle (char port, int data);	//Conmuta el valor de un bit de un puerto determinado
int * bitGet (char port, int data);			//Obtiene el valor de un bit. Devuelve dicho valor si no hubo errores, o -1 si hubo un error
BOOLEAN * maskOn (char port, int data);		//Enciende todos los bits de un puerto segun los bits seteados de una mascara
BOOLEAN * maskOff (char port, int data);		//Apaga todos los bits de un puerto segun los bits seteados de una mascara
BOOLEAN * maskToggle (char port, int data);	//Conmuta todos los bits de un puerto segun los bits seteados de una mascara

/*VARIABLES*/
int testpass, testfail, testpassglo, testfailglo; //creo estas varibles que son las quevan a contabilizar la cantidad de test que pasaron o fallaron 
                                                  //las distintas funciones y el total de las pruebas.
int main(int argc, char** argv) {
    printf("%%SUITE_STARTING%% test\n");
    printf("%%SUITE_STARTED%%\n");
    
    /*testbitset (0x2,FALSE, 'b', 1);     //
    testbitset(0x2,TRUE,'b',12);
    testbitset(0x4,TRUE,'f',2);
    testbitset(0x8000,FALSE,'d',15);
    testbitset(0x8000,TRUE,'A', 16);*/
    printf("%%TEST_STARTED%%  testbitSet  (test)\n");
    p.portD.W = 0;
    testbit(FALSE,0x2, bitSet, 'b',1);
    testbit(TRUE,0x2,bitSet,'b',12);
    testbit(TRUE,0x4,bitSet,'f',2);
    p.portD.W = 0;
    testbit(FALSE,0x8000,'d',15);
    testbit(TRUE,0x8000,'A',16);
    
    printf("%%TEST_STARTED%%  testbitClr  (test)\n");
    p.portD.W = 0xFFFF;
    testbit(FALSE,0xFFFE,bitClear,'D',0);
    testbit(TRUE,0xFFFE,bitClear,'d',17);
    testbit(TRUE,0xFFFE,bitClear,'F',0);
    testbit(TRUE,0xE,bitClear,'a',-1);
    testbit(FALSE,0x7FFE,'A',7);
    
    printf("%%TEST_STARTED%%  testbitGet  (test)\n");
    testbit(FALSE,0,bitGet,'a',7);
    testbit(TRUE,0,bitGet,'d',-1);
    testbit(FALSE,1,bitGet,'d',3);
    testbit(TRUE,1,bitGet,'b',8);
    testbit(TRUE,1,bitGet,'j',0);
    
    printf("%%TEST_STARTED%%  testbitGet  (test)\n");
    
    
#ifdef ENABLE_DDR
    DDR.portD = 0x8888;
    testbit(FALSE,0x1,bitSet,'b',0);
    testbit(TRUE,0x8,bitSet,'b',7);    
#endif
    
    
  
    
    printf("%%TEST_FINISHED%% time=0 testPort_operations  (test)\n");

    printf("%%SUITE_FINISHED%% time=0\n");

    return (EXIT_SUCCESS);
}
void testbit (int esperado,int esp , int (* pf)(char prt,int dat), char puerto,int data)
{
    

    static n;
    static int testpass; 
    static int testfail;
    int valid;
    n++;
    valid = *pf(puerto, data);
    
    if (esperado == valid)
    {
        testpass++;
          
    }
    else
    {
        testfail++;
       
        printf("%%TEST_FAILED%% time=0 testname=testbit %d (test) message=esperado %d, actual %d\n",n, esperado, p.portD.W);
    }
     printf("%%TEST_FINISHED%% time=0 testbitSet testpass= %d  testfail = %d(test)\n", testpass, testfail);
    
      if (esp == p.portD.W)
    {
        testpass++;
        testpassglo++;   
    }
    else
    {
        testfail++;
        testfailglo++;
        printf("%%TEST_FAILED%% time=0 testname=testbit %d (test) message=esperado %d, actual %d\n",n, esperado, p.portD.W);
    }
     printf("%%TEST_FINISHED%% time=0 testbit testpass= %d  testfail = %d(test)\n", testpass, testfail);
    
}



/*void testbitset (int esperado,int espvalid, char puerto, int data)
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
   
    if (esperado == p.portD.W)
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
    if (esperado == p.portD.W)
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
}*/
/*void testmaskOn (int esperado, char puerto, int data)
{
    printf("%%TEST_STARTED%%  testmaskOn (test)\n");
    static n;
    static int testpass; 
    static int testfail;
    int valid;
    n++;  
    valid = maskOn (puerto, data);
    if (esperado == valid)
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
    int valid;
    n++;  
    valid = maskOff (puerto, data);
    if (esperado == valid)
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

void testmasktoggle (int esperado, char puerto, int mask)
{
 static n;
 static int testpass;
 static int testfail;
 int valid;
 n++;
 
 valid = maskToggle(puerto, mask);
 
 if (esperado = valid)
    {
        testpass++;
        testpassglo++;
    }
    else
    {
        testfail++;
        testfailglo++;
        printf("%%TEST_FAILED%% time=0 testname=testmaskToggle %d (test) message=esperado %d, actual %d\n",n, esperado, p.portD.W);  
    }
    printf("%%TEST_FINISHED%% time=0 testmaskToggle testpass= %d  testfail = %d(test)\n", testpass, testfail);


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

    
}*/
