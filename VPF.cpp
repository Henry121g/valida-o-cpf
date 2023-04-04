#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

bool validarCPF(char cpf[]) {
    int i, j, d[11], s = 0;

    if (strlen(cpf) != 11) {
        printf("CPF invalido: deve conter 11 digitos!\n");
        return false;
    }

    for (i = 0; i < 11; i++) {
        if (!isdigit(cpf[i])) {
            printf("CPF invalido: deve conter apenas digitos!\n");
            return false;
        }
        d[i] = cpf[i] - '0'; 
    }

    for (i = 0, j = 10; i < 9; i++, j--) {
        s += d[i] * j;
    }
    int primeiro_digito_verificador = (s % 11 < 2) ? 0 : 11 - (s % 11);

    if (primeiro_digito_verificador != d[9]) {
        printf("CPF invalido: primeiro digito verificador incorreto!\n");
        return false;
    }

    s = 0;
    for (i = 0, j = 11; i < 10; i++, j--) {
        s += d[i] * j;
    }
    int segundo_digito_verificador = (s % 11 < 2) ? 0 : 11 - (s % 11);

    if (segundo_digito_verificador != d[10]) {
        printf("CPF invalido: segundo dígito verificador incorreto!\n");
        return false;
    }


    printf("CPF valido!\n");
    return true;
}

int main()
{
    char cpf[12];

    printf("Digite o CPF (apenas numeros): ");
    scanf("%s", cpf);

    validarCPF(cpf);

    return 0;
}
