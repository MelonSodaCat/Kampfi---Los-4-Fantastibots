
//TAREA 3 CODIGO LOS 4 FANTASTIBOTS

//paquete control bluetooth
#include <SoftwareSerial.h>
SoftwareSerial SerialBT(3,2);
//RX, TX

// Pines de motores

int FR_Fwrd =   8;

int FL_Fwrd = 11;

int FR_Bkrd =   10;

int FL_Bkrd = 12;
//ARMA
int S=4;

//Otras variables
char state;
char I;



//--- Codigo ---

//---MOVIMIENTO---
//notar que en el codigo se invierten los comandos para la rueda FRONT RIGHT (FR Bkrd y Fwrd) esto se debe a un problema del puente H en enviar las instrucciones,
// por eso esa discrepancias con lo usual

// stop(): Detiene todos los motores. No recibe ni retorna nada
//para fr high es low, low es high
void stop() {
    digitalWrite(FR_Fwrd, LOW);
    digitalWrite(FL_Fwrd, LOW);
    digitalWrite(FR_Bkrd, LOW);
    
    digitalWrite(FL_Bkrd, LOW);
}



//linea_recta: str -> void
//funcion para moverse en una linea recta por 2000 ms
//el string entregado indica si prender los pines
// correspondientes a movimiento adelante o atras
void linea_recta(String dir) {  
  //adelante
  if (dir == "forward"){
     digitalWrite(FR_Fwrd, LOW);
  
  digitalWrite(FL_Fwrd, LOW);
  
    digitalWrite(FR_Bkrd,HIGH);
  
  digitalWrite(FL_Bkrd, HIGH);

    




    
  
 


  }
    //atras
   else if (dir == "back"){
    digitalWrite(FR_Bkrd, LOW);
  
  digitalWrite(FL_Bkrd, LOW);
  
    digitalWrite(FR_Fwrd, HIGH);
  
  digitalWrite(FL_Fwrd, HIGH);
  

  

  }
  
}

//giro: str  -> void
//Funcion para girar al lado indicado por el primer str 

void giro(String side){

//aqui se inicia la funcion de direccion para determinar hacia donde el giro
  linea_recta("forward");


    //Se realizan dos casos para cada lado de giro
    //la logica de giro es que se prenden solo las ruedas del lado contrario (4 ruedas)
  if(side=="left"){

     digitalWrite(FR_Fwrd, HIGH);
  digitalWrite(FR_Bkrd, LOW);
    
    


 


    }
  else if(side=="right"){

     digitalWrite(FL_Fwrd, HIGH);
     digitalWrite(FL_Bkrd, LOW);

      



    }
    

  }
  




//bluetooth--Arduino
//leerSerial: void->str
char leerSerial(){

  SerialBT.listen();
  if (SerialBT.available()>0){

    state=SerialBT.read();
     
   
  
  }

 return state;
}









void setup() {
  // Definimos los pines como outputs
    pinMode(FR_Fwrd, OUTPUT);
    
    pinMode(FL_Fwrd, OUTPUT);
    
    pinMode(FR_Bkrd, OUTPUT);

    pinMode(FL_Bkrd, OUTPUT);
    
    pinMode(S, OUTPUT);
    
  // Activamos el led de la placa
    pinMode(LED_BUILTIN, OUTPUT);
    //Conexion bluetooth
    Serial.begin(9600);
    
  Serial.println("----");
  Serial.println("Ready");
  Serial.println("----");
    SerialBT.begin(9600);
    
  // Por si acaso, paramos los motores
    stop();
}

void loop() {
  
  
  I=leerSerial();
if (I=='F'){
linea_recta("forward");
delay(50);
Serial.println(I);

}
else if(I=='B'){
linea_recta("back");
delay(50);
Serial.println(I);
}
else if(I=='R'){
  giro("right");
  Serial.println(I);

}
else if(I=='L'){

  giro("left");
  Serial.println(I);


}
else if(I=='S'){
  stop();



}
else if(I=='A'){
digitalWrite(S,HIGH);}
else if(I=='P'){
digitalWrite(S,LOW);

}
else{

digitalWrite(LED_BUILTIN, HIGH);

}


}

  
