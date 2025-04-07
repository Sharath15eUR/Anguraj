# Wi-Fi Training Program – Module 2 Assignment

## 1. SplitMAC Architecture and AP Performance

**SplitMAC** is a Wi-Fi architecture approach where the 802.11 MAC layer is split between the Access Point (AP) and the Wireless LAN Controller (WLC).

### Key Functions Split Between AP and WLC:
- **AP Responsibilities (Real-time MAC Functions):**
  - Beacon generation and transmission
  - Acknowledgment of frames
  - RTS/CTS handling
  - Encryption/decryption of data frames
  - Fragmentation and reassembly

- **WLC Responsibilities (Management MAC Functions):**
  - Client authentication and association
  - Roaming management and decision-making
  - Applying QoS and ACL policies
  - Radio Resource Management (RRM)
  - Load balancing
  - Firmware and configuration management

### Benefits to AP Performance:
- Reduces processing load on AP hardware
- Enables use of lightweight APs with minimal firmware
- Centralizes control, making APs easier to manage
- Improves scalability and network consistency
- Simplifies network policy enforcement

---

## 2. CAPWAP Protocol and Flow Between AP & Controller

**CAPWAP (Control and Provisioning of Wireless Access Points)** is defined by the IETF (RFC 5415) to standardize the communication between a WLC and multiple lightweight APs.

### Main Goals:
- Abstract the AP hardware and standardize control
- Provide secure and reliable communication between AP and controller
- Enable plug-and-play AP deployment

### Communication Flow (Step-by-step):
1. **AP Bootup:** Sends DHCP request to get IP address.
2. **Discovery Phase:**
   - AP sends CAPWAP Discovery Request (broadcast/multicast or directed)
   - WLC responds with Discovery Response
3. **Join Phase:**
   - AP sends CAPWAP Join Request to selected WLC
   - WLC authenticates and replies with Join Response
4. **Configuration Phase:**
   - AP receives image upgrade if necessary
   - AP downloads configuration parameters from WLC
5. **Operational Phase:**
   - CAPWAP control and data tunnels established
   - AP starts broadcasting SSIDs and handling client data

---

## 3. CAPWAP in OSI Model & Tunnel Types

### OSI Layer Mapping:
- **Layer 2 (Data Link Layer):**
  - CAPWAP can operate using L2 tunneling when no IP infrastructure is present
- **Layer 3 (Network Layer):**
  - Most common; CAPWAP uses UDP over IP for communication

### Tunnel Types:
1. **Control Tunnel:**
   - Uses UDP port 5246
   - Exchanges management messages (AP join, config, keep-alives)
   - Encrypted with DTLS for security

2. **Data Tunnel:**
   - Uses UDP port 5247
   - Carries encapsulated 802.11 data frames from clients
   - Optional encryption based on deployment needs

### Purpose:
- Separate data from control traffic
- Improve scalability and troubleshooting
- Secure and centralized AP management

---

## 4. Lightweight APs vs Cloud-based APs

### Lightweight APs:
- Controlled by on-premises WLC
- Require constant CAPWAP tunnel to function
- Cannot function autonomously without WLC (except FlexConnect mode)
- Suitable for centralized campus deployments

### Cloud-based APs:
- Managed via cloud controller (Meraki, Aruba Central, etc.)
- APs connect to cloud using secure HTTPS tunnels
- Easier deployment in distributed environments
- Automatically receive updates and policies from the cloud
- Suitable for branch offices, retail chains, and SMBs

| Feature | Lightweight AP | Cloud-based AP |
|--------|----------------|----------------|
| Controller | On-premises | Cloud-hosted |
| Management | Centralized (local) | Centralized (cloud) |
| Scalability | Moderate | High |
| Deployment | IT-intensive | Plug-and-play |
| Updates | Manual or WLC-driven | Cloud-driven |
| Ideal For | Enterprises, campuses | Branches, SMBs |

---

## 5. CAPWAP Tunnel Maintenance

- **Keepalive Messages:** Sent periodically (every 30 seconds by default) to maintain the control tunnel
- **DTLS Encryption:** Ensures control traffic integrity and confidentiality
- **WLC Monitoring:** Detects if an AP becomes unresponsive and takes recovery actions
- **Failover Capability:** If configured, AP can switch to a secondary WLC

### CAPWAP Session States:
1. **Discovery** – AP locates WLCs
2. **Join** – AP sends join request
3. **Configure** – WLC pushes config to AP
4. **Operational** – AP is active and forwarding traffic
5. **Image Download** – If AP needs a new image

---

## 6. Sniffer Mode vs Monitor Mode

| Mode | Function | Use Case |
|------|----------|----------|
| Sniffer Mode | Captures and forwards raw 802.11 frames to packet analyzer (e.g., Wireshark) | In-depth packet-level analysis |
| Monitor Mode | AP passively listens to RF spectrum on all channels | Detect rogue APs, RF analysis, WIDS/WIPS |

### Sniffer Mode:
- Needs a wired connection to send captured packets to analyzer
- Used for troubleshooting client connectivity or protocol issues

### Monitor Mode:
- AP does not serve clients
- Continuously scans environment for threats and interference
- Used in security audits and compliance

---

## 7. Best AP Mode for Local Network When WLC is in WAN

### Best Mode: **FlexConnect (HREAP)**

### Features:
- Allows AP to locally switch client data traffic
- Control traffic still goes to WLC over WAN
- Supports backup RADIUS server for authentication
- Enables minimal downtime during WAN outages

### Behavior During WAN Failure:
- **Authentication:** Cached credentials can be used (if pre-auth is enabled)
- **Roaming:** Still possible between APs in the same FlexConnect group
- **Data Traffic:** Continues to be switched locally

---

## 8. Challenges with Deploying >50 Autonomous APs

- **Scalability Issues:** Hard to configure and manage each AP manually
- **Lack of Central Control:** No unified policy or firmware distribution
- **Inconsistent SSIDs and Security Policies:** Risk of misconfigurations
- **Roaming Problems:** No fast handoff or client load balancing
- **High Maintenance:** Firmware upgrades and troubleshooting are time-consuming
- **Monitoring Gaps:** No consolidated logging, alerts, or dashboard
- **Inefficient Spectrum Usage:** No coordinated channel and power adjustment

**Conclusion:** Autonomous APs are not ideal for large enterprise or campus networks. Controller-based or cloud-managed solutions provide better scalability and efficiency.

---

## 9. Impact if WLC Goes Down (Lightweight AP in Local Mode)

- **Client Sessions:** Existing sessions may remain active temporarily, but new sessions cannot be authenticated
- **New Associations:** Not possible without WLC (unless FlexConnect with local auth is enabled)
- **Management Tasks:** AP cannot receive config updates or be monitored
- **Data Traffic:** Will be dropped unless AP supports local switching (FlexConnect)

### Mitigation Strategies:
- Use **FlexConnect** mode with local authentication fallback
- Configure **secondary/backup WLCs** with priority
- Ensure APs are grouped into **FlexConnect groups** for roaming and resilience

---