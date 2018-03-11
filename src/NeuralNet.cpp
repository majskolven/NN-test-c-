#include "../headers/NeuralNet.h"



NeuralNet::NeuralNet(vector<int> NNLayout, vector<double> inputValues)
{
  //Making Layers
  for(unsigned int i = 0; i < NNLayout.size(); i++)
  {
    this->layers.push_back(new Layer(NNLayout.at(i)));
  }

  //Making Weights matrices connecting layers
  for(unsigned int i = 0; i < (NNLayout.size()-1); i++)
  {
    this->weights.push_back(new Matrice(this->layers.at(i)->getSize(),
                            this->layers.at(i+1)->getSize(),
                            true));
  }
  if(inputValues.size() != 0)
    this->setInputLayer(inputValues);
}

void NeuralNet::setInputLayer(vector<double> inputValues)
{
  this->inputValues = inputValues;
  for(unsigned int i = 0; i < inputValues.size(); i++)
  {
    this->layers.at(0)->setValues(i, inputValues.at(i));
  }
}
