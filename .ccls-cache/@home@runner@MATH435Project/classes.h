#include <iostream>
#include <vector> 
#include <algorithm>
#include <chrono>
#include <math.h> 
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


    cout << endl << endl << "You've created the group Z* mod " << groupSize << " of order " << groupSize << endl; 
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
   
   for(int j = 0; j < units.size(); j++){

     cout << units.at(j) << " "; 
   }

   cout << endl << endl << "To check if this is a subgroup, we check the following criteria: \n \n (i) If a, b is in H, then ab is in H \n (ii) If a is in H, then a^{-1} is in H" << endl << endl; 


  closure(units); 

  cout << endl << "This set is closed under multiplication." << endl << endl; 

   inverses(units); 

   cout << endl << " The inverses of each element are found in U" << groupSize << endl; 

   cout << endl << endl << "Thus, U" << groupSize << " is a subgroup of Z* mod " << groupSize << " of order " << units.size() << endl; 
     
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
  void closure(vector<int> sub){

     int product = 0; 
     int count = 0; 
     
    std::chrono::time_point<std::chrono::system_clock> start, end;
  
    start = std::chrono::system_clock::now();

    //Loop to check every possible combination of integers in the subset
  do{

     product = (sub[sub.size() - 1] * sub[sub.size() - 2]) % groupSize; 
  
      if(!find(sub, product)){

      cout << "This subset is not closed under multiplication." << endl;
      return; 
        
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

//Create a cyclical subgroup 
  void cyclicSub(int num){

    int count = 0; 
    int exp = 0; 

  cout << endl << "Generating the cyclic subgroup " << "<" << num << "> ...";
   exp += num; 

  cout << " { "; 
    do{

     
      cout << exp % groupSize << ", "; 
      exp *= num; 
      count += 1; 
      
    }while((exp % groupSize) != 1); 

    count += 1; 
    
    cout << exp % groupSize << " }" << endl << endl; 

    cout << "<" << num << ">" << " has order " << count; 
}


//Verify inverses of a subgroup 
void inverses(vector<int> sub){

    int product = 0; 
    int p2 = 0; 
     int count = 0; 
     
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();

    //Loop to check every possible combination of integers in the subset
  do{

     product = (sub[sub.size() - 1] * sub[sub.size() - 2]) % groupSize; 
     p2 = (sub[sub.size() - 1] * sub[sub.size() - 1]) % groupSize;
     
     if(p2 == 1){

         cout << sub[sub.size() - 1] << " * " << sub[sub.size() - 1] << " = " << 
         (sub[sub.size() - 1] *       
         sub[sub.size() - 1]) << " = " << p2 << endl; 
       
     }else if(product == 1){

       cout << sub[sub.size() - 1] << " * " << sub[sub.size() - 2] << " = " << 
       (sub[sub.size() - 1] *       
       sub[sub.size() - 2]) << " = " << product << endl; 
        
      }
    
    }while(next_permutation(sub.begin(), sub.end())); 
  
   end = std::chrono::system_clock::now();  

    std::chrono::duration<double> elapsed_seconds = end - start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);

    std::cout << endl << "Elapsed Time: " << elapsed_seconds.count() << "s\n"; 
}



};