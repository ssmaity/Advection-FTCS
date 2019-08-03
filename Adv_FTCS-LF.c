#include <stdio.h>
#include <math.h>

#define xmin 0.0
#define	xmax 1.0

#define	tmin 0.0
#define tmax 0.5

#define Nx 100
#define Nt 50

double init(double x)
{
	return exp(-200*pow((x - 0.25), 2));
}

double exact(double x, double t, double c)
{
	return exp(-200*pow((x - 0.25 - c*t), 2));
}

int main()
{
	double u[Nx+1][Nt+1];
	double dx = (xmax - xmin)/Nx;
	double dt = (tmax - tmin)/Nt;
	
	int i, j;
	double c = 0.9;
	double CFL = c*dt/dx;
	
	for (i=0; i<=Nt; i++)
	{
		u[0][i] = 0.0;
		u[Nx][i] = 0.0;
	}

	for (i=1; i<Nx; i++)
		u[i][0] = init(i*dx);
	
	for (i=0; i<Nt; i++)
		for (j=1; j<Nx; j++)
			u[j][i+1] = 0.5*(1 + CFL)*u[j-1][i] + 0.5*(1 - CFL)*u[j+1][i];
	
	for (i=0; i<=Nt; i++)
	{
		for (j=0; j<=Nx; j++)
			printf("%lf\t%lf\t%lf\n", j*dx, u[j][i], exact(j*dx, i*dt, c));
		printf("\n\n");
	}
	
	return 0;
}
