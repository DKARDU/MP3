void led_UP(){
 if(volume==0){
       setColor(0,0,0);
  }
      if(volume==1){
      setColor(255,0,255);
     }
        if(volume==4){
       setColor(0,0,255);
        }
    if(volume == 9){
       setColor(0,255,0);
  }
      if(volume == 14){
       setColor(255,255,0);
  }
   if(volume == 19){
       setColor(0,255,255);
  }
   if(volume == 24){
       setColor(255,0,0);
  }
   if(volume==29){
       setColor(0,0,255);
   }
}

void led_DOWWN(){
 if(volume== 0){
       setColor(0,0,0);
  }
      if(volume== 4){
      setColor(255,0,255);
     }
        if(volume == 9){
       setColor(0,0,255);
        }
    if(volume == 14){
       setColor(0,255,0);
  }
      if(volume ==19){
       setColor(255,255,0);
  }
   if(volume == 24){
       setColor(0,255,255);
  }
   if(volume == 29){
       setColor(255,0,0);
  }
 
}
void leftButtonISR()
{
  led_UP();
 static unsigned long last_interrupt_time = 0;
 unsigned long interrupt_time = millis();
 // If interrupts come faster than 150ms, assume it's a bounce and ignore
 if (interrupt_time - last_interrupt_time > 150)
 {
  updateScreen = true;  
  if(inSideMenuSelection && sMenuSelection < 2)
  {
   sMenuSelection++;
  }
  else if(selection < 4 && sMenuSelection == 1)
  {
     selection++; 
  }
  else if(selection == 1 && volume < 30 &&sMenuSelection == 2 && !inSideMenuSelection)
  {
     volume++; 
  }
  else if(selection == 2 && eq < 5 && sMenuSelection == 2 && !inSideMenuSelection)
  {
     eq++; 
  }
 }
 last_interrupt_time = interrupt_time;
}

void rightButtonISR()
{
  led_DOWWN();
 static unsigned long last_interrupt_time = 0;
 unsigned long interrupt_time = millis();
 // If interrupts come faster than 150, assume it's a bounce and ignore
 if (interrupt_time - last_interrupt_time > 150)
 {
  updateScreen = true;  
  if(inSideMenuSelection && sMenuSelection > 1)
  {
   sMenuSelection--;  
  }
  else if(selection > 1 && sMenuSelection == 1)
  {
    selection--;  
  }
  else if(selection == 1 && volume > 0 &&sMenuSelection == 2)
  {
     volume--; 
  }
  else if(selection == 2 && eq > 0 && sMenuSelection == 2)
  {
     eq--; 
  }
 }
 last_interrupt_time = interrupt_time;
}
