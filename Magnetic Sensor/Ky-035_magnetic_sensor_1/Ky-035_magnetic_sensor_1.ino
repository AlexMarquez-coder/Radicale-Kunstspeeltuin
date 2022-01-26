/*
* Arduino and KY-035 module
* KY-035 analog output.
* Analog read
* Geen magnetisch veld: +/- 525
* Pos. magneet 
*     2 cm afstand 550  verschil +25
*     1 cm afstand 605  verschil +80
*     
* Min. magneet
*     2 cm afstand 511  verschil -14
*     1 cm afstand 480  verschil -65
*/

// Analoog magneet sensor
const int sensor1 = A0 ;  
const int sensor2 = A1 ; 
const int sensor3 = A4 ;

// GEEFT INDICATIE JUISTE ANTWOORD
const int led1 = 12; 
const int led2 = 4;
const int led3 = 13;


// DE FUNCTIE OM DE HALLSENSOR TE LEZEN
bool readMagnSensor (int sensor){
  int value = analogRead(sensor);
  bool returnStatus;

  // HIER GEBRUIK JE DE OUTPUT WAARDEN VAN DE HALL SENSOR OM TE 
  // BEPALEN OF DE MAGNEET IN DE BUURT IS OF NIET
  if (value < 510 || value > 550){
    returnStatus = true;
    }
  else{
    returnStatus = false;
    }

  // ALS DEBUG OP TRUE STAAT DAN PRINT DE OUTPUT 
  // WAARDE VAN DE SENSOR NAAR DE MONITOR 
  if(debug){
   // Serial.print(sensor);
   // Serial.print(returnStatus);
    Serial.println(value);
    }
  return returnStatus;
  }

void setup ()
{
  // HIER MEE ACTIVEER JE DE INGANG EN UITGANG VAN DE ARDUINO 
  Serial.begin(9600); // initialize serial
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop ()
{
  // DIT ZORGT ER VOOR ALS JE DE MAGNEET SENSOR BIJ DE MAGNEET HOUD
  // DAN GAAT DE DE LED LICHT BRANDEN EN ANDERS GAAT DIE UIT

  // sensor 1 led 1 
  if (readMagnSensor(sensor1)){
    digitalWrite(led1, HIGH);
    }
  else{
      digitalWrite(led1, LOW);
    }
    
  // sensor 2 led 2
    if (readMagnSensor(sensor2)){
    digitalWrite(led2, HIGH);
    }
  else{
    digitalWrite(led2, LOW);
    }
    
    // sensor 3 led 3
    if (readMagnSensor(sensor3)){
    digitalWrite(led3, HIGH);
    }
  else{
    digitalWrite(led3, LOW);
    }
}
