#include <iostream>
#include <vector> 
#include <algorithm>
#include <chrono>
using namespace std; 

class Group{

  public: 

      int groupSize; 
      vector<int> *group; 
      
  Group(int s){

    groupSize = s; 

    group = new vector<int>[groupSize]; 
    
  }

//Create a group Z mod groupSize
  void createGroup(){

    for(int i = 0; i < groupSize; i++){

      group->push_back(i); 
      cout << group->back() << " "; 
    }


    cout << endl << endl << "You've created the group Z* mod " << groupSize << endl; 
  }

//Find gcd of two numbers 
int gcd(int a, int b)
{
    if(b == 0)
       return a;
    else
     return  gcd(b, a%b);
}

//Create subgroup of units for Z mod groupSize 
 void createSubGroup(){

   vector<int> units; 
   
   for(int i = 0; i < group->size(); i++){

     if(gcd(group->at(i), groupSize) == 1){

     
       units.push_back(group->at(i)); 
       
     }

   }

   cout << "You've created the subset of units U" << groupSize << endl << endl; 
   
   for(int j = 1; j < units.size(); j++){

     cout << units.at(j) << " "; 
   }

   cout << endl << endl << "To check if this is a subgroup, we check the following criteria: \n \n (i) If a, b is in H, then ab is in H \n (ii) If a is in H, then a^{-1} is in H" << endl << endl; 


 // closure(units); 
 
 }

//Print a vector 
void print(vector<int> v){

  for(auto i: v){

    cout << v[i] << " "; 
  }
}

//find a value within a vector 
bool find(vector<int> v, int element){

  vector<int>::iterator it; 
  int found = 0; 
  it = ::find(v.begin(), v.end(), element); 

  if(it != v.end()){

    return true; 
  }
 
}

//Check U groupSize for closure under multiplication 
/*
Add code to elapse time as it checks for each product in the vector. The elapsed time should print out if every permutation is successful. Otherwise, the program will stop and print "not closed under *". 
*/
  void closure(vector<int> sub){

     int product = 0; 
     int count = 0; 
       // Using time point and system_clock
    std::chrono::time_point<std::chrono::system_clock> start, end;
  
    start = std::chrono::system_clock::now();
    
  do{

     product = (sub[sub.size() - 1] * sub[sub.size() - 2]) % groupSize; 
  
      if(!find(sub, product)){

      cout << "This subset is not closed under multiplication." << endl;
      
      }else{

      cout << sub[sub.size() - 1] << " * " << sub[sub.size() - 2] << " = " << (sub[sub.size() - 1] *       
      sub[sub.size() - 2]) << " = " << product << endl; 
        
      }
    
    }while(next_permutation(sub.begin(), sub.end())); 
  
   end = std::chrono::system_clock::now();  

    std::chrono::duration<double> elapsed_seconds = end - start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);

      std::cout << endl << "Elapsed Time: " << elapsed_seconds.count() << "s\n";
}

  
};