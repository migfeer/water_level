#include <SPI.h>
#include <WiFi.h>

// Replace the next variables with your SSID/Password combination
const char* ssid = "Estudio";
const char* password = "Estudio@FernandoLuis45";

void setup() {

  Serial.begin(115200);
  setup_wifi();

}

void loop() {
  // put your main code here, to run repeatedly:

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