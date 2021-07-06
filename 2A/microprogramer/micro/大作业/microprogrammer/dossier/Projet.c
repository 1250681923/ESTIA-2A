bit Change_sens;
int count_tours;
int cot;
int time;
void interrupt()       /***interrupt pour changer les sens et counter les tours***/
{
      if(INTCON.RBIF == 1)
      {
        if(PORTB.RB5 == 1|PORTB.RB4 == 1|PORTB.RB3 == 1)
        {
           Change_sens = 1;
        }
        if(PORTB.RB1 == 1)     //le capteur de la rotation
        {
           count_tours ++ ;
        }
        INTCON.RBIF = 0;
      }
// Timer0
      if(INT0IF_bit)      // debortement
      {
         time ++;
         if(time > 123)    //une seconde
           {
            cot = count_tours;       // cot: vitesse de la rotation par seconde
            count_tours = 0;
           } 
         INT0IF_bit = 0;
      }
}



unsigned ReadADC1 (void);       /**** Commencer ADC pour les capteurs distances **/
unsigned ReadADC2 (void);



void main() {

/***** Declaration and initialisation of variables *****/


  unsigned res1 = 0;                // result of analog to digital conversion
  unsigned res2 = 0;
  int count_tours;
  int cot;
  int time;
/***** Declaration and initialisation of variables *****/

Change_sens = 0;

PORTA = 0;
PORTB = 0;
PORTC = 0;
PORTD = 0;
/** configuration pour la changement du sens **/
TRISB.TRISB5 = 1;     /** Deux entree pour changer les sens****/
TRISB.TRISB4 = 1;
ANSELH.ANS11 = 0;    /** Deux entree numeriques***/
ANSELH.ANS13 = 0;
TRISA.TRISA1 = 0;   /***Deux sorties pour afficher l'information de sens ***/
TRISA.TRISA2 = 0;
ANSEL.ANS1 = 0;
ANSEL.ANS2 = 0;
TRISB.TRISB3 = 1;  /*** pour arrete**/
ANSELH.ANS9 = 0;
PORTA.RA1 = 0;    /****** sens initial****/
PORTA.RA2 = 0;
/**** interrupt configuration ****/
IOCB = 0;
IOCB.IOCB5 = 1;
IOCB.IOCB4 = 1;
IOCB.IOCB3 = 1;
INTCON.RBIE = 1;
INTCON.RBIF = 0;
INTCON.GIE = 1;





/** configuration pour les capteurs de vitesse**/
TRISA.TRISA0 = 1;
TRISB.TRISB0 = 1;     /**A0 est l'entree de ADC**/
ANSEL.ANS0 = 1;
ANSELH.ANS12 = 1;
/** 8 sorties pour realiser la vitesse sera proportionnelle a la distance d mesuree**/
TRISC.TRISC0 = 0;
TRISC.TRISC1 = 0;
TRISC.TRISC2 = 0;
TRISC.TRISC3 = 0;
TRISC.TRISC4 = 0;
TRISC.TRISC5 = 0;
TRISC.TRISC6 = 0;
TRISC.TRISC7 = 0;

/***ADC  ADCON configuration **/
  ADCON0.ADCS0 = 0;        /**ADCS1 = 1 ADCS0 = 0  C-a-dire 8HZ 32bits**/
  ADCON0.ADCS1 = 1;
  ADCON0.CHS0 = 0;      /**entree est A0, du coup 0000*/
  ADCON0.CHS1 = 0;
  ADCON0.CHS2 = 0;
  ADCON0.CHS3 = 0;
  ADCON0.GO = 0;     /**GO DONE = 0     **/
  ADCON0.ADON = 1;    /**ADON = 1 ADC is enable**/

  ADCON1.VCFG0 = 0;           /** l'entree**/
  ADCON1.VCFG1 = 0;           /** connecter la masse**/
  ADCON1.ADFM = 1;        /**ADFM = 1 **/

/***** Configuration des comparateurs *****/

  C1ON_bit = 0;                    // Disable all comparators
  C2ON_bit = 0;                    //PWM


/***configuration pour messurer la vitesse de la rotation***/
  TRISB.TRISB1 = 1;       // RB1 : entree du interrupt
  ANSELH.ANS10 = 0;
  TRISD.TRISD0 = 0;
  TRISD.TRISD1 = 0;
  TRISD.TRISD2 = 0;
  TRISD.TRISD3 = 0;
  TRISD.TRISD4 = 0;
  TRISD.TRISD5 = 0;
  TRISD.TRISD6 = 0;
  TRISD.TRISD7 = 0;

  IOCB.IOCB1 = 1;    // RB1 : interrupt pour counter les tours

/***** Timer Configuration *****/
  INTCON.T0IE = 1;  
  INTCON.T0IF = 1;
  OPTION_REG.PS0 = 1;   // on choisi  PS <2:0>   1：64   ： N_debortement = 123
  OPTION_REG.PS1 = 0;
  OPTION_REG.PS2 = 1;
  OPTION_REG.PSA = 0;  // Prescaler is assigned to the Timer0 module
  OPTION_REG.T0CS = 0;   //Internal instruction cycle clock (Fosc/4)












do
{
   res1 = ReadADC1();
   res2 = ReadADC2();
   if(Change_sens == 1 && PORTB.RB5 == 1 && PORTB.RB4 == 0)            /**** Changer les sens ***/
   {
     PORTA.RA2 = 1;
     PORTA.RA1 = 0;
     Change_sens = 0;
   }
   if(Change_sens == 1 && PORTB.RB4 == 1 && PORTB.RB5 == 0)
   {
     PORTA.RA2 = 0;
     PORTA.RA1 = 1;
     Change_sens = 0;
   }
    if(Change_sens == 1 && PORTB.RB3 == 1)
   {
     PORTA.RA2 = 0;
     PORTA.RA1 = 0;
     Change_sens = 0;
   }
   
    /***On choisi dmax est 80% de distance total **  dmin est 20% de distance total**/
    if(res1 < 50)
   {
     PORTC.RC0 = 0;
     PORTC.RC1 = 0;
     PORTC.RC2 = 0;
     PORTC.RC3 = 0;
   }
   if(51 <= res1 && res1 < 100)
   {
     PORTC.RC0 = 1;
     PORTC.RC1 = 0;
     PORTC.RC2 = 0;
     PORTC.RC3 = 0;
   }
   if(101 <= res1 && res1 < 150)
   {
     PORTC.RC0 = 1;
     PORTC.RC1 = 1;
     PORTC.RC2 = 0;
     PORTC.RC3 = 0;
   }
   if(151 <= res1 && res1 < 200)
   {
     PORTC.RC0 = 1;
     PORTC.RC1 = 1;
     PORTC.RC2 = 1;
     PORTC.RC3 = 0;
   }
   if(res1 >= 200)
   {
     PORTC.RC0 = 1;
     PORTC.RC1 = 1;
     PORTC.RC2 = 1;
     PORTC.RC3 = 1;
   }
   if(res2 < 50)
   {
     PORTC.RC4 = 0;
     PORTC.RC5 = 0;
     PORTC.RC6 = 0;
     PORTC.RC7 = 0;
   }
   if(51 <= res2 && res2 < 100)
   {
     PORTC.RC4 = 1;
     PORTC.RC5 = 0;
     PORTC.RC6 = 0;
     PORTC.RC7 = 0;
   }
   if(101 <= res2 && res2 < 150)
   {
     PORTC.RC4 = 1;
     PORTC.RC5 = 1;
     PORTC.RC6 = 0;
     PORTC.RC7 = 0;
   }
   if(151 <= res2 && res2 < 200)
   {
     PORTC.RC4 = 1;
     PORTC.RC5 = 1;
     PORTC.RC6 = 1;
     PORTC.RC7 = 0;
   }
   if(res2 >= 200)
   {
     PORTC.RC4 = 1;
     PORTC.RC5 = 1;
     PORTC.RC6 = 1;
     PORTC.RC7 = 1;


   PORTD = cot;

}while(1);
}











unsigned ReadADC1(){
  unsigned res1;

  ADCON0.CHS0 = 0;      /**entree est A0, du coup 0000*/
  ADCON0.CHS1 = 0;
  ADCON0.CHS2 = 0;
  ADCON0.CHS3 = 0;

  Delay_us(4);

  ADCON0.GO = 1;      // start conversion comme go
  while(ADCON0.GO == 1){};
  res1 = ADRESH * 256 + ADRESL;
  return res1;
}


unsigned ReadADC2() {
  unsigned res2;
  ADCON0.CHS0 = 0;      //entree est B0, du coup 1100
  ADCON0.CHS1 = 0;
  ADCON0.CHS2 = 1;
  ADCON0.CHS3 = 1;

  Delay_us(4);


  ADCON0.GO = 1;      // start conversion comme go
  while(ADCON0.GO == 1){};

  res2 = ADRESH * 256 + ADRESL;
  return res2;
}
