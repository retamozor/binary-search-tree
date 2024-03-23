#include <iostream>
#include "Bst/Bst.h"

using namespace std;

int main() {
  BST* bst = new BST();

  int n;
  cout << "Ingresar cantidad de numeros: ";
  cin >> n;

  for (int i = 0; i<n; i++) {
    int number;
    cout << "Ingresa el numero " << i + 1 << ": ";
    cin >> number;
    bst->push(number);
  }

  bst->print();
  
  BstNode* max = bst->max();
  if (max != nullptr) {
    cout << "el maximo es: " << max->data << endl;
  }
  
  BstNode* min = bst->min();
  if (min != nullptr) {
    cout << "el minimo es: " << min->data << endl;
  }
  
  cout << "la altura es: " << bst->height() << endl;
  
  int num;
  cout << "Ingresa un numero para buscar: ";
  cin >> num;
  if (bst->search(num) != nullptr) cout << "Encontrado" << endl;
  else cout << "No encontrado" << endl;

  cout << "Ingresa un numero para eliminar: ";
  cin >> num;
  bst->pop(num);
  bst->print();

  return 0;
}
