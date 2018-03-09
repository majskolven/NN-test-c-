#include "../headers/Neuron.h"



//CTOR

Neuron::Neuron(double val)
{
  this->val           = val;
  this->activatedVal  = this->activate();
  this->derivedVal    = this->derive();
}

double Neuron::activate()
{
  return this->val / (1 + abs(this->val));
}

double Neuron::derive()
{
  return this->activatedVal * (1 - this->activatedVal);
}

double Neuron::getVal()
{
  return this->val;
}

double Neuron::getActivatedVal()
{
  return this->activatedVal;
}

double Neuron::getDerivedVal()
{
  return this->derivedVal;
}
