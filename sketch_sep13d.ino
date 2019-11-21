int counter=0;
void setup() {
  Serial.begin(9600);
  DDRB = DDRB | B10100100;
 
  cli();
  TCCR1B= 0; TCCR1A=0;
  TCCR1B |= B00001101;
  OCR1A= 0x3D09;
  TIMSK1 |= (1 << OCIE1A);
  sei();
}

void loop() {
  // put your main code here, to run repeatedly:

}

ISR(TIMER1_COMPA_vect){
  Serial.println("ISR triggered");
  Serial.println(counter);
 
  if(counter==0){
  digitalWrite(2, HIGH); //verde
  digitalWrite(5, LOW);
  digitalWrite(7, LOW);
  }else if(counter==12){
  digitalWrite(5, HIGH);
  }else if(counter== 15){
  digitalWrite(2, LOW); //verde
  digitalWrite(5, LOW);
  digitalWrite(7, HIGH);
  }else if(counter==24){
  counter=-1;
  }
counter= counter+1;
}
