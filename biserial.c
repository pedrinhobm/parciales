#include <stdio.h>
#include <math.h>

double correlacion_puntual_biserial(float x[], int y[], int n) {
    double sum_x_0 = 0.0;
    double sum_x_1 = 0.0;
    double sum_squared_x = 0.0;
    double sum_y = 0.0;
    double sum_squared_y = 0.0;
    int n_0 = 0;
    int n_1 = 0;

    // Calcular sumas necesarias
    for (int i = 0; i < n; i++) {
        if (y[i] == 0) {
            sum_x_0 += x[i];
            n_0 += 1;
        } else if (y[i] == 1) {
            sum_x_1 += x[i];
            n_1 += 1;
        }

        sum_squared_x += pow(x[i], 2);
        sum_y += y[i];
        sum_squared_y += pow(y[i], 2);
    }

    // Calcular medias
    double mean_x_0 = sum_x_0 / n_0;
    double mean_x_1 = sum_x_1 / n_1;
    double mean_y = sum_y / n;
    
    // Calcular el coeficiente de correlación puntual biserial
    double numerator = (mean_x_1 - mean_x_0);
    double denominator = sqrt((sum_squared_x - (pow(sum_x_1, 2) / n_1) - (pow(sum_x_0, 2) / n_0) + (pow((sum_x_1 + sum_x_0), 2) / n)));
    
    double r_pb = numerator / denominator;

    return r_pb;
}

int main() {
    // Ejemplo de uso con arreglos
    float x[] = {1.2, 2.3, 3.1, 4.0, 5.5};
    int y[] = {0, 1, 0, 1, 0};
    int n = sizeof(x) / sizeof(x[0]);

    double r_pb = correlacion_puntual_biserial(x, y, n);
    printf("Coeficiente de correlacion puntual biserial: %lf\n", r_pb);

    return 0;
}
import math

def correlacion_puntual_biserial(x, y):
    sum_x_0 = 0.0
    sum_x_1 = 0.0
    sum_squared_x = 0.0
    sum_y = 0.0
    sum_squared_y = 0.0
    n_0 = 0
    n_1 = 0

    # Calcular sumas necesarias
    for i in range(len(x)):
        if y[i] == 0:
            sum_x_0 += x[i]
            n_0 += 1
        elif y[i] == 1:
            sum_x_1 += x[i]
            n_1 += 1

        sum_squared_x += x[i]**2
        sum_y += y[i]
        sum_squared_y += y[i]**2

    # Calcular medias
    mean_x_0 = sum_x_0 / n_0
    mean_x_1 = sum_x_1 / n_1
    mean_y = sum_y / len(y)

    # Calcular el coeficiente de correlación puntual biserial
    numerator = (mean_x_1 - mean_x_0)
    denominator = math.sqrt((sum_squared_x - (sum_x_1**2 / n_1) - (sum_x_0**2 / n_0) + ((sum_x_1 + sum_x_0)**2 / len(x))))

    r_pb = numerator / denominator

    return r_pb

# Ejemplo de uso con listas
x = [1.2, 2.3, 3.1, 4.0, 5.5]
y = [0, 1, 0, 1, 0]

r_pb = correlacion_puntual_biserial(x, y)
print(f"Coeficiente de correlacion puntual biserial: {r_pb}")
