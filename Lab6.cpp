#include <stdio.h>

short factorial (short in){
    short out = 1;
    short i;
    for (i = in; i>1; i--){
        out*=i;
    }
    return out;
}

void bionomial (short n){
    int i;
    printf("binom form: ");
    printf("x^%i", n);
    for(i=1;i<n;i++){
        printf(" + %i(x)^%i(y)^%i", factorial(n)/(factorial(i)*factorial(n-i)), n-i, i);
    }
    printf(" + y^%i\n\n", n);
}

int main (void){
    int amount, i, pointer;
    printf("how much elements \n");
    scanf("%i",&amount);
    int elements[amount];
    for(i=0;i<amount;i++){
        printf("input %i element: \n", i+1);
        scanf("%i",&elements[i]);
    }
    for (;;){
        pointer =0;
        for (i=0;i<amount-1;i++){
            if (elements[i]>elements[i+1]){
                int a=elements[i];
                elements[i]=elements[i+1];
                elements[i+1]=a;
                pointer++;
            }
        }
        if (pointer == 0){
            break;
        }

    }
    for(i=0;i<amount;i++){
        printf("%i) %i\n",i+1,elements[i]);
    }
    bionomial(4);
}
