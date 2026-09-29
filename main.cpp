/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <string>
#include <limits>

using namespace std;

int main() {

    const int MAX = 5;

    int numeroConta[MAX];
    string nomeCliente[MAX];
    string cpf[MAX];
    int tipoConta[MAX];
    double saldo[MAX];
    bool contaAtiva[MAX];

    int quantidadeContas = 0;
    int opcao;
    int contaProcurada;
    int posicao;

    do {

        cout << "\n==============================" << endl;
        cout << "          BANCO INF101" << endl;
        cout << "==============================" << endl;
        cout << "1 - Cadastrar conta" << endl;
        cout << "2 - Consultar conta" << endl;
        cout << "3 - Verificar saldo" << endl;
        cout << "4 - Alterar tipo da conta" << endl;
        cout << "5 - Ativar/Desativar conta" << endl;
        cout << "6 - Sair" << endl;

        cout << "\nEscolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {

        case 1:

            if (quantidadeContas >= MAX) {
                cout << "\nLimite de 5 contas atingido!" << endl;
                break;
            }

            cout << "\nNumero da conta: ";
            cin >> numeroConta[quantidadeContas];

            if (numeroConta[quantidadeContas] <= 0) {
                cout << "Numero da conta invalido!" << endl;
                break;
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Nome do cliente: ";
            getline(cin, nomeCliente[quantidadeContas]);

            cout << "CPF: ";
            getline(cin, cpf[quantidadeContas]);

            cout << "\nTipo da conta:" << endl;
            cout << "1 - Corrente" << endl;
            cout << "2 - Poupanca" << endl;
            cout << "Escolha: ";
            cin >> tipoConta[quantidadeContas];

            if (tipoConta[quantidadeContas] != 1 &&
                tipoConta[quantidadeContas] != 2) {

                cout << "Tipo de conta invalido!" << endl;
                break;
            }

            cout << "Saldo inicial: R$ ";
            cin >> saldo[quantidadeContas];

            if (saldo[quantidadeContas] < 0) {
                cout << "O saldo nao pode ser negativo!" << endl;
                break;
            }

            contaAtiva[quantidadeContas] = true;

            quantidadeContas++;

            cout << "\nConta cadastrada com sucesso!" << endl;

            break;


        case 2:

            cout << "\nDigite o numero da conta: ";
            cin >> contaProcurada;

            posicao = -1;

            for (int i = 0; i < quantidadeContas; i++) {

                if (numeroConta[i] == contaProcurada) {
                    posicao = i;
                    break;
                }
            }

            if (posicao == -1) {

                cout << "\nConta nao encontrada!" << endl;

            } else {

                cout << "\n==============================" << endl;
                cout << "       DADOS DA CONTA" << endl;
                cout << "==============================" << endl;

                cout << "Numero: "
                     << numeroConta[posicao] << endl;

                cout << "Cliente: "
                     << nomeCliente[posicao] << endl;

                cout << "CPF: "
                     << cpf[posicao] << endl;

                if (tipoConta[posicao] == 1) {
                    cout << "Tipo: Conta Corrente" << endl;
                } else {
                    cout << "Tipo: Conta Poupanca" << endl;
                }

                cout << "Saldo: R$ "
                     << saldo[posicao] << endl;

                if (contaAtiva[posicao] == true) {
                    cout << "Situacao: Ativa" << endl;
                } else {
                    cout << "Situacao: Inativa" << endl;
                }
            }

            break;


        case 3:

            cout << "\nDigite o numero da conta: ";
            cin >> contaProcurada;

            posicao = -1;

            for (int i = 0; i < quantidadeContas; i++) {

                if (numeroConta[i] == contaProcurada) {
                    posicao = i;
                    break;
                }
            }

            if (posicao == -1) {

                cout << "\nConta nao encontrada!" << endl;

            } else if (contaAtiva[posicao] == false) {

                cout << "\nA conta esta desativada!" << endl;

            } else {

                cout << "\nSaldo atual: R$ "
                     << saldo[posicao] << endl;
            }

            break;


        case 4:

            cout << "\nDigite o numero da conta: ";
            cin >> contaProcurada;

            posicao = -1;

            for (int i = 0; i < quantidadeContas; i++) {

                if (numeroConta[i] == contaProcurada) {
                    posicao = i;
                    break;
                }
            }

            if (posicao == -1) {

                cout << "\nConta nao encontrada!" << endl;

            } else if (contaAtiva[posicao] == false) {

                cout << "\nA conta esta desativada!" << endl;

            } else {

                int novoTipo;

                cout << "\nNovo tipo da conta:" << endl;
                cout << "1 - Corrente" << endl;
                cout << "2 - Poupanca" << endl;
                cout << "Escolha: ";

                cin >> novoTipo;

                if (novoTipo == 1 || novoTipo == 2) {

                    tipoConta[posicao] = novoTipo;

                    cout << "\nTipo alterado com sucesso!" << endl;

                } else {

                    cout << "\nTipo invalido!" << endl;
                }
            }

            break;


        case 5:

            cout << "\nDigite o numero da conta: ";
            cin >> contaProcurada;

            posicao = -1;

            for (int i = 0; i < quantidadeContas; i++) {

                if (numeroConta[i] == contaProcurada) {
                    posicao = i;
                    break;
                }
            }

            if (posicao == -1) {

                cout << "\nConta nao encontrada!" << endl;

            } else {

                if (contaAtiva[posicao] == true) {

                    contaAtiva[posicao] = false;

                    cout << "\nConta desativada com sucesso!" << endl;

                } else {

                    contaAtiva[posicao] = true;

                    cout << "\nConta ativada com sucesso!" << endl;
                }
            }

            break;


        case 6:

            cout << "\nSistema encerrado." << endl;
            break;


        default:

            cout << "\nOpcao invalida!" << endl;
        }


        if (opcao != 6) {

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "\nPressione ENTER para voltar ao menu...";

            cin.get();
        }

    } while (opcao != 6);


    return 0;
}
