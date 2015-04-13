/*
 * ==============================================================
 * String.cpp
 * Created by Christopher Jones for CS23001
 * Copyright (c) 2015 Christopher Jones. All rights reserved.
 * ==============================================================
*/

#include "string.hpp"

// ---[Default Constructor]--- //
// ---[Initialize String to '\0', with optional capacity]--- //
String::String(const int size) 
{
	capacity = size;
	s = new char[capacity];
	s[0] = '\0';
	strLength = 0;
}

// ---[char Constructor]--- //
String::String(const char ch, const int size)
{
	capacity = size;
	s = new char[capacity];
	s[0] = ch;
	s[1] = '\0';
	strLength = 1;
}

// ---[New implementation: String constructor for c-style strings]--- //
String::String(const char ch[], const int size)
{
	// Calculate the length of the string
	for (length = 0; ch[length] != '\0'; ++length){}

	// Resize capacity as needed
	if (length > size - 1)
	{
		capacity = length + 1;
	} else {
		capacity = size;
	}

	s = new char[capacity];

	// Copy chars to string
	for (int i = 0; ch[i] != '\0'; ++i)
	{
		s[i] = ch[i];
	}

	s[length] = '\0';
}

/*
// ---[const char Constructor]--- //
String::String(const char ch[], const int size)
{
	capacity = size;
	s = new char[capacity];

	do {
		int i = 0;

		for (; ch[i] != '\0'; ++i)
		{ 
			s[1] = ch[i];
		}

		strLength = i;

		if (capacity < strLength) {
			delete [] s;
			capacity *= 2;
			s = new char[capacity];
			strLength = capacity;
		}
	} while (capacity < strLength);

	s[strLength] = '\0';
}
*/

// ---[Copy constructor]--- //
String::String(const String& rhs, const int cap)
{
	// Check if string capacity is shorter than length
	if (cap <= rhs.strLength)
		capacity = rhs.strLength + 1;
    	else
        	capacity = cap;
    
    	s = new char[capacity];
    
	// Copy chars to string
	for (length = 0; rhs.s[length] != '\0'; ++length)
	{
		s[length] = rhs.s[length];
	}

	s[length] = '\0';



/* ---[old implementation]---
 *
  	do {
        	int i = 0;
        
        	for (; rhs[i] != '\0'; ++i) {
            		s[i] = rhs[i];
        }
        
        strLength = i;
        
    	} while (capacity < strLength);
    
    	s[strLength] = '\0';
*/
}


// ---[Destructor]--- //
String::~String()
{
	strLength = 0;
	delete [] s;
}

// ---[Assignment operator for strings]--- //
String& String::operator=(String rhs)
{
    swap(rhs);
    return *this;
}

// ---[operator overloading: compare two strings]--- //    
bool    String::operator == (const String& rhs)           const
{
	if (length != rhs.length) return false;

	for (int i=0; i<length;++i)
	{
		if (length != rhs.length) return false;
	}

	return true;
/*	
	if (strLength == rhs.strLength)
	{
		for (int i=0; s[i] != '\0' && rhs[i] != '\0'; ++i)
		{
			if (s[i] != rhs[i])
				return false;
		}
		return true;
	}
	return false;
*/
}

// ---[compares the length of the strings and returns a bool]--- //
bool    String::operator<(const String& rhs)          const
{
	bool lessThan = false;
	int i = 0;

	for (; (s[i] != '\0') && (rhs[i] != '\0'); ++i)
	{
		if (s[i] > rhs[i])
            return false;
		if (s[i] < rhs[i])
            lessThan = true;
    }

	if (lessThan && (s[i] == '\0') && (rhs[i] == '\0')) return true;
	if (lessThan && (rhs[i] == '\0')) return true;
	if (!lessThan && (s[i] == '\0') && (rhs[i] == '\0')) return false;
	if (s[i] == '\0') return true;
	return false;
}

            
// ---[add strings]--- //
String String::operator+(const String& rhs)	const
{
	int i = strLength;
	String result(*this, i + rhs.strLength + 1);
            
    	for (int j = 0; rhs[j] != '\0'; ++i, ++j)
    	{
        	result[i] = rhs[j];
    	}
            
    	return (result.strLength = i, result[i] = '\0', result);
}

// ---[Subtract x number of chars from string]--- //
String String::operator-(const int x)
{
    if (x <= 0)
    {
        return *this;
    }
    else if (x >= strLength)
    {
        String result;
        return result;
    }
    else
    {
        String result(strLength - (x + 1));
                
        for (int i = 0; i < (strLength - x); ++i)
        {
            result += s[i];
        }
                
            return result;
    }
}
            
// ---[subracts a specific char from string]--- //
String String::operator-(const char ch)
{
    String result(strLength + 1);
            
    for (int i = 0; i < strLength; ++i) {
        if (s[i] != ch)
        {
            result += s[i];
        }
    }
            
        return result;
}
            
// ---[Subtract a specific string from String]--- //
String String::operator-(const String& rhs)
{
    String result(strLength + 1);
    int i = 0;
            
    for (int j = 0; i < strLength; ++i, j = 0)
    {
        while (s[i + j] == rhs.s[j] && j <= rhs.strLength)
        {
            ++j;
                    
            if (j == rhs.strLength)
            {
                i = i + j;
            }
        }
                
            result += s[i];
    }
            
        return result;
}
            
// ---[Multiplies the contents of String by an integer]--- //
String String::operator*(const int x)
{
    if (x <= 0)
    {
        String result;
        return result;
    }
    else if (x == 1)
    {
        return *this;
    }
    else
    {
        String result(*this, (strLength * x) + 1);
                
        for (int i = 1; i < x; ++i)
        {
            result += *this;
        }
                
        return result;
    }
}
            
// ---[Outputs string with << operator]--- //
ostream& operator<<(ostream& out, const String& str)
{
    out << str.s;
    return out;
}
            
// ---[Inputs string with >> operator]--- //
istream& operator>>(istream& in, const String& str)
{
    //in >> str.s;
    return in;
}
            
// ---[returns the number of occurences of char in a string]--- //
int String::findchar(const char ch, const int start) const
{
    String temp = substr(start);
    int first_index = -1;
            
    for (int i = 0; i < strLength; ++i)
    {
        if (temp[i] == ch)
        {
            return first_index = i + start;
        }
    }
            
        return first_index;
}
            
// ---[returns the number of occurences of a string inside a string]--- //
int String::findstr(const String& find) const
{
    int times = 0;
            
    if (strLength >= find.strLength)
    {
        for (int i = 0, j = 0; i < strLength; ++i, j = 0)
        {
            while (s[i + j] == find.s[j] && j <= find.strLength)
            {
                ++j;
                        
                if (j == find.strLength)
                {
                    ++times;
                    i = i + j;
                }
            }
        }
    }
    
    return times;
}
            
// ---[increases the capacity of a string and copies it]--- //
void String::reallocate(const int size)
{
    String temp(*this, size);
    swap(temp);
}
            
// ---[repeats a string an optional number of times with specifier]--- //
String String::repeat(const int x, const String& seperator)
{
    String result(((strLength + seperator.strLength) * x) + 1);
            
    for (int i = 0; i < x; ++i)
    {
        result += *this + seperator;
    }
            
        return result;
}
            
// ---[reverses the contents of a string]--- //
String String::reverse() const
{
    int i = strLength;
    String result(i + 1);
            
    for (; i >= 0; --i)
    {
        result += s[i];
    }
            
    return result;
}
            
// ---[splits string on a char and returns a vector]--- //
vector<String> String::split()
{
    vector<String> result;
            
    for (int i = 0; s[i] != '\0'; ++i)
    {
        result.push_back(s[i]);
    }
            
        return result;
}
            
vector<String> String::split(const char ch)
{
    vector<String> result;
    String temp;
            
    for (int i = 0; s[i] != '\0'; ++i)
    {
        if (s[i] != ch)
        {
        temp += s[i];
        }
        else
        {
            result.push_back(temp);
            temp = s[++i];
        }
    }
            
    return (result.push_back(temp), result);
}
            
// ---[strips newlines from strings]--- //
String String::strip_nl(const String& replacement)
{
    String result;
            
    for (int i = 0; i < strLength; ++i)
    {
        if (s[i] != '\n')
            result += s[i];
        else
            result += replacement;
    }
            
    return result;
}
            
// ---[RETURNS EXTRACTED PART OF STRING]--- //
String String::substr(const int left, int right) const
{
    if (right < 0 || right > strLength)
    {
        right = strLength;
    }
            
    if (left == 0)
    {
        String result = *this;
        return result - (strLength - right);
    }
    else
    {
        String result(strLength + 1);
                
        for (int i = left; i < right + 1; ++i)
        {
            result += s[i];
        }
                
        return result;
    }
}
            
// ---[swaps two strings' pointers]--- //
void String::swap(String& str)
{
    char *temp = s;
    s = str.s;
    str.s = temp;
            
    capacity = (capacity + str.capacity) - (str.capacity = capacity);
    strLength = (strLength + str.strLength) - (str.strLength = strLength);
}
            
// ---[converts a string to integer]--- //
int String::to_i()
{
    int startindex = strLength - 1;
            
    if (s[startindex] == '-')
    {
        return 0;
    }
            
    int value = 0,
    tenspot = 1;
            
    for (int i = startindex; i >= 0; --i)
    {
        value += (int(s[i] - int('0')) * tenspot);
        tenspot *= 10;
    }
            
    return value;
}
            
// ---[zips two strings together]--- //
String String::zip(const String& rhs) const
{
    String result(strLength + rhs.strLength + 1);
    int i = 0;
            
    do
    {
        if (i <= strLength)
            result += s[i];
                
        if (i <= rhs.strLength)
            result += rhs[i];
                
            ++i;
    }
    while (i <= result.capacity - 1);
            
        return result;
}
            
// ---[get line of text with optional delimiter]--- //
String getline(istream& in)
{
    String line;
    char ch = '\0';
            
    for (int i = (in.get(ch), 0); (ch != '\n') && (!in.fail()); ++i, in.get(ch))
    {
        if (i == (line.buffCapacity() - 1))
        {
            line.reallocate(line.buffCapacity() * 2);
        }
                
        line += ch;
    }
            
    return line;
}

