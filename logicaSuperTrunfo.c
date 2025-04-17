#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// Estrutura para representar uma carta de país
struct Carta {
    char nome[50];
    char codigo[4];
    int populacao;
    float area;
    float pib; // em bilhões de dólares
    int pontos_turisticos;
};

// Função para calcular a densidade demográfica
float calcular_densidade(int populacao, float area) {
    return populacao / area;
}

// Função para exibir os dados de uma carta
void exibir_carta(struct Carta carta) {
    float densidade = calcular_densidade(carta.populacao, carta.area);
    float pib_per_capita = (carta.pib * 1000000000) / carta.populacao;
    
    printf("\nDados da Carta:\n");
    printf("País: %s\n", carta.nome);
    printf("Código: %s\n", carta.codigo);
    printf("População: %d habitantes\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões de dólares\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontos_turisticos);
    printf("Densidade Demográfica: %.2f hab/km²\n", densidade);
    printf("PIB per capita: %.2f dólares\n", pib_per_capita);
}

// Função para exibir o menu de atributos disponíveis
void exibir_menu_atributos(bool disponiveis[]) {
    printf("\nEscolha um atributo para comparação:\n");
    if(disponiveis[0]) printf("1 - População\n");
    if(disponiveis[1]) printf("2 - Área\n");
    if(disponiveis[2]) printf("3 - PIB\n");
    if(disponiveis[3]) printf("4 - Pontos Turísticos\n");
    if(disponiveis[4]) printf("5 - Densidade Demográfica\n");
    printf("0 - Cancelar\n");
    printf("Opção: ");
}

int main() {
    // Definindo duas cartas de países
    struct Carta carta1 = {
        "Brasil", "BR1", 213993437, 8515767.0, 1.609, 2500
    };
    
    struct Carta carta2 = {
        "Argentina", "AR2", 45195774, 2780400.0, 445.469, 1200
    };

    int opcao, atributo1 = -1, atributo2 = -1;
    char continuar;
    bool atributos_disponiveis[5] = {true, true, true, true, true};
    
    do {
        // Resetar seleção de atributos
        atributo1 = -1;
        atributo2 = -1;
        for(int i = 0; i < 5; i++) atributos_disponiveis[i] = true;
        
        printf("\n=== SUPER TRUNFO - COMPARAÇÃO AVANÇADA ===\n");
        
        // Seleção do primeiro atributo
        while(atributo1 == -1) {
            exibir_menu_atributos(atributos_disponiveis);
            scanf("%d", &opcao);
            
            switch(opcao) {
                case 1: case 2: case 3: case 4: case 5:
                    if(atributos_disponiveis[opcao-1]) {
                        atributo1 = opcao;
                        atributos_disponiveis[opcao-1] = false;
                    } else {
                        printf("Atributo já selecionado. Escolha outro.\n");
                    }
                    break;
                case 0:
                    printf("Operação cancelada.\n");
                    return 0;
                default:
                    printf("Opção inválida! Tente novamente.\n");
            }
        }
        
        // Seleção do segundo atributo
        while(atributo2 == -1) {
            printf("\nEscolha o segundo atributo (diferente do primeiro):\n");
            exibir_menu_atributos(atributos_disponiveis);
            scanf("%d", &opcao);
            
            switch(opcao) {
                case 1: case 2: case 3: case 4: case 5:
                    if(atributos_disponiveis[opcao-1]) {
                        atributo2 = opcao;
                        atributos_disponiveis[opcao-1] = false;
                    } else {
                        printf("Atributo já selecionado. Escolha outro.\n");
                    }
                    break;
                case 0:
                    printf("Operação cancelada.\n");
                    return 0;
                default:
                    printf("Opção inválida! Tente novamente.\n");
            }
        }
        
        // Variáveis para armazenar os valores dos atributos
        float valor1_atr1, valor2_atr1, valor1_atr2, valor2_atr2;
        char *nome_atr1, *nome_atr2;
        bool menor_vence_atr1 = false, menor_vence_atr2 = false;
        
        // Obter valores e nomes do primeiro atributo
        switch(atributo1) {
            case 1:
                valor1_atr1 = carta1.populacao;
                valor2_atr1 = carta2.populacao;
                nome_atr1 = "População";
                break;
            case 2:
                valor1_atr1 = carta1.area;
                valor2_atr1 = carta2.area;
                nome_atr1 = "Área";
                break;
            case 3:
                valor1_atr1 = carta1.pib;
                valor2_atr1 = carta2.pib;
                nome_atr1 = "PIB";
                break;
            case 4:
                valor1_atr1 = carta1.pontos_turisticos;
                valor2_atr1 = carta2.pontos_turisticos;
                nome_atr1 = "Pontos Turísticos";
                break;
            case 5:
                valor1_atr1 = calcular_densidade(carta1.populacao, carta1.area);
                valor2_atr1 = calcular_densidade(carta2.populacao, carta2.area);
                nome_atr1 = "Densidade Demográfica";
                menor_vence_atr1 = true;
                break;
        }
        
        // Obter valores e nomes do segundo atributo
        switch(atributo2) {
            case 1:
                valor1_atr2 = carta1.populacao;
                valor2_atr2 = carta2.populacao;
                nome_atr2 = "População";
                break;
            case 2:
                valor1_atr2 = carta1.area;
                valor2_atr2 = carta2.area;
                nome_atr2 = "Área";
                break;
            case 3:
                valor1_atr2 = carta1.pib;
                valor2_atr2 = carta2.pib;
                nome_atr2 = "PIB";
                break;
            case 4:
                valor1_atr2 = carta1.pontos_turisticos;
                valor2_atr2 = carta2.pontos_turisticos;
                nome_atr2 = "Pontos Turísticos";
                break;
            case 5:
                valor1_atr2 = calcular_densidade(carta1.populacao, carta1.area);
                valor2_atr2 = calcular_densidade(carta2.populacao, carta2.area);
                nome_atr2 = "Densidade Demográfica";
                menor_vence_atr2 = true;
                break;
        }
        
        // Comparação dos atributos
        int resultado_atr1 = (menor_vence_atr1 ? (valor1_atr1 < valor2_atr1) : (valor1_atr1 > valor2_atr1)) ? 1 : 
                           (menor_vence_atr1 ? (valor2_atr1 < valor1_atr1) : (valor2_atr1 > valor1_atr1)) ? 2 : 0;
        
        int resultado_atr2 = (menor_vence_atr2 ? (valor1_atr2 < valor2_atr2) : (valor1_atr2 > valor2_atr2)) ? 1 : 
                           (menor_vence_atr2 ? (valor2_atr2 < valor1_atr2) : (valor2_atr2 > valor1_atr2)) ? 2 : 0;
        
        // Cálculo da soma dos atributos
        float soma_carta1 = valor1_atr1 + valor1_atr2;
        float soma_carta2 = valor2_atr1 + valor2_atr2;
        
        // Determinar o vencedor geral
        int vencedor_geral = (soma_carta1 > soma_carta2) ? 1 : 
                            (soma_carta2 > soma_carta1) ? 2 : 0;
        
        // Exibir resultados
        printf("\n=== RESULTADOS DA COMPARAÇÃO ===\n");
        printf("Países: %s vs %s\n", carta1.nome, carta2.nome);
        printf("\nAtributo 1: %s\n", nome_atr1);
        printf("%s: %.2f\n", carta1.nome, valor1_atr1);
        printf("%s: %.2f\n", carta2.nome, valor2_atr1);
        printf("Vencedor: %s\n", resultado_atr1 == 0 ? "Empate!" : 
                                 (resultado_atr1 == 1 ? carta1.nome : carta2.nome));
        
        printf("\nAtributo 2: %s\n", nome_atr2);
        printf("%s: %.2f\n", carta1.nome, valor1_atr2);
        printf("%s: %.2f\n", carta2.nome, valor2_atr2);
        printf("Vencedor: %s\n", resultado_atr2 == 0 ? "Empate!" : 
                                 (resultado_atr2 == 1 ? carta1.nome : carta2.nome));
        
        printf("\nSoma dos atributos:\n");
        printf("%s: %.2f\n", carta1.nome, soma_carta1);
        printf("%s: %.2f\n", carta2.nome, soma_carta2);
        printf("\nResultado Final: %s\n", vencedor_geral == 0 ? "Empate!" : 
                                        (vencedor_geral == 1 ? carta1.nome : carta2.nome));
        
        // Perguntar se deseja continuar
        printf("\nDeseja fazer outra comparação? (S/N): ");
        scanf(" %c", &continuar);
        continuar = toupper(continuar);
        
    } while(continuar == 'S');
    
    printf("\nObrigado por jogar Super Trunfo!\n");
    return 0;
}