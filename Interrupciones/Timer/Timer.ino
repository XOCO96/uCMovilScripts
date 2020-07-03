/* Script de un Reloj, haciendo uso de la función
    de interrupcion por Timer  */


#include <TimerOne.h>


int segundo = 50;
int minuto = 59;
int hora = 11;
bool enviar = false;
bool tiempo = true;


void setup()
{
	Timer1.initialize(1000000); //microseconds
    Timer1.attachInterrupt(blinky);
    Serial.begin(9600);
}

void loop()
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
            Serial.print("   PM");
        }
        else
        {
            Serial.print("   AM");
        }

    }
}


void blinky() 
{
    enviar = true;
}
