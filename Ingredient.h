#include "IngredientAttribute.h"

class Ingredient
{
  private:
    char * name;
    unsigned int calories;
    unsigned int caloriesFromFat;
    unsigned int weight;

    unsigned int attributeIndex;
    IngredientAttribute * attributes;
  public:
    Ingredient();
    Ingredient(string name);
    Ingredient(string name, unsigned int calories, unsigned, int caloriesFromFat);

    ~Ingredient();
    Ingredient(const Ingredient & other);
    Ingredient & operator = (const Ingredient & other);

    void setName(char * name);
    char * getName();
    
    void setCalories(unsigned int calories);
    unsigned int getCalories();

    void setCaloriesFromFat(unsigned int caloriesFromFat);
    unsigned int getCaloriesFromFat();

    unsigned int getNumAttributes();
    IngredientAttribute * getAttributes(unsigned int & numAttributes);
    IngredientAttribute * getAttribute(unsigned int index);
    IngredientAttribute * getAttribute(char * name);
    bool addAttribute(IngredientAttribute * newAttribute);

};
