#ifndef NEURALNET_H
#define NEURALNET_H



//2.31
//1.36
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>
#include "Layer.h"
#include "Matrice.h"
#include "./utils/utils.h"


using namespace std;
using namespace utils;

class NeuralNet
{

public:
  NeuralNet(vector<int> NNLayout);
  NeuralNet(
            vector<int> NNLayout,
            double error,
            ActivationType activationTypeOfHidden,
            ActivationType activationTypeOfOutput,
            int costFuncType
          );

  void setNeuronInLayer(int layer, int neuron, double value);
  void setInputLayer(vector<double> inputValues);
  void setTargetLayer(vector<double> targetValues);
  //implementaion in Errors.cpp
  void errorsFunc();
  void costErrorsFunc();

  vector<double> getActivatedValues(int index);
  Matrice* getWeights(int index);
  Matrice* getConvertedLayer(int index, utils::ValueType type);


  void forwardProp();
  void backProp();


  string toString();

  ~NeuralNet();
private:

  ActivationType activationTypeOfHidden  = RELU;
  ActivationType activationTypeOfOutput  = SIGMOID;
  int costFuncType                       = MSE_COST;
  double error;
  double bias;
  double momentum;
  double learnRate;

  vector<int>       NNLayout;

  vector<double>    errors;
  vector<double>    derivedErrors;

  vector<Layer*>    layers;
  vector<Matrice*>  weights;
  vector<Matrice*>  gradients;

  vector<double>    targetValues;
  vector<double>    inputValues;

};






#endif
