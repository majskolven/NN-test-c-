#include "../headers/Layer.h"


Layer::Layer(int size)
{
  this->size = size;
  for(int i=0; i < this->size; i++)
  {
    this->layer.push_back(new Neuron(0.0));
  }
}

int Layer::getSize()
{
  return this->size;
}


Layer::~Layer()
{
  while (!this->layer.empty())
  {
    Neuron *n = this->layer.back();
    delete n;
    this->layer.pop_back();
  }

}
