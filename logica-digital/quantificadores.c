/* =====================================================================
 *  DESAFIO: QUANTIFICADORES EM MATRIZES DE DADOS
 *  Disciplina: Logica Digital  -  Profa. Polyana Santos Fonseca Nascimento
 *
 *  Alunos: Vinicius Meneses   Maria Luiza Cardoso
 *
 * ---------------------------------------------------------------------
 *  DECLARACAO DE USO DE IA GENERATIVA
 * ---------------------------------------------------------------------
 *  - Houve uso de IA Generativa? Sim.
 *  - Ferramenta utilizada: Claude.
 *  - Finalidade: apoio na replicação do codigo e correcao de erros
 *  - Extensao aproximada da contribuicao: Media, na replicacao/organizacao do
 *    codigo e dos textos explicativos; a logica de cada questao foi
 *    feita e validada por nos.
 *  - Medidas de validacao: (1) conferencia da matriz transcrita contra o
 *    PDF da lista; (2) verificacao dos exemplos/contraexemplos e
 *    dos conjuntos-verdade; (3) compilacao e execucao do codigo.
 *
 *  OBS.: nao foram usadas bibliotecas prontas para resolver os
 *  quantificadores. Tudo eh feito "na mao" com lacos e condicionais,
 *  (somente <stdio.h>). A programacao ficou um pouco confusa, caso nao entenda
 *  algo pergunte para nos
 * ===================================================================== */

#include <stdio.h>

#define NS 12   /* numero de sessoes  -> linhas  (S = {1..12}) */
#define NC 20   /* numero de cadeiras -> colunas (C = {1..20}) */

/* Codificacao: 1 = cadeira vendida ; 0 = cadeira nao vendida.
 * Cada LINHA eh uma sessao, cada COLUNA eh uma cadeira.
 * (Transcrita da lista de questoes.) */
int M[NS][NC] = {
/* Sessao  1 */ { 1,0,1,1,0, 1,1,0,1,1, 0,1,1,0,1, 0,1,1,0,1 },
/* Sessao  2 */ { 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0 },
/* Sessao  3 */ { 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1 },
/* Sessao  4 */ { 1,1,0,0,0, 1,0,1,0,1, 1,0,0,1,0, 1,0,1,0,1 },
/* Sessao  5 */ { 1,1,1,1,0, 1,0,1,0,1, 0,1,0,1,1, 1,1,1,1,1 },
/* Sessao  6 */ { 0,0,0,0,0, 1,1,1,0,1, 0,1,1,0,1, 0,1,0,1,1 },
/* Sessao  7 */ { 0,0,0,0,0, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1 },
/* Sessao  8 */ { 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,0 },
/* Sessao  9 */ { 1,0,1,0,1, 0,1,0,1,0, 1,0,1,0,1, 0,1,0,1,0 },
/* Sessao 10 */ { 1,1,1,1,1, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0 },
/* Sessao 11 */ { 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1 },
/* Sessao 12 */ { 1,1,1,0,1, 1,0,1,1,0, 1,0,1,1,0, 1,1,0,1,0 }
};

/* Regiao VIP = cadeiras 1..5  ;  Nao-VIP (N) = cadeiras 6..20 */
#define VIP_INI 1
#define VIP_FIM 5

/* ---------- Funcoes basicas pedidas no enunciado ---------- */

/* V(s,c): verdadeira (1) se a cadeira c foi vendida na sessao s.
 * Recebe s e c em base 1 (como no enunciado). */
int V(int s, int c) {
    return M[s - 1][c - 1] == 1;
}

/* I(s): numero total de cadeiras vendidas na sessao s (somatorio da linha). */
int I(int s) {
    int c, soma = 0;
    for (c = 1; c <= NC; c++)
        if (V(s, c)) soma++;
    return soma;
}

/* ---------- Utilitarios de impressao ---------- */

void linha(void) {
    printf("------------------------------------------------------------\n");
}

/* imprime um conjunto de inteiros no formato { a, b, c } */
void imprime_conjunto(int *v, int n) {
    int i;
    printf("{");
    for (i = 0; i < n; i++) {
        printf(" %d", v[i]);
        if (i < n - 1) printf(",");
    }
    if (n == 0) printf(" ");
    printf(" }");
}

void mostra_matriz(void) {
    int s, c;
    printf("MATRIZ DE VENDAS (1 = vendida | 0 = nao vendida)\n");
    printf("        ");
    for (c = 1; c <= NC; c++) printf("%2d ", c);
    printf("  I(s)\n");
    for (s = 1; s <= NS; s++) {
        printf("S%-2d :   ", s);
        for (c = 1; c <= NC; c++) printf("%2d ", M[s - 1][c - 1]);
        printf("   %2d\n", I(s));
    }
}

/* =====================================================================
 *  2. QUANTIFICACAO SIMPLES
 * ===================================================================== */

/* Q1 - Quantificador universal: para todo s, I(s) > 0
 * Logica do "para todo": procuramos o PRIMEIRO contraexemplo. */
void questao1(void) {
    int s, ok = 1, contra = 0;
    linha();
    printf("QUESTAO 1 - Quantificador universal:  (Vs in S) I(s) > 0\n");
    printf("Pergunta: todas as sessoes venderam pelo menos uma cadeira?\n");
    for (s = 1; s <= NS; s++) {
        if (!(I(s) > 0)) { ok = 0; contra = s; break; }  /* achou um falso -> derruba */
    }
    if (ok)
        printf("Resultado: VERDADEIRO. Todas as sessoes tem I(s) > 0.\n");
    else
        printf("Resultado: FALSO. Contraexemplo: sessao %d (I(%d) = %d).\n",
               contra, contra, I(contra));
}

/* Q2 - Quantificador existencial: existe s tal que I(s) = 20
 * Logica do "existe": procuramos o PRIMEIRO caso verdadeiro. */
void questao2(void) {
    int s, achou = 0, ex = 0;
    linha();
    printf("QUESTAO 2 - Quantificador existencial:  (Es in S) I(s) = 20\n");
    printf("Pergunta: existe alguma sessao em que TODAS as cadeiras foram vendidas?\n");
    for (s = 1; s <= NS; s++) {
        if (I(s) == NC) { achou = 1; ex = s; break; }
    }
    if (achou)
        printf("Resultado: VERDADEIRO. Exemplo: sessao %d (I(%d) = %d).\n",
               ex, ex, I(ex));
    else
        printf("Resultado: FALSO. Nenhuma sessao vendeu as 20 cadeiras.\n");
}

/* =====================================================================
 *  3. QUANTIFICACAO PARCIAL  (uma variavel quantificada, outra livre)
 *     -> a resposta eh um CONJUNTO-VERDADE
 * ===================================================================== */

/* Q3 - Sessoes em que TODAS as cadeiras foram vendidas:  (Vc in C) V(s,c)
 * Variavel livre: s.  Procuramos linhas com TODOS os valores 1. */
void questao3(void) {
    int s, c, conj[NS], n = 0;
    linha();
    printf("QUESTAO 3 - Conjunto-verdade de:  (Vc in C) V(s,c)\n");
    printf("Pergunta: em quais sessoes TODAS as cadeiras foram vendidas?\n");
    for (s = 1; s <= NS; s++) {
        int todas = 1;
        for (c = 1; c <= NC; c++)
            if (!V(s, c)) { todas = 0; break; }
        if (todas) conj[n++] = s;
    }
    printf("Conjunto-verdade (sessoes) = ");
    imprime_conjunto(conj, n);
    printf("\n");
}

/* Q4 - Sessoes em que PELO MENOS UMA cadeira foi vendida:  (Ec in C) V(s,c)
 * Variavel livre: s.  Procuramos linhas com pelo menos um 1. */
void questao4(void) {
    int s, c, conj[NS], n = 0;
    linha();
    printf("QUESTAO 4 - Conjunto-verdade de:  (Ec in C) V(s,c)\n");
    printf("Pergunta: em quais sessoes pelo menos uma cadeira foi vendida?\n");
    for (s = 1; s <= NS; s++) {
        int alguma = 0;
        for (c = 1; c <= NC; c++)
            if (V(s, c)) { alguma = 1; break; }
        if (alguma) conj[n++] = s;
    }
    printf("Conjunto-verdade (sessoes) = ");
    imprime_conjunto(conj, n);
    printf("\n");
}

/* Q5 - Cadeiras vendidas em TODAS as sessoes:  (Vs in S) V(s,c)
 * Variavel livre: c.  Procuramos COLUNAS com todos os valores 1. */
void questao5(void) {
    int c, s, conj[NC], n = 0;
    linha();
    printf("QUESTAO 5 - Conjunto-verdade de:  (Vs in S) V(s,c)\n");
    printf("Pergunta: quais cadeiras foram vendidas em TODAS as sessoes?\n");
    for (c = 1; c <= NC; c++) {
        int todas = 1;
        for (s = 1; s <= NS; s++)
            if (!V(s, c)) { todas = 0; break; }
        if (todas) conj[n++] = c;
    }
    printf("Conjunto-verdade (cadeiras) = ");
    imprime_conjunto(conj, n);
    printf("\n");
}

/* Q6 - Cadeiras vendidas em PELO MENOS UMA sessao:  (Es in S) V(s,c)
 * Variavel livre: c.  Procuramos COLUNAS com pelo menos um 1. */
void questao6(void) {
    int c, s, conj[NC], n = 0;
    linha();
    printf("QUESTAO 6 - Conjunto-verdade de:  (Es in S) V(s,c)\n");
    printf("Pergunta: quais cadeiras foram vendidas em pelo menos uma sessao?\n");
    for (c = 1; c <= NC; c++) {
        int alguma = 0;
        for (s = 1; s <= NS; s++)
            if (V(s, c)) { alguma = 1; break; }
        if (alguma) conj[n++] = c;
    }
    printf("Conjunto-verdade (cadeiras) = ");
    imprime_conjunto(conj, n);
    printf("\n");
}

/* =====================================================================
 *  4. QUANTIFICACAO DUPLA  (as duas variaveis presas -> resposta T/F)
 * ===================================================================== */

/* Q7 - Existe sessao com TODAS as cadeiras vendidas?  (Es in S)(Vc in C) V(s,c)
 * Procuramos pelo menos UMA linha totalmente preenchida com 1. */
void questao7(void) {
    int s, c, achou = 0, ex = 0;
    linha();
    printf("QUESTAO 7 - Dupla:  (Es in S)(Vc in C) V(s,c)\n");
    printf("Pergunta: existe alguma sessao em que todas as cadeiras foram vendidas?\n");
    for (s = 1; s <= NS && !achou; s++) {
        int todas = 1;
        for (c = 1; c <= NC; c++)
            if (!V(s, c)) { todas = 0; break; }
        if (todas) { achou = 1; ex = s; }
    }
    if (achou)
        printf("Resultado: VERDADEIRO. Exemplo: sessao %d esta totalmente vendida.\n", ex);
    else
        printf("Resultado: FALSO. Nenhuma sessao tem todas as cadeiras vendidas.\n");
}

/* Q8 - Toda sessao teve pelo menos uma cadeira vendida?  (Vs in S)(Ec in C) V(s,c)
 * Verificamos se TODA linha possui pelo menos um 1. */
void questao8(void) {
    int s, c, ok = 1, contra = 0;
    linha();
    printf("QUESTAO 8 - Dupla:  (Vs in S)(Ec in C) V(s,c)\n");
    printf("Pergunta: toda sessao teve pelo menos uma cadeira vendida?\n");
    for (s = 1; s <= NS; s++) {
        int alguma = 0;
        for (c = 1; c <= NC; c++)
            if (V(s, c)) { alguma = 1; break; }
        if (!alguma) { ok = 0; contra = s; break; }
    }
    if (ok)
        printf("Resultado: VERDADEIRO. Toda sessao vendeu pelo menos uma cadeira.\n");
    else
        printf("Resultado: FALSO. Contraexemplo: sessao %d nao vendeu nenhuma cadeira.\n",
               contra);
}

/* Q9 - Todas as cadeiras vendidas em todas as sessoes?  (Vs in S)(Vc in C) V(s,c)
 * Basta UMA celula 0 para tornar a proposicao falsa. */
void questao9(void) {
    int s, c, ok = 1, cs = 0, cc = 0;
    linha();
    printf("QUESTAO 9 - Dupla:  (Vs in S)(Vc in C) V(s,c)\n");
    printf("Pergunta: todas as cadeiras foram vendidas em todas as sessoes?\n");
    for (s = 1; s <= NS && ok; s++)
        for (c = 1; c <= NC; c++)
            if (!V(s, c)) { ok = 0; cs = s; cc = c; break; }
    if (ok)
        printf("Resultado: VERDADEIRO. A matriz inteira esta preenchida com 1.\n");
    else
        printf("Resultado: FALSO. Contraexemplo: V(%d,%d) = 0 (cadeira %d nao vendida na sessao %d).\n",
               cs, cc, cc, cs);
}

/* Q10 - Existe alguma cadeira nao vendida em alguma sessao?  (Es in S)(Ec in C) ~V(s,c)
 * Basta UMA celula 0 para a proposicao ser verdadeira. */
void questao10(void) {
    int s, c, achou = 0, cs = 0, cc = 0;
    linha();
    printf("QUESTAO 10 - Dupla:  (Es in S)(Ec in C) ~V(s,c)\n");
    printf("Pergunta: existe pelo menos uma cadeira nao vendida em alguma sessao?\n");
    for (s = 1; s <= NS && !achou; s++)
        for (c = 1; c <= NC; c++)
            if (!V(s, c)) { achou = 1; cs = s; cc = c; break; }
    if (achou)
        printf("Resultado: VERDADEIRO. Exemplo: V(%d,%d) = 0 (cadeira %d nao vendida na sessao %d).\n",
               cs, cc, cc, cs);
    else
        printf("Resultado: FALSO. Nenhuma cadeira ficou sem vender.\n");
}

/* =====================================================================
 *  5. PROPOSICOES COMPOSTAS COM REGIAO VIP
 * ===================================================================== */

/* Q11 - VIP esgotado E cadeira comum disponivel (conjunto-verdade em s):
 *        (Vc in VIP, V(s,c))  E  (Ec in N, ~V(s,c))
 * Sessoes em que TODAS as cadeiras VIP (1..5) foram vendidas
 * E PELO MENOS UMA cadeira nao-VIP (6..20) ficou disponivel. */
void questao11(void) {
    int s, c, conj[NS], n = 0;
    linha();
    printf("QUESTAO 11 - Composta (conjunto-verdade):\n");
    printf("   (Vc in VIP, V(s,c))  E  (Ec in N, ~V(s,c))\n");
    printf("Pergunta: em quais sessoes TODAS as VIP foram vendidas e pelo menos\n");
    printf("          uma cadeira comum (nao-VIP) ficou disponivel?\n");
    for (s = 1; s <= NS; s++) {
        int vip_todas = 1;   /* parte 1: para todo c VIP, V(s,c) */
        int comum_livre = 0; /* parte 2: existe c nao-VIP com ~V(s,c) */
        for (c = VIP_INI; c <= VIP_FIM; c++)
            if (!V(s, c)) { vip_todas = 0; break; }
        for (c = VIP_FIM + 1; c <= NC; c++)
            if (!V(s, c)) { comum_livre = 1; break; }
        if (vip_todas && comum_livre) conj[n++] = s;
    }
    printf("Conjunto-verdade (sessoes) = ");
    imprime_conjunto(conj, n);
    printf("\n");
}

/* Q12 - Nenhuma VIP vendida OU sala quase lotada (conjunto-verdade em s):
 *        (Vc in VIP, ~V(s,c))  OU  (I(s) >= 18)
 * Sessoes em que NENHUMA cadeira VIP foi vendida
 * OU pelo menos 18 cadeiras foram vendidas no total. */
void questao12(void) {
    int s, c, conj[NS], n = 0;
    linha();
    printf("QUESTAO 12 - Composta (conjunto-verdade):\n");
    printf("   (Vc in VIP, ~V(s,c))  OU  (I(s) >= 18)\n");
    printf("Pergunta: em quais sessoes nenhuma cadeira VIP foi vendida\n");
    printf("          OU pelo menos 18 cadeiras foram vendidas no total?\n");
    for (s = 1; s <= NS; s++) {
        int vip_nenhuma = 1; /* parte 1: para todo c VIP, ~V(s,c) */
        int lotada;          /* parte 2: I(s) >= 18 */
        for (c = VIP_INI; c <= VIP_FIM; c++)
            if (V(s, c)) { vip_nenhuma = 0; break; }
        lotada = (I(s) >= 18);
        if (vip_nenhuma || lotada) conj[n++] = s;
    }
    printf("Conjunto-verdade (sessoes) = ");
    imprime_conjunto(conj, n);
    printf("\n");
}

/* ===================================================================== */

int main(void) {
    printf("============================================================\n");
    printf(" DESAFIO: QUANTIFICADORES EM MATRIZES DE DADOS\n");
    printf(" S = {1..12} sessoes | C = {1..20} cadeiras | VIP = {1..5}\n");
    printf("============================================================\n");
    mostra_matriz();

    printf("\n>>> 2. QUANTIFICACAO SIMPLES\n");
    questao1();
    questao2();

    printf("\n>>> 3. QUANTIFICACAO PARCIAL (conjunto-verdade)\n");
    questao3();
    questao4();
    questao5();
    questao6();

    printf("\n>>> 4. QUANTIFICACAO DUPLA (verdadeiro / falso)\n");
    questao7();
    questao8();
    questao9();
    questao10();

    printf("\n>>> 5. PROPOSICOES COMPOSTAS COM REGIAO VIP\n");
    questao11();
    questao12();

    linha();
    return 0;
}
