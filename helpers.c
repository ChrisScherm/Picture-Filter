#include "helpers.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>




// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // RGBTRIPLE(*imageNew)[width] = calloc(height, width * sizeof(RGBTRIPLE));

    // int blue = image[2][2].rgbtBlue;
    // int red = image[2][2].rgbtRed;
    // int green = image[2][2].rgbtGreen;

    // printf("blue5= %i",blue);
    // printf("red5= %i",red);
    // printf("green5= %i \n",green);

    //  blue = image[20][20].rgbtBlue;
    //  red = image[20][20].rgbtRed;
    //  green = image[20][20].rgbtGreen;

    // printf("blue20= %i",blue);
    // printf("red20= %i",red);
    // printf("green20= %i\n",green);


    for (int y = 0; y<height;y++)
    {
        for (int x= 0; x<width;x++)
        {
            float blue = image[y][x].rgbtBlue;
            float red = image[y][x].rgbtRed;
            float green = image[y][x].rgbtGreen;

            float avg = (blue+ red + green)/3;

            int newavg = round(avg);

            image[y][x].rgbtBlue = newavg;
            image[y][x].rgbtRed = newavg;
            image[y][x].rgbtGreen = newavg;

        }


    }



    //free(imageNew);
    return;
}





// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE(*imageTEMP)[width] = calloc(height, width * sizeof(RGBTRIPLE));

    for (int y = 0; y<height;y++)
    {
        for (int x= 0; x<width;x++)
        {
            imageTEMP[y][(width-1)-x]= image[y][x];
        }



    }

    for (int y = 0; y<height;y++)
    {
        for (int x=0; x<=width;x++)
        {
            image[y][x] = imageTEMP[y][x];
        }
    }
    free(imageTEMP);
    return;
}





// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE(*imageTEMP)[width] = calloc(height, width * sizeof(RGBTRIPLE));





    for (int y = 0; y<height;y++)
    {
        for (int x= 0; x<width;x++)
        {
            float avgBlue= 0;
            float avgRed= 0;
            float avgGreen= 0;
            float sideDiv=0;



            if (y==0)
            {
                for(int i = 0;i<2;i++)
                {
                    if(x==0)
                    {
                        for(int j = 0; j<2;j++)
                        {
                            avgBlue += image[y+i][x+j].rgbtBlue;
                            avgRed +=image[y+i][x+j].rgbtRed;
                            avgGreen +=image[y+i][x+j].rgbtGreen;
                        }
                        sideDiv = 4;
                    }
                    if(x==width-1)
                    {
                        for(int j = -1; j<1;j++)
                        {
                            avgBlue += image[y+i][x+j].rgbtBlue;
                            avgRed +=image[y+i][x+j].rgbtRed;
                            avgGreen +=image[y+i][x+j].rgbtGreen;
                        }
                        sideDiv = 4;
                    }
                    if(x!=0 && x!=width-1)
                    {
                        for(int j = -1; j<2;j++)
                        {
                            avgBlue += image[y+i][x+j].rgbtBlue;
                            avgRed +=image[y+i][x+j].rgbtRed;
                            avgGreen +=image[y+i][x+j].rgbtGreen;
                        }
                        sideDiv = 6;
                    }
                }

            }





            if (y==height-1)
            {
                for(int i = -1;i<1;i++)
                {
                    if(x==0)
                    {
                        for(int j = 0; j<2;j++)
                        {
                            avgBlue += image[y+i][x+j].rgbtBlue;
                            avgRed +=image[y+i][x+j].rgbtRed;
                            avgGreen +=image[y+i][x+j].rgbtGreen;
                        }
                        sideDiv = 4;
                    }
                    if(x==width-1)
                    {
                        for(int j = -1; j<1;j++)
                        {
                            avgBlue += image[y+i][x+j].rgbtBlue;
                            avgRed +=image[y+i][x+j].rgbtRed;
                            avgGreen +=image[y+i][x+j].rgbtGreen;
                        }
                        sideDiv = 4;
                    }
                    if(x!=0 && x!=width-1)
                    {
                        for(int j = -1; j<2;j++)
                        {
                            avgBlue += image[y+i][x+j].rgbtBlue;
                            avgRed +=image[y+i][x+j].rgbtRed;
                            avgGreen +=image[y+i][x+j].rgbtGreen;
                        }
                        sideDiv = 6;
                    }
                }

            }




            if (y!=0 && y!=height-1)
            {
                for(int i = -1;i<2;i++)
                {
                    if(x==0)
                    {
                        for(int j = 0; j<2;j++)
                        {
                            avgBlue += image[y+i][x+j].rgbtBlue;
                            avgRed +=image[y+i][x+j].rgbtRed;
                            avgGreen +=image[y+i][x+j].rgbtGreen;
                        }
                        sideDiv = 6;
                    }
                    if(x==width-1)
                    {
                        for(int j = -1; j<1;j++)
                        {
                            avgBlue += image[y+i][x+j].rgbtBlue;
                            avgRed +=image[y+i][x+j].rgbtRed;
                            avgGreen +=image[y+i][x+j].rgbtGreen;
                        }
                        sideDiv = 6;
                    }
                    if(x!=0 && x!=width-1)
                    {
                        for(int j = -1; j<2;j++)
                        {
                            avgBlue += image[y+i][x+j].rgbtBlue;
                            avgRed +=image[y+i][x+j].rgbtRed;
                            avgGreen +=image[y+i][x+j].rgbtGreen;
                        }
                        sideDiv = 9;
                    }


                }

            }
            avgBlue = avgBlue/sideDiv;
            avgRed = avgRed/sideDiv;
            avgGreen = avgGreen/sideDiv;

            int rndBlue = round(avgBlue);
            int rndRed = round(avgRed);
            int rndGreen = round(avgGreen);

            imageTEMP[y][x].rgbtBlue =rndBlue;
            imageTEMP[y][x].rgbtRed =rndRed;
            imageTEMP[y][x].rgbtGreen =rndGreen;
        }




    }

    for (int y = 0; y<height;y++)
    {
        for (int x= 0; x<width;x++)
        {
            image[y][x].rgbtBlue = imageTEMP[y][x].rgbtBlue;
            image[y][x].rgbtRed = imageTEMP[y][x].rgbtRed;
            image[y][x].rgbtGreen = imageTEMP[y][x].rgbtGreen;
        }


    }




    free(imageTEMP);
    return;
}




// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE(*imageTEMP)[width] = calloc(height, width * sizeof(RGBTRIPLE));



    int GxMulti[3][3] = {{-1,0,1},{-2,0,2},{-1,0,1}};






    int GyMulti[3][3] = {{-1,-2,-1},{0,0,0},{1,2,1}};




    for (int y = 0; y<height;y++)
    {
        for (int x= 0; x<width;x++)
        {
            int GxRed = 0;
            int GxBlue = 0;
            int GxGreen = 0;

            int GyRed = 0;
            int GyBlue = 0;
            int GyGreen = 0;


            if (y==0)
            {
                for(int i = 0;i<2;i++)
                {
                    if(x==0)
                    {
                        for(int j = 0; j<2;j++)
                        {
                            GxBlue +=image[y+i][x+j].rgbtBlue * GxMulti[i+1][j+1];
                            GxRed +=image[y+i][x+j].rgbtRed * GxMulti[i+1][j+1];
                            GxGreen +=image[y+i][x+j].rgbtGreen * GxMulti[i+1][j+1];

                            GyBlue +=image[y+i][x+j].rgbtBlue * GyMulti[i+1][j+1];
                            GyRed +=image[y+i][x+j].rgbtRed * GyMulti[i+1][j+1];
                            GyGreen +=image[y+i][x+j].rgbtGreen * GyMulti[i+1][j+1];
                        }

                    }
                    if(x==width-1)
                    {
                        for(int j = -1; j<1;j++)
                        {
                            GxBlue +=image[y+i][x+j].rgbtBlue * GxMulti[i+1][j+1];
                            GxRed +=image[y+i][x+j].rgbtRed * GxMulti[i+1][j+1];
                            GxGreen +=image[y+i][x+j].rgbtGreen * GxMulti[i+1][j+1];

                            GyBlue +=image[y+i][x+j].rgbtBlue * GyMulti[i+1][j+1];
                            GyRed +=image[y+i][x+j].rgbtRed * GyMulti[i+1][j+1];
                            GyGreen +=image[y+i][x+j].rgbtGreen * GyMulti[i+1][j+1];
                        }

                    }
                    if(x!=0 && x!=width-1)
                    {
                        for(int j = -1; j<2;j++)
                        {
                            GxBlue +=image[y+i][x+j].rgbtBlue * GxMulti[i+1][j+1];
                            GxRed +=image[y+i][x+j].rgbtRed * GxMulti[i+1][j+1];
                            GxGreen +=image[y+i][x+j].rgbtGreen * GxMulti[i+1][j+1];

                            GyBlue +=image[y+i][x+j].rgbtBlue * GyMulti[i+1][j+1];
                            GyRed +=image[y+i][x+j].rgbtRed * GyMulti[i+1][j+1];
                            GyGreen +=image[y+i][x+j].rgbtGreen * GyMulti[i+1][j+1];
                        }
                    }
                }

            }





            if (y==height-1)
            {
                for(int i = -1;i<1;i++)
                {
                    if(x==0)
                    {
                        for(int j = 0; j<2;j++)
                        {
                            GxBlue +=image[y+i][x+j].rgbtBlue * GxMulti[i+1][j+1];
                            GxRed +=image[y+i][x+j].rgbtRed * GxMulti[i+1][j+1];
                            GxGreen +=image[y+i][x+j].rgbtGreen * GxMulti[i+1][j+1];

                            GyBlue +=image[y+i][x+j].rgbtBlue * GyMulti[i+1][j+1];
                            GyRed +=image[y+i][x+j].rgbtRed * GyMulti[i+1][j+1];
                            GyGreen +=image[y+i][x+j].rgbtGreen * GyMulti[i+1][j+1];
                        }
                    }
                    if(x==width-1)
                    {
                        for(int j = -1; j<1;j++)
                        {
                            GxBlue +=image[y+i][x+j].rgbtBlue * GxMulti[i+1][j+1];
                            GxRed +=image[y+i][x+j].rgbtRed * GxMulti[i+1][j+1];
                            GxGreen +=image[y+i][x+j].rgbtGreen * GxMulti[i+1][j+1];

                            GyBlue +=image[y+i][x+j].rgbtBlue * GyMulti[i+1][j+1];
                            GyRed +=image[y+i][x+j].rgbtRed * GyMulti[i+1][j+1];
                            GyGreen +=image[y+i][x+j].rgbtGreen * GyMulti[i+1][j+1];
                        }
                    }
                    if(x!=0 && x!=width-1)
                    {
                        for(int j = -1; j<2;j++)
                        {
                            GxBlue +=image[y+i][x+j].rgbtBlue * GxMulti[i+1][j+1];
                            GxRed +=image[y+i][x+j].rgbtRed * GxMulti[i+1][j+1];
                            GxGreen +=image[y+i][x+j].rgbtGreen * GxMulti[i+1][j+1];

                            GyBlue +=image[y+i][x+j].rgbtBlue * GyMulti[i+1][j+1];
                            GyRed +=image[y+i][x+j].rgbtRed * GyMulti[i+1][j+1];
                            GyGreen +=image[y+i][x+j].rgbtGreen * GyMulti[i+1][j+1];
                        }
                    }
                }

            }




            if (y!=0 && y!=height-1)
            {
                for(int i = -1;i<2;i++)
                {
                    if(x==0)
                    {
                        for(int j = 0; j<2;j++)
                        {
                            GxBlue +=image[y+i][x+j].rgbtBlue * GxMulti[i+1][j+1];
                            GxRed +=image[y+i][x+j].rgbtRed * GxMulti[i+1][j+1];
                            GxGreen +=image[y+i][x+j].rgbtGreen * GxMulti[i+1][j+1];

                            GyBlue +=image[y+i][x+j].rgbtBlue * GyMulti[i+1][j+1];
                            GyRed +=image[y+i][x+j].rgbtRed * GyMulti[i+1][j+1];
                            GyGreen +=image[y+i][x+j].rgbtGreen * GyMulti[i+1][j+1];
                        }
                    }
                    if(x==width-1)
                    {
                        for(int j = -1; j<1;j++)
                        {
                            GxBlue +=image[y+i][x+j].rgbtBlue * GxMulti[i+1][j+1];
                            GxRed +=image[y+i][x+j].rgbtRed * GxMulti[i+1][j+1];
                            GxGreen +=image[y+i][x+j].rgbtGreen * GxMulti[i+1][j+1];

                            GyBlue +=image[y+i][x+j].rgbtBlue * GyMulti[i+1][j+1];
                            GyRed +=image[y+i][x+j].rgbtRed * GyMulti[i+1][j+1];
                            GyGreen +=image[y+i][x+j].rgbtGreen * GyMulti[i+1][j+1];
                        }
                    }
                    if(x!=0 && x!=width-1)
                    {
                        for(int j = -1; j<2;j++)
                        {
                            GxBlue +=image[y+i][x+j].rgbtBlue * GxMulti[i+1][j+1];
                            GxRed +=image[y+i][x+j].rgbtRed * GxMulti[i+1][j+1];
                            GxGreen +=image[y+i][x+j].rgbtGreen * GxMulti[i+1][j+1];

                            GyBlue += image[y+i][x+j].rgbtBlue * GyMulti[i+1][j+1];
                            GyRed +=image[y+i][x+j].rgbtRed * GyMulti[i+1][j+1];
                            GyGreen +=image[y+i][x+j].rgbtGreen * GyMulti[i+1][j+1];
                        }

                    }


                }

            }

            float newRed = 0;
            float newBlue = 0;
            float newGreen = 0;

            GxRed = pow (GxRed, 2);
            GyRed = pow (GyRed, 2);

            GxBlue = pow (GxBlue, 2);
            GyBlue = pow (GyBlue, 2);

            GxGreen = pow (GxGreen, 2);
            GyGreen = pow (GyGreen, 2);


            // printf("GxRed=%i ",GxRed);
            // printf("GyRed =%i \n",GyRed);

            newRed = sqrt((GxRed)+(GyRed));
            newBlue = sqrt((GxBlue)+(GyBlue));
            newGreen = sqrt((GxGreen)+(GyGreen));


            // printf("newRed =%f\n",newRed);

            if (newRed > 255)
            {
                newRed = 255;
            }

            if (newGreen > 255)
            {
                newGreen = 255;
            }

            if (newBlue > 255)
            {
                newBlue = 255;
            }

            // printf("newblue =%f ",newBlue);
            // printf("newGreen =%f ",newGreen);

            int rndRed;
            int rndBlue;
            int rndGreen;

            rndRed = round(newRed);
            rndGreen = round(newGreen);
            rndBlue = round(newBlue);




            imageTEMP[y][x].rgbtBlue =rndBlue;
            imageTEMP[y][x].rgbtRed =rndRed;
            imageTEMP[y][x].rgbtGreen =rndGreen;



        }




    }

    for (int y = 0; y<height;y++)
    {
        for (int x= 0; x<width;x++)
        {
            image[y][x].rgbtBlue = imageTEMP[y][x].rgbtBlue;
            image[y][x].rgbtRed = imageTEMP[y][x].rgbtRed;
            image[y][x].rgbtGreen = imageTEMP[y][x].rgbtGreen;
        }


    }




    free(imageTEMP);




    return;
}
