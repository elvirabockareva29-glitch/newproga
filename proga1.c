
#include <stdio.h>
#include <math.h>
#include <float.h>

int main(void) {
    const double x_min = 1.0, x_max = 3.0, hx = 1.2;
    const double y_min = 0.0, y_max = 1.0, hy = 0.55;
    const double z_min = 1.0, z_max = 2.0, hz = 0.6;
    const double eps = 1e-9;

    double best_U = -DBL_MAX;
    double best_x = 0.0, best_y = 0.0, best_z = 0.0;

    printf("   x      y      z        U\n");
    printf("-------------------------------------\n");

    // Перебор по x
    for (int ix = 0;; ++ix) {
        double x = x_min + ix * hx;
        if (x > x_max + eps) break;

        // Перебор по y
        for (int iy = 0;; ++iy) {
            double y = y_min + iy * hy;
            if (y > y_max + eps) break;

            // Перебор по z
            for (int iz = 0;; ++iz) {
                double z = z_min + iz * hz;
                if (z > z_max + eps) break;

                // Формула для U
                double denom = z*z + (x*x)/4.0;
                double expr = y - sqrt(x) * (x - y/denom);
                double U = sin(fabs(expr));

                printf("%5.2f  %5.2f  %5.2f   %10.6f\n", x, y, z, U);

                if (U > best_U) {
                    best_U = U;
                    best_x = x;
                    best_y = y;
                    best_z = z;
                }
            }
        }
    }

    printf("\nМаксимальное значение U = %.6f\n", best_U);
    printf("Достигается при: x = %.2f, y = %.2f, z = %.2f\n",
           best_x, best_y, best_z);

    return 0;
}
