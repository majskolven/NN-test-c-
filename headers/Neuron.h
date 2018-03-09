#ifndef NEURON_H
#define NEURON_H

#include <iostream>
#include <math.h>

using namespace std;


class Neuron
{

public:
  Neuron(double val);


  //using fast sigmoid
  double activate();

  //derivative for fast sigmoid
  double derive();


  //getter
  double getVal();
  double getActivatedVal();
  double getDerivedVal();

private:

  double val;

  double activatedVal;

  double derivedVal;
};






#endif
