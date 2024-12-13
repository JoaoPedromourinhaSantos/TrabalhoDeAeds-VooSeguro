//INTEGRANTES!!!!!!!!!!!!!!!!!!!!!
//JOÃO PEDRO MOURA SANTOS E MATHEUS FUSCALDI GOMES
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>


#define MAX_PASSAGEIROS 100
#define MAX_TRIPULACAO 50
#define MAX_VOOS 50
#define MAX_ASSENTOS 200
#define MAX_RESERVAS 500


// Estruturas
typedef struct {
    int codigo;
    char nome[100];
    char endereco[200];
    char telefone[15];
    int fidelidade; // 1 para sim, 0 para não
    int pontosFidelidade;
} Passageiro;

typedef struct {
    int codigo;
    char nome[100];
    char telefone[15];
    char cargo[20];
} Tripulacao;

typedef struct {
    int numeroAssento;
    int codigoVoo;
    int ocupado; // 1 para ocupado, 0 para livre
} Assento;

typedef struct {
    int codigo;
    char data[11];
    char hora[6];
    char origem[50];
    char destino[50];
    int codigoAviao;
    int codigoPiloto;
    int codigoCopiloto;
    int codigoComissario;
    int status; // 1 para ativo, 0 para inativo
    float tarifa;
    Assento assentos[MAX_ASSENTOS];
    int totalAssentos;
} Voo;

typedef struct {
    int codigoVoo;
    int numeroAssento;
    int codigoPassageiro;
} Reserva;

// Variáveis globais
Passageiro passageiros[MAX_PASSAGEIROS];
int totalPassageiros = 0;

Tripulacao tripulacao[MAX_TRIPULACAO];
int totalTripulacao = 0;

Voo voos[MAX_VOOS];
int totalVoos = 0;

Reserva reservas[MAX_RESERVAS];
int totalReservas = 0;

// Funções auxiliares
int gerarCodigoUnico() {
    static int codigo = 1;
    return codigo++;
}

int buscarPassageiro(int codigo) {
    for (int i = 0; i < totalPassageiros; i++) {
        if (passageiros[i].codigo == codigo) return i;
    }
    return -1;
}

int buscarTripulacao(int codigo) {
    for (int i = 0; i < totalTripulacao; i++) {
        if (tripulacao[i].codigo == codigo) return i;
    }
    return -1;
}

int buscarVoo(int codigo) {
    for (int i = 0; i < totalVoos; i++) {
        if (voos[i].codigo == codigo) return i;
    }
    return -1;
}



int buscarReserva(int codigoVoo, int numeroAssento) {
    for (int i = 0; i < totalReservas; i++) {
        if (reservas[i].codigoVoo == codigoVoo && reservas[i].numeroAssento == numeroAssento) {
            return i;
        }
    }
    return -1;
}


//passageiros belo horizonte para rio de janeiro.
void cadastrarPassageiro();
//função menu inicial
void apresentacao();
void cadastrarTripulacao();
void cadastrarVoo();
void cadastrarAssentos();
void fazerReserva();
void cancelarReserva();
void buscarPassageirosOuTripulacao();
void listarVoosPassageiro();





int main() {




  int escolha;
  int voodesejado;


//chamando o menu de voos
      apresentacao();


printf("\n\n\n");



printf("-|--------------------------------------------------------------------|\n");
printf("-|               ------------------------------------                -|\n");
printf("-|                     EMPRESA AEREA VOO SEGURO                      -|\n");
printf("-|                                                                   -|\n");
printf("-|                             OPCOES                                -|\n");
printf("-|                                                                   -|\n");
printf("-|      (1) =           Cadastro de passageiro                       -|\n");
printf("-|                                                                   -|\n");
printf("-|      (2) =           Cadastrar tripulação                         -|\n");
printf("-|                                                                   -|\n");
printf("-|      (3) =           Cadastro de voo                              -|\n");
printf("-|                                                                   -|\n");
printf("-|      (4) =           Cadastrar assento                            -|\n");
printf("-|                                                                   -|\n");
printf("-|      (5) =           Reserva                                      -|\n");
printf("-|                                                                   -|\n");
printf("-|      (6) =           Baixa em Reserva                             -|\n");
printf("-|                                                                   -|\n");
printf("-|      (7) =           Pesquisa                                     -|\n");
printf("-|                                                                   -|\n");
printf("-|      (8) =           Programa fidelidade                          -|\n");
printf("-|                                                                   -|\n");
printf("-|                                                                   -|\n");
printf("-|                                                                   -|\n");
printf("-|                                                                   -|\n");
printf("-|                          (9) = SAIR                               -|\n");
printf("-|                   -----------------------------                   -|\n");
printf("-|                         DIGITE SUA OPCAO!                         -|\n");
printf("-|--------------------------------------------------------------------|\n");
printf("-|                __  _                                               |\n");
printf("-|                !! `/ |                                             |\n");
printf("-|                 !!__`!                                             |\n");
printf("-|                 / ,' `-.__________________                         |\n");
printf("-|                '-'!_____                LI`-.                      |\n");
printf("-|                   <____()-=O=O=O=O=O=[]====--)                     |\n");
printf("-|                     `.___ ,-----,_______...-'                      |\n");
printf("-|                          /    .'                                   |\n");
printf("-|                         /   .'                                     |\n");
printf("-|                        /  .'                                       |\n");
printf("-|                        `-'                                         |\n");
printf("-|--------------------------------------------------------------------|\n");

scanf("%d", &escolha);
printf("\n\n\n\n");


switch (escolha){

  case 1:
printf("-|--------------------------------------------------------------------|\n");
printf("-|               ------------------------------------                -|\n");
printf("-|                     EMPRESA AEREA VOO SEGURO                     -|\n");
printf("-|                                                                   -|\n");
printf("-|                      CADASTRO DE PASSAGEIRO                       -|\n");
printf("-|                                                                   -|\n");
printf("-|--------------------------------------------------------------------|\n");

    cadastrarPassageiro();

break;

  case 2:
printf("-|--------------------------------------------------------------------|\n");
printf("-|               ------------------------------------                -|\n");
printf("-|                    EMPRESA AEREA VOO SEGURO                      -|\n");
printf("-|                                                                   -|\n");
printf("-|                      CADASTRAR TRIPULACAO                         -|\n");
printf("-|                                                                   -|\n");
printf("-|                                                                   -|\n");
printf("-|--------------------------------------------------------------------|\n");

    cadastrarTripulacao();

  break;

  case 3:

printf("-|--------------------------------------------------------------------|\n");
printf("-|               ------------------------------------                -|\n");
printf("-|                    EMPRESA AEREA VOO SEGURO                      -|\n");
printf("-|                                                                   -|\n");
printf("-|                          CADASTRAR VOO                            -|\n");
printf("-|                                                                   -|\n");
printf("-|                                                                   -|\n");
printf("-|--------------------------------------------------------------------|\n");

      cadastrarVoo();

  break;

  case 4:

printf("-|--------------------------------------------------------------------|\n");
printf("-|               ------------------------------------                -|\n");
printf("-|                     EMPRESA AEREA VOO SEGURO                      -|\n");
printf("-|                                                                   -|\n");
printf("-|                       CADASTRAR ASSENTOS                          -|\n");
printf("-|                                                                   -|\n");
printf("-|                                                                   -|\n");
printf("-|--------------------------------------------------------------------|\n");

      cadastrarAssentos();

break;

  case 5:
printf("-|--------------------------------------------------------------------|\n");
printf("-|               ------------------------------------                -|\n");
printf("-|                    EMPRESA AEREA VOO SEGURO                     -|\n");
printf("-|                                                                   -|\n");
printf("-|                          FAZER RESERVA                            -|\n");
printf("-|                                                                   -|\n");
printf("-|                                                                   -|\n");
printf("-|--------------------------------------------------------------------|\n");

    fazerReserva();

  case 6:
printf("-|--------------------------------------------------------------------|\n");
printf("-|               ------------------------------------                -|\n");
printf("-|                     EMPRESA AEREA VOO SEGURO                      -|\n");
printf("-|                                                                   -|\n");
printf("-|                        DAR BAIXA EM RESERVA                       -|\n");
printf("-|                          FILA DE ESPERA                           -|\n");
printf("-|--------------------------------------------------------------------|\n");

      cancelarReserva();

  break;

    case 7:

printf("-|--------------------------------------------------------------------|\n");
printf("-|               ------------------------------------                -|\n");
printf("-|                    EMPRESA AEREA VOO SEGURO                     -|\n");
printf("-|                                                                   -|\n");
printf("-|                        PESQUISAR PASSAGEIRO                       -|\n");
printf("-|                          FILA DE ESPERA                           -|\n");
printf("-|--------------------------------------------------------------------|\n");


        buscarPassageirosOuTripulacao();
    break;



    case 8:
printf("-|--------------------------------------------------------------------|\n");
printf("-|               ------------------------------------                -|\n");
printf("-|                     EMPRESA AEREA VOO SEGURO                      -|\n");
printf("-|                                                                   -|\n");
printf("-|                        LISTAR VOOS DO PASSAGEIRO                  -|\n");
printf("-|                          FILA DE ESPERA                           -|\n");
printf("-|--------------------------------------------------------------------|\n");


        listarVoosPassageiro();

    break;


  case 9:
printf("-|--------------------------------------------------------------------|\n");
printf("-|               ------------------------------------                -|\n");
printf("-|                     EMPRESA AEREA VOO SEGURO                    -|\n");
printf("-|                                                                   -|\n");
printf("-|                                                                   -|\n");
printf("-|                     AGRADEÇEMOS A PREFERENCIA                     -|\n");
printf("-|                                                                   -|\n");
printf("-|                                                                   -|\n");
printf("-|--------------------------------------------------------------------|\n");

    printf("\n\n\n");
    main();

  break;
}

    main();


  return 0;
}









//funções
void apresentacao (){
printf("-|--------------------------------------------------------|\n");
printf("-|            ------------------------------              |\n");
printf("-|               EMPRESA AEREA VOO SEGURO               -|\n");
printf("-|                                                       -|\n");
printf("-|            ------------------------------             -|\n");
printf("-|                   TENHA UM BOM VOO                    -|\n");
printf("-|--------------------------------------------------------|\n");

};


//ler passageiros voo de bh para rio de janeiro
void cadastrarPassageiro() {
    if (totalPassageiros >= MAX_PASSAGEIROS) {
        printf("Limite de passageiros atingido!\n");
        return;
    }

    Passageiro p;
    p.codigo = gerarCodigoUnico();
    printf("Digite o nome do passageiro: ");
    scanf(" %[^\n]", p.nome);
    printf("Digite o endereco do passageiro: ");
    scanf(" %[^\n]", p.endereco);
    printf("Digite o telefone do passageiro: ");
    scanf(" %[^\n]", p.telefone);
    printf("O passageiro participa do programa de fidelidade? (1 para sim, 0 para nao): ");
    scanf("%d", &p.fidelidade);

    if (p.fidelidade) {
        p.pontosFidelidade = 0;
    } else {
        p.pontosFidelidade = -1; // Indica que o passageiro não participa do programa
    }

    passageiros[totalPassageiros++] = p;
    printf("Passageiro cadastrado com sucesso! Codigo: %d\n", p.codigo);


}



void cadastrarTripulacao() {
    Tripulacao t;
    t.codigo = gerarCodigoUnico();
    printf("Digite o nome do membro da tripulacao: ");
    scanf(" %[^\n]", t.nome);
    printf("Digite o telefone: ");
    scanf(" %[^\n]", t.telefone);
    printf("Digite o cargo (piloto/copiloto/comissario): ");
    scanf(" %[^\n]", t.cargo);

    tripulacao[totalTripulacao++] = t;
    printf("Tripulacao cadastrada com sucesso! Codigo: %d\n", t.codigo);

    printf("\n\n");
    main();

}


void cadastrarVoo() {
    Voo v;
    v.codigo = gerarCodigoUnico();

    // Entrada de dados do voo
    printf("Digite a data do voo (dd/mm/aaaa): ");
    scanf(" %[^\n]", v.data);
    printf("Digite a hora do voo (hh:mm): ");
    scanf(" %[^\n]", v.hora);
    printf("Digite a origem do voo: ");
    scanf(" %[^\n]", v.origem);
    printf("Digite o destino do voo: ");
    scanf(" %[^\n]", v.destino);
    printf("Digite o codigo do aviao: ");
    scanf("%d", &v.codigoAviao);
    printf("Digite a tarifa do voo: ");
    scanf("%f", &v.tarifa);

    // Entrada e validação da tripulação
    int piloto, copiloto, comissario;
    printf("Digite o codigo do piloto: ");
    scanf("%d", &piloto);
    if (buscarTripulacao(piloto) == -1) {
        printf("Erro: Piloto nao encontrado. Cadastro de voo cancelado.\n");
        return;
    }
    printf("Digite o codigo do copiloto: ");
    scanf("%d", &copiloto);
    if (buscarTripulacao(copiloto) == -1) {
        printf("Erro: Copiloto nao encontrado. Cadastro de voo cancelado.\n");
        return;
    }
    printf("Digite o codigo do comissario: ");
    scanf("%d", &comissario);
    if (buscarTripulacao(comissario) == -1) {
        printf("Erro: Comissario nao encontrado. Cadastro de voo cancelado.\n");
        return;
    }

    // Atribuindo a tripulação ao voo
    v.codigoPiloto = piloto;
    v.codigoCopiloto = copiloto;
    v.codigoComissario = comissario;

    // Verificação do status do voo
    v.status = 1; // Ativo
    if (piloto == -1 || copiloto == -1) {
        printf("Erro: Para ativar o voo, é necessário um piloto e um copiloto válidos.\n");
        v.status = 0; // Inativo
    }

    // Inicialização dos assentos
    printf("Digite o total de assentos no voo: ");
    scanf("%d", &v.totalAssentos);
    if (v.totalAssentos > MAX_ASSENTOS) {
        printf("Erro: Número máximo de assentos excedido (%d).\n", MAX_ASSENTOS);
        return;
    }
    for (int i = 0; i < v.totalAssentos; i++) {
        v.assentos[i].numeroAssento = i + 1;
        v.assentos[i].codigoVoo = v.codigo;
        v.assentos[i].ocupado = 0; // Livre
    }

    // Cadastro do voo
    voos[totalVoos++] = v;
    printf("Voo cadastrado com sucesso! Codigo: %d, Status: %s\n", v.codigo, v.status == 1 ? "Ativo" : "Inativo");
    main();
}




void cadastrarAssentos() {
    int codigoVoo;
    printf("Digite o codigo do voo: ");
    scanf("%d", &codigoVoo);

    int index = buscarVoo(codigoVoo);
    if (index == -1) {
        printf("Voo nao encontrado!\n");
        return;
    }

    printf("Digite o numero de assentos do voo: ");
    scanf("%d", &voos[index].totalAssentos);
    for (int i = 0; i < voos[index].totalAssentos; i++) {
        voos[index].assentos[i].numeroAssento = i + 1;
        voos[index].assentos[i].codigoVoo = codigoVoo;
        voos[index].assentos[i].ocupado = 0;
    }
    printf("Assentos cadastrados com sucesso!\n");
    main();
}







void fazerReserva() {
        int codigoVoo, numeroAssento, codigoPassageiro;

        // Solicita o código do voo
        printf("Digite o codigo do voo: ");
        scanf("%d", &codigoVoo);

        int vooIndex = buscarVoo(codigoVoo);
        if (vooIndex == -1 || voos[vooIndex].status == 0) {
            printf("Erro: Voo nao encontrado ou inativo!\n");
            return;
        }

        // Solicita o número do assento
        printf("Digite o numero do assento: ");
        scanf("%d", &numeroAssento);

        if (numeroAssento < 1 || numeroAssento > voos[vooIndex].totalAssentos ||
            voos[vooIndex].assentos[numeroAssento - 1].ocupado) {
            printf("Erro: Assento invalido ou ja ocupado!\n");
            return;
        }

        // Solicita o código do passageiro
        printf("Digite o codigo do passageiro: ");
        scanf("%d", &codigoPassageiro);

        int passageiroIndex = buscarPassageiro(codigoPassageiro);
        if (passageiroIndex == -1) {
            printf("Erro: Passageiro nao encontrado!\n");
            return;
        }

        // Verifica se já existe reserva para o assento no mesmo voo
        if (buscarReserva(codigoVoo, numeroAssento) != -1) {
            printf("Erro: Reserva ja existe para este assento no voo informado!\n");
            return;
        }

        // Realiza a reserva
        Reserva r = {codigoVoo, numeroAssento, codigoPassageiro};
        reservas[totalReservas++] = r;
        voos[vooIndex].assentos[numeroAssento - 1].ocupado = 1;

        // Atualiza pontos de fidelidade se aplicável
        if (passageiros[passageiroIndex].fidelidade) {
            passageiros[passageiroIndex].pontosFidelidade += 10;
        }

        printf("Reserva realizada com sucesso! Assento %d reservado para o passageiro de codigo %d no voo %d.\n",numeroAssento, codigoPassageiro, codigoVoo);
    main();
}



void cancelarReserva() {
    int codigoVoo, numeroAssento;
    printf("Digite o codigo do voo: ");
    scanf("%d", &codigoVoo);
    printf("Digite o numero do assento: ");
    scanf("%d", &numeroAssento);

    int reservaIndex = buscarReserva(codigoVoo, numeroAssento);
    if (reservaIndex == -1) {
        printf("Reserva nao encontrada!\n");
        main();
    }

    int vooIndex = buscarVoo(codigoVoo);
    voos[vooIndex].assentos[numeroAssento - 1].ocupado = 0;
    printf("Reserva cancelada com sucesso!\n");
    reservas[reservaIndex] = reservas[--totalReservas];
    main();
}

void buscarPassageirosOuTripulacao() {
    char nome[100];
    printf("Digite o nome para busca: ");
    scanf(" %[^\n]", nome);

    printf("--- Passageiros ---\n");
    for (int i = 0; i < totalPassageiros; i++) {
        if (strstr(passageiros[i].nome, nome)) {
            printf("Codigo: %d, Nome: %s\n", passageiros[i].codigo, passageiros[i].nome);
        }
    }

    printf("--- Tripulacao ---\n");
    for (int i = 0; i < totalTripulacao; i++) {
        if (strstr(tripulacao[i].nome, nome)) {
            printf("Codigo: %d, Nome: %s, Cargo: %s\n", tripulacao[i].codigo, tripulacao[i].nome, tripulacao[i].cargo);
        }
    }

    main();
}



void listarVoosPassageiro() {
    int codigoPassageiro;
    printf("Digite o codigo do passageiro: ");
    scanf("%d", &codigoPassageiro);

    printf("--- Voos do Passageiro ---\n");
    for (int i = 0; i < totalReservas; i++) {
        if (reservas[i].codigoPassageiro == codigoPassageiro) {
            int vooIndex = buscarVoo(reservas[i].codigoVoo);
            printf("Voo: %d, Data: %s, Hora: %s, Origem: %s, Destino: %s\n",
                   voos[vooIndex].codigo, voos[vooIndex].data, voos[vooIndex].hora,
                   voos[vooIndex].origem, voos[vooIndex].destino);
        }
    }
    main();
}












