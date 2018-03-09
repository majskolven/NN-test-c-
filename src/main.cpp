#include <iostream>
#include <string>


#include "../headers/Neuron.h"
using namespace std;


int main ()
{


  //In
  Neuron *n = new Neuron(5.9);

  cout << "Val: " << n->getVal() << endl;
  cout << "Val Activated: " << n->getActivatedVal() << endl;
  cout << "Val Derived: " << n->getDerivedVal() << endl;
  delete n;

  return 0;
}
