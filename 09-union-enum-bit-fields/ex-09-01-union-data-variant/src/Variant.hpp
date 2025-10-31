#pragma once

#ifndef VARIANT_H
#define VARIANT_H


enum VariantType { INT_T, FLOAT_T };

struct Variant {
    union TagValue {
        int intValue; 
        float floatValue;
    } value; 
    
    VariantType storedType; // Поле-тег
    
    void setInt(int i) ;
    int getInt() const ;

    void setFloat(float i) ;
    float getFloat() const ;
};

#endif // VARIANT_H