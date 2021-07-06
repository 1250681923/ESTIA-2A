******** Global variables and functions declaration ****************/

int count_tours;
int cot;
int time;
void interrupt()                                  /***interrupt pour changer les sens ***/
{
      if(INTCON.RBIF == 1)
      {
         if(PORTB.RB1 == 1)     //le capteur
         {
            count_tours ++ ;
         }
         INTCON.RBIF = 0;
      }
      if(INT0IF_bit)      // debortement
      {
         time ++;
         INT0IF_bit = 0;
      }
      if(time > 123)    //une seconde
      {
         cot = count_tours;       // cot: vitesse de la rotation par seconde
         count_tours = 0;
      } 
}
/*******************************************************************************
                                 Main Function
*******************************************************************************/

void main() 
{

  /***** Declaration and initialisation of variables *****/

int count_tours;
int cot;
int time;
  
  /********** E/S compteur*********/
  PORTA = 0;                        
  PORTB = 0;
  PORTC = 0;
  PORTE = 0;
  TRISB.TRISB1 = 1;       // RB3 : entree du interrupt
  ANSELH.ANS10 = 0;
  TRISA.TRISA1 = 0;        // 3 leds pour afficher les infors       
  TRISA.TRISA2 = 0;               
  TRISA.TRISA3 = 0;
  ANSEL.ANS1 = 0;  
  ANSEL.ANS2 = 0; 
  ANSEL.ANS3 = 0; 
  PORTA.RA1 = 0;      //initialisation des leds
  PORTA.RA2 = 0;
  PORTA.RA3 = 0;
 /********** interrupt configuration compteur *********/
  IOCB = 0;           // others are
  IOCB.IOCB1 = 1;     //
  INTCON.GIE = 1;
  INTCON.RBIF = 0;
  INTCON.RBIE = 1;
  INTCON.T0IE = 1;
  INTCON.T0IF = 1;
 
/***** Timer Configuration *****/
  OPTION_REG.PS0 = 1;   // on choisi  PS <2:0>   1：64   ： N_debortement = 123
  OPTION_REG.PS1 = 0;
  OPTION_REG.PS2 = 1;
  OPTION_REG.PSA = 0;  // Prescaler is assigned to the Timer0 module
  OPTION_REG.T0CS = 0;   //Internal instruction cycle clock (Fosc/4)




/********************************** Main Loop *********************************/

do
{
if(cot = 0)
{  
PORTE.RE0 = 0;    
PORTE.RE1 = 0;
PORTE.RE2 = 0;
}
if(cot = 1)
{  
PORTE.RE0 = 1;    
PORTE.RE1 = 0;
PORTE.RE2 = 0;
}
if(cot = 2)
{  
PORTE.RE0 = 1;    
PORTE.RE1 = 1;
PORTE.RE2 = 0;
}
if(cot >= 3)
{  
PORTE.RE0 = 1;    
PORTE.RE1 = 1;
PORTE.RE2 = 1;
}
} while(1);
}