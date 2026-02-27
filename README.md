# 🟦 DAMA EM C

Um jogo de **Damas tradicional** implementado em **C**, desenvolvido como projeto de estudo para aprender lógica, estruturas de controle e manipulação de matrizes.

---

## 🎯 Sobre o Projeto

Este projeto implementa um jogo de damas clássico no console, com:

✔ Tabuleiro 8x8  
✔ Posicionamento inicial correto das peças  
✔ Turnos alternados entre as peças **Brancas (B)** e **Pretas (P)**  
✔ Movimentos diagonais válidos  
✔ Contagem de peças e detecção de vitória  
✔ Validação de entradas do jogador

O foco principal é reforçar lógica de programação, uso de funções, estruturas condicionais e loops.

---

## 🧠 Funcionalidades Implementadas

✅ Inicialização do tabuleiro  
✅ Impressão do tabuleiro no terminal  
✅ Função de mover peças  
✅ Alternância de turno entre os jogadores  
✅ Verificação de movimento válido (diagonal comum)  
✅ Contagem de peças para detectar vencedor  
*(desenvolvimento futuro)*
❌  Captura de peças  
❌ Promoção de dama  
❌ Jogador vs Computador

---

## 📌 Regras do jogo no programa

👉 O jogador informa:

[Coluna da peça] [Linha da peça]
[Coluna de destino] [Linha de destino]


▪ As peças **B (brancas)** se movem para frente (linha decrescente)  
▪ As peças **P (pretas)** se movem para frente (linha crescente)  
▪ Somente um passo diagonal simples é permitido por vez  
▪ Movimento válido apenas se o destino estiver vazio

---

## ▶ Como Compilar e Executar

Para compilar:

```bash
gcc -o damas damas.c

Para executar:
./damas