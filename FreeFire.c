

// Código da Ilha – Edição Free Fire
// Nível: Mestre
// Este programa simula o gerenciamento avançado de uma mochila com componentes coletados durante a fuga de uma ilha.
// Ele introduz ordenação com critérios e busca binária para otimizar a gestão dos recursos.


    // Menu principal com opções:
    // 1. Adicionar um item
    // 2. Remover um item
    // 3. Listar todos os itens
    // 4. Ordenar os itens por critério (nome, tipo, prioridade)
    // 5. Realizar busca binária por nome
    // 0. Sair

    // A estrutura switch trata cada opção chamando a função correspondente.
    // A ordenação e busca binária exigem que os dados estejam bem organizados.

 

// Struct Item:
// Representa um componente com nome, tipo, quantidade e prioridade (1 a 5).
// A prioridade indica a importância do item na montagem do plano de fuga.

// Enum CriterioOrdenacao:
// Define os critérios possíveis para a ordenação dos itens (nome, tipo ou prioridade).

// Vetor mochila:
// Armazena até 10 itens coletados.
// Variáveis de controle: numItens (quantidade atual), comparacoes (análise de desempenho), ordenadaPorNome (para controle da busca binária).

// limparTela():
// Simula a limpeza da tela imprimindo várias linhas em branco.

// exibirMenu():
// Apresenta o menu principal ao jogador, com destaque para status da ordenação.

// inserirItem():
// Adiciona um novo componente à mochila se houver espaço.
// Solicita nome, tipo, quantidade e prioridade.
// Após inserir, marca a mochila como "não ordenada por nome".

// removerItem():
// Permite remover um componente da mochila pelo nome.
// Se encontrado, reorganiza o vetor para preencher a lacuna.

// listarItens():
// Exibe uma tabela formatada com todos os componentes presentes na mochila.

// menuDeOrdenacao():
// Permite ao jogador escolher como deseja ordenar os itens.
// Utiliza a função insertionSort() com o critério selecionado.
// Exibe a quantidade de comparações feitas (análise de desempenho).

// insertionSort():
// Implementação do algoritmo de ordenação por inserção.
// Funciona com diferentes critérios de ordenação:
// - Por nome (ordem alfabética)
// - Por tipo (ordem alfabética)
// - Por prioridade (da mais alta para a mais baixa)

// buscaBinariaPorNome():
// Realiza busca binária por nome, desde que a mochila esteja ordenada por nome.
// Se encontrar, exibe os dados do item buscado.
// Caso contrário, informa que não encontrou o item.
#include <stdio.h>
#include <string.h>

#define MAX_ITENS 10

// Estrutura para representar um item da mochila
typedef struct {
    char nome[50];
    char tipo[30];
    int quantidade;
} Item;

int main() {
    Item mochila[MAX_ITENS];
    int opcao;
    int total_itens = 0;
    char nome_remover[50];

    do {
        printf("\n=== CODIGO DA ILHA - NIVEL NOVATO ===\n");
        printf("1. Adicionar item\n");
        printf("2. Remover item\n");
        printf("3. Listar itens\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // limpar buffer do teclado

        switch (opcao) {
            case 1:
                if (total_itens >= MAX_ITENS) {
                    printf("\n⚠️ Mochila cheia! Nao e possivel adicionar mais itens.\n");
                } else {
                    printf("\nDigite o nome do item: ");
                    fgets(mochila[total_itens].nome, sizeof(mochila[total_itens].nome), stdin);
                    mochila[total_itens].nome[strcspn(mochila[total_itens].nome, "\n")] = '\0';

                    printf("Digite o tipo do item: ");
                    fgets(mochila[total_itens].tipo, sizeof(mochila[total_itens].tipo), stdin);
                    mochila[total_itens].tipo[strcspn(mochila[total_itens].tipo, "\n")] = '\0';

                    printf("Digite a quantidade: ");
                    scanf("%d", &mochila[total_itens].quantidade);

                    total_itens++;
                    printf("\n✅ Item adicionado com sucesso!\n");
                }
                break;

            case 2:
                if (total_itens == 0) {
                    printf("\n⚠️ Nenhum item na mochila para remover.\n");
                } else {
                    printf("\nDigite o nome do item para remover: ");
                    getchar(); // limpar o buffer
                    fgets(nome_remover, sizeof(nome_remover), stdin);
                    nome_remover[strcspn(nome_remover, "\n")] = '\0';

                    int encontrado = 0;
                    for (int i = 0; i < total_itens; i++) {
                        if (strcmp(mochila[i].nome, nome_remover) == 0) {
                            // mover os itens seguintes uma posição para trás
                            for (int j = i; j < total_itens - 1; j++) {
                                mochila[j] = mochila[j + 1];
                            }
                            total_itens--;
                            encontrado = 1;
                            printf("\n🗑️ Item removido com sucesso!\n");
                            break;
                        }
                    }
                    if (!encontrado) {
                        printf("\n❌ Item nao encontrado!\n");
                    }
                }
                break;

            case 3:
                if (total_itens == 0) {
                    printf("\n📦 Mochila vazia.\n");
                } else {
                    printf("\n=== ITENS NA MOCHILA ===\n");
                    printf("%-20s %-15s %-10s\n", "Nome", "Tipo", "Quantidade");
                    printf("-------------------------------------------------\n");
                    for (int i = 0; i < total_itens; i++) {
                        printf("%-20s %-15s %-10d\n",
                               mochila[i].nome,
                               mochila[i].tipo,
                               mochila[i].quantidade);
                    }
                }
                break;

            case 4:
                printf("\n🏝️ Saindo do desafio... ate a proxima!\n");
                break;

            default:
                printf("\n❗ Opcao invalida! Tente novamente.\n");
        }

    } while (opcao != 4);

    return 0;
}