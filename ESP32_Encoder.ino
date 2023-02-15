// Pins del Encoder

#define clk 35
#define dt 33

 int contador = 0; 
 int aEstado;
 int aUltEstado;  

 void setup() { 
   pinMode (clk,INPUT);
   pinMode (dt,INPUT);
   
   Serial.begin (115200);
   // Leo el estado inicial de clk
   aUltEstado = digitalRead(clk);   
 } 

 void loop() { 
   aEstado = digitalRead(clk); // Leo el estado actual de clk
   // Si el estado previo y el estado actual de CLK son diferentes significa que ocurrio un pulso
   if (aEstado != aUltEstado){     
     // Si el estado de DT es diferente al de CLK significa que se roto 
     if (digitalRead(dt) != aEstado) { 
       contador --;
     } else {
       contador ++;
     }
     Serial.print("Posicion: ");
     Serial.println(contador);
   } 
   aUltEstado = aEstado; // Actualiza el ultimo estado de CLK con el estado actual
 }
