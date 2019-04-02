// cppVsZombies.cpp: Define o ponto de entrada para a aplica��o de console.
//

#include "stdafx.h"
#include "Flood.h"
#include <Windows.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <time.h>

/*
 *	Menu principal.
 *	A primeira vez que este � executado o mostrar_incoming � verdadeiro.
 *	Portanto, ele chamar� a fun��o "incoming_connection" para dar tem�tica ao trabalho.
 */
void begin_connect(bool mostrar_incoming = false);
/*
 *	Fun��o para dar tem�tica ao trabalho.
 */
void incoming_connection();
/*
 *	Menu para escolher qual o tamanho do campo para simular a prolifera��o.
 */
void opcao_simular_proliferacao();
/*
 *	Simulador de prolifera��o para o campo pequeno.
 */
void opcao_simulador_pequeno();
/*
 *	Simulador de prolifera��o para o campo m�dio.
 */
void opcao_simulador_medio();
/*
 *	Simulador de prolifera��o para o campo grande.
 */
void opcao_simulador_grande();

int main()
{
	setlocale(LC_ALL, "Portuguese");
	char continuar_programa = 'c';
	bool mostrar_incoming = true;
	while (continuar_programa != 'z' && continuar_programa != 'Z') {
		begin_connect(mostrar_incoming);
		mostrar_incoming = false;
		cout << endl << endl << "Digite Z para sair ou qualquer tecla para continuar... ";
		cin.ignore(); //ignorar enter
		cin.sync(); //sincronizar
		cin.get(continuar_programa);
	}
	return 0;
}

void alterar_cor(int cor)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), cor);
}

void begin_connect(bool mostrar_incoming) {
	/*
	Cabe�alho do menu
	*/
	system("cls");
	cout << "/*" << endl
		<< " * TOPSECRET" << endl
		<< " * ALBERTO // JOSE ZANCANARO // LUCAS CARDONE" << endl
		<< " * Sistema para simula��o de Conten��o do v�rus X." << endl
		<< " * Vers�o 1.2" << endl
		<< " */" << endl << endl;
	/*
	ALBERTO??
	*/
	if (mostrar_incoming) incoming_connection();
	/*
	Menu principal
	*/
	cout << endl << endl << ">>Selecione abaixo o n�mero da op��o desejada:" << endl << endl
		 << "1 - Simular prolifera��o em diversos campos." << endl
		 << "2 - Simular melhor estrat�gia para conten��o." << endl << endl
		 << "\\Univali51\\System64>";
	int i = 0; cin >> i;
	switch (i) {
	case 1:
		opcao_simular_proliferacao();
		break;
	case 2:
		cout << "//nada ainda";
		break;
	}
}

void incoming_connection()
{
	/*
	 *	Mensagens do nosso parceiro de trabalho, vulgo Alberto.
	 */
	string albert_msg1 = "\nSauda��es!\n\nVenho dizer que resist�ncia posterior n�o trar� resultado, a menos que";
	string albert_msg2 = "\n\n[Connection lost]\n\nUser: 4LB3RT0\nSent time: 16/06/2020\n\n";
	/*
	 *	Univali51
	 */
	cout << "\\\Connecting to Univali51 Servers..." << endl;
	Sleep(250); alterar_cor(12);
	//Mensagem Alberto 1 com efeito de digita��o
	for (int i = 0; i < albert_msg1.length(); i++) {
		cout << albert_msg1.substr(i, 1);
		Sleep(50);
	}
	//Mensagem Alberto 2, conex�o perdida
	Sleep(1000);
	cout << albert_msg2;
	Sleep(250);
	//Voltar cor ao normal
	alterar_cor(7);
	cout << "\\\Connection established!";
}

void opcao_simular_proliferacao()
{
	system("cls");
	cout << "Simular prolifera��o: Escolha o campo desejado:" << endl << endl;
	/*
	 * CAMPO PEQUENO
	 */
	cout << string(20, '-') + "\n1: CAMPO PEQUENO\n\n";
	escreverUmDosCampos(TAMANHO_PEQUENO);
	cout << "\n" + string(20, '-') + "\n\n";
	/*
	 * CAMPO M�DIO
	 */
	cout << string(20, '-') + "\n2: CAMPO M�DIO\n\n";
	escreverUmDosCampos(TAMANHO_MEDIO);
	cout << "\n" + string(20, '-') + "\n\n";
	/*
	 * CAMPO GRANDE
	 */
	cout << string(20, '-') + "\n3: CAMPO GRANDE\n\n";
	escreverUmDosCampos(TAMANHO_GRANDE);
	cout << "\n" + string(20, '-');
	/*
	 * Menu
	 */
	int escolha_campo = 0; string mensagem = "Escolha o campo para simula��o:";
	while (escolha_campo <= 0 || escolha_campo > 4) {
		//Op��es do menu
		cout << endl << endl << mensagem << endl << endl 
			 << "1 - Campo Pequeno"<< endl
			 << "2 - Campo M�dio" << endl
			 << "3 - Campo Grande" << endl
			 << "4 - Voltar" << endl << endl 
			 << "\\Univali51\\System64\\Simulacao-Proliferacao>";
		cin >> escolha_campo;
		//Alterar a mensagem a ser escrita, caso o while n�o seja finalizado.
		mensagem = "Op��o inv�lida! Especifique um campo de 1 a 3.";
	}
	/*
	 * Designar para a fun��o correspondente, de acordo com a escolha do usu�rio.
	 */
	switch (escolha_campo) {
	case 1:
		opcao_simulador_pequeno();
		break;
	case 2:
		opcao_simulador_medio();
		break;
	case 3:
		opcao_simulador_grande();
		break;
	case 4:
		begin_connect();
		break;
	}
}

void opcao_simulador_pequeno()
{
	system("cls");

	//Cria��o de um novo campo, baseado no modelo PEQUENO
	char novoCampo[QUANTIDADE_LINHAS_PARA_MENORES][QUANTIDADE_COLUNAS];
	copiar_matriz(TAMANHO_PEQUENO, novoCampo);

	//Exibi��o do campo
	cout << "# CAMPO PEQUENO #" << endl << endl;
	escreverMedidasCampo(novoCampo, QUANTIDADE_LINHAS_PARA_MENORES);

	//Definir posi��o de in�cio do v�rus
	int x = 0, y = 0; string msg_desc = "Digite a posi��o de origem do v�rus: ";
	while (aplicar_posicao(x, y, TAMANHO_PEQUENO, novoCampo)) {
		cout << endl << endl << msg_desc << endl << endl;
		cout << "\\Univali51\\System64\\Simulacao-Proliferacao\\Campo-Pequeno\\[Param X]>";
		cin >> x;
		cout << "\\Univali51\\System64\\Simulacao-Proliferacao\\Campo-Pequeno\\[Param Y]>";
		cin >> y;
		msg_desc = "Op��o inv�lida. Tente novamente.";
	}
	definir_ponto_proliferacao(x, y, novoCampo);

	//Definir m�todo de exibi��o
	int tempo_espera = -1; 
	string msg_desc_time = "Escreva o valor de espera entre atualiza��o das casas em MILISEGUNDOS\nRecomendado: 150\nM�ximo: 1000\nPara ver apenas o resultado final, apenas digite 0.";
	while (tempo_espera < 0 || tempo_espera > 1000) {
		cout << endl << endl << msg_desc_time << endl << endl;
		cout << "\\Univali51\\System64\\Simulacao - Proliferacao\\Campo - Pequeno\\[Param Time]>";
		cin >> tempo_espera;
		msg_desc_time = "Op��o inv�lida, tente novamente.";
	}

	//In�cio de prolifera��o
	iniciar_proliferacao(QUANTIDADE_LINHAS_PARA_MENORES, novoCampo, tempo_espera);

	//Fim da rotina
	system("cls");
	cout << "# CAMPO PEQUENO #" << endl << endl;
	escreverCampo(novoCampo, QUANTIDADE_LINHAS_PARA_MENORES);

	//Contar resultados
	int	casas_disponiveis = contar_chars(VAZIO, QUANTIDADE_LINHAS_PARA_MENORES, campoPequeno);
	int	casas_infectadas = contar_chars(VIRUS, QUANTIDADE_LINHAS_PARA_MENORES, novoCampo) + contar_chars(VIRUS_ALT, QUANTIDADE_LINHAS_PARA_MENORES, novoCampo);
	cout << endl << "Totais de casas dispon�veis (vazias) : " << casas_disponiveis;
	cout << endl << "Totais de casas infectadas           : " << casas_infectadas;
}

void opcao_simulador_medio()
{
	system("cls");

	//Cria��o de um novo campo, baseado no modelo PEQUENO
	char novoCampo[QUANTIDADE_LINHAS_PARA_MEDIOS][QUANTIDADE_COLUNAS];
	copiar_matriz(TAMANHO_MEDIO, novoCampo);

	//Exibi��o do campo
	cout << "# CAMPO M�DIO #" << endl << endl;
	escreverMedidasCampo(novoCampo, QUANTIDADE_LINHAS_PARA_MEDIOS);

	//Definir posi��o de in�cio do v�rus
	int x = 0, y = 0; string msg_desc = "Digite a posi��o de origem do v�rus: ";
	while (aplicar_posicao(x, y, TAMANHO_MEDIO, novoCampo)) {
		cout << endl << endl << msg_desc << endl << endl;
		cout << "\\Univali51\\System64\\Simulacao-Proliferacao\\Campo-Medio\\[Param X]>";
		cin >> x;
		cout << "\\Univali51\\System64\\Simulacao-Proliferacao\\Campo-Medio\\[Param Y]>";
		cin >> y;
		msg_desc = "Op��o inv�lida. Tente novamente.";
	}
	definir_ponto_proliferacao(x, y, novoCampo);

	//Definir m�todo de exibi��o
	int tempo_espera = -1; string msg_desc_time = "Escreva o valor de espera entre atualiza��o das casas em MILISEGUNDOS\nRecomendado: 150\nM�ximo: 1000\nPara ver apenas o resultado final, apenas digite 0.";
	while (tempo_espera < 0 || tempo_espera > 1000) {
		cout << endl << endl << msg_desc_time << endl << endl;
		cout << "\\Univali51\\System64\\Simulacao - Proliferacao\\Campo - Medio\\[Param Time]>";
		cin >> tempo_espera;
		msg_desc_time = "Op��o inv�lida, tente novamente.";
	}

	//In�cio de prolifera��o
	iniciar_proliferacao(QUANTIDADE_LINHAS_PARA_MEDIOS, novoCampo, tempo_espera);

	//Fim da rotina
	system("cls");
	cout << "# CAMPO M�DIO #" << endl << endl;
	escreverCampo(novoCampo, QUANTIDADE_LINHAS_PARA_MEDIOS);

	//Contar resultados
	int	casas_disponiveis = contar_chars(VAZIO, QUANTIDADE_LINHAS_PARA_MEDIOS, campoMedio);
	int	casas_infectadas = contar_chars(VIRUS, QUANTIDADE_LINHAS_PARA_MEDIOS, novoCampo) + contar_chars(VIRUS_ALT, QUANTIDADE_LINHAS_PARA_MEDIOS, novoCampo);
	cout << endl << "Totais de casas dispon�veis (vazias) : " << casas_disponiveis;
	cout << endl << "Totais de casas infectadas           : " << casas_infectadas;
}

void opcao_simulador_grande()
{
	system("cls");

	//Cria��o de um novo campo, baseado no modelo PEQUENO
	char novoCampo[QUANTIDADE_LINHAS_PARA_GRANDES][QUANTIDADE_COLUNAS];
	copiar_matriz(TAMANHO_GRANDE, novoCampo);

	//Exibi��o do campo
	cout << "# CAMPO GRANDE #" << endl << endl;
	escreverMedidasCampo(novoCampo, QUANTIDADE_LINHAS_PARA_GRANDES);

	//Definir posi��o de in�cio do v�rus
	int x = 0, y = 0; string msg_desc = "Digite a posi��o de origem do v�rus: ";
	while (aplicar_posicao(x, y, TAMANHO_GRANDE, novoCampo)) {
		cout << endl << endl << msg_desc << endl << endl;
		cout << "\\Univali51\\System64\\Simulacao-Proliferacao\\Campo-Grande\\[Param X]>";
		cin >> x;
		cout << "\\Univali51\\System64\\Simulacao-Proliferacao\\Campo-Grande\\[Param Y]>";
		cin >> y;
		msg_desc = "Op��o inv�lida. Tente novamente.";
	}
	definir_ponto_proliferacao(x, y, novoCampo);

	//Definir m�todo de exibi��o
	int tempo_espera = -1; string msg_desc_time = "Escreva o valor de espera entre atualiza��o das casas em MILISEGUNDOS\nRecomendado: 150\nM�ximo: 1000\nPara ver apenas o resultado final, apenas digite 0.";
	while (tempo_espera < 0 || tempo_espera > 1000) {
		cout << endl << endl << msg_desc_time << endl << endl;
		cout << "\\Univali51\\System64\\Simulacao - Proliferacao\\Campo - Grande\\[Param Time]>";
		cin >> tempo_espera;
		msg_desc_time = "Op��o inv�lida, tente novamente.";
	}

	//In�cio de prolifera��o
	iniciar_proliferacao(QUANTIDADE_LINHAS_PARA_GRANDES, novoCampo, tempo_espera);

	//Fim da rotina
	system("cls");
	cout << "# CAMPO GRANDE #" << endl << endl;
	escreverCampo(novoCampo, QUANTIDADE_LINHAS_PARA_GRANDES);

	//Contar resultados
	int	casas_disponiveis = contar_chars(VAZIO, QUANTIDADE_LINHAS_PARA_GRANDES, campoGrande);
	int	casas_infectadas = contar_chars(VIRUS, QUANTIDADE_LINHAS_PARA_GRANDES, novoCampo) + contar_chars(VIRUS_ALT, QUANTIDADE_LINHAS_PARA_GRANDES, novoCampo);
	cout << endl << "Totais de casas dispon�veis (vazias) : " << casas_disponiveis;
	cout << endl << "Totais de casas infectadas           : " << casas_infectadas;
}