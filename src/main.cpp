#include <iostream>
#include <string>

#include "../headers/Layer.h"

#include "../headers/Neuron.h"

#include "../headers/Matrice.h"

using namespace std;


int main ()
{

  Matrice *m = new Matrice(3,2,true);
  cout << to_string(m->getRowCount())<< "    " << to_string(m->getColCount()) << endl << endl;
  cout << m->toString() << endl;

  cout << "=================================" << endl;


  Matrice *mtrans = m->tranposeMatrice();
  cout << to_string(mtrans->getRowCount())<< "    "  << to_string(mtrans->getColCount()) << endl << endl;
  cout << mtrans->toString() << endl;
  //In
  /*Neuron *n = new Neuron(5.9);
  Layer *l = new Layer(10);
  cout << "Val: " << n->getValue() << endl;
  cout << "Val Activated: " << n->getActivatedValue() << endl;
  cout << "Val Derived: " << n->getDerivedValue() << endl;
  delete n;*/

  return 0;
}
