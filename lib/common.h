#pragma once

#define ASSERT(x) if (!(x)) __debugbreak();

// Function type macros.
#define FORCEINLINE __forceinline			/* Force code to be inline */
#define FORCENOINLINE __declspec(noinline)	/* Force code to NOT be inline */
