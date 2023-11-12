#ifndef CLIONPROJECTS_BIBLIOTECA_H
#define CLIONPROJECTS_BIBLIOTECA_H

#define maxtarefas 100

typedef struct {
    char tarefa[100];
    char descricao[300];
    int prioridade;
    int pos;
    char estado[20];
    char categoria[15];
    int existe;
} Tarefa;

void Menu(Tarefa Lista[]);
void ListarTarefas2(Tarefa Lista[]);
void CriarTarefa(Tarefa Lista[]);
void DeletarTarefa(Tarefa Lista[]);
void ListarTarefas(Tarefa Lista[]);
int criararquivo(Tarefa Lista[]);
int lerarquivo(Tarefa Lista[]);
void Alterartarefa(Tarefa Lista[]);
void FiltrartarefaPrioridade(Tarefa Lista[]);
void FiltrartarefaEstado(Tarefa Lista[]);
void FiltrarTarefaCategoria(Tarefa Lista[]);
void FiltrarTarefasPorPrioridadeECategoria(Tarefa Lista[]);
void ExportarPorPrioridade(Tarefa Lista[]);
void ExportarPorCategoria(Tarefa Lista[]);
void ExportarPorPrioridadeCategoria(Tarefa Lista[]);
void limpar();

#endif //CLIONPROJECTS_BIBLIOTECA_H