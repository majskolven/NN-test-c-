#ifndef LAYER_H
#define LAYER_H

#include <iostream>
#include <vector>
#include "Neuron.h"
#include "Matrice.h"
#include "./utils/utils.h"


using namespace std;

class Layer
{

public:
  Layer(int size);
  Layer(int size, utils::ActivationType type);


  Matrice* convertToMatrice(utils::ValueType type);

  int getSize();
  Neuron* getNeuron(int index);
  vector<double> getActivatedValues();
  vector<Neuron *> getLayer();

  void setLayer(vector<Neuron *> layer);
  void setNeuronValue(int index, double value);

  ~Layer();
private:
  int size;
  vector<Neuron *> layer;


};






#endif
