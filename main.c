//Leonardo Hideki Onohara Davanco 2020002131
//Projeto final de programacao embarcada

#include <pic18f4520.h>
#include "config.h"
#include "atraso.h"
#include "bits.h"
#include "lcd.h"
#include "keypad.h"
#include "lcd10.h"
#include "ssd.h"
#include "io.h"

void lcdPosition(unsigned char linha, unsigned char coluna) {
    if (linha == 0) {
        lcdCommand(0x80 + (coluna % 16));
    }
    if (linha == 1) {
        lcdCommand(0xC0 + (coluna % 16));
    }
    if (linha == 2) {
        lcdCommand(0x90 + (coluna % 16));
    }
    if (linha == 3) {
        lcdCommand(0xD0 + (coluna % 16));
    }
}

void ConfiguraLed() {
    TRISD = 0x00;
    PORTD = 0x00;
}

void LigarLed(char num) {
    unsigned char aux = PORTD;
    if (num == 0) {
        PORTD = aux | 0x01;
    }
    if (num == 1) {
        PORTD = aux | 0x02;
    }
    if (num == 2) {
        PORTD = aux | 0x04;
    }
    if (num == 3) {
        PORTD = aux | 0x08;
    }
    if (num == 4) {
        PORTD = aux | 0x10;
    }
    if (num == 5) {
        PORTD = aux | 0x20;
    }
    if (num == 6) {
        PORTD = aux | 0x40;
    }
    if (num == 7) {
        PORTD = aux | 0x80;
    }
}

void inicializa() {
    int i;
    char vetor[32] = {0x00, 0x01, 0x1F, 0x10, 0x14, 0x16, 0x15, 0x14,
        0x00, 0x10, 0x1F, 0x01, 0x05, 0x0D, 0x15, 0x05,
        0x14, 0x14, 0x14, 0x14, 0x14, 0x10, 0x10, 0x1F,
        0x05, 0x05, 0x05, 0x05, 0x05, 0x01, 0x01, 0x1F};

    char vetor1[32] = {0x03, 0x07, 0x01, 0x07, 0x08, 0x1F, 0x10, 0x1F,
        0x00, 0x00, 0x00, 0x1C, 0x02, 0x1F, 0x01, 0x1F,
        0x10, 0x1F, 0x08, 0x07, 0x00, 0x00, 0x00, 0x00,
        0x01, 0x1F, 0x02, 0x1C, 0x00, 0x00, 0x00, 0x00};

    lcdCommand(0x40);
    for (i = 0; i < 32; i++) lcdData(vetor1[i]);
    lcdPosition(0, 0);
    lcdData(0);
    lcdData(1);
    lcdPosition(1, 0);
    lcdData(2);
    lcdData(3);
    lcdCommand(0x60);
    for (i = 0; i < 32; i++) lcdData(vetor[i]);
    lcdPosition(0, 14);
    lcdData(4);
    lcdData(5);
    lcdPosition(1, 14);
    lcdData(6);
    lcdData(7);
    lcdPosition(0, 3);
    lcd_str("Bem  vindo");
    lcdPosition(1, 6);
    lcd_str("ao");
    lcdPosition(2, 3);
    lcd_str("McDonalds!");
    lcdPosition(3, 0);
    atraso_ms(3000);
    lcd_cmd(L_CLR);
    lcdPosition(0, 0);
    lcd_str("Primeiro, qual");
    lcdPosition(1, 0);
    lcd_str("lanche gostaria");
    lcdPosition(2, 0);
    lcd_str("de escolher?");
    atraso_ms(3000);
    lcd_cmd(L_CLR);
    lcdPosition(0, 0);
    lcd_str("2-BigMac R$20");
    lcdPosition(1, 0);
    lcd_str("5-McChicken R$18");
    lcdPosition(2, 0);
    lcd_str("8-McTasty R$24");
    lcdPosition(3,0);
    lcd_str("0-Cancelar");
}

void escolhaBebida() {
    lcd_str("Agora, escolha");
    lcdPosition(2, 0);
    lcd_str("a sua bebida.");
    atraso_ms(3000);
    lcd_cmd(L_CLR);
    lcdPosition(0, 0);
    lcd_str("2-CocaCola R$8");
    lcdPosition(1, 0);
    lcd_str("5-Pepsi R$7");
    lcdPosition(2, 0);
    lcd_str("8-Kuat R$6");
    lcdPosition(3, 0);
    lcd_str("0-Cancelar");
}

void cocaCola() {
    lcd_cmd(L_CLR);
    lcdPosition(0, 0);
    lcd_str("CocaCola? Legal");
    lcdPosition(1, 0);
    lcd_str("Agora, escolha");
    lcdPosition(2, 0);
    lcd_str("o seu");
    lcdPosition(3, 0);
    lcd_str("acompanhamento.");
    atraso_ms(3000);
    lcd_cmd(L_CLR);
    lcdPosition(0, 0);
    lcd_str("2-Batata R$6");
    lcdPosition(1, 0);
    lcd_str("5-Nuggets R$5");
    lcdPosition(2, 0);
    lcd_str("8-Salada R$4");
    lcdPosition(3, 0);
    lcd_str("0-Cancelar");
}

void pepsi() {
    lcd_cmd(L_CLR);
    lcdPosition(0, 0);
    lcd_str("Pepsi? Legal");
    lcdPosition(1, 0);
    lcd_str("Agora, escolha");
    lcdPosition(2, 0);
    lcd_str("o seu");
    lcdPosition(3, 0);
    lcd_str("acompanhamento.");
    atraso_ms(3000);
    lcd_cmd(L_CLR);
    lcdPosition(0, 0);
    lcd_str("2-Batata R$6");
    lcdPosition(1, 0);
    lcd_str("5-Nuggets R$5");
    lcdPosition(2, 0);
    lcd_str("8-Salada R$4");
    lcdPosition(3, 0);
    lcd_str("0-Cancelar");
}

void kuat() {
    lcd_cmd(L_CLR);
    lcdPosition(0, 0);
    lcd_str("Kuat? Legal");
    lcdPosition(1, 0);
    lcd_str("Agora, escolha");
    lcdPosition(2, 0);
    lcd_str("o seu");
    lcdPosition(3, 0);
    lcd_str("acompanhamento.");
    atraso_ms(3000);
    lcd_cmd(L_CLR);
    lcdPosition(0, 0);
    lcd_str("2-Batata R$6");
    lcdPosition(1, 0);
    lcd_str("5-Nuggets R$5");
    lcdPosition(2, 0);
    lcd_str("8-Salada R$4");
    lcdPosition(3, 0);
    lcd_str("0-Cancelar");
}

void calculaPedido() {
    int i;
    lcd_cmd(L_CLR);
    lcdPosition(0, 0);
    lcd_str("Certo.");
    lcdPosition(1, 0);
    lcd_str("Calculando o");
    lcdPosition(2, 0);
    lcd_str("pedido");
    lcdPosition(3, 0);
    lcd_str("aguarde...");
    ConfiguraLed();
    for (i = 0; i < 8; i++) {
        LigarLed(i);
        atraso_ms(700);
    }
    lcd_cmd(L_CLR);
}

void montandoPedido() {

    int i;
    digitalWrite(PIN_A2, LOW);
    digitalWrite(PIN_A3, LOW);
    digitalWrite(PIN_A4, LOW);
    digitalWrite(PIN_A5, LOW);
    atraso_ms(2000);
    lcd_cmd(L_CLR);
    lcdPosition(0, 0);
    lcd_str("Montando seu");
    lcdPosition(1, 0);
    lcd_str("pedido.");
    lcdPosition(2, 0);
    lcd_str("Aguarde...");
    bitSet(PORTC, 2);
    ConfiguraLed();
    atraso_ms(3000);
    for (i = 8; i > 0; i--) {
        LigarLed(i);
        atraso_ms(700);
    }
    bitClr(PORTC, 2);
    lcd_cmd(L_CLR);
    lcdPosition(0, 0);
    lcd_str("Pronto, retire");
    lcdPosition(1, 0);
    lcd_str("seu pedido no");
    lcdPosition(2, 0);
    lcd_str("balcao.");
    atraso_ms(3000);
    lcd_cmd(L_CLR);
    lcdPosition(0, 0);
    lcd_str("Agradecemos a");
    lcdPosition(1, 0);
    lcd_str("preferencia.");
    lcdPosition(2, 0);
    lcd_str("Volte sempre ao");
    lcdPosition(3, 0);
    lcd_str("McDonalds");
    atraso_ms(6000);
}

void cancela() {
    lcd_cmd(L_CLR);
    lcdPosition(0, 0);
    lcd_str("Cancelado.");
    lcdPosition(1, 0);
    lcd_str("Volte sempre!");
    atraso_ms(3500);
}

void main(void) {
    int i = 0;
    unsigned char botao = 16;

    lcdInit();
    kpInit();
    ssdInit();
    TRISC = 0x01;

    inicializa();
    for (;;) {
        kpDebounce();
        if (kpRead() != botao) {
            botao = kpRead();
            if (bitTst(botao, 7)) {
                lcd_cmd(L_CLR);
                lcdPosition(0, 0);
                lcd_str("BigMac? Otimo");
                lcdPosition(1, 0);
                escolhaBebida();
                for (;;) {
                    kpDebounce();
                    if (kpRead() != botao) {
                        botao = kpRead();
                        if (bitTst(botao, 7)) {
                            cocaCola();
                            for (;;) {
                                kpDebounce();
                                if (kpRead() != botao) {
                                    botao = kpRead();
                                    if (bitTst(botao, 7)) {
                                        calculaPedido();
                                        lcdPosition(0, 0);
                                        lcd_str("BigMac");
                                        lcdPosition(1, 0);
                                        lcd_str("CocaCola");
                                        lcdPosition(2, 0);
                                        lcd_str("Batata");
                                        lcdPosition(3, 0);
                                        lcd_str("Total: R$34");
                                        for (i = 0; i < 3000; i++) {
                                            ssdDigit(3, 0);
                                            ssdDigit(4, 1);
                                            ssdDigit(0, 2);
                                            ssdDigit(0, 3);
                                            ssdUpdate();
                                            atraso_ms(2);
                                        }
                                        montandoPedido();
                                        return;
                                    }
                                    if (bitTst(botao, 6)) {
                                        calculaPedido();
                                        lcdPosition(0, 0);
                                        lcd_str("BigMac");
                                        lcdPosition(1, 0);
                                        lcd_str("CocaCola");
                                        lcdPosition(2, 0);
                                        lcd_str("Nuggets");
                                        lcdPosition(3, 0);
                                        lcd_str("Total: R$33");
                                        for (i = 0; i < 1000; i++) {
                                            ssdDigit(3, 0);
                                            ssdDigit(3, 1);
                                            ssdDigit(0, 2);
                                            ssdDigit(0, 3);
                                            ssdUpdate();
                                            atraso_ms(2);
                                        }
                                        montandoPedido();
                                        return;
                                    }
                                    if (bitTst(botao, 5)) {
                                        calculaPedido();
                                        lcdPosition(0, 0);
                                        lcd_str("BigMac");
                                        lcdPosition(1, 0);
                                        lcd_str("CocaCola");
                                        lcdPosition(2, 0);
                                        lcd_str("Salada");
                                        lcdPosition(3, 0);
                                        lcd_str("Total: R$32");
                                        for (i = 0; i < 1000; i++) {
                                            ssdDigit(3, 0);
                                            ssdDigit(2, 1);
                                            ssdDigit(0, 2);
                                            ssdDigit(0, 3);
                                            ssdUpdate();
                                            atraso_ms(2);
                                        }
                                        montandoPedido();
                                        return;
                                    }
                                    if (bitTst(botao, 4)) {
                                        cancela();
                                        return;
                                    }
                                }
                            }
                        }
                    }
                    if (bitTst(botao, 6)) {
                        pepsi();
                        for (;;) {
                            kpDebounce();
                            if (kpRead() != botao) {
                                botao = kpRead();
                                if (bitTst(botao, 7)) {
                                    calculaPedido();
                                    lcdPosition(0, 0);
                                    lcd_str("BigMac");
                                    lcdPosition(1, 0);
                                    lcd_str("Pepsi");
                                    lcdPosition(2, 0);
                                    lcd_str("Batata");
                                    lcdPosition(3, 0);
                                    lcd_str("Total: R$33");
                                    for (i = 0; i < 1000; i++) {
                                        ssdDigit(3, 0);
                                        ssdDigit(2, 1);
                                        ssdDigit(0, 2);
                                        ssdDigit(0, 3);
                                        ssdUpdate();
                                        atraso_ms(2);
                                    }
                                    montandoPedido();
                                    return;
                                }
                                if (bitTst(botao, 6)) {
                                    calculaPedido();
                                    lcdPosition(0, 0);
                                    lcd_str("BigMac");
                                    lcdPosition(1, 0);
                                    lcd_str("Pepsi");
                                    lcdPosition(2, 0);
                                    lcd_str("Nuggets");
                                    lcdPosition(3, 0);
                                    lcd_str("Total: R$32");
                                    for (i = 0; i < 1000; i++) {
                                        ssdDigit(3, 0);
                                        ssdDigit(2, 1);
                                        ssdDigit(0, 2);
                                        ssdDigit(0, 3);
                                        ssdUpdate();
                                        atraso_ms(2);
                                    }
                                    montandoPedido();
                                    return;
                                }
                                if (bitTst(botao, 5)) {
                                    calculaPedido();
                                    lcdPosition(0, 0);
                                    lcd_str("BigMac");
                                    lcdPosition(1, 0);
                                    lcd_str("Pepsi");
                                    lcdPosition(2, 0);
                                    lcd_str("Salada");
                                    lcdPosition(3, 0);
                                    lcd_str("Total: R$31");
                                    for (i = 0; i < 1000; i++) {
                                        ssdDigit(3, 0);
                                        ssdDigit(1, 1);
                                        ssdDigit(0, 2);
                                        ssdDigit(0, 3);
                                        ssdUpdate();
                                        atraso_ms(2);
                                    }
                                    montandoPedido();
                                    return;
                                }
                                if (bitTst(botao, 4)) {
                                    cancela();
                                    return;
                                }
                            }
                        }
                    }
                    if (bitTst(botao, 5)) {
                        kuat();
                        for (;;) {
                            kpDebounce();
                            if (kpRead() != botao) {
                                botao = kpRead();
                                if (bitTst(botao, 7)) {
                                    calculaPedido();
                                    lcdPosition(0, 0);
                                    lcd_str("BigMac");
                                    lcdPosition(1, 0);
                                    lcd_str("Kuat");
                                    lcdPosition(2, 0);
                                    lcd_str("Batata");
                                    lcdPosition(3, 0);
                                    lcd_str("Total: R$32");
                                    for (i = 0; i < 1000; i++) {
                                        ssdDigit(3, 0);
                                        ssdDigit(2, 1);
                                        ssdDigit(0, 2);
                                        ssdDigit(0, 3);
                                        ssdUpdate();
                                        atraso_ms(2);
                                    }
                                    montandoPedido();
                                    return;
                                }
                                if (bitTst(botao, 6)) {
                                    calculaPedido();
                                    lcdPosition(0, 0);
                                    lcd_str("BigMac");
                                    lcdPosition(1, 0);
                                    lcd_str("Kuat");
                                    lcdPosition(2, 0);
                                    lcd_str("Nuggets");
                                    lcdPosition(3, 0);
                                    lcd_str("Total: R$31");
                                    for (i = 0; i < 1000; i++) {
                                        ssdDigit(3, 0);
                                        ssdDigit(1, 1);
                                        ssdDigit(0, 2);
                                        ssdDigit(0, 3);
                                        ssdUpdate();
                                        atraso_ms(2);
                                    }
                                    montandoPedido();
                                    return;
                                }
                                if (bitTst(botao, 5)) {
                                    calculaPedido();
                                    lcdPosition(0, 0);
                                    lcd_str("BigMac");
                                    lcdPosition(1, 0);
                                    lcd_str("Kuat");
                                    lcdPosition(2, 0);
                                    lcd_str("Salada");
                                    lcdPosition(3, 0);
                                    lcd_str("Total: R$30");
                                    for (i = 0; i < 1000; i++) {
                                        ssdDigit(3, 0);
                                        ssdDigit(0, 1);
                                        ssdDigit(0, 2);
                                        ssdDigit(0, 3);
                                        ssdUpdate();
                                        atraso_ms(2);
                                    }
                                    montandoPedido();
                                    return;
                                }
                                if (bitTst(botao, 4)) {
                                    cancela();
                                    return;
                                }
                            }
                        }
                    }
                    if (bitTst(botao, 4)) {
                        cancela();
                        return;
                    }
                }
            }
        }
        if (bitTst(botao, 6)) {
            lcd_cmd(L_CLR);
            lcdPosition(0, 0);
            lcd_str("McChicken? Otimo");
            lcdPosition(1, 0);
            escolhaBebida();
            for (;;) {
                kpDebounce();
                if (kpRead() != botao) {
                    botao = kpRead();
                    if (bitTst(botao, 7)) {
                        cocaCola();
                        for (;;) {
                            kpDebounce();
                            if (kpRead() != botao) {
                                botao = kpRead();
                                if (bitTst(botao, 7)) {
                                    calculaPedido();
                                    lcdPosition(0, 0);
                                    lcd_str("McChicken");
                                    lcdPosition(1, 0);
                                    lcd_str("CocaCola");
                                    lcdPosition(2, 0);
                                    lcd_str("Batata");
                                    lcdPosition(3, 0);
                                    lcd_str("Total: R$32");
                                    for (i = 0; i < 1000; i++) {
                                        ssdDigit(3, 0);
                                        ssdDigit(2, 1);
                                        ssdDigit(0, 2);
                                        ssdDigit(0, 3);
                                        ssdUpdate();
                                        atraso_ms(2);
                                    }
                                    montandoPedido();
                                    return;
                                }
                                if (bitTst(botao, 6)) {
                                    calculaPedido();
                                    lcdPosition(0, 0);
                                    lcd_str("McChicken");
                                    lcdPosition(1, 0);
                                    lcd_str("CocaCola");
                                    lcdPosition(2, 0);
                                    lcd_str("Nuggets");
                                    lcdPosition(3, 0);
                                    lcd_str("Total: R$31");
                                    for (i = 0; i < 1000; i++) {
                                        ssdDigit(3, 0);
                                        ssdDigit(1, 1);
                                        ssdDigit(0, 2);
                                        ssdDigit(0, 3);
                                        ssdUpdate();
                                        atraso_ms(2);
                                    }
                                    montandoPedido();
                                    return;
                                }
                                if (bitTst(botao, 5)) {
                                    calculaPedido();
                                    lcdPosition(0, 0);
                                    lcd_str("McChicken");
                                    lcdPosition(1, 0);
                                    lcd_str("CocaCola");
                                    lcdPosition(2, 0);
                                    lcd_str("Salada");
                                    lcdPosition(3, 0);
                                    lcd_str("Total: R$30");
                                    for (i = 0; i < 1000; i++) {
                                        ssdDigit(3, 0);
                                        ssdDigit(0, 1);
                                        ssdDigit(0, 2);
                                        ssdDigit(0, 3);
                                        ssdUpdate();
                                        atraso_ms(2);
                                    }
                                    montandoPedido();
                                    return;
                                }
                                if (bitTst(botao, 4)) {
                                    cancela();
                                    return;
                                }
                            }
                        }
                    }

                    if (bitTst(botao, 6)) {
                        pepsi();
                        for (;;) {
                            kpDebounce();
                            if (kpRead() != botao) {
                                botao = kpRead();
                                if (bitTst(botao, 7)) {
                                    calculaPedido();
                                    lcdPosition(0, 0);
                                    lcd_str("McChicken");
                                    lcdPosition(1, 0);
                                    lcd_str("Pepsi");
                                    lcdPosition(2, 0);
                                    lcd_str("Batata");
                                    lcdPosition(3, 0);
                                    lcd_str("Total: R$31");
                                    for (i = 0; i < 1000; i++) {
                                        ssdDigit(3, 0);
                                        ssdDigit(1, 1);
                                        ssdDigit(0, 2);
                                        ssdDigit(0, 3);
                                        ssdUpdate();
                                        atraso_ms(2);
                                    }
                                    montandoPedido();
                                    return;
                                }
                                if (bitTst(botao, 6)) {
                                    calculaPedido();
                                    lcdPosition(0, 0);
                                    lcd_str("McChicken");
                                    lcdPosition(1, 0);
                                    lcd_str("Pepsi");
                                    lcdPosition(2, 0);
                                    lcd_str("Nuggets");
                                    lcdPosition(3, 0);
                                    lcd_str("Total: R$30");
                                    for (i = 0; i < 1000; i++) {
                                        ssdDigit(3, 0);
                                        ssdDigit(0, 1);
                                        ssdDigit(0, 2);
                                        ssdDigit(0, 3);
                                        ssdUpdate();
                                        atraso_ms(2);
                                    }
                                    montandoPedido();
                                    return;
                                }
                                if (bitTst(botao, 5)) {
                                    calculaPedido();
                                    lcdPosition(0, 0);
                                    lcd_str("McChicken");
                                    lcdPosition(1, 0);
                                    lcd_str("Pepsi");
                                    lcdPosition(2, 0);
                                    lcd_str("Salada");
                                    lcdPosition(3, 0);
                                    lcd_str("Total: R$29");
                                    for (i = 0; i < 1000; i++) {
                                        ssdDigit(2, 0);
                                        ssdDigit(9, 1);
                                        ssdDigit(0, 2);
                                        ssdDigit(0, 3);
                                        ssdUpdate();
                                        atraso_ms(2);
                                    }
                                    montandoPedido();
                                    return;
                                }
                                if (bitTst(botao, 4)) {
                                    cancela;
                                    return;
                                }
                            }
                        }
                    }
                    if (bitTst(botao, 5)) {
                        kuat();
                        for (;;) {
                            kpDebounce();
                            if (kpRead() != botao) {
                                botao = kpRead();
                                if (bitTst(botao, 7)) {
                                    calculaPedido();
                                    lcdPosition(0, 0);
                                    lcd_str("McChicken");
                                    lcdPosition(1, 0);
                                    lcd_str("Kuat");
                                    lcdPosition(2, 0);
                                    lcd_str("Batata");
                                    lcdPosition(3, 0);
                                    lcd_str("Total: R$30");
                                    for (i = 0; i < 1000; i++) {
                                        ssdDigit(3, 0);
                                        ssdDigit(0, 1);
                                        ssdDigit(0, 2);
                                        ssdDigit(0, 3);
                                        ssdUpdate();
                                        atraso_ms(2);
                                    }
                                    montandoPedido();
                                    return;
                                }
                                if (bitTst(botao, 6)) {
                                    calculaPedido();
                                    lcdPosition(0, 0);
                                    lcd_str("McChicken");
                                    lcdPosition(1, 0);
                                    lcd_str("Kuat");
                                    lcdPosition(2, 0);
                                    lcd_str("Nuggets");
                                    lcdPosition(3, 0);
                                    lcd_str("Total: R$29");
                                    for (i = 0; i < 1000; i++) {
                                        ssdDigit(2, 0);
                                        ssdDigit(9, 1);
                                        ssdDigit(0, 2);
                                        ssdDigit(0, 3);
                                        ssdUpdate();
                                        atraso_ms(2);
                                    }
                                    montandoPedido();
                                    return;
                                }
                                if (bitTst(botao, 5)) {
                                    calculaPedido();
                                    lcdPosition(0, 0);
                                    lcd_str("McChicken");
                                    lcdPosition(1, 0);
                                    lcd_str("Kuat");
                                    lcdPosition(2, 0);
                                    lcd_str("Salada");
                                    lcdPosition(3, 0);
                                    lcd_str("Total: R$28");
                                    for (i = 0; i < 1000; i++) {
                                        ssdDigit(2, 0);
                                        ssdDigit(8, 1);
                                        ssdDigit(0, 2);
                                        ssdDigit(0, 3);
                                        ssdUpdate();
                                        atraso_ms(2);
                                    }
                                    montandoPedido();
                                    return;
                                }
                                if (bitTst(botao, 4)) {
                                    cancela();
                                    return;
                                }
                            }
                        }
                    }
                    if (bitTst(botao, 4)) {
                        cancela();
                        return;
                    }
                }
            }
        }
        if (bitTst(botao, 5)) {
            lcd_cmd(L_CLR);
            lcdPosition(0, 0);
            lcd_str("McTasty? Otimo");
            lcdPosition(1, 0);
            escolhaBebida();
            for (;;) {
                kpDebounce();
                if (kpRead() != botao) {
                    botao = kpRead();
                    if (bitTst(botao, 7)) {
                        cocaCola();
                        for (;;) {
                            kpDebounce();
                            if (kpRead() != botao) {
                                botao = kpRead();
                                if (bitTst(botao, 7)) {
                                    calculaPedido();
                                    lcdPosition(0, 0);
                                    lcd_str("McTasty");
                                    lcdPosition(1, 0);
                                    lcd_str("CocaCola");
                                    lcdPosition(2, 0);
                                    lcd_str("Batata");
                                    lcdPosition(3, 0);
                                    lcd_str("Total: R$38");
                                    for (i = 0; i < 1000; i++) {
                                        ssdDigit(3, 0);
                                        ssdDigit(8, 1);
                                        ssdDigit(0, 2);
                                        ssdDigit(0, 3);
                                        ssdUpdate();
                                        atraso_ms(2);
                                    }
                                    montandoPedido();
                                    return;
                                }
                                if (bitTst(botao, 6)) {
                                    calculaPedido();
                                    lcdPosition(0, 0);
                                    lcd_str("McTasty");
                                    lcdPosition(1, 0);
                                    lcd_str("CocaCola");
                                    lcdPosition(2, 0);
                                    lcd_str("Nuggets");
                                    lcdPosition(3, 0);
                                    lcd_str("Total: R$37");
                                    for (i = 0; i < 1000; i++) {
                                        ssdDigit(3, 0);
                                        ssdDigit(7, 1);
                                        ssdDigit(0, 2);
                                        ssdDigit(0, 3);
                                        ssdUpdate();
                                        atraso_ms(2);
                                    }
                                    montandoPedido();
                                    return;
                                }
                                if (bitTst(botao, 5)) {
                                    calculaPedido();
                                    lcdPosition(0, 0);
                                    lcd_str("McTasty");
                                    lcdPosition(1, 0);
                                    lcd_str("CocaCola");
                                    lcdPosition(2, 0);
                                    lcd_str("Salada");
                                    lcdPosition(3, 0);
                                    lcd_str("Total: R$36");
                                    for (i = 0; i < 1000; i++) {
                                        ssdDigit(3, 0);
                                        ssdDigit(6, 1);
                                        ssdDigit(0, 2);
                                        ssdDigit(0, 3);
                                        ssdUpdate();
                                        atraso_ms(2);
                                    }
                                    montandoPedido();
                                    return;
                                }
                                if (bitTst(botao, 4)) {
                                    cancela();
                                    return;
                                }
                            }
                        }
                    }

                    if (bitTst(botao, 6)) {
                        pepsi();
                        for (;;) {
                            kpDebounce();
                            if (kpRead() != botao) {
                                botao = kpRead();
                                if (bitTst(botao, 7)) {
                                    calculaPedido();
                                    lcdPosition(0, 0);
                                    lcd_str("McTasty");
                                    lcdPosition(1, 0);
                                    lcd_str("Pepsi");
                                    lcdPosition(2, 0);
                                    lcd_str("Batata");
                                    lcdPosition(3, 0);
                                    lcd_str("Total: R$37");
                                    for (i = 0; i < 1000; i++) {
                                        ssdDigit(3, 0);
                                        ssdDigit(7, 1);
                                        ssdDigit(0, 2);
                                        ssdDigit(0, 3);
                                        ssdUpdate();
                                        atraso_ms(2);
                                    }
                                    montandoPedido();
                                    return;
                                }
                                if (bitTst(botao, 6)) {
                                    calculaPedido();
                                    lcdPosition(0, 0);
                                    lcd_str("McTasty");
                                    lcdPosition(1, 0);
                                    lcd_str("Pepsi");
                                    lcdPosition(2, 0);
                                    lcd_str("Nuggets");
                                    lcdPosition(3, 0);
                                    lcd_str("Total: R$36");
                                    for (i = 0; i < 1000; i++) {
                                        ssdDigit(3, 0);
                                        ssdDigit(6, 1);
                                        ssdDigit(0, 2);
                                        ssdDigit(0, 3);
                                        ssdUpdate();
                                        atraso_ms(2);
                                    }
                                    montandoPedido();
                                    return;
                                }
                                if (bitTst(botao, 5)) {
                                    calculaPedido();
                                    lcdPosition(0, 0);
                                    lcd_str("McTasty");
                                    lcdPosition(1, 0);
                                    lcd_str("Pepsi");
                                    lcdPosition(2, 0);
                                    lcd_str("Salada");
                                    lcdPosition(3, 0);
                                    lcd_str("Total: R$35");
                                    for (i = 0; i < 1000; i++) {
                                        ssdDigit(3, 0);
                                        ssdDigit(5, 1);
                                        ssdDigit(0, 2);
                                        ssdDigit(0, 3);
                                        ssdUpdate();
                                        atraso_ms(2);
                                    }
                                    montandoPedido();
                                    return;
                                }
                                if (bitTst(botao, 4)) {
                                    cancela;
                                    return;
                                }
                            }
                        }
                    }
                    if (bitTst(botao, 5)) {
                        kuat();
                        for (;;) {
                            kpDebounce();
                            if (kpRead() != botao) {
                                botao = kpRead();
                                if (bitTst(botao, 7)) {
                                    calculaPedido();
                                    lcdPosition(0, 0);
                                    lcd_str("McTasty");
                                    lcdPosition(1, 0);
                                    lcd_str("Kuat");
                                    lcdPosition(2, 0);
                                    lcd_str("Batata");
                                    lcdPosition(3, 0);
                                    lcd_str("Total: R$36");
                                    for (i = 0; i < 1000; i++) {
                                        ssdDigit(3, 0);
                                        ssdDigit(6, 1);
                                        ssdDigit(0, 2);
                                        ssdDigit(0, 3);
                                        ssdUpdate();
                                        atraso_ms(2);
                                    }
                                    montandoPedido();
                                    return;
                                }
                                if (bitTst(botao, 6)) {
                                    calculaPedido();
                                    lcdPosition(0, 0);
                                    lcd_str("McTasty");
                                    lcdPosition(1, 0);
                                    lcd_str("Kuat");
                                    lcdPosition(2, 0);
                                    lcd_str("Nuggets");
                                    lcdPosition(3, 0);
                                    lcd_str("Total: R$35");
                                    for (i = 0; i < 1000; i++) {
                                        ssdDigit(3, 0);
                                        ssdDigit(5, 1);
                                        ssdDigit(0, 2);
                                        ssdDigit(0, 3);
                                        ssdUpdate();
                                        atraso_ms(2);
                                    }
                                    montandoPedido();
                                    return;
                                }
                                if (bitTst(botao, 5)) {
                                    calculaPedido();
                                    lcdPosition(0, 0);
                                    lcd_str("McTasty");
                                    lcdPosition(1, 0);
                                    lcd_str("Kuat");
                                    lcdPosition(2, 0);
                                    lcd_str("Salada");
                                    lcdPosition(3, 0);
                                    lcd_str("Total: R$34");
                                    for (i = 0; i < 1000; i++) {
                                        ssdDigit(3, 0);
                                        ssdDigit(4, 1);
                                        ssdDigit(0, 2);
                                        ssdDigit(0, 3);
                                        ssdUpdate();
                                        atraso_ms(2);
                                    }
                                    montandoPedido();
                                    return;
                                }
                                if (bitTst(botao, 4)) {
                                    cancela();
                                    return;
                                }
                            }
                        }
                    }
                    if (bitTst(botao, 4)) {
                        cancela();
                        return;
                    }
                }
            }
        }
        if (bitTst(botao, 4)) {
            cancela();
            return;
        }
    }
}