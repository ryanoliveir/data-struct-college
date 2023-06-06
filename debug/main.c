#include <stdio.h>


// Um armazém trabalha com um determinado número de mercadorias diferentes (um máximo de 100 itens). Faça um programa que leia e armazene em vetores os preços de cada mercadoria e a 
// quantidade vendida no mês e, além disso, calcule e imprima:  
// a. O faturamento mensal do armazém. 
// b. A mercadoria mais vendida e a menos vendida. 
// c. O preço da mercadoria menos vendida. 2 
// d. Quantas mercadorias têm seu preço mais alto que o preço da mercadoria menos vendida.


#define MAX_ITENS 100
int main()
{
  float preco[MAX_ITENS], fatMensal, qtdVend[MAX_ITENS], precoMenos;
  int i,j, numItens, menorQtd = 0, maiorQtd = 0, acimamenor = 0;

  //numero de itens vendidos
  do{
    printf("Digite o numero de mercadorias diferentes: \n");
    scanf("%d", &numItens);
    if (numItens < 0 || numItens > MAX_ITENS)
      printf("Digite uma quantidade valida!\n");
  } while (numItens < 0 || numItens > MAX_ITENS);

  for (i = 0; i < numItens; i++)
  {
    //Preço
    do{
      printf("\nDigite o preco da mercadoria N%d: ", i+1);
      scanf("%f", &preco[i]);
      if (preco[i] < 0)
        printf("Digite um preço valido!\n");
    } while (preco[i] < 0);
    //Quantidade Vendida
    do{
      printf("Digite qual a quantidade de vendas da mercadoria N%d: ", i+1);
      scanf("%f", &qtdVend[i]);
      if (qtdVend[i] < 0)
        printf("Digite uma quantidade valida!\n");
    } while (qtdVend[i] < 0);

    fatMensal += preco[i] * qtdVend[i];

    //maior venda
    if (preco[i] > preco[maiorQtd])
      printf("\n%f: ", preco[i]);
      printf("\n%f: ", preco[maiorQtd]);
      maiorQtd = i;
      
    
    //menor venda
    if (preco[i] < preco[menorQtd])
      printf("\n%f: ", preco[i]);
      printf("\n%f: ", preco[maiorQtd]);
      menorQtd = i;

    //menos vendida
    precoMenos = preco[menorQtd];

    //qtd de precos maiores que a menor venda
    for (j = 0; j < numItens; j++) {
      if (preco[j] > precoMenos)
        acimamenor++;
        
    }  
  }
printf(
      "O faturamento mensal do armazem foi de %2.f reais.\n"
      "A mercadoria mais vendida foi a N%d e a menos vendida foi a N%d.\n"
      "O preco da mercadoria menos vendida e %2.f reais."
      "Foram vendidas %d mercadorias com preco maior do que menos vendida.", fatMensal, maiorQtd + 1, menorQtd + 1, preco[menorQtd], acimamenor);  

  
  return 0;
}