#ifndef UTILS_H
#define UTILS_H
#include "../Matrice.h"

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <assert.h>



using namespace std;

namespace utils
{
  static const int MSE_COST = 1;


  enum ValueType
  {
     ACTIVATED,
     DERIVED,
     NORMAL
  };

  enum ActivationType{
    TANH,
    RELU,
    SIGMOID
  };


  class Helper
  {
  public:
    static void matriceMultiplier(Matrice *x, Matrice *y, Matrice *z)
    {
      for(unsigned int i = 0; i < x->getRowCount(); i++)
      {
        for(unsigned int j = 0; j < y->getColCount(); j++)
        {
          for(unsigned int k = 0; k < y->getRowCount(); k++)
          {
            double a = x->getSpecificValue(i,k) * y->getSpecificValue(k,j);
            double b = z->getSpecificValue(i,j) + a;
            z->setSpecificValue(i,j,b);

          }

          z->setSpecificValue(i,j,z->getSpecificValue(i,j));
        }
      }
    }
  };
}

#endif
