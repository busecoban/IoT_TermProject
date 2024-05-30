## Project Owner

**Name:** Buse Çoban

**Student Number:** 20200808070

## Project

**Title of the project:** The Smart Door and Window Sensor System

**Course Name:** CSE 328 Internet of Things 

[20200808070_ProjectProposal.pdf](https://github.com/busecoban/IoT_TermProject/files/15501400/20200808070_ProjectProposal.pdf)


[CSE328_TermProjectReport_20200808070.pdf](https://github.com/busecoban/IoT_TermProject/files/15501398/CSE328_TermProjectReport_20200808070.pdf)

https://webappdeployment1.azurewebsites.net/



https://github.com/busecoban/IoT_TermProject/assets/73944611/be9fd13d-2c5a-4001-8d1c-4e5fe97e3605




# Project Proposal

 The Smart Door and Window Sensor System aims to enhance security and convenience by providing real-time monitoring of the open/close status of doors and windows in residential or commercial buildings. The project's primary objectives include accurately detecting door/window events, notifying users of any changes in status, enabling remote monitoring and control, and ensuring energy efficiency. The scope encompasses the deployment of sensors and microcontrollers to detect status changes, the development of a user interface for notifications and control, and the integration of power sources for reliable operation.

## Proposed Methodology and Approach

- Accurately and reliably detecting door/window open/close events.
- Providing real-time notifications to users via a user interface.
- Enabling remote monitoring and control of door/window status.
- Integrating power-efficient components for prolonged operation.

## List of Required Hardware and Software Resources

### Hardware Resources:

1. Hall effect sensor: [Link](https://www.robotistan.com/us1881?ref=burakyahsi)
2. Mini reed relay card: [Link](https://www.robotistan.com/mini-reed-role-karti-reed-relay?ref=burakyahsi)
3. ESP32 microcontroller
4. Power sources:
   - AC to DC converter (e.g., AC 220V to DC 5V converter, 3W-700mA):
   - [Link 1](https://www.robotistan.com/ac-220v-dc-5v-donusturucu-3w-guc-kaynagi-hlk-pm01?ref=burakyahsi)
   - [Link 2](https://www.robotistan.com/ac220v-dc5v-donusturucu-5v-700ma?ref=burakyahsi)
     
### Software Resources:

1. Arduino IDE
2. Libraries for ESP32 (e.g., ESP32 Arduino Core)
3. Wi-Fi library for ESP32 communication
4. User interface development tools

# Project Final Report 

## Introduction

The Smart Door and Window Sensor System is an IoT project designed to enhance home security by monitoring the status of doors and windows. This system uses an ESP32 microcontroller and a Hall effect sensor to detect whether doors and windows are open or closed. The information is sent to Azure IoT Central for real-time monitoring and analysis. The integration with Azure IoT services allows for scalable, secure, and efficient management of the devices.

## System Architecture

### Circuit Description

1. **Hall Effect Sensor Wiring**:
   - VCC wire to the 3.3V pin of the ESP32.
   - Ground wire to the ground pin of the ESP32.
   - Signal wire to the D2 pin of the ESP32.

2. **Operation**:
   - **Power-On**: The ESP32 provides a 3.3V supply to the Hall Effect sensor.
   - **Magnetic Field Detection**: The sensor detects the magnetic field strength.
   - **Signal Transmission**: When the door moves away, the magnetic field decreases, and the sensor modifies its output signal.
   - **Signal Reading**: The ESP32 reads the signal from the Hall Effect sensor on its D2 pin to determine whether the door is open or closed.
   - **Action**: The ESP32 can send notifications, log data, or control other devices based on the door status.

## Implementation Details

### Software Development

**GitHub Repository**: [IoT Term Project](https://github.com/busecoban/IoT_TermProject)

- **Arduino Sketch (IOTDoorSensor.ino)**:
  - Initializes serial communication, WiFi connection, and Azure IoT client.
  - Monitors the Hall effect sensor and sends telemetry data to Azure IoT Central.
  - Handles incoming messages from Azure IoT Central.

- **Azure IoT PnP Templates (Azure_IoT_PnP_Template.cpp and .h)**:
  - Configures the connection to Azure IoT Hub.
  - Formats and sends telemetry data according to the PnP model.
  - Processes commands from Azure IoT Central.

- **Azure IoT Client Management (AzureIoT.cpp and .h)**:
  - Manages MQTT client operations, including connecting to IoT Hub and handling telemetry and commands.

- **Configuration File (iot_configs.h)**:
  - Contains device credentials, MQTT configuration, and other constants.

### Web Integration

- **React Components**:
  - `DeviceRecent.jsx`: Fetches and displays recent device statuses, and shows notifications for status changes.

### Azure Functions

- Processes telemetry data received from IoT Hub.
- Integrates with the web application to provide real-time updates on the device status.

## Results and Analysis

The Smart Door and Window Sensor System has demonstrated the following results:

1. **Real-Time Monitoring**: The system provides real-time updates on the status of doors and windows, allowing users to monitor their home security remotely.
2. **Reliable Data Transmission**: Using Azure IoT Hub and Azure Functions, the system ensures reliable data transmission and processing.
3. **Scalability**: Azure IoT Central facilitates scalable device management, allowing for the easy addition of new devices.
4. **User-Friendly Interface**: The React-based web application provides an intuitive interface for users to monitor device status and manage devices.

## Conclusion

The Smart Door and Window Sensor System successfully integrates hardware and cloud services to provide a robust home security solution. The use of Azure IoT services ensures secure, scalable, and efficient management of the devices, while the web application offers a user-friendly interface for real-time monitoring and control. This project demonstrates the potential of IoT in enhancing home security and provides a foundation for further development and integration of additional smart home features.

## References

1. [Azure IoT Central Documentation](https://docs.microsoft.com/en-us/azure/iot-central/)
2. [Azure DPS Documentation](https://docs.microsoft.com/en-us/azure/iot-dps/)
3. [Azure Functions Documentation](https://docs.microsoft.com/en-us/azure/azure-functions/)
4. [ESP32 Documentation](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/)
5. [Arduino Documentation](https://www.arduino.cc/reference/en/)


