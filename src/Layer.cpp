#include "../headers/Layer.h"


Layer::Layer(int size)
{
  this->size = size + 1;
  for(int i=0; i < this->size-1; i++)
  {
    this->layer.push_back(new Neuron(0.0, false));
  }
  //Adding Bias Neuron
  this->layer.push_back(new Neuron(1.0, true));
}

Layer::Layer(int size, utils::ActivationType type)
{
  this->size = size + 1;
  for(int i=0; i < this->size-1; i++)
  {
    this->layer.push_back(new Neuron(0.0, type, false));
  }
  //Adding Bias Neuron
  this->layer.push_back(new Neuron(1.0, true));

}

void Layer::setNeuronValue(int index, double value)
{
  this->layer.at(index)->setValue(value);
}

vector<Neuron *> Layer::getLayer()
{
  return this->layer;
}

void Layer::setLayer(vector<Neuron *> layer)
{
  this->layer = layer;
}

Neuron* Layer::getNeuron(int index)
{
  return this->layer.at(index);
}

int Layer::getSize()
{
  return this->size;
}

Matrice* Layer::convertToMatrice(utils::ValueType type)
{
  Matrice *result = new Matrice(1, this->layer.size(), false);
  for(unsigned int i = 0; i < this->layer.size(); i++)
  {
    switch(type){
      case utils::ACTIVATED:
        result->setSpecificValue(0, i, this->layer.at(i)->getActivatedValue());
      case utils::DERIVED:
        result->setSpecificValue(0, i, this->layer.at(i)->getDerivedValue());
      case utils::NORMAL:
        result->setSpecificValue(0, i, this->layer.at(i)->getValue());
    }
  }
  return result;
}

vector<double> Layer::getActivatedValues()
{
  vector<double> returnValue;
  for(unsigned int i = 0; i < this->layer.size(); i++)
  {
    returnValue.push_back(this->layer.at(i)->getActivatedValue());
  }
  return returnValue;
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
