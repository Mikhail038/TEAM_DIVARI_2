//==============================================================================================================================================================================
//MAIN HEADER FILE
//==============================================================================================================================================================================

int experiment (double *radioactivity, double *time, double start_time, double end_time, double step); // returns N

void add_noise (double *radioactivity, int N);

//==============================================================================================================================================================================

double model (double *radioactivity, double *time, int N, double point);

double nonlinear_equation (double *radioactivity, double *time, int N, double precision);

double linear_equation (double *radioactivity, double *time, int N);

//==============================================================================================================================================================================

double precision_analysis (double *radioactivity, double *time, int N);

double dev_exp (double *radioactivity, double *time, int M, double decay_time);

double dev_linear (double *radioactivity, double *time, int M, double decay_rate);

//==============================================================================================================================================================================

