#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <time.h>

using namespace std;

void limpaTela(){
    system("CLS");
}
string retornaPalavraAleatoria(){
    string palavras[10] = {"abacaxi","manga","morango","abacate","laranja", "uva","amora", "banana", "cereja", "framboesa"};
    //Indice gerado no intervalo (0,1,2)
    int indiceAleatorio = rand() % 10;

    return palavras[indiceAleatorio];
}

string retornapalavraComMascara( int tamanhoDaPalavra){
    //Contador auxiliar
    int cont = 0;

    //O que vai ser mostrado pro usuario e depois eventualmente furar ela, quando o usuario acertar as letras
    string palavraComMascara;

    //Coloca uma mascara na palavras enquanto tiver que adicionar um underline, incrementa na string com underline
    while (cont < tamanhoDaPalavra){
        palavraComMascara += "_";
        cont++;
    }

    return palavraComMascara;
}

void exibeStatus(string palavraComMascara, int tamanhoDaPalavra, int tentativasRestantes, string letrasJaArriscadas, string mensagem){
    cout << mensagem;
    cout << "\nPalavra:" << palavraComMascara << "(Tamanho da palavras: " << tamanhoDaPalavra <<")";
    cout << "\nTentativas restantes:" << tentativasRestantes;
    //Exibe as letras arriscadas
    int cont;
    cout << "\nLetras arriscadas: ";
    for(cont = 0; cont < letrasJaArriscadas.size(); cont++){
        cout << letrasJaArriscadas[cont] << ", ";
    }
}
int jogar(int numeroDeJogadores){
    //Palavras a ser advinhada
    string palavra;

    //Confere numero de jogadores
    if(numeroDeJogadores == 1){
        //Se for apenas um jogar gera uma palavra aleatoria
        palavra = retornaPalavraAleatoria();
    }else{
        //Se for mais de um jogador, pede pro jogador escolher uma palavra
        cout << "\nDigite uma palavra: ";
        cin >> palavra;
    }

    
    

    //Tamanho da palavras
    int tamanhoDaPalavra = palavra.size();
    //Palavra mascarada
    string palavraComMascara = retornapalavraComMascara(tamanhoDaPalavra);

    int tentativas = 0, maximoDeTentativas = 20;
    int cont = 0;
    int opcao;
    char letra;
    string letrasJaArriscadas;
    string mensagem = "Bem vindo ao Jogo";
    string palavraArriscada;
    bool jaDigitouLetra = false;
    bool acertouLetra = false;

    //Quais as condições pro game estar rolando: O jogador nao acertar a palavra e tiver mais de uma tentativa sobrando
    while( palavra != palavraComMascara && maximoDeTentativas - tentativas > 0  ){
        limpaTela();

        exibeStatus(palavraComMascara, tamanhoDaPalavra, maximoDeTentativas - tentativas, letrasJaArriscadas, mensagem);

        //Lê um palpite
        cout << "\nDigite uma letra(ou digite 1 para arriscar a palavra): ";
        cin >> letra;

        //Se digitar 1, deixa o usuario arriscar a palavra inteira
        if(letra == '1'){
            cin >> palavraArriscada;
            if(palavraArriscada == palavra){
                palavraComMascara = palavraArriscada;
            }else{
                tentativas = maximoDeTentativas;
            }
        }

        //percorre as letras ja arriscadas
        for(cont = 0; cont < tentativas; cont++){
            //Se encontrar a letra
            if(letrasJaArriscadas[cont] == letra){

                mensagem = "Essa letra ja foi digitada";
                //Indica com a variavel booleana
                jaDigitouLetra = true;
            }
        }
        //Se for uma letra nova
        if(jaDigitouLetra == false){
            //Incrementa as letras ja arriscadas em minúsculo usando a função tolower()
            letrasJaArriscadas += tolower(letra);

            //percorre a palavra real e se a letra existir muda a palavra com mascara
            for(cont = 0; cont < tamanhoDaPalavra; cont++){

                //Se a letra existir na palavra escondida
                if(palavra[cont] == tolower(letra)){ 

                    //Faz aquela letra aparecer na palavraComMascara na posição exata
                    palavraComMascara[cont] = palavra[cont];

                    acertouLetra = true;
                }
            }
         
        

        if(acertouLetra == false){
            mensagem = "Voce errou uma letra!";
        }else{
            mensagem = "Voce acertou uma letra!";
        }

        //Aumenta uma tentativa usada
        tentativas++;

        }

        //Reinicia auxiliares(pois se nao o programa fica com cache, achando que eu ja digitei a letra pra sempre, e o  programa buga)
        jaDigitouLetra = false;
        acertouLetra = false;
    }


    if(palavra == palavraComMascara){
        limpaTela();
        cout << "Parabens voce venceu!";
        cout << "\nDeseja reiniciar?";
        cout << "\n1 - Sim";
        cout << "\n2 - Nao";
        cin >> opcao;
        if(opcao == 1){
            return opcao;
        }else{
            cout << "Ate mais!";
        }
    }else{
        cout << "Bleh, voce perdeu!";
        cout << "\nDeseja reiniciar?";
        cout << "\n1 - Sim";
        cout << "\n2 - Nao";
        cin >> opcao;
        if(opcao == 1){
            return opcao;
        }else{
            cout << "Ate mais!";
        }
    }
   
}

void menuInicial(){
    //Opção escolhida pelo usuário
    int opcao = 0;

    while(opcao < 1 || opcao > 3){
        limpaTela();
        cout << "Bem vindo ao jogo";
        cout << "\n1 - Jogar";
        cout << "\n2 - Jogar em dupla";
        cout << "\n3 - Sobre";
        cout << "\n4 - Sair";
        cout << "\nEscolha uma opcao e tecle ENTER:";

        //Faz a leitura da opcao
        cin >> opcao;
        
        switch (opcao)
        {
        case 1:
        //Inicia o jogo
            if(jogar(1) == 1){
                menuInicial();
            };
            break;

        case 2:
        //Inicia o jogo
            if(jogar(2) == 2){
                menuInicial();
            };
            break;
        
        case 3:
            cout << "Informações do jogo";
            limpaTela();
            cout << "Jogo desenvolvido por mim, continuar a escrever mais tarde";
            cout << "\n1 - Voltar";
            cout << "\n2 - Sair";
            cin >> opcao;
            if(opcao == 1){
                menuInicial();
            }
            break;
        case 4:
            cout << "Até mais";
            break;
        
        default:
            break;
        }
    }
}

int main(){
    //Gera números realmente aleatórios
    srand((unsigned)time(NULL));


    menuInicial();
    return 0;
}