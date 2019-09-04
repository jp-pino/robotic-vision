//----------------------------------------------------------------------------//
// Template for reading portable gray map files (*.pgm)                       //
//                                                                            //
//                                                RickWare                    //
//                                                August 22, 2011             //
//                                                                            //
//----------------------------------------------------------------------------//

//----------------------------------------------------------------------------//
//         Prototype declarations                                             //
//----------------------------------------------------------------------------//

void heading (void);      /* Displays program heading */
void openfiles (void);    /* Opens input and output files in binary */
void userdefined (void);  /* Here, the user will implement his routine */
void readhdr (void);      /* Read header from input image file */
void addhdr (void);       /* Add header to output image file */
void closefiles (void);   /* Close all files used in program */

//----------------------------------------------------------------------------//
//         Include declarations                                               //
//----------------------------------------------------------------------------//

# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <string.h>

//----------------------------------------------------------------------------//
//         Variable declarations                                              //
//----------------------------------------------------------------------------//

int    MRows, NCols, MaxRGB;         /* Number of Rows and columns in image */
FILE   *infptr, *outfptr, *outfptrh; /* Input and output file pointers */
char   infile[40];                   /* Name of input file */
char   outfile[40];                  /* Name of output file */

//----------------------------------------------------------------------------//
//         Main program                                                       //
//----------------------------------------------------------------------------//

int main ()
{
     // Display heading
     heading ();
     // Open Input and Output Image Files
     openfiles ();
     // Read header from image file
     readhdr();
     // Add header to output file
     addhdr();
     // Execute userdefined procedure
     userdefined ();
     // Close all image files
     closefiles ();

     printf("\n Bye! Bye!\n");
     return(0);
} // end main ();

//----------------------------------------------------------------------------//
//         Headings                                                           //
//----------------------------------------------------------------------------//

void heading ()
{
     int i;
     for (i=0; i<16; i++)
       printf("                                    +                       \n");
       printf("                      Digital Image Processing in C         \n");
       printf("                          Date: August 22, 2011             \n");
       printf("                            Author: RickWare                \n");
     for (i=0; i<3; i++)
       printf("                                    +                       \n");
       return;
} // end heading ()

//----------------------------------------------------------------------------//
//         Openfiles                                                          //
//----------------------------------------------------------------------------//

void openfiles ()
{
     printf("\n Opening Input and Output image files\n");
     printf(" Enter name of *.pgm INPUT image file (example: lena.ppm) ");
		 strcpy(infile, "img/");
     scanf("%s",(infile + 4));


     //Check if input file exists
     if ((infptr = fopen(infile, "rb")) == NULL)
     {
       printf(" Cannot open input image file: %s\n",infile);
       printf(" Exiting program...\n");
       exit(0);
       }

     printf(" Enter name of *.pgm OUTPUT image file (example: lenaout.pgm) ");
		 strcpy(outfile, "out/");
     scanf("%s",(outfile + 4));

     //Check if output file was created succesfully
     if ((outfptr = fopen(outfile, "wb")) == NULL)
     {
       printf(" Cannot create output image file: %s\n",outfile);
       printf(" Exiting program...\n");
       exit(0);
       }

     // If this point is reached, file are OK
     printf(" File opened and created OK! \n\n");

}  //end openfiles ()

//----------------------------------------------------------------------------//
//         Read Header                                                        //
//----------------------------------------------------------------------------//

void readhdr ()
{
     int   i=0;
     char  c, buffer[128];

     //Read header of PGM file
     printf("\n\n File <%s> Header: \n",infile);

     do
     {
       c = fgetc(infptr);
       buffer[i] = c;
       i++;
     } while (c != '\n');

     //Check if file is P5 (pgm) format
     if (buffer[1] == '6')
       printf("\n Input file is ppm, OK\n");
     else
     {
       printf("\n Input file is NOT ppm, Exiting program...\n");
       exit(0);
     }

     //File is pgm, read rest of header
     fscanf(infptr,"%d %d %d",&NCols, &MRows, &MaxRGB);
     c = fgetc(infptr);
     printf("%d ",NCols);
     printf("%d   <---- Width x Height) \n",MRows);
     printf("%d   <---- Max. Grayscale level) \n\n",MaxRGB);
}  // end readhdr ()

//----------------------------------------------------------------------------//
//         Add Header                                                         //
//----------------------------------------------------------------------------//

void addhdr ()
{
     fprintf(outfptr, "P6\n%d %d\n%d\n",NCols*2,MRows*2,MaxRGB);
} //addhdr ()

//----------------------------------------------------------------------------//
//         User defined section                                               //
//----------------------------------------------------------------------------//

void scale_up(int rows, int cols, FILE *in, FILE *out) {
	unsigned char inbuffer[rows][cols][3];
	unsigned char outbuffer[rows*2][cols*2][3];

	// Read buffer
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			for (int k = 0; k < 3; k++) {
				inbuffer[i][j][k] = fgetc(in);
			}
		}
	}

	// Scale up
	for (int i = 0; i < rows*2; i++) {
		for (int j = 0; j < cols*2; j++) {
			for (int k = 0; k < 3; k++) {
				outbuffer[i][j][k] = inbuffer[i/2][j/2][k];
			}
		}
	}

	// Save to file
	for (int i = 0; i < cols*2; i++) {
		for (int j = 0; j < rows*2; j++) {
			for (int k = 0; k < 3; k++) {
				 fputc(outbuffer[i][j][k], out);
			}
		}
	}
}

void userdefined ()
{
	scale_up(MRows, NCols, infptr, outfptr);
}  // end userdefined ()

//----------------------------------------------------------------------------//
//         Close Files                                                        //
//----------------------------------------------------------------------------//

void closefiles ()
{
     fclose(infptr);
     fclose(outfptr);
}  // end closefiles ()
