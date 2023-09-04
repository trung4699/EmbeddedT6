#define Rx 7
#define Tx 6


bool checkStartCondition = false;
bool checkStopCondition = true;

uint8_t dataReceive = 0x00;
uint8_t sizeDataReceive = 0;

bool checkParityBit = false;

uint8_t dataSend = 0x00;
uint8_t sizeDataSend = 0;
uint8_t data_value = 2;

void uartInit()
{
  pinMode(Rx, INPUT);
  pinMode(Tx, OUTPUT);  
}

void checkStart()
{
  if (digitalRead(Rx) == HIGH)
  {
    delay(10);
    if (digitalRead(Rx) == LOW)
    {
      checkStartCondition = true;
      checkStopCondition = false;
      Serial.println("Start");
    }
  }
}

void readData()
{
  delay(30);
  Serial.print("Get bit data: ");
  if (sizeDataReceive < 8)
  {
    dataReceive = dataReceive << 1;
    dataReceive = dataReceive | digitalRead(Rx);
    Serial.println(digitalRead(Rx));
    ++sizeDataReceive;
  }
  

}

void checkParity()
{
  uint8_t x = 0x00;
  uint8_t dataCheckParity = dataReceive;
  uint8_t countBit1 = 0;
  
  
  for (int i = 0; i < 8; ++i)
  {
    x = dataCheckParity & 0x80;
    if ( x > 0 )
    {
      ++countBit1;
    }
    dataCheckParity = dataCheckParity << 1;
  }

  delay(30);

  if ( (countBit1 % 2) == digitalRead(Rx) )
  {
    checkParityBit = true;
    Serial.println("Check parity bit true");
  }
  else
  {
    checkParityBit = false;
    dataReceive = 0x00;
    sizeDataReceive = 0;
    Serial.println(countBit1);
    Serial.println(digitalRead(Rx));
    Serial.println("Check parity bit false");
  }
}

void checkStop()
{
  checkParityBit = false;
  delay(20);
  if ( digitalRead(Rx) == HIGH )
  {
    delay(40);
    if (digitalRead(Rx) == LOW)
    {   
       checkStartCondition = false;
       checkStopCondition = true;
       Serial.println("Stop");
    }
    else
    {
      Serial.println("Check stop second condition not true");
    }
    
  }
  else
  {
    Serial.println("Check stop first condition not true");
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  uartInit();

}

void loop() {
  // put your main code here, to run repeatedly:
  if (checkStartCondition == false)
  {
    checkStart();
  }

  if (checkStartCondition == true && sizeDataReceive < 8)
  {
    readData();
  }

  if (checkStartCondition == true && sizeDataReceive == 8)
  {
    checkParity();
  }

  if (checkParityBit == true)
  {
    Serial.print("Data receive: ");
    Serial.println(dataReceive);
    dataReceive = 0x00;
    sizeDataReceive = 0;
    checkStop();
  }

  

  

}
