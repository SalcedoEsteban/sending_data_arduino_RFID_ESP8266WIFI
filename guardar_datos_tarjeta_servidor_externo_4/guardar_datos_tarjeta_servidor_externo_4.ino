#include <ESP8266WiFi.h>
#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN  5    //Pin 5 para el reset del RC522
#define SS_PIN  15   //Pin 15 para el SS (SDA) del RC522

//String codigotarjeta = "";
String codigotarjeta;
String chipid = "";
bool bandera;

const char* ssid = "MARISAJABE";
const char* password = "31126263"; 
const char* host = "192.168.0.35";
//const char* host = "subirdatosmodulowifi.epizy.com";
//const char* host = "185.27.134.142";

//Creamos el objeto para el RC522 al cual llamamos Lector1
MFRC522 lector1(SS_PIN, RST_PIN); 

//CREAMOS LA FUNCION QUE ENVIARÁ LOS DATOS A LA BASE DE DATOS LOCAL O EXTERNA
bool enviarDatos(bool bandera, String codigotarjeta)
{
    if(bandera == true)
    {
     //=============CODIGO CONEXION AL HOST==========================

     Serial.print("connecting to ");
     Serial.println(host);

     // Use WiFiClient class to create TCP connections
     WiFiClient client;
     const int httpPort = 80;
     if (!client.connect(host, httpPort))
     {
        Serial.println("connection failed");
        //return;
     }
     else
     {
        Serial.println("successful conection");
     }
     
     //====================== FIN DE CODIGO DE CONEXION AL HOST ==========
    
      // http://subirdatosmodulowifi.epizy.com/guardar.php?codigotarjeta=245+217+149+187&chipid=553355
    
     // We now create a URL for the request
     String url = "prueba_arduino_mysql_local/guardar.php";
     String key = "?";
     String dato1 = "codigotarjeta=";
     String dato2 = "&chipid=";

     Serial.print("Requesting URL: ");
     Serial.println(url);

     // This will send the request to the server
     client.print(String("GET /") + url + key + dato1 + codigotarjeta + dato2 + chipid + " HTTP/1.1\r\n" + "Host: " + host + "\r\n" + "Connection: close\r\n\r\n");

    //EN ESTA PARTE SE IMPRIME LA URL EN ORDEN PARA SABER QUE ES LO QUE SE ENVIA CUANDO SE REALIZA LA PETICION GET
    /*Serial.print( url + key + dato1 + codigotarjeta + dato2 + chipid + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "Connection: close\r\n\r\n");*/
               
  unsigned long timeout = millis();
  while (client.available() == 0)
  {
    if (millis() - timeout > 5000)
    {
      Serial.println(">>> Client Timeout !");
      client.stop();
      //return;
    }
  }

  // Read all the lines of the reply from server and print them to Serial
  while (client.available())
  {
    String line = client.readStringUntil('\r');
    Serial.print(line);
  }

  Serial.println();
  Serial.println("closing connection");
  }

  

  Serial.println("el codigo de la tarjeta almacenado en la variable global es: ");
  Serial.println(codigotarjeta);

  //reiniciamos la variable que alamacena el serial de la tarjeta
  reiniciarVariable();


  Serial.println("el codigo de la tarjeta despues de reiniciarse es: ");
  Serial.println(codigotarjeta);
  
  return true;



  
}


//DECLARAMOS LA FUNCION QUE REINICIA LA VARIABLE QUE ALMACENA EL SERIAL DEL CARNE
void reiniciarVariable()
{
  codigotarjeta = "";
}


//CREAMOS LA FUNCION QUE CONECTARA AL WIFI DE LA COMPUTADORA
void conectarWifi()
{
  //=========CODIGO CONEXION WIFI================
    Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);
  
    WiFi.begin(ssid, password);
  
    while (WiFi.status() != WL_CONNECTED)
    {
      delay(500);
      Serial.print(".");
    }
  
    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP()); 
  
    //===========FIN CODIGO CONEXION WIFI=============  

}

void setup()
{
  //=======CODIGO SENSOR RFID============================
  Serial.begin(9600); //Iniciamos La comunicacion serial
  SPI.begin();        //Iniciamos el Bus SPI
  lector1.PCD_Init(); // Iniciamos el MFRC522
  Serial.println("Bienvenido al Sistema Lector de Tarjetas RFID\n    Por Favor Acerca tu Tarjeta al Lector\n");
  //=======FIN CODIGO SENSOR RID=========================

  //==========CODIGO MODULO WIFI=======================
  Serial.print("chipId: "); 
  chipid = String(ESP.getChipId());
  Serial.println(chipid);
  //==========FIN CODIGO MODULO WIFI=======================


  //SE HACE EL LLAMADO A LA FUNCION QUE CONECTA EL WIFI
  conectarWifi();
}

void loop()
{
  // put your main code here, to run repeatedly:
  if ( lector1.PICC_IsNewCardPresent())   // Revisamos si hay nuevas tarjetas  presentes.
        { 
            if ( lector1.PICC_ReadCardSerial())  //LEEMOS EL SERIAL DE LA TARJETA
            {
                  //Serial.print("El ID de tu tarjeta es: \n"); // Imprimimos el ID de la tarjeta
                  for (byte i = 0; i < lector1.uid.size; i++)
                  {
                          //Serial.print(lector1.uid.uidByte[i] < 0x10 ? " 0" : " ");
                          //Serial.print(lector1.uid.uidByte[i], DEC);
                          //codigotarjeta = codigotarjeta + lector1.uid.uidByte[i]+ " ";
                          codigotarjeta = codigotarjeta + lector1.uid.uidByte[i], DEC;    
                  }
                  Serial.println(" ");

                  //Serial.println("el codigo de la tarjeta es: ");
                  //Serial.println(codigotarjeta);

                  Serial.println("el codigo de la tarjeta almacenado en la variable global es: ");
                  Serial.println(codigotarjeta);
                  //codigotarjeta = " ";
                  //Serial.println("despues de volver a reiniciar la variable, el codigo es: ");
                  //Serial.println(codigotarjeta);
                  
                  lector1.PICC_HaltA(); // Terminamos la lectura de la tarjeta tarjeta para ahorrar energía.
                  //lector1.PCD_StopCrypto1(); //Detenemos la encriptacion.

                  
            }

            bandera = true;
            enviarDatos(bandera, codigotarjeta);
            
      }
      else
      {
        //aca se puede enviar un mensaje de que no hay tarjetas presentes, que se pase una por el sensor
      }
}
