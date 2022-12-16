#include "radioactivity.h"
#include <stdio.h>
#include <assert.h>
#include <math.h>

const int INITIAL_SIZE = 10;
const double MAX_PRECISION_RATIO = 2;

double 
precision_analysis(double *radioactivity, double *time, int N)
{
         
        assert(radioactivity);
        assert(time);

        int current_N = INITIAL_SIZE;

        double decay_time = nonlinear_equation(radioactivity, time, N, PRECISION);
        double decay_rate = linear_equation(radioactivity, time, N);

        printf("decay time: %.5lf +- 0.5\n"
               "decay rate: %.5lf += 0.5\n", decay_time, decay_rate);

        int i = INITIAL_SIZE;
        while (dev_linear(radioactivity, time, i, decay_rate) > 
               2 * dev_exp(radioactivity, time, i, decay_time)) {
                i++;
        }

        return i;
}

double 
dev_linear(double *radioactivity, double *time, int M, double decay_rate) 
{
        double sum_res = 0;
        for (int i = 0; i < M; i++) {
                sum_res += radioactivity[i] - (1 - time[i]/decay_rate); 
        }
        return sqrt(sum_res) / M;
}

double 
dev_exp(double *radioactivity, double *time, int M, double decay_time)
{
        double sum_res = 0;
        for (int i = 0; i < M; i++) {
                sum_res += radioactivity[i] - exp(-time[i]/decay_time); 
        }
        return sqrt(sum_res) / M;
}

