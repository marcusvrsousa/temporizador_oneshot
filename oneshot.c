#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/timer.h"

// Definição dos pinos
#define LED_BLUE 11
#define LED_RED 12
#define LED_GREEN 13
#define BUTTON_PIN 5

#define DELAY_MS 3000  // Atraso de 3 segundos entre os estados dos LEDs

volatile bool sequence_running = false;  // Bloqueia novas ativações até o final da sequência

// Callback do timer: Desliga o LED azul, mantém os outros dois acesos
int64_t turn_off_blue(alarm_id_t id, void *user_data) {
    gpio_put(LED_BLUE, 0);
    return 0;
}

// Callback do timer: Desliga o LED vermelho, mantendo apenas o verde aceso
int64_t turn_off_red(alarm_id_t id, void *user_data) {
    gpio_put(LED_RED, 0);
    return 0;
}

// Callback do timer: Desliga o LED verde e libera o botão para nova ativação
int64_t turn_off_green(alarm_id_t id, void *user_data) {
    gpio_put(LED_GREEN, 0);
    sequence_running = false;  // Permite reiniciar a sequência
    return 0;
}

// Callback de interrupção do botão
void button_callback(uint gpio, uint32_t events) {
    if (sequence_running) return;  // Evita reativar durante a execução da sequência

    sequence_running = true;  // Bloqueia novas ativações

    // Liga todos os LEDs
    gpio_put(LED_BLUE, 1);
    gpio_put(LED_RED, 1);
    gpio_put(LED_GREEN, 1);

    // Configura temporizadores para desligar os LEDs progressivamente
    add_alarm_in_ms(DELAY_MS, turn_off_blue, NULL, false);
    add_alarm_in_ms(DELAY_MS * 2, turn_off_red, NULL, false);
    add_alarm_in_ms(DELAY_MS * 3, turn_off_green, NULL, false);
}

int main() {
    stdio_init_all();  // Inicializa comunicação serial

    // Configuração dos LEDs como saída
    gpio_init(LED_BLUE);
    gpio_set_dir(LED_BLUE, GPIO_OUT);
    gpio_put(LED_BLUE, 0);

    gpio_init(LED_RED);
    gpio_set_dir(LED_RED, GPIO_OUT);
    gpio_put(LED_RED, 0);

    gpio_init(LED_GREEN);
    gpio_set_dir(LED_GREEN, GPIO_OUT);
    gpio_put(LED_GREEN, 0);

    // Configuração do botão com pull-up interno
    gpio_init(BUTTON_PIN);
    gpio_set_dir(BUTTON_PIN, GPIO_IN);
    gpio_pull_up(BUTTON_PIN);

    // Configura interrupção para detectar o clique do botão
    gpio_set_irq_enabled_with_callback(BUTTON_PIN, GPIO_IRQ_EDGE_FALL, true, &button_callback);

    while (1) {
        tight_loop_contents();  // Mantém o código rodando
    }
}