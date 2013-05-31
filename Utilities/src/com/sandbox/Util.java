package com.sandbox;

public class Util
{
    public static void main( String[] args )
    {
        Integer result = GetMax( 5,  -10 );
        System.out.println( "Max number is: " + result );
        
        int[] num1 = { 2 };
        int[] num2 = { 22 };
        ReverseIntegerNoTemp( num1, num2 );
        System.out.println( "Swapped numbers are: " + num1[0] + " : " + num2[0] );
    }
    
    public static int GetMax( int num1, int num2 )
    {
        int[] array = { num1, num2 };
        
        Integer result = num1 - num2;
        result = ( result & 0x80000000 ) >>> 31;
        
        return array[result];
    }
    
    public static void ReverseIntegerNoTemp( int[] num1, int[] num2 )
    {
        num1[0] = num1[0] ^ num2[0];
        num2[0] = num1[0] ^ num2[0];
        num1[0] = num1[0] ^ num2[0];
    }
}
