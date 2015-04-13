# strings
Attempt at creating a string library

<b>Objectives: </b>
-Use a well developed ADT class which utilizes operator overloading. 
-Use dynamically allocated arrays. 

<b>Problem: </b>
The Apache web server produces information detailing web page accesses, this information is stored in a log file in the Apache Common log file format. The assignment is to develop a program to process this log file and keep track of the different types of log entries. 

<b>Requirements: </b>
You CANNOT use the C++ standard string or any other libraries for this assignment, except were specified.
You must use your ADT string for the later parts of the assignment.
using namespace std; is stricly forbiden. As are any global using statements.

<b>Part 1 (25pts) </b>
<b><i>Implementation:</b></i>
<ul>
<li>Create an ADT String using the class construct.</li>
<i>Note: C++ has a standard type called string so you should not use this name. Use String instead.</i>
<li>Use the provided specification (string-Part1.hpp) for naming your class and methods You should rename this to string.hpp. A test suite will be provided in Part 2 that uses this interface to test your string class.</li>
<li>You can use a fixed sized array of char for storage with a max capacity constant (DEFAULT_STRING_CAPACITY = 256).</li>
<li>Implement the constructor functions (i.e., for char[] and char).</li>
<li>Overload operator+ as concatenation (make sure it works for all variations string + string, string + char[], char[] + string, etc).</li>
<li>Overload all the relational operators (==, <, >, etc.).</li>
<li>Implement the methods length, substr, findstr, findchar.</li>
<li>Overload I/O operators. Input should read in one word at a time. The input operator for char[] works that way and can be used.</li>
<li>Overload the accessor/modifier operator[].</li>
</ul>
<b>Testing:</b>
<ul>
<li>Develop a set of test cases, using asserts, for each of the operators and methods of the String class.</li>
<li>Write test cases first. Testing must be thorough. You will be relying on the string to be correct.</li>
<li>The command make tests will build and run the unit tests.</li>
<li>After each function passes a test, commit your work to svn with a message such as "Constructor tests passed".</li>
<li>Your string class will be tested on a set of cases developed by the instructor. You will be graded on how well you pass these tests. These tests cover the constructors, comparison, and the concatenation operator.</li>
</ul>
<br>
<b>Part 2 (25pts)</b>
<b>Implementation:</b>
<ul>
<li>Re-implement your String class to use a dynamically allocated array for storage.</li>
<li>Implement a destructor, copy constructor, constant time swap, and assignment operator for your ADT.</li>
<li>Set the default capacity to 256 and allow the user to specify a different capacity (via a constructor function).</li>
<li>Implement a resetCapacity method to change the capacity of your string keeping the contents intact. That is, create a new array and copy contents over to the new array, making sure to clean up memory.</li>
<b>Testing:</b>
<li>Re-run the tests again from Part 1. Write additional tests for the methods developed in this part.</li>
<li>Write test cases first. Testing must be thorough. You will be relying on the String to be correct.</li>
<li>The command make tests will build and run the unit tests.</li>
<li>After each function passes a test, commit your work to svn with an appropriate message.</li>
<li>A testing oracle will also be provided. These are a set of test cases for a large part of the string class functionality. You should make sure that the test cases you develop are as complete as the provided oracle.</li>
<li>You need to use the specification for String provided in string-part2.hpp to take advantage of the test oracle.</li>
<li>If you add additional member variables the tests will not work properly.</li>
<li>The command make oracle will build and run the unit tests.</li>
</ul><br>
<b>Part 3 (25 pts)
Implementation:</b>
<ul>
<li>You will use std::vector<> (need to include <vector>) for storing the results of parsing the input data.</li>
<li>For your String class, implement a method std::vector<String> String::split(char) const;</li>
<li>This method will return a vector of String split up based on a supplied character. For example given s = "abc ef gh", the call s.split(' ') will return a vector with three strings: "abc", "ef", and "gh".</li>
<li>std::vector has a number of operations defined including operator[], and size (number of elements in the vector).</li>
<b>Testing:</b>
<li>Write additional test cases for your split method (test_split.cpp).</li>
<li>Make sure these tests demostrate that the method work properly.</li>
<li>The command make tests will build and run the unit tests.</li>
</ul><br>
<b>Part 4 (25 pts)
Implementation:</b>
<ul>
<li>See the supplied source code and data files in the shared folder in svn. logentry.cpp defines an ADT for logEntry. You will need to add functionality to this class (mainly constructors) to solve the problem. logview.cpp is the main and compiles and runs as is. You can modify this if needed.</li>
<li>For each line in the log file split the line on blanks. This should result in 10 strings.</li>
<li>If the entry is invalid (not 10 strings), store a blank logEntry.</li>
<li>For all valid entries you will need to do further processing and properly construct the logEntry data structure. See logentry.hpp</li>
<b>Testing:</b></li>
<li>Write a function (called parse) to read all the lines from the file and create a logEntry object for each line. This function will return a vector of logEntry's.</li>
<li>Write a function that given the vector of logEntry's computes the total number of bytes in all the entries.</li>
<li>Write a function that given the vector of logEntry's prints out the host member of each log entry (one per line).</li>
<li>Write a main that takes a file name and an option as command line parameters. The program will open the file name given on the command line and read from that file. Based on the command line options it will:</li>
<li>Print all the logEntry entries (neatly one per line).</li>
<li>Print the total number of bytes.</li>
<li>Print the host member for each logEntry (one per line).</li>
<li>The command make logview will build and run this program.</li>
<li>Your program should work on all the provided input files.</li>
<li>Two data files are in www.cs.kent.edu/~jmaletic/CS23001/programs/data/ - log_4_large.txt and log_5_huge.txt.</li>
<li>Do NOT copy these into subversion as they are VERY large. The direct path is /users/cs/faculty/jmaletic/public_html/CS23001/programs/data/</li>
<b>Other Requirements:</b>
<li>You must have a separate specification file (.hpp), implementation file (.cpp), and main file.</li>
<li>Your program will be graded on programming and commenting style as well as the implementation of your ADT.</li>
<li>Include all source code files in svn.</li>
<li>You can NOT use a pre-defined or built in class (other than std::vector) to solve this problem.</li>
<i>See the grading policy for other requirements.</i>
</ul>
