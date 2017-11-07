#include <iostream>
#include "Data/pointData.h"

int main()
{
	int n;
	std::cin >> n;

	PointData data;

	for(int i=0; i<n; ++i) {
        int x,y;
		std::cin >> x >> y;
		data.pushPoint(x,y);
	}

	return 0;
}
