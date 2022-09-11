/********************************************************************************
* main.cpp: Demostration av klasstemplates i C++ via en egenskapad generisk
*           vektorklass d�pt vec.
********************************************************************************/
#include "vec.hpp"

/********************************************************************************
* main: Deklarerar en vektor v1 som rymmer 20 heltal. Denna vektor tilldelas
*       20 heltal 0 - 19, vilket skrivs ut i terminalen. D�refter deklareras
*       en vektor som rymmer 30 heltal. Denna vektor fylls med heltal fr�n 0
*       och dekrementeras i steg om 0.5. Inneh�llet skrivs ut i terminalen.
********************************************************************************/
int main(void)
{
   vec<int> v1(20);
   v1.assign();
   v1.print();

   vec<double> v2(30);
   v2.assign(0, -0.5);
   v2.print();
   
   return 0;
}

