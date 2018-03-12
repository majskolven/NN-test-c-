#include "../headers/NeuralNet.h"



NeuralNet::NeuralNet(vector<int> NNLayout)
{
  this->NNLayout = NNLayout;
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
}

NeuralNet::NeuralNet(vector<int> NNLayout, vector<double> inputValues)
{
  this->NNLayout = NNLayout;

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

string NeuralNet::toString()
{
  string result = "";
  for(unsigned int i = 0; i < NNLayout.size(); i++)
  {
    result += "------- Layer: " + to_string(i+1) + "-------\n";
    for(unsigned int j = 0; j < NNLayout.at(i); j++)
    {
      if(!i)
        result += to_string(this->layers.at(i)->getNeuron(j)->getValue()) + "\t\t";
      else
        result += to_string(this->layers.at(i)->getNeuron(j)->getActivatedValue()) + "\t\t";
    }
    result += "\n";
  }

  return result;
}

NeuralNet::~NeuralNet()
{
  while (!this->layers.empty())
  {
    Layer *l = this->layers.back();
    delete l;
    this->layers.pop_back();
  }

  while (!this->weights.empty())
  {
    Matrice *w = this->weights.back();
    delete w;
    this->weights.pop_back();
  }

}
