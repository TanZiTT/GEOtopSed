
/* STATEMENT:
 
 GEOtop MODELS THE ENERGY AND WATER FLUXES AT THE LAND SURFACE
 GEOtop 1.0 Public - Version "Montebello" - Update 2 (29 April 2010)
 
 Copyright (c), 2010 - Stefano Endrizzi and Riccardo Rigon
 
 This file is part of GEOtop 1.0 Public
 
 GEOtop 1.0 Public is a free software and is distributed under GNU General Public License v. 3.0 <http://www.gnu.org/licenses/>
 WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE
 
 GEOtop 1.0 Public is distributed as a free software in the hope to create and support a community of developers and users that constructively interact.
 If you just use the code, please give feedback to the authors and the community at the following E-mail address: geotopusers@googlegroups.com to which you can subscribe at  http://groups.google.com/group/geotopusers/
 Any way you use the model, may be the most trivial one, is significantly helpful for the future development of the GEOtop model. Any feedback will be highly appreciated.
 
 If you have satisfactorily used the code, please acknowledge the authors
 
 */



void aero_resistance(double zmu, double zmt, double z0, double d0, double z0_z0t, double v, double Ta, double T, double Qa, double Q, double P, double gmT, 
	double *Lobukhov, double *rm, double *rh, double *rv, short state_turb, short MO, long maxiter);
	
void aero_resistance2(double zmu, double zmt, double z0, double d0, double z0_z0t, double hveg, double v, double Ta, double T, double Qa, double Q, double P, 
	double gmT, double LSAI, double *rm, double *rh, double *rv, double *u_top, double *Lobukhov, short state_turb, short MO, long maxiter);

void turbulent_fluxes(double rh, double rv, double P, double Ta, double T, double Qa, double Q, double dQdT, double *H, double *dHdT, double *E, double *dEdT);

double Psim(double z);

double Psih(double z);

double Zero(double z);

double PsiStab(double z);

void Lewis(double zmu, double zmt, double d0, double z0, double z0_z0t, double Ta, double Ts, double v, double *rm, double *rh, double *rv, DOUBLEVECTOR *w);

double cz(double zmeas, double z0, double d0, double L, double (* unstab)(double z), double (* stab)(double z));

double CZ(short state, double zmeas, double z0, double d0, double L, double (*Psi)(double z));

void Star(short a, double zmeas, double z0, double d0, double L, double u, double delta, double M, double N, double R, double *var, double *c, double *z0v,
	double (*Psi)(double z), double (*roughness)(double x, double y, double z) );
	
double roughT(double M, double N, double R);

double roughQ(double M, double N, double R);

void Businger(short a, double zmu, double zmt, double d0, double z0, double v, double T, double DT, double DQ, double z0_z0t, double *rm, double *rh, 
			  double *rv, double *Lobukhov, long maxiter);

double Levap(double T);

double latent(double Ts, double Le);

void find_actual_evaporation_parameters(long R, long C, double *alpha, double *beta, DOUBLEVECTOR *evap_layer, double *theta, 
				double **soil, double *T, double psi, double P, double rv, double Ta, double Qa, double Qgsat, long nsnow);
