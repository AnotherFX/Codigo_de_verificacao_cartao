/*O código de confirmação de uma transação bancária é calculada considerando os quatro dígitos
finais do cartão e o horário da transação no formato HHMM. Para o cálculo, são gerados dois números
considerando para o primeiro os maiores numerais de cada posição, e para o segundo o menor
númeral de cada posição. Em seguida, o menor número é subtraído do maior e seu invertido é gerado.
Este último valor é o código de confirmação da transação.
Por exemplo, para o cartão 4392 e uma transação realizada às 12:15, o código de confirmação será
igual a 3813; calculado da seguinte forma: 4395 - 1212 = 3183, que quando invertido, gera o número
3813.
Escreva um programa em C, que leia um número de quatro dígitos do cartão e um outro representando
o horário no formato HHMM e imprima o código de confirmação calculado.*/

#include <stdio.h>
int main (void) {
    int hora, cartao, parcial_hora, parcial_cartao, aux_hora, aux_cartao,
        numero_maior=0, numero_menor=0, subt, aux_codigo, cont=1, divisor=100;
    printf("Insira a hora que a compra foi efetuada no formato HHMM:\n");
    scanf("%d", &hora);
    while (hora<0000 || hora>2359) { //N1-validação de entrada das horas
        printf("Insira a hora que a compra foi efetuada no formato HHMM:\n");
        scanf("%d", &hora);
    }
    printf("Insira os ultimos 4 digitos do cartao:\n");
    scanf("%d", &cartao);
    while (cartao<0000 || cartao>9999) { //N2-validação de entrada do numero do cartao
        printf("Insira os ultimos 4 digitos do cartao:\n");
        scanf("%d", &cartao);
    }
    parcial_hora=hora%1000; //N3-armazenando o resto da divisão para separar os proximos digitos
    aux_hora=hora/1000; //N4-separando o digito de maior magnitude para efetuar a comparação
    parcial_cartao=cartao%1000; // idem N3
    aux_cartao=cartao/1000; //idem N4
    if (aux_hora>=aux_cartao) { //N5-ao efetuar a comparação, armazenar nas variáveis que serão utilizadas na subt.
        numero_maior+=aux_hora*1000;
        numero_menor+=aux_cartao*1000;
    }    
        else {
            numero_maior+=aux_cartao*1000;
            numero_menor+=aux_hora*1000;
        }
    for ( ; cont<=3; cont++) {    
        aux_hora=parcial_hora/divisor;//idem N4
        parcial_hora%=divisor;//idem N3
        aux_cartao=parcial_cartao/divisor;//idem N4
        parcial_cartao%=divisor; //idem N3
        if (aux_hora>=aux_cartao) { //idem N5
           numero_maior+=aux_hora*divisor;
           numero_menor+=aux_cartao*divisor;
        }    
        else {
            numero_maior+=aux_cartao*divisor;
            numero_menor+=aux_hora*divisor;
        }
        divisor/=10;
    }    
    subt=numero_maior-numero_menor; //N6-efetuando a subt. do numero de maiores algarismos - numero de menores alg.
    printf("O codigo de verificacao e:\n"); 
    while (subt!=0) { //N7-estrut. de repet. para inverter a ordem de saída e gerar o código de verificação
        aux_codigo= subt%10;
        subt/=10;
        printf("%d", aux_codigo);
    }
    return 0;
}