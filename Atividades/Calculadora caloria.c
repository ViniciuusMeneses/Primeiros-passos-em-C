#include <stdio.h>

int main()
{
	int prato;
	
	printf("Pratos: \n Vegetariano 180cal (1) \n");
    printf(" Peixe 230cal (2) \n");
    printf(" Frango 250cal (3) \n");
    printf(" Carne 350cal (4) \n");
    
    scanf("%d", &prato);
    
    int pratoc;
    
    if(prato == 1){
		pratoc = 180;
	} else if (prato == 2){
		pratoc = 230;
	} else if (prato == 3){
		pratoc = 250;
	} else {
		pratoc = 350;
	}
    
    int sobremesa;
	
	printf("Sobremesa: \n Abacaxi 75cal (1) \n");
    printf(" Sorvete diet 110cal (2) \n");
    printf(" Mousse diet 170cal (3) \n");
    printf(" Mousse Chocolate 200cal (4) \n");
    
    scanf("%d", &sobremesa);
    
    int sobremesac;
    
    if(sobremesa == 1){
		sobremesac = 75;
	} else if (sobremesa == 2){
		sobremesac = 110;
	} else if (sobremesa == 3){
		sobremesac = 170;
	} else {
		sobremesac = 200;
	}
    
    int bebida;
	
	printf("Bebida: \n cha 20cal (1) \n");
    printf(" Suco de laranja 70cal (2) \n");
    printf(" Suco de melao 100cal (3) \n");
    printf(" Refrigerante diet 75cal (4) \n");
    
    scanf("%d", &bebida);
    
    int bebidac;
    
     if(bebida == 1){
		bebidac = 20;
	} else if (bebida == 2){
		bebidac = 70;
	} else if (bebida == 3){
		bebidac = 100;
	} else {
		bebidac = 65;
	}
	
	printf("Voce ira consumir %d calorias", pratoc + sobremesac + bebidac );
	
	return 0;
}
