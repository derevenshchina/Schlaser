/******************************* Schlaser Header ******************************
Purpose: 
   Compute the strike water temperature needed to raise the mash temperature
Reference:
   Add ref
Programmers:
   E. Kent Golding -- Oct 2011 -- Initial Implementation
******************************************************************************/

#include <stdio.h>
#include <math.h>

/* Following D. Carey's method from the 1988 AHA conference: Aa + Bb + Cc */

int main()
{

double heat_capacity[2];   /* Heat Capacity */
double amount[2];          /* Amount of stuff: grist in lbm, water in gal */
double specific_heat[3];   /* Specific heat*/
double temp[3];            /* temperatures: we are solving for temp[1] */


heat_capacity[0] = 0.05; /* correct relative value for barley malt; it is not *
                            exactly correct for flaked grains but it is close *
                            enough. */
heat_capacity[1] = 1.0;  /* correct relative value for water */
printf("Input the mass of grist in lbm: ");
scanf("%lf", &amount[0]);
printf("Input the volume of strike water in gal: ");
scanf("%lf", &amount[1]);
specific_heat[0] = heat_capacity[0] * amount[0];
specific_heat[1] = heat_capacity[1] * amount[1];
specific_heat[2] = specific_heat[0] + specific_heat[1]; /* always true */
printf("Input the temperature of the grist: ");
scanf("%lf", &temp[0]);
printf("Input the target mash temperature: ");
scanf("%lf", &temp[2]);

//printf("h0 = %f\nh1 = %f\n\n", heat_capacity[0], heat_capacity[1]);
//printf("a0 = %f\na1 = %f\n\n", amount[0], amount[1]);
//printf("C0 = %f\nC1 = %f\nC2 = %f\n\n", specific_heat[0], specific_heat[1],
//   specific_heat[2]);

temp[1] = ((temp[2]*specific_heat[2]) - (temp[0]*specific_heat[0])) / 
   specific_heat[1];

printf("Use %.2f gallons of strike water at %.2f F\n\n", amount[1], temp[1]);

return 0;
}
