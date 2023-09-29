# include <stdio.h>
# include <cs50.h>

int somaNumerosCartao(long n);
string validarCartao(long n, int x);

int main(void)
{
    long nCartao;
    do
    {
        nCartao = get_long("Insira o número do seu cartão: ");
    }
    while (nCartao < 0);
    string tipoCartao = validarCartao(nCartao,somaNumerosCartao(nCartao));
    printf("%s\n", tipoCartao);
}

int somaNumerosCartao(long n)
{
    long cartao = n;
    int cont = 1;
    int soma = 0;
    do
    {
        int digito = cartao % 10;
        if (cont % 2 == 0)
        {
            int mult = digito * 2;
            if (mult > 9)
            {
                soma += mult % 10 + mult / 10;
            }
            else
            {
                soma += mult;
            }
        }
        else
        {
            soma += digito;
        }
        cartao = cartao / 10;
        cont++;
    }
    while (cartao > 0);
    return soma % 10;
}

string validarCartao(long n, int x)
{
    long cartao = n;
    if (x == 0)
    {
        int soma = 0;
        do
        {
            cartao = cartao / 10;
            soma++;
        }
        while (cartao > 100);
        if (soma >= 11)
        {
            if (cartao >= 40 && cartao <= 49)
            {
                return "VISA";
            }
            else if (cartao >= 51 && cartao <= 55)
            {
                return "MASTERCARD";
            }
            else if (cartao == 34 || cartao == 37)
            {
                return "AMERICAN EXPRESS";
            }
        }
    }
    return "INVALIDO!";
}
