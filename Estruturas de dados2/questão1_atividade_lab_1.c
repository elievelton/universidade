#include <stdio.h>
#include <stdlib.h>

void divisores( int a, int b){
    

    if(a >= b){
        if(a % b ==0){
            
            
            printf("%d\n",b);
            divisores(a,b+1);           
                        
        }else{
            divisores(a,b+1);
        }
    }
}


int main (){
    
    int num, aux =1 ;
    printf("Digite um numero\n");
    scanf("%d", &num);
    divisores(num,aux);


    return (0);


}