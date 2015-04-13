#include "string.hpp"
#include <cassert>

//===========================================================================
int main ()
{
	{
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
		String str;

        // VERIFY
        assert(str.getLength() == 0);
	}

	{
		// Setup
		String str('a');

		// Verify
		assert(str.getLength() == 1);
	}

	{
		// Setup
		String str("a");

		// Verify
		assert(str.getLength() == 1);
	}

	{
		// Test
		String str("It's over 9000!");

        // Verify
        assert(str.getLength() == 15);
	}
}
