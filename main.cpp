#include <iostream>
#include "classes.h"
using namespace std; 
#include <chrono>
#include <ctime>

//Need to calculate subgroups for certain groups 

/**
Definition of subgroups: 

A nonempty subset H of a group G is a subgroup of G provided that 

(i) If a, b \in H, then ab \in H
(ii) If a \in H, then a^{-1} \in H

**/

int main() {

  int userInput; 

  cout << "Enter an integer value: " << endl << endl; 
  
  cin >> userInput; 
  
  Group *group = new Group(userInput); 

  cout << endl << endl; 
  
  group->createGroup(); 

  cout << endl << endl; 
  
  group->createSubGroup(); 

  int userInput2;

  cout << endl << "Enter an element to generate a cyclic subgroup from: " << endl; 
  
  cin >> userInput2; 
  
  group->cyclicSub(userInput2); 
  
}