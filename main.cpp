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

*/
//also make one to check cyclic groups? 
/**
Function to find centralizer of a group 
*/

bool findInverse(int sub[]){

  //for(int i = 0; i < sub.length(); i++){

    
 // }
  
}

void subgroup(int group[], int sub[]){


  
  
}

int main() {

    // Using time point and system_clock
   // std::chrono::time_point<std::chrono::system_clock> start, end;
  
  //  start = std::chrono::system_clock::now();
  
  int userInput; 

  cout << "Enter an integer value: " << endl << endl; 
  
  cin >> userInput; 
  
  Group *group = new Group(userInput); 

  cout << endl << endl; 
  
  group->createGroup(); 

  cout << endl << endl; 
  
  group->createSubGroup(); 


  
   
  //  end = std::chrono::system_clock::now();
  
 //   std::chrono::duration<double> elapsed_seconds = end - start;
   // std::time_t end_time = std::chrono::system_clock::to_time_t(end);
  
   // std::cout << "finished computation at " << std::ctime(&end_time)
      //        << "elapsed time: " << elapsed_seconds.count() << "s\n";
}