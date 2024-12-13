# Trabalho De Aeds e Fundamentos de Engenharia de Software - VooSeguro
A Voo Seguro é uma companhia aérea fictícia que visa garantir a satisfação de seus passageiros e promover sua fidelização. Ela opera em vários aeroportos pelo Brasil e conta com uma equipe de tripulação composta por pilotos, copilotos e comissários.

* **Instituição**: Pontifícia Universidade Católica de Minas Gerais.
* **Campus**: Coração Eucaristíco.
* **Alunos**: João Pedro Moura Santos e Matheus Fuscaldi Gomes Santos.
* **Professores**: Carlos Ribas e José Laerte Xavier.
* **Data**: 2° Semestre de 2024.

* **LINK DO VÍDEO DE APRESENTAÇÃO:** https://youtu.be/30m3-z6MxBY

# Proposta
A proposta deste trabalho é aplicar nossos conhecimentos de Análise e Estrutura de Dados e sua lógica de programação e mesclar com nossos conhecimentos gerais adquiridos nos conteúdos que foram aplicados e absorvidos na matéria de Fundamentos de Engenharia de Software.
# Objetivo
* **Nosso objetivo principal é implementar as seguintes funções:**
 Cadastro de Passageiros, cadastro de voo, cadastro de tripulação. cadastro de assento, função de reserva, função de baixa em reserva, função de pesquisa e função de programa de fidelidade.

* **Nossos objetivos especificos e secundários são:**
Definir a assinatura dos módulos (procedimentos e funções) e documentar seus parâmetros; 
Documentar o módulo (procedimento ou função) indicando seu propósito, parâmetros de entrada e saída;
Implementar o caso de sucesso do módulo (procedimento ou função);
Selecionar casos de teste para verificar o funcionamento de cada módulo;
Executar os casos de teste planejados para o módulo;
Criar um relatório de execução de testes que contenha os casos de teste;
Implementar os casos especiais; A evolução do backlog do produto a cada semana; Documentação das funcionalidades do software.


## Funcionalidades a serem Implementadas

 - **Cadastro de Passageiro:** - Garante que não haja dois passageiros com o mesmo
código.
 - **Cadastro de Tripulação:** - Cada membro deve possuir um cargo específico. - Garantia
de unicidade de código para membros da tripulação. 
-  **Cadastro de Voo:** - Informações sobre data, hora, origem, destino, tarifa, tripulação e
avião. - Validação da presença de piloto e copiloto para ativação do voo.
- **Cadastro de Assento:** - Registro de assentos para cada voo.
- **Reserva:** - Verificação da disponibilidade de assento antes de reservar. - Prevenção
de reservas duplicadas para o mesmo assento no mesmo voo.
- **Baixa em Reserva:** - Liberação do assento e atualização do status para livre. - Cálculo
do valor total, conforme tarifa do voo.
- **Pesquisa:** - Busca de passageiros e tripulação por nome ou código. - Listagem de
todos os voos de um passageiro.
- **Programa de Fidelidade:** - Cada voo concede 10 pontos ao passageiro. - Acumulação
de pontos ao longo de múltiplos voos.


## Metodologia:

O desenvolvimento segue a metodologia Scrum, com organização do backlog do
produto e alocação de tarefas em sprints de 3 a 4 dias. Cada funcionalidade é
responsabilidade de um membro do grupo, garantindo divisão eficiente do trabalho e
controle da evolução do projeto.

## Regras de Negócio

- Limite máximo de **500 reservas período**.
-  Limite máximo de **50 cadastro tripulação**.
- Limite máximo de **50 voos regisrados**.
- Limite máximo de **200 acentos disponíveis p/voo**.
- Limite máximo de **100 passageiros cadastrados**.
- Validação de **telefones** (9 a 12 dígitos) e **datas** (formato DD/MM/AAAA).  


---

## Arquitetura do Sistema

### Estrutura de Arquivos
- **src/main.c**: Código principal do sistema.
- **docs/**: Documentação detalhada do projeto.
- **data/**: Contém arquivos de exemplo com dados de clientes e funcionários.

---

## Planejamento e Sprints

| Sprint | Atividades Realizadas                                      | Datas                |
|--------|------------------------------------------------------------|----------------------|
| 1      | Definição da estrutura básica do sistema (Matheus) e desenvolvimento dos cadastros de passageiro (João), tripulação (João), voo (Matheus) e assento (João) | 26/11/2024 a 29/11/2024 |
| 2      | Implementação do sistema de pontos de fidelidade ( Matheus), sistema de reserva e baixa em reserva (João) | 30/11/2024 a 04/12/2024 |
| 3      | Implementação do sistema de Pesquisa (João) + reparação (João)          | 05/12/2024 a 10/12/2024 |
| 4      | Testes automatizados e ajustes finais no sistema. (Matheus)         | 11/12/2024 a 13/12/2024 |

---

## Links Importantes

| Repositório no GitHub               |   https://github.com/matheusfgs/TrabalhoDeAeds-VooSeguro.git               |
|-------------------------------------|---------------------------------------------------------------------------|

| Vídeo de apresentação no YouTube    |    https://youtu.be/30m3-z6MxBY                        |

---

## Casos de Teste

| ID | Funcionalidade            | Entrada                      | Saída Esperada                   | Resultado |
|----|---------------------------|------------------------------|-----------------------------------|-----------|
| 1  | Cadastro de Clientes      | Nome, Endereço, Telefone          | Cliente cadastrado com sucesso    | Aprovado  |
| 2  | Cadastro de Tripulação  | Nome, Telefone, Cargo        | Membro cadastrado com sucesso       | Aprovado  |
| 3  | Cadastro de Voo      | data, hora, origem, destino, tarifa, tripulação e avião. | Voo registrado com sucesso  | Aprovado  |
| 4  | Cadastro de Assento     | voo, numero de assentos | Assento cadastrado com sucesso     | Aprovado  |
| 5  | Reserva      | Nome, codigo do cliente, codigo do voo                  | Reserva feito com sucesso         | Aprovado  |
| 6  | Baixa em Reserva       | Nome, codigo do cliente, codigo do voo              | Baixa feita com sucesso             | Aprovado  |
| 7 |  Pesquisa      |Código                | Cliente/Tripulação/Voo encontrado             | Aprovado  |
| 8  | Programa de Fidelidade      | Nome, codigo do cliente              | Cliente encontrado, pontuação X             | Aprovado  |

---


## Conclusão

O sistema planejado visa atender integralmente às necessidades propostas,
garantindo um fluxo funcional eficiente para o gerenciamento de voos. A utilização de
Scrum possibilita adaptação e melhoria contínua ao longo do desenvolvimento.

## Principais Trechos de Código

### Cadastro da Tripulação

```c
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
    
### Entrada de Dados do Voo

 ```c
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







---
