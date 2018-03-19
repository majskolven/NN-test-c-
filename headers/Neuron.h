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
  Neuron(double value, bool isBias);
  Neuron(double value, utils::ActivationType type, bool isBias);


  //using fast sigmoid
  double activate();

  //derivative for fast sigmoid
  double derive();

  //setter
  void setValue(double value);
  //getter
  bool getIsBias();
  double getValue();
  double getActivatedValue();
  double getDerivedValue();

private:
  utils::ActivationType type;

  bool isBias;
  double value;
  double activatedValue;
  double derivedValue;
};



#endif
