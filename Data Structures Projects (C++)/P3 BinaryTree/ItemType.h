//ItemType.h
#ifndef ITEMTYPE_H
#define ITEMTYPE_H

/*
 * construction of the Comparison enumeration
 */
enum Comparison {LESS, EQUAL, GREATER};

class ItemType
{
  public:
    /*
     * default constructor
     * Post-Condition: ItemType object is created.
     */
    ItemType();

    /*
     * constructor
     * Pre-Condition: Number has been initialized.
     * Post-Condition: ItemType object is created.
     */
    ItemType(int number);

    /*
     * initializes ItemType with a new value
     * Pre-Condition: Number has been initialized.
     * Post-Condition: The value instance variable is set to number.
     */
    void initialize(int number);

    /*
     * prototype for the compareTo function that compares the values stored
     * Pre-Condition: ItemType item has been initialized. ItemType with value
     * has been initialized.
     * Post-Condition: One of the cases of enum (GREATER, LESS, EQUAL) is returned
     * from the result of the comparison
     */
    Comparison compareTo(ItemType &item);

    /*
     * prototype for the getValue function that returns the value of item
     * Pre-Condition: ItemType object has been initialized.
     * Post-Condition: Return the value instance variable.
     */
    int getValue() const;

    /*
     * prototype for the print function that prints the value of item
     * Pre-Condition: ItemType object has been initialized.
     * Post-Conditon: Value instance varibale is printed to standard-out
     */
    void print();

  private:
    int value;
};

#endif
