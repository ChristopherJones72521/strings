###############################################################
# String & Oracle
#
# CS II Kent State University
# Make file for string class and testing oracle 
# J. Maletic 2015
#
#

###############################################################
# Variables
CPP     = clang++
OPTIONS = -g -Wall -W -Wunused -Wuninitialized -Wshadow -std=c++11


# Names of your test files - add them in as you build them.
# Names must start with "test_"
MYTESTS = test_default_ctor test_c_str_ctor test_assignment test_subscript test_length test_less_than test_greater_than test_additon test_reverse test_multiplication test_zip test_strip_nl test_repeat test_subtraction test_substr test_cout test_findchar test_findstring test_cin test_reallocate test_split test_swap test_to_i


# Names of test oracle files 
CTOR = testoracle_ctor_default testoracle_ctor_int testoracle_ctor_char testoracle_ctor_charArray_int testoracle_ctor_charArray
REL  = testoracle_equal testoracle_lessThan
COPY = testoracle_ctor_copy testoracle_assign
OPS  = testoracle_concat

###############################################################
# Compile just the string
# Compile and run all provided test oracles on string
# Compile and run all your tests on string
# Compile and run the project
msg:
	@echo 'Targets are:'
	@echo '  string'
	@echo '  oracle'
	@echo '  tests'
	@echo '  logview'
	@echo '  clean'



###############################################################
# Compile string 
#
string.o: string.hpp string.cpp
	$(CPP) -c $(OPTIONS) string.cpp -o string.o

string: string.o
	

###############################################################
# Run all of your tests
#
tests: $(MYTESTS)
	./test_default_ctor
	./test_c_str_ctor
	./test_assignment
	./test_subscript
	./test_length
	./test_less_than
	./test_greater_than
	./test_addition
	./test_reverse
	./test_multiplication
	./test_zip
	./test_strip_nl
	./test_repeat
	./test_subtraction
	./test_substr
	./test_findchar
	./test_findstring
	./test_cout
	./test_cin
	./test_reallocate
	./test_split
	./test_swap
	./test_to_i
    
###############################################################
# Compile all test programs
#
test_%: string.o test_%.o
	$(CPP) string.o test_$*.o -o test_$*

test_%.o: string.hpp test_%.cpp
	$(CPP) $(OPTIONS) -c test_$*.cpp



###############################################################
# Run test oracle
# Comment out one's you don't want.
#
oracle: $(CTOR) $(REL) $(COPY) $(OPS)
	./testoracle_ctor_default
	./testoracle_ctor_int
	./testoracle_ctor_char 
	./testoracle_ctor_charArray
	./testoracle_ctor_charArray_int 
	./testoracle_equal 
	./testoracle_lessThan
	./testoracle_ctor_copy 
	./testoracle_assign
	./testoracle_concat
    

###############################################################
# Compile all test programs
#
testoracle_%: string.o testoracles/testoracle_%.o
	$(CPP) string.o testoracles/testoracle_$*.o -o testoracle_$*
    



###############################################################
# Compile Project 
#

logview.o: logview.cpp logentry.hpp string.hpp
	$(CPP) -c $(OPTIONS) logview.cpp -o logview.o
    
logentry.o: logentry.cpp logentry.hpp string.hpp
	$(CPP) -c $(OPTIONS) logentry.cpp -o logentry.o

logview: logview.o string.o logentry.o 
	$(CPP) $(OPTIONS) logview.o string.o logentry.o -o logview


###############################################################
# clean 
# Removes all .o files and all executables
#
clean:
	rm -f *.o
	rm -f $(CTOR) $(REL) $(COPY) $(OPS)
	rm -f $(MYTESTS)
	rm -f logview
	rm -f test_default_ctor test_c_str_ctor test_assignment
	rm -f test_length test_subscript
	rm -f test_less_than test_greater_than
	rm -f test_additon test_reverse test_multiplication test_zip test_strip_nl test_repeat test_subtraction
	rm -f test_substr test_cout test_findchar test_findstring test_cin test_reallocate test_split test_swap
	rm -f test_to_i splits logview 


