
/*  Script empleado para el uso de los puertos analógicos:
    A partir de la lectura de un potenciometro se determina 
    el voltaje en el mismo y en relacion a este valor se 
    determina el valor para el PWM que controla la intensidad
    de un LED */


float voltaje = 0;
float q = 0.004887;
float prop = 4.0117;
int pwm = 0;
const int Led = 13;
int ctimp = 0;


void setup()
{
	Serial.begin(9600);
    pinMode(Led,OUTPUT);
}

void loop()
{
	int ValorSensor = analogRead(A0);


    Serial.print(ValorSensor);
    voltaje = ValorSensor*q;
    Serial.print("   ") ;
    Serial.print(voltaje);
    Serial.print("   ");


    pwm = ValorSensor/prop;
    if (ctimp==10)
    {
        Serial.print(pwm);
        ctimp = 0;
    }
    else
    {
        Serial.print(pwm);
        ctimp++;
    }
    

    analogWrite(Led,pwm);
    delay(1000);
    
}
