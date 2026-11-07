// Sample C++ code

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {

    // 1. VARIAVEIS E TIPOS DE DADOS
    float temperatura;
    float temperaturaDesejada = 22.0;
    float soma, media;
    int opcao;
    char continuar;

    // VETOR PARA ARMAZENAR AS TEMPERATURAS
    vector<float> historico;

    // 2. ESTRUTURA DE REPETICAO WHILE
    while (opcao != 6) {

        cout << "\n===== CONTROLE DE TEMPERATURA =====" << endl;
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

        // 3. ESTRUTURA CONDICIONAL SWITCH
        switch (opcao) {

            case 1:

                // ENTRADA E REPETICAO DO-WHILE
                do {
                    cout << "\nDigite a temperatura atual: ";
                    cin >> temperatura;

                    historico.push_back(temperatura);

                    // PROCESSAMENTO E IF/ELSE
                    if (temperatura > temperaturaDesejada) {
                        cout << "Temperatura alta!" << endl;
                        cout << "LIGAR AR-CONDICIONADO." << endl;
                    }
                    else if (temperatura < temperaturaDesejada) {
                        cout << "Temperatura baixa!" << endl;
                        cout << "LIGAR AQUECEDOR." << endl;
                    }
                    else {
                        cout << "Temperatura ideal!" << endl;
                        cout << "SISTEMA EM EQUILIBRIO." << endl;
                    }

                    cout << "\nDeseja registrar outra temperatura? (s/n): ";
                    cin >> continuar;

                } while (continuar == 's' || continuar == 'S');

                break;

            case 2:

                // SAIDA E VETOR
                cout << "\n===== HISTORICO =====" << endl;

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

            case 3:

                // OPERADORES E CALCULO DA MEDIA
                if (historico.empty()) {
                    cout << "Nenhum dado para calcular." << endl;
                }
                else {
                    soma = 0;

                    for (int i = 0; i < historico.size(); i++) {
                        soma = soma + historico[i];
                    }

                    media = soma / historico.size();

                    cout << fixed << setprecision(2);
                    cout << "Media das temperaturas: "
                         << media << " C" << endl;
                }

                break;

            case 4:

                // ALTERAR TEMPERATURA DESEJADA
                cout << "\nDigite a nova temperatura desejada: ";
                cin >> temperaturaDesejada;

                cout << "Temperatura atualizada com sucesso!" << endl;

                break;

            case 5: {

                // 4. MATRIZ 7x4
                // 7 dias e 4 medicoes por dia

                float matriz[7][4] = {};
                bool ocupada[7][4] = {};

                int limite = historico.size();

                if (limite > 28) {
                    limite = 28;
                }

                for (int i = 0; i < limite; i++) {
                    matriz[i / 4][i % 4] = historico[i];
                    ocupada[i / 4][i % 4] = true;
                }

                cout << "\n===== RELATORIO EM MATRIZ =====" << endl;

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

            case 6:

                cout << "\nSistema encerrado!" << endl;
                break;

            default:

                cout << "\nOpcao invalida! Tente novamente." << endl;
        }
    }

    return 0;
}