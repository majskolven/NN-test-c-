#include "../headers/NeuralNet.h"



NeuralNet::NeuralNet(vector<int> NNLayout)
{
  this->NNLayout = NNLayout;
  this->learnRate = 0.05;
  this->momentum = 1;
  this->bias = 1;

  //Making Layers and activating Neurons
  this->layers.push_back(new Layer(NNLayout.at(0)));
  for(unsigned int i = 1; i < NNLayout.size() - 1; i++)
  {
    this->layers.push_back(new Layer(NNLayout.at(i), this->activationTypeOfHidden));
  }
  this->layers.push_back(new Layer(NNLayout.at(NNLayout.size()-1), this->activationTypeOfOutput));

  //Making Weights matrices connecting layers
  for(unsigned int i = 0; i < (NNLayout.size()-1); i++)
  {
    this->weights.push_back(new Matrice(this->layers.at(i)->getSize(),
                            this->layers.at(i+1)->getSize(),
                            true));
  }
  for(unsigned int i = 0; i < NNLayout.at((NNLayout.size()-1)); i++)
  {
    this->errors.push_back(0.00);
  }
  this->error = 0.00;
}

NeuralNet::NeuralNet(vector<int> NNLayout, double error,
                      ActivationType activationTypeOfHidden,
                      ActivationType activationTypeOfOutput,
                      int costFuncType
                    )
{
  this->NNLayout = NNLayout;
  this->learnRate = 0.05;
  this->momentum = 1;
  this->bias = 1;
  this->activationTypeOfHidden = activationTypeOfHidden;
  this->activationTypeOfOutput = activationTypeOfOutput;
  this->costFuncType = costFuncType;

  //Making Layers and activating Neurons
  this->layers.push_back(new Layer(NNLayout.at(0)));
  for(unsigned int i = 1; i < NNLayout.size() - 1; i++)
  {
    this->layers.push_back(new Layer(NNLayout.at(i), this->activationTypeOfHidden));
  }
  this->layers.push_back(new Layer(NNLayout.at(NNLayout.size()-1), this->activationTypeOfOutput));

  //Making Weights matrices connecting layers
  for(unsigned int i = 0; i < (NNLayout.size()-1); i++)
  {
    this->weights.push_back(new Matrice(this->layers.at(i)->getSize(),
                            this->layers.at(i+1)->getSize(),
                            true));
  }
  for(unsigned int i = 0; i < NNLayout.at((NNLayout.size()-1)); i++)
  {
    this->errors.push_back(0.00);
  }
  this->error = 0.00;

}

void NeuralNet::setNeuronInLayer(int layer, int neuron, double value)
{
  this->layers.at(layer)->setNeuronValue(neuron, value);
}

void NeuralNet::setInputLayer(vector<double> inputValues)
{
  this->inputValues = inputValues;
  for(unsigned int i = 0; i < inputValues.size(); i++)
  {
    this->layers.at(0)->setNeuronValue(i, inputValues.at(i));
  }
}

void NeuralNet::setTargetLayer(vector<double> targetValues)
{
  this->targetValues = targetValues;
}

vector<double> NeuralNet::getActivatedValues(int index)
{
  return this->layers.at(index)->getActivatedValues();
}


Matrice* NeuralNet::getConvertedLayer(int index, utils::ValueType type)
{
  return this->layers.at(index)->convertToMatrice(type);
}

Matrice* NeuralNet::getWeights(int index)
{
  return new Matrice(*this->weights.at(index));
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
