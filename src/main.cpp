#include <iostream>
#include <string>
#include <vector>

#include "../headers/Layer.h"

#include "../headers/Neuron.h"

#include "../headers/Matrice.h"

#include "../headers/NeuralNet.h"

using namespace std;


int main ()
{
  vector<int> layout;
  layout.push_back(3);
  layout.push_back(2);
  layout.push_back(3);

  vector<double> inputVals;
  inputVals.push_back(1.0);
  inputVals.push_back(0.0);
  inputVals.push_back(1.0);


  NeuralNet *net = new NeuralNet(layout, inputVals);

  return 0;
}
