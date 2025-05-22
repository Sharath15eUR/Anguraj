## Module 6 - Wi-Fi Security

### 1. **Pillars of Wi-Fi Security**

Wi-Fi security is fundamentally based on three core principles that work together to ensure safe and reliable wireless communication:

* **Authentication**: This is the mechanism by which a device or user proves their identity before gaining access to the network. Authentication helps prevent unauthorized users from connecting to the Wi-Fi network. It ensures that only devices with the correct credentials (such as a pre-shared key or certificate) can connect.

* **Confidentiality**: Often referred to as encryption in technical discussions, confidentiality is about protecting the privacy of the data being transmitted. It ensures that even if someone intercepts the wireless signal, they cannot make sense of the data without the proper decryption keys. Confidentiality is crucial to prevent eavesdropping and data theft.

* **Integrity**: Integrity mechanisms ensure that the data sent over the Wi-Fi network arrives at its destination unchanged. This helps protect against tampering or corruption during transmission. Integrity checks (such as Message Integrity Code - MIC) detect alterations to packets, making it harder for attackers to inject or modify data without detection.

---

### 2. **Authentication vs Confidentiality in Wi-Fi Security**

These two concepts, while related, serve different roles in securing a wireless network:

* **Authentication** is the process of confirming the identity of the devices or users trying to connect to the Wi-Fi network. It acts as a gatekeeper, ensuring that only trusted entities are granted access. This might involve entering a password, using digital certificates, or undergoing a handshake protocol.

* **Confidentiality** (often implemented through encryption) focuses on keeping the data private. Once a device is authenticated, confidentiality ensures that the communication between the device and the access point is shielded from unauthorized observers. Encrypted data cannot be easily read or understood by attackers, even if they manage to capture it.

Together, authentication and confidentiality form a foundational layer of wireless security—one validating access, the other protecting communication.

---

### 3. **Differences between WEP, WPA, WPA2, and WPA3**

Wi-Fi security standards have evolved over time to address growing threats and vulnerabilities. Here's a comparative overview of the four main security protocols:

| Standard | Features                                                                                                          | Security Level |
| -------- | ----------------------------------------------------------------------------------------------------------------- | -------------- |
| **WEP**  | Uses RC4 encryption with static keys and weak IV management                                                       | Very Low       |
| **WPA**  | Introduced TKIP, supports dynamic key generation                                                                  | Moderate       |
| **WPA2** | Implements AES encryption, uses CCMP for integrity checks                                                         | High           |
| **WPA3** | Uses Simultaneous Authentication of Equals (SAE), 192-bit encryption, and enhanced protection for public networks | Very High      |

Each protocol builds on its predecessor, improving both the strength of encryption and the robustness of authentication and integrity mechanisms.

---

### 4. **Why WEP is Considered Insecure**

Wired Equivalent Privacy (WEP) was the original security algorithm for Wi-Fi networks but is now considered highly insecure for several reasons:

* **Static keys**: WEP uses the same encryption key for every session, which makes it easier for attackers to guess the key through repeated packet captures.
* **Weak encryption algorithm**: WEP relies on the RC4 stream cipher with poor key management and implementation flaws that are exploitable.
* **Vulnerable to attacks**: There are publicly available tools that can break WEP encryption within minutes, even by capturing a small number of packets.
* **No proper integrity checks**: WEP's checksum-based integrity mechanism is insufficient to detect packet modifications, leaving the network exposed to tampering.

Due to these significant weaknesses, WEP is obsolete and should not be used in any modern network.

---

### 5. **Why WPA2 was Introduced**

WPA2 was introduced as a long-term solution to the shortcomings of WEP and the interim WPA standard. Its design focuses on providing enterprise-grade security with improved encryption and data protection features:

* **Stronger encryption with AES**: WPA2 replaces RC4 and TKIP with the Advanced Encryption Standard (AES), which is more secure and widely trusted across the cybersecurity industry.
* **CCMP for integrity**: The Counter Mode with Cipher Block Chaining Message Authentication Code Protocol (CCMP) ensures that data has not been altered during transmission.
* **Enhanced authentication**: WPA2 supports enterprise-level authentication methods such as EAP (Extensible Authentication Protocol), allowing integration with RADIUS servers and certificate-based access control.
* **Widespread compatibility**: WPA2 became a mandatory certification for Wi-Fi devices, ensuring that both home and business users had access to strong, standardized security.

WPA2 remains the most widely adopted Wi-Fi security standard today, although WPA3 is gradually being adopted for enhanced protection in modern networks.

---
### 6. Role of Pairwise Master Key (PMK) in the 4-Way Handshake

The Pairwise Master Key (PMK) is a fundamental component in the Wi-Fi security framework, particularly during the 4-Way Handshake process. It acts as a shared secret between the client (STA) and the Access Point (AP) after the initial authentication phase.

In personal Wi-Fi networks (WPA/WPA2-Personal), the PMK is derived from the Pre-Shared Key (PSK) provided by the user. In enterprise networks (WPA/WPA2-Enterprise), it is generated through the 802.1X authentication process using credentials such as usernames and passwords, or certificates.

Once derived, the PMK is not used directly for encryption. Instead, it serves as the base for generating other session-specific keys, particularly the Pairwise Transient Key (PTK), which is used to encrypt and protect unicast traffic between the client and the AP. The beauty of this approach is that the actual PMK is never transmitted over the air, reducing the risk of interception or leakage.

This layered approach to key management ensures a robust and secure framework where the compromise of a session key does not expose the master key or affect other sessions.

---

### 7. How 4-Way Handshake Ensures Mutual Authentication

The 4-Way Handshake is a mechanism defined in the IEEE 802.11i standard that ensures both the Wi-Fi client and the Access Point can authenticate each other without actually transmitting the PMK. This mutual authentication is vital to establishing a secure communication channel.

Here’s how the process works in detail:

1. **Nonce Exchange**: The Access Point generates a random number called the ANonce and sends it to the client. The client responds with its own random number called the SNonce.

2. **Key Generation**: Both the AP and the client use the PMK, along with the ANonce and SNonce, and their MAC addresses to derive a Pairwise Transient Key (PTK). Since both sides have all the same inputs, they derive the same PTK independently.

3. **Message Integrity Check**: Each handshake message includes a Message Integrity Code (MIC), which is calculated using the PTK. If any message is tampered with or if the PTK does not match, the MIC verification fails, and the handshake is terminated.

This ensures that both devices genuinely possess the PMK and prevents attackers from injecting or modifying messages without detection. By confirming each other's identities in this cryptographic manner, both the client and AP establish a secure and trusted session.

---

### 8. Effect of Wrong Passphrase during 4-Way Handshake

When a Wi-Fi client attempts to connect to a network with an incorrect passphrase, the 4-Way Handshake fails, and the connection is not established. Here's a breakdown of why that happens:

* **Incorrect PMK**: The wrong passphrase leads to the derivation of an incorrect PMK on the client side.
* **Mismatched PTK**: Since the PMK is one of the primary inputs for generating the PTK, the client and AP derive different PTKs.
* **MIC Verification Failure**: When the handshake messages are exchanged, the Message Integrity Code (MIC) calculated by each party will not match, resulting in a failed authentication attempt.

This failure acts as a safeguard. Even if an attacker tries to guess the passphrase, they cannot complete the handshake without producing a correct MIC, thus preventing unauthorized access to the network.

---

### 9. Problem Solved by 802.1X in a Network

802.1X is a standard that solves the issue of unauthorized access to both wired and wireless networks by enforcing port-based access control. It ensures that only authenticated and authorized devices can access the network.

Here's what it addresses:

* **Unauthorized Access**: Without 802.1X, any device within range can attempt to connect to a network, increasing the risk of intrusion.
* **User Identity Verification**: 802.1X requires users to authenticate through a centralized server (typically RADIUS), verifying their credentials before allowing network access.
* **Role-Based Access Control**: Based on authentication results, users can be granted different levels of network access.

This approach is especially critical in enterprise environments, where sensitive data and internal systems must be protected from unauthorized devices or users.

---

### 10. How 802.1X Enhances Security over Wireless Networks

802.1X significantly improves the security posture of wireless networks by implementing a dynamic and centralized authentication system. Here are the ways it enhances network security:

1. **Strong Authentication via EAP**: 802.1X supports various Extensible Authentication Protocol (EAP) methods such as EAP-TLS (using digital certificates), EAP-PEAP, and EAP-TTLS. These provide strong and flexible authentication mechanisms suited for different organizational needs.

2. **Dynamic Key Generation**: Unlike static PSK systems, 802.1X enables the dynamic generation of encryption keys for each session. This minimizes the risk of key reuse and ensures that even if one session is compromised, others remain secure.

3. **Centralized User Management**: Integration with RADIUS servers allows for centralized policy enforcement and user authentication, simplifying access control and auditing.

4. **Minimized Attack Surface**: By requiring user authentication before granting network access, 802.1X prevents rogue devices from accessing or scanning the network.

5. **Seamless Roaming**: In enterprise deployments with multiple access points, 802.1X allows for secure and seamless handoffs as clients move between APs without re-authentication interruptions.

Overall, 802.1X transforms a wireless network into a managed, authenticated environment that meets the high security standards required by corporations, educational institutions, and government agencies.

---
