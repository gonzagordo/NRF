// Defines for setting the MiRF registers for transmitting or receiving mode
void inicializar(){   
	cePin = 8;
	csnPin = 7;
	channel = 1;
	payload = 16;
	
    pinMode(cePin,OUTPUT);
    pinMode(csnPin,OUTPUT);
    ceLow();
    csnHi();
}

void ceHi(){
	digitalWrite(cePin,HIGH);
}

void ceLow(){
	digitalWrite(cePin,LOW);
}

void csnHi(){
	digitalWrite(csnPin,HIGH);
}

void csnLow(){
	digitalWrite(csnPin,LOW);
}

// Clocks only one byte INTO the given MiRF register
void configRegister(uint8_t reg, uint8_t value){
    csnLow();
    SPI.transfer(W_REGISTER | (REGISTER_MASK & reg));
    SPI.transfer(value);
    csnHi();
}

// Clocks only one byte FROM the given MiRF register
 uint8_t readRegister(uint8_t reg, uint8_t  value)
{
    csnLow();
    SPI.transfer(R_REGISTER | (REGISTER_MASK & reg));
    value= SPI.transfer(10);
    csnHi();
    return value;
}
