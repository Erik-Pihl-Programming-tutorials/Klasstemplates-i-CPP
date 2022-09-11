/********************************************************************************
* vec.hpp: Implementering av dynamiska vektorer via klassen vec.
********************************************************************************/
#ifndef VEC_HPP_
#define VEC_HPP_

/* Inkluderingsdirektiv: */
#include <iostream>
#include <cstdlib>

/********************************************************************************
* vec: Generisk klass för implementering av dynamiska vektorer av valfri datatyp.
********************************************************************************/
template<class T>
class vec
{
private:
   T* data = nullptr;    /* Pekare till ett dynamiskt fält innehållande lagrad data. */
   std::size_t size = 0; /* Vektorns storlek, dvs. antalet lagrade element. */
public:

   /*****************************************************************************
   * vec: Tom konstruktor, initierar en ny tom vektor. 
   *****************************************************************************/
   vec(void) { }

   /*****************************************************************************
   * vec: Konstruktor, initierar ny vektor av angiven storlek med angivet
   *      startvärde.
   * 
   *      - start_size: Vektorns nya storlek (antalet element).
   *      - start_val : Referens till startvärde för alla element (default = 0).
   *****************************************************************************/
   vec(const std::size_t start_size,
       const T& start_val = static_cast<T>(0))
   {
      this->resize(start_size, start_val);
      return;
   }

   /*****************************************************************************
   * ~vec: Destruktor, frigör minne allokerat för vektorn innan objekt raderas.
   *****************************************************************************/
   ~vec(void) 
   {
      this->clear();
      return;
   } 

   /*****************************************************************************
   * get: Returnerar en pekare till innehållet lagrat i angiven array.
   *****************************************************************************/
   T* get(void) const
   {
      return this->data;
   }

   /*****************************************************************************
   * len: Returnerar längden (antalet element) i angiven vektor.
   *****************************************************************************/
   std::size_t len(void) const 
   { 
      return this->size; 
   }

   /*****************************************************************************
   * begin: Returnerar adressen till det första elementet i angiven vektor.
   *****************************************************************************/
   T* begin(void) const
   {
      return this->data;
   }

   /*****************************************************************************
   * end: Returnerar adressen direkt efter det sista elementet i angiven vektor.
   *****************************************************************************/
   T* end(void) const
   {
      return this->data + this->size;
   }

   /*****************************************************************************
   * last: Returnerar adressen till det sista elementet i angiven vektor.
   *****************************************************************************/
   T* last(void) const
   {
      return this->data ? this->end() - 1 : nullptr;
   }

   /*****************************************************************************
   * clear: Tömmer angiven vektor.
   *****************************************************************************/
   void clear(void)
   {
      std::free(this->data);
      this->data = nullptr;
      this->size = 0;
      return;
   }

   /*****************************************************************************
   * resize: Ändrar storlek på angiven vektor med angivet startvärde, där
   *         startvärdet är satt till 0 som default. Ifall vektorns storlek
   *         lyckas ändras till önskad storlek returneras 0, annars felkod 1.
   * 
   *         - new_size : Vektorns nya storlek (antalet element).
   *         - start_val: Referens till startvärde för respektive element 
   *                      (default = 0).
   *****************************************************************************/
   int resize(const std::size_t new_size,
              const T& start_val = static_cast<T>(0))
   {
      if (!new_size)
      {
         this->clear();
         return 0;
      }

      auto copy = (T*)std::realloc(this->data, sizeof(T) * new_size);
      if (!copy) return 1;
      this->data = copy;
      this->size = new_size;

      for (auto& i : *this)
      {
         i = start_val;
      }

      return 0;
   }

   /*****************************************************************************
   * push: Lägger till ett nytt element längst bak i angiven vektor. Ifall
   *       minnesallokeringen lyckas så returneras 0, annars felkod 1.
   * 
   *       - new_element: Referens till det nya element som skall läggas till.
   *****************************************************************************/
   int push(const T& new_element)
   {
      auto copy = (T*)std::realloc(this->data, sizeof(T) * (this->size + 1));
      if (!copy) return 1;
      copy[this->size++] = new_element;
      this->data = copy;
      return 0;
   }

   /*****************************************************************************
   * pop: Tar bort det sista elementet i angiven vektor om ett sådant finns.
   *      Om högst ett element finns lagrat i vektor så töms den helt.
   *****************************************************************************/
   void pop(void)
   {
      if (this->size <= 1)
      {
         this->clear();
      }
      else
      {
         auto copy = (T*)std::realloc(this->data, sizeof(T) * (this->size - 1));
         if (!copy) return;
         this->data = copy;
         this->size--;
      }

      return;
   }

   /*****************************************************************************
   * assign: Fyller vektor med heltal från angivet startvärde och inkrementerar
   *         varje element med angivet stegvärde. Som default används startvärde
   *         0 och stegvärde 1.
   *
   *        - start_val: Startvärde för första elementet (default = 0).
   *        - step_val : Stegvärde (defeault = 1).
   *****************************************************************************/
   void assign(const T& start_val = static_cast<T>(0),
               const T& step_val = static_cast<T>(1))
   {
      auto num = start_val;

      for (auto& i : *this)
      {
         i = num;
         num += step_val;
      }

      return;
   }

   /*****************************************************************************
   * print: Skriver ut innehållet lagrat i angiven vektor via angiven utström,
   *        där standardutenheten std::cout används som default för utskrift
   *        i terminalen.
   * 
   *        - ostream: Referens till angiven utström (default = std::cout).
   *****************************************************************************/
   void print(std::ostream& ostream = std::cout) const
   {
      if (!this->size) return;
      ostream << "--------------------------------------------------------------------------------\n";

      for (auto& i : *this)
      {
         ostream << i << "\n";
      }

      ostream << "--------------------------------------------------------------------------------\n\n";
      return;
   }
};

#endif /* VEC_HPP_ */