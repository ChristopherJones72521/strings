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
        assert(str[0] == '\0');
        assert(str == "");
    }

	{
		// Setup
		String str(50);

		// Verify
		assert(str[0] == '\0');
		assert(str == "");
	}
}
