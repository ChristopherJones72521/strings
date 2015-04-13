#include "string.hpp"
#include <cassert>

//===========================================================================
int main ()
{
	{
		// Setup
		String str;

		// Verify
		assert(str[0] == '\0');
	}

	{
		// Setup
		String str('a');

		// Verify
		assert(str[0] == 'a');
	}

	{
		// Setup
		String str("a");

		// Verify
		assert(str[0] == 'a');
	}

	{
		// Setup
		String str("It's over 9000!");

		// Verify
        assert(str[1] == 'I');
		assert(str[2] == '\'');
	}
}
