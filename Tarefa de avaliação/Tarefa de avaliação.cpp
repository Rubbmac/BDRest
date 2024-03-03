#include "Header.h"

void imprimirStock(string** m, int *l) {
	cout << "\n \n STOCK ATUAL \n \n";
	//escrever as informaçoes de cada prato
	cout << "|" << m[0][0] << "\t|" << m[0][1] << "\t|" << m[0][2] << " \t|" << m[0][3] << " \t|" << m[0][4] << " \t|" << m[0][5] << "\t|" << endl;
	for (int i = 1; i < *l+1; i++)
	{
		cout << "|";
		for (int e = 0; e < 6; e++) //bloqueia as colunas em 6, porque nao ha mais (corresponde aos dados)
		{
			cout << m[i][e]; // imprimir as posiçoes de cada cliente
			cout << "\t|";
		}
		cout << endl;
	}
	cout << "\n";
}
void imprimirCliente(string** m, int* l) {
	cout << "\n \n LISTA CLIENTES ATUAL \n \n";
	//escrever as informaçoes de cada cliente
	cout << "|" << m[0][0] << "\t|" << m[0][1] << "\t|" << m[0][2] << " \t|" << m[0][3] << " \t|" << m[0][4] << " \t|" << endl;
	for (int i = 1; i < *l + 1; i++)
	{
		cout << "|";
		for (int e = 0; e < 5; e++) //bloqueia as colunas em 5, porque nao ha mais (corresponde aos dados)
		{
			cout << m[i][e]; // imprimir as informaçoes de cada cliente
			cout << "\t|";
		}
		cout << endl;
	}
	cout << "\n";

}
void criarMatriz(string** m, int l, int c) {
	for (int k = 0; k < l; k++)
	{
		m[k] = new string[c];
	}
}
bool verificaInt(string n) { 
	for (char c : n) {
		if (!isdigit(c)) {	// early return 
			cout << endl << "Erro, por favor insira um numero valido. \n";
			return false;
		}
	}
	return true;
}
bool isValidDecimal(const string& input) {
	stringstream ss(input);
	double value;
	return (ss >> value) && (ss.eof());
}
string verificaDouble() {
	string n;
	bool v;
	do
	{
		cin >> n;
		v= isValidDecimal(n);
		if (v==false)
		{
			cout << "\nNumero decimal invalido, por favor insira novamente.";
			cout << endl << "Dica: verifique o uso de '.' em vez de ',' de modo a validar o numero.\n";
		}
	} while (v==false);
	return n;
}


// garante que o numero inserido é um inteiro de 1 a 2
bool verProcedimento2(string p) {
	if (p == "1")
	{
		return true;
	}
	if (p == "2")
	{
		return true;
	}
	else
	{
		cout << endl << "Numero invalido.\n\n";
		return false;
	}
}

// garante que o numero inserido é um inteiro de 1 a 3
bool verProcedimento3(string p) {
	if (p=="1")
	{
		return true;
	}
	if (p=="2")
	{
		return true;
	}
	if (p=="3")
	{
		return true;
	}
	else
	{
		cout << endl << "Numero invalido.\n\n";
		return false;
	}
}  

// garante que o numero inserido é um inteiro de 1 a 4
bool verProcedimento4(string p) {
	if (p == "1")
	{
		return true;
	}
	if (p == "2")
	{
		return true;
	}
	if (p == "3")
	{
		return true;
	}
	if (p == "4")
	{
		return true;
	}
	else
	{
		cout << endl << "Numero invalido.\n\n";
		return false;
	}
} 



		// PARA OS PEDIDOS //

void imprimeRecibo(string** mRec, int* cRec) {
	int aux;
	cout << "\nNr. Pedido: " << mRec[*cRec][1] << endl;
	cout << "Nr. Cliente:" << mRec[*cRec][2] << endl;
	aux = stoi(mRec[*cRec][0]); // auxiliar igual á quantidade de linhas de pratos
	for (int k = 1; k <= aux; k++) // imprime recibo
	{
		cout << "Linha: " << mRec[*cRec][k * 4 - 1] << endl;
		cout << "Prato: " << mRec[*cRec][k * 4] << endl;
		cout << "Quantidade: " << mRec[*cRec][k * 4 + 1] << endl;
		cout << "Preco unitario: " << stod(mRec[*cRec][k * 4 + 2]) << " eur" << endl;
	}
	// cout << setprecision(2) << fixed;
	cout << "Preco total: " << stod(mRec[*cRec][aux * 4 + 3]) << " eur" << endl;
	cout << "Valor pago: " << stod(mRec[*cRec][aux * 4 + 4]) << " eur" << endl;
	cout << "Troco: " << stod(mRec[*cRec][aux * 4 + 5]) << " eur" << endl;
	cout << "Data do recibo: " << mRec[*cRec][aux * 4 + 6] << endl;
}
void adicionaCompra(string** m, string idCliente) {

	m[stoi(idCliente)][4] = to_string(stoi(m[stoi(idCliente)][4]) + 1); //converte valor atual de compras para inteiro (stoi), adiciona +1 compra e volta a converter para texto (to_string) para repor na matriz cliente
}
bool verificaStock(string** m, string id, string q) {

	if (stoi(m[stoi(id)][1]) < stoi(q)) // se stock for menor que a quantidade pedida
	{
		cout << "\nStock insuficiente" << " (" << m[stoi(id)][1] << " pratos).\n";
		return false;
	}
	return true;
}
void removerStock(string** m, string id, string qtd) {
	m[stoi(id)][1] = to_string(stoi(m[stoi(id)][1]) - stoi(qtd));
}
void adicionaVenda(string** m, string id, string qtd) {
	m[stoi(id)][5] = to_string(stoi(m[stoi(id)][5]) - stoi(qtd));
}
string dataAuto() {

	time_t currentTime = time(NULL); //le a data e hora atual

	//converte a data e hora atual para um string
	stringstream ss;
	ss << put_time(localtime(&currentTime), "%d/%m/%Y %H:%M:%S"); //vai buscar uma funcao à biblioteca "iomanip" para a conversao
	string dateString = ss.str();
	return dateString;

}
string verificaTotal(string total) {
	string vPago;
	bool v=false;
	cout << "\nInsira o valor pago pelo cliente.\n";
	do
	{
		vPago = verificaDouble();	//pede para introduzir o valor pago e verifica se é decimal valido
		if (stod(vPago)<stod(total))	//verifica se valor é suficiente para pagar o total
		{
			v = false;
			cout << "\nValor insuficiente, pf volte a inserir.\n";
		}
		else
		{
			v = true;
		}

	} while (v==false);
	return vPago;

}
string precoTotal(string** m, int* c) {
	double total=0;

	for (int i = 6; i < (stoi(m[*c][0])*4+3); i = i + 4)	//le 
	{
		total = total + (stod(m[*c][i])) * (stod(m[*c][i-1]));
	}
	string t;
	t = to_string(total);
	return t;
}
bool verifIdMenu(string** m, int* c, string id) {
	for (int i = 1; i < *c + 1; i++)
	{
		if (stoi(m[i][1]) != 0) //verifica stock do prato que está a ser lido no ciclo
		{
			if (id==m[i][0]) //verifica se o prato lido no ciclo, é o prato inserido pelo utilizador
			{
				return true;
			}
		}
	}
	return false;
}
void menu(string** m, int* l) {
	cout << "\n\n	MENU\n\n";
	//escrever as informaçoes de cada prato

	for (int i = 1; i < *l + 1; i++)
	{
		if (stoi(m[i][1])!=0) //so imprime se o stock for maior que 0
		{
			cout << "| ID: " << m[i][0] << " | " << m[i][3] << " - " << (stod(m[i][4])*1.3) << " eur. | " << m[i][1] << " pratos em stock\n"; //apenas imprime no MENU o nome e preço do prato
		}
	}
	cout << "\n";
}
string adicionaPratoRecibo(string** mSto, int* cSto, string** mRec, int* cRec) {
	bool v = false;
	string idPrato;
	do
	{
		menu(mSto, cSto); //so apresenta pratos existentes e com stock positivo
		cout << "\nInsira o ID do prato\n";
		cin >> idPrato;
		v = verifIdMenu(mSto, cSto, idPrato); // verifica se o id inserido é valido
		if (v == false)
		{
			cout << "\nID inexistente ou sem stock, por favor volte a inserir.\n";
		}
	} while (v == false);
	mRec[*cRec][(4*stoi(mRec[*cRec][0]))-1] = mRec[*cRec][0];	//coloca o nr da linha do prato
	mRec[*cRec][(4 * stoi(mRec[*cRec][0]))] = mSto[stoi(idPrato)][3];	//coloca o nome do prato
	string qtd;
	cout << "\nQuantos pratos deseja?\n";
	do
	{
		cin >> qtd;
		v = verificaInt(qtd);
		if (v == false)
		{
			cout << endl << "Insira novamente a quantidade.\n";
		}
		if (v == true)
		{
			v = verificaStock(mSto, idPrato, qtd);
			if (v == true)
			{
				removerStock(mSto, idPrato, qtd);	//remove stock do prato na matriz stock
				adicionaVenda(mSto, idPrato, qtd);	//adiciona a venda na matriz stock
			}

		}
	} while (v == false);
	mRec[*cRec][(4 * stoi(mRec[*cRec][0]))+1] = qtd;	//coloca a quantidade do prato no recibo

	return idPrato;
}
void pedido(string** mRec, int* cRec, string** mSto, int* cSto, string** mCli, int* cCli) {
	
	string s;
	imprimirCliente(mCli, cCli);	//imprime a lista de clientes, de modo a associar o cliente a um pedido
	cout << "\nIndique o ID do cliente para registar o pedido.\n";
	string idCliente;
	bool v = false;
	do
	{
		do
		{
			v = false;
			cin >> idCliente;
			v = verificaInt(idCliente); //verifica se o nr inserido é inteiro
		} while (v==false);
		v = false;
		if (stoi(idCliente) > 0 && stoi(idCliente) <= *cCli) //verifica se o nr inserido corresponde a algum cliente na base de dados
		{
			v = true;
		}
		else
		{
			v = false;
			cout << "\nID inexistente, por favor insira novamente.\n";
		}
	} while (v == false);

	mRec[*cRec][0] = "1";	// contador de linhas de pratos passa a 1, pois é o primeiro prato
	mRec[*cRec][1] = to_string(*cRec);	//id do recibo
	mRec[*cRec][2] = idCliente;

	string idPrato=adicionaPratoRecibo(mSto, cSto, mRec, cRec);
	mRec[*cRec][(4 * stoi(mRec[*cRec][0]))+2] = to_string(stod(mSto[stoi(idPrato)][4])*1.3); // coloca o preco unitario do prato inserido (multiplica o custo por 1.3

	cout << "\nDeseja adicionar mais algum prato? ('s' para sim, 'n' para nao)\n";
	string v1;

	do
	{
		cin >> v1;
	} while (v1 != "n" && v1 != "s");	//verifica se a insercao é "n" ou "s"

	if (v1=="s")
	{
		do
		{
			mRec[*cRec][0] = to_string(stoi(mRec[*cRec][0]) + 1); //aumenta o contador de pratos(linhas de prato) no recibo
			idPrato = adicionaPratoRecibo(mSto, cSto, mRec, cRec);
			mRec[*cRec][(4 * stoi(mRec[*cRec][0]))+2] = to_string(stod(mSto[stoi(idPrato)][4])*1.3);
			cout << "\nDeseja adicionar mais algum prato? ('s' para sim, 'n' para nao)\n";
			do
			{
				cin >> v1;
			} while (v1 != "n" && v1 != "s");
		} while (v1=="s");
	}
	if (v1=="n")
	{
		int oferta;
		oferta = 1 + (rand() % 1000);
		if (oferta==500)	// o nr 500 corresponde ao numero da sorte de modo a ter a refeicao gratis, este nr podera ser atribuido ou nao, na variavel (aleatoria) "oferta"
		{
			cout << "\nParabens, foi o selecionado para oferta da refeicao!!\n";

			//coloca os seguintes campos (valor total, valor pago e troco) a 0, porque a refeiçao foi oferecida, mas convem ter um registo
			mRec[*cRec][3 + (4 * stoi(mRec[*cRec][0]))] = "0"; 
			mRec[*cRec][4 + (4 * stoi(mRec[*cRec][0]))] = "0";
			mRec[*cRec][5 + (4 * stoi(mRec[*cRec][0]))] = "0";
		}
		else
		{
			mRec[*cRec][3 + (4 * stoi(mRec[*cRec][0]))] = precoTotal(mRec, cRec); //funcao multiplicar pre unit. por qtd e somar o total dos diferentes pratos
			cout << "\nPreco total:" << endl << stod(mRec[*cRec][3 + (4 * stoi(mRec[*cRec][0]))]) << "\n";
			mRec[*cRec][4 + (4 * stoi(mRec[*cRec][0]))] = verificaTotal(mRec[*cRec][3 + (4 * stoi(mRec[*cRec][0]))]); //utilizador insere preço decimal, e tem de ser maior que total
			mRec[*cRec][5 + (4 * stoi(mRec[*cRec][0]))] = to_string(stod(mRec[*cRec][4 + (4 * stoi(mRec[*cRec][0]))]) - stod(mRec[*cRec][3 + (4 * stoi(mRec[*cRec][0]))])); //vpago-total	
			cout << "\nTroco: " << stod(mRec[*cRec][5 + (4 * stoi(mRec[*cRec][0]))]) << " eur\n";
		}
		mRec[*cRec][6 + (4 * stoi(mRec[*cRec][0]))] = dataAuto();	//coloca a data automaticamente no fim do recibo

		cout << "\nDeseja imprimir recibo? ('s' para sim, 'n' para nao)\n";
		do
		{
			cin >> v1;
		} while (v1 != "n" && v1 != "s");
		
		if (v1=="s")
		{
			imprimeRecibo(mRec, cRec);
		}

	}
	adicionaCompra(mCli, idCliente); //aumenta o numero de vendas ao cliente
	* cRec = *cRec + 1; // contador de recibos aumenta em 1 valor, de modo a dar para ler esta linha na matriz.
}


		// PARA A GESTAO //

void alteraNomeCliente(string** mCli, int* cCli) {
	imprimirCliente(mCli, cCli);
	cout << "\nIndique o ID do cliente que pretende alterar o nome:\n";
	string idCliente;
	bool v = false;
	do
	{
		cin >> idCliente;
		if (stoi(idCliente) > 0 && stoi(idCliente) <= *cCli)
		{
			v = true;
		}
		else
		{
			v = false;
			cout << "\nID inexistente, por favor insira novamente.\n";
		}
	} while (v == false);
	string v1;
	cout << "\nVai alterar o nome do cliente " << mCli[stoi(idCliente)][1] << ", " << mCli[stoi(idCliente)][2] << ", " << mCli[stoi(idCliente)][3];
	cout << "\nTem a certeza que pretende continuar? ('s' para continuar / 'n' para cancelar) \n";
	do
	{
		cin >> v1;
	} while (v1 != "n" && v1 != "s");

	if (v1 == "s")
	{
		string u; //variavel lixo para o getline poder funcionar
		getline(cin, u);
		cout << "\nNovo nome a considerar:\n";
		getline(cin, mCli[stoi(idCliente)][1]);
	}
	else
	{
		cout << "\nOperacao cancelada.\n";
	}
}
void removeCliente(string** mCli, int* cCli) {
	string idCliente;
	bool v = false;
	imprimirCliente(mCli, cCli);
	cout << "Qual o ID do cliente que pretende remover?\n";
	do
	{
		cin >> idCliente;	
		if (stoi(idCliente)>0&&stoi(idCliente)<=*cCli)
		{
			v = true;
		}
		else
		{
			v = false;
			cout << "\nID inexistente, por favor insira novamente.\n";
		}
	} while (v == false);
	string v1;
	cout << "\nVai remover o cliente " << mCli[stoi(idCliente)][1] << ", " << mCli[stoi(idCliente)][2] << ", " << mCli[stoi(idCliente)][3];
	cout << "\nTem a certeza que pretende continuar? ('s' para continuar / 'n' para cancelar) \n";	
	do
	{
		cin >> v1;
	} while (v1!="n"&&v1!="s");
	if (v1=="s")
	{
		for (int i = 1; i < *cCli; i++) //neste ciclo for o contador so ira ler ate ao penultimo prato, porque se o cliente a apagar for o ultimo na lista, basta diminuir um valor ao contador
		{
			if (mCli[i][3] == idCliente)
			{
				//nao troca o valor do ID de modo a manter a consistência entre ID e nr da linha na matriz.
				//simplesmente troca os dados do ultimo cliente para a posicao do cliente que sera removido 
				mCli[i][1] = mCli[*cCli][1];
				mCli[i][2] = mCli[*cCli][2];
				mCli[i][3] = mCli[*cCli][3];
				mCli[i][4] = mCli[*cCli][4];
			}
		}
		*cCli = *cCli - 1;
	}
	else
	{
		cout << "\nOperacao cancelada.\n";
	}
}
bool contaDigitos(string c) {
	double aux;
	aux = stod(c);
	aux = aux - 99999999;
	if (aux >= 1 && aux <= 900000000)
	{
		cout << "\nContacto valido!\n";
		return true;
	}
	return false;
	
}
string verifContacto() {
	string contacto;
	bool v = false;
	cout << "\nInsira o contacto do cliente (9 digitos):\n";
	do
	{
		cin >> contacto;
		v = verificaInt(contacto);
		v = contaDigitos(contacto); //garante que apenas 9 digitos sao inseridos
		if (v==false)
		{
			cout << "\nContacto invalido, por favor volte a inserir.\n";
		}
	} while (v==false);

	return contacto;
}
void adicionaCliente(string** mCli, int* cCli) {
	// telf valida entre 1 e 900 000 000
	string u; //variavel lixo para o getline poder funcionar
	getline(cin, u);
	*cCli = *cCli + 1; // adiciona uma nova linha a considerar pelo contador de clientes
	mCli[*cCli][0] = to_string(*cCli);
	cout << "\nInsira o nome do cliente:\n";
	getline(cin, mCli[*cCli][1]);
	mCli[*cCli][2] = verifContacto();
	cout << "\nInsira a morada do cliente:\n";
	getline(cin, u);
	getline(cin, mCli[*cCli][3]);
	mCli[*cCli][4] = "0"; //por defeito, quantidade de compras é 0

}
void subGestaoCliente(string** mCli, int* cCli, string p3) {
	//"'3' para alterar o nome de um cliente\n" 
	if (p3=="1")
	{
		// '1' para registar no cliente"
		adicionaCliente(mCli, cCli);

	}
	else if (p3=="2")
	{
		// '2' para remover um cliente" 
		removeCliente(mCli, cCli);
	}
	else
	{
		//"'3' para alterar o nome de um cliente"
		alteraNomeCliente(mCli, cCli);
	}
}
string adicionaStock(string** m, int* c) {
	bool v=true;
	string stock;
	cout << endl << "Quanto unidades pretende adicionar?" << endl;
	do
	{
		v = true;
		cin >> stock;
		v = verificaInt(stock);		
	} while (v==false);
	return stock;
}
bool verPratoStock(string** m, int* c, string n) {
	for (int i = 1; i < *c + 1; i++)
	{
		if (n == m[i][3])
		{
			return true;
		}

	}
	return false;
}
void adicionaPrato(string** m, int* c) {
	string nome;
	bool v;
	cout << "\nInsira o nome do prato a adicionar\n";
	do
	{
		string u; //variavel lixo para o getline poder funcionar
		getline(cin, u);
		v = true;
		getline(cin, nome);
		v = verPratoStock(m, c, nome);
		if (v==true)
		{
			cout << "\nNome ja existente, por favor insira outro nome\n";
		}
	} while (v==true);
	*c = *c + 1; //apos confirmacao do nome do prato, adiciona mais um prato ao contador
	m[*c][0] = to_string(*c);
	cout << "\nInsira os dados do prato.\n";
	cout << "\nStock atual do novo prato:";
	m[*c][1] = adicionaStock(m, c);
	cout << "\nValidade do novo prato:";
	cin >> m[*c][2]; // validade inserida pelo utilizador 
	m[*c][3] = nome; //insere o nome do prato indicado acima
	cout << "\nPreco do novo prato:";
	m[*c][4] = verificaDouble(); //adiciona o preço em decimal
	m[*c][5] = "0"; // por defeito, nr de vendas é 0
}
void removePrato(string** m, int* count) {
	string nome;

	bool v;
	cout << "Qual o nome do prato que pretende remover?\n";	
	do
	{
		string u; //variavel lixo para o getline poder funcionar
		getline(cin, u);
		v = true;
		getline(cin, nome);
		v = verPratoStock(m, count, nome); //verifica a existencia do prato em stock
		if (v==false)
		{
			cout << "\nPrato invalido, por favor insira novamente.\n";
		}
	} while (v==false);

	string v1;
	for (int i = 1; i < *count; i++)
	{
		if (m[i][3]==nome)
		{
			cout << "\nVai remover o prato " << m[i][3];
			cout << "\nTem a certeza que pretende continuar? ('s' para continuar / 'n' para cancelar) \n";
		}
	}

	do
	{
		cin >> v1;
	} while (v1 != "n" && v1 != "s");

	if (v1 == "s")
	{
		for (int i = 1; i < *count; i++) //neste ciclo "for" o contador so ira ler ate ao penultimo prato, porque se o prato a apagar for o ultimo na lista, basta diminuir um valor ao contador
		{
			if (m[i][3] == nome)
			{
				//nao troca o valor do ID de modo a manter a consistência entre ID e nr da linha na matriz.
				//simplesmente troca os dados do ultimo prato para a posicao do prato que sera removido e dando um novo id ao prato da ultima linha
				m[i][1] = m[*count][1];
				m[i][2] = m[*count][2];
				m[i][3] = m[*count][3];
				m[i][4] = m[*count][4];
				m[i][5] = m[*count][5];
			}
		}
		*count = *count - 1;
	}
	else
	{
		cout << "\nOperacao cancelada.\n";
	}
}
void subGestaoStock(string** m, int* c, string p3) {

	if (p3=="1")
	{
		adicionaPrato(m, c);
	}
	else if (p3=="2")
	{
		removePrato(m, c);
	}
	else if (p3=="3")
	{
		string stock, nome;
		bool v=true;		
		do
		{
			string u; //variavel lixo para o getline poder funcionar
			getline(cin, u);
			v = true;
			cout << "\nIndique o prato que pretende alterar o stock.\n";
			getline(cin, nome);
			v = verPratoStock(m, c, nome);
			if (v==false)
			{
				cout << "\nNome de prato invalido, por favor volte a inserir.";
			}

		} while (v==false);
		stock = adicionaStock(m, c);
		for (int i = 1; i < *c; i++)
		{
			if (m[i][3] == nome)
			{
				cout << "\nStock antigo:" << m[i][1];
				m[i][1] = to_string(stoi(stock) + stoi(m[i][1])); // atualiza o valor do stock, converte o stock para inteiro para fazer a soma, e reconverte em texto para guardar na matriz
				cout << "\nNovo stock do prato " << m[i][3] << ".\nStock:" << m[i][1];
			}
		}
	}

}
string gestaoCliente() {
	string p3;
	bool v;
	do
	{
		v = true;
		cout << "\nIndique o que pretende gerir nos clientes:\n";
		cout << "'1' para registar no cliente" << endl << "'2' para remover um cliente" << endl << "'3' para alterar o nome de um cliente\n" << endl;
		cin >> p3;
		v = verificaInt(p3);
		v = verProcedimento3(p3);
	} while (v == false);
	return p3;
}
string gestaoStock() {
	string p3;
	bool v;
	do
	{
		v = true;
		cout << "\nIndique o que pretende gerir no stock:\n";
		cout << "'1' para adicionar um prato" << endl << "'2' para remover um prato" << endl << "'3' para adicionar stock a um prato\n" << endl;
		cin >> p3;
		v=verificaInt(p3);
		v=verProcedimento3(p3);
	} while (v==false);	
	return p3;
}
string gestao() {
	string s;
	bool v;
	cout << "\n GESTAO \n";
	do
	{
		v = true;
		cout << "Indique o que pretende gerir" << endl;
		cout << "'1' para stock" << endl << "'2' para clientes\n";
		cin >> s;
		v = verificaInt(s);
		v = verProcedimento2(s);
	} while (v == false);

	return s;
}


		// PARA OS RELATORIOS //

void pratoMaisVendido(string** matStock, int* contPratos) {
	int maisVen;
	maisVen = stoi(matStock[1][5]); //iguala o numero de vendas correspondente ao primeiro prato na matriz

	for (int o = 1; o < *contPratos + 1; o++)
	{
		int aux;
		aux = stoi(matStock[o][5]);
		if (aux > maisVen)	//descobre qual o maior numero de vendas
		{
			maisVen = aux;
		}
	}

	cout << "\nPrato ou pratos mais vendidos: \n \n";

	for (int p = 1; p < *contPratos + 1; p++)
	{
		int aux;
		aux = stoi(matStock[p][5]);
		if (aux == maisVen)	//descobre se ha mais que um prato com nr vendas igual ao maior nr de vendas
		{
			cout << matStock[p][3] << " com " << maisVen << " vendas. " << endl;

		}
	}

	cout << "\n";
}
void pratoMenosVendido(string** matStock, int* contPratos) {
	int menosVen;
	menosVen = stoi(matStock[1][5]); //iguala o numero de vendas correspondente ao primeiro prato na matriz

	for (int o = 1; o < *contPratos + 1; o++)
	{
		int aux;
		aux = stoi(matStock[o][5]);
		if (aux < menosVen)	//descobre qual o menor numero de vendas
		{
			menosVen = aux;
		}
	}
	cout << "\nPrato ou pratos menos vendidos: \n \n";

	for (int p = 1; p < *contPratos + 1; p++)
	{
		int aux;
		aux = stoi(matStock[p][5]);
		if (aux == menosVen)	//descobre se ha mais que um prato com nr vendas igual ao menor nr de vendas
		{
			cout << matStock[p][3] << " com " << menosVen << " vendas. " << endl;

		}
	}
	cout << "\n";
}
void pratoMaiorLucro(string** matStock, int* contPratos) {
	double maiorLuc;
	maiorLuc = ((stod(matStock[1][4])*1.3) - stod(matStock[1][4])) * (stod(matStock[1][5])); // preço de custo vezes 1.3 (obtem preço de venda) - preço de custo (obtem o lucro de cada prato) vezes o numero de vendas

	for (int o = 1; o < *contPratos + 1; o++)
	{
		double aux;
		aux = ((stod(matStock[o][4])*1.3) - stod(matStock[o][4])) * stod(matStock[o][5]);
		if (aux > maiorLuc)	//descobre qual o maior lucro
		{
			maiorLuc = aux;
		}
	}
	cout << "\nPrato ou pratos com maior lucro: \n \n";

	for (int p = 1; p < *contPratos + 1; p++)
	{
		double aux;
		aux = ((stod(matStock[p][4])*1.3)- stod(matStock[p][4])) * stod(matStock[p][5]);
		if (aux == maiorLuc)	//descobre se ha mais que um prato com lucro total igual ao maior lucro
		{
			cout << matStock[p][3] << " com " << maiorLuc << " euros de lucro em todas as vendas. " << endl;
		}
	}
	cout << "\n";

}
void clienteMaisCompras(string**mCli, int*cCli) {
	int maComp;

	maComp = stoi(mCli[1][4]); //igualar ao nr de compras do primeiro cliente da matriz
	for (int o = 1; o < * cCli + 1; o++)
	{
		int aux;
		aux = stoi(mCli[o][4]);
		if (aux > maComp)	//descobre qual o maior numero de compras
		{
			maComp = aux;
		}
	}
	cout << "\nCliente ou clientes que mais compraram: \n \n";

	for (int p = 1; p < * cCli + 1; p++)
	{
		int aux;
		aux = stoi(mCli[p][4]);
		if (aux == maComp)	//descobre se ha mais que um cliente com o maior nr de compras igual 
		{
			cout << mCli[p][1] << " com " << maComp << " compras. " << endl;
		}
	}
	cout << "\n";
}
string totalVendas() {
	string p3;
	bool v = false;
	do
	{
		v = false;
		cout << endl << "Indique o que pretende verificar";
		cout << endl << "'1' para o prato mais vendido" << endl << "'2' para o prato menos vendido";
		cout << endl << "'3' para o prato com maior lucro" << endl << "'4' para o cliente que mais comprou \n \n";
		cin >> p3;
		v = verificaInt(p3);
		v = verProcedimento4(p3);
	} while (v == false);
	return p3;
}
void subRelatorio2(string** m, int* c, string p3, string**mCli, int*cCli) {
	if (p3 == "1")
	{
		pratoMaisVendido(m, c);
	}
	else if (p3 == "2")
	{
		pratoMenosVendido(m, c);
	}
	else if (p3 == "3")
	{
		pratoMaiorLucro(m, c);
	}
	else if (p3 == "4")
	{
		clienteMaisCompras(mCli, cCli);
	}
}
void imprimeVendaPrato(string** mSto, int* cSto, string prato) {
	for (int i = 1; i <= *cSto; i++)
	{
		if (mSto[i][3]==prato) //quando encontrar o prato na matriz, imprime o nr de vendas
		{
			cout << endl << "O prato selecionado tem " << mSto[i][5] << " vendas. \n \n"; 
		}
	}
}
void vendasPorPrato(string** mSto, int* cSto) {
	bool v = false;
	string prato;
	do
	{
		string u; //variavel lixo para o getline poder funcionar
		getline(cin, u);
		cout << "Insira o nome do prato" << endl;
		getline(cin, prato);
		for (int i = 1; i <= *cSto; i++)
		{
			if (prato == mSto[i][3])	//verifica se o prato inserido existe no stock
			{
				v = true;
			}
		}
		if (v == false)
		{
			cout << endl << "Prato inexistente, por favor insira novamente. \n \n ";
		}
	} while (v == false);
	imprimeVendaPrato(mSto, cSto, prato);
}
bool verificaCliente(string** mCli, int* cCli, string nome) {
	for (int i = 0; i < *cCli; i++)
	{
		if (mCli[i][1]==nome)
		{
			return true;
		}
	}
	return false;
}
void imprimeVendaCliente(string** mCli, int* cCli, string nome) {
	for (int i = 1; i < *cCli; i++)
	{
		if (mCli[i][1]==nome)
		{
			cout << "\nO cliente " << mCli[i][1] << " tem " << mCli[i][4] << " compras.\n";
		}
	}

}
void vendasPorCliente(string** mCli, int* cCli) {
	cout << "\nInsira o cliente que pretende verificar.\n";
	bool v = false;
	string nome;
	do
	{
		string u; //variavel lixo para o getline poder funcionar
		getline(cin, u);
		getline(cin, nome);
		v = verificaCliente(mCli, cCli, nome);
		if (v==false)
		{
			cout << "\nCliente inexistente, por favor insira novamente.\n";
		}
	} while (v==false);
	imprimeVendaCliente(mCli, cCli, nome);

}
void subRelatorio1(string p2, string** m, int* count, string**mCli, int*cCli) {
	if (p2 == "1")
	{
		imprimirStock(m, count);
	}
	else if (p2 == "2")
	{
		vendasPorPrato(m, count);
	}
	else if (p2=="3")
	{
		string p3;
		p3 = totalVendas();
		subRelatorio2(m, count, p3, mCli, cCli);
	}
	else
	{
		vendasPorCliente(mCli, cCli);
	}
}
string relatorios() {
	string s;
	bool v;
	cout << "\n RELATORIOS \n";
	do
	{
		v = true;
		cout << "Indique o relatorio pretendido" << endl;
		cout << "'1' para mostrar stock atual" << endl << "'2' para mostrar vendas por prato" << endl;
		cout << "'3' para mostrar vendas totais" << endl << "'4' para relatorio de vendas por cliente\n";
		cin >> s;
		v = verificaInt(s);
		v = verProcedimento4(s);
	} while (v == false);
	return s;
}


string menuIni() {
	string p1;
	bool v;
	do
	{
		v = true;
		cout << "Por favor indique o que pretende fazer:" << endl << "'1' para Relatorios" << endl << "'2' para Gestao" << endl << "'3' para novo Pedido \n";
		cin >> p1;
		v = verificaInt(p1);
		v = verProcedimento3(p1);
	} while (v == false);
	return p1;
}


int main()
{
	int asd;
	cin >> asd;

	cout << setprecision(2) << fixed; //para limitar a 2 casas decimais os numeros apresentados
	srand(time(NULL));
	string u;
	cout << "Pressione 'ENTER' para comecar." << endl;
	getline(cin, u); // comando com variavel "lixo" de modo ao "getline" nao fazer nenhum valor desaparecer

	string** matStock = new string * [101]; // matriz com o stock de pratos do restaurante (tem possibilidade de 100 pratos, a linha 1 è para designações da coluna
	criarMatriz(matStock, 100, 6);
	criar::matStock(matStock); // preenche a matriz com 5 pratos
	int *contPratos=new int; //contador para limitar a quantidade de linhas lidas na matriz stock 
	*contPratos = 5;

	string** matCliente = new string * [101]; // matriz com os clientes do restaurante (tem possibilidade de 100 clientes, a linha 1 é para designações da coluna
	criarMatriz(matCliente, 100, 5);
	criar::matCliente(matCliente);
	int* contCliente = new int; //contador para limitar a quantidade de clientes lidos na matriz cliente
	*contCliente = 5;

	string** matRecibo = new string * [100];
	criarMatriz(matRecibo, 100, 100);
	criar::matCliente(matRecibo);
	int* contRecibo = new int; //contador para limitar a quantidade de recibos lidos na matriz recibo
	*contRecibo = 1;

	bool programa = true; //variavel serve para certificar que nunca sairemos do programa
	do
	{
		string proced1, proced2, proced3;
		cout << "\n \n -----MENU INICIAL----- \n \n";
		proced1 = menuIni();	
		if (proced1 == "1") // se escolheu relatorios na funçao menuIni
		{
			proced2 = relatorios();
			subRelatorio1(proced2, matStock, contPratos, matCliente, contCliente);
		}
		else if (proced1 == "2")//se escolheu gestao na funçao menuIni
		{
			proced2 = gestao(); 
			if (proced2=="1") // se escolheu gestao de stock
			{
				proced3=gestaoStock();
				subGestaoStock(matStock, contPratos, proced3);
			}
			else // se escolheu gestao de clientes
			{
				proced3=gestaoCliente();
				subGestaoCliente(matCliente, contCliente, proced3);
			}
			
		}
		else {		// se escolheu pedido na funçao menuIni

			pedido(matRecibo, contRecibo, matStock, contPratos, matCliente, contCliente); 
		}

	} while (programa==true);
}