int xsensor[5]={0,0,0,0,0};
int sensor[5]={A0,A1,A2,A3,A4};
float mcpsensor[5]={0.0,0.0,0.0,0.0,0.0};
float pipsensor[5]={0.0,0.0,0.0,0.0,0.0};

String val="";
void setup() {
 Serial.begin(9600); // put your setup code here, to run once:
pinMode(sensor[0],INPUT);
pinMode(sensor[1],INPUT);
pinMode(sensor[2],INPUT);
pinMode(sensor[3],INPUT);
pinMode(sensor[4],INPUT);
}

void loop() {
 


  while (Serial.available()==0)  
  {                                       //Wait for user input  
    
  }  
   val=Serial.readString();
 

  if(val=="pip")
  {
     
    while(1)
{

 
 
  xsensor[0]=analogRead(sensor[0]);
  xsensor[1]=analogRead(sensor[1]);
  xsensor[2]=analogRead(sensor[2]);
  xsensor[3]=analogRead(sensor[3]);
  xsensor[4]=analogRead(sensor[4]);    
   pipsensor[4]=(0.001148 *xsensor[4]*xsensor[4])-(1.625*xsensor[4])+554;
  pipsensor[3]=(-0.002908*xsensor[3]*xsensor[3])+(2.059*xsensor[3])-264.6;
  pipsensor[2]=( -0.002278*xsensor[2]*xsensor[2])+(1.31*xsensor[2])-83.43;
 // pipsensor[]=( *xsensor*xsensor)-(*xsensor) (not caliberated)
  pipsensor[0]=( 0.0007476*xsensor[0]*xsensor[0])-(1.021*xsensor[0])+317;

   Serial.print(xsensor[0]);
     Serial.print(",");
     Serial.print(pipsensor[0]); 
     Serial.print(",");
     Serial.print(xsensor[1]);
     Serial.print(",");
     Serial.print(pipsensor[1]); 
     Serial.print(",");
Serial.print(xsensor[2]);
     Serial.print(",");
     Serial.print(pipsensor[2]);
      Serial.print(",");
     Serial.print(xsensor[3]);
     Serial.print(","); 
     Serial.print(pipsensor[3]); 
     Serial.print(",");
     Serial.print(xsensor[4]);
     Serial.print(",");
     Serial.println(pipsensor[4]); 
    
}    
  }
    else if(val=="mcp")
  {
 while(1)  
 {
  xsensor[0]=analogRead(sensor[0]);
  xsensor[1]=analogRead(sensor[1]);
  xsensor[2]=analogRead(sensor[2]);
  xsensor[3]=analogRead(sensor[3]);
  xsensor[4]=analogRead(sensor[4]); 
  //curve obtain using matlab
  mcpsensor[4]=(-0.003187*xsensor[4]*xsensor[4])-(0.2601*xsensor[4])+214;
  mcpsensor[3]=( 0.00128*xsensor[3]*xsensor[3])-(1.698*xsensor[3])+544.9;
  mcpsensor[2]=(0.003803*xsensor[2]*xsensor[2])-(4.088*xsensor[2])+1098;
   mcpsensor[1]=(0.003803*xsensor[1]*xsensor[1])-(4.088*xsensor[1])+1098;
  mcpsensor[0]=( 0.0003135*xsensor[0]*xsensor[0])- (0.7166*xsensor[0])+275.7;
  
 

     Serial.print(xsensor[0]);
     Serial.print(",");
     Serial.print(mcpsensor[0]); 
     Serial.print(",");
      Serial.print(xsensor[1]);
     Serial.print(",");
     Serial.print(mcpsensor[1]); 
     Serial.print(",");
      Serial.print(xsensor[2]);
     Serial.print(",");
     Serial.print(mcpsensor[2]); 
     Serial.print(",");
      Serial.print(xsensor[3]);
     Serial.print(",");
     Serial.print(mcpsensor[3]); 
     Serial.print(",");
      Serial.print(xsensor[4]);
     Serial.print(",");
     Serial.println(mcpsensor[4]); 
 }    
  }
      else
      {
      Serial.println("error");
        }
}
