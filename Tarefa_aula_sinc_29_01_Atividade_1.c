#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include <stdio.h>

// Definição dos pinos para cada LED
#define LED_VERMELHO  11
#define LED_AMARELO   12
#define LED_VERDE     13

volatile uint8_t estado = 0;

 //Função de callback do timer repetitivo. A cada 3 segundos, esta função é chamada para alternar o estado do semáforo.
// Na primeira chamada, o LED vermelho já está ligado, então a função desliga o vermelho e liga o amarelo.
bool repeating_timer_callback(struct repeating_timer *t) {
    if (estado == 0) {
        // Estado 0: Vermelho está ligado; na transição, desliga o vermelho e liga o amarelo
        gpio_put(LED_VERMELHO, false);
        gpio_put(LED_AMARELO, true);
        gpio_put(LED_VERDE, false);
        estado = 1;
    } else if (estado == 1) {
        // Estado 1: Amarelo está ligado; na transição, desliga o amarelo e liga o verde
        gpio_put(LED_VERMELHO, false);
        gpio_put(LED_AMARELO, false);
        gpio_put(LED_VERDE, true);
        estado = 2;
    } else if (estado == 2) {
        // Estado 2: Verde está ligado; na transição, desliga o verde e liga o vermelho
        gpio_put(LED_VERMELHO, true);
        gpio_put(LED_AMARELO, false);
        gpio_put(LED_VERDE, false);
        estado = 0;
    }
    // Retorna true para manter o timer ativo
    return true;
}

int main(void) {
    // Inicializa a biblioteca padrão (GPIO, timers, etc.)
    stdio_init_all();

    // Inicializa os pinos dos LEDs e configura-os como saída
    gpio_init(LED_VERMELHO);
    gpio_set_dir(LED_VERMELHO, GPIO_OUT);

    gpio_init(LED_AMARELO);
    gpio_set_dir(LED_AMARELO, GPIO_OUT);

    gpio_init(LED_VERDE);
    gpio_set_dir(LED_VERDE, GPIO_OUT);

    // Estado inicial: somente o LED vermelho ligado
    gpio_put(LED_VERMELHO, true);
    gpio_put(LED_AMARELO, false);
    gpio_put(LED_VERDE, false);

    // Configura um timer repetitivo com intervalo de 3000 milissegundos (3 segundos)
    struct repeating_timer temporizador;
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &temporizador);

    // Loop principal: imprime uma mensagem a cada segundo
    while (true) {
        printf("Sistema funcionando...\n");
        sleep_ms(1000);
    }

    return 0;
}
