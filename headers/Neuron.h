#ifndef _NEURON_HPP_
#define _NEURON_HPP_

#include <iostream>

using namespace std;


Class Neuron
{
Public:
  Neuron(double val);


  //using fast sigmoid
  void activate();

  //derivative for fast sigmoid
  void derive()


  //getter
  double getVal();
  double getActivatedVal();
  double getDerivedVal();

Private:

  double val;

  double activatedVal;

  double derivedVal;
};






#endif
