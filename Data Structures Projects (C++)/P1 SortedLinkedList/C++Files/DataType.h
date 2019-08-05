#ifndef DATATYPE_H
#define DATATYPE_H

enum Comparison {LESS, EQUAL, GREATER};

class DataType
{
public:
    DataType();
    DataType(int newValue);
    
    void initialize(int newValue);
    Comparison compareTo(DataType &item);
    int getValue() const;
    void print() const;

private:
    int value;
};

#endif
