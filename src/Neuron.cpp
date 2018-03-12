#include "../headers/Neuron.h"



//CTOR
Neuron::Neuron(double value)
{
  this->setValue(value);
}

Neuron::Neuron(double value, ActivationType type)
{
  this->type = type;
  this->setValue(value);
}

double Neuron::activate()
{
  double returnValue;
  switch(this->type){
    case TANH:
      returnValue = tanh(this->value);
    case RELU:
      if(this->value > 0)
        returnValue = this->getValue();
      else
        return 0;
    case SIGMOID:
      returnValue = 1 / (1 + exp(-this->value));
    default:
        returnValue = this->value / (1 + abs(this->value)); //Defaulting to "fast" sigmoid
  }

  return returnValue;
}

double Neuron::derive()
{
  double returnValue;
  switch(this->type){
    case TANH:
      returnValue = 1.0 - pow(this->activatedValue, 2);
    case RELU:
      if(this->value > 0)
        returnValue = 1;
      else
        returnValue = 0;
    case SIGMOID:
      returnValue = this->activatedValue * (1 - this->activatedValue);
    default:
        returnValue = this->activatedValue * (1 - this->activatedValue);
  }

  return returnValue;
}

double Neuron::getValue()
{
  return this->value;
}

double Neuron::getActivatedValue()
{
  return this->activatedValue;
}

double Neuron::getDerivedValue()
{
  return this->derivedValue;
}

void Neuron::setValue(double value)
{
  this->value = value;
  this->activatedValue = activate();
  this->derivedValue = derive();
}
