#include <SPI.h>
#include <Ethernet.h>

/* --------------------------------------------------------------------
*  Ethernet Config
* -------------------------------------------------------------------*/
byte mac[] = { 0x00, 0xAA, 0xBB, 0xCC, 0xDE, 0x02 }; //MAC Address
char server[] = "XXX.XXX.XXX.XXX"; //API Server
String s_data1 = ""; // Request Data
int led_green = 6; // LED ON
int led_red = 7; // LED ON

/* --------------------------------------------------------------------
 *  Ethernet Library 
 * -------------------------------------------------------------------*/
EthernetClient client;

/* --------------------------------------------------------------------
*  SETUP
* -------------------------------------------------------------------*/
void setup() {

 // LED 
 pinMode(led_green, OUTPUT);
 pinMode(led_red, OUTPUT);

 // Open serial communications and wait for port to open:
 Serial.begin(9600);

 Serial.println("### setup start");

 // this check is only needed on the Leonardo:
 //while (!Serial) {
 // ; // wait for serial port to connect. Needed for Leonardo only
 //}

 // start the Ethernet connection:
 if (Ethernet.begin(mac) == 0) {
  Serial.println("Failed to configure Ethernet using DHCP");
  // no point in carrying on, so do nothing forevermore:
  for (;;)
   ;
 }
 // print your local IP address:
 Serial.print("My IP address: ");
 for (byte thisByte = 0; thisByte < 4; thisByte++) {
  // print the value of each byte of the IP address:
  Serial.print(Ethernet.localIP()[thisByte], DEC);
  Serial.print(".");
 }
 Serial.println();

}

/* --------------------------------------------------------------------
*  LOOP
* -------------------------------------------------------------------*/
void loop() {

 Serial.println("### loop start");

 //sensor 1~..
 s_data1 = "sensor_id=S001&";
 s_data1 += "sensor_board=ArduinoUno&";
 s_data1 += "sensor_shield=W5100&";
 s_data1 += "sensor_comm=Ethernet&";
 s_data1 += "sensor_name=MiniPhotocell&";
 s_data1 += "sensor_func=F01&";
 s_data1 += "sensor_value=" + (String)analogRead(A0) + "&";
 s_data1 += "sensor_value_desc=0~1023";
 //Serial.println(s_data1);
 Serial.println("S001-"+ (String)analogRead(A0));
 
 //서버 연결
 client.stop();
 connect_server();

 if (client.connected())
 {
  Serial.println("c1");
  client.println("POST /iotHome-api/v1/sensor/post-form2xml-mysqldb HTTP/1.0");
  client.println("Host: XXX.XXX.XXX.XXX");
  client.println("User-Agent: Arduino");
  client.println("Connection: close");
  client.println("Content-Type: application/x-www-form-urlencoded");
  client.print("Content-Length: ");
  client.println(s_data1.length());
  client.println();
  client.println(s_data1);

  digitalWrite(led_green, HIGH);
  delay(100);
  digitalWrite(led_green, LOW);

 } 
 else
 {
  digitalWrite(led_red, HIGH);
  delay(1000);
  digitalWrite(led_red, LOW);
 }
 delay(1000);

 s_data1 = "sensor_id=S002&";
 s_data1 += "sensor_board=ArduinoUno&";
 s_data1 += "sensor_shield=W5100&";
 s_data1 += "sensor_comm=Ethernet&";
 s_data1 += "sensor_name=PhotoResistorModule&";
 s_data1 += "sensor_func=F01&";
 s_data1 += "sensor_value=" + (String)analogRead(A1) + "&";
 s_data1 += "sensor_value_desc=0~1023";
 //Serial.println(s_data1);
 Serial.println("S002-" + (String)analogRead(A1));

 client.stop();
 connect_server();
 if (client.connected())
 {
  Serial.println("c2");

  client.println("POST /iotHome-api/v1/sensor/post-form2xml-mysqldb HTTP/1.0");
  client.println("Host: XXX.XXX.XXX.XXX");
  client.println("User-Agent: Arduino");
  client.println("Connection: close");
  client.println("Content-Type: application/x-www-form-urlencoded");
  client.print("Content-Length: ");
  client.println(s_data1.length());
  client.println();
  client.println(s_data1);

  digitalWrite(led_green, HIGH);
  delay(100);
  digitalWrite(led_green, LOW);

 }
 else
 {
  digitalWrite(led_red, HIGH);
  delay(1000);
  digitalWrite(led_red, LOW);
 }
 
 delay(1000);

 s_data1 = "sensor_id=S003&";
 s_data1 += "sensor_board=ArduinoUno&";
 s_data1 += "sensor_shield=W5100&";
 s_data1 += "sensor_comm=Ethernet&";
 s_data1 += "sensor_name=CDS5MM&";
 s_data1 += "sensor_func=F01&";
 s_data1 += "sensor_value=" + (String)analogRead(A2) + "&";
 s_data1 += "sensor_value_desc=0~1023";
 //Serial.println(s_data1);
 Serial.println("S003-" + (String)analogRead(A2));

 client.stop();
 connect_server();

 if (client.connected())
 {
  Serial.println("c3");

  client.println("POST /iotHome-api/v1/sensor/post-form2xml-mysqldb HTTP/1.0");
  client.println("Host: XXX.XXX.XXX.XXX");
  client.println("User-Agent: Arduino");
  client.println("Connection: close");
  client.println("Content-Type: application/x-www-form-urlencoded");
  client.print("Content-Length: ");
  client.println(s_data1.length());
  client.println();
  client.println(s_data1);

  digitalWrite(led_green, HIGH);
  delay(100);
  digitalWrite(led_green, LOW);

 }
 else
 {
  digitalWrite(led_red, HIGH);
  delay(1000);
  digitalWrite(led_red, LOW);
 }
 delay(1000);

 s_data1 = "sensor_id=S004&";
 s_data1 += "sensor_board=ArduinoUno&";
 s_data1 += "sensor_shield=W5100&";
 s_data1 += "sensor_comm=Ethernet&";
 s_data1 += "sensor_name=CDS10MM&";
 s_data1 += "sensor_func=F01&";
 s_data1 += "sensor_value=" + (String)analogRead(A3) + "&";
 s_data1 += "sensor_value_desc=0~1023";
 //Serial.println(s_data1);
 Serial.println("S004-" + (String)analogRead(A3));

 client.stop();
 connect_server();
 if (client.connected())
 {
  Serial.println("c4");

  client.println("POST /iotHome-api/v1/sensor/post-form2xml-mysqldb HTTP/1.0");
  client.println("Host: XXX.XXX.XXX.XXX");
  client.println("User-Agent: Arduino");
  client.println("Connection: close");
  client.println("Content-Type: application/x-www-form-urlencoded");
  client.print("Content-Length: ");
  client.println(s_data1.length());
  client.println();
  client.println(s_data1);

  digitalWrite(led_green, HIGH);
  delay(100);
  digitalWrite(led_green, LOW);

  //Serial.println(client.readString());

 }
 else
 {
  digitalWrite(led_red, HIGH);
  delay(1000);
  digitalWrite(led_red, LOW);
 }
 delay(1000);

 s_data1 = "sensor_id=S005&";
 s_data1 += "sensor_board=ArduinoUno&";
 s_data1 += "sensor_shield=W5100&";
 s_data1 += "sensor_comm=Ethernet&";
 s_data1 += "sensor_name=CDS15MM&";
 s_data1 += "sensor_func=F01&";
 s_data1 += "sensor_value=" + (String)analogRead(A4) + "&";
 s_data1 += "sensor_value_desc=0~1023";
 //Serial.println(s_data1);
 Serial.println("S005-" + (String)analogRead(A4));

 client.stop();
 connect_server();
 if (client.connected())
 {
  Serial.println("c5");

  client.println("POST /iotHome-api/v1/sensor/post-form2xml-mysqldb HTTP/1.0");
  client.println("Host: XXX.XXX.XXX.XXX");
  client.println("User-Agent: Arduino");
  client.println("Connection: close");
  client.println("Content-Type: application/x-www-form-urlencoded");
  client.print("Content-Length: ");
  client.println(s_data1.length());
  client.println();
  client.println(s_data1);

  digitalWrite(led_green, HIGH);
  delay(100);
  digitalWrite(led_green, LOW);

 }
 else
 {
  digitalWrite(led_red, HIGH);
  delay(1000);
  digitalWrite(led_red, LOW);
 }
 delay(1000);
 
 s_data1 = "sensor_id=S006&";
 s_data1 += "sensor_board=ArduinoUno&";
 s_data1 += "sensor_shield=W5100&";
 s_data1 += "sensor_comm=Ethernet&";
 s_data1 += "sensor_name=CDS20MM&";
 s_data1 += "sensor_func=F01&";
 s_data1 += "sensor_value=" + (String)analogRead(A5) + "&";
 s_data1 += "sensor_value_desc=0~1023";
 //Serial.println(s_data1);
 Serial.println("S006-" + (String)analogRead(A5));
 
 client.stop();
 connect_server();
 if (client.connected())
 {
  Serial.println("c6");

  client.println("POST /iotHome-api/v1/sensor/post-form2xml-mysqldb HTTP/1.0");
  client.println("Host: XXX.XXX.XXX.XXX");
  client.println("User-Agent: Arduino");
  client.println("Connection: close");
  client.println("Content-Type: application/x-www-form-urlencoded");
  client.print("Content-Length: ");
  client.println(s_data1.length());
  client.println();
  client.println(s_data1);

  digitalWrite(led_green, HIGH);
  delay(100);
  digitalWrite(led_green, LOW);
 }
 else
 {
  digitalWrite(led_red, HIGH);
  delay(1000);
  digitalWrite(led_red, LOW);
 }
 delay(60000);
}

/* --------------------------------------------------------------------
*  Connect to Server
* -------------------------------------------------------------------*/
void connect_server() {
 if (client.connect(server, 80)) {
  Serial.print("# server connected-");
 } 
 else {
  Serial.println("server connection failed");
  setup();

  digitalWrite(led_red, HIGH);
  delay(100);
  digitalWrite(led_red, LOW);
  delay(100);
  digitalWrite(led_red, HIGH);
  delay(100);
  digitalWrite(led_red, LOW);
  delay(100);
  digitalWrite(led_red, HIGH);
  delay(100);
  digitalWrite(led_red, LOW);

 }
}

/* --------------------------------------------------------------------
*  Call to Server API 
* -------------------------------------------------------------------*/
void call_api(String pdata) {
 //Serial.println((String)pdata.length());
 //Serial.println(pdata);
 
  client.println("POST /iotHome-api/v1/sensor/post-form2xml-mysqldb HTTP/1.0");
  client.println("Host: XXX.XXX.XXX.XXX");
  client.println("User-Agent: Arduino");
  client.println("Connection: close");
  client.println("Content-Type: application/x-www-form-urlencoded");
  client.print("Content-Length: ");
  client.println(pdata.length());
  client.println();
  client.println(pdata);
}
