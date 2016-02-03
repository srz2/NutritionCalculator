#include <fstream>
#include "MainProgram.h"

//typedef IngredientAttribute iAtt;

int main()
{
  Log * log = Log::Instance();
  MainProgram * myProgram = MainProgram::Instance();

  myProgram->run();

  delete myProgram;
  delete log;
  
  /*unsigned int index = 0;
  Ingredient * ingredients = new Ingredient[100];

  string foodname = "";
  unsigned int weight;
  unsigned int cals;
  unsigned int calsFat;

  cout << "Input Food Name: ";
  getline(cin, foodname);
  cin.clear();

  cout << "Input Weight Per Serving: ";
  cin >> weight;
  cout << "Input Calories: ";
  cin >> cals;
  cout << "Input Calories from Fat: ";
  cin >> calsFat;

  unsigned int totalCarbs = 0;
  unsigned int dFiber = 0;
  unsigned int sugar = 0;
  Ingredient anIngredient = Ingredient(foodname);
  cout << "Total Carbs: ";
  cin >>  totalCarbs;
  cout << "Dietary Fiber: ";
  cin >> dFiber;
  cout << "Sugar: ";
  cin >> sugar;
  IngredientAttribute * carbs = new IngredientAttribute("Total Carbs", totalCarbs);
  carbs->addAttribute(new IngredientAttribute("Dietary Fiber", dFiber));
  carbs->addAttribute(new IngredientAttribute("Sugar", sugar));
  anIngredient.addAttribute(carbs);


  IngredientAttribute * singleAttribute = anIngredient.getAttribute((unsigned int)0);
  cout << "\tCreated: " << anIngredient.getName() << " with " << anIngredient.getNumAttributes() << " attributes!" << endl;
  cout << "\t\tIt has " << singleAttribute->getWeight() << "g of " << singleAttribute->getName() << "!" << endl;
  cout << "\t\t" << singleAttribute->getName() << " has " << singleAttribute->getNumAttributes() << endl; 
  
  delete [] ingredients;*/
}
