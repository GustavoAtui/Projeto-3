#include "biblioteca.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Menu(Tarefa Lista[]) {
    int cod;
    cod = lerarquivo(Lista); // Le as tarefas do arquivo
    if (cod == 1) {
        printf("Não foi possível ler o arquivo!\n");
    }

    Tarefa *tarefa = malloc(sizeof(Tarefa));
    int opcao;
    do { // Mostra as opções para o usuário
        printf(" --- MENU ---\n");
        printf("1 - Criar tarefa.\n2 - Deletar tarefa.\n3 - Listar tarefas.\n4 - Alterar Tarefa.\n"
               "5 - Filtrar Tarefa pela Prioridade. \n6 - Filtrar Tarefa pelo Estado. \n7 - Filtrar Tarefa pela Categoria. \n8 - Filtrar Tarefa pela Prioridade e Categoria. \n9 - Exportar Tarefa pela Prioridade. \n10 - Exportar Tarefa pela Categoria. \n11 - Exportar Tarefa pela Prioridade e Categoria.\n0 - Sair.\n");
        printf("Digite a operacao que deseja realizar: ");
        scanf("%d", &opcao);
        getchar();// Limpa o buffer do teclado
        switch (opcao) {
            case 1:
                CriarTarefa(Lista);
                break;
            case 2:
                DeletarTarefa(Lista);
                break;
            case 3:
                ListarTarefas(Lista);
                break;
            case 4:
                Alterartarefa(Lista);
                break;
            case 5:
                FiltrartarefaPrioridade(Lista);
                break;
            case 6:
                FiltrartarefaEstado(Lista);
                break;
            case 7:
              FiltrarTarefaCategoria(Lista);
              break;
            case 8:
              FiltrarTarefasPorPrioridadeECategoria(Lista);
              break;
            case 9:
            ExportarPorPrioridade(Lista);
              break;
            case 10:
            ExportarPorCategoria(Lista);
            break;
            case 11:
            ExportarPorPrioridadeCategoria(Lista);
            break;

        };
    } while (opcao != 0);

    criararquivo(Lista);
    free(tarefa); // Libera a memoria alocada 
}
// Função para listar tarefas 
void ListarTarefas2(Tarefa Lista[]) {
    printf("\n---LISTA DE TAREFAS---\n\n");
    for (int i = 0; i < maxtarefas; i++) {
        if (Lista[i].existe == 1) {
            int num = i + 1;
            printf("Tarefa %d: %s\n", num, Lista[i].tarefa);
        }
    }
    printf("\n");
}
// Função para listar tarefas existentes
void CriarTarefa(Tarefa Lista[]) {
    // Declaração de variáveis locais
    char tarefa[100];
    char descricao[300];
    int prioridade;
    char estado[15];
    char categoria[15];
    size_t len2;
    size_t len;
    // Pede as informações para criar a tarefa
    printf("Digite sua tarefa: ");
    fgets(tarefa, sizeof(tarefa), stdin);
    printf("Digite aqui a descricao desta tarefa: ");
    fgets(descricao, sizeof(descricao), stdin);
    printf("Digite aqui a prioridade desta tarefa: ");
    scanf("%d", &prioridade);
    limpar();
    // Definicao dos estados para a tarefa
    char est[15];
    char est2[15];
    char est3[15];
    int comp;
    int comp2;
    int comp3;
    sprintf(est, "Feito");
    sprintf(est2, "Fazendo");
    sprintf(est3, "Fazer");
    // Loop para que o estado da tarefa seja valido
    do {
        printf("Digite o estado dessa tarefa(Feito,Fazendo ou Fazer): ");
        fgets(estado, sizeof(estado), stdin);
        len = strlen(estado);
        if (estado[len - 1] == '\n') estado[--len] = 0;
        comp = strcmp(estado, est);
        comp2 = strcmp(estado, est2);
        comp3 = strcmp(estado, est3);
    } while (comp != 0 && comp2 != 0 && comp3 != 0);
    // Definicao de categorias para a tarefa
    char categoria1[15];
    char categoria2[15];
    char categoria3[15];
    char categoria4[15];
    sprintf(categoria, "Casa");
    sprintf(categoria2, "Trabalho");
    sprintf(categoria3, "Estudo");
    sprintf(categoria4, "Lazer");
    int comp4;
    int comp5;
    int comp6;
    int comp7;
    // Loop para que a categoria da tarefa seja valida
    do {
        printf("Digite a categoria dessa tarefa(Casa,Trabalho,Estudo e Lazer): ");
        fgets(categoria, sizeof(categoria), stdin);
        len2 = strlen(categoria);
        if (categoria[len2 - 1] == '\n') categoria[--len2] = 0;
        comp4 = strcmp(categoria, categoria1);
        comp5 = strcmp(categoria, categoria2);
        comp6 = strcmp(categoria, categoria3);
        comp7 = strcmp(categoria, categoria4);
    } while (comp4 != 0 && comp5 != 0 && comp6 != 0 && comp7 != 0);
    // Adicao da tarefa a lista de tarefas
    for (int i = 0; i < maxtarefas; i++) {
        if (Lista[i].existe == 0) {
            strcpy(Lista[i].tarefa, tarefa);
            strcpy(Lista[i].descricao, descricao);
            strcpy(Lista[i].estado, estado);
            strcpy(Lista[i].categoria, categoria);
            Lista[i].prioridade = prioridade;
            Lista[i].existe = 1;
            break;
        };
    };
}
// Função para excluir uma tarefa existente
void DeletarTarefa(Tarefa Lista[]) {
    // Exibe a lista de tarefas para o usuario excluir
    printf("Aqui está sua lista!\n");
    ListarTarefas2(Lista);
    int del;
    printf("Qual tarefa deseja excluir: ");
    scanf("%d", &del);
    // posição do array onde esta a tarefa escolhida 
    int pos = del - 1;
    //deleta a tarefa 
    Lista[pos].existe = 0;
    printf("Tarefa excluída com sucesso!\n");
}
// Função para listar todas as tarefas existentes detalhadamente
void ListarTarefas(Tarefa Lista[]) {
    printf("\n--- LISTA DE TAREFAS ---\n");
    printf("\n");
    // Loop para percorrer todas as tarefas na lista
    for (int i = 0; i < maxtarefas; i++) {
        if (Lista[i].existe == 1) {
            // Exibe as informações da tarefa
            printf("Tarefa: %s", Lista[i].tarefa);
            printf("Descricao: %s", Lista[i].descricao);
            printf("Prioridade: %d\n", Lista[i].prioridade);
            printf("Estado: %s\n", Lista[i].estado);
            printf("Categoria: %s", Lista[i].categoria);
            printf("\n-----------------\n");
        }
    }
}
// Função para alterar uma tarefa existente
void Alterartarefa(Tarefa Lista[]) {
    // Declaracao de variaveis locais
    char novatarefa[20];
    char novadescricao[100];
    int novaprioridade;
    char novoestado[15];
    int num;
    int alt;
    int opcao;
    // Exibe a lista de tarefas para o usuario excluir
    ListarTarefas2(Lista);
    printf("Digite qual tarefa deseja alterar: ");
    scanf("%d", &alt);
    // posição do array onde esta a tarefa escolhida
    num = alt - 1;
    // Exibe opções de alteração para o usuário
    printf("1. A tarefa.\n");
    printf("2. A descricao.\n");
    printf("3. A prioridade.\n");
    printf("4. O estado.\n");
    printf("Digite o que deseja mudar: ");
    scanf("%d", &opcao);
    // Limpa o buffer do teclado
    limpar();
    // Realiza a alteracao com base na opcao escolhida
    if (opcao == 1) {
        printf("Digite qual vai ser a nova tarefa: ");
        fgets(novatarefa, sizeof(novatarefa), stdin);
        sprintf(Lista[num].tarefa, novatarefa);
        printf("Tarefa alterada com sucesso!\n");
    }
    if (opcao == 2) {
        printf("Digite qual vai ser a nova descricao: ");
        fgets(novadescricao, sizeof(novatarefa), stdin);
        sprintf(Lista[num].descricao, novadescricao);
        printf("Descricao alterada com sucesso!\n");
    }
    if (opcao == 3) {
        printf("Digite qual vai ser a nova prioridade: ");
        scanf("%d", &novaprioridade);
        Lista[num].prioridade = novaprioridade;
        printf("Prioridade alterada com sucesso!\n");
    }
    if (opcao == 4) {
        // Variaveis para validar o novo estado
        char estado[15];
        char est[15];
        char est2[15];
        char est3[15];
        int comp;
        int comp2;
        int comp3;
        size_t len;
        sprintf(est, "Feito");
        sprintf(est2, "Fazendo");
        sprintf(est3, "Fazer");
        // Loop para que o estado da tarefa seja valido
        do {
            printf("Digite o novo estado(Feito,Fazendo ou Fazer): ");
            fgets(estado, sizeof(estado), stdin);
            len = strlen(estado);
            if (estado[len - 1] == '\n') estado[--len] = 0;
            comp = strcmp(estado, est);
            comp2 = strcmp(estado, est2);
            comp3 = strcmp(estado, est3);
        } while (comp != 0 && comp2 != 0 && comp3 != 0);
        sprintf(Lista[num].estado, estado);
        printf("Estado alterado com sucesso!\n");
    }
}
// Função para filtrar tarefas por prioridade
void FiltrartarefaPrioridade(Tarefa Lista[]) {
    int pri;
    int contador = 0;
    printf("Digite a prioridade que deseja filtrar: ");
    scanf("%d", &pri);
    printf("\n");
    // Loop para percorrer todas as tarefas na lista
    for (int i = 0; i < maxtarefas; i++) {
        // Verifica se a prioridade da tarefa na posicao atual é igual à prioridade desejada
        if (Lista[i].prioridade == pri) {
            contador++;
            // Exibe as informações das tarefas
          printf("\n-----------------\n");
          printf("Tarefa: %s", Lista[i].tarefa);
          printf("Descricao: %s", Lista[i].descricao);
          printf("Prioridade: %d\n", Lista[i].prioridade);
          printf("Estado: %s\n", Lista[i].estado);
          printf("Categoria: %s", Lista[i].categoria);
          printf("\n-----------------\n");
        }
    }
    //se nao encontrar a terefa com essa prioridade faz esse print
    if (contador == 0) {
        printf("Nao tem nenhuma tarefa com essa prioridade!\n");
    }
    printf("\n");
}
// Função para filtrar tarefas por estado
void FiltrartarefaEstado(Tarefa Lista[]) {
    // Definicao de categorias para a tarefa
    int contador = 0;
    char estado[15];
    char est[15];
    char est2[15];
    char est3[15];
    int comp;
    int comp2;
    int comp3;
    int comp4;
    size_t len;
    sprintf(est, "Completo");
    sprintf(est2, "Em andamento");
    sprintf(est3, "Nao iniciado");
    // Loop para que o estado da tarefa seja valido
    do {
        printf("Digite o estado que deseja filtrar(Completo,Em andamento ou Nao iniciado): ");
        fgets(estado, sizeof(estado), stdin);
        len = strlen(estado);
        if (estado[len - 1] == '\n') estado[--len] = 0;
        comp = strcmp(estado, est);
        comp2 = strcmp(estado, est2);
        comp3 = strcmp(estado, est3);
    } while (comp != 0 && comp2 != 0 && comp3 != 0);
    printf("\n");
    // Loop para percorrer todas as tarefas na lista
    for (int i = 0; i < maxtarefas; i++) {
        comp4 = strcmp(estado, Lista[i].estado);
        // Compara o estado da tarefa na posição atual com o estado desejado
        if (comp4 == 0) {
            contador++;
        //printa a lista de tarefas filtradas por estado
          printf("\n-----------------\n");
          printf("Tarefa: %s", Lista[i].tarefa);
          printf("Descricao: %s", Lista[i].descricao);
          printf("Prioridade: %d\n", Lista[i].prioridade);
          printf("Estado: %s\n", Lista[i].estado);
          printf("Categoria: %s", Lista[i].categoria);
          printf("\n-----------------\n");
        }
    }
    //se nao encontrar a terefa com essa prioridade faz esse print
    if (contador == 0) {
        printf("Nao tem nenhuma tarefa com esse estado!\n");
    }
    printf("\n");
}
// Função para filtrar tarefas por categoria
void FiltrarTarefaCategoria(Tarefa Lista[]) {
    // Definicao de categorias para a tarefa
  int contador = 0;
  char categoria[15];
  char categoria1[15];
  char categoria2[15];
  char categoria3[15];
  char categoria4[15];
  int comp;
  int comp2;
  int comp3;
  int comp4;
  size_t len;
  sprintf(categoria1, "Casa");
  sprintf(categoria2, "Trabalho");
  sprintf(categoria3, "Estudo");
  sprintf(categoria4, "Lazer");
  // Loop para que o estado da tarefa seja valido
  do {
      printf("Digite o estado que deseja filtrar(Casa,Trabalho, Estudo ou Lazer): ");
      fgets(categoria, sizeof(categoria), stdin);
      len = strlen(categoria);
      if (categoria[len - 1] == '\n') categoria[--len] = 0;
      comp = strcmp(categoria, categoria1);
      comp2 = strcmp(categoria, categoria2);
      comp3 = strcmp(categoria, categoria3);
      comp4 = strcmp(categoria, categoria4);
  } while (comp != 0 && comp2 != 0 && comp3 != 0 && comp4 != 0);
  printf("\n");

    printf("\n--- TAREFAS FILTRADAS POR CATEGORIA  ---\n");

    
    for (int i = 0; i < maxtarefas; i++) {
        // Verifica se a tarefa na posição atual existe e é igual a categoria 
        if (Lista[i].existe == 1 && strcmp(Lista[i].categoria, categoria) == 0) {
            contador++;
            //Printa a lista de tarefas filtradas por categoria
            printf("\n-----------------\n");
            printf("Tarefa: %s", Lista[i].tarefa);
            printf("Descricao: %s", Lista[i].descricao);
            printf("Prioridade: %d\n", Lista[i].prioridade);
            printf("Estado: %s\n", Lista[i].estado);
            printf("Categoria: %s", Lista[i].categoria);
            printf("\n-----------------\n");
        }
    }
    // Se nao encontrar a terefa com essa prioridade faz esse print
    if (contador == 0) {
        printf("Nao tem nenhuma tarefa com essa categoria!\n");
    }
}

// Função para filtrar tarefas por prioridade e categoria
void FiltrarTarefasPorPrioridadeECategoria(Tarefa Lista[]) {
    // Definicao de categorias para a tarefa
    int prioridade;
  char categoria[15];
  char categoria1[15];
  char categoria2[15];
  char categoria3[15];
  char categoria4[15];
  int comp;
  int comp2;
  int comp3;
  int comp4;
  size_t len;
  sprintf(categoria1, "Casa");
  sprintf(categoria2, "Trabalho");
  sprintf(categoria3, "Estudo");
  sprintf(categoria4, "Lazer");
  // Loop para que a categoria da tarefa seja valido
  do {
      printf("Digite o estado que deseja filtrar(Casa,Trabalho, Estudo ou Lazer): ");
      fgets(categoria, sizeof(categoria), stdin);
      len = strlen(categoria);
      if (categoria[len - 1] == '\n') categoria[--len] = 0;
      comp = strcmp(categoria, categoria1);
      comp2 = strcmp(categoria, categoria2);
      comp3 = strcmp(categoria, categoria3);
      comp4 = strcmp(categoria, categoria4);
  } while (comp != 0 && comp2 != 0 && comp3 != 0 && comp4 != 0);
  printf("\n");
    // Digitar a prioridade desejada 
    printf("Digite a prioridade que deseja filtrar: ");
    scanf("%d", &prioridade);
    while (getchar() != '\n'); 

    int contador = 0;

    printf("\n--- TAREFAS FILTRADAS POR PRIORIDADE E CATEGORIA ---\n");

    for (int i = 0; i < maxtarefas; i++) {
        // Verifica se a tarefa na posição atual existe e é igual a categoria e prioridade
        if (Lista[i].existe == 1 && strcmp(Lista[i].categoria, categoria) == 0 &&
            Lista[i].prioridade == prioridade) {
            contador++;
             //Printa a lista de tarefas filtradas por categoria e prioridade
            printf("\n-----------------\n");
            printf("Tarefa: %s", Lista[i].tarefa);
            printf("Descricao: %s", Lista[i].descricao);
            printf("Prioridade: %d\n", Lista[i].prioridade);
            printf("Estado: %s\n", Lista[i].estado);
            printf("Categoria: %s", Lista[i].categoria);
            printf("\n-----------------\n");
        }
    }
    //Se nao encontrar a terefa com essa prioridade faz esse print
    if (contador == 0) {
        printf("Nao tem nenhuma tarefa com essa categoria e prioridade!\n");
    }
}
// Função para exportar tarefas por prioridade para um arquivo
void ExportarPorPrioridade(Tarefa Lista[]) {
    //Variavel para armazenar a prioridade 
    int prioridade;

    printf("Digite a prioridade para exportar as tarefas: ");
    scanf("%d", &prioridade);
    while (getchar() != '\n'); // Limpa o buffer do teclado
    //Nome do arquivo de exportação
  char arqpri[] = "aqrpri.txt";
       arqpri[strcspn( arqpri, "\n")] = '\0';  
    //Abre o arquivo 
    FILE *arquivo = fopen(arqpri, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    printf("\n--- TAREFAS EXPORTADAS POR PRIORIDADE ---\n");
    //Loop para percorrer todas as tarefas na Lista
  for (int i = 0; i < maxtarefas; i++) {
      if (Lista[i].existe == 1 && Lista[i].prioridade == prioridade) {
            //Printa as informacoes no arquivo
          fprintf(arquivo, "-----------------\n");
          fprintf(arquivo, "Tarefa: %s", Lista[i].tarefa);
          fprintf(arquivo, "Descricao: %s\n", Lista[i].descricao);
          fprintf(arquivo, "Prioridade: %d\n", Lista[i].prioridade);
          fprintf(arquivo, "Estado: %s\n", Lista[i].estado);
          fprintf(arquivo, "Categoria: %s\n", Lista[i].categoria);
          fprintf(arquivo, "-----------------\n");
      }
  }

    fclose(arquivo);

    printf("Tarefas exportadas com sucesso para o arquivo %s.\n", arqpri);
    return;
}
// Função para exportar tarefas por categoria para um arquivo
void ExportarPorCategoria(Tarefa Lista[]) {
    //Variavel para armazenar a categoria 
    char categoria[15];

    printf("Digite a categoria para exportar as tarefas: ");
    fgets(categoria, sizeof(categoria), stdin);
    categoria[strcspn(categoria, "\n")] = '\0';  
    //Nome do arquivo de exportação
    char aqrcat[] = "aqrcat.txt";  
    //Abre o arquivo 
    FILE *arquivo = fopen(aqrcat, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    printf("\n--- TAREFAS EXPORTADAS POR CATEGORIA  ---\n");

    //Ordena as tarefas por prioridade em ordem decrescente
    for (int i = 0; i < maxtarefas - 1; i++) {
        for (int j = i + 1; j < maxtarefas; j++) {
            if (Lista[j].existe == 1 && Lista[i].existe == 1 && Lista[j].prioridade > Lista[i].prioridade) {

                Tarefa temp = Lista[i];
                Lista[i] = Lista[j];
                Lista[j] = temp;
            }
        }
    }
    //Loop para percorrer todas as tarefas na Lista
  for (int i = 0; i < maxtarefas; i++) {
      if (Lista[i].existe == 1 && strcmp(Lista[i].categoria, categoria) == 0) {
        //Printa as informacoes no arquivo
          fprintf(arquivo, "-----------------\n");
          fprintf(arquivo, "Tarefa: %s", Lista[i].tarefa);
          fprintf(arquivo, "Descricao: %s\n", Lista[i].descricao);
          fprintf(arquivo, "Prioridade: %d\n", Lista[i].prioridade);
          fprintf(arquivo, "Estado: %s\n", Lista[i].estado);
          fprintf(arquivo, "Categoria: %s\n", Lista[i].categoria);
          fprintf(arquivo, "-----------------\n");
      }
  }

    fclose(arquivo);

    printf("Tarefas exportadas com sucesso para o arquivo %s.\n", aqrcat);
    return;
}
// Função para exportar tarefas por prioridade e categoria para um arquivo
void ExportarPorPrioridadeCategoria(Tarefa Lista[]) {
    //Variavel para armazenar a categoria
    char categoria[15];

    printf("Digite a categoria para exportar as tarefas: ");
    fgets(categoria, sizeof(categoria), stdin);
    categoria[strcspn(categoria, "\n")] = '\0';  
    //Variavel para armazenar a prioridade 
    int prioridade;

    printf("Digite a prioridade para exportar as tarefas: ");
    scanf("%d", &prioridade);
    while (getchar() != '\n'); //Limpa o buffer do teclado 
    //Nome do arquivo
    char NomeArq[] = "aqrpricat.txt";  
    //Abre o arquivo
    FILE *arquivo = fopen(NomeArq, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    printf("\n--- TAREFAS EXPORTADAS POR PRIORIDADE E CATEGORIA ---\n");

    //Ordena as tarefas por prioridade em ordem decrescente
    for (int i = 0; i < maxtarefas - 1; i++) {
        for (int j = i + 1; j < maxtarefas; j++) {
            if (Lista[j].existe == 1 && Lista[i].existe == 1 && Lista[j].prioridade > Lista[i].prioridade) {

                Tarefa temp = Lista[i];
                Lista[i] = Lista[j];
                Lista[j] = temp;
            }
        }
    }
    //Loop para percorrer todas as tarefas na Lista
  for (int i = 0; i < maxtarefas; i++) {
      if (Lista[i].existe == 1 && strcmp(Lista[i].categoria, categoria) == 0 && Lista[i].prioridade == prioridade) {
          //Printa as informacoes no arquivo
          fprintf(arquivo, "-----------------\n");
          fprintf(arquivo, "Tarefa: %s\n", Lista[i].tarefa);
          fprintf(arquivo, "Prioridade: %d\n", Lista[i].prioridade);
          fprintf(arquivo, "Categoria: %s\n", Lista[i].categoria);
          fprintf(arquivo, "Estado: %s\n", Lista[i].estado);
          fprintf(arquivo, "Descricao: %s\n", Lista[i].descricao);
          fprintf(arquivo, "-----------------\n");
      }
  }

    fclose(arquivo);

    printf("Tarefas exportadas com sucesso para o arquivo %s.\n", NomeArq);
    return;
}
// Função para criar um arquivo e salvar as tarefas 
int criararquivo(Tarefa Lista[]) {
    // Abre o arquivo binario
    FILE *arqtarefas = fopen("arqtarefas", "wb");
    if (arqtarefas == NULL) {
        return 1;
    }
    //Escreve as informacoes da lista no arquivo binario
    fwrite(Lista, sizeof(Tarefa), maxtarefas, arqtarefas);
    fclose(arqtarefas);
    return 0;
}
// Função para ler as tarefas de um arquivo
int lerarquivo(Tarefa Lista[]) {
     // Abre o arquivo binário para leitura
    FILE *arqtarefas = fopen("arqtarefas", "rb");
    if (arqtarefas == NULL) {
        return 1;
    }
    //Le as informacoes do arquivo binario para a lista de tarefas
    fread(Lista, sizeof(Tarefa), maxtarefas, arqtarefas);
    fclose(arqtarefas);
    return 0;
}

void limpar() {
    int c;
    //Loop para ler e descartar caracter ate encontrar uma nova linha
    while ((c = getchar()) != '\n' && c != EOF) {}
}