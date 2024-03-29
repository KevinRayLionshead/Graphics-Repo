// RayTracing1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <float.h>

#include "CImg.h"
#include "vec3.h"
#include "utils.h"
#include "ray.h"

using namespace std;
using namespace cimg_library;

vec3 color() {
	
	return vec3(0.5f, 0.7f, 1.0f);
}
int main()
{
	int nx, ny, countRows;
	nx = 500;
	ny = 500;

	CImg<unsigned char> img(nx, ny, 1, 3);
	CImgDisplay canvas(img, "RayTracing Test2", 0);

	countRows = 0;
	for (int j = ny - 1; j >= 0; j--, countRows++) {
		for (int i = 0; i < nx; i++) {
			
			vec3 col = color();
			int ir = int(255.99f * col[0]);
			int ig = int(255.99f * col[1]);
			int ib = int(255.99f * col[2]);

			img(i, j, 0, 0) = ir;
			img(i, j, 0, 1) = ig;
			img(i, j, 0, 2) = ib;
		}
		float percentDone = 100.f * (float(countRows) / float(ny - 1));
		cout << percentDone << "%" << endl;
	}
	canvas.resize(nx, ny);
	img.mirror('y');
	while (!canvas.is_closed() && !canvas.is_keyESC()) {
		img.display(canvas);
		cimg::wait(20);
	}
}


