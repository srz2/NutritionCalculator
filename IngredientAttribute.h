#include <iostream>
#include <stdio.h>
using namespace std;

#define MAX_SIZE_INGREDIENT_NAME            32
#define MAX_SIZE_INGREDIENT_ATTRIBUTE_NAME  32
#define MAX_SIZE_ATTRIBUTE_CHILDREN         32
#define MAX_SIZE_ATTRIBUTES_PER_INGREDIENT  10

class IngredientAttribute
{
private:
  char * name;
  unsigned int weight;

  unsigned int childrenIndex;
  IngredientAttribute * children;
public:
  IngredientAttribute();
  IngredientAttribute(string name);
  IngredientAttribute(string name, unsigned int weight);

  ~IngredientAttribute();
  IngredientAttribute(const IngredientAttribute & other);
  IngredientAttribute & operator = (const IngredientAttribute & other);

  void setName(char * newName);
  char * getName();
  void setWeight(unsigned int newWeight);
  unsigned int getWeight();

  bool hasAttributes();
  unsigned int getNumAttributes();
  IngredientAttribute * getAttributes(unsigned int numChildren);
  IngredientAttribute * getAttribute(unsigned int index);
  bool addAttribute(IngredientAttribute * newChild);
  bool addAttribute(char * name, unsigned int weight);
};
