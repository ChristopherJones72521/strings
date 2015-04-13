// 
// String.hpp
// Modified by Christopher Jones 
// for CS23001
//

#ifndef CS23001_P1_STRING_INTERFACE_HPP
#define CS23001_P1_STRING_INTERFACE_HPP

#include <iostream>
#include <vector>
#include <cstdlib>

using std::istream;
using std::ostream;
using std::vector;

#define default_size 128

class String
{
public:	
    String        (int size = default_size); // Initialize Sting to '\0', w/ optional capacity
    String        (const char, int size = default_size); // Initialize Sting to a single char
    String        (const char[], int size = default_size); // Initialize Sting to char array
    String(const String& rhs, int cap = default_size); // copy constructor
    ~String       (); // destructor
    String& operator=(String); // assignment operator for Strings
    
    
    char&   operator[]    (const int spot)                {return s[spot];}; // returns char from spot in string
    char    operator[]    (const int spot)          const {return s[spot];};
    bool    operator==    (const String&)           const;
    bool    operator!=    (const String& rhs)       const { return !(*this == rhs); };
    bool    operator<     (const String&)           const;
    bool    operator<=    (const String& rhs)       const { return (*this < rhs) || (*this == rhs); };
    bool    operator>     (const String& rhs)       const { return rhs < *this; };
    bool    operator>=    (const String& rhs)       const { return rhs <= *this; };
    String  operator+     (const String&)           const;
    String  operator+     (const String&);
    String  operator+=    (const String& rhs)             { return *this = *this + rhs; };
    String  operator-     (const int);
    String  operator-=    (const int x)                   { return *this = *this - x; };
    String  operator-     (const char);
    String  operator-=    (const char ch)                 { return *this = *this - ch; };
    String  operator-     (const String&);
    String  operator-=    (const String& str)             { return *this = *this - str; };
    String  operator*     (const int);
    String  operator*=    (const int x)                   { return *this = *this * x; };
    

    friend std::istream& operator>>(std::istream&, String&);
    friend std::ostream& operator<<(std::ostream&, const String&);
    
    int buffCapacity() const { return capacity; }; // return the length of a string
    int findchar(const char, const int start = 0) const; // return the number of occurances of char in a string
    int findstr(const String&) const; // return the number of occurances of a string inside a string
    int getLength() const { return strLength; }; // returns the length of a string
    void reallocate(const int size = default_size); // increases the capacity of a string and copies it
    String repeat(const int x) { return *this * x; }; // repeats a string a specified number of times with optional separator
    String repeat(const int, const String&);
    String reverse() const; // reverses the contents of a string
    vector<String> split(); // splits a string on a char and returns it as a vector
    vector<String> split(const char);
    String strip_nl() { return *this - '\n'; }; // Strips newlines from strings with optional replacement string
    String strip_nl(const String&);
    String substr(const int left = 0, int right = -1) const; // returns extracted part of a string
    void swap(String&); // swaps two string pointers
    int to_i(); // converts string to integer
    String zip(const String&) const; // zips two strings together

private:
    char *s;
    int capacity,
        strLength = 0;
    int length = strLength;
//    char str[DEFAULT_STRING_CAPACITY];
};

String getline(std::istream&); // Get's line with optional delimiter

#endif

