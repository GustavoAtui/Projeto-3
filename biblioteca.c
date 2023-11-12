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