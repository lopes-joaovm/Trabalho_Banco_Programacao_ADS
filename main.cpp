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

    const int MAX = 100;
    const int MAX_MOVIMENTACOES = 500;

    int numeroConta[MAX];
    string nomeCliente[MAX];
    string cpf[MAX];
    int tipoConta[MAX];
    double saldo[MAX];
    bool contaAtiva[MAX];

    int contaMovimentacao[MAX_MOVIMENTACOES];
    char tipoMovimentacao[MAX_MOVIMENTACOES];
    double valorMovimentacao[MAX_MOVIMENTACOES];

    int quantidadeContas = 0;
    int quantidadeMovimentacoes = 0;

    int opcao;
    int contaProcurada;
    int posicao;

    do {

        cout << "\n==============================" << endl;
        cout << "       BANCO DO JOÃO" << endl;
        cout << "==============================" << endl;
        cout << "1 - Cadastrar conta" << endl;
        cout << "2 - Consultar conta" << endl;
        cout << "3 - Verificar saldo" << endl;
        cout << "4 - Alterar tipo da conta" << endl;
        cout << "5 - Ativar/Desativar conta" << endl;
        cout << "6 - Listar contas" << endl;
        cout << "7 - Realizar deposito" << endl;
        cout << "8 - Realizar saque" << endl;
        cout << "9 - Realizar transferencia" << endl;
        cout << "10 - Exibir extrato" << endl;
        cout << "11 - Sair" << endl;

        cout << "\nEscolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {

        case 1:

            if (quantidadeContas >= MAX) {
                cout << "\nLimite de 100 contas atingido!" << endl;
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

            if (quantidadeContas == 0) {

                cout << "\nNenhuma conta cadastrada!" << endl;

            } else {

                cout << "\n======= CONTAS CADASTRADAS =======" << endl;

                for (int i = 0; i < quantidadeContas; i++) {

                    cout << "\nNumero: " << numeroConta[i] << endl;
                    cout << "Cliente: " << nomeCliente[i] << endl;
                    cout << "Saldo: R$ " << saldo[i] << endl;

                    if (tipoConta[i] == 1) {
                        cout << "Tipo: Corrente" << endl;
                    } else {
                        cout << "Tipo: Poupanca" << endl;
                    }

                    if (contaAtiva[i] == true) {
                        cout << "Situacao: Ativa" << endl;
                    } else {
                        cout << "Situacao: Inativa" << endl;
                    }
                }
            }

            break;


        case 7:

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

            } else if (quantidadeMovimentacoes >= MAX_MOVIMENTACOES) {

                cout << "\nLimite de movimentacoes atingido!" << endl;

            } else {

                double valor;

                cout << "Digite o valor do deposito: R$ ";
                cin >> valor;

                if (valor <= 0) {

                    cout << "\nValor invalido!" << endl;

                } else {

                    saldo[posicao] = saldo[posicao] + valor;

                    contaMovimentacao[quantidadeMovimentacoes] =
                        numeroConta[posicao];

                    tipoMovimentacao[quantidadeMovimentacoes] = 'D';

                    valorMovimentacao[quantidadeMovimentacoes] = valor;

                    quantidadeMovimentacoes++;

                    cout << "\nDeposito realizado com sucesso!" << endl;
                    cout << "Novo saldo: R$ " << saldo[posicao] << endl;
                }
            }

            break;


        case 8:

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

            } else if (quantidadeMovimentacoes >= MAX_MOVIMENTACOES) {

                cout << "\nLimite de movimentacoes atingido!" << endl;

            } else {

                double valor;

                cout << "Digite o valor do saque: R$ ";
                cin >> valor;

                if (valor <= 0) {

                    cout << "\nValor invalido!" << endl;

                } else if (valor > saldo[posicao]) {

                    cout << "\nSaldo insuficiente!" << endl;

                } else {

                    saldo[posicao] = saldo[posicao] - valor;

                    contaMovimentacao[quantidadeMovimentacoes] =
                        numeroConta[posicao];

                    tipoMovimentacao[quantidadeMovimentacoes] = 'S';

                    valorMovimentacao[quantidadeMovimentacoes] = valor;

                    quantidadeMovimentacoes++;

                    cout << "\nSaque realizado com sucesso!" << endl;
                    cout << "Novo saldo: R$ " << saldo[posicao] << endl;
                }
            }

            break;


        case 9:

            {
                int contaOrigem;
                int contaDestino;
                int indiceOrigem = -1;
                int indiceDestino = -1;
                double valor;

                cout << "\nConta de origem: ";
                cin >> contaOrigem;

                cout << "Conta de destino: ";
                cin >> contaDestino;

                for (int i = 0; i < quantidadeContas; i++) {

                    if (numeroConta[i] == contaOrigem) {
                        indiceOrigem = i;
                    }

                    if (numeroConta[i] == contaDestino) {
                        indiceDestino = i;
                    }
                }

                if (indiceOrigem == -1 || indiceDestino == -1) {

                    cout << "\nUma das contas nao foi encontrada!" << endl;

                } else if (indiceOrigem == indiceDestino) {

                    cout << "\nNao e possivel transferir para a mesma conta!" << endl;

                } else if (contaAtiva[indiceOrigem] == false ||
                           contaAtiva[indiceDestino] == false) {

                    cout << "\nAs duas contas precisam estar ativas!" << endl;

                } else if (quantidadeMovimentacoes + 2 > MAX_MOVIMENTACOES) {

                    cout << "\nNao ha espaco para registrar a transferencia!" << endl;

                } else {

                    cout << "Digite o valor da transferencia: R$ ";
                    cin >> valor;

                    if (valor <= 0) {

                        cout << "\nValor invalido!" << endl;

                    } else if (valor > saldo[indiceOrigem]) {

                        cout << "\nSaldo insuficiente!" << endl;

                    } else {

                        saldo[indiceOrigem] =
                            saldo[indiceOrigem] - valor;

                        saldo[indiceDestino] =
                            saldo[indiceDestino] + valor;


                        contaMovimentacao[quantidadeMovimentacoes] =
                            numeroConta[indiceOrigem];

                        tipoMovimentacao[quantidadeMovimentacoes] = 'S';

                        valorMovimentacao[quantidadeMovimentacoes] = valor;


                        contaMovimentacao[quantidadeMovimentacoes + 1] =
                            numeroConta[indiceDestino];

                        tipoMovimentacao[quantidadeMovimentacoes + 1] = 'D';

                        valorMovimentacao[quantidadeMovimentacoes + 1] = valor;


                        quantidadeMovimentacoes += 2;

                        cout << "\nTransferencia realizada com sucesso!" << endl;

                        cout << "Saldo da conta de origem: R$ "
                             << saldo[indiceOrigem] << endl;

                        cout << "Saldo da conta de destino: R$ "
                             << saldo[indiceDestino] << endl;
                    }
                }
            }

            break;


        case 10:

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

                cout << "\n========== EXTRATO ==========" << endl;
                cout << "Conta: " << numeroConta[posicao] << endl;
                cout << "Cliente: " << nomeCliente[posicao] << endl;

                bool encontrouMovimentacao = false;

                for (int i = 0; i < quantidadeMovimentacoes; i++) {

                    if (contaMovimentacao[i] == contaProcurada) {

                        encontrouMovimentacao = true;

                        if (tipoMovimentacao[i] == 'D') {

                            cout << "Deposito/Entrada: R$ "
                                 << valorMovimentacao[i] << endl;

                        } else if (tipoMovimentacao[i] == 'S') {

                            cout << "Saque/Saida: R$ "
                                 << valorMovimentacao[i] << endl;
                        }
                    }
                }

                if (encontrouMovimentacao == false) {

                    cout << "\nNenhuma movimentacao registrada!" << endl;
                }

                cout << "Saldo atual: R$ " << saldo[posicao] << endl;
                cout << "=============================" << endl;
            }

            break;


        case 11:

            cout << "\nSistema encerrado." << endl;
            break;


        default:

            cout << "\nOpcao invalida!" << endl;
        }


        if (opcao != 11) {

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "\nPressione ENTER para voltar ao menu...";

            cin.get();
        }

    } while (opcao != 11);


    return 0;
}
