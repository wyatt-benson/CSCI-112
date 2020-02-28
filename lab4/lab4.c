#include <stdio.h>
#include <string.h>
#include <math.h>

double power(int x, int y){
	double total;
	total = 1;
	if(y > 0){
		for(int i=0;i<y;i++){
			total = total * x;
		}
	}
	if(y < 0){
		for(int i=0;i>y;i--){
			total = total/x;
		}
	}
	return total;
}
double convert(char str[100]){
	double total;
	int asciiConvert;
	double m;
	double mult;
	m = 0;
	for(int i=0;i<strlen(str);i++){
		asciiConvert = str[i];
		if(asciiConvert == 46){
			m = -1;
		}
		else if(asciiConvert >= 48 && asciiConvert <= 57){
			mult = power(10,m);
			total = total + ((asciiConvert - 48) * mult);
			if(m >= 0){
				m++;
			}
			else{
				m--;
			}
		}
	}
	return total;
}
int main(void){
	char str[100];
	double coord;
	int state;
	int test;
	int first;
	double x,xPrev,xStart,xAdd;
	double yPrev,y,yStart,yAdd;
	double total;
	state = 0;
	first = 0;
	printf("  x    y\n  -    -\n");
	while(1 == scanf("%s",&str)){
		test = str[0];
		if(test >= 48 && test <= 57){
			coord = convert(str);
			if(state == 0){
				if(first == 0){
					x = coord;
					xStart = coord;
				}
				else{
					xPrev = x;
					x = coord;
				}
				printf("%.2lf  ",coord);
				state = 1;
			}
			else{
				printf("%.2lf\n",coord);
				state = 0;
				if(first == 1){
					yPrev = y;
					y = coord;
					if(x == xStart && y == yStart){
						total = (fabs(total))/2;
						printf("The area of this polygon is %.2lf\n",total);
					}
					xAdd = x + xPrev;
					yAdd = y - yPrev;
					total = total + (xAdd * yAdd);
				}
				else{
					y = coord;
					yStart = coord;
					first = 1;
				}
			}
		}
	}
	return 0;
}
