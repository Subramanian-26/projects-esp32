# 1.Smart Traffic Light System using ESP32 and HC-SR04

## Description

This project is a beginner-friendly **smart traffic light control system** using an ESP32, an HC-SR04 ultrasonic sensor, and three LEDs.

The HC-SR04 sensor is used to detect the presence of a vehicle based on its distance from the sensor. The ESP32 then adjusts the **green-light duration according to the detected traffic condition**.

If a vehicle is detected within **100 cm**, the system considers the road busy and keeps the green light ON for **10 seconds**. Otherwise, the green light remains ON for **5 seconds**.

This project demonstrates **ultrasonic sensor interfacing, GPIO control, distance measurement, conditional logic, and automatic traffic signal control**.

---

## Working Principle

The HC-SR04 ultrasonic sensor measures the distance between the sensor and a nearby object.

The sensor uses two pins:

* **TRIG** – Sends an ultrasonic pulse.
* **ECHO** – Receives the reflected ultrasonic pulse.

The ESP32 measures the time taken for the ultrasonic wave to travel to the object and return.

The distance is calculated using:

```text
Distance = Duration × 0.0343 / 2
```

### Why divide by 2?

The ultrasonic wave travels from the sensor to the object and then back to the sensor.

Therefore, the measured distance corresponds to twice the actual distance.

For example:

```text
Sensor → Object → Sensor
```

The speed of sound is approximately **0.0343 cm/µs**, which is used in the distance calculation.

### Traffic Detection

The system uses **100 cm** as the detection threshold.

If:

```text
Distance < 100 cm
```

the system considers a vehicle to be detected and sets the green-light duration to **10 seconds**.

If:

```text
Distance ≥ 100 cm
```

the system considers the road to have normal traffic and sets the green-light duration to **5 seconds**.

The traffic light follows the sequence:

```text
RED → GREEN → YELLOW → RED
```

---

## Features

* Uses **ESP32** as the main controller
* Detects nearby vehicles using an **HC-SR04 ultrasonic sensor**
* Dynamically changes green-light duration
* Implements automatic traffic light sequencing
* Displays distance readings through the Serial Monitor
* Demonstrates sensor-based decision making
* Can be simulated completely using **Wokwi**
* Simple design that can be expanded into an advanced smart traffic system

---

## Components Used

* ESP32
* HC-SR04 Ultrasonic Distance Sensor
* Red LED
* Yellow LED
* Green LED
* 3 × 220 Ω Resistors
* Jumper Wires

---

## Pin Connections

### HC-SR04 Connections

* **VCC → 5V**
* **GND → GND**
* **TRIG → GPIO 19**
* **ECHO → GPIO 18**

### Traffic Light Connections

**Red LED**

* Anode → 220 Ω resistor → GPIO 32
* Cathode → GND

**Yellow LED**

* Anode → 220 Ω resistor → GPIO 33
* Cathode → GND

**Green LED**

* Anode → 220 Ω resistor → GPIO 25
* Cathode → GND

### Pin Configuration

```text
Red LED       → GPIO 32
Yellow LED    → GPIO 33
Green LED     → GPIO 25

HC-SR04 TRIG  → GPIO 19
HC-SR04 ECHO  → GPIO 18
```

---

## Applications

* Smart traffic light prototypes
* Vehicle detection systems
* Smart city applications
* Embedded systems practice
* IoT-based traffic management
* Traffic signal automation
* Educational demonstrations

---

## Future Improvements

* Add multiple HC-SR04 sensors for improved traffic detection
* Implement actual **vehicle counting**
* Add an I2C LCD/OLED display
* Implement multiple traffic lanes
* Calculate traffic density
* Dynamically adjust signal timing based on traffic density
* Add pedestrian crossing control
* Add emergency vehicle detection
* Use ESP32 Wi-Fi for remote traffic monitoring
* Use ESP32-CAM for camera-based vehicle detection
* Develop a web-based traffic monitoring dashboard
* Replace `delay()` with `millis()` for non-blocking operation

## Author 
Subramanian R 
