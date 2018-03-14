#ifndef NEURON_H
#define NEURON_H

#include <iostream>
#include <math.h>
#include "./utils/utils.h"


using namespace std;
using namespace utils;

class Neuron
{

public:
  Neuron(double value);
  Neuron(double value, utils::ActivationType type);


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
  utils::ActivationType type;
  double value;
  double activatedValue;
  double derivedValue;
};



#endif
