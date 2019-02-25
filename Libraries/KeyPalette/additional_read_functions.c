
/* KeyPalette MANAGES  THE I/O FILES  OF A MODEL
KeyPalette Version 0.9375 KMackenzie

file additional_read_functions.c

Copyright (c), 2009 Emanuele Cordano and Riccardo Rigon

This file is part of KeyPalette.
 KeyPalette is free software: you can redistribute it and/or modify
    it under the terms of the GNU  General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    KeyPalette is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License v. 3.0 for more details.

    You should have received a copy of the GNU  General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/



#include <stdio.h>
#include "turtle.h"
#include "additional_read_functions.h"
#include <stddef.h>
#include <string.h>



DOUBLEVECTOR *read_doublearray_from_string(char *argument,char *delimiters,int max_numbers,short print){
	/*
	 *
	 * \author Emanuele Cordano
	 * \date September 2008
	 *
	 *\param (char *) - argument string from which read the values
	 *\param (char *) - delimiters charcters between two values
	 *\param (char *) - maximum numbers of vales which can be read
	 *
	 *\returns (DOUBLEVECTOR *) - a vector containing the read values (double)
	 *
	 */
	int s,l,i;
	DOUBLEVECTOR *vect;
    DOUBLEVECTOR *vect1;
    double value;
    char *cp,*token;

    vect1=new_doublevector(max_numbers);
    l=0;
    value=-999.0;
 //   printf("\n cc\n ");
    cp=strdup(argument);
    token=strtok(cp,delimiters);
    do{
    	l++;
    	value=-999.0;

    	 /* see http://www.gnu.org/software/libtool/manual/libc/Finding-Tokens-in-a-String.html
    	  * */
		s=0;
		s=sscanf(token,"%lf",&value);
    	if (s==1) {
   		vect1->co[l]=value;
    	} else if (s==0 && print==1) {
			printf("\nWARNING: No real value found for %s option, no value is set at location %d  ",token,l);
    	}
    	token=strtok(NULL,delimiters);
    } while ((s==1) &&  (l<=max_numbers) );

    l=l-1;
    vect=new_doublevector(l);

    for(i=vect->nl;i<=vect->nh;i++){

    	vect->co[i]=vect1->co[i];
    }

    free_doublevector(vect1);

    return vect;

}

/* */


LONGVECTOR *read_longarray_from_string(char *argument,char *delimiters,int max_numbers,short print){
	/*
	 *
	 * \author Emanuele Cordano
	 * \date November 2008
	 *
	 *\param (char *) - argument string from which read the values
	 *\param (char *) - delimiters charcters between two values
	 *\param (char *) - maximum numbers of vales which can be read
	 *
	 *\returns (LONGVECTOR *) - a vector containing the long integer values (long)
	 *
	 */
	int s,l,i;
	LONGVECTOR *vect;
    LONGVECTOR *vect1;
    long value;
    char *cp,*token;

    vect1=new_longvector(max_numbers);
    l=0;
    value=-999;

    cp=strdup(argument);
    token=strtok(cp,delimiters);
    do{
    	l++;
    	value=-999;

    	 /* see http://www.gnu.org/software/libtool/manual/libc/Finding-Tokens-in-a-String.html
    	  * */
		s=0;
		s=sscanf(token,"%ld",&value);
    	if (s==1) {
   		vect1->co[l]=value;
    	} else if (s==0 && print==1) {
			printf("\nWARNING: No integer value found for %s option, no value is set at location %d  ",token,l);
    	}
    	token=strtok(NULL,delimiters);
    } while ((s==1) &&  (l<=max_numbers) );

    l=l-1;
    vect=new_longvector(l);

    for(i=vect->nl;i<=vect->nh;i++){

    	vect->co[i]=vect1->co[i];
    }

    free_longvector(vect1);

    return vect;

}

