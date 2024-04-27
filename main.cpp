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

    std::cout << "\nBem-Vindo(a) ao Qual É O Número?" << std::endl;
    std::cout << "--------------------------------" << std::endl;
    std::cout << "Dificuldade: [F] Fácil | [M] Médio | [D] Difícil  ";
    std::cin >> level;

    if (level == 'F' || level == 'f') {
        chances = 15;
        std::cout << "\nVocê tem 15 chances para acertar o número." << std::endl; 
    } else if (level == 'M' || level == 'm') {
        chances = 10;
        std::cout << "\nVocê tem 10 chances para acertar o número." << std::endl; 
    } else if (level == 'D' || level == 'd') {
        chances = 5;
        std::cout << "\nVocê tem 5 chances para acertar o número." << std::endl; 
    } else {
        std::cout << "\nESCOLHA UMA DIFICULDADE VÁLIDA NA PRÓXIMA VEZ";
    }

    bool not_win = true;

    srand(time(NULL));
    const int RESPOSTA = rand() % 100;

    for (int i = 1; i <= chances; i++) {
        tentativa++;
        int chute;

        std::cout << "\nFaça um chute: ";
        std::cin >> chute;

        double lost_points = abs(chute - RESPOSTA) / 2.0;
        points -= lost_points;

        if (chute > RESPOSTA) {
            std::cout << chute << " é maior do que o número certo. Tente novamente." << std::endl;
        } else if (chute < RESPOSTA) {
            std::cout << chute << " é menor do que o número certo. Tente novamente." << std::endl;
        } else if (chute == RESPOSTA && tentativa == 1) {
            std::cout << "\nParabéns, você acertou o número " << RESPOSTA << " na 1º tentativa!!!" << std::endl;
            cout.precision(2);
            cout << fixed;
            std::cout << "Vocé obteve: " << points << " pontos!!!" << std::endl;
            not_win = false;
            system("PAUSE");
            break;
        } else {
            std::cout << "\nParabéns, você acertou o número " << RESPOSTA << " após " << tentativa << " tentativas!!!" << std::endl;
            cout.precision(2);
            cout << fixed;
            std::cout << "Você obteve: " << points << " pontos!!!\n";
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