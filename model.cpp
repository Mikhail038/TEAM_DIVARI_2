#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "radioactivity.h"

double
model(double *radioactivity, double *time, int N, double point)
{
        assert(radioactivity);
        assert(time);

        // Value of the equation in given point.
        double ret = 0;

        for (int i = 0; i < N; i++) {
                ret += time[i] * exp(-time[i]/point) * 
                       (radioactivity[i] - exp(-time[i]/point));
        }

        return ret;
}

double
nonlinear_equation(double *radioactivity, double *time, 
                   int N, double precision)
{
        assert(radioactivity);
        assert(time);

        // Variable to find.
        double decay_time = 0;

        // Get interval.
        double t1 = 0;
        double t2 = 0;

        printf("Enter the interval:\n");
        printf(" $ ");
        scanf("%lf", &t1);
        printf(" $ ");
        scanf("%lf", &t2);

        while (fabs(t1 - t2) > precision) {
                decay_time = (t1 + t2) / 2;
                if (model(radioactivity, time, N, t1) * model(radioactivity, time, N, decay_time) < 0)
                        t2 = decay_time;
                else 
                        t1 = decay_time;
        }

        return decay_time;
}

double 
linear_equation (double *radioactivity, double *time, int N)
{
        assert(radioactivity);
        assert(time);

        // Return value.
        double decay_rate = 0;

        // Numerator.
        double numer = 0;
        // Denominator.
        double denom = 0;

        for (int i = 0; i < N; i++) {
                numer += time[i];
                denom += time[i] * (1 - radioactivity[i]);
        }

        decay_rate = numer / denom;

        return decay_rate;
}

