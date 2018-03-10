#ifndef NEURON_H
#define NEURON_H

#include <iostream>
#include <math.h>

using namespace std;


class Neuron
{

public:
  Neuron(double value);


  //using fast sigmoid
  double activate();

  //derivative for fast sigmoid
  double derive();

  //setter
  void setValue(double value);
  //getter
  double getValue();
  double getActivatedValue();
  double getDerivedValue();

private:

  double value;

  double activatedValue;

  double derivedValue;
};






#endif
