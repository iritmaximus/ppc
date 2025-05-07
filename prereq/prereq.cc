#include <iostream>

struct Result {
    float avg[3];
};

/*
This is the function you need to implement. Quick reference:
- x coordinates: 0 <= x < nx
- y coordinates: 0 <= y < ny
- horizontal position: 0 <= x0 < x1 <= nx
- vertical position: 0 <= y0 < y1 <= ny
- color components: 0 <= c < 3
- input: data[c + 3 * x + 3 * nx * y]
- output: avg[c]
*/
Result calculate(int ny, int nx, const float *data, int y0, int x0, int y1, int x1) {
    Result result{{0.0f, 0.0f, 0.0f}};

    // 1. figure out rectangle
    // 2. extract each colors
    // 3. calculate average
    const double rect_size = (x1-x0)*(y1-y0);
    double color_array[] = {0.0, 0.0, 0.0};

    for (int x=0; x<nx; ++x) {
        for (int y=0; y<ny; ++y) {
            // 1. rectangle
            if (y0 <= y && y <= (y1-1) && x0 <= x && x <= (x1-1)) {
                // 2. colors
                /*
                std::cout << "x:" << x << ", y:" << y << " " 
                    << data[0 + 3*x + 3*nx*y] << " "
                    << data[1 + 3*x + 3*nx*y] << " "
                    << data[2 + 3*x + 3*nx*y] << " "
                    << "rect_size: " << rect_size
                    << std::endl;
                */
                for (int color=0; color<3;++color) {
                    color_array[color] += data[color + 3*x + 3*nx*y];
                }

            }
        }
    }

    /*
    std::cout << result.avg[0] << " "
        << result.avg[1] << " "
        << result.avg[2]
        << std::endl;
    */

    result.avg[0] = color_array[0]/rect_size;
    result.avg[1] = color_array[1]/rect_size;
    result.avg[2] = color_array[2]/rect_size;

    return result;
}
