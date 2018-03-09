#include "../header/Neuron.h"



//CTOR

Neuron::Neuron(double val)
{
  this->val = val;

  activate();
  derive();
}
