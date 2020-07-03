/* Script de led intermitente y contador, haciendo uso de la función
    de interrupción externa por puerto  */


const int BOTON_INT = 0;
int cuenta = 0;
boolean estado = true;


void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(9600);
    attachInterrupt(BOTON_INT, swap, RISING);
}

void loop()
{
    digitalWrite(LED_BUILTIN,estado);
    Serial.println(cuenta);
    delay(1000);
}


void swap()
{
    cuenta++;
    estado = !estado;
}
