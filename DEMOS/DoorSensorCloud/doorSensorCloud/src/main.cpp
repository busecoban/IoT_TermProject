#include <WiFi.h>
#include <AzureIoTHub.h>
#include <AzureIoTProtocol_MQTT.h>
#include <AzureIoTUtility.h>
#include <iothubtransportmqtt.h>

// WiFi bilgilerinizi buraya girin
const char* ssid = "Buse";
const char* password = "casuva48";
const char* connectionString = "HostName=BusesIotHub.azure-devices.net;DeviceId=Busesesp32;SharedAccessKey=Ax+2xwXuCju6BU5+QTKRLkFmFzRuW39/mAIoTFPq8OY=";

const int manyetikSensorPin = 2;
int doorStatus = 0;

IOTHUB_DEVICE_CLIENT_LL_HANDLE device_ll_handle;

const char certificates[] = 
"-----BEGIN CERTIFICATE-----\r\n"
"MIIDdzCCAl+gAwIBAgIEfQKN5DANBgkqhkiG9w0BAQsFADBvMQswCQYDVQQGEwJV\r\n"
"UzEVMBMGA1UEChMMQmFsdGltb3JlIFRST1NUIENBMRowGAYDVQQLExFTZWN1cmUg\r\n"
"U2VydmVyIFJvb3QxGzAZBgNVBAMTEkJhbHRpbW9yZSBDQSBUTFMgUlNBIENBMB4X\r\n"
"DTAwMDkwNTAwMDAwMFoXDTI1MDkwNTAwMDAwMFowgYMxCzAJBgNVBAYTAlVTMQsw\r\n"
"CQYDVQQIEwJDQTEMMAoGA1UEBxMDSXJ2aW5lMRAwDgYDVQQKEwdBdHRsYXNzdDEW\r\n"
"MBQGA1UEAxMNR1VBUkRJQU4gRFcgVE1DMTowOAYJKoZIhvcNAQkBFhdsaWRpYS5h\r\n"
"bHRsYXNzdEBndWFyZGlhbmR3LmNvbTEnMCUGCSqGSIb3DQEJARYYcm9vdEBhdHRs\r\n"
"YXNzdC1zZWN1cmUuY29tMIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEA\r\n"
"vFi07x3+CMfLBaKH4c5Z+u4Wr4b9kw/sLBfgQymYSLszV1D7e4eAjjbaDqAxRRDL\r\n"
"6DkJb0uvOHIMdEYy2pFLg/Mr4zEbKJ3OE3dhF9kmSih3z6ZcF8m5K7A3xr1ZAXog\r\n"
"2GiT2Jqzvd0Wl7hGye3+TtMYzGVbH0oTTlByfYw+i4iS3aj56coWX80LV2Z1Ok5I\r\n"
"pI6yuwOU9/REZgk0hhJd4eGJGSt2g0wYm8cuAhW3S1Mh5m8Nc76LNk5U4EKBLPSJ\r\n"
"yOlsFvN0Ve8LXN32JGT0nU0/ONdXH7IKArXlOYD67dwTQWm4CvsNQQJvWkDpBf9Y\r\n"
"kHzpCOWOHrBvqSCnITrQXwIDAQABo1AwTjAdBgNVHQ4EFgQU3ARDCyCzH2kBIpD8\r\n"
"g4lVbkmxozowHwYDVR0jBBgwFoAUe6H9vIDWGrN/Jj15X9b0f4bQJ3owDAYDVR0T\r\n"
"BAUwAwEB/zANBgkqhkiG9w0BAQsFAAOCAQEAqWZOxfGOthmF3A1zLFNGL9gYkxkQ\r\n"
"R3K2BnoROQHc6Wf/xJmNj1GAu+5/MrjE/VJSZ0LT93SGFivKvZJ+G8qY1+E/9+5b\r\n"
"RLmjEvkRokvbs0b8ZT4ICxRPvX6CfROXX2N8kAKzpIgG6dkw7y23bE6u4pl0r9xL\r\n"
"jv73BGZ6g1DhXWObdOEPFkhM4XpzW6GLHH3zHaXhJH67FZ3akNCrW2/6P7DhA23Z\r\n"
"Dy57m8dOKFA0fVHGzRSJ22y6HbXQEOqQK5BpiUE6B0nQodlvF5+bKlFXygFqGy/k\r\n"
"bWeJ9x0B8jeJTYhQ+lQlNe3C0Yl86RUV7gnAC59DZv+npGUHjt6kzA==\r\n"
"-----END CERTIFICATE-----\r\n";

void reconnectWiFi() {
  if (WiFi.status() != WL_CONNECTED) {
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
      delay(1000);
      Serial.println("Reconnecting to WiFi...");
    }
    Serial.println("Reconnected to WiFi");
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(manyetikSensorPin, INPUT_PULLUP);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Initialize the IoT Hub client
  IoTHub_Init();
  device_ll_handle = IoTHubDeviceClient_LL_CreateFromConnectionString(connectionString, MQTT_Protocol);
  if (device_ll_handle == NULL) {
    Serial.println("Failed to create IoT Hub client");
    return;
  }

  // Sertifikayı ayarlayın
  IoTHubDeviceClient_LL_SetOption(device_ll_handle, "TrustedCerts", certificates);
  IoTHubDeviceClient_LL_SetOption(device_ll_handle, "messageTimeout", "120");
}

void loop() {
  reconnectWiFi();

  int manyetikDurum = digitalRead(manyetikSensorPin);

  if (manyetikDurum == HIGH) {
    Serial.println("Door Open");
    doorStatus = 1;
  } else {
    Serial.println("Door Close");
    doorStatus = 0;
  }

  char messagePayload[100];
  snprintf(messagePayload, sizeof(messagePayload), "{\"doorStatus\":%d}", doorStatus);

  IOTHUB_MESSAGE_HANDLE message_handle = IoTHubMessage_CreateFromString(messagePayload);
  if (message_handle == NULL) {
    Serial.println("Failed to create message");
    return;
  }

  if (IoTHubDeviceClient_LL_SendEventAsync(device_ll_handle, message_handle, NULL, NULL) != IOTHUB_CLIENT_OK) {
    Serial.println("Failed to send message");
  } else {
    Serial.println("Message sent: " + String(messagePayload));
  }

  IoTHubMessage_Destroy(message_handle);
  IoTHubDeviceClient_LL_DoWork(device_ll_handle);
  delay(10000); // 10 saniye bekleme süresi
}
