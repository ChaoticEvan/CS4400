/*******************************************
 * Solutions for the CS:APP Performance Lab
 ********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "defs.h"

/* 
 * Please fill in the following student struct 
 */
student_t student = {
  "Evan W. Voordeckers",     /* Full name */
  "evan.voordeckers@yahoo.com",  /* Email address */
};

/***************
 * COMPLEX KERNEL
 ***************/

/******************************************************
 * Your different versions of the complex kernel go here
 ******************************************************/

/* 
 * naive_complex - The naive baseline version of complex 
 */
char naive_complex_descr[] = "naive_complex: Naive baseline implementation";
void naive_complex(int dim, pixel *src, pixel *dest)
{
  int i, j;

  for(i = 0; i < dim; i++)
    for(j = 0; j < dim; j++)
    {

      dest[RIDX(dim - j - 1, dim - i - 1, dim)].red = ((int)src[RIDX(i, j, dim)].red +
						      (int)src[RIDX(i, j, dim)].green +
						      (int)src[RIDX(i, j, dim)].blue) / 3;
      
      dest[RIDX(dim - j - 1, dim - i - 1, dim)].green = ((int)src[RIDX(i, j, dim)].red +
							(int)src[RIDX(i, j, dim)].green +
							(int)src[RIDX(i, j, dim)].blue) / 3;
      
      dest[RIDX(dim - j - 1, dim - i - 1, dim)].blue = ((int)src[RIDX(i, j, dim)].red +
						       (int)src[RIDX(i, j, dim)].green +
						       (int)src[RIDX(i, j, dim)].blue) / 3;

    }
}

// char complex_unrollJ2_descr[] = "complex_unrollJ2: Unroll j+=2";
// void complex_unrollJ2(int dim, pixel *src, pixel *dest)
// {
//   int i, j;

//   for(i = 0; i < dim; i++)
//     for(j = 0; j < dim; j+=2)
//     {
//       dest[RIDX(dim - j - 1, dim - i - 1, dim)].red = ((int)src[RIDX(i, j, dim)].red +
// 							(int)src[RIDX(i, j, dim)].green +
// 							(int)src[RIDX(i, j, dim)].blue) / 3;
      
//       dest[RIDX(dim - j - 1, dim - i - 1, dim)].green = ((int)src[RIDX(i, j, dim)].red +
// 							(int)src[RIDX(i, j, dim)].green +
// 							(int)src[RIDX(i, j, dim)].blue) / 3;
      
//       dest[RIDX(dim - j - 1, dim - i - 1, dim)].blue = ((int)src[RIDX(i, j, dim)].red +
// 							(int)src[RIDX(i, j, dim)].green +
// 							(int)src[RIDX(i, j, dim)].blue) / 3;


//       // Second half of unroll
//       dest[RIDX(dim - (j+1) - 1, dim - i - 1, dim)].red = ((int)src[RIDX(i, (j+1), dim)].red +
// 						      (int)src[RIDX(i, (j+1), dim)].green +
// 						      (int)src[RIDX(i, (j+1), dim)].blue) / 3;
      
//       dest[RIDX(dim - (j+1) - 1, dim - i - 1, dim)].green = ((int)src[RIDX(i, (j+1), dim)].red +
// 							(int)src[RIDX(i, (j+1), dim)].green +
// 							(int)src[RIDX(i, (j+1), dim)].blue) / 3;
      
//       dest[RIDX(dim - (j+1) - 1, dim - i - 1, dim)].blue = ((int)src[RIDX(i, (j+1), dim)].red +
// 							(int)src[RIDX(i, (j+1), dim)].green +
// 							(int)src[RIDX(i, (j+1), dim)].blue) / 3;
//     }
// }

// char complex_unrollI2_descr[] = "complex_unrollI2: Unroll i+=2";
// void complex_unrollI2(int dim, pixel *src, pixel *dest)
// {
//   int i, j;

//   for(i = 0; i < dim; i+=2)
// 	{
//     for(j = 0; j < dim; j++)
//     {
//       dest[RIDX(dim - j - 1, dim - i - 1, dim)].red = ((int)src[RIDX(i, j, dim)].red +
// 							(int)src[RIDX(i, j, dim)].green +
// 							(int)src[RIDX(i, j, dim)].blue) / 3;
      
//       dest[RIDX(dim - j - 1, dim - i - 1, dim)].green = ((int)src[RIDX(i, j, dim)].red +
// 							(int)src[RIDX(i, j, dim)].green +
// 							(int)src[RIDX(i, j, dim)].blue) / 3;
      
//       dest[RIDX(dim - j - 1, dim - i - 1, dim)].blue = ((int)src[RIDX(i, j, dim)].red +
// 							(int)src[RIDX(i, j, dim)].green +
// 							(int)src[RIDX(i, j, dim)].blue) / 3;


//       // Second half of unroll
//       dest[RIDX(dim - j - 1, dim - (i+1) - 1, dim)].red = ((int)src[RIDX((i+1), j, dim)].red +
// 						      (int)src[RIDX((i+1), j, dim)].green +
// 						      (int)src[RIDX((i+1), j, dim)].blue) / 3;
      
//       dest[RIDX(dim - j - 1, dim - (i+1) - 1, dim)].green = ((int)src[RIDX((i+1), j, dim)].red +
// 							(int)src[RIDX((i+1), j, dim)].green +
// 							(int)src[RIDX((i+1), j, dim)].blue) / 3;
      
//       dest[RIDX(dim - j - 1, dim - (i+1) - 1, dim)].blue = ((int)src[RIDX((i+1), j, dim)].red +
// 							(int)src[RIDX((i+1), j, dim)].green +
// 							(int)src[RIDX((i+1), j, dim)].blue) / 3;
//     }
// 	}
// }

// char complex_unrollJ2I2_descr[] = "complex_unrollJ2I2: Unroll i+=2 j+=2";
// void complex_unrollJ2I2(int dim, pixel *src, pixel *dest)
// {
//   int i, j;

//   for(i = 0; i < dim; i+=2)
// 	{
//     for(j = 0; j < dim; j+=2)
//     {
//       dest[RIDX(dim - j - 1, dim - i - 1, dim)].red = ((int)src[RIDX(i, j, dim)].red +
// 							(int)src[RIDX(i, j, dim)].green +
// 							(int)src[RIDX(i, j, dim)].blue) / 3;
      
//       dest[RIDX(dim - j - 1, dim - i - 1, dim)].green = ((int)src[RIDX(i, j, dim)].red +
// 							(int)src[RIDX(i, j, dim)].green +
// 							(int)src[RIDX(i, j, dim)].blue) / 3;
      
//       dest[RIDX(dim - j - 1, dim - i - 1, dim)].blue = ((int)src[RIDX(i, j, dim)].red +
// 							(int)src[RIDX(i, j, dim)].green +
// 							(int)src[RIDX(i, j, dim)].blue) / 3;


//       // (i+1, j)
//       dest[RIDX(dim - j - 1, dim - (i+1) - 1, dim)].red = ((int)src[RIDX((i+1), j, dim)].red +
// 						      (int)src[RIDX((i+1), j, dim)].green +
// 						      (int)src[RIDX((i+1), j, dim)].blue) / 3;
      
//       dest[RIDX(dim - j - 1, dim - (i+1) - 1, dim)].green = ((int)src[RIDX((i+1), j, dim)].red +
// 							(int)src[RIDX((i+1), j, dim)].green +
// 							(int)src[RIDX((i+1), j, dim)].blue) / 3;
      
//       dest[RIDX(dim - j - 1, dim - (i+1) - 1, dim)].blue = ((int)src[RIDX((i+1), j, dim)].red +
// 							(int)src[RIDX((i+1), j, dim)].green +
// 							(int)src[RIDX((i+1), j, dim)].blue) / 3;

//       // (i, j+1)
//       dest[RIDX(dim - (j+1) - 1, dim - i - 1, dim)].red = ((int)src[RIDX(i, (j+1), dim)].red +
// 						      (int)src[RIDX(i, (j+1), dim)].green +
// 						      (int)src[RIDX(i, (j+1), dim)].blue) / 3;
      
//       dest[RIDX(dim - (j+1) - 1, dim - i - 1, dim)].green = ((int)src[RIDX(i, (j+1), dim)].red +
// 							(int)src[RIDX(i, (j+1), dim)].green +
// 							(int)src[RIDX(i, (j+1), dim)].blue) / 3;
      
//       dest[RIDX(dim - (j+1) - 1, dim - i - 1, dim)].blue = ((int)src[RIDX(i, (j+1), dim)].red +
// 							(int)src[RIDX(i, (j+1), dim)].green +
// 							(int)src[RIDX(i, (j+1), dim)].blue) / 3;

// 			// (i+1, j+1)
//       dest[RIDX(dim - (j+1) - 1, dim - (i+1) - 1, dim)].red = ((int)src[RIDX((i+1), (j+1), dim)].red +
// 						      (int)src[RIDX((i+1), (j+1), dim)].green +
// 						      (int)src[RIDX((i+1), (j+1), dim)].blue) / 3;
      
//       dest[RIDX(dim - (j+1) - 1, dim - (i+1) - 1, dim)].green = ((int)src[RIDX((i+1), (j+1), dim)].red +
// 							(int)src[RIDX((i+1), (j+1), dim)].green +
// 							(int)src[RIDX((i+1), (j+1), dim)].blue) / 3;
      
//       dest[RIDX(dim - (j+1) - 1, dim - (i+1) - 1, dim)].blue = ((int)src[RIDX((i+1), (j+1), dim)].red +
// 							(int)src[RIDX((i+1), (j+1), dim)].green +
// 							(int)src[RIDX((i+1), (j+1), dim)].blue) / 3;
//     }
// 	}
// }

// char complex_unrollJ2I2_CSE_descr[] = "complex_unrollJ2I2_CSE: Unroll i+=2 j+=2 w/ CSE";
// void complex_unrollJ2I2_CSE(int dim, pixel *src, pixel *dest)
// {
//   int i, j, dimCalc, srcDimCalc;

//   for(i = 0; i < dim; i+=2)
// 	{
//     for(j = 0; j < dim; j+=2)
//     {
// 			dimCalc = ((dim - j - 1) * (dim) + (dim - i - 1));
// 			srcDimCalc = ((i)*(dim)+(j));
//       dest[dimCalc].red = ((int)src[srcDimCalc].red +
// 							(int)src[srcDimCalc].green +
// 							(int)src[srcDimCalc].blue) / 3;
      
//       dest[dimCalc].green = ((int)src[srcDimCalc].red +
// 							(int)src[srcDimCalc].green +
// 							(int)src[srcDimCalc].blue) / 3;
      
//       dest[dimCalc].blue = ((int)src[srcDimCalc].red +
// 							(int)src[srcDimCalc].green +
// 							(int)src[srcDimCalc].blue) / 3;


//       // (i+1, j)
//       dest[dimCalc - 1].red = ((int)src[srcDimCalc + dim].red +
// 						      (int)src[srcDimCalc + dim].green +
// 						      (int)src[srcDimCalc + dim].blue) / 3;
      
//       dest[dimCalc - 1].green = ((int)src[srcDimCalc + dim].red +
// 							(int)src[srcDimCalc + dim].green +
// 							(int)src[srcDimCalc + dim].blue) / 3;
      
//       dest[dimCalc - 1].blue = ((int)src[srcDimCalc + dim].red +
// 							(int)src[srcDimCalc + dim].green +
// 							(int)src[srcDimCalc + dim].blue) / 3;

//       // (i, j+1)
//       dest[dimCalc - dim].red = ((int)src[srcDimCalc + 1].red +
// 						      (int)src[srcDimCalc + 1].green +
// 						      (int)src[srcDimCalc + 1].blue) / 3;
      
//       dest[dimCalc - dim].green = ((int)src[srcDimCalc + 1].red +
// 							(int)src[srcDimCalc + 1].green +
// 							(int)src[srcDimCalc + 1].blue) / 3;
      
//       dest[dimCalc - dim].blue = ((int)src[srcDimCalc + 1].red +
// 							(int)src[srcDimCalc + 1].green +
// 							(int)src[srcDimCalc + 1].blue) / 3;

// 			// (i+1, j+1)
//       dest[dimCalc - dim - 1].red = ((int)src[srcDimCalc + dim + 1].red +
// 						      (int)src[srcDimCalc + dim + 1].green +
// 						      (int)src[srcDimCalc + dim + 1].blue) / 3;
      
//       dest[dimCalc - dim - 1].green = ((int)src[srcDimCalc + dim + 1].red +
// 							(int)src[srcDimCalc + dim + 1].green +
// 							(int)src[srcDimCalc + dim + 1].blue) / 3;
      
//       dest[dimCalc - dim - 1].blue = ((int)src[srcDimCalc + dim + 1].red +
// 							(int)src[srcDimCalc + dim + 1].green +
// 							(int)src[srcDimCalc + dim + 1].blue) / 3;
//     }
// 	}
// }

// char complex_unrollJ2I2_CSE2_descr[] = "complex_unrollJ2I2_CSE2: Unroll i+=2 j+=2 w/ CSE #2";
// void complex_unrollJ2I2_CSE2(int dim, pixel *src, pixel *dest)
// {
//   int i, j, dimCalc, srcDimCalc, tempRes;

//   for(i = 0; i < dim; i+=2)
// 	{
//     for(j = 0; j < dim; j+=2)
//     {
// 			dimCalc = ((dim - j - 1) * (dim) + (dim - i - 1));
// 			srcDimCalc = ((i)*(dim)+(j));

// 			tempRes = ((int)src[srcDimCalc].red +
// 							(int)src[srcDimCalc].green +
// 							(int)src[srcDimCalc].blue) / 3;
//       dest[dimCalc].red = tempRes;      
//       dest[dimCalc].green = tempRes;      
//       dest[dimCalc].blue = tempRes;

//       // (i+1, j)
// 			tempRes = ((int)src[srcDimCalc + dim].red +
// 						      (int)src[srcDimCalc + dim].green +
// 						      (int)src[srcDimCalc + dim].blue) / 3;
//       dest[dimCalc - 1].red = tempRes;      
//       dest[dimCalc - 1].green = tempRes;      
//       dest[dimCalc - 1].blue = tempRes;

//       // (i, j+1)
// 			tempRes = ((int)src[srcDimCalc + 1].red +
// 						      (int)src[srcDimCalc + 1].green +
// 						      (int)src[srcDimCalc + 1].blue) / 3;
//       dest[dimCalc - dim].red = tempRes;    
//       dest[dimCalc - dim].green = tempRes;      
//       dest[dimCalc - dim].blue = tempRes;

// 			// (i+1, j+1)
// 			tempRes = ((int)src[srcDimCalc + dim + 1].red +
// 						      (int)src[srcDimCalc + dim + 1].green +
// 						      (int)src[srcDimCalc + dim + 1].blue) / 3;
//       dest[dimCalc - dim - 1].red = tempRes;      
//       dest[dimCalc - dim - 1].green = tempRes;      
//       dest[dimCalc - dim - 1].blue = tempRes;
//     }
// 	}
// }

// char complex_unrollJI4_descr[] = "complex_unrollJI4: Unroll i+=4 j+=4 w/ CSE";
// void complex_unrollJI4(int dim, pixel *src, pixel *dest)
// {
//   int i, j, dimCalc, srcDimCalc, tempRes;

//   for(i = 0; i < dim; i+=4)
// 	{
//     for(j = 0; j < dim; j++)
//     {
// 			dimCalc = ((dim - j - 1) * (dim) + (dim - i - 1));
// 			srcDimCalc = ((i)*(dim)+(j));

//       // (i, j)
// 			tempRes = ((int)src[srcDimCalc].red +
// 							(int)src[srcDimCalc].green +
// 							(int)src[srcDimCalc].blue) / 3;
//       dest[dimCalc].red = tempRes;      
//       dest[dimCalc].green = tempRes;      
//       dest[dimCalc].blue = tempRes;
//       // (i+1, j)
// 			tempRes = ((int)src[srcDimCalc + dim].red +
// 						      (int)src[srcDimCalc + dim].green +
// 						      (int)src[srcDimCalc + dim].blue) / 3;
//       dest[dimCalc - 1].red = tempRes;      
//       dest[dimCalc - 1].green = tempRes;      
//       dest[dimCalc - 1].blue = tempRes;
// 			// (i+2, j)
// 			tempRes = ((int)src[srcDimCalc + (2*dim)].red +
// 						      (int)src[srcDimCalc + (2*dim)].green +
// 						      (int)src[srcDimCalc + (2*dim)].blue) / 3;
//       dest[dimCalc - 2].red = tempRes;      
//       dest[dimCalc - 2].green = tempRes;      
//       dest[dimCalc - 2].blue = tempRes;
// 			// (i+3, j)
// 			tempRes = ((int)src[srcDimCalc + (3*dim)].red +
// 						      (int)src[srcDimCalc + (3*dim)].green +
// 						      (int)src[srcDimCalc + (3*dim)].blue) / 3;
//       dest[dimCalc - 3].red = tempRes;      
//       dest[dimCalc - 3].green = tempRes;      
//       dest[dimCalc - 3].blue = tempRes;

//     }
// 	}
// }

/* 
 * complex - Your current working version of complex
 * IMPORTANT: This is the version you will be graded on
 */
char complex_descr[] = "complex: Current working version";
void complex(int dim, pixel *src, pixel *dest)
	{
		int i, j, dimCalc, srcDimCalc, tempRes;

		for(i = 0; i < dim; i+=4)
		{
			for(j = 0; j < dim; j++)
			{
				dimCalc = ((dim - j - 1) * (dim) + (dim - i - 1));
				srcDimCalc = ((i)*(dim)+(j));

				// (i, j)
				tempRes = ((int)src[srcDimCalc].red +
								(int)src[srcDimCalc].green +
								(int)src[srcDimCalc].blue) / 3;
				dest[dimCalc].red = tempRes;      
				dest[dimCalc].green = tempRes;      
				dest[dimCalc].blue = tempRes;
				// (i+1, j)
				tempRes = ((int)src[srcDimCalc + dim].red +
										(int)src[srcDimCalc + dim].green +
										(int)src[srcDimCalc + dim].blue) / 3;
				dest[dimCalc - 1].red = tempRes;      
				dest[dimCalc - 1].green = tempRes;      
				dest[dimCalc - 1].blue = tempRes;
				// (i+2, j)
				tempRes = ((int)src[srcDimCalc + (2*dim)].red +
										(int)src[srcDimCalc + (2*dim)].green +
										(int)src[srcDimCalc + (2*dim)].blue) / 3;
				dest[dimCalc - 2].red = tempRes;      
				dest[dimCalc - 2].green = tempRes;      
				dest[dimCalc - 2].blue = tempRes;
				// (i+3, j)
				tempRes = ((int)src[srcDimCalc + (3*dim)].red +
										(int)src[srcDimCalc + (3*dim)].green +
										(int)src[srcDimCalc + (3*dim)].blue) / 3;
				dest[dimCalc - 3].red = tempRes;      
				dest[dimCalc - 3].green = tempRes;      
				dest[dimCalc - 3].blue = tempRes;

			}
		}
	}



/*********************************************************************
 * register_complex_functions - Register all of your different versions
 *     of the complex kernel with the driver by calling the
 *     add_complex_function() for each test function. When you run the
 *     driver program, it will test and report the performance of each
 *     registered test function.  
 *********************************************************************/

void register_complex_functions() {
  add_complex_function(&complex, complex_descr);
  add_complex_function(&naive_complex, naive_complex_descr);

	// Removed because complex_unrollJ2I2 did both of these
  // add_complex_function(&complex_unrollJ2, complex_unrollJ2_descr);
	// add_complex_function(&complex_unrollI2, complex_unrollI2_descr);

	// With common subexpression elimination the code is much faster
	//add_complex_function(&complex_unrollJ2I2, complex_unrollJ2I2_descr);
	//add_complex_function(&complex_unrollJ2I2_CSE, complex_unrollJ2I2_CSE_descr);

	// Unrolling the loop to j+=4 is giving me an average of 1.7-1.8 on CADE Lab1-27
	//add_complex_function(&complex_unrollJ2I2_CSE2, complex_unrollJ2I2_CSE2_descr);

	// This is method is duplicated in complex()
	//add_complex_function(&complex_unrollJI4, complex_unrollJI4_descr);
}


/***************
 * MOTION KERNEL
 **************/

/***************************************************************
 * Various helper functions for the motion kernel
 * You may modify these or add new ones any way you like.
 **************************************************************/

typedef struct{
  int red;
  int green;
  int blue;
}AvgPixel;

/* 
 * weighted_combo - Returns new pixel value at (i,j) 
 */
static pixel weighted_combo(int dim, int i, int j, pixel *src) 
{
  int ii, jj;
  pixel current_pixel;

  int red, green, blue;
  red = green = blue = 0;

  int num_neighbors = 0;
  for(ii=0; ii < 3; ii++)
    for(jj=0; jj < 3; jj++) 
      if ((i + ii < dim) && (j + jj < dim)) 
      {
		num_neighbors++;
		red += (int) src[RIDX(i+ii,j+jj,dim)].red;
		green += (int) src[RIDX(i+ii,j+jj,dim)].green;
		blue += (int) src[RIDX(i+ii,j+jj,dim)].blue;
      }
  
  current_pixel.red = (unsigned short) (red / num_neighbors);
  current_pixel.green = (unsigned short) (green / num_neighbors);
  current_pixel.blue = (unsigned short) (blue / num_neighbors);
  
  return current_pixel;
}

/******************************************************
 * Your different versions of the motion kernel go here
 ******************************************************/


/*
 * naive_motion - The naive baseline version of motion 
 */
char naive_motion_descr[] = "naive_motion: Naive baseline implementation";
void naive_motion(int dim, pixel *src, pixel *dst) 
{
  int i, j;
    
  for (i = 0; i < dim; i++)
    for (j = 0; j < dim; j++)
      dst[RIDX(i, j, dim)] = weighted_combo(dim, i, j, src);
}



// char unroll_motion_descr[] = "unroll_motion: Uses unrolling";
// void unroll_motion(int dim, pixel *src, pixel *dst) 
// {
// 	int i, j, dimCalc;

// 	for (i = 0; i < dim; i+=4)
// 	{
// 		for (j = 0; j < dim; j+=8)
// 		{
// 			dimCalc = ((i)*(dim)+(j));
// 			dst[dimCalc]= weighted_combo(dim, i, j, src);
// 			dst[dimCalc + dim]= weighted_combo(dim, i+1, j, src);
// 			dst[dimCalc + (2*dim)]= weighted_combo(dim, i+2, j, src);
// 			dst[dimCalc + (3*dim)]= weighted_combo(dim, i+3, j, src);

// 			dst[dimCalc + 1]= weighted_combo(dim, i, j+1, src);
// 			dst[dimCalc + dim + 1]= weighted_combo(dim, i+1, j+1, src);
// 			dst[dimCalc + (2*dim) + 1]= weighted_combo(dim, i+2, j+1, src);
// 			dst[dimCalc + (3*dim) + 1]= weighted_combo(dim, i+3, j+1, src);

// 			dst[dimCalc + 2]= weighted_combo(dim, i, j+2, src);
// 			dst[dimCalc + dim + 2]= weighted_combo(dim, i+1, j+2, src);
// 			dst[dimCalc + (2*dim) + 2]= weighted_combo(dim, i+2, j+2, src);
// 			dst[dimCalc + (3*dim) + 2]= weighted_combo(dim, i+3, j+2, src);

// 			dst[dimCalc + 3]= weighted_combo(dim, i, j+4, src);
// 			dst[dimCalc + dim + 3]= weighted_combo(dim, i+1, j+4, src);
// 			dst[dimCalc + (2*dim) + 3]= weighted_combo(dim, i+2, j+4, src);
// 			dst[dimCalc + (3*dim) + 3]= weighted_combo(dim, i+3, j+4, src);

// 			dst[dimCalc + 3]= weighted_combo(dim, i, j+5, src);
// 			dst[dimCalc + dim + 3]= weighted_combo(dim, i+1, j+5, src);
// 			dst[dimCalc + (2*dim) + 3]= weighted_combo(dim, i+2, j+5, src);
// 			dst[dimCalc + (3*dim) + 3]= weighted_combo(dim, i+3, j+5, src);

// 			dst[dimCalc + 3]= weighted_combo(dim, i, j+6, src);
// 			dst[dimCalc + dim + 3]= weighted_combo(dim, i+1, j+6, src);
// 			dst[dimCalc + (2*dim) + 3]= weighted_combo(dim, i+2, j+6, src);
// 			dst[dimCalc + (3*dim) + 3]= weighted_combo(dim, i+3, j+6, src);

// 			dst[dimCalc + 3]= weighted_combo(dim, i, j+7, src);
// 			dst[dimCalc + dim + 3]= weighted_combo(dim, i+1, j+7, src);
// 			dst[dimCalc + (2*dim) + 3]= weighted_combo(dim, i+2, j+7, src);
// 			dst[dimCalc + (3*dim) + 3]= weighted_combo(dim, i+3, j+7, src);					
// 		}
// 	}
// }

char lab_motion_descr[] = "lab_motion: Uses process from lab";
__attribute__((always_inline)) void lab_motion(int dim, pixel *src, pixel *dst) 
{
  int i,j;
  AvgPixel AvgPixels[3];
  AvgPixel tempAvgPixel;
  pixel tempPixel1, tempPixel2, tempPixel3, tempPixel4;  
  int upper_limit = pow(dim, 2);
  int currIdx = 0;

  // Loop does everything except the last two rows
  for(i = 0; i < dim - 2; i++)
  {
    // Loops over the first row of neighbors for the 
    // current pixel at (i,j)
    for(j = 1; j < 3; j++)
    {
      tempPixel2 = src[currIdx + j  - 1];
      tempPixel3 = src[currIdx + dim + j - 1];
      tempPixel4 = src[currIdx + (2*dim) + j - 1];

      // Add all of these neighbors RGB values to be averaged later
      tempAvgPixel.red = tempPixel2.red + tempPixel3.red + tempPixel4.red;
      tempAvgPixel.green = tempPixel2.green + tempPixel3.green + tempPixel4.green;
      tempAvgPixel.blue = tempPixel2.blue + tempPixel3.blue + tempPixel4.blue;

      AvgPixels[j] = tempAvgPixel;
    }
    for(j = 0; j < dim - 2; j++)
    {
      AvgPixels[0] = AvgPixels[1];
      AvgPixels[1] = AvgPixels[2];

      tempPixel2 = src[currIdx + j + 2];
      tempPixel3 = src[currIdx + dim + j + 2];
      tempPixel4 = src[currIdx + (2*dim) + j + 2];

      tempAvgPixel.red = tempPixel2.red + tempPixel3.red + tempPixel4.red;
      tempAvgPixel.green = tempPixel2.green + tempPixel3.green + tempPixel4.green;
      tempAvgPixel.blue = tempPixel2.blue + tempPixel3.blue + tempPixel4.blue;
      AvgPixels[2] = tempAvgPixel;

      // Get the averaged values from all neighbors
      tempPixel1.red = (AvgPixels[0].red + AvgPixels[1].red + AvgPixels[2].red)/9;
      tempPixel1.green = (AvgPixels[0].green + AvgPixels[1].green + AvgPixels[2].green)/9;
      tempPixel1.blue = (AvgPixels[0].blue + AvgPixels[1].blue + AvgPixels[2].blue)/9;

      dst[currIdx + j] = tempPixel1;
    }

    // Set the last two columns
    tempPixel1.red = (AvgPixels[1].red + AvgPixels[2].red)/6;
    tempPixel1.green = (AvgPixels[1].green + AvgPixels[2].green)/6;
    tempPixel1.blue = (AvgPixels[1].blue + AvgPixels[2].blue)/6;
    dst[currIdx + dim - 2] = tempPixel1;

    tempPixel1.red = AvgPixels[2].red/3;
    tempPixel1.green = AvgPixels[2].green/3;
    tempPixel1.blue = AvgPixels[2].blue/3;
    dst[currIdx + dim - 1] = tempPixel1;

    currIdx += dim;
  }


  for(j = 1; j < 3; j++)
  {
    tempPixel2 = src[upper_limit - (2*dim) + j - 1];
    tempPixel3 = src[upper_limit - dim + j - 1];

    tempAvgPixel.red = tempPixel2.red + tempPixel3.red;
    tempAvgPixel.green = tempPixel2.green + tempPixel3.green;
    tempAvgPixel.blue = tempPixel2.blue + tempPixel3.blue;
    AvgPixels[j] = tempAvgPixel;
  }
  for(j = 0; j < dim - 2; j++)
  {
    AvgPixels[0] = AvgPixels[1];
    AvgPixels[1] = AvgPixels[2];

    tempPixel2 = src[upper_limit - (2*dim) + j + 2];
    tempPixel3 = src[upper_limit - dim + j + 2];

    tempAvgPixel.red = tempPixel2.red + tempPixel3.red;
    tempAvgPixel.green = tempPixel2.green + tempPixel3.green;
    tempAvgPixel.blue = tempPixel2.blue + tempPixel3.blue;
    AvgPixels[2] = tempAvgPixel;

    tempPixel1.red = (AvgPixels[0].red + AvgPixels[1].red + AvgPixels[2].red)/6;
    tempPixel1.green = (AvgPixels[0].green + AvgPixels[1].green + AvgPixels[2].green)/6;
    tempPixel1.blue = (AvgPixels[0].blue + AvgPixels[1].blue + AvgPixels[2].blue)/6;
    dst[upper_limit - (2*dim) + j] = tempPixel1;
  }
  // Hardcoded # of neighbors because we know where these are located
  tempPixel1.red = (AvgPixels[1].red + AvgPixels[2].red)/4;
  tempPixel1.green = (AvgPixels[1].green + AvgPixels[2].green)/4;
  tempPixel1.blue = (AvgPixels[1].blue + AvgPixels[2].blue)/4;
  dst[upper_limit - dim - 2] = tempPixel1;

  tempPixel1.red = AvgPixels[2].red/2;
  tempPixel1.green = AvgPixels[2].green/2;
  tempPixel1.blue = AvgPixels[2].blue/2;
  dst[upper_limit - dim - 1] = tempPixel1;

  // Covers last row up to the the very last two pixels in its row
  for(j = 1; j < 3; j++)
  {
    tempPixel2 = src[upper_limit - dim + j - 1];
    tempAvgPixel.red = tempPixel2.red;
    tempAvgPixel.blue = tempPixel2.blue;
    tempAvgPixel.green = tempPixel2.green;
    AvgPixels[j] = tempAvgPixel;
  }
  for(j = 0; j < dim - 2; j++)
  {
    AvgPixels[0] = AvgPixels[1];
    AvgPixels[1] = AvgPixels[2];

    tempPixel3 = src[upper_limit - dim + j + 2];

    tempAvgPixel.red = tempPixel3.red;
    tempAvgPixel.green = tempPixel3.green;
    tempAvgPixel.blue = tempPixel3.blue;
    AvgPixels[2] = tempAvgPixel;

    tempPixel1.red = (AvgPixels[0].red + AvgPixels[1].red + AvgPixels[2].red)/3;
    tempPixel1.green = (AvgPixels[0].green + AvgPixels[1].green + AvgPixels[2].green)/3;
    tempPixel1.blue = (AvgPixels[0].blue + AvgPixels[1].blue + AvgPixels[2].blue)/3;
    dst[upper_limit - dim + j] = tempPixel1;
  }

  // Set the last two pixels  
  tempPixel1.red = (AvgPixels[1].red + AvgPixels[2].red)/2;
  tempPixel1.green = (AvgPixels[1].green + AvgPixels[2].green)/2;
  tempPixel1.blue = (AvgPixels[1].blue + AvgPixels[2].blue)/2;
  dst[upper_limit - 2] = tempPixel1;

  tempPixel1.red = AvgPixels[2].red;
  tempPixel1.green = AvgPixels[2].green;
  tempPixel1.blue = AvgPixels[2].blue;
  dst[upper_limit - 1] = tempPixel1;
}

/*
 * motion - Your current working version of motion. 
 * IMPORTANT: This is the version you will be graded on
 */
char motion_descr[] = "motion: Current working version";
void motion(int dim, pixel *src, pixel *dst) 
{
  lab_motion(dim, src, dst);
}

/********************************************************************* 
 * register_motion_functions - Register all of your different versions
 *     of the motion kernel with the driver by calling the
 *     add_motion_function() for each test function.  When you run the
 *     driver program, it will test and report the performance of each
 *     registered test function.  
 *********************************************************************/

void register_motion_functions() 
{
	add_motion_function(&motion, motion_descr);
	add_motion_function(&naive_motion, naive_motion_descr);
	
	// Unrolling didn't seem to help that much
	//add_motion_function(&unroll_motion, unroll_motion_descr);
	add_motion_function(&lab_motion, lab_motion_descr);
}
