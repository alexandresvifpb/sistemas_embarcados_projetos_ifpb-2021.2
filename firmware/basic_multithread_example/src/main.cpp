#include <Arduino.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <esp_task_wdt.h>

// referencia da tarefa
TaskHandle_t TaskIDTarefa1;
TaskHandle_t TaskIDTarefa2;
TaskHandle_t TaskIDTarefa3;

// funcoes que implementam as tarefas
void TaskTarefa1 (void * pvParameters);
void TaskTarefa2 (void * pvParameters);
void TaskTarefa3 (void * pvParameters);

void setup() {

  // cria a tarefa (task) 1 com uma pilha 2048 palavras, prioridade 0 no nucleo 0
  xTaskCreatePinnedToCore(
    TaskTarefa1,            // funcao que implementa a tarefa
    "TaskTarefa1",          // nome da tarefa
    1024,                   // tamanho (em palavras) da pilha alocada para a tarefa
    NULL,                   // paramentros de entrada para a funcao que implementa a tarefa
    0,                      // prioridade da tarefa (quanto menor maior a prioridade)
    &TaskIDTarefa1,         // referencia da tarefa (para acompanhamento)
    PRO_CPU_NUM             // defini o nucleo (core) que ira executar a tarefa (PRO_CPU_NUM = 0)
  );
  delay(500);               // tempo de atraso para que a tarefa seja criada
  
  // cria a tarefa (task) 2 com uma pilha 1024 palavras, prioridade 2 no nucleo 1
  xTaskCreatePinnedToCore(
    TaskTarefa2,            // funcao que implementa a tarefa
    "TaskTarefa2",          // nome da tarefa
    2048,                   // tamanho (em palavras) da pilha alocada para a tarefa
    NULL,                   // paramentros de entrada para a funcao que implementa a tarefa
    2,                      // prioridade da tarefa (quanto menor maior a prioridade)
    &TaskIDTarefa2,         // referencia da tarefa (para acompanhamento)
    APP_CPU_NUM             // defini o nucleo (core) que ira executar a tarefa (APP_CPU_NUM = 1)
  );
  delay(500);               // tempo de atraso para que a tarefa seja criada
  
  // cria a tarefa (task) 3 com uma pilha 4096 palavras, prioridade 5 no nucleo escolhido pelo
  // escalonador do freertos
  xTaskCreatePinnedToCore(
    TaskTarefa3,            // funcao que implementa a tarefa
    "TaskTarefa3",          // nome da tarefa
    4096,                   // tamanho (em palavras) da pilha alocada para a tarefa
    NULL,                   // paramentros de entrada para a funcao que implementa a tarefa
    5,                      // prioridade da tarefa (quanto menor maior a prioridade)
    &TaskIDTarefa3,         // referencia da tarefa (para acompanhamento)
    tskNO_AFFINITY          // defini o nucleo que ira executar a tarefa (tskNO_AFFINITY = qualquer)
  );
  delay(500);               // tempo de atraso para que a tarefa seja criada

  // inicializa o watchdog dedicado para monitorar indivudalmente as tarefas
  // e garantir que todas nao trave
  esp_task_wdt_init(60, true);
}

void loop() {
  // quando estiver usando multithread evite usar a funcao principal loop()
  // pois ela sempre usa o nucleo de aplicacao 1 (APP_CPU_NUM = 1)
}

// implementacao da tarefa 1
void TaskTarefa1 (void * pvParameters)
{
  // configurcao dos recursos que a tarefa ira utilizar

  // loop infinito que implementa a tarefa
  for ( ;; )
  {
    /* code */
  }
  
}

// implementacao da tarefa 2
void TaskTarefa2 (void * pvParameters)
{
  // configurcao dos recursos que a tarefa ira utilizar

  // loop infinito que implementa a tarefa
  for ( ;; )
  {
    /* code */
  }
  
}

// implementacao da tarefa 3
void TaskTarefa3 (void * pvParameters)
{
  // configurcao dos recursos que a tarefa ira utilizar

  // loop infinito que implementa a tarefa
  for ( ;; )
  {
    /* code */
  }
  
}