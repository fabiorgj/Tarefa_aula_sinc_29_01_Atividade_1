Embarcatech     

Tarefa da aula sincrona do dia 29/01/2025 - **ATIVIDADE 1**        

Aluno: **Fábio Rocha Gomes Jardim**     

Matrícula: **TIC370100723**     


# Semáforo com Raspberry Pi Pico W

Este projeto implementa um semáforo simples utilizando uma Raspberry Pi Pico W. O semáforo possui três LEDs (vermelho, amarelo e verde) que alternam seus estados a cada 3 segundos, simulando a lógica de um semáforo real. O código também imprime periodicamente uma mensagem no console para indicar que o sistema está em funcionamento. 

## Simulação no Wokwi

O projeto **integra o Wokwi ao VS Code** para fazer a simulação do circuito, todos os arquivos estão incluídos.

Caso queira ver a simulação através do wokwi web: [simulação no Wokwi web](https://wokwi.com/projects/421919387878016001)

Observação importante!: Na simulação do Wokwi o printf via terminal não funciona para o rp2040 com Cmake.

![Simulação no VS Code](https://github.com/fabiorgj/Tarefa_aula_sinc_29_01_Atividade_1/blob/main/simula%C3%A7%C3%A3o%20wokwi.gif)   

O código rodando na BitdogLab:

![Na bitdoglab](https://github.com/fabiorgj/Tarefa_aula_sinc_29_01_Atividade_1/blob/main/bitdoglab-atv1.gif)    

## Descrição
O código controla um semáforo com três LEDs:
- **Vermelho**: 3 segundos.
- **Amarelo**: 3 segundos (após o vermelho).
- **Verde**: 3 segundos (após o amarelo).

Um timer repetitivo gerencia as transições entre os estados. O sistema também imprime mensagens de status no console a cada segundo.

## Explicação do Código
### Definições e Variáveis
- **Pinos dos LEDs**: `LED_VERMELHO` (GPIO 11), `LED_AMARELO` (GPIO 12), `LED_VERDE` (GPIO 13).
- `estado`: Controla o estado atual do semáforo (0: vermelho, 1: amarelo, 2: verde).

### Função `repeating_timer_callback`
Alterna os estados do semáforo a cada 3 segundos:
1. **Estado 0**: Desliga vermelho, liga amarelo.
2. **Estado 1**: Desliga amarelo, liga verde.
3. **Estado 2**: Desliga verde, liga vermelho.

### Função `main`
1. Inicializa GPIOs e configura os LEDs como saída.
2. Define o estado inicial (vermelho ligado).
3. Configura um timer repetitivo de 3 segundos.
4. Loop principal exibe mensagens no console a cada 1 segundo.

## Componentes Necessários
- Raspberry Pi Pico W
- 1 LED Vermelho (GPIO 11)
- 1 LED Amarelo (GPIO 12)
- 1 LED Verde (GPIO 13)
- 3 Resistorres de 330Ω (para cada LED)

![imagem diagrama Wokwi](https://github.com/fabiorgj/Tarefa_aula_sinc_29_01_Atividade_1/blob/main/diagrama%20wokwi.png)
