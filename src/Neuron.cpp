#include "../headers/Neuron.h"



//CTOR

Neuron::Neuron(double value)
{
  this->setValue(value);
}

double Neuron::activate()
{
  return this->value / (1 + abs(this->value));
}

double Neuron::derive()
{
  return this->activatedValue * (1 - this->activatedValue);
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
