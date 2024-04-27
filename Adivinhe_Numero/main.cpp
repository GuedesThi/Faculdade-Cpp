#include <iostream>
#include <locale>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil");

    char level;
    int chances;
    double points = 100.0; 
    int tentativa = 0;

    std::cout << "\nBem-Vindo(a) ao Qual � O N�mero?" << std::endl;
    std::cout << "--------------------------------" << std::endl;
    std::cout << "Dificuldade: [F] F�cil | [M] M�dio | [D] Dif�cil  ";
    std::cin >> level;

    if (level == 'F' || level == 'f') {
        chances = 15;
        std::cout << "\nVoc� tem 15 chances para acertar o n�mero." << std::endl; 
    } else if (level == 'M' || level == 'm') {
        chances = 10;
        std::cout << "\nVoc� tem 10 chances para acertar o n�mero." << std::endl; 
    } else if (level == 'D' || level == 'd') {
        chances = 5;
        std::cout << "\nVoc� tem 5 chances para acertar o n�mero." << std::endl; 
    } else {
        std::cout << "\nESCOLHA UMA DIFICULDADE V�LIDA NA PR�XIMA VEZ";
    }

    bool not_win = true;

    srand(time(NULL));
    const int RESPOSTA = rand() % 100;

    for (int i = 1; i <= chances; i++) {
        tentativa++;
        int chute;

        std::cout << "\nFa�a um chute: ";
        std::cin >> chute;

        double lost_points = abs(chute - RESPOSTA) / 2.0;
        points -= lost_points;

        if (chute > RESPOSTA) {
            std::cout << chute << " � maior do que o n�mero certo. Tente novamente." << std::endl;
        } else if (chute < RESPOSTA) {
            std::cout << chute << " � menor do que o n�mero certo. Tente novamente." << std::endl;
        } else if (chute == RESPOSTA && tentativa == 1) {
            std::cout << "\nParab�ns, voc� acertou o n�mero " << RESPOSTA << " na 1� tentativa!!!" << std::endl;
            cout.precision(2);
            cout << fixed;
            std::cout << "Voc� obteve: " << points << " pontos!!!" << std::endl;
            not_win = false;
            system("PAUSE");
            break;
        } else {
            std::cout << "\nParab�ns, voc� acertou o n�mero " << RESPOSTA << " ap�s " << tentativa << " tentativas!!!" << std::endl;
            cout.precision(2);
            cout << fixed;
            std::cout << "Voc� obteve: " << points << " pontos!!!\n";
            not_win = false;
            system("PAUSE");
            break;
        }
    }

    if (not_win) {
        std::cout << "Acabaram suas chances! Tente novamente.\n" << std::endl;
    }
    
    return 0;
}