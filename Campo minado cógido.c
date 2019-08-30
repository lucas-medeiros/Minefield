#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#define JOGADA 0
#define MINA 1
#define FUNDO 2 


void Zeracampo(int *campo)
{
	int i;
	for (i = 0; i < 9; i++)
		campo[i] = FUNDO;
}

void MostraCampo(int*campo)
{
	int i, j;
	for (i = 0; i<3; i++)
	{
		printf("\n| ");
		for (j = 0; j<3; j++)
		{
			printf("%c ", campo[3 * i + j] == JOGADA ? '0' : (campo[3 * i + j] == MINA ? ' ' : ' '));

		}
		printf("|");
	}
	printf("\n");

}

void MostraCampo2(int*campo)
{
	{
		int i, j;
		for (i = 0; i<3; i++)
		{
			printf("\n| ");
			for (j = 0; j<3; j++)
			{
				printf("%c ", campo[3 * i + j] == JOGADA ? '0' : (campo[3 * i + j] == MINA ? 'X' : ' '));

			}
			printf("|");
		}
		printf("\n");

	}

}


int main()
{
	int  d, jogadas, linha, coluna, campo[3][3], morreu = 0, n, a, b, j, jn, v = 0, de = 0, p = 0;
	do
	{
		morreu = 0;
		Zeracampo(&campo[0][0]);
		printf("Vitoria: %d    Derrotas: %d\n", v, de);
		printf("Escolha sua dificuldade\n");
		printf("Digite 1 para: easy (Uma bomba)\n");
		printf("Digite 2 para: normal (Duas bombas)\n");
		printf("Digite 3 para: harcore (Tres bombas)\n");
		scanf("%d", &d);
		if ((d < 1) || (d > 3))
		{
			do
			{
				printf("Dificuldade invalida, escolha novamente: ");
				scanf("%d", &d); fflush(stdin);
			} while ((d < 1) || (d > 3));
		}
		if (d == 3)
			printf("Isso pode demorar alguns segundos, por favor aguarde\n\n");

		for (n = 0; n < d; n++)
		{

			srand(time(NULL));
			a = rand() % 99;
			b = rand() % 99;
			if (a <= 33)
				linha = 0;
			if (a <= 66)
				linha = 1;
			else
				linha = 2;
			if (b <= 33);
			coluna = 0;
			if (b <= 66)
				coluna = 1;
			else
				coluna = 2;
			if (campo[linha][coluna] != MINA)
				campo[linha][coluna] = MINA;
			else
			{
				do
				{
					srand(time(NULL));
					a = rand() % 99;
					b = rand() % 99;
					if ((a <= 33) && (a > 66));
					linha = 1;
					if (a <= 66)
						linha = 2;
					else
						linha = 0;
					if ((b <= 33) && (b > 66));
					coluna = 1;
					if (b <= 66)
						coluna = 2;
					else
						coluna = 0;
				} while (campo[linha][coluna] == MINA);
				campo[linha][coluna] = MINA;
			}

		}
		printf("\nFaca suas jogadas:\n");
		for (j = 0; j < 9 - d; j++)
		{
			do
			{
				MostraCampo(&campo[0][0]);
				printf("\nEscolha a linha que deseja jogar: ");
				scanf("%d", &linha); fflush(stdin);
				printf("\nEscolha a coluna que deseja jogar: ");
				scanf("%d", &coluna); fflush(stdin);
				if ((((linha < 3) && (linha>-1)) && ((coluna <3) && (coluna >-1))) || (campo[linha][coluna] == MINA))
					if (campo[linha][coluna] == JOGADA)
					{
						printf("\nVoce ja jogou nessa posicao! tente novamente");
						j = j - 1;
					}
					else
						p = 1;
				else
				{
					printf("\nJogada invalida! tente novamente");
					j = j - 1;
				}

			} while (p == 0);
			if (campo[linha][coluna] == MINA)
			{
				printf("voce morreu!");
				morreu = morreu++;
				de = de++;
				break;
			}
			campo[linha][coluna] = JOGADA;
		}
		MostraCampo2(&campo[0][0]);
		if (morreu == 0)
		{
			printf("Parabens, voce venceu!");
			v = v++;
		}
		printf("\nJogar novamente ? : 1 sim \n                    2 nao\n ");
		scanf("%d", &jn);
		printf("\n\n");
	} while (jn == 1);
	system("PAUSE");
	return 0;
}