#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {

    // =================================
    // 1. VARIAVEIS E TIPOS DE DADOS
    // =================================

    float temperatura;
    float temperaturaDesejada = 22.0;
    float soma, media;

    int opcao = 0;
    char continuar;

    // VETOR PARA GUARDAR AS TEMPERATURAS
    vector<float> historico;


    // =================================
    // 2. MENU PRINCIPAL (WHILE)
    // =================================

    while (opcao != 6) {

        cout << "\n==================================" << endl;
        cout << "   SISTEMA DE CONTROLE DE TEMPERATURA" << endl;
        cout << "==================================" << endl;

        cout << "Temperatura desejada: "
             << temperaturaDesejada << " C" << endl;

        cout << "\n1 - Registrar temperatura";
        cout << "\n2 - Consultar historico";
        cout << "\n3 - Calcular media";
        cout << "\n4 - Alterar temperatura desejada";
        cout << "\n5 - Relatorio em matriz";
        cout << "\n6 - Sair";

        cout << "\n\nEscolha uma opcao: ";
        cin >> opcao;


        // =================================
        // 3. PROCESSAMENTO (SWITCH)
        // =================================

        switch (opcao) {


            // ---------------------------------
            // OPCAO 1 - REGISTRAR TEMPERATURA
            // ---------------------------------

            case 1:

                do {

                    cout << "\nDigite a temperatura atual: ";
                    cin >> temperatura;

                    // ARMAZENAR NO VETOR
                    historico.push_back(temperatura);


                    // COMPARAR TEMPERATURAS (IF / ELSE)

                    if (temperatura > temperaturaDesejada) {

                        cout << "\nTemperatura alta!" << endl;
                        cout << "LIGAR AR-CONDICIONADO." << endl;

                    }

                    else if (temperatura < temperaturaDesejada) {

                        cout << "\nTemperatura baixa!" << endl;
                        cout << "LIGAR AQUECEDOR." << endl;

                    }

                    else {

                        cout << "\nTemperatura ideal!" << endl;
                        cout << "SISTEMA EM EQUILIBRIO." << endl;

                    }


                    // REPETICAO DO-WHILE

                    cout << "\nDeseja registrar outra temperatura? (s/n): ";
                    cin >> continuar;

                } while (continuar == 's' || continuar == 'S');

                break;


            // ---------------------------------
            // OPCAO 2 - CONSULTAR HISTORICO
            // ---------------------------------

            case 2:

                cout << "\n========== HISTORICO ==========" << endl;

                if (historico.empty()) {

                    cout << "Nenhuma temperatura registrada." << endl;

                }

                else {

                    for (int i = 0; i < historico.size(); i++) {

                        cout << "Registro " << i + 1 << ": "
                             << historico[i] << " C" << endl;

                    }

                }

                break;


            // ---------------------------------
            // OPCAO 3 - CALCULAR MEDIA
            // ---------------------------------

            case 3:

                if (historico.empty()) {

                    cout << "\nNenhuma temperatura para calcular." << endl;

                }

                else {

                    soma = 0;

                    for (int i = 0; i < historico.size(); i++) {

                        soma = soma + historico[i];

                    }

                    media = soma / historico.size();

                    cout << fixed << setprecision(2);

                    cout << "\nMedia das temperaturas: "
                         << media << " C" << endl;

                }

                break;


            // ---------------------------------
            // OPCAO 4 - ALTERAR TEMPERATURA
            // ---------------------------------

            case 4:

                cout << "\nDigite a nova temperatura desejada: ";
                cin >> temperaturaDesejada;

                cout << "\nTemperatura atualizada com sucesso!" << endl;

                break;


            // ---------------------------------
            // OPCAO 5 - RELATORIO EM MATRIZ
            // ---------------------------------

            case 5: {

                float matriz[7][4] = {};
                bool ocupada[7][4] = {};

                int limite = historico.size();

                if (limite > 28) {

                    limite = 28;

                }


                // PREENCHER A MATRIZ

                for (int i = 0; i < limite; i++) {

                    matriz[i / 4][i % 4] = historico[i];

                    ocupada[i / 4][i % 4] = true;

                }


                // EXIBIR RELATORIO

                cout << "\n========== RELATORIO ==========" << endl;

                for (int i = 0; i < 7; i++) {

                    cout << "\nDia " << i + 1 << ": ";

                    for (int j = 0; j < 4; j++) {

                        if (ocupada[i][j]) {

                            cout << matriz[i][j] << " C\t";

                        }

                        else {

                            cout << "--\t";

                        }

                    }

                }

                cout << endl;

                break;

            }


            // ---------------------------------
            // OPCAO 6 - ENCERRAR SISTEMA
            // ---------------------------------

            case 6:

                cout << "\nSistema encerrado!" << endl;

                break;


            // ---------------------------------
            // OPCAO INVALIDA
            // ---------------------------------

            default:

                cout << "\nOpcao invalida! Tente novamente." << endl;

        }

    }


    // =================================
    // 4. FINALIZACAO DO PROGRAMA
    // =================================

    return 0;

}
