/*  Script general para el uC   */   


#include <TimerOne.h>

//----------------------------
int segundo = 50;
int minuto = 59;
int hora = 11;
bool enviar = false;
bool tiempo = true;

//----------------------------
char recibido = 0;
char actividad = 0;
//----------------------------
float voltaje = 0;
float q = 0.004887;
float prop = 4.0117;
int pwm = 0;
const int Led = 13;
int ctimp = 0;
//----------------------------
const int LED = 22;
const int LED2 = 23;
const int LED3 = 24;
const int BUTTON = 3;
//const int BUTTON2 = 3;
int conteo = 0;
int estadoactual = 0;
int estadoanterior = 0;
//----------------------------
const int BOTON_INT = 0;
int cuenta = 0;
boolean estado = true;

boolean analogAux = false;


//////////////////////   Configuracion   ///////////////////////
void setup()
{
    Timer1.initialize(1000000); //microseconds
    Timer1.attachInterrupt(blinky);
    Serial.begin(9600);
    //---------------------------
    pinMode(Led,OUTPUT);
    //---------------------------
    pinMode(LED,OUTPUT);
    pinMode(LED2,OUTPUT);
    pinMode(LED3,OUTPUT);
    pinMode(BUTTON,INPUT_PULLUP);
    //--------------------------------
    pinMode(Led, OUTPUT);
    attachInterrupt(BOTON_INT, swap, RISING);
}

//////////////////////   Ciclo principal   ///////////////////////
void loop()
{

    if (Serial.available())
    {
        recibido = Serial.read(); 
        if (recibido != '\n')
        {
            actividad = recibido;
            analogAux=true;
            //Serial.println(recibido);
        }  
    }

    switch (actividad)
    {
    case 'R':
        reloj();
        break;
    case 'A':
        ESAnalog();
        break;
    case 'D':
        ESDigital();
        break;
    case 'P':
        IntPuerto();
        break;
    
    default:
        //Serial.print("Esperando instruccion:   ");
        //Serial.println(actividad);
        delay(1000);
        break;
    }

    
}


//////////////////////   Funciones   ///////////////////////
void reloj()
{
    if (enviar)
    {
        enviar = false;

        if (segundo == 59)
        {
            segundo = 0;
            if (minuto == 59)
            {
                minuto = 0;
                if (hora == 11)
                {
                    tiempo = !tiempo;
                }
                if (hora == 12)
                {
                    hora = 1;
                }
                else
                {
                    hora++;
                }     
            }
            else
            {
                minuto++;
            }
        }
        else
        {
            segundo++;
        }
        Serial.print(hora);
        Serial.print(":");
        Serial.print(minuto);
        Serial.print(":");
        Serial.print(segundo);
        if (tiempo)
        {
            Serial.println("   PM");
        }
        else
        {
            Serial.println("   AM");
        }

    }
}


void ESAnalog()
{
    if (analogAux)
    {
        ctimp=0;
        analogAux = false;
    }
    
    int ValorSensor = analogRead(A0);


    //Serial.println(ValorSensor);
    //voltaje = ValorSensor*q;
    //Serial.print("   ") ;
    //Serial.print(voltaje);
    //Serial.print("   ");


    pwm = ValorSensor/prop;
    if (ctimp <50)
    {
        //Serial.println(pwm);
        Serial.println(ValorSensor);
        //ctimp = 0;
    }
    /*else
    {
        //Serial.println(pwm);
        ctimp++;
    }*/
    ctimp++;

    analogWrite(Led,pwm);
    delay(1000);
}


void ESDigital()
{
    estadoactual = digitalRead(BUTTON);
    delay(20);

    if (estadoactual == 0 & estadoanterior == 1)
    {
        if (conteo == 3)
        {
            conteo = 0;
        }else conteo++;
    }
    estadoanterior = estadoactual;
    
    if (conteo == 0)
    {
        digitalWrite(LED,LOW);
        digitalWrite(LED2,LOW);
        digitalWrite(LED3,LOW);
    }
    if (conteo == 1)
    {
        digitalWrite(LED,HIGH);
        digitalWrite(LED2,LOW);
        digitalWrite(LED3,LOW);
    }
    if (conteo == 2)
    {
        digitalWrite(LED,HIGH);
        digitalWrite(LED2,HIGH);
        digitalWrite(LED3,LOW);
    }
    if (conteo == 3)
    {
        digitalWrite(LED,HIGH);
        digitalWrite(LED2,HIGH);
        digitalWrite(LED3,HIGH);
    }
}


void IntPuerto()
{
    digitalWrite(Led,estado);
    Serial.println(cuenta);
    delay(1000);
}


//////////////////////   Acciones de interrupción   ///////////////////////
void blinky() 
{
    enviar = true;
}


void swap()
{
    cuenta++;
    estado = !estado;
}
