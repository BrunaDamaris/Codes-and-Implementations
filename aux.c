#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    double totalprice = 0, discount = 0;
    char meatchoice[3],bread,adultdrinks,childrendrinks;
    int adults,children,control = 0,drinks = 0;
    scanf("%s",meatchoice);
    getchar();
    scanf("%c\n%c\n%c\n",&bread,&adultdrinks,&childrendrinks);
    scanf("%d%d",&adults,&children);

    if(meatchoice[0] == 'C'){
        totalprice += ((200 * (adults+children)) * 32.0)/1000;
        totalprice += ((100 * adults) * 18.0)/1000;
        totalprice += ((100 * adults) * 15.0)/1000;
    }
    else if(meatchoice[0] == 'B' && meatchoice[1] == 'F'){
        totalprice += ((250 * adults) * 32.0)/1000;
        totalprice += ((150 * adults)* 18.0)/1000;
        totalprice += ((200 * children) * 32.0)/1000;
    }
    else if(meatchoice[0] == 'B' && meatchoice[1] == 'S'){
        totalprice += ((250 * adults) * 32.0)/1000;
        totalprice += ((150 * adults)* 15.0)/1000;
        totalprice += ((200 * children) * 32.0)/1000;
    }
    else {
        printf("Opção inválida.\n");
        control = 1;
    }
    if(control == 0){
        if(adultdrinks == 'S'){
            drinks = adults * 2;
            totalprice += drinks * 8;
            drinks = 0;
        }
        if(childrendrinks == 'S'){
            drinks = children * 0.5;
            totalprice += drinks * 6;
        }
        if(bread == 'N') {
            discount = totalprice * 0.2;
            totalprice = totalprice - discount;;
        }
        printf("R$: %.2lf\n",totalprice);
    }
	return 0;
}
