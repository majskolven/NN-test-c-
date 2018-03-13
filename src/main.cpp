#include <iostream>
#include <string>
#include <vector>

#include "../headers/Layer.h"

#include "../headers/utils/utils.h"


#include "../headers/Neuron.h"

#include "../headers/Matrice.h"

#include "../headers/NeuralNet.h"

using namespace std;


int main ()
{

  Matrice *a = new Matrice(3, 3, true);
  cout << a->toString() << endl;
  Matrice *b = new Matrice(3, 3, true);
  cout << "===================================" << endl;
  cout << b->toString() << endl;
  cout << "===================================" << endl<<endl<<endl;
  Matrice *c = new Matrice(a->getColCount(), b->getRowCount(), false);

  utils::Helper::matriceMultiplier(a,b,c);

  cout << c->toString() << endl;


  /*vector<int> layout;
  layout.push_back(4);
  layout.push_back(5);
  layout.push_back(5);
  layout.push_back(5);
  layout.push_back(3);

  vector<double> inputVals;
  inputVals.push_back(3.0);
  inputVals.push_back(4.0);
  inputVals.push_back(4.0);
  inputVals.push_back(4.0);

  NeuralNet *net = new NeuralNet(layout, inputVals);
  cout << net->toString() << endl;*/

  return 0;
}
