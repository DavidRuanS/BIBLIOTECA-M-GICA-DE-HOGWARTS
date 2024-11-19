
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

// Estrutura para armazenar informações do livro na árvore binária
typedef struct Livro {
    char titulo[100];
    char autor[50];
    int ano;
    struct Livro *esquerda, *direita;
} Livro;

// Funções para manipulação da árvore
Livro* criarLivro(char *titulo, char *autor, int ano) {
    Livro* novo = (Livro*)malloc(sizeof(Livro));
    strcpy(novo->titulo, titulo);
    strcpy(novo->autor, autor);
    novo->ano = ano;
    novo->esquerda = novo->direita = NULL;
    return novo;
}

Livro* inserirLivro(Livro* raiz, char *titulo, char *autor, int ano) {
    if (raiz == NULL) return criarLivro(titulo, autor, ano);

    if (strcmp(titulo, raiz->titulo) < 0)
        raiz->esquerda = inserirLivro(raiz->esquerda, titulo, autor, ano);
    else
        raiz->direita = inserirLivro(raiz->direita, titulo, autor, ano);

    return raiz;
}

// Função para buscar livro na árvore
void buscarLivro(Livro* raiz, char *titulo) {
    if (raiz == NULL) {
        printf("Livro não encontrado.\n");
        return;
    }

    if (strcmp(titulo, raiz->titulo) == 0) {
        printf("Livro encontrado: %s, Autor: %s, Ano: %d\n", raiz->titulo, raiz->autor, raiz->ano);
    } else if (strcmp(titulo, raiz->titulo) < 0) {
        buscarLivro(raiz->esquerda, titulo);
    } else {
        buscarLivro(raiz->direita, titulo);
    }
}

// Função para exibir todos os livros em ordem alfabética
void exibirLivros(Livro* raiz) {
    if (raiz != NULL) {
        exibirLivros(raiz->esquerda);
        printf("Título: %s, Autor: %s, Ano: %d\n", raiz->titulo, raiz->autor, raiz->ano);
        exibirLivros(raiz->direita);
    }
}

// Função para remover um livro da árvore
Livro* excluirLivro(Livro* raiz, char *titulo) {
    if (raiz == NULL) {
        printf("Livro não encontrado para exclusão.\n");
        return NULL;
    }

    if (strcmp(titulo, raiz->titulo) < 0) {
        raiz->esquerda = excluirLivro(raiz->esquerda, titulo);
    } else if (strcmp(titulo, raiz->titulo) > 0) {
        raiz->direita = excluirLivro(raiz->direita, titulo);
    } else {
        // Caso 1: Sem filhos
        if (raiz->esquerda == NULL && raiz->direita == NULL) {
            free(raiz);
            return NULL;
        }
        // Caso 2: Um filho
        else if (raiz->esquerda == NULL) {
            Livro* temp = raiz->direita;
            free(raiz);
            return temp;
        } else if (raiz->direita == NULL) {
            Livro* temp = raiz->esquerda;
            free(raiz);
            return temp;
        }
        // Caso 3: Dois filhos
        else {
            Livro* temp = raiz->direita;
            while (temp->esquerda != NULL) {
                temp = temp->esquerda;
            }
            strcpy(raiz->titulo, temp->titulo);
            strcpy(raiz->autor, temp->autor);
            raiz->ano = temp->ano;
            raiz->direita = excluirLivro(raiz->direita, temp->titulo);
        }
    }
    return raiz;
}

// Função para salvar a árvore no arquivo
void salvarArquivo(Livro* raiz, FILE *arquivo) {
    if (raiz != NULL) {
        fprintf(arquivo, "%s;%s;%d\n", raiz->titulo, raiz->autor, raiz->ano);
        salvarArquivo(raiz->esquerda, arquivo);
        salvarArquivo(raiz->direita, arquivo);
    }
}

// Função para carregar livros do arquivo
Livro* carregarArquivo(Livro* raiz) {
    FILE *arquivo = fopen("biblioteca_hogwarts.txt", "r");
    if (arquivo == NULL) return NULL;

    char titulo[100], autor[50];
    int ano;

    while (fscanf(arquivo, "%99[^;];%49[^;];%d\n", titulo, autor, &ano) != EOF) {
        raiz = inserirLivro(raiz, titulo, autor, ano);
    }

    fclose(arquivo);
    return raiz;
}

// Função principal
int main() {
    setlocale(LC_ALL, "Portuguese_Brazil.1252"); // Definindo a localidade para português brasileiro

    Livro* raiz = NULL;
    int opcao;
    raiz = carregarArquivo(raiz); // Carrega os livros existentes no arquivo

    printf("Bem-vindo à Biblioteca de Hogwarts!\n");
    printf("Aqui você encontrará livros mágicos e raros usados pelos alunos da Escola de Magia e Bruxaria.\n");
    printf("Você pode gerenciar os livros da biblioteca adicionando, buscando, listando e até removendo livros antigos.\n");

    do {
        printf("\n--- Menu da Biblioteca de Hogwarts ---\n");
        printf("1. Cadastrar Livro\n");
        printf("2. Buscar Livro\n");
        printf("3. Exibir Todos os Livros\n");
        printf("4. Excluir Livro\n");
        printf("5. Salvar e Sair\n");
        printf("Escolha uma opção: ");
        if (scanf("%d", &opcao) != 1) { // Verifica se a leitura foi bem-sucedida
            printf("Entrada inválida! Tente novamente.\n");
            while (getchar() != '\n'); // Limpa o buffer
            continue;
        }

        switch(opcao) {
            case 1: {
                char titulo[100], autor[50];
                int ano;
                printf("Digite o título do livro: ");
                while (getchar() != '\n'); // Limpa o buffer
                fgets(titulo, sizeof(titulo), stdin);
                titulo[strcspn(titulo, "\n")] = '\0';  // Remove nova linha
                printf("Digite o autor do livro: ");
                fgets(autor, sizeof(autor), stdin);
                autor[strcspn(autor, "\n")] = '\0';  // Remove nova linha
                printf("Digite o ano de publicação: ");
                if (scanf("%d", &ano) != 1) {
                    printf("Ano inválido!\n");
                    while (getchar() != '\n'); // Limpa o buffer
                    continue;
                }
                raiz = inserirLivro(raiz, titulo, autor, ano);
                printf("Livro cadastrado com sucesso!\n");
                break;
            }
            case 2: {
                char titulo[100];
                printf("Digite o título do livro a ser buscado: ");
                while (getchar() != '\n'); // Limpa o buffer
                fgets(titulo, sizeof(titulo), stdin);
                titulo[strcspn(titulo, "\n")] = '\0';  // Remove nova linha
                buscarLivro(raiz, titulo);
                break;
            }
            case 3:
                printf("\n--- Lista de Livros ---\n");
                exibirLivros(raiz);
                break;
            case 4: {
                char titulo[100];
                printf("Digite o título do livro a ser excluído: ");
                while (getchar() != '\n'); // Limpa o buffer
                fgets(titulo, sizeof(titulo), stdin);
                titulo[strcspn(titulo, "\n")] = '\0';  // Remove nova linha
                raiz = excluirLivro(raiz, titulo);
                printf("Livro excluído com sucesso, se existia.\n");
                break;
            }
            case 5: {
                FILE *arquivo = fopen("biblioteca_hogwarts.txt", "w");
                if (arquivo == NULL) {
                    printf("Erro ao abrir o arquivo!\n");
                    break;
                }
                salvarArquivo(raiz, arquivo);
                fclose(arquivo);
                printf("Livros salvos com sucesso! Saindo...\n");
                break;
            }
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 5);

    return 0;
}

