#include "../headers/Layer.h"


Layer::Layer(int size)
{
  this->size = size;
  for(int i=0; i < this->size; i++)
  {
    layer.push_back(new Neuron(0.0));
  }
}
