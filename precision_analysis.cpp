#include "radioactivity.h"
#include <assert.h>
#include <math.h>

const int INITIAL_SIZE = 10;
const double precision = 1e-3;

double precision_analysis(double *radioactivity, double *time, int N)
{
    assert(radioactivity);
    assert(time);

    int current_N = INITIAL_SIZE;

    double decay_time = NAN;
    double decay_rate = NAN;

    double deviation_exp = NAN;
    double deviation_lin = NAN;

    do
    {
        decay_time = nonlinear_equation(radioactivity, time, current_N, precision);
        decay_rate = linear_equation(radioactivity, time, current_N);

        deviation_exp = dev_exp(radioactivity, time, current_N, decay_time);
        deviation_lin = dev_linear(radioactivity, time, current_N, decay_rate);

        current_N++;
    } while(current_N <= N && deviation_exp / deviation_lin < 2);

    return time[current_N - 1];
}

double dev_exp(double *radioactivity, double *time, int M, double decay_time)
{
    assert(radioactivity);
    assert(time);

    double sum = NAN;

    for(int i = 0; i < M; i++)
    {
        double num = radioactivity[i] - exp(-time[i]/decay_time);

        sum += num*num;
    }

    double ans = sqrt(sum)/M;

    return ans;
}

double dev_linear(double *radioactivity, double *time, int M, double decay_rate)
{
    assert(radioactivity);
    assert(time);

    double sum = NAN;

    for(int i = 0; i < M; i++)
    {
        double num = radioactivity[i] - (1 - time[i]/decay_rate);

        sum += num*num;
    }

    double ans = sqrt(sum)/M;

    return ans;
}
