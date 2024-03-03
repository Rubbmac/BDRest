#include "Header.h"

void criar::matStock(string** m) {

	m[0][0] = "ID";
	m[0][1] = "Stock";
	m[0][2] = "Validade";
	m[0][3] = "Nome do Prato";
	m[0][4] = "Preco";
	m[0][5] = "Nr Vendas";

	m[1][0] = "1";
	m[1][1] = "5";
	m[1][2] = "31/12/2023";
	m[1][3] = "Francesinha";
	m[1][4] = "13.00";
	m[1][5] = "2";

	m[2][0] = "2";
	m[2][1] = "5";
	m[2][2] = "31/12/2023";
	m[2][3] = "Feijoada";
	m[2][4] = "7.50";
	m[2][5] = "1";

	m[3][0] = "3";
	m[3][1] = "5";
	m[3][2] = "31/12/2023";
	m[3][3] = "Frango assado";
	m[3][4] = "9.00";
	m[3][5] = "2";

	m[4][0] = "4";
	m[4][1] = "5";
	m[4][2] = "31/12/2023";
	m[4][3] = "Bacalhau";
	m[4][4] = "15.00";
	m[4][5] = "1";

	m[5][0] = "5";
	m[5][1] = "5";
	m[5][2] = "31/12/2023";
	m[5][3] = "Filetes";
	m[5][4] = "6.00";
	m[5][5] = "0";
}
void criar::matCliente(string** m) {
	m[0][0] = "ID Cliente";
	m[0][1] = "Nome Cliente";
	m[0][2] = "Contacto";
	m[0][3] = "Morada";
	m[0][4] = "Nr Compras";

	m[1][0] = "1";
	m[1][1] = "Rita";
	m[1][2] = "912345678";
	m[1][3] = "Porto";
	m[1][4] = "2";

	m[2][0] = "2";
	m[2][1] = "Carla";
	m[2][2] = "913456789";
	m[2][3] = "Porto";
	m[2][4] = "10";

	m[3][0] = "3";
	m[3][1] = "Joaq.";
	m[3][2] = "934567892";
	m[3][3] = "Perafita";
	m[3][4] = "5";

	m[4][0] = "4";
	m[4][1] = "Pedro";
	m[4][2] = "931245678";
	m[4][3] = "Ermesinde";
	m[4][4] = "2";

	m[5][0] = "5";
	m[5][1] = "Afonso";
	m[5][2] = "913245768";
	m[5][3] = "Trofa";
	m[5][4] = "10";
}
void criar::matRecibo(string** m) {

	// as 3 primeiras colunas e 3 ultimas colunas, serao sempre correspondentes ás informaçoes abaixo indicadas
	// as colunas para linha, nome, quantidade e preço unitario, poderam aumentar caso sejam inserido mais que um prato
	m[0][0] = "contador de pratos inseridos";
	m[0][1] = "ID do Recibo";
	m[0][2] = "ID do cliente";
	m[0][3] = "Linha do prato";
	m[0][4] = "Nome do prato";
	m[0][5] = "Quantidade do prato";
	m[0][6] = "Preco unitario do prato";
	m[0][7] = "Total do recibo";
	m[0][8] = "Valor pago";
	m[0][9] = "Troco";
	m[9][10] = "Data";
}