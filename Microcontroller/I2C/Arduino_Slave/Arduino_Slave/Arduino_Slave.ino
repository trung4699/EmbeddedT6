/*
  File: Arduino_Slave.ino
  Author: Phan Hoang Trung
  Date: 05/09/2023
  Description: Coding bit - bangging I2C protocol. This file is for an arduino as a slave
*/

//Bus I2C
#define SDA 4
#define SCL 3
//Bit Write/Read
#define WRITE 0
#define READ 1
//Address
#define ADDRESS 0x6E

uint8_t dataReceive = 0x00;  //Data receive from Master
uint8_t sizeDataReceive = 0;     // Size data receive from Master

uint8_t frameAddress = 0x00;//frame address include 7 bit address of slave, 1 bit mode read/write
uint8_t sizeFrameAddress = 0;//size of frame address;
uint8_t readOrWrite;//Lưu chế độ

uint8_t dataSend = 0x00; //Data send to Master
uint8_t sizeDataSend = 0;//Size of data send to master
uint8_t data_value = 21;

bool checkStart = false;//Variable check start status
bool checkStop = true;  //Variable check stop status
bool checkAddress = false;  //Variable check address status


unsigned long start_time ; // This variable is used for replace delay function incase delay doesn't work

/*
  Function: i2cInit
  Description: Initialize i2c protocol
  Input:
    No input
  Output:
    No return
*/
void i2cInit()
{
  pinMode(SDA, INPUT);
  pinMode(SCL, INPUT);
}


/*
  Function: delayUsingMillis
  Description: using this function incase delay doesn't work
  Input:
    No input
  Output:
    No return
*/
void delayUsingMillis(unsigned long timeDelay)
{
  start_time = millis();
  
  
  while(millis() - start_time <= timeDelay)
  {
    Serial.print("Delay: ");
    Serial.println(millis() - start_time);
  }
}

/*
  Function: checkStopCondition
  Description: check stop condition 
  Input:
    No input
  Output:
    No return
*/

      
volatile void checkStopCondition()
{
  delay(30);
  if (digitalRead(SCL) == HIGH && digitalRead(SDA) == LOW) 
  {
      delay(30);
      Serial.println("Check stop condition");
      if (digitalRead(SCL) == HIGH && digitalRead(SDA) == HIGH) 
      {
        Serial.println("Stop");
        checkStart = false;
        checkAddress = false;
        checkStop = true;
        frameAddress = 0x00;
        sizeFrameAddress = 0;
      }
      else
      {
        Serial.println("Stop second condition not true");
      }
   }
   else
   {
     Serial.println("Stop first condition not true");
   }
   
  
}


/*
  Function: writeData
  Description: send data in slave to master
  Input:
    No input
  Output:
    No return
*/

volatile void writeData() {
  
  pinMode(SDA, OUTPUT);
  uint8_t x = 0;
  
  if (sizeDataSend < 8) 
  {
    x = dataSend & 0x80;
    if ( x > 0)
    {
      digitalWrite(SDA, HIGH);
    }
    else
    {
      digitalWrite(SDA, LOW);
    }
    dataSend = dataSend << 1;
    ++sizeDataSend;
  }
}

/*
  Function: readData
  Description: read data receive from master
  Input:
    No input
  Output:
    No return
*/

volatile void readData() {
    
    if (sizeDataReceive < 8)
    {
      dataReceive = dataReceive << 1;
      dataReceive = dataReceive | digitalRead(SDA);
      ++sizeDataReceive;
    }
}


/*
  Function: checkStartCondition
  Description: check start condition 
  Input:
    No input
  Output:
    No return
*/
volatile void checkStartCondition()
{
  if (digitalRead(SDA) == LOW)
  {
    checkStart = true;
    checkStop = false;
    Serial.println("Start");
  }
    
}

/*
  Function: interruptSCL
  Description: This function will run when has a change voltage in SCL pin
  Input:
    No input
  Output:
    No return
*/

volatile void interruptSCL() {
  //Check start condition
  if (checkStart == false && checkStop == true)
  {
    checkStartCondition();
    return;
  }

  // If address receive from master
  if (checkStart == true && checkAddress == false)
  {
    if ( sizeFrameAddress < 8)
    {
      
      frameAddress = frameAddress << 1;
      frameAddress = frameAddress | digitalRead(SDA);
      
      ++sizeFrameAddress;
      return;
    }
  }
  
  //Check stop condition, then check mode read/write
  if (checkStart == true && checkAddress == true)
  {
      if (checkStop == false)
      {
          if (readOrWrite == READ)
          {
            writeData();
          }
          else if (readOrWrite == WRITE)
          {
            readData();  
          }
      }
  }

  
  
}

void setup() {
  Serial.begin(9600);
  i2cInit();
  dataSend = data_value;
  attachInterrupt(1, interruptSCL, FALLING); // run interrupt function when has a change voltage from HIGH to LOW
  
}

void loop(){

  // if receive enough 8 bit frame address, compare 7 bit address with address of this slave.
  // if true, return an ACK signal, determine mode.
  // else do nothing
  if (sizeFrameAddress == 8)
  {
      Serial.print("Frame address from master: ");
      Serial.println((int)frameAddress);
      if ( (frameAddress  & 0xFE) == (ADDRESS << 1) )
      {
        pinMode(SDA, OUTPUT);
        digitalWrite(SDA, LOW);
        delay(60);
        pinMode(SDA, INPUT);
        checkAddress = true;
        
        Serial.println((int)frameAddress);
        readOrWrite = frameAddress & 0x01;
        Serial.print("Read or write: ");
        Serial.println(readOrWrite);
        sizeFrameAddress = 0;
        frameAddress = 0x00;
        return;
      }
      else
      {
        sizeFrameAddress = 0;
        frameAddress = 0x00;
        return;
      }
  }

  // if receive enough 8 bit data, then return an ACK signal
  // then check stop condition
  // if stop, then stop
  // else, keep on receiving data
  if (sizeDataReceive == 8)
  {
      pinMode(SDA, OUTPUT);
      digitalWrite(SDA, LOW);
      delay(60);
      pinMode(SDA, INPUT);
      Serial.print("Data reiceive: ");
      Serial.println((int)dataReceive);
      sizeDataReceive = 0;
      dataReceive = 0;

      delay(30);
      checkStopCondition();

  }
  
  if (sizeDataSend == 8)
  {
    delay(60);
    pinMode(SDA, INPUT);
    
    if (digitalRead(SDA) == LOW)
    {
      Serial.print("Data send success: ");
      Serial.println(data_value);
      if (data_value >= 44)
      {
        data_value = 19;
      }
      
      ++data_value;
      dataSend = data_value;
    }
    else
    {
       Serial.print("Data send fail: ");
    }
    
    sizeDataSend = 0;
    
    //Checkstop
    delay(30);
    checkStopCondition();

  }
  
}
