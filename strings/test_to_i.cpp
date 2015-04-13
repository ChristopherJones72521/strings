#include "string.hpp"
#include <cassert>

//===========================================================================
int main ()
{
	{
		// Setup
		String str = "35";
		
		// Test
		int num = str.to_i();
		
		// Verify
		assert(str == "35");
		assert(num == 35);
	}
}
