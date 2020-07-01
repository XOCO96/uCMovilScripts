// Script de configuracion del puerto Serial
    // Enciende/apaga el LED cada que
    // recibe un valor por el puerto serie

boolean Mensaje = false;


void setup()
{
	Serial.begin(9600);
    pinMode(LED_BUILTIN,OUTPUT);
}

void loop()
{
	char c;

    if (Serial.available())
    {
        c = Serial.read();

        Mensaje = !Mensaje;
        if (Mensaje)
        {
            digitalWrite(LED_BUILTIN, HIGH);
        }else  digitalWrite(LED_BUILTIN, LOW); 
        
    }
    delay(10);
    
}
