#include <SPI.h>
#include <Mirf.h>
#include <nRF24L01.h>
#include <MirfHardwareSpiDriver.h>
void setup()
{
 Serial.begin(9600);
 Serial.println( "RECEPTOR---Starting wireless..." );

// Setup
  Mirf.spi = &MirfHardwareSpi;
  Mirf.init();
  Mirf.config();
 
 // Nombre que le vas a dar a ESTE NRF24L01. Si el alguien quiere emitir a ESTE equipo tiene que referirse a este nombre
// seria el equivalente a la ip de un ordenador. 5 bytes maximo.

 Mirf.setRADDR((byte *)"RX_02");
 
 // Payload, en bytes, a transmitir. Si quiere mandar dos datos, dos por por ejemplo, usa 2. 3 para tres... hasta 32
 Mirf.payload = 1;

 // we use channel 90 as it is outside of WLAN bands 
 // or channels used by wireless surveillance cameras 
// esto lo dejo igual
 Mirf.channel = 45;
 
 
 // Esto inicia el mirf y borra la lista FIFO
 Mirf.config();  

}

void loop()
{

 byte c; 

 // comprobamos que no hay datos a recibir.
 if( Mirf.dataReady() )
 {
    // lo recibimos y lo almacenamos en C
    Mirf.getData(&c);

   // ... and write it out to the PC
    Serial.println(c);
 }
}
