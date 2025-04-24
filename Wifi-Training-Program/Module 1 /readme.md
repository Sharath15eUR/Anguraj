# Module 1 - Assignment 

## Question 1 : In Which OSI Layer Does the Wi-Fi Standard/Protocol Fit?

Wi-Fi, which is defined by the **IEEE 802.11 standard**, primarily operates at **two layers** of the OSI (Open Systems Interconnection) model:

### **1. Physical Layer (Layer 1)**
At this layer, Wi-Fi is responsible for transmitting raw data over radio waves. The key functions include:
- **Modulation and Encoding** – Converts digital data into radio signals for wireless transmission.
- **Frequency Bands** – Operates in **2.4 GHz, 5 GHz, and 6 GHz** frequency ranges.
- **Signal Strength and Interference Handling** – Manages transmission power and interference from other wireless devices.
- **Wireless Transmission Techniques** – Uses technologies like **OFDM (Orthogonal Frequency-Division Multiplexing)** and **DSSS (Direct Sequence Spread Spectrum)** for reliable data transfer.

### **2. Data Link Layer (Layer 2)**
Wi-Fi functions at the **Data Link Layer**, specifically in the **MAC (Medium Access Control) sublayer**. The key responsibilities here include:
- **Media Access Control** – Uses **CSMA/CA (Carrier Sense Multiple Access with Collision Avoidance)** to manage access to the shared wireless medium and prevent data collisions.
- **Frame Formation and Transmission** – Divides data into frames and ensures they are correctly sent and received.
- **Error Detection and Retransmission** – Implements **ACK (Acknowledgment) frames** and **Automatic Repeat reQuest (ARQ)** for error control.
- **Security Mechanisms** – Supports encryption and authentication methods like **WPA2, WPA3, and WEP**.


While Wi-Fi itself is defined at **Layers 1 and 2**, it enables higher-layer protocols such as:
- **IP (Internet Protocol) at Layer 3** – Facilitates routing over wireless networks.
- **TCP/UDP (Transport Layer at Layer 4)** – Manages reliable/unreliable communication over Wi-Fi.

Wi-Fi primarily operates at:
- **Layer 1 (Physical Layer)** – Handles radio signal transmission and modulation.
- **Layer 2 (Data Link Layer, MAC Sublayer)** – Manages media access, error detection, and wireless security.

Thus, Wi-Fi plays a critical role in **wireless communication at both the Physical and Data Link layers** of the OSI model.

---

## Question 2 : Can you share the Wi-Fi devices that you are using day to day life, share that device's wireless capability/properties after connecting to network. Match your device to corresponding Wi-Fi Generations based on properties

### Device Wi-Fi Capabilities and Generations

| Device               | Wireless Adapter/Chipset  | Frequency Band | Wi-Fi Standard       | Max Speed (Mbps) | Wi-Fi Generation |
|----------------------|-------------------------|---------------|----------------------|------------------|-----------------|
| **Oppo Reno 6**     | Wi-Fi 6 (802.11ax)       | 2.4 GHz, 5 GHz | 802.11a/b/g/n/ac/ax  | Up to 9.6 Gbps   | Wi-Fi 6         |
| **Mi Router 4A**    | 2.4 GHz: 2x2 MIMO, 5 GHz: 2x2 MIMO | 2.4 GHz, 5 GHz | 802.11n (2.4 GHz), 802.11ac (5 GHz) | 300 Mbps (2.4 GHz), 867 Mbps (5 GHz) | Wi-Fi 4 (2.4 GHz), Wi-Fi 5 (5 GHz) |
| **Mi Router 4C**    | 2.4 GHz: 2x2 MIMO        | 2.4 GHz       | 802.11b/g/n          | Up to 300 Mbps   | Wi-Fi 4         |
| **Asus TUF F15 (10th Gen i5)** | Intel Wi-Fi 6 AX201 | 2.4 GHz, 5 GHz | 802.11a/b/g/n/ac/ax  | Up to 2.4 Gbps   | Wi-Fi 6         |
| **ESP32**           | Integrated Wi-Fi transceiver | 2.4 GHz | 802.11b/g/n          | Up to 150 Mbps   | Wi-Fi 4         |
| **Samsung Flip TV** | Wi-Fi 5 (varies by model) | 2.4 GHz, 5 GHz | 802.11a/b/g/n/ac     | Up to 1.3 Gbps   | Wi-Fi 5         |

---

## Question 3: What is BSS and ESS?

### **Basic Service Set (BSS) vs. Extended Service Set (ESS)**

| Feature          | **BSS (Basic Service Set)**                          | **ESS (Extended Service Set)**                     |
|-----------------|----------------------------------------------------|--------------------------------------------------|
| **Definition**  | A single access point (AP) and its connected devices. | Multiple BSS units connected to form a larger network. |
| **Number of APs** | One AP                                            | Multiple APs                                   |
| **Coverage Area** | Small (Limited to the range of a single AP)       | Large (Covers multiple APs' combined range)    |
| **Roaming Support** | Not supported (devices stay within one AP range) | Supported (seamless transition between APs)    |
| **Communication** | Devices communicate directly with a single AP.    | Devices can switch between APs while staying connected. |
| **Network Type** | Used in home Wi-Fi, small office networks.         | Used in large enterprises, universities, airports, etc. |
| **Identifier**   | Identified by a **BSSID** (AP’s MAC address).      | Uses multiple **BSSIDs** under a common **SSID**. |
| **Example**      | A home Wi-Fi router with connected devices.        | A campus Wi-Fi network with multiple APs providing continuous coverage. |


- **BSS** is a single access point and its connected devices, suitable for small networks.  
- **ESS** is a group of multiple BSS units, providing larger coverage and seamless connectivity.  

---

## Question 4: What are the Basic Functionalities of a Wi-Fi Access Point?

A **Wi-Fi Access Point (AP)** is a networking device that allows wireless devices to connect to a wired network. It serves as a **bridge** between wired Ethernet networks and wireless clients, enabling seamless communication.A **Wi-Fi Access Point** plays a crucial role in wireless networking by enabling devices to connect, managing security, optimizing network traffic, and providing seamless connectivity in both small and large-scale deployments.

### **Basic Functionalities of a Wi-Fi Access Point**

| Functionality        | Description |
|----------------------|-------------|
| **Wireless Signal Transmission** | Transmits and receives Wi-Fi signals, allowing wireless devices to connect to the network. |
| **SSID Broadcasting** | Advertises the **Service Set Identifier (SSID)**, allowing users to discover and connect to the network. |
| **Authentication & Security** | Supports security protocols such as **WPA2, WPA3**, and **802.1X authentication** to prevent unauthorized access. |
| **Traffic Management** | Manages data flow between connected devices and the wired network to optimize performance. |
| **Multiple Device Connectivity** | Supports multiple wireless clients simultaneously using **MIMO (Multiple-Input Multiple-Output)** technology. |
| **Frequency Band Support** | Operates on **2.4 GHz, 5 GHz, and 6 GHz** bands depending on the Wi-Fi standard (Wi-Fi 4, 5, 6, 6E). |
| **Roaming Support** | In an **Extended Service Set (ESS)**, allows devices to switch between APs without disconnecting. |
| **QoS (Quality of Service)** | Prioritizes certain types of traffic (e.g., video streaming, VoIP) for better performance. |
| **Wired Network Integration** | Connects to a router or switch via **Ethernet** to enable internet and network access. |
| **Power over Ethernet (PoE) Support** | Some APs can receive power through **Ethernet cables**, eliminating the need for a separate power source. |
| **Guest Network Creation** | Allows setting up a separate network for guests to improve security and limit access. |
| **Mesh Networking** | Some APs support **mesh Wi-Fi**, allowing multiple APs to extend network coverage seamlessly. |

---

## Question 5: Difference Between Bridge Mode and Repeater Mode

Both **Bridge Mode** and **Repeater Mode** are used to extend network connectivity, but they function differently.

### **1. Bridge Mode**
Bridge mode allows two or more **separate networks** to communicate with each other by **connecting them over a wired or wireless link**.

- **Functionality:**
  - Connects two **different networks** (e.g., wired and wireless).
  - Operates at the **Data Link Layer (Layer 2)** of the OSI model.
  - Devices in one network can communicate with devices in the other network **without changing their IP addresses**.
  - Commonly used in large-scale **enterprise networks**.

- **Example:**
  - Connecting a wired network in **Building A** to a Wi-Fi network in **Building B** using a wireless bridge.

---

### **2. Repeater Mode**
Repeater mode **extends the range** of an existing Wi-Fi network by receiving, amplifying, and retransmitting the signal.

- **Functionality:**
  - Expands Wi-Fi coverage by rebroadcasting the existing signal.
  - Creates a **single network** where all devices use the same SSID.
  - May introduce **latency** since it processes and retransmits data.
  - Commonly used in **home networks** to eliminate Wi-Fi dead zones.

- **Example:**
  - Using a **Wi-Fi range extender** to improve signal strength in a large house.

---

### **Key Differences:**

| Feature           | **Bridge Mode**                                         | **Repeater Mode**                                    |
|------------------|------------------------------------------------------|--------------------------------------------------|
| **Purpose**     | Connects two separate networks.                        | Extends the range of an existing Wi-Fi network. |
| **Operation**   | Works at **Layer 2 (Data Link Layer)**.                 | Works at **Layer 1 (Physical Layer)**.          |
| **Network Type** | Connects **two different networks**.                   | Extends **one single network**.                 |
| **IP Addressing** | Networks retain their **own IP ranges**.             | All devices stay in the **same IP range**.      |
| **Performance**  | No signal loss; provides **direct network bridging**. | May reduce speed due to **retransmission delays**. |
| **Usage**       | Used in enterprises, industrial setups.                | Used in homes, small offices to eliminate Wi-Fi dead zones. |
| **Example**      | Connecting two office networks in different buildings. | Using a repeater to boost Wi-Fi in a large home. |


- **Bridge Mode** is for connecting **two separate networks** efficiently.  
- **Repeater Mode** is for **extending Wi-Fi coverage** by amplifying and retransmitting signals.  

---
## Question 6: Differences Between 802.1 LAN (802.1x) and 802.11b

Both **802.1x** and **802.11b** are IEEE standards, but they serve different purposes in networking.

### **1. IEEE 802.1x (Wired & Wireless Authentication Protocol)**
### **2. IEEE 802.11b (Wi-Fi Standard)**

### **Key Differences:**

| Feature          | **802.1x (LAN Authentication)**                        | **802.11b (Wi-Fi Standard)**                   |
|-----------------|--------------------------------------------------------|-----------------------------------------------|
| **Purpose**     | Secure **authentication mechanism** for network access. | Wireless communication standard for Wi-Fi.  |
| **Layer**       | Works at **Layer 2 (Data Link Layer)**.                 | Works at **Layer 1 (Physical Layer)**.      |
| **Application** | Used in **wired & wireless networks** for authentication. | Defines **Wi-Fi transmission** in the 2.4 GHz band. |
| **Security**    | Provides **user authentication & access control**.      | **No built-in authentication**, relies on additional security (e.g., WEP, WPA). |
| **Data Speed**  | Not related to speed, used for authentication only.     | **Up to 11 Mbps** (very slow by modern standards). |
| **Frequency Band** | Not frequency-specific.                              | Uses **2.4 GHz** frequency. |
| **Example Usage** | Enterprise networks with **WPA2-Enterprise** security. | Early home and office Wi-Fi networks. |


- **802.1x** is an **authentication framework** for secure network access.  
- **802.11b** is an **early Wi-Fi standard** defining wireless communication at **11 Mbps in the 2.4 GHz band**.  

---

## Question 7 : Configure your modem/hotspot to operate only in 2.4Ghz and connect your laptop/ Wi-Fi device, and capture the capability/properties in your Wi-Fi device. Repeat the same in 5Ghz and tabulate all the differences you observed during this

# Wi-Fi Band Comparison: 2.4 GHz vs 5 GHz

Captured on Wi-Fi network: **Anguraj**  
Device used: Smartphone  

| **Parameter**         | **2.4 GHz (Image 2 - 10:58)** | **5 GHz (Image 1 - 10:59)**   | **Remarks** |
|-----------------------|-------------------------------|-------------------------------|-------------|
| **Signal Strength**   | -30 dB (Excellent)            | -40 dB (Excellent)            | 2.4 GHz usually penetrates walls better, hence stronger signal. |
| **Link Speed**        | 130 Mbps                      | 390 Mbps                      | 5 GHz offers higher speeds but shorter range. |
| **MAC Address**       | aa:f9:64:54:32:60 (Random)    | aa:f9:64:54:32:60 (Random)    | Same MAC (randomized). |
| **IPv4 Address**      | 192.168.137.213               | 192.168.137.213               | Same; indicates no change in DHCP lease or interface. |
| **Security**          | WPA/WPA2-Personal             | WPA/WPA2-Personal             | Same encryption protocol. |

---

> **Note:** Device was configured to auto-connect and had the same IP & MAC addresses in both configurations. Performance difference is mainly due to the frequency band characteristics.
#### Output:
![Output Image](screenshots/7_1.jpeg)

![Output Image](screenshots/7_2.jpeg)

---

## Question 8: What is the Difference Between IEEE and WFA?

### **1. IEEE (Institute of Electrical and Electronics Engineers)**
- **Definition:**  
  - A **professional organization** that develops global **technical standards** for various industries, including networking and telecommunications.
- **Role in Wi-Fi:**  
  - Defines the **802.11 standards** (Wi-Fi protocols) such as **802.11a, 802.11b, 802.11n, 802.11ax (Wi-Fi 6)**.
  - Focuses on **technical specifications, protocols, and interoperability**.
- **Example Contribution:**  
  - IEEE **802.3 (Ethernet)**, IEEE **802.11 (Wi-Fi)**, IEEE **802.1x (Authentication protocol)**.

---

### **2. WFA (Wi-Fi Alliance)**
- **Definition:**  
  - A **non-profit industry consortium** that **certifies** Wi-Fi products for compatibility, performance, and security.
- **Role in Wi-Fi:**  
  - Ensures devices from different manufacturers **work together seamlessly**.
  - Develops **Wi-Fi branding** (e.g., **Wi-Fi 4, Wi-Fi 5, Wi-Fi 6**).
  - Introduces **security and performance enhancements** (e.g., WPA2, WPA3).
- **Example Contribution:**  
  - **Wi-Fi CERTIFIED™ program**, **Wi-Fi Direct**, **Passpoint**, **WPA3 security standard**.

---

### **Key Differences:**

| Feature            | **IEEE (Institute of Electrical and Electronics Engineers)** | **WFA (Wi-Fi Alliance)** |
|-------------------|-------------------------------------------------------------|--------------------------|
| **Purpose**      | Develops **technical standards** for networking and communication. | **Certifies** Wi-Fi products for interoperability. |
| **Focus Area**   | Defines **Wi-Fi protocols (802.11 standards)**. | Ensures **Wi-Fi devices are compatible and secure**. |
| **Membership**   | Open to researchers, engineers, and industry professionals. | Includes **companies** like Intel, Cisco, Qualcomm, etc. |
| **Wi-Fi Involvement** | Creates the **802.11 Wi-Fi standards**. | **Certifies** Wi-Fi products and introduces Wi-Fi branding. |
| **Security Role** | Defines authentication mechanisms like **802.1x**. | Develops **Wi-Fi security protocols (e.g., WPA2, WPA3)**. |
| **Branding**     | No branding – just technical standards. | Creates **Wi-Fi branding (Wi-Fi 4, 5, 6, etc.)**. |
| **Example Contribution** | **802.11ax (Wi-Fi 6)** standard definition. | **Wi-Fi 6 certification program**, **WPA3 encryption**. |

---

## Question 9: Types of Wi-Fi Internet Connectivity Backhaul

### **What is Backhaul?**
A **backhaul** is the network connection that links the **Wi-Fi access points (APs)** to the main internet service provider (ISP) or core network.

### **Types of Wi-Fi Backhaul Connections**

| Backhaul Type        | Description |
|----------------------|-------------|
| **Fiber Optic Backhaul** | Uses **fiber-optic cables** for high-speed, low-latency internet connectivity. Common in **enterprise networks and 5G backhaul**. |
| **Ethernet Backhaul** | Connects Wi-Fi access points via **wired Ethernet cables** for stable, high-speed connections. Used in **homes, offices, and businesses**. |
| **Wireless Backhaul (PtP/PtMP)** | Uses **microwave, millimeter-wave, or Wi-Fi links** to connect APs without physical cables. Used in **rural and large outdoor deployments**. |
| **Cellular (4G/5G) Backhaul** | Uses **LTE/5G networks** to provide Wi-Fi connectivity where wired connections are unavailable. Common in **remote areas and mobile hotspots**. |
| **Satellite Backhaul** | Provides internet via satellites, useful for **rural and remote locations** with no wired infrastructure. Higher latency compared to fiber. |
| **Power Line Communication (PLC) Backhaul** | Uses **electrical power lines** for network data transmission. Less common but useful in **industrial environments**. |

---

### **Your Home/College Wi-Fi Backhaul**

| Location  | Backhaul Type       | Provider/Technology | Speed (Mbps) | Latency |
|-----------|--------------------|---------------------|--------------|---------|
| **Home**  | **Fiber Optic**    |  ACT Fibernet | 100-1000 Mbps | Low (1-5ms) |
| **College** | **Ethernet/Fiber** | BSNL  | 100-500 Mbps | Low (5-10ms) |

---

## Question 10: Wi-Fi Topologies and Their Use Cases  

### **What is Wi-Fi Topology?**  
Wi-Fi topology refers to the **network structure** and how devices connect to each other and the internet.  

### **Types of Wi-Fi Topologies and Their Use Cases**  

| **Wi-Fi Topology**   | **Description** | **Use Cases** |
|----------------------|----------------|---------------|
| **Infrastructure Mode** | Devices connect to a **central Access Point (AP)**, which manages communication and connects to the internet. | - Home and office Wi-Fi networks.<br>- Public Wi-Fi (cafes, airports). |
| **Ad-hoc Mode (Peer-to-Peer)** | Devices communicate **directly** with each other **without** an access point. | - Temporary networks (file sharing, gaming).<br>- Device-to-device communication. |
| **Mesh Wi-Fi** | Multiple access points (APs) work together to create a **seamless network**, improving coverage and reliability. | - Large homes and offices.<br>- Smart city and IoT deployments.<br>- Campus-wide Wi-Fi. |
| **Wi-Fi Direct** | Allows two Wi-Fi-enabled devices to connect **without** an access point, similar to Bluetooth. | - Wireless printing.<br>- File sharing between phones and laptops. |
| **Hotspot (Tethering)** | A mobile device or router shares its **internet connection** over Wi-Fi. | - Mobile hotspots.<br>- Temporary Wi-Fi access for travel. |
| **Wireless Distribution System (WDS)** | Extends Wi-Fi networks using multiple APs **without cables**, maintaining a single SSID. | - Expanding Wi-Fi in large buildings.<br>- Campus and warehouse networks. |
| **Extender/Repeater Mode** | Wi-Fi extenders **boost** existing signals to reach dead zones. | - Homes with weak Wi-Fi spots.<br>- Extending Wi-Fi in offices. |

---


- **Infrastructure Mode** is the most common for **homes and businesses**.  
- **Mesh Wi-Fi** provides the best coverage for **large areas**.  
- **Ad-hoc and Wi-Fi Direct** are great for **device-to-device** communication.  
- **Hotspots and WDS** help in **expanding networks where cabling isn’t feasible**.  

--- 

