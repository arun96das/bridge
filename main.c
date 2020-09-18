// Standard (system) header files
#include <stdio.h>
struct bridge
{
	float bowwidth;
	float bowheight;
	float streetheight;
	int elements;
	float xposition[20];
	float beamlength[20];
	float total;
} b1;

void readbowwidth(void)
{
	do
	{
		printf("\nEnter value of width of bow:\t");
		scanf("%f", &b1.bowwidth);
	} while (b1.bowwidth <= 0);
}
void readbowheight(void)
{
	do
	{
		printf("\nEnter value of height of bow:\t");
		scanf("%f", &b1.bowheight);
	} while (b1.bowheight <= 0);
}
void readstreetheight(void)
{
	do
	{
		printf("\nEnter value of height of the street:\t");
		scanf("%f", &b1.streetheight);
	} while (b1.streetheight <= 0);
}
void readelements(void)
{
	do
	{
		printf("\nEnter number of vertical carrier elements:\t");
		scanf("%d", &b1.elements);
	} while (b1.elements < 2);
}
float calculatey(float x) //function to calculate y value in bow at any value of x
{
	float p1 = 0, p2 = 0, p3 = 0, t = 0;
	p1 = (-4 * b1.bowheight) / (b1.bowwidth * b1.bowwidth);
	p2 = (4 * b1.bowheight) / b1.bowwidth;
	t = (p1 * x * x) + (p2 * x) + p3;
	return t;
}
void calcbeamandpos(void) //function to calculate xpositions where elements are connected and their beam lengths
{
	float gap = 0.0, g = 0.0; //distance between beam elements
	gap = b1.bowwidth / (b1.elements - 1);
	for (int i = 0; i < b1.elements; i++)
	{
		b1.xposition[i] = g;
		b1.beamlength[i] = b1.streetheight + b1.bowheight
				- calculatey(b1.xposition[i]);
		g = g + gap;
	}
}

void calculatetotal(void) //function to calculate total steel material length required
{
	b1.total = 0.0;
	for (int i = 0; i < b1.elements; i++)
	{
		b1.total = b1.total + b1.beamlength[i];
	}
}
void displayeach(void) //function to display length of steel elements at each x position
{
	int j=0;
	while(j<b1.elements)
		{
	       printf("\n At x position %f , material length = %f",b1.xposition[j],b1.beamlength[j]);
		   j=j+1;
		}
}
int main(void)
{
	setvbuf(stdout, NULL, _IONBF, 0);
	printf("Bridge material calculation");
	//reading inputs
	readbowwidth();
	readbowheight();
	readstreetheight();
	readelements();
	//calculations
	//calculating x positions from which steel elements connected to street and length of individual beams
	calcbeamandpos();
	//calculating total steel material required
	calculatetotal();
	//output
	//display length of steel elements at each x position
    displayeach();
	//display total steel material required
	printf("\nTotal length of material:%f", b1.total);
	return 0;
}
