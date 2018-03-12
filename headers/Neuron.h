#ifndef NEURON_H
#define NEURON_H

#include <iostream>
#include <math.h>

using namespace std;

enum ActivationType{
  TANH,
  RELU,
  SIGMOID
};

class Neuron
{

public:
  Neuron(double value);
  Neuron(double value, ActivationType type);


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
  ActivationType type;
  double value;
  double activatedValue;
  double derivedValue;
};



#endif
