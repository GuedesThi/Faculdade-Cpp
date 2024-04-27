## Exercício | Adivinhe o Número

### Objetivo:
- Jogo onde o usuário deve tentar adivinhar qual é o número

- Dependendo do nível de dificuldade, as chances para o usuário tentar acertar varia

- Caso o usuário acerte o número, eu devo informar quantas tentativas ele levou, e quantos pontos ele conseguiu
<br></br>
---
### Explicação do Algoritmo:

1. Usei <span
    style="background:black; color:red; font-weight: bolder; padding: 5px; border-radius: 5px;">rand()</span> para gerar valores aleatórios, e <span
    style="background:black; color:red; font-weight: bolder; padding: 5px; border-radius: 5px;">srand(time(NULL))</span> para me gerar Sementes aleatórias para nunca repetir o mesmo número.
    
    Além disso, falei para <span
    style="background:black; color:red; font-weight: bolder; padding: 5px; border-radius: 5px;">NUMERO</span> ser o resto do número aleatório gerado com 100, para ser obrigatóriamente um valor entre 0 e 99:
    ```cpp
    #include <iostream>
    #include <locale>
    #include <cstdlib>
    #include <ctime>

    int main() {
        setlocale(LC_ALL, "Portuguese");

        srand(time(NULL));
        const int NUMERO = rand() % 100;

        return 0;
    }
    ```
    <br></br>
    2. Criei variáveis para <span
    style="background:black; color:red; font-weight: bolder; padding: 5px; border-radius: 5px;">level</span> (Dificuldade escolhida), <span
    style="background:black; color:red; font-weight: bolder; padding: 5px; border-radius: 5px;">chances</span> (Chances que o usuário tem de acordo com a dificuldade), <span
    style="background:black; color:red; font-weight: bolder; padding: 5px; border-radius: 5px;">points</span> (Pontos do usuário caso ele acerte o número), e, <span
    style="background:black; color:red; font-weight: bolder; padding: 5px; border-radius: 5px;">tentativa</span> (Chances que precisou para acertar o número)

    Também criei a mensagem de inicio do jogo, e, vários **if** e **else** para declarar a quantidade de chances que o usuário terá:
    ```cpp
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
    ```
    <br></br>
    3. Criei um **loop for** para o usuário tentar várias vezes de acordo com seu número de chances. E além disso, criei a variável <span
    style="background:black; color:red; font-weight: bolder; padding: 5px; border-radius: 5px;">not_win = true</span>, para, caso o usuário ganhe o jogo ela irá virar <span
    style="background:black; color:red; font-weight: bolder; padding: 5px; border-radius: 5px;">false</span> e não rodará o **loop** falando que você perdeu o jogo.
    ```cpp
    bool not_win = true;

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
    ```
    
    Perceba que dentro do **for** das tentativas, eu falo o quanto o usuário irá perder de pontos caso não acerte na chance que ele está.