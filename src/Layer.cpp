#include "../headers/Layer.h"


Layer::Layer(int size)
{
  this->size = size;
  for(int i=0; i < this->size; i++)
  {
    this->layer.push_back(new Neuron(0.0));
  }
}

void Layer::setValues(int index, double value)
{
  this->layer.at(index)->setValue(value);
}

Neuron* Layer::getNeuron(int index)
{
  return this->layer.at(index);
}

int Layer::getSize()
{
  return this->size;
}

Matrice* Layer::convertToMatrice(ValueType type)
{
  Matrice *result = new Matrice(1, this->layer.size(), false);
  for(unsigned int i = 0; i<this->layer.size(); i++)
  {
    switch(type){
      case ACTIVATED:
        result->setSpecificValue(0, i, this->layer.at(i)->getActivatedValue());
      case DERIVED:
        result->setSpecificValue(0, i, this->layer.at(i)->getDerivedValue());
      case NORMAL:
        result->setSpecificValue(0, i, this->layer.at(i)->getValue());
    }
  }
  return result;
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
