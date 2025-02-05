# Temporizador de um Disparo (One Shot) 🚀
Esta atividade consiste na implementação de um temporizador utilizando a função add_alarm_in_ms() do Pico SDK, para controlar o acionamento de LEDs a partir do clique em um botão (pushbutton). O sistema será desenvolvido para o microcontrolador Raspberry Pi Pico W e simulado na plataforma Wokwi.

## Ambiente de Desenvolvimento

- Editor: VS Code

- Linguagem: C

- SDK: Pico SDK

- Simulador: Wokwi, integrado ao VS Code

## Funcionalidades Implementadas 🔧

Acionamento por Botão: O sistema é ativado somente quando o usuário pressiona o botão (pushbutton).

Sequência de LEDs:

Inicialmente, todos os LEDs (azul, vermelho e verde) são acesos simultaneamente.

Após 3 segundos, o LED azul é desligado.

Após 6 segundos, o LED vermelho é desligado.

Após 9 segundos, o LED verde é desligado, finalizando a sequência.

Controle de Reativação: O botão só pode ser pressionado novamente após a finalização da sequência de desligamento do último LED.

Interrupção GPIO: Utiliza um sistema de callback para capturar a interrupção do botão e iniciar o processo de temporização.

Temporização com Callbacks: Cada mudança de estado dos LEDs é gerenciada por funções de callback do temporizador add_alarm_in_ms(). ⏳

Simulação no Wokwi: O projeto pode ser testado no simulador Wokwi com LEDs RGB e um pushbutton.

## Componentes Utilizados 📌

- Microcontrolador: Raspberry Pi Pico W

- 🚦LEDs: LED Azul (conectado ao GPIO 11) / LED Vermelho (conectado ao GPIO 12) / LED Verde (conectado ao GPIO 13) 

- Resistores: 3 resistores de 330 Ω para limitar a corrente dos LEDs

- Botão (Pushbutton): Conectado ao GPIO 5 com pull-up interno ativado 🔘

## Ambiente de Desenvolvimento

- Linguagem: C

- SDK: Pico SDK

- IDE: VS Code

- Simulador: Wokwi (integrado ao VS Code)

## Como Utilizar 🛠️

Compile e carregue o código no Raspberry Pi Pico W.


## 6. Rodar no Simulador Wokwi 🔄

1️⃣ Acesse wokwi.com
2️⃣ Crie um novo projeto para Raspberry Pi Pico
3️⃣ Importe o arquivo oneshot.c e o diagram.json fornecido no repositório
4️⃣ Clique em "Start Simulation" para ver o código funcionando!
5️⃣ Pressione o botão conectado ao microcontrolador para iniciar a sequência de iluminação dos LEDs.
6️⃣ Observe os LEDs acenderem e apagarem conforme a temporização programada.
7️⃣ Aguarde o fim da sequência para pressionar o botão novamente.
