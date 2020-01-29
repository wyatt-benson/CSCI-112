#include <stdio.h>

int teaching(){
	char ans;
	printf("Are you a music teacher(y or n) >> ");
	scanf("%c", &ans);
/* if answer is  y or Y return true */
	if(ans == 121 || ans == 89){
		return 1;
	}
/* if answer is n or N return false */
	else if(ans == 110 || ans == 78){
		return 0;
	}
	else{
		return teaching();
	}
}
float calc(int teach, float amount){
	float discounted;
	float total;
/* Give discount if teach is true */
	if(teach == 1){
/* discount for purchases over $100 */
		if(amount < 100){
			discounted = amount * 0.9;
/* discount for purchases under $100 */
		}
		else{
			discounted = amount * 0.88;
		}
	}
	else{
		discounted = amount;
	}
/* 5% sales tax applied */
	total = discounted * 1.05;
	return total;
}
int main(){
	float cost;
	float finalCost;
	int teach;
	printf("Enter the cost of your items >> ");
	scanf("%f", &cost);
	teach = teaching();
	finalCost = calc(teach, cost);
	printf("The total comes out to $ %.2f\n", finalCost);
}
