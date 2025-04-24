## Module 4 - MAC Layer in Wi-Fi

### 1. **Significance of MAC Layer & Its Position in OSI Model**
The Medium Access Control (MAC) layer plays a crucial role in wireless communication by managing how data is transmitted between devices over the shared wireless medium.

- **OSI Model Placement**: The MAC layer is a sublayer of the Data Link Layer, which is the second layer in the OSI model.
- **Significance**:
  - Facilitates channel access coordination using techniques like CSMA/CA.
  - Manages addressing using MAC addresses for local delivery.
  - Controls frame formatting, sequencing, and error detection.
  - Plays a role in security mechanisms (e.g., key exchange in WPA2).
  - Enables power saving, retransmissions, and data fragmentation.

---

### 2. **Frame Format of the 802.11 MAC Header**
The 802.11 MAC header defines the structure of data frames for reliable wireless communication.

**Frame Format Fields**:
- **Frame Control (2 bytes)**: Indicates type (management, control, data), and subtype.
- **Duration/ID (2 bytes)**: NAV setup or association ID.
- **Address Fields (6 bytes each)**:
  - Address 1: Receiver
  - Address 2: Transmitter
  - Address 3: Filtering (BSSID/AP)
  - Address 4 (optional): For WDS
- **Sequence Control (2 bytes)**: Manages fragmentation and reassembly.
- **QoS Control (optional)**: For Quality of Service frames.
- **HT Control (optional)**: Used in high throughput (802.11n) networks.

**Purpose**:
Each field ensures proper frame routing, acknowledgment, and processing by receiver devices.

---

### 3. **MAC Layer Functionalities**

#### a. **Management Plane**
- Beaconing
- Authentication/Deauthentication
- Association/Reassociation
- Scanning (Active/Passive)
- Disassociation

#### b. **Control Plane**
- RTS/CTS exchange (collision avoidance)
- ACK for reliability
- PS-Poll (Power Save Poll)
- CF-End (PCF mode)

#### c. **Data Plane**
- Frame delivery (unicast, multicast, broadcast)
- Fragmentation and reassembly
- Error checking (FCS/CRC)
- MAC addressing and sequence control

---

### 4. **Scanning Process and Its Types**
Scanning allows a client device to discover available access points (APs).

- **Passive Scanning**:
  - Device listens for beacon frames on different channels.
  - No frame transmission by the client.

- **Active Scanning**:
  - Device sends probe requests to APs.
  - Waits for probe responses.

**Steps**:
1. Switch channel.
2. Listen (passive) or send probe (active).
3. Collect and store responses/beacons.
4. Compile network list.

---

### 5. **Client Association Process**
Establishes a connection between a Wi-Fi client and an AP.

1. **Scanning**: Detect available APs.
2. **Authentication**: Open or Shared Key.
3. **Association Request**: Client requests to join the AP.
4. **Association Response**: AP confirms connection.

Optional: Security negotiation via EAPOL handshake.

---

### 6. **EAPOL 4-Way Handshake**
Used in WPA2 security to establish encryption keys between client and AP.

#### Steps:
1. **Message 1**: AP → Client: Sends ANonce.
2. **Message 2**: Client → AP: Sends SNonce and MIC (with PTK).
3. **Message 3**: AP → Client: Sends GTK and MIC.
4. **Message 4**: Client → AP: Confirms receipt.

#### Derived Keys:
- **PMK (Pairwise Master Key)**: Pre-shared or derived from 802.1X.
- **PTK (Pairwise Transient Key)**: Used for unicast encryption.
- **GTK (Group Temporal Key)**: Used for multicast/broadcast encryption.

---

### 7. **Power Saving Scheme in MAC Layer**
Power saving is essential in mobile devices for battery efficiency.

#### Mechanisms:
- **Legacy PS (PS-Poll)**:
  - STA enters sleep mode.
  - Wakes up periodically to check AP beacons.
  - Requests buffered frames via PS-Poll.

- **U-APSD (Unscheduled Automatic Power Save Delivery)**:
  - Triggered delivery of frames.
  - Suitable for voice/video traffic.

- **TWT (Target Wake Time)**:
  - Defined in 802.11ax.
  - Devices agree on wake times for transmissions.

---

### 8. **Medium Access Control Methodologies**

- **DCF (Distributed Coordination Function)**:
  - CSMA/CA based.
  - Devices wait for the medium to be idle, then transmit.

- **PCF (Point Coordination Function)**:
  - AP controls medium access via polling.
  - Provides contention-free periods.

- **EDCA (Enhanced Distributed Channel Access)**:
  - Used in 802.11e for QoS.
  - Different traffic types get different access priorities.

---

### 9. **Block ACK Mechanism**

- **Purpose**: Acknowledge multiple data frames together.
- **How it works**:
  - Sender sends a burst of frames.
  - Receiver sends one Block ACK indicating received frames.

**Advantages**:
- Reduces ACK overhead.
- Improves throughput in high-bandwidth scenarios.
- Efficient for video and data streaming.

---

### 10. **A-MSDU, A-MPDU, and A-MSDU in A-MPDU**

- **A-MSDU (Aggregate MAC Service Data Unit)**:
  - Aggregates multiple MSDUs into a single MPDU.
  - Reduces header overhead.

- **A-MPDU (Aggregate MAC Protocol Data Unit)**:
  - Aggregates multiple MPDUs.
  - Each MPDU has its own MAC header and CRC.
  - More resilient to errors.

- **A-MSDU in A-MPDU**:
  - Combines both methods.
  - Each MPDU in an A-MPDU can be an A-MSDU.
  - Provides best trade-off between overhead and reliability.

---


