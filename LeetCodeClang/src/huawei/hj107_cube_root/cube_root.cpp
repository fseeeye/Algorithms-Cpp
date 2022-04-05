#include "cube_root.h"

void HJ107::native_main()
{
	// handle input
	double num;
	std::cin >> num;

	// binary search
	double l = std::min(-1.0, num);
	double r = std::max(1.0, num);

	double mid = DBL_MAX, tmp;
	while (std::fabs(r - l) >= 0.01)
	{
		mid = l + (r - l) / 2.0;
		tmp = mid * mid * mid - num;

		if (tmp > 0.0)
		{
			r = mid;
		}
		else if (tmp < 0.0)
		{
			l = mid;
		}
	}

	if (mid != DBL_MAX)
	{
		printf("%.1f", mid);
	}
	else
	{
		printf("error");
	}
}
