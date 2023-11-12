#include "biblioteca.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Menu(Tarefa Lista[]) {
    int cod;
    cod = lerarquivo(Lista);
    if (cod == 1) {
        printf("Não foi possível ler o arquivo!\n");
    }

    Tarefa *tarefa = malloc(sizeof(Tarefa));
    int opcao;
    do {
        printf(" --- MENU ---\n");
        printf("1 - Criar tarefa.\n2 - Deletar tarefa.\n3 - Listar tarefas.\n4 - Alterar Tarefa.\n"
               "5 - Filtrar Tarefa pela Prioridade. \n6 - Filtrar Tarefa pelo Estado. \n7 - Filtrar Tarefa pela Categoria. \n8 - Filtrar Tarefa pela Prioridade e Categoria. \n9 - Exportar Tarefa pela Prioridade. \n10 - Exportar Tarefa pela Categoria. \n11 - Exportar Tarefa pela Prioridade e Categoria.\n0 - Sair.\n");
        printf("Digite a operacao que deseja realizar: ");
        scanf("%d", &opcao);
        getchar();
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
    free(tarefa);
}

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

void CriarTarefa(Tarefa Lista[]) {
    char tarefa[100];
    char descricao[300];
    int prioridade;
    char estado[15];
    char categoria[15];
    size_t len2;
    size_t len;
    printf("Digite sua tarefa: ");
    fgets(tarefa, sizeof(tarefa), stdin);
    printf("Digite aqui a descricao desta tarefa: ");
    fgets(descricao, sizeof(descricao), stdin);
    printf("Digite aqui a prioridade desta tarefa: ");
    scanf("%d", &prioridade);
    limpar();
    char est[15];
    char est2[15];
    char est3[15];
    int comp;
    int comp2;
    int comp3;
    sprintf(est, "Feito");
    sprintf(est2, "Fazendo");
    sprintf(est3, "Fazer");
    do {
        printf("Digite o estado dessa tarefa(Feito,Fazendo ou Fazer): ");
        fgets(estado, sizeof(estado), stdin);
        len = strlen(estado);
        if (estado[len - 1] == '\n') estado[--len] = 0;
        comp = strcmp(estado, est);
        comp2 = strcmp(estado, est2);
        comp3 = strcmp(estado, est3);
    } while (comp != 0 && comp2 != 0 && comp3 != 0);
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

void DeletarTarefa(Tarefa Lista[]) {
    printf("Aqui está sua lista!\n");
    ListarTarefas2(Lista);
    int del;
    printf("Qual tarefa deseja excluir: ");
    scanf("%d", &del);
    int pos = del - 1;
    Lista[pos].existe = 0;
    printf("Tarefa excluída com sucesso!\n");
}

void ListarTarefas(Tarefa Lista[]) {
    printf("\n--- LISTA DE TAREFAS ---\n");
    printf("\n");
    for (int i = 0; i < maxtarefas; i++) {
        if (Lista[i].existe == 1) {
            printf("Tarefa: %s", Lista[i].tarefa);
            printf("Descricao: %s", Lista[i].descricao);
            printf("Prioridade: %d\n", Lista[i].prioridade);
            printf("Estado: %s\n", Lista[i].estado);
            printf("Categoria: %s", Lista[i].categoria);
            printf("\n-----------------\n");
        }
    }
}

void Alterartarefa(Tarefa Lista[]) {
    char novatarefa[20];
    char novadescricao[100];
    int novaprioridade;
    char novoestado[15];
    int num;
    int alt;
    int opcao;
    ListarTarefas2(Lista);
    printf("Digite qual tarefa deseja alterar: ");
    scanf("%d", &alt);
    num = alt - 1;
    printf("1. A tarefa.\n");
    printf("2. A descricao.\n");
    printf("3. A prioridade.\n");
    printf("4. O estado.\n");
    printf("Digite o que deseja mudar: ");
    scanf("%d", &opcao);
    limpar();
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

void FiltrartarefaPrioridade(Tarefa Lista[]) {
    int pri;
    int contador = 0;
    printf("Digite a prioridade que deseja filtrar: ");
    scanf("%d", &pri);
    printf("\n");
    for (int i = 0; i < maxtarefas; i++) {
        if (Lista[i].prioridade == pri) {
            contador++;
          printf("\n-----------------\n");
          printf("Tarefa: %s", Lista[i].tarefa);
          printf("Descricao: %s", Lista[i].descricao);
          printf("Prioridade: %d\n", Lista[i].prioridade);
          printf("Estado: %s\n", Lista[i].estado);
          printf("Categoria: %s", Lista[i].categoria);
          printf("\n-----------------\n");
        }
    }
    if (contador == 0) {
        printf("Nao tem nenhuma tarefa com essa prioridade!\n");
    }
    printf("\n");
}

void FiltrartarefaEstado(Tarefa Lista[]) {
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
    for (int i = 0; i < maxtarefas; i++) {
        comp4 = strcmp(estado, Lista[i].estado);
        if (comp4 == 0) {
            contador++;
          printf("\n-----------------\n");
          printf("Tarefa: %s", Lista[i].tarefa);
          printf("Descricao: %s", Lista[i].descricao);
          printf("Prioridade: %d\n", Lista[i].prioridade);
          printf("Estado: %s\n", Lista[i].estado);
          printf("Categoria: %s", Lista[i].categoria);
          printf("\n-----------------\n");
        }
    }
    if (contador == 0) {
        printf("Nao tem nenhuma tarefa com esse estado!\n");
    }
    printf("\n");
}

void FiltrarTarefaCategoria(Tarefa Lista[]) {
    char categoria[15];
    int contador = 0;
    printf("Digite a categoria que deseja filtrar: ");
    fgets(categoria, sizeof(categoria), stdin);
    size_t len = strlen(categoria);
    if (categoria[len - 1] == '\n') categoria[--len] = 0;

    printf("\n--- TAREFAS FILTRADAS POR CATEGORIA E ORDENADAS POR PRIORIDADE ---\n");


    for (int i = 0; i < maxtarefas; i++) {
        if (Lista[i].existe == 1 && strcmp(Lista[i].categoria, categoria) == 0) {
            contador++;
            printf("\n-----------------\n");
            printf("Tarefa: %s", Lista[i].tarefa);
            printf("Descricao: %s", Lista[i].descricao);
            printf("Prioridade: %d\n", Lista[i].prioridade);
            printf("Estado: %s\n", Lista[i].estado);
            printf("Categoria: %s", Lista[i].categoria);
            printf("\n-----------------\n");
        }
    }

    if (contador == 0) {
        printf("Nao tem nenhuma tarefa com essa categoria!\n");
    }
}

void FiltrarTarefasPorPrioridadeECategoria(Tarefa Lista[]) {
    char categoria[15];
    int prioridade;

    printf("Digite a categoria que deseja filtrar: ");
    fgets(categoria, sizeof(categoria), stdin);
    categoria[strcspn(categoria, "\n")] = '\0';  

    printf("Digite a prioridade que deseja filtrar: ");
    scanf("%d", &prioridade);
    while (getchar() != '\n'); 

    int contador = 0;

    printf("\n--- TAREFAS FILTRADAS POR PRIORIDADE E CATEGORIA ---\n");

    for (int i = 0; i < maxtarefas; i++) {
        if (Lista[i].existe == 1 && strcmp(Lista[i].categoria, categoria) == 0 &&
            Lista[i].prioridade == prioridade) {
            contador++;
            printf("\n-----------------\n");
            printf("Tarefa: %s", Lista[i].tarefa);
            printf("Descricao: %s", Lista[i].descricao);
            printf("Prioridade: %d\n", Lista[i].prioridade);
            printf("Estado: %s\n", Lista[i].estado);
            printf("Categoria: %s", Lista[i].categoria);
            printf("\n-----------------\n");
        }
    }

    if (contador == 0) {
        printf("Nao tem nenhuma tarefa com essa categoria e prioridade!\n");
    }
}

void ExportarPorPrioridade(Tarefa Lista[]) {
    int prioridade;

    printf("Digite a prioridade para exportar as tarefas: ");
    scanf("%d", &prioridade);
    while (getchar() != '\n'); 

  char arqpri[] = "aqrpri.txt";
       arqpri[strcspn( arqpri, "\n")] = '\0';  

    FILE *arquivo = fopen(arqpri, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    printf("\n--- TAREFAS EXPORTADAS POR PRIORIDADE ---\n");

  for (int i = 0; i < maxtarefas; i++) {
      if (Lista[i].existe == 1 && Lista[i].prioridade == prioridade) {
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

void ExportarPorCategoria(Tarefa Lista[]) {
    char categoria[15];

    printf("Digite a categoria para exportar as tarefas: ");
    fgets(categoria, sizeof(categoria), stdin);
    categoria[strcspn(categoria, "\n")] = '\0';  

    char aqrcat[] = "aqrcat.txt";  

    FILE *arquivo = fopen(aqrcat, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    printf("\n--- TAREFAS EXPORTADAS POR CATEGORIA  ---\n");


    for (int i = 0; i < maxtarefas - 1; i++) {
        for (int j = i + 1; j < maxtarefas; j++) {
            if (Lista[j].existe == 1 && Lista[i].existe == 1 && Lista[j].prioridade > Lista[i].prioridade) {

                Tarefa temp = Lista[i];
                Lista[i] = Lista[j];
                Lista[j] = temp;
            }
        }
    }

  for (int i = 0; i < maxtarefas; i++) {
      if (Lista[i].existe == 1 && strcmp(Lista[i].categoria, categoria) == 0) {
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

void ExportarPorPrioridadeCategoria(Tarefa Lista[]) {
    char categoria[15];

    printf("Digite a categoria para exportar as tarefas: ");
    fgets(categoria, sizeof(categoria), stdin);
    categoria[strcspn(categoria, "\n")] = '\0';  

    int prioridade;

    printf("Digite a prioridade para exportar as tarefas: ");
    scanf("%d", &prioridade);
    while (getchar() != '\n');  

    char NomeArq[] = "aqrpricat.txt";  

    FILE *arquivo = fopen(NomeArq, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    printf("\n--- TAREFAS EXPORTADAS POR PRIORIDADE E CATEGORIA ---\n");


    for (int i = 0; i < maxtarefas - 1; i++) {
        for (int j = i + 1; j < maxtarefas; j++) {
            if (Lista[j].existe == 1 && Lista[i].existe == 1 && Lista[j].prioridade > Lista[i].prioridade) {

                Tarefa temp = Lista[i];
                Lista[i] = Lista[j];
                Lista[j] = temp;
            }
        }
    }

  for (int i = 0; i < maxtarefas; i++) {
      if (Lista[i].existe == 1 && strcmp(Lista[i].categoria, categoria) == 0 && Lista[i].prioridade == prioridade) {
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

int criararquivo(Tarefa Lista[]) {
    FILE *arqtarefas = fopen("arqtarefas", "wb");
    if (arqtarefas == NULL) {
        return 1;
    }
    fwrite(Lista, sizeof(Tarefa), maxtarefas, arqtarefas);
    fclose(arqtarefas);
    return 0;
}
int lerarquivo(Tarefa Lista[]) {
    FILE *arqtarefas = fopen("arqtarefas", "rb");
    if (arqtarefas == NULL) {
        return 1;
    }
    fread(Lista, sizeof(Tarefa), maxtarefas, arqtarefas);
    fclose(arqtarefas);
    return 0;
}