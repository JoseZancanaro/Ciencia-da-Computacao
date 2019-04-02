#pragma once

#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
#include <vector>

using namespace std;

/*
Constante para identificar as cercas
*/
const char CERCA = '#';
/*
Constante para identificar as cercas criadas pelo algoritmo
*/
const char CERCA_ALT = '%';
/*
Constante para identiciar um espa�o vazio
*/
const char VAZIO = '\0';
/*
Constante para identificar um v�rus
*/
const char VIRUS = 'X';
/*
Constante para identificar o ponto inicial de infecta��o
*/
const char VIRUS_ALT = '@';
/*
Constante para identificar o tamanho de campo pequeno
*/
const int TAMANHO_PEQUENO = 1;
/*
Constante para identificar o tamanho de campo m�dio
*/
const int TAMANHO_MEDIO = 2;
/*
Constante para identificar o tamanho de campo grande
*/
const int TAMANHO_GRANDE = 3;

/*
Constante para definir a quantidade de colunas de todos os campos
*/
const int QUANTIDADE_COLUNAS = 20;

/*
Constante para definir a quantidade de linhas dos campos pequenos
*/
const int QUANTIDADE_LINHAS_PARA_MENORES = 10;

/*
Constante para definir a quantidade de linhas dos campos m�dios
*/
const int QUANTIDADE_LINHAS_PARA_MEDIOS = 15;

/*
Constante para definir a quantidade de linhas dos campos grandes
*/
const int QUANTIDADE_LINHAS_PARA_GRANDES = 25;

/*
Campo pequeno com os valores inciais
*/
char campoPequeno[QUANTIDADE_LINHAS_PARA_MENORES][QUANTIDADE_COLUNAS] = {
	{ CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA,CERCA, CERCA, CERCA, CERCA, CERCA,CERCA, CERCA, CERCA, CERCA, CERCA,CERCA,CERCA },
	{ CERCA, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO,VAZIO, VAZIO, VAZIO, VAZIO, VAZIO,VAZIO, VAZIO, VAZIO, VAZIO, VAZIO,VAZIO,CERCA },
	{ CERCA, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO,VAZIO, VAZIO, VAZIO, VAZIO, VAZIO,VAZIO, VAZIO, VAZIO, VAZIO, VAZIO,VAZIO,CERCA },
	{ CERCA, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO,VAZIO, VAZIO, VAZIO, VAZIO, VAZIO,VAZIO, VAZIO, VAZIO, VAZIO, VAZIO,VAZIO,CERCA },
	{ CERCA, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO,VAZIO, VAZIO, VAZIO, VAZIO, VAZIO,VAZIO, VAZIO, VAZIO, VAZIO, VAZIO,VAZIO,CERCA },
	{ CERCA, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO,VAZIO, VAZIO, VAZIO, VAZIO, VAZIO,VAZIO, VAZIO, VAZIO, VAZIO, VAZIO,VAZIO,CERCA },
	{ CERCA, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO,VAZIO, VAZIO, VAZIO, VAZIO, VAZIO,VAZIO, VAZIO, VAZIO, VAZIO, VAZIO,VAZIO,CERCA },
	{ CERCA, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO,VAZIO, VAZIO, VAZIO, VAZIO, VAZIO,VAZIO, VAZIO, VAZIO, VAZIO, VAZIO,VAZIO,CERCA },
	{ CERCA, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO,VAZIO, VAZIO, VAZIO, VAZIO, VAZIO,VAZIO, VAZIO, VAZIO, VAZIO, VAZIO,VAZIO,CERCA },
	{ CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA,CERCA, CERCA, CERCA, CERCA, CERCA,CERCA, CERCA, CERCA, CERCA, CERCA,CERCA,CERCA }
};

/*
Campo m�dio com os valores inciais
*/
char campoMedio[QUANTIDADE_LINHAS_PARA_MEDIOS][QUANTIDADE_COLUNAS] = {
	{ CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA,CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA,CERCA },
	{ CERCA, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, CERCA,VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO,CERCA },
	{ CERCA, CERCA, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO,VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO,CERCA },
	{ CERCA, VAZIO, CERCA, VAZIO, CERCA, VAZIO, VAZIO, VAZIO,CERCA, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, VAZIO,CERCA },
	{ CERCA, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, CERCA,VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO,CERCA },
	{ CERCA, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, CERCA,VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, CERCA, CERCA, CERCA, VAZIO, VAZIO,CERCA },
	{ CERCA, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO,VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO,CERCA },
	{ CERCA, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO,VAZIO, VAZIO, CERCA, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, CERCA, CERCA,CERCA },
	{ CERCA, VAZIO, VAZIO, CERCA, VAZIO, CERCA, VAZIO, VAZIO,CERCA, CERCA, CERCA, CERCA, CERCA, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO,CERCA },
	{ CERCA, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, CERCA, VAZIO,VAZIO, CERCA, CERCA, VAZIO, VAZIO, CERCA, CERCA, VAZIO, VAZIO, VAZIO, VAZIO,CERCA },
	{ CERCA, VAZIO, CERCA, VAZIO, CERCA, VAZIO, CERCA, VAZIO,VAZIO, CERCA, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO,CERCA },
	{ CERCA, VAZIO, VAZIO, CERCA, CERCA, VAZIO, CERCA, VAZIO,VAZIO, CERCA, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO,CERCA },
	{ CERCA, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO,VAZIO, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO,CERCA },
	{ CERCA, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, CERCA, VAZIO,VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO,CERCA },
	{ CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA,CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA,CERCA }
};

/*
Campo grande com os valores inciais
*/
char campoGrande[QUANTIDADE_LINHAS_PARA_GRANDES][QUANTIDADE_COLUNAS] = {
	{ CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA,CERCA,CERCA },
	{ CERCA, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO,VAZIO,CERCA },
	{ CERCA, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO,VAZIO,CERCA },
	{ CERCA, VAZIO, VAZIO, CERCA, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO,VAZIO,CERCA },
	{ CERCA, VAZIO, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO,VAZIO,CERCA },
	{ CERCA, VAZIO, CERCA, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO,VAZIO,CERCA },
	{ CERCA, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO,VAZIO,CERCA },
	{ CERCA, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO,VAZIO,CERCA },
	{ CERCA, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, VAZIO, CERCA, CERCA, VAZIO, CERCA, VAZIO, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA,VAZIO,CERCA },
	{ CERCA, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO,CERCA,CERCA },
	{ CERCA, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO,CERCA,CERCA },
	{ CERCA, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO,VAZIO,CERCA },
	{ CERCA, VAZIO, VAZIO, CERCA, CERCA, CERCA, VAZIO, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO,VAZIO,CERCA },
	{ CERCA, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO,VAZIO,CERCA },
	{ CERCA, CERCA, CERCA, CERCA, VAZIO, CERCA, CERCA, CERCA, CERCA, VAZIO, CERCA, VAZIO, CERCA, CERCA, CERCA, CERCA, VAZIO, CERCA,CERCA,CERCA },
	{ CERCA, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, VAZIO,VAZIO,CERCA },
	{ CERCA, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO,VAZIO,CERCA },
	{ CERCA, VAZIO, VAZIO, CERCA, CERCA, CERCA, CERCA, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO,VAZIO,CERCA },
	{ CERCA, VAZIO, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO,VAZIO,CERCA },
	{ CERCA, VAZIO, CERCA, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, CERCA, VAZIO, CERCA,VAZIO,CERCA },
	{ CERCA, VAZIO, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, CERCA, VAZIO, VAZIO,VAZIO,CERCA },
	{ CERCA, CERCA, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, VAZIO, CERCA, CERCA, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO,VAZIO,CERCA },
	{ CERCA, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO,VAZIO,CERCA },
	{ CERCA, VAZIO, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO,VAZIO,CERCA },
	{ CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA,CERCA,CERCA }
};

/*
 * Fun��o para copiar as matrizes padr�es.
 */
void copiar_matriz(int TAMANHO_CAMPO, char campo[][QUANTIDADE_COLUNAS])
{
	switch (TAMANHO_CAMPO) {
	case TAMANHO_PEQUENO:
		for (int linha = 0; linha < QUANTIDADE_LINHAS_PARA_MENORES; linha++) {
			for (int coluna = 0; coluna < QUANTIDADE_COLUNAS; coluna++)
				campo[linha][coluna] = campoPequeno[linha][coluna];
		}
		break;
	case TAMANHO_MEDIO:
		for (int linha = 0; linha < QUANTIDADE_LINHAS_PARA_MEDIOS; linha++) {
			for (int coluna = 0; coluna < QUANTIDADE_COLUNAS; coluna++)
				campo[linha][coluna] = campoMedio[linha][coluna];
		}
		break;
	case TAMANHO_GRANDE:
		for (int linha = 0; linha < QUANTIDADE_LINHAS_PARA_GRANDES; linha++) {
			for (int coluna = 0; coluna < QUANTIDADE_COLUNAS; coluna++)
				campo[linha][coluna] = campoGrande[linha][coluna];
		}
		break;
	}
}

/*
 * Fun��o para escrever os valores contidos em um campo, deve ser utilizado para exibir o campo para o usu�rio
 */
void escreverCampo(char campo[][QUANTIDADE_COLUNAS], int tamanhoCampo)
{
	for (int linha = 0; linha < tamanhoCampo; linha++)
	{
		for (int coluna = 0; coluna < QUANTIDADE_COLUNAS; coluna++) {
			cout << campo[linha][coluna];
		}
		cout << endl;
	}
}

/*
 *	Contar repeti��es dentro da matriz
 */
int contar_chars(char char_count, int LIMITE_LINHAS, char campo[][QUANTIDADE_COLUNAS])
{
	int contar_qtd = 0;
	for (int linha = 0; linha < LIMITE_LINHAS; linha++) {
		for (int coluna = 0; coluna < QUANTIDADE_COLUNAS; coluna++)
			if (campo[linha][coluna] == char_count) {
				contar_qtd++;
			}
	}
	return contar_qtd;
}

/*
 * Fun��o para escrever as posi��es e o campo para o usu�rio
 */
void escreverMedidasCampo(char campo[][QUANTIDADE_COLUNAS], int tamanhoCampo)
{
	cout << "#  : ";
	for (int coluna = 0; coluna < QUANTIDADE_COLUNAS; coluna++)
		cout << coluna << string(3 - to_string(coluna).length(), ' ');
	for (int linha = 0; linha < tamanhoCampo; linha++)
	{
		cout << endl << linha << string(2 - to_string(linha).length(), ' ') << " : ";
		for (int coluna = 0; coluna < QUANTIDADE_COLUNAS; coluna++) {
			cout << campo[linha][coluna] << "  ";
		}
	}
}

/*
 * Fun��o para escrever os valores de um dos campos, de acordo com o par�metro
 * Utilize as constantes de TAMANHO na biblioteca para selecionar o campo que deve ser escrito
 */
void escreverUmDosCampos(int tamanho)
{
	switch (tamanho)
	{
	case TAMANHO_PEQUENO:
		escreverCampo(campoPequeno, QUANTIDADE_LINHAS_PARA_MENORES);
		break;
	case TAMANHO_MEDIO:
		escreverCampo(campoMedio, QUANTIDADE_LINHAS_PARA_MEDIOS);
		break;
	case TAMANHO_GRANDE:
		escreverCampo(campoGrande, QUANTIDADE_LINHAS_PARA_GRANDES);
		break;
	}
}

/*
 *	Verificar se a posi��o escolhida � valida para os padr�es da matriz e se est� vazia.
 */
bool aplicar_posicao(int posicao_x, int posicao_y, int TAMANHO, char campo[][QUANTIDADE_COLUNAS])
{
	bool resultado_posicao = false;
	switch (TAMANHO)
	{
	case TAMANHO_PEQUENO:
		resultado_posicao = (posicao_x < QUANTIDADE_LINHAS_PARA_MENORES && posicao_y < QUANTIDADE_COLUNAS);
		if (resultado_posicao)
			resultado_posicao = campo[posicao_x][posicao_y];
		break;
	case TAMANHO_MEDIO:
		resultado_posicao = (posicao_x < QUANTIDADE_LINHAS_PARA_MEDIOS && posicao_y < QUANTIDADE_COLUNAS);
		if (resultado_posicao)
			resultado_posicao = campo[posicao_x][posicao_y];
		break;
	case TAMANHO_GRANDE:
		resultado_posicao = (posicao_x < QUANTIDADE_LINHAS_PARA_GRANDES && posicao_y < QUANTIDADE_COLUNAS);
		if (resultado_posicao)
			resultado_posicao = campo[posicao_x][posicao_y];
		break;
	}
	return resultado_posicao;
}

/*
 *	Marcar regi�es para in�cio da prolifera��o do campo
 */
void definir_ponto_proliferacao(int posicao_x, int posicao_y, char campo[][QUANTIDADE_COLUNAS])
{
	if (campo[posicao_x][posicao_y] == VAZIO) campo[posicao_x][posicao_y] = VIRUS_ALT;
}

/*
 *	Iniciar e proliferar o v�rus atrav�s de par�metros.
 */
void infectar_por_parametro(char infeccao_origem, int posicao_x, int posicao_y, char campo[][QUANTIDADE_COLUNAS], bool ignorar_primeiro = true)
{
	if (campo[posicao_x][posicao_y] == VAZIO || (campo[posicao_x][posicao_y] == VIRUS_ALT && ignorar_primeiro)) {
		ignorar_primeiro = false;
		campo[posicao_x][posicao_y] = infeccao_origem;
		infectar_por_parametro(VIRUS, posicao_x + 1, posicao_y, campo, ignorar_primeiro);
		infectar_por_parametro(VIRUS, posicao_x - 1, posicao_y, campo, ignorar_primeiro);
		infectar_por_parametro(VIRUS, posicao_x, posicao_y + 1, campo, ignorar_primeiro);
		infectar_por_parametro(VIRUS, posicao_x, posicao_y - 1, campo, ignorar_primeiro);
	}
}

/*
 *	Iniciar e proliferar o v�rus atrav�s de par�metros, mostrando a atualiza��o na tela.
 */
void infectar_por_parametro(char infeccao_origem, int posicao_x, int posicao_y, char campo[][QUANTIDADE_COLUNAS], int QUANTIDADE_LINHAS, int MILISECONDS, bool ignorar_primeiro = true)
{
	if (campo[posicao_x][posicao_y] == VAZIO || (campo[posicao_x][posicao_y] == VIRUS_ALT && ignorar_primeiro)) {
		ignorar_primeiro = false;
		campo[posicao_x][posicao_y] = infeccao_origem;
		system("cls");
		escreverCampo(campo, QUANTIDADE_LINHAS);
		Sleep(MILISECONDS);
		infectar_por_parametro(VIRUS, posicao_x + 1, posicao_y, campo, QUANTIDADE_LINHAS, MILISECONDS, ignorar_primeiro);
		infectar_por_parametro(VIRUS, posicao_x - 1, posicao_y, campo, QUANTIDADE_LINHAS, MILISECONDS, ignorar_primeiro);
		infectar_por_parametro(VIRUS, posicao_x, posicao_y + 1, campo, QUANTIDADE_LINHAS, MILISECONDS, ignorar_primeiro);
		infectar_por_parametro(VIRUS, posicao_x, posicao_y - 1, campo, QUANTIDADE_LINHAS, MILISECONDS, ignorar_primeiro);
	}
}

/*
 *	Iniciar prolifera��o a partir de casas j� infectadas
 */
void iniciar_proliferacao(int QUANTIDADE_LINHAS, char campo[][QUANTIDADE_COLUNAS], int MILISECONDS)
{
	if (MILISECONDS == 0) {
		for (int linha = 0; linha < QUANTIDADE_LINHAS; linha++) {
			for (int coluna = 0; coluna < QUANTIDADE_COLUNAS; coluna++)
				if (campo[linha][coluna] == VIRUS_ALT) infectar_por_parametro(VIRUS_ALT, linha, coluna, campo);
		}
	}
	else {
		for (int linha = 0; linha < QUANTIDADE_LINHAS; linha++) {
			for (int coluna = 0; coluna < QUANTIDADE_COLUNAS; coluna++)
				if (campo[linha][coluna] == VIRUS_ALT) infectar_por_parametro(VIRUS_ALT, linha, coluna, campo, QUANTIDADE_LINHAS, MILISECONDS);
		}
	}
}

/*
 *	Quantificar quantidade de �reas infectadas
 *	O score � definido negativamente atrav�s da quantidade de casas atingidas + saldo positivo de cercas N�O UTILIZADAS
 *	Portanto, a melhor solu��o � aquela que utiliza menos cercas e evita infec��o da menor quantidade de casas
 */
int infectarScore(char infec_origem, char cerca_artifical, int QUANTIDADE_LINHAS, char campo[][QUANTIDADE_COLUNAS], int QUANTIDADE_CERCAS)
{
	//Quantidade m�xima de origens para infesta��o
	for (int i = 0; i < 5; i++) {
		//Procurar focos atrav�s das linhas
		for (int j = 0; j < QUANTIDADE_LINHAS; j++) {
			//Procurar focos atrav�s das colunas
			for (int k = 0; k < QUANTIDADE_COLUNAS; k++)
				if (campo[j][k] == infec_origem) infectar_por_parametro(VIRUS, j, k, campo);
		}
	}
	//Quantificar infec��es e cercas n�o utilizadas.
	int quantidade_infectada = 0; int cercas_utilizadas = 0;
	for (int i = 0; i < QUANTIDADE_LINHAS; i++) {
		for (int j = 0; j < QUANTIDADE_COLUNAS; j++) {
			if (campo[i][j] == VIRUS) {
				//Contar quantidade de casas infectadas e limpar o valor das �reas
				//para n�o comprometer o estado da matriz
				quantidade_infectada--;
				campo[i][j] = VAZIO;
			}
			else if (campo[i][j] == cerca_artifical)
				cercas_utilizadas++;
		}
	}
	return quantidade_infectada + (QUANTIDADE_CERCAS - cercas_utilizadas);
}
