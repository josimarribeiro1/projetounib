#include "ctimer.h"
 
#define LED0  13 //DEFININDO A VARIAVEL PARA O LED NO CONECTOR 13
#define LED1  12 //DEFININDO A VARIAVEL PARA O LED NO CONECTOR 12
#define LED2  11 //DEFININDO A VARIAVEL PARA O LED NO CONECTOR 11
 
cTimer  g_Timer0(true); //INICIAR OS CONTADORES
cTimer  g_Timer1(true); //INICIAR OS CONTADORES
cTimer  g_Timer2(true); //INICIAR OS CONTADORES
 
// Defina aqui os tempos em MS para cada LED piscar:

#define   TEMPO_0   3000 //AMARELO
#define   TEMPO_1   3050 //VERDE
#define   TEMPO_2   3100 //VERMELHO

bool    gLed0 = false; //BOOLEANO - LIGA/DESLIGA
bool    gLed1 = false; //BOOLEANO - LIGA/DESLIGA
bool    gLed2 = false; //BOOLEANO - LIGA/DESLIGA
 
void setup() {
  pinMode(LED0, OUTPUT); //CONFIGURA O PINO
  digitalWrite(LED0, 0); //ATIVA O PINO
  
  pinMode(LED1, OUTPUT); //CONFIGURA O PINO
  digitalWrite(LED1, 0); //ATIVA O PINO
  
  pinMode(LED2, OUTPUT); //CONFIGURA O PINO
  digitalWrite(LED2, 0); //ATIVA O PINO
 
  g_Timer0.SetTimeOut(TEMPO_0); //RECEBE O TEMPO EM MS
  g_Timer1.SetTimeOut(TEMPO_1); //RECEBE O TEMPO EM MS
  g_Timer2.SetTimeOut(TEMPO_2); //RECEBE O TEMPO EM MS
   
}
 
void loop() {

  //Ou seja, se o timer já atingiu o tempo limite (IsTimeOut() retorna verdadeiro),
  //inverta o estado do LED e reinicie o contador novamente (parâmetro true no IsTimeOut) .

  //AMARELO
  if(g_Timer0.IsTimeOut(true))   //Se o timer esgotar (true), reinicia o contador, assim o LED acende.
  {
    digitalWrite(LED0, gLed0); //LED é ativo
    gLed0 = !gLed0;  //Liga/Desliga
  }


 //VERDE
  if(g_Timer1.IsTimeOut(true))
  {
    digitalWrite(LED1, gLed1); //LED é ativo
    gLed1 = !gLed1;  //Liga/Desliga
  }

 //VERMELHO
  if(g_Timer2.IsTimeOut(true))
  {
    digitalWrite(LED2, gLed2); //LED é ativo
    gLed2 = !gLed2;  //Liga/Desliga
  }
 
  }
