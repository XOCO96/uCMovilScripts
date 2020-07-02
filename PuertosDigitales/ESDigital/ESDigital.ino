// Script para el manejo de entradas/salidas digitales


const int LED = 22;
const int LED2 = 23;
const int LED3 = 24;
const int BUTTON = 2;
//const int BUTTON2 = 3;
int conteo = 0;
int estadoactual = 0;
int estadoanterior = 0;


void setup()
{
	pinMode(LED,OUTPUT);
    pinMode(LED2,OUTPUT);
    pinMode(LED3,OUTPUT);
    pinMode(BUTTON,INPUT_PULLUP);
    //pinMode(BUTTON2,INPUT_PULLUP);
}

void loop()
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
