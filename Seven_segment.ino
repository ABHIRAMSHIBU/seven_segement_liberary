long readVcc() {
  long result;
  // Read 1.1V reference against AVcc
  ADMUX = _BV(REFS0) | _BV(MUX3) | _BV(MUX2) | _BV(MUX1);
  delay(2); // Wait for Vref to settle
  ADCSRA |= _BV(ADSC); // Convert
  while (bit_is_set(ADCSRA,ADSC));
  result = ADCL;
  result |= ADCH<<8;
  result = 1126400L / result; // Back-calculate AVcc in mV
  return result;
}
void seg1_on()
{
  DDRD =(1<<2)|(1<<5)|(1<<6)|(1<<7);
  DDRB =(1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4);
}
void seg1_off()
{
  DDRD =(0<<2)|(0<<5)|(0<<6)|(0<<7);
  DDRB =(0<<0)|(0<<1)|(0<<2)|(0<<3)|(0<<4);
}
void seg1_selftest()
{
  #define del 100
  PORTD =(0<<2)|(1<<5)|(1<<6)|(1<<7);
  PORTB =(1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4);
  delay(del);
  PORTD =(0<<2)|(0<<5)|(1<<6)|(1<<7);
  delay(del);
  PORTD =(0<<2)|(0<<5)|(0<<6)|(1<<7);
  delay(del);
  PORTD =(0<<2)|(0<<5)|(0<<6)|(0<<7);
  delay(del);
  PORTB =(0<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4);
  delay(100);
  PORTB =(0<<0)|(0<<1)|(1<<2)|(1<<3)|(1<<4);
  delay(del);
  PORTB =(0<<0)|(0<<1)|(0<<2)|(1<<3)|(1<<4);
  delay(100);
  PORTB =(0<<0)|(0<<1)|(0<<2)|(0<<3)|(1<<4);
  delay(del);
  PORTB =(0<<0)|(0<<1)|(0<<2)|(0<<3)|(0<<4);
  delay(del);
  PORTD =(0<<2)|(1<<5)|(1<<6)|(1<<7);
  PORTB =(1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4);
  delay(del);
  PORTD =(0<<2)|(0<<5)|(0<<6)|(0<<7);
  PORTB =(0<<0)|(0<<1)|(0<<2)|(0<<3)|(0<<4);
  delay(del);
  PORTD =(0<<2)|(0<<5)|(0<<6)|(0<<7);
  PORTB =(0<<0)|(0<<1)|(0<<2)|(0<<3)|(0<<4); 
  delay(del);
  #undef del
}
void seg1_reset()
{
  PORTD =(0<<2)|(0<<5)|(0<<6)|(0<<7);
  PORTB =(0<<0)|(0<<1)|(0<<2)|(0<<3)|(0<<4);
}
void seg1_zero()
{
  seg1_reset();
  PORTD =(0<<2)|(1<<5)|(1<<6)|(1<<7);
  PORTB =(0<<0)|(1<<1)|(1<<2)|(1<<3)|(0<<4);
}
void seg1_one()
{
  seg1_reset();
  PORTD =(0<<2)|(0<<5)|(0<<6)|(1<<7);
  PORTB =(0<<0)|(1<<1)|(0<<2)|(0<<3)|(0<<4);
}
void seg1_two()
{
  seg1_reset();
  PORTD =(0<<2)|(1<<5)|(1<<6)|(0<<7);
  PORTB =(0<<0)|(1<<1)|(1<<2)|(0<<3)|(1<<4);
}
void seg1_three()
{
  seg1_reset();
  PORTD =(0<<2)|(0<<5)|(1<<6)|(1<<7);
  PORTB =(0<<0)|(1<<1)|(1<<2)|(0<<3)|(1<<4);
}
void seg1_four()
{
  seg1_reset();
  PORTD =(0<<2)|(0<<5)|(0<<6)|(1<<7);
  PORTB =(0<<0)|(1<<1)|(0<<2)|(1<<3)|(1<<4);
}
void seg1_five()
{
  seg1_reset();
  PORTD =(0<<2)|(0<<5)|(1<<6)|(1<<7);
  PORTB =(0<<0)|(0<<1)|(1<<2)|(1<<3)|(1<<4);
}
void seg1_six()
{
  seg1_reset();
  PORTD =(0<<2)|(1<<5)|(1<<6)|(1<<7);
  PORTB =(0<<0)|(0<<1)|(1<<2)|(1<<3)|(1<<4);
}
void seg1_seven()
{
  seg1_reset();
  PORTD =(0<<2)|(0<<5)|(0<<6)|(1<<7);
  PORTB =(0<<0)|(1<<1)|(1<<2)|(0<<3)|(0<<4);
}
void seg1_eight()
{
  seg1_reset();
  PORTD =(0<<2)|(1<<5)|(1<<6)|(1<<7);
  PORTB =(0<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4);
}
void seg1_nine()
{
  seg1_reset();
  PORTD =(0<<2)|(0<<5)|(1<<6)|(1<<7);
  PORTB =(0<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4);
}
void seg1_dot_zero()
{
  seg1_reset();
  PORTD =(0<<2)|(1<<5)|(1<<6)|(1<<7);
  PORTB =(1<<0)|(1<<1)|(1<<2)|(1<<3)|(0<<4);
}
void seg1_dot_one()
{
  seg1_reset();
  PORTD =(0<<2)|(0<<5)|(0<<6)|(1<<7);
  PORTB =(1<<0)|(1<<1)|(0<<2)|(0<<3)|(0<<4);
}
void seg1_dot_two()
{
  seg1_reset();
  PORTD =(0<<2)|(1<<5)|(1<<6)|(0<<7);
  PORTB =(1<<0)|(1<<1)|(1<<2)|(0<<3)|(1<<4);
}
void seg1_dot_three()
{
  seg1_reset();
  PORTD =(0<<2)|(0<<5)|(1<<6)|(1<<7);
  PORTB =(1<<0)|(1<<1)|(1<<2)|(0<<3)|(1<<4);
}
void seg1_dot_four()
{
  seg1_reset();
  PORTD =(0<<2)|(0<<5)|(0<<6)|(1<<7);
  PORTB =(1<<0)|(1<<1)|(0<<2)|(1<<3)|(1<<4);
}
void seg1_dot_five()
{
  seg1_reset();
  PORTD =(0<<2)|(0<<5)|(1<<6)|(1<<7);
  PORTB =(1<<0)|(0<<1)|(1<<2)|(1<<3)|(1<<4);
}
void seg1_dot_six()
{
  seg1_reset();
  PORTD =(0<<2)|(1<<5)|(1<<6)|(1<<7);
  PORTB =(1<<0)|(0<<1)|(1<<2)|(1<<3)|(1<<4);
}
void seg1_dot_seven()
{
  seg1_reset();
  PORTD =(1<<2)|(0<<5)|(0<<6)|(1<<7);
  PORTB =(0<<0)|(1<<1)|(1<<2)|(0<<3)|(0<<4);
}
void seg1_dot_eight()
{
  seg1_reset();
  PORTD =(0<<2)|(1<<5)|(1<<6)|(1<<7);
  PORTB =(1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4);
}
void seg1_dot_nine()
{
  seg1_reset();
  PORTD =(0<<2)|(0<<5)|(1<<6)|(1<<7);
  PORTB =(1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4);
}
void seg1_num_test()
{
  #define del 100
  //zero
  seg1_zero();
  delay(del);
  //one
  seg1_one();
  delay(del);
  //two
  seg1_two();
  delay(del);
  //three
  seg1_three();
  delay(del);
  //four
  seg1_four();
  delay(del);
  //five
  seg1_five();
  delay(del);
  //six
  seg1_six();
  delay(del);
  //seven
  seg1_seven();
  delay(del);
  //eight
  seg1_eight();
  delay(del);
  //nine
  seg1_nine();
  delay(del);
}
void seg1_dot_num_test()
{
  #define del 100
  //zero
  seg1_dot_zero();
  delay(del);
  //one
  seg1_dot_one();
  delay(del);
  //two
  seg1_dot_two();
  delay(del);
  //three
  seg1_dot_three();
  delay(del);
  //four
  seg1_dot_four();
  delay(del);
  //five
  seg1_dot_five();
  delay(del);
  //six
  seg1_dot_six();
  delay(del);
  //seven
  seg1_dot_seven();
  delay(del);
  //eight
  seg1_dot_eight();
  delay(del);
  //nine
  seg1_dot_nine();
  delay(del);
}











void seg2_on()
{
  PORTD = (1<<4)|(1<<5)|(1<<6)|(1<<7);
  PORTB = (1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4);
  DDRD =(1<<4)|(1<<5)|(1<<6)|(1<<7);
  DDRB =(1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4);
}
void seg2_off()
{
  DDRD =(0<<4)|(0<<5)|(0<<6)|(0<<7);
  DDRB =(0<<0)|(0<<1)|(0<<2)|(0<<3)|(0<<4);
}
void seg2_selftest()
{
  #define del 100
  PORTD =~((0<<2)|(1<5)|(1<<6)|(1<<7));
  PORTB =~((1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4));
  delay(del);
  PORTD =~((0<<2)|(0<<5)|(1<<6)|(1<<7));
  delay(del);
  PORTD =~((0<<2)|(0<<5)|(0<<6)|(1<<7));
  delay(del);
  PORTD =~((0<<2)|(0<<5)|(0<<6)|(0<<7));
  delay(del);
  PORTB =~((0<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4));
  delay(del);
  PORTB =~((0<<0)|(0<<1)|(1<<2)|(1<<3)|(1<<4));
  delay(del);
  PORTB =~((0<<0)|(0<<1)|(0<<2)|(1<<3)|(1<<4));
  delay(100);
  PORTB =~((0<<0)|(0<<1)|(0<<2)|(0<<3)|(1<<4));
  delay(del);
  PORTB =~((0<<0)|(0<<1)|(0<<2)|(0<<3)|(0<<4));
  delay(del);
  PORTD =~((0<<2)|(1<<5)|(1<<6)|(1<<7));
  PORTB =~((1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4));
  delay(del);
  PORTD =~((0<<2)|(0<<5)|(0<<6)|(0<<7));
  PORTB =~((0<<0)|(0<<1)|(0<<2)|(0<<3)|(0<<4));
  delay(del);
  PORTD =~((0<<2)|(0<<5)|(0<<6)|(0<<7));
  PORTB =~((0<<0)|(0<<1)|(0<<2)|(0<<3)|(0<<4));
  delay(del);
  #undef del
}
void seg2_reset()
{
  PORTD =~((0<<2)|(0<<5)|(0<<6)|(0<<7));
  PORTB =~((0<<0)|(0<<1)|(0<<2)|(0<<3)|(0<<4));
}
void seg2_zero()
{
  seg2_reset();
  PORTD =~((0<<2)|(1<<5)|(1<<6)|(1<<7));
  PORTB =~((0<<0)|(1<<1)|(1<<2)|(1<<3)|(0<<4));
}
void seg2_one()
{
  seg2_reset();
  PORTD =~((0<<2)|(0<<5)|(0<<6)|(1<<7));
  PORTB =~((0<<0)|(1<<1)|(0<<2)|(0<<3)|(0<<4));
}
void seg2_two()
{
  seg2_reset();
  PORTD =~((0<<2)|(1<<5)|(1<<6)|(0<<7));
  PORTB =~((0<<0)|(1<<1)|(1<<2)|(0<<3)|(1<<4));
}
void seg2_three()
{
  seg2_reset();
  PORTD =~((0<<2)|(0<<5)|(1<<6)|(1<<7));
  PORTB =~((0<<0)|(1<<1)|(1<<2)|(0<<3)|(1<<4));
}
void seg2_four()
{
  seg2_reset();
  PORTD =~((0<<2)|(0<<5)|(0<<6)|(1<<7));
  PORTB =~((0<<0)|(1<<1)|(0<<2)|(1<<3)|(1<<4));
}
void seg2_five()
{
  seg2_reset();
  PORTD =~((0<<2)|(0<<5)|(1<<6)|(1<<7));
  PORTB =~((0<<0)|(0<<1)|(1<<2)|(1<<3)|(1<<4));
}
void seg2_six()
{
  seg2_reset();
  PORTD =~((0<<2)|(1<<5)|(1<<6)|(1<<7));
  PORTB =~((0<<0)|(0<<1)|(1<<2)|(1<<3)|(1<<4));
}
void seg2_seven()
{
  seg2_reset();
  PORTD =~((0<<2)|(0<<5)|(0<<6)|(1<<7));
  PORTB =~((0<<0)|(1<<1)|(1<<2)|(0<<3)|(0<<4));
}
void seg2_eight()
{
  seg2_reset();
  PORTD =~((0<<2)|(1<<5)|(1<<6)|(1<<7));
  PORTB =~((0<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4));
}
void seg2_nine()
{
  seg2_reset();
  PORTD =~((0<<2)|(0<<5)|(1<<6)|(1<<7));
  PORTB =~((0<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4));
}
void seg2_num_test()
{
  #define del 100
  //zero
  seg2_zero();
  delay(del);
  //one
  seg2_one();
  delay(del);
  //two
  seg2_two();
  delay(del);
  //three
  seg2_three();
  delay(del);
  //four
  seg2_four();
  delay(del);
  //five
  seg2_five();
  delay(del);
  //six
  seg2_six();
  delay(del);
  //seven
  seg2_seven();
  delay(del);
  //eight
  seg2_eight();
  delay(del);
  //nine
  seg2_nine();
  delay(del);
  #undef del
}
//DOT
void seg2_dot_zero()
{
  seg2_reset();
  PORTD =~((0<<2)|(1<<5)|(1<<6)|(1<<7));
  PORTB =~((1<<0)|(1<<1)|(1<<2)|(1<<3)|(0<<4));
}
void seg2_dot_one()
{
  seg2_reset();
  PORTD =~((0<<2)|(0<<5)|(0<<6)|(1<<7));
  PORTB =~((1<<0)|(1<<1)|(0<<2)|(0<<3)|(0<<4));
}
void seg2_dot_two()
{
  seg2_reset();
  PORTD =~((0<<2)|(1<<5)|(1<<6)|(0<<7));
  PORTB =~((1<<0)|(1<<1)|(1<<2)|(0<<3)|(1<<4));
}
void seg2_dot_three()
{
  seg2_reset();
  PORTD =~((0<<2)|(0<<5)|(1<<6)|(1<<7));
  PORTB =~((1<<0)|(1<<1)|(1<<2)|(0<<3)|(1<<4));
}
void seg2_dot_four()
{
  seg2_reset();
  PORTD =~((0<<2)|(0<<5)|(0<<6)|(1<<7));
  PORTB =~((1<<0)|(1<<1)|(0<<2)|(1<<3)|(1<<4));
}
void seg2_dot_five()
{
  seg2_reset();
  PORTD =~((0<<2)|(0<<5)|(1<<6)|(1<<7));
  PORTB =~((1<<0)|(0<<1)|(1<<2)|(1<<3)|(1<<4));
}
void seg2_dot_six()
{
  seg2_reset();
  PORTD =~((0<<2)|(1<<5)|(1<<6)|(1<<7));
  PORTB =~((1<<0)|(0<<1)|(1<<2)|(1<<3)|(1<<4));
}
void seg2_dot_seven()
{
  seg2_reset();
  PORTD =~((0<<2)|(0<<5)|(0<<6)|(1<<7));
  PORTB =~((1<<0)|(1<<1)|(1<<2)|(0<<3)|(0<<4));
}
void seg2_dot_eight()
{
  seg2_reset();
  PORTD =~((0<<2)|(1<<5)|(1<<6)|(1<<7));
  PORTB =~((1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4));
}
void seg2_dot_nine()
{
  seg2_reset();
  PORTD =~((0<<2)|(0<<5)|(1<<6)|(1<<7));
  PORTB =~((1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4));
}
void seg2_dot_num_test()
{
  #define del 100
  //zero
  seg2_dot_zero();
  delay(del);
  //one
  seg2_dot_one();
  delay(del);
  //two
  seg2_dot_two();
  delay(del);
  //three
  seg2_dot_three();
  delay(del);
  //four
  seg2_dot_four();
  delay(del);
  //five
  seg2_dot_five();
  delay(del);
  //six
  seg2_dot_six();
  delay(del);
  //seven
  seg2_dot_seven();
  delay(del);
  //eight
  seg2_dot_eight();
  delay(del);
  //nine
  seg2_dot_nine();
  delay(del);
  #undef del
}
void two_seg(int a)
{
  #define del 8
  if(a<100&&a>-1)
  {
    int z=a%10;
    a=a/10;
    switch(z)
    {
      case 0:seg2_on();seg2_zero();delay(del);seg2_off();break;
      case 1:seg2_on();seg2_one();delay(del);seg2_off();break;
      case 2:seg2_on();seg2_two();delay(del);seg2_off();break;
      case 3:seg2_on();seg2_three();delay(del);seg2_off();break;
      case 4:seg2_on();seg2_four();delay(del);seg2_off();break;
      case 5:seg2_on();seg2_five();delay(del);seg2_off();break;
      case 6:seg2_on();seg2_six();delay(del);seg2_off();break;
      case 7:seg2_on();seg2_seven();delay(del);seg2_off();break;
      case 8:seg2_on();seg2_eight();delay(del);seg2_off();break;
      case 9:seg2_on();seg2_nine();delay(del);seg2_off();break;
    }
    switch(a)
    {
      case 0:seg1_on();seg1_zero();delay(del);seg1_off();break;
      case 1:seg1_on();seg1_one();delay(del);seg1_off();break;
      case 2:seg1_on();seg1_two();delay(del);seg1_off();break;
      case 3:seg1_on();seg1_three();delay(del);seg1_off();break;
      case 4:seg1_on();seg1_four();delay(del);seg1_off();break;
      case 5:seg1_on();seg1_five();delay(del);seg1_off();break;
      case 6:seg1_on();seg1_six();delay(del);seg1_off();break;
      case 7:seg1_on();seg1_seven();delay(del);seg1_off();break;
      case 8:seg1_on();seg1_eight();delay(del);seg1_off();break;
      case 9:seg1_on();seg1_nine();delay(del);seg1_off();break;
    }
    #undef del
  }
}
void two_seg_test()
{
  #define del 1
  pinMode(A0,1);
  digitalWrite(A0,1);
  unsigned long int timei =millis();
  unsigned long int timeo =1000;
  for(int i=0;i<99;i++)
  {
    digitalWrite(A0,0);
    while(1)
    {
    two_seg(i);
    unsigned long int time2 =millis()-timei;
    if(time2>timeo)
    {
      timeo+=1000;
      break;
    }
    digitalWrite(A0,1);
    delay(del);
    }
  digitalWrite(A0,0);
  }
  for(int i=99;i>-1;i--)
  {
    digitalWrite(A0,1);
    while(1)
    {
    two_seg(i);
    unsigned long int time2 =millis()-timei;
    if(time2>timeo)
    {
      timeo+=1000;
      break;
    }
    digitalWrite(A0,0);
    delay(del);
    }
  }
}











void seg3_on()
{
  DDRD =(1<<5)|(1<<6)|(1<<7);
  DDRB =(1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4)|(1<<5);
}
void seg3_off()
{
  DDRD =(0<<5)|(0<<6)|(0<<7);
  DDRB =(0<<0)|(0<<1)|(0<<2)|(0<<3)|(0<<4)|(0<<5);
}
void seg3_selftest()
{
  #define del 100
  PORTD =(1<<5)|(1<<6)|(1<<7);
  PORTB =(1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4)|(0<<5);
  delay(del);
  PORTD =(0<<5)|(1<<6)|(1<<7);
  delay(del);
  PORTD =(0<<5)|(0<<6)|(1<<7);
  delay(del);
  PORTD =(0<<5)|(0<<6)|(0<<7);
  delay(del);
  PORTB =(0<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4)|(0<<5);
  delay(100);
  PORTB =(0<<0)|(0<<1)|(1<<2)|(1<<3)|(1<<4)|(0<<5);
  delay(del);
  PORTB =(0<<0)|(0<<1)|(0<<2)|(1<<3)|(1<<4)|(0<<5);
  delay(100);
  PORTB =(0<<0)|(0<<1)|(0<<2)|(0<<3)|(1<<4)|(0<<5);
  delay(del);
  PORTB =(0<<0)|(0<<1)|(0<<2)|(0<<3)|(0<<4)|(0<<5);
  delay(del);
  PORTD =(1<<5)|(1<<6)|(1<<7);
  PORTB =(1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4)|(0<<5);
  delay(del);
  PORTD =(0<<5)|(0<<6)|(0<<7);
  PORTB =(0<<0)|(0<<1)|(0<<2)|(0<<3)|(0<<4)||(0<<5);
  delay(del);
  PORTD =(0<<5)|(0<<6)|(0<<7);
  PORTB =(0<<0)|(0<<1)|(0<<2)|(0<<3)|(0<<4)|(0<<5); 
  delay(del);
  #undef del
}
void seg3_reset()
{
  PORTD =(0<<2)|(0<<5)|(0<<6)|(0<<7);
  PORTB =(0<<0)|(0<<1)|(0<<2)|(0<<3)|(0<<4);
}
void seg3_zero()
{
  seg3_reset();
  PORTD =(0<<2)|(1<<5)|(1<<6)|(1<<7);
  PORTB =(0<<0)|(1<<1)|(1<<2)|(1<<3)|(0<<4);
}
void seg3_one()
{
  seg3_reset();
  PORTD =(0<<2)|(0<<5)|(0<<6)|(1<<7);
  PORTB =(0<<0)|(1<<1)|(0<<2)|(0<<3)|(0<<4);
}
void seg3_two()
{
  seg3_reset();
  PORTD =(0<<2)|(1<<5)|(1<<6)|(0<<7);
  PORTB =(0<<0)|(1<<1)|(1<<2)|(0<<3)|(1<<4);
}
void seg3_three()
{
  seg3_reset();
  PORTD =(0<<2)|(0<<5)|(1<<6)|(1<<7);
  PORTB =(0<<0)|(1<<1)|(1<<2)|(0<<3)|(1<<4);
}
void seg3_four()
{
  seg3_reset();
  PORTD =(0<<2)|(0<<5)|(0<<6)|(1<<7);
  PORTB =(0<<0)|(1<<1)|(0<<2)|(1<<3)|(1<<4);
}
void seg3_five()
{
  seg3_reset();
  PORTD =(0<<2)|(0<<5)|(1<<6)|(1<<7);
  PORTB =(0<<0)|(0<<1)|(1<<2)|(1<<3)|(1<<4);
}
void seg3_six()
{
  seg3_reset();
  PORTD =(0<<2)|(1<<5)|(1<<6)|(1<<7);
  PORTB =(0<<0)|(0<<1)|(1<<2)|(1<<3)|(1<<4);
}
void seg3_seven()
{
  seg3_reset();
  PORTD =(0<<2)|(0<<5)|(0<<6)|(1<<7);
  PORTB =(0<<0)|(1<<1)|(1<<2)|(0<<3)|(0<<4);
}
void seg3_eight()
{
  seg3_reset();
  PORTD =(0<<2)|(1<<5)|(1<<6)|(1<<7);
  PORTB =(0<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4);
}
void seg3_nine()
{
  seg3_reset();
  PORTD =(0<<2)|(0<<5)|(1<<6)|(1<<7);
  PORTB =(0<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4);
}
void seg3_num_test()
{
  #define del 100
  //zero
  seg3_zero();
  delay(del);
  //one
  seg3_one();
  delay(del);
  //two
  seg3_two();
  delay(del);
  //three
  seg3_three();
  delay(del);
  //four
  seg3_four();
  delay(del);
  //five
  seg3_five();
  delay(del);
  //six
  seg3_six();
  delay(del);
  //seven
  seg3_seven();
  delay(del);
  //eight
  seg3_eight();
  delay(del);
  //nine
  seg3_nine();
  delay(del);
}
//DOT
void seg3_dot_zero()
{
  seg3_reset();
  PORTD =(0<<2)|(1<<5)|(1<<6)|(1<<7);
  PORTB =(1<<0)|(1<<1)|(1<<2)|(1<<3)|(0<<4);
}
void seg3_dot_one()
{
  seg3_reset();
  PORTD =(0<<2)|(0<<5)|(0<<6)|(1<<7);
  PORTB =(1<<0)|(1<<1)|(0<<2)|(0<<3)|(0<<4);
}
void seg3_dot_two()
{
  seg3_reset();
  PORTD =(0<<2)|(1<<5)|(1<<6)|(0<<7);
  PORTB =(1<<0)|(1<<1)|(1<<2)|(0<<3)|(1<<4);
}
void seg3_dot_three()
{
  seg3_reset();
  PORTD =(0<<2)|(0<<5)|(1<<6)|(1<<7);
  PORTB =(1<<0)|(1<<1)|(1<<2)|(0<<3)|(1<<4);
}
void seg3_dot_four()
{
  seg3_reset();
  PORTD =(0<<2)|(0<<5)|(0<<6)|(1<<7);
  PORTB =(1<<0)|(1<<1)|(0<<2)|(1<<3)|(1<<4);
}
void seg3_dot_five()
{
  seg3_reset();
  PORTD =(0<<2)|(0<<5)|(1<<6)|(1<<7);
  PORTB =(1<<0)|(0<<1)|(1<<2)|(1<<3)|(1<<4);
}
void seg3_dot_six()
{
  seg3_reset();
  PORTD =(0<<2)|(1<<5)|(1<<6)|(1<<7);
  PORTB =(1<<0)|(0<<1)|(1<<2)|(1<<3)|(1<<4);
}
void seg3_dot_seven()
{
  seg3_reset();
  PORTD =(0<<2)|(0<<5)|(0<<6)|(1<<7);
  PORTB =(1<<0)|(1<<1)|(1<<2)|(0<<3)|(0<<4);
}
void seg3_dot_eight()
{
  seg3_reset();
  PORTD =(0<<2)|(1<<5)|(1<<6)|(1<<7);
  PORTB =(1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4);
}
void seg3_dot_nine()
{
  seg3_reset();
  PORTD =(0<<2)|(0<<5)|(1<<6)|(1<<7);
  PORTB =(1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4);
}
void seg3_dot_num_test()
{
  #define del 100
  //zero
  seg3_dot_zero();
  delay(del);
  //one
  seg3_dot_one();
  delay(del);
  //two
  seg3_dot_two();
  delay(del);
  //three
  seg3_dot_three();
  delay(del);
  //four
  seg3_dot_four();
  delay(del);
  //five
  seg3_dot_five();
  delay(del);
  //six
  seg3_dot_six();
  delay(del);
  //seven
  seg3_dot_seven();
  delay(del);
  //eight
  seg3_dot_eight();
  delay(del);
  //nine
  seg3_dot_nine();
  delay(del);
}
void three_seg(int a)
{
  #define del 2
  if(a<1000&&a>-1)
  {
    int z=a%10;
    a=a/10;
    switch(z)
    {
      case 0:seg3_on();seg3_zero();delay(del);seg3_off();break;
      case 1:seg3_on();seg3_one();delay(del);seg3_off();break;
      case 2:seg3_on();seg3_two();delay(del);seg3_off();break;
      case 3:seg3_on();seg3_three();delay(del);seg3_off();break;
      case 4:seg3_on();seg3_four();delay(del);seg3_off();break;
      case 5:seg3_on();seg3_five();delay(del);seg3_off();break;
      case 6:seg3_on();seg3_six();delay(del);seg3_off();break;
      case 7:seg3_on();seg3_seven();delay(del);seg3_off();break;
      case 8:seg3_on();seg3_eight();delay(del);seg3_off();break;
      case 9:seg3_on();seg3_nine();delay(del);seg3_off();break;
    }
    z=a%10;
    a=a/10;
    switch(z)
    {
      case 0:seg2_on();seg2_zero();delay(del);seg2_off();break;
      case 1:seg2_on();seg2_one();delay(del);seg2_off();break;
      case 2:seg2_on();seg2_two();delay(del);seg2_off();break;
      case 3:seg2_on();seg2_three();delay(del);seg2_off();break;
      case 4:seg2_on();seg2_four();delay(del);seg2_off();break;
      case 5:seg2_on();seg2_five();delay(del);seg2_off();break;
      case 6:seg2_on();seg2_six();delay(del);seg2_off();break;
      case 7:seg2_on();seg2_seven();delay(del);seg2_off();break;
      case 8:seg2_on();seg2_eight();delay(del);seg2_off();break;
      case 9:seg2_on();seg2_nine();delay(del);seg2_off();break;
    }
    switch(a)
    {
      case 0:seg1_on();seg1_zero();delay(del);seg1_off();break;
      case 1:seg1_on();seg1_one();delay(del);seg1_off();break;
      case 2:seg1_on();seg1_two();delay(del);seg1_off();break;
      case 3:seg1_on();seg1_three();delay(del);seg1_off();break;
      case 4:seg1_on();seg1_four();delay(del);seg1_off();break;
      case 5:seg1_on();seg1_five();delay(del);seg1_off();break;
      case 6:seg1_on();seg1_six();delay(del);seg1_off();break;
      case 7:seg1_on();seg1_seven();delay(del);seg1_off();break;
      case 8:seg1_on();seg1_eight();delay(del);seg1_off();break;
      case 9:seg1_on();seg1_nine();delay(del);seg1_off();break;
    }
    #undef del
  }
}
void three_seg_test()
{
  #define del 1
  pinMode(A0,1);
  digitalWrite(A0,1);
  unsigned long int timei =millis();
  unsigned long int timeo =1000;
  for(int i=0;i<999;i++)
  {
    digitalWrite(A0,0);
    while(1)
    {
    three_seg(i);
    unsigned long int time2 =millis()-timei;
    if(time2>timeo)
    {
      timeo+=1000;
      break;
    }
    digitalWrite(A0,1);
    delay(del);
    }
  digitalWrite(A0,0);
  }
  for(int i=999;i>-1;i--)
  {
    digitalWrite(A0,1);
    while(1)
    {
    three_seg(i);
    unsigned long int time2 =millis()-timei;
    if(time2>timeo)
    {
      timeo+=1000;
      break;
    }
    digitalWrite(A0,0);
    delay(del);
    }
  }
}










void seg4_on()
{
  PORTD = (1<<3)|(1<<5)|(1<<6)|(1<<7);
  PORTB = (1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4);
  DDRD =(1<<3)|(1<<5)|(1<<6)|(1<<7);
  DDRB =(1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4);
}
void seg4_off()
{
  DDRD =(0<<3)|(0<<5)|(0<<6)|(0<<7);
  DDRB =(0<<0)|(0<<1)|(0<<2)|(0<<3)|(0<<4);
}
void seg4_selftest()
{
  #define del 100
  PORTD =~((0<<3)|(1<5)|(1<<6)|(1<<7));
  PORTB =~((1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4));
  delay(del);
  PORTD =~((0<<3)|(0<<5)|(1<<6)|(1<<7));
  delay(del);
  PORTD =~((0<<3)|(0<<5)|(0<<6)|(1<<7));
  delay(del);
  PORTD =~((0<<3)|(0<<5)|(0<<6)|(0<<7));
  delay(del);
  PORTB =~((0<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4));
  delay(del);
  PORTB =~((0<<0)|(0<<1)|(1<<2)|(1<<3)|(1<<4));
  delay(del);
  PORTB =~((0<<0)|(0<<1)|(0<<2)|(1<<3)|(1<<4));
  delay(100);
  PORTB =~((0<<0)|(0<<1)|(0<<2)|(0<<3)|(1<<4));
  delay(del);
  PORTB =~((0<<0)|(0<<1)|(0<<2)|(0<<3)|(0<<4));
  delay(del);
  PORTD =~((0<<3)|(1<<5)|(1<<6)|(1<<7));
  PORTB =~((1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4));
  delay(del);
  PORTD =~((0<<3)|(0<<5)|(0<<6)|(0<<7));
  PORTB =~((0<<0)|(0<<1)|(0<<2)|(0<<3)|(0<<4));
  delay(del);
  PORTD =~((0<<3)|(0<<5)|(0<<6)|(0<<7));
  PORTB =~((0<<0)|(0<<1)|(0<<2)|(0<<3)|(0<<4));
  delay(del);
  #undef del
}
void seg4_reset()
{
  PORTD =~((0<<3)|(0<<5)|(0<<6)|(0<<7));
  PORTB =~((0<<0)|(0<<1)|(0<<2)|(0<<3)|(0<<4));
}
//DOT
void seg4_dot_zero()
{
  seg4_reset();
  PORTD =~((0<<3)|(1<<5)|(1<<6)|(1<<7));
  PORTB =~((1<<0)|(1<<1)|(1<<2)|(1<<3)|(0<<4));
}
void seg4_dot_one()
{
  seg4_reset();
  PORTD =~((0<<3)|(0<<5)|(0<<6)|(1<<7));
  PORTB =~((1<<0)|(1<<1)|(0<<2)|(0<<3)|(0<<4));
}
void seg4_dot_two()
{
  seg4_reset();
  PORTD =~((0<<3)|(1<<5)|(1<<6)|(0<<7));
  PORTB =~((1<<0)|(1<<1)|(1<<2)|(0<<3)|(1<<4));
}
void seg4_dot_three()
{
  seg4_reset();
  PORTD =~((0<<3)|(0<<5)|(1<<6)|(1<<7));
  PORTB =~((1<<0)|(1<<1)|(1<<2)|(0<<3)|(1<<4));
}
void seg4_dot_four()
{
  seg4_reset();
  PORTD =~((0<<3)|(0<<5)|(0<<6)|(1<<7));
  PORTB =~((1<<0)|(1<<1)|(0<<2)|(1<<3)|(1<<4));
}
void seg4_dot_five()
{
  seg4_reset();
  PORTD =~((0<<3)|(0<<5)|(1<<6)|(1<<7));
  PORTB =~((1<<0)|(0<<1)|(1<<2)|(1<<3)|(1<<4));
}
void seg4_dot_six()
{
  seg2_reset();
  PORTD =~((0<<3)|(1<<5)|(1<<6)|(1<<7));
  PORTB =~((1<<0)|(0<<1)|(1<<2)|(1<<3)|(1<<4));
}
void seg4_dot_seven()
{
  seg4_reset();
  PORTD =~((0<<3)|(0<<5)|(0<<6)|(1<<7));
  PORTB =~((1<<0)|(1<<1)|(1<<2)|(0<<3)|(0<<4));
}
void seg4_dot_eight()
{
  seg4_reset();
  PORTD =~((0<<3)|(1<<5)|(1<<6)|(1<<7));
  PORTB =~((1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4));
}
void seg4_dot_nine()
{
  seg4_reset();
  PORTD =~((0<<3)|(0<<5)|(1<<6)|(1<<7));
  PORTB =~((1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4));
}
void seg4_dot_num_test()
{
  #define del 100
  //zero
  seg4_dot_zero();
  delay(del);
  //one
  seg4_dot_one();
  delay(del);
  //two
  seg4_dot_two();
  delay(del);
  //three
  seg4_dot_three();
  delay(del);
  //four
  seg4_dot_four();
  delay(del);
  //five
  seg4_dot_five();
  delay(del);
  //six
  seg4_dot_six();
  delay(del);
  //seven
  seg4_dot_seven();
  delay(del);
  //eight
  seg4_dot_eight();
  delay(del);
  //nine
  seg4_dot_nine();
  delay(del);
}
//normal
void seg4_zero()
{
  seg4_reset();
  PORTD =~((0<<3)|(1<<5)|(1<<6)|(1<<7));
  PORTB =~((0<<0)|(1<<1)|(1<<2)|(1<<3)|(0<<4));
}
void seg4_one()
{
  seg4_reset();
  PORTD =~((0<<3)|(0<<5)|(0<<6)|(1<<7));
  PORTB =~((0<<0)|(1<<1)|(0<<2)|(0<<3)|(0<<4));
}
void seg4_two()
{
  seg4_reset();
  PORTD =~((0<<3)|(1<<5)|(1<<6)|(0<<7));
  PORTB =~((0<<0)|(1<<1)|(1<<2)|(0<<3)|(1<<4));
}
void seg4_three()
{
  seg4_reset();
  PORTD =~((0<<3)|(0<<5)|(1<<6)|(1<<7));
  PORTB =~((0<<0)|(1<<1)|(1<<2)|(0<<3)|(1<<4));
}
void seg4_four()
{
  seg4_reset();
  PORTD =~((0<<3)|(0<<5)|(0<<6)|(1<<7));
  PORTB =~((0<<0)|(1<<1)|(0<<2)|(1<<3)|(1<<4));
}
void seg4_five()
{
  seg4_reset();
  PORTD =~((0<<3)|(0<<5)|(1<<6)|(1<<7));
  PORTB =~((0<<0)|(0<<1)|(1<<2)|(1<<3)|(1<<4));
}
void seg4_six()
{
  seg2_reset();
  PORTD =~((0<<3)|(1<<5)|(1<<6)|(1<<7));
  PORTB =~((0<<0)|(0<<1)|(1<<2)|(1<<3)|(1<<4));
}
void seg4_seven()
{
  seg4_reset();
  PORTD =~((0<<3)|(0<<5)|(0<<6)|(1<<7));
  PORTB =~((0<<0)|(1<<1)|(1<<2)|(0<<3)|(0<<4));
}
void seg4_eight()
{
  seg4_reset();
  PORTD =~((0<<3)|(1<<5)|(1<<6)|(1<<7));
  PORTB =~((0<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4));
}
void seg4_nine()
{
  seg4_reset();
  PORTD =~((0<<3)|(0<<5)|(1<<6)|(1<<7));
  PORTB =~((0<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4));
}
void seg4_num_test()
{
  #define del 100
  //zero
  seg4_zero();
  delay(del);
  //one
  seg4_one();
  delay(del);
  //two
  seg4_two();
  delay(del);
  //three
  seg4_three();
  delay(del);
  //four
  seg4_four();
  delay(del);
  //five
  seg4_five();
  delay(del);
  //six
  seg4_six();
  delay(del);
  //seven
  seg4_seven();
  delay(del);
  //eight
  seg4_eight();
  delay(del);
  //nine
  seg4_nine();
  delay(del);
}
void four_seg(int a)
{
  #define del 300
  if(a<10000&&a>-1)
  {
    int z=a%10;
    a=a/10;
    switch(z)
    {
      case 0:seg4_on();seg4_zero();delayMicroseconds(del);seg4_off();break;
      case 1:seg4_on();seg4_one();delayMicroseconds(del);seg4_off();break;
      case 2:seg4_on();seg4_two();delayMicroseconds(del);seg4_off();break;
      case 3:seg4_on();seg4_three();delayMicroseconds(del);seg4_off();break;
      case 4:seg4_on();seg4_four();delayMicroseconds(del);seg4_off();break;
      case 5:seg4_on();seg4_five();delayMicroseconds(del);seg4_off();break;
      case 6:seg4_on();seg4_six();delayMicroseconds(del);seg4_off();break;
      case 7:seg4_on();seg4_seven();delayMicroseconds(del);seg4_off();break;
      case 8:seg4_on();seg4_eight();delayMicroseconds(del);seg4_off();break;
      case 9:seg4_on();seg4_nine();delayMicroseconds(del);seg4_off();break;
    }
    z=a%10;
    a=a/10;
    switch(z)
    {
      case 0:seg3_on();seg3_zero();delayMicroseconds(del);seg3_off();break;
      case 1:seg3_on();seg3_one();delayMicroseconds(del);seg3_off();break;
      case 2:seg3_on();seg3_two();delayMicroseconds(del);seg3_off();break;
      case 3:seg3_on();seg3_three();delayMicroseconds(del);seg3_off();break;
      case 4:seg3_on();seg3_four();delayMicroseconds(del);seg3_off();break;
      case 5:seg3_on();seg3_five();delayMicroseconds(del);seg3_off();break;
      case 6:seg3_on();seg3_six();delayMicroseconds(del);seg3_off();break;
      case 7:seg3_on();seg3_seven();delayMicroseconds(del);seg3_off();break;
      case 8:seg3_on();seg3_eight();delayMicroseconds(del);seg3_off();break;
      case 9:seg3_on();seg3_nine();delayMicroseconds(del);seg3_off();break;
    }
    z=a%10;
    a=a/10;
    switch(z)
    {
      case 0:seg2_on();seg2_zero();delayMicroseconds(del);seg2_off();break;
      case 1:seg2_on();seg2_one();delayMicroseconds(del);seg2_off();break;
      case 2:seg2_on();seg2_two();delayMicroseconds(del);seg2_off();break;
      case 3:seg2_on();seg2_three();delayMicroseconds(del);seg2_off();break;
      case 4:seg2_on();seg2_four();delayMicroseconds(del);seg2_off();break;
      case 5:seg2_on();seg2_five();delayMicroseconds(del);seg2_off();break;
      case 6:seg2_on();seg2_six();delayMicroseconds(del);seg2_off();break;
      case 7:seg2_on();seg2_seven();delayMicroseconds(del);seg2_off();break;
      case 8:seg2_on();seg2_eight();delayMicroseconds(del);seg2_off();break;
      case 9:seg2_on();seg2_nine();delayMicroseconds(del);seg2_off();break;
    }
    switch(a)
    {
      case 0:seg1_on();seg1_zero();delayMicroseconds(del);seg1_off();break;
      case 1:seg1_on();seg1_one();delayMicroseconds(del);seg1_off();break;
      case 2:seg1_on();seg1_two();delayMicroseconds(del);seg1_off();break;
      case 3:seg1_on();seg1_three();delayMicroseconds(del);seg1_off();break;
      case 4:seg1_on();seg1_four();delayMicroseconds(del);seg1_off();break;
      case 5:seg1_on();seg1_five();delayMicroseconds(del);seg1_off();break;
      case 6:seg1_on();seg1_six();delayMicroseconds(del);seg1_off();break;
      case 7:seg1_on();seg1_seven();delayMicroseconds(del);seg1_off();break;
      case 8:seg1_on();seg1_eight();delayMicroseconds(del);seg1_off();break;
      case 9:seg1_on();seg1_nine();delayMicroseconds(del);seg1_off();break;
    }
    #undef del
  }
}
void four_seg_test()
{
  #define del 1
  pinMode(A0,1);
  digitalWrite(A0,1);
  unsigned long int timei =millis();
  unsigned long int timeo =1000;
  for(int i=0;i<9999;i++)
  {
    digitalWrite(A0,0);
    while(1)
    {
    four_seg(i);
    unsigned long int time2 =millis()-timei;
    if(time2>timeo)
    {
      timeo+=1000;
      break;
    }
    digitalWrite(A0,1);
    delay(del);
    }
  digitalWrite(A0,0);
  }
  for(int i=9999;i>-1;i--)
  {
    digitalWrite(A0,1);
    while(1)
    {
    four_seg(i);
    unsigned long int time2 =millis()-timei;
    if(time2>timeo)
    {
      timeo+=1000;
      break;
    }
    digitalWrite(A0,0);
    delay(del);
    }
  }
}









void four_seg_print_Vcc()
{
  #define sps 0.1 //Samples per second
  int vcc=readVcc();
  unsigned long int timei =millis();
  unsigned long int timeo =500;
  while(1)
    {
    four_seg(vcc);
    unsigned long int time2 =millis()-timei;
    if(time2>timeo)
    {
      timeo+=(1000*sps);
      break;
    }
    }
} 













void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A0,1);
}
#define del 1
int i=0;
int flag=0;
void loop() {
  seg1_on();
  seg1_dot_num_test();
  seg2_on();
  seg2_dot_num_test();
  seg3_on();
  seg3_dot_num_test();
  seg4_on();
  seg4_dot_num_test();
  //four_seg(1245);
  while(1)
  {
    four_seg_print_Vcc();
  }
}
