#include "utilities.h"

#include <iostream>

namespace Sandbox
{
    void Utilities::Reverse( std::string& str )
    {
        std::string::iterator end = str.end() - 1;
        std::string::iterator front = str.begin();
        for( ; front < end; ++front, --end )
        {
            (*front) = (*front) ^ (*end );
            (*end) = (*front) ^ (*end );
            (*front) = (*front) ^ (*end );
        }
    }

    void Utilities::Swap( int32_t& num1, int32_t& num2 )
    {
        num1 = num1 ^ num2;
        num2 = num1 ^ num2;
        num1 = num1 ^ num2;
    }

    int32_t Utilities::GetMax( int32_t num1, int32_t num2 )
    {
        int32_t array[2] = { num1, num2 };
        int32_t diff = num1 - num2;
        diff = ( diff & 0x80000000 ) >> 31;
        return array[diff];
    }

    int32_t Utilities::GetMin( int32_t num1, int32_t num2 )
    {
        int32_t array[2] = { num2, num1 };
        int32_t diff = num1 - num2;
        diff = ( diff & 0x80000000 ) >> 31;
        return array[diff];
    }
}
