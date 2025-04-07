# Wi-Fi Training Program – Module 3 Assignment 

---

### 1. Different 802.11 PHY Layer Standards & Comparison

| Standard | Frequency | Max Data Rate | Modulation | Bandwidth | Year Introduced |
|----------|-----------|---------------|------------|-----------|-----------------|
| 802.11a | 5 GHz | 54 Mbps | OFDM | 20 MHz | 1999 |
| 802.11b | 2.4 GHz | 11 Mbps | DSSS | 22 MHz | 1999 |
| 802.11g | 2.4 GHz | 54 Mbps | OFDM | 20 MHz | 2003 |
| 802.11n | 2.4/5 GHz | 600 Mbps | OFDM + MIMO | 20/40 MHz | 2009 |
| 802.11ac | 5 GHz | 6.9 Gbps | OFDM + MU-MIMO | 20/40/80/160 MHz | 2013 |
| 802.11ax (Wi-Fi 6) | 2.4/5 GHz | ~9.6 Gbps | OFDMA + MU-MIMO | 20/40/80/160 MHz | 2019 |
| 802.11be (Wi-Fi 7) | 2.4/5/6 GHz | >30 Gbps | OFDMA + 4096-QAM | 20–320 MHz | 2024 (planned) |

---

### 2. DSSS and FHSS – Working Principles

- **DSSS (Direct Sequence Spread Spectrum):**
  - Data is spread over a wider frequency band using pseudo-random noise (PN) code.
  - Reduces interference and increases signal robustness.
  - Used in 802.11b.

- **FHSS (Frequency Hopping Spread Spectrum):**
  - Signal rapidly hops between different frequencies based on a sequence.
  - More resistant to narrowband interference.
  - Used in early 802.11 standards (not commonly used now).

### Comparison:
| Feature | DSSS | FHSS |
|--------|------|------|
| Interference Resistance | High | Very High |
| Complexity | Moderate | High |
| Speed | Moderate | Low |
| Usage | 802.11b | Legacy standards |

---

### 3. Modulation Schemes in PHY Layer

Modulation schemes convert digital signals into analog for wireless transmission.

### Common Schemes:
- **BPSK (Binary Phase Shift Keying)** – 1 bit/symbol
- **QPSK (Quadrature Phase Shift Keying)** – 2 bits/symbol
- **16-QAM (Quadrature Amplitude Modulation)** – 4 bits/symbol
- **64-QAM, 256-QAM, 1024-QAM** – Higher bits/symbol, better efficiency

### Performance Comparison:
| Modulation | Bits/Symbol | Data Rate | Noise Tolerance |
|------------|-------------|-----------|-----------------|
| BPSK | 1 | Low | High |
| QPSK | 2 | Medium | Medium |
| 16-QAM | 4 | High | Low |
| 64-QAM | 6 | Very High | Lower |
| 256-QAM | 8 | Very High | Lower |

---

### 4. Significance of OFDM in WLAN

**OFDM (Orthogonal Frequency Division Multiplexing):**
- Divides a signal into multiple subcarriers.
- Each subcarrier is modulated separately.
- Used in 802.11a/g/n/ac/ax.

### Benefits:
- Resistant to multipath fading
- High spectral efficiency
- Lower inter-symbol interference
- Enables higher data rates

---

### 5. Frequency Bands and Channel Division in Wi-Fi

| Band | Frequency Range | Common Use |
|------|------------------|-------------|
| 2.4 GHz | 2.400–2.4835 GHz | Legacy, IoT |
| 5 GHz | 5.150–5.850 GHz | High-speed Wi-Fi |
| 6 GHz (Wi-Fi 6E/7) | 5.925–7.125 GHz | Low congestion, future use |

### Channel Details:
- **2.4 GHz:** 3 non-overlapping channels (1, 6, 11)
- **5 GHz:** Up to 24 non-overlapping channels
- **6 GHz:** Up to 59 non-overlapping 20 MHz channels

---

### 6. Guard Intervals in WLAN

**Guard Interval (GI):** Time buffer between symbol transmissions to avoid interference due to multipath.

| GI Type | Duration | Benefit |
|---------|----------|---------|
| Normal | 800 ns | Better reliability |
| Short GI | 400 ns | Increased throughput (~10% gain) |

**Use Case for Short GI:**
- Environments with minimal multipath reflections (e.g., open office)

---

### 7. 802.11 PHY Frame Structure

**802.11 PHY Frame Components:**
- **Preamble:** Synchronization between sender and receiver
- **PLCP Header (Physical Layer Convergence Protocol):** Contains frame length, modulation, coding rate
- **PSDU (Physical Layer Service Data Unit):** Actual data from MAC layer

### Frame Format (Simplified):
```
| Preamble | PLCP Header | PSDU |
```

---

### 8. OFDM vs OFDMA

| Feature | OFDM | OFDMA |
|---------|------|--------|
| Used In | 802.11a/g/n/ac | 802.11ax (Wi-Fi 6) |
| Transmission | One user per time slot | Multiple users simultaneously |
| Efficiency | Lower in dense networks | Higher in dense networks |
| Uplink Support | No | Yes |

---

### 9. MIMO vs MU-MIMO

| Feature | MIMO | MU-MIMO |
|--------|------|---------|
| Stands For | Multiple Input Multiple Output | Multi-User MIMO |
| Description | One user uses multiple streams | Multiple users use streams concurrently |
| Introduced In | 802.11n | 802.11ac (downlink), 802.11ax (uplink + downlink) |
| Efficiency | High for individual devices | High for overall network |

---

### 10. PPDU, PLCP, and PMD

- **PPDU (PLCP Protocol Data Unit):** The complete physical layer frame transmitted over the air
- **PLCP (Physical Layer Convergence Protocol):** Adds preamble and header to PSDU
- **PMD (Physical Medium Dependent):** Handles modulation/demodulation and RF transmission

---

### 11. Types of PPDU and Frame Formats

| Wi-Fi Generation | PPDU Type |
|------------------|-----------|
| 802.11a/g | OFDM PPDU |
| 802.11b | DSSS/HR-DSSS PPDU |
| 802.11n | HT-Mixed, HT-Greenfield |
| 802.11ac | VHT PPDU |
| 802.11ax | HE-SU, HE-MU, HE-Trigger |
| 802.11be | EHT PPDU (Enhanced High Throughput) |

**Frame Structure (Generic):**
```
| L-STF | L-LTF | L-SIG | HT-SIG | HT-STF | HT-LTF | Data |
```

---

### 12. Data Rate Calculation

**Formula:**
```
Data Rate = (Number of subcarriers) × (Bits per symbol) × (Symbol rate) × (Coding rate) × (Number of spatial streams)
```

### Factors Affecting Data Rate:
- Modulation scheme (BPSK → 1024-QAM)
- Channel bandwidth (20, 40, 80, 160 MHz)
- Guard interval (800 ns vs 400 ns)
- Number of spatial streams (MIMO)
- Coding rate (e.g., 1/2, 3/4)

---