/*
  File: Slave.ino
  Author: Linh Pham
  Date: 22/04/2023
  Description: Mô phỏng quá trình truyền nhận giữa Master và Slave sử dụng giao thức I2C. File này dành cho Slave
*/

//Bus I2C
#define SDA 4
#define SCL 3
//Bit Write/Read
#define WRITE 0
#define READ 1
//Adress
#define ADDRESS 0x6E

uint8_t dataReceive = 0x00;  //Data receive from Master
uint8_t sizeDataReceive = 0;     // Size data receive from Master

uint8_t frameAddress = 0x00;//frame address include 7 bit address of slave, 1 bit mode read/write
uint8_t sizeFrameAddress = 0;//size of frame address;
uint8_t readOrWrite;//Lưu chế độ

uint8_t dataSend = 0x00; //Data send to Master
uint8_t sizeDataSend = 0;//Size of data send to master
uint8_t data_value = 20;

bool checkStart = false;//Biến kiểm tra Start
bool checkStop = true;
bool checkAddress = false;//Biến kiểm tra địa chỉ
//bool checkData = 1;////Biến kiểm tra để bắt đầu đọc DATA

unsigned long start_time ;
unsigned long present_time;

/*
  Function: i2cInit
  Description: Hàm khởi động giao thức I2C
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
  Function: checkStop
  Description: Hàm kiểm tra tín hiệu kết thúc
  Input:
    No input
  Output:
    No return
*/

      
volatile void checkStopCondition()
{
  delay(100);
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
   }
   else
   {
     Serial.println("Stop condition not true");
   }
   
  
}


/*
  Function: writeData
  Description: Hàm gửi Data tới Master
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
  pinMode(SDA, INPUT);
}

/*
  Function: readData
  Description: Hàm đọc Data từ Master
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
  Description: Chương trình ngắt mỗi khi có xung Clock
  Input:
    No input
  Output:
    No return
*/

volatile void interruptSCL() {
  //Check tín hiệu bắt đầu I2C
  if (checkStart == false && checkStop == true)
  {
    checkStartCondition();
    return;
  }
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
  
  //Truyền nhận Data nếu địa chỉ đúng
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
  attachInterrupt(1, interruptSCL, FALLING);
  
}

void loop(){
  
  if (sizeFrameAddress == 8)
  {
      Serial.print("Frame address from master: ");
      Serial.println((int)frameAddress);
      if ( (frameAddress  & 0xFE) == (ADDRESS << 1) )
      {
        pinMode(SDA, OUTPUT);
        digitalWrite(SDA, LOW);
        delay(50);
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


  if (sizeDataReceive == 8)
  {
      pinMode(SDA, OUTPUT);
      digitalWrite(SDA, LOW);
      delay(50);
      pinMode(SDA, INPUT);
      Serial.print("Data reiceive: ");
      Serial.println((int)dataReceive);
      sizeDataReceive = 0;
      dataReceive = 0;

      
      checkStopCondition();

  }
  
  if (sizeDataSend == 8)
  {
    pinMode(SDA, OUTPUT);
    digitalWrite(SDA, LOW);
    delay(70);
    pinMode(SDA, INPUT);
    Serial.print("Data send: ");
    Serial.println(data_value);
    
    
    
    if (data_value >= 44)
    {
      data_value = 19;
    }
    ++data_value;

    dataSend = data_value;
    sizeDataSend = 0;
    
    //Checkstop
    
    checkStopCondition();

  }
  
}
