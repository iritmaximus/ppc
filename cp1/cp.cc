#include <iostream>
#include <cmath>
/*
This is the function you need to implement. Quick reference:
- input rows: 0 <= y < ny
- input columns: 0 <= x < nx
- element at row y and column x is stored in data[x + y*nx]
- correlation between rows i and row j has to be stored in result[i + j*ny]
- only parts with 0 <= j <= i < ny need to be filled
*/
void correlate(int ny, int nx, const float *data, float *result) {

    double sum_product;
    double sum_xi;
    double sum_xi_2pow;
    double sum_yi;
    double sum_yi_2pow;

    const int n = ny;

    for (int i=0; i<ny; ++i) {
        for (int j=0; j<ny; ++j) {
            result[j + i*nx] = 0; // initialize with 0
            std::cout << i << j << std::endl;
            
            if (i<j)
                continue;

            sum_product = 0;
            sum_xi = 0;
            sum_yi = 0;
            sum_xi_2pow = 0;
            sum_yi_2pow = 0;

            for (int k=0; k<ny; ++k) {
                double x_i = data[k + i*nx];
                double y_i = data[k + j*nx];

                sum_product += x_i * y_i;
                sum_xi += x_i;
                sum_yi += y_i;
                sum_xi_2pow += std::pow(x_i, 2);
                sum_yi_2pow += std::pow(y_i, 2);

                std::cout << x_i << " " << sum_xi << " " << sum_xi_2pow << std::endl;
            }

        double covariance = sum_product - sum_xi * sum_yi;
        double std_deviation_x = std::sqrt(n * sum_xi_2pow - pow(sum_xi, 2));
        double std_deviation_y = std::sqrt(n * sum_yi_2pow - pow(sum_yi, 2));

        float calc_result = covariance / (std_deviation_x * std_deviation_y);

        std::cout << "Covariance: " << covariance << " = " << sum_product << " - " << sum_xi << " * " << sum_yi << std::endl;
        std::cout << "std_deviation_x: " << std_deviation_x << std::endl;
        std::cout << "std_deviation_y: " << std_deviation_y << std::endl;
        std::cout << "Final calculations: (cov / (std_x * std_y))" << calc_result << std::endl;

        result[i + j*ny] = calc_result;
        }
    }


}
