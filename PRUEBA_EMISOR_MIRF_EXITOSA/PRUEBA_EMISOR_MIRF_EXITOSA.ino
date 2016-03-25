#include <SPI.h>
#include <Mirf.h>
#include <nRF24L01.h>
#include <MirfHardwareSpiDriver.h>
byte dato=33;
void setup()
{
  Serial.begin(9600);
 Serial.println( "TRANSMISOR---Starting wireless... " );
  // Iniciamos el modo de trasmision
  // Setup
 Mirf.spi = &MirfHardwareSpi;
 Mirf.init();
 
 // payload de un byte
 Mirf.payload = 1;
 
 // lo del canal
 Mirf.channel = 90;
// Nombre que le vas a dar a ESTE NRF24L01. En el momento de transmsitir al emisor tienes que señalarle este receptor.
// seria el equivalente a la ip de un ordenador. 5 bytes maximo.

 Mirf.setRADDR((byte *)"EM_01");
// a configurar y vavciar cola FIFO
 Mirf.config();
 
}

void loop() 
{
 
 
 // nombre del NRF24l01 al que vamos a emitir. Del NRF24L01 DESTINO. 

 Mirf.setTADDR((byte *)"RX_01");
 Serial.print( "EMITIENDO= " );
Serial.println(dato);

 //ahora vamos a emitir
 Mirf.send(&dato);
//esperamos a que termine de emitir
   while( Mirf.isSending() ) ;
 
 delay(1000);
 dato++;
}
