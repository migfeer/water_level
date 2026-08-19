#include <WiFi.h>
#include <PubSubClient.h>
#include <Wire.h>

// SSID/Password
const char* ssid = "Estudio";
const char* password = "Estudio@FernandoLuis45";

// MQTT credentials:
const char* mqtt_server = "192.168.9.107";
const char* username = "ferxxo";
const char* pass = "jesus200";

WiFiClient espClient;
PubSubClient client(espClient);

//Name of de client
const char* clientName = "myesp32";

unsigned long lastMsg = 0;
unsigned long interval = 5000;

unsigned long previusTime = 0;
unsigned long interval2 = 1000;

//Pin out vertical level sensors

const int level1 = 6; //25%
const int level2 = 5; //50%
const int level3 = 4; //75%
const int level4 = 3; //100%

bool activeMesure = false;
char mymsg[4] = ""; //Message to send


void setup() {

  Serial.begin(115200);
  pinMode(level1, INPUT);
  pinMode(level2, INPUT);
  pinMode(level3, INPUT);
  pinMode(level4, INPUT);

  setup_wifi();
  client.setServer(mqtt_server, 1883);
  //It needs to receive a message
  client.setCallback(callback);

}



void setup_wifi() {
  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* message, unsigned int length) {
  Serial.print("Message arrived on topic: ");
  Serial.print(topic);
  Serial.print(". Message: ");
  String messageTemp;
  
  for (int i = 0; i < length; i++) {
    Serial.print((char)message[i]);
    messageTemp += (char)message[i];
  }
  Serial.println();

  // If a message is received on the topic esp32/start, you check if the message is either "on" or "off". 
  // Changes the output state according to the message

  if (String(topic) == "esp32/start") {
    Serial.print("Changing output to ");
    if(messageTemp == "on"){
      Serial.println("on");
      activeMesure = true;
      //client.publish("esp32/level", "25%");
    }
    else if(messageTemp == "off"){
      activeMesure = false;
      Serial.println("off");
    }
  }

}




void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect(clientName, username, pass)) {
      Serial.println("connected");
      client.subscribe("esp32/start");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}


void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  long now = millis();

  if (activeMesure)
  {
    //Read vertical sensors:
    if (!digitalRead(level1) && digitalRead(level2) && digitalRead(level3) && digitalRead(level4)){

      strlcpy(mymsg, "25%", 4); 
      Serial.println("25%");
    }
    if (!digitalRead(level1) && !digitalRead(level2) && digitalRead(level3) && digitalRead(level4))
    {
      strlcpy(mymsg, "50%", 4); 
      Serial.println("50%");
    }
    if (!digitalRead(level1) && !digitalRead(level2) && !digitalRead(level3) && digitalRead(level4))
    {
      strlcpy(mymsg, "75%", 4); 
      Serial.println("75%");
    }
    if (!digitalRead(level1) && !digitalRead(level2) && !digitalRead(level3) && !digitalRead(level4))
    {
      strlcpy(mymsg, "100%", 4); 
      Serial.println("100%");
    }
    //Send data
    client.publish("esp32/level", mymsg);
  }
  
}
