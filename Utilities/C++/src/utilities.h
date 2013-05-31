#ifndef UTILITIES_H_
#define UTILITIES_H_

#include <string>
#include <stdint.h>

namespace Sandbox
{

    class Utilities
    {
    public:
        // Reverse a std::string without using temporary memory
        static void Reverse( std::string& str );

        // Swap 2 integers without using temporary memory
        static void Swap( int32_t& num1, int32_t& num2 );

        // Return the higher of the 2 input numbers without
        // using conditional statements ( if/else ) or
        // comparison operators ( ==, <, >, <=, >=, etc. )
        static int32_t GetMax( int32_t num1, int32_t num2 );

        // Return the lower of the 2 input numbers without
        // using conditional statements ( if/else ) or
        // comparison operators ( ==, <, >, <=, >=, etc. )
        static int32_t GetMin( int32_t num1, int32_t num2 );
    };
}
#endif /* UTILITIES_H_ */
