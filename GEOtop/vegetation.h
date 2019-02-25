
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


void Tcanopy(long r, long c, double Tv0, double Tg, double Qg, double dQgdT, double Tg0, double Qg0, double Ta, double Qa, 
	double zmu, double zmT, double z0, double z0s, double d0, double z0r, double hveg, double v, double LR, double P, 
	double SW, double SWv, double LW, double e, double LSAI, double decaycoeff0, double *land, double Wcrn0, double Wcrnmax, 
	double Wcsn0, double Wcsnmax, double *dWcrn, double *dWcsn, double *LWv, double *LWg, double *Hv, double *Hg, 
	double *dHgdT, double *LEv, double *Eg, double *dEgdT, double *Ts, double *Qs, double *froot, double *theta, 
	DOUBLEVECTOR *soil_transp_layer, double *Lobukhov, PAR *par, long n, double *rh, double *rv, double *rc, double *rb, 
	double *r_uc, double *u_top, double *Etrans, double *Tv, double *Qv, double *decay, double *Locc,
	double *LWup_above_v, double psi, double **soil, double *T, DOUBLEVECTOR *soil_evap_layer);
	
void canopy_fluxes(long r, long c, double Tv, double Tg, double Ta, double Qgsat, double Qa, double zmu, double zmT, double z0, 
	double z0s, double d0, double z0r, double hveg, double v, double LR, double P, double SW, double LW, double e, double LSAI, 
	double decaycoeff0, double *land, double Wcrn, double Wcrnmax, double Wcsn, double Wcsnmax, double *Esubl, double *Etrans,
	double *LWv, double *LWg, double *H, double *LE, double *h, double *dhdT, double *Ts, double *Qs, double *r_uc, 
	double *froot, double *theta, DOUBLEVECTOR *soil_transp_layer, long chgsgn, double *Lobukhov, PAR *par, long n, double *rh, 
	double *rv, double *rc, double *rb, double *u_top, double *decay, double *Locc, double *LWup_above_v, double psi, 
	double **soil, double *alpha, double *beta, double *T, DOUBLEVECTOR *soil_evap_layer);
	
void shortwave_vegetation(double Sd, double Sb, double x, double fwsn, double wsn, double Bsnd, double Bsnb, double Agd, 
	double Agb, double C, double R, double T, double L, double *Sv, double *Sg, double *Sup_above);

void longwave_vegetation(double Lin, double eg, double Tg, double Tv, double L, double *Lv, double *Lg, double *dLv_dTv, double *Lup_above);

void canopy_rain_interception(double rain_max_loading, double LSAI, double Prain, double *max_storage, double *storage, double *drip);

void canopy_snow_interception(double snow_max_loading, double LSAI, double Psnow, double Tc, double v, double Dt, double *max_storage, double *storage, double *drip);

void update_roughness_veg(double hc, double snowD, double zmu, double zmt, double *z0_ris, double *d0_ris, double *hc_ris);

void root(long n, double d, double slope, double *D, double *root_fraction);

void canopy_evapotranspiration(double rbv, double Tv, double Qa, double Pa, double SWin, double *theta, double *land, double **soil, double *root, double *f, DOUBLEVECTOR *fl);

void veg_transmittance(long r, long c, double rm, double v, double Ts, double Tg, double z0soil, double LSAI, double decaycoeff0, 
	double z0veg, double d0veg, double Hveg, double u_top, double Lo, double *rb, double *rh, double *ra, double *decay, double Loc,
	short stabcorr_incanopy);