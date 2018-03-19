#include "../headers/Neuron.h"



//CTOR
Neuron::Neuron(double value, bool isBias)
{
  this->isBias = isBias;
  if(this->isBias)
    this->setValue(1.00);
  else
    this->setValue(value);
}

Neuron::Neuron(double value, utils::ActivationType type, bool isBias)
{
  this->type = type;
  this->isBias = isBias;
  if(this->isBias)
    this->setValue(1.00);
  else
    this->setValue(value);
}

double Neuron::activate()
{
  double returnValue;
  switch(this->type){
    case utils::TANH:
      returnValue = tanh(this->value);
    case utils::RELU:
      if(this->value > 0)
        returnValue = this->getValue();
      else
        return 0;
    case utils::SIGMOID:
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
    case utils::TANH:
      returnValue = 1.0 - pow(this->activatedValue, 2);
    case utils::RELU:
      if(this->value > 0)
        returnValue = 1;
      else
        returnValue = 0;
    case utils::SIGMOID:
      returnValue = this->activatedValue * (1 - this->activatedValue);
    default:
        returnValue = this->activatedValue * (1 - this->activatedValue);
  }

  return returnValue;
}

bool Neuron::getIsBias()
{
  return this->isBias;
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
  if(!this->isBias){
    this->activatedValue = activate();
    this->derivedValue = derive();
  }
}
