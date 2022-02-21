#ifndef MY_LIBRARY_H
#define MY_LIBRARY_H
 
#include <Arduino.h>
 
class My_library
{
public:
   My_library(void);
   void  function_1();
   void  function_2();
   void  function_3();
 
private:
   int variable;
};
 
#endif