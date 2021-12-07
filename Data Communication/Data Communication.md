# Data Communication

- Overview
- Protocol Architecture
- Data Transmission
- Transmission Media
- Signal Encoding Techniques
- Digital Data Communication Techniques
    - Asynchronous and Synchronous Transmission
        
        → timing problems require a mechanism to synchronize the transmitter and receiver.
        
        - receiver samples stream at bit intervals
        - if clocks are not not precissely aligned, drifting(data bit drift) will sample at wrong time after sufficient bits are sent.
        
        → two possible solutions for synchronizing clocks
        
        - Asynchronous transmission
            
            → Avoids timing problems by not sending long, uninterrupted streams of bits
            
            → Data are transmitted one character at a time
            
            - Each character is 5 to 8 bits in length
            - receiver has the opportunity to resynchronize at the beginning of each new character
            
            → Simple and cheap
            
            - Requires overhead of 2 or 3 bits per character
            
            → The larger the block of bits, the greater the cumulative timing error (synchronous transmission can fix the error)
            
            → good for data with large gaps (ex. keyboard)
            
            ![Untitled](Data%20Communication%205e17d8ab9d17423db87f671d88d54a07/Untitled.png)
            
        - Synchronous transmission
            
            → A block of bits is transmitted in a steady stream without start and stop codes.
            
            → Clocks must be synchronized to prevent drift
            
            - Can use separate clock line
            - Embed clock signal in data
            
            → need to indicate start and end of block
            
            → use preamble and postamble bit patterns
            
            → frame is data + preamble + postamble + control information
            
            → more efficient than asynchronous for large blocks of data
            
            ![Untitled](Data%20Communication%205e17d8ab9d17423db87f671d88d54a07/Untitled%201.png)
            
    - Types of Error
        - An error occurs when a bit is altered between transmission and reception
            - Binary 1 is transmitted and binary 0 is received (or opposite)
        - Single bit errors
            - isolated error that alters one bit but not nearby bits
            - caused by white noise
        - Burst errors
            - contiguous sequence of B bits where first and last bits and any number of intermediate bits are received in error
            - caused by impulse noise or by fading in wireless
            - effects greater at higher data rates. → as bandwidth grows error rate grows
    - Error Detection
        - Regardless of design errors might appear
        - Can detect errors by using error-detecting code added by transmitter
            - code is also referred to as check bits (included in transmitted bits)
        - Recalculated and checked by receiver
        - Still chance of undetected error
        - Parity
            - Parity bit set to character has even or odd number of ones
            - Even number of bit errors goes undetected
        - Error Detection Process
        
        ![Untitled](Data%20Communication%205e17d8ab9d17423db87f671d88d54a07/Untitled%202.png)
        
    - Parity Check
        - Simplest error detecting scheme is to append a parity bit to the end of block of data
            - even parity - even number of 1s
                - used for synchronous transmissino
            - odd parity- odd number of 1s
                - used for asynchronous transmissino
        - If any even number of bits are inverted due to error, and undetected error occurs
    - Cyclic Redundancy Check (CRC)
        - One of most common and powerful checks
        - For block of k bits transmitter generates an n bit frame check sequence (FCS)
        - transmits (k + n) bits which is exactly divisible by some predetermined number
        - receiver divides frame by that number
            - if no remainder, assume no error
    - Error Correction
        - Correction of detected errors usually requires data block to be retransmitted → ARQ (Automatic Repeat Request)
        - Not appropriate for wireless applications
            - Bit error rate is high causing lots of retransmissions
            - Propagation delay long(ex. satellite) compared with frame transmission time, resulting in retransmission of frame in error + many subsequent frames
        - Need to correct errors on basis of bits received
        - Codeword
            - On the transmission end, each k-bit block of data is mapped into an n-bit block (n > k) using a forward error correction (FEC → correction at reciever) encoder
        - Error Correction Process
        
        ![Untitled](Data%20Communication%205e17d8ab9d17423db87f671d88d54a07/Untitled%203.png)
        
        - How Error Correction Works
            - Adds redundancy(중복성) to transmitted message
                - Redundancy makes it possible to deduce original message despite some errors
            - (n - k) / k = redundancy
            - k / n = code rate
            - Block error correction code
                - map k-bit input onto an n-bit codeword
                - each codeword is unique
                - if invalid codeword is received, assume input codeword is the valid codeword closest to received codeword
    - Line Configuration
        - Topology
            - Topology
                - refers to the physical arrangement of stations
            - Point to Point → Two stations
                - such as between two routers/ computers
            - Multi Point → Multiple Stations
                - traditionally mainframe computer and terminals
                - now typically a local area network (LAN)
            
            ![Untitled](Data%20Communication%205e17d8ab9d17423db87f671d88d54a07/Untitled%204.png)
            
        - Duplex
            - Data exchanges classificed as half or full duplex
            - Half duplex (two-way alternate)
                - only one station may transmit at a time
                - requires one data path
            - Full duplex (two-way simultaneous)
                - simultaneous transmission and reception between two stations
                - requires two data paths
                    - separate media or frequencies used for each direction
- Data Link Control Protocols
    - What is Data Link Control Protocols
        - When sending data to archieve control, a layer of logic is added above the Physical layer
            - Data link control or a data link control protocol
        - To manage exchange of data over a link
            - Frame Synchronization
            - Flow Control
            - Error Control
            - Addressing
            - Control and Data
            - Link Management
    - Flow Control
        - Ensure sending entity does not overwhelm receiving entity
            - prevent buffer overflow
        - Influence via transmission time
            - time taken to emit(방출) all bits into medium
        - Influence via propagation time
            - time for a bit to traverse(횡단) the linik
        - Assumption is all frames are successfully received with no frames lost or arrving with errors (still suffers from delay)
        
        ![Untitled](Data%20Communication%205e17d8ab9d17423db87f671d88d54a07/Untitled%205.png)
        
    - Flow Control : Stop and Wait
        - Simplest form of flow control
            - Not effective when fast transmission
        - Works well for message sent in a few large frames
            - Stop and wait becomes inadequate when large block of data is split into small frames
        - source transmits frame → destination receives frame and replies with ACK → source waits for ACK before sending → destination can stop flow by not sending ACK
        
        ![Untitled](Data%20Communication%205e17d8ab9d17423db87f671d88d54a07/Untitled%206.png)
        
    - Flow Control : Sliding Windows
        - Allows multiple numbered frames to be in transit
            - Receiver has buffer W long
            - Transmitter sends up to W frames without ACK
            - ACK includes number of next frame expected
            - Sequence number is bounded by size of field (k)
                - frames are numbered modulo 2$^k$
                - giving max window size of up to 2$^k$ - 1
            - Receiver can ACK frames without permitting further transmission (Receive Not Ready) → piggyback
            - Must send a normal ACK to resume
        - If have full-duplex link, can piggyback ACKs.
        - much more efficieint by sending multiple frames at one time
        - Sliding Window Diagram
        
        ![Untitled](Data%20Communication%205e17d8ab9d17423db87f671d88d54a07/Untitled%207.png)
        
        - Sliding Window Example
        
        ![Untitled](Data%20Communication%205e17d8ab9d17423db87f671d88d54a07/Untitled%208.png)
        
    - Error Control Techniques
        - Detection and correction of erros such as
            - lost frames
                - a frame fails to arrive at the other side
            - damaged frames
                - frames arrives but some of the bits are in error
        - Error detection → positive acknowledgement → retransmission after timeout → negative acknowledgement & retransmission
    - Error Control : Automatic Repeat Request(ARQ)
        - Collective name for error control mechanism
        - Effect of ARQ is to turn an unreliable data link into a reliable one
        - Stop and Wait
            - Source transmits single frame
            - Waits for ACK
                - No other data can be sent until destination's reply arrives
            - If frame received is damaged, discard it
                - Transmitter has timeout
                - If no ACK within timeout, retransmit
            - If ACK is damaged, transmitter will not recognize
                - Transmitter will retransmit
                - Receiver gets two copies of frame
                - Use alternate numbering and ACK0 / ACK1
                    - ACK0 → Original
                    - ACK1 → Duplicated Copy
            - Pros → Simplistic
            - Cons → Inefficient (One frame each)
            
            ![Untitled](Data%20Communication%205e17d8ab9d17423db87f671d88d54a07/Untitled%209.png)
            
        - Go Back N
            - Most commonly used error control
            - Based on sliding-Window
            - Use window size to control number of outstanding frames
            - If no error → ACK as usual
            - If error → reply with rejection
                - Destination will discard that frame and all future frames until frame in error is received correctly
                - Transmitter must go back and retransmit that frame and all subsequent frames
            - Damaged frame
                - Error in frame *i* so receiver rejects frame *i*
                - Transmitter retransmits frames from *i*
            - Lost frame
                - Frame *i* lost **and either
                    - Transmitter sends *i+1* and receiver gets frame *i+1* out of sequence and rejects frame *i*
                    - Transmitter times out and sends ACK with P (poll that check status)bit set which receiver responds to with ACK *i*
                - Transmitter then retransmits frames from *i* (all the frames from *i*)
            
            ![Untitled](Data%20Communication%205e17d8ab9d17423db87f671d88d54a07/Untitled%2010.png)
            
        - Selective Reject
            - Also called selectvie retransmission
            - Only rejected frames are retransmitted
            - Subsequent frames are accepted by the receiver and buffered
            - Minimizes retransmission
            - Receiver must maintain large enough buffer
            - More complext logic in transmitter
                - Less widely used → go-back is easier
            - Useful for satellite links with long propagation delays
            
            ![Untitled](Data%20Communication%205e17d8ab9d17423db87f671d88d54a07/Untitled%2011.png)
            
    - High Level Data Link Control (HDLC)
        - About HDLC
            - Most important data link control protocol
                - specified as ISO 3009, ISO 4335
                - basis for other data link control protocols
            - Station types:
                - Primary - controls operation of link
                - Secondary - under control of primary station
                - Combined - issues commands and responses
            - Link configuration
                - Unbalanced - 1 primary, multiple secondary → normal
                - Balanced - 2 combined stations → Both full/half duplex → abnormal
        - HDLC Transfer Modes
            - Normal Response Mode (NRM)
                - Used with an unbalanced configuration
                - Primary initiates transfer
            - Asynchronous Balanced Mode (ABM)
                - Used with a balanced configuration
                - Either station initiates transmission
                - Has no polling overhead
                - Most widely used
            - Asynchronous Response Mode (ARM)
                - Used with unbalanced configuration → normal
                - Secondary may transmit without permission from primary
                - Rarely used
        - HDLC Frame Structure
            - Uses synchronous transmission
            - Transmission are in the form of frames
            - Single frame format is used
            
            ![Untitled](Data%20Communication%205e17d8ab9d17423db87f671d88d54a07/Untitled%2012.png)
            
            - Flag Fields and Bit Stuffing
                - Delimit frame at both ends with 01111110
                - Receiver hunts for flag sequence to synchronize
                - Bit stuffing used to avoid confusion with data containing flag sequence 01111110
                    - 0 inserted after every sequence of five 1s
                    - If receiver detects five 1s it checks next bit
                    - If next bit is 0, it is deleted (was stuffed bit)
                    - If next bit is 1 and seventh bit is 0, accepted as flag
                    - If sixth and seventh bits 1, sender is indicating abort
                
                ![Untitled](Data%20Communication%205e17d8ab9d17423db87f671d88d54a07/Untitled%2013.png)
                
            - Address Field
                - Identifies secondary station that transmitted or will receive frame
                - When point to point, address field is not needed
                - Usually 8 bits long
                - May be extended to multiples of 7 bits
                    - Leftmost bit indicates if is the last octet (1) or not (0)
                - Address 11111111 allows primary to broadcast
                
                ![Untitled](Data%20Communication%205e17d8ab9d17423db87f671d88d54a07/Untitled%2014.png)
                
            - Control Field
                - Different frame types
                    - Information - data transmitted to user (next layer up)
                        - Flow and error control piggybacked on information frames
                    - Supervisory - ARQ when piggyback is not used
                    - Unnumbered - supplementary link control functions
                - First 1-2 bits of control field identify frame type
                
                ![Untitled](Data%20Communication%205e17d8ab9d17423db87f671d88d54a07/Untitled%2015.png)
                
                - Use of Poll/Final (P/F) bit depends on context
                - In command frame P bit set to 1 to solicit (poll) response from peer
                - In response frame P bit set to 1 to indicate response to soliciting(간청) command
                - Sequence number usually 3 bits
                    - Can extend to 8 bits
                
                ![Untitled](Data%20Communication%205e17d8ab9d17423db87f671d88d54a07/Untitled%2016.png)
                
            - Information and Frame Check Sequence (FCS) Fields
                - Information Field
                    - In I-Frames and some U-Frames
                    - Must contain integral number of octets
                    - Variable length
                - Frame Check Sequence Field (FCS)
                    - Used for error detection → exclustive of flags
                    - Either 16 bit CRC or 32 bit CRC
        - HDLC Operation
            - Consists of exchange of I-Frames, S-Frames and U-Frames
            - Involves three phases
                - Initialization
                    - Either side may request by issuing one of the six set-mode commands
                - Data Transfer
                    - With flow and error control
                    - Using both I/S Frames (RR, RNR, REJ, SREJ)
                - Disconnect
                    - When fault noted or at request of higher-layer user
                    - Sends a disconnect(DISC) frame
            
            ![Untitled](Data%20Communication%205e17d8ab9d17423db87f671d88d54a07/Untitled%2017.png)
            
            ![Untitled](Data%20Communication%205e17d8ab9d17423db87f671d88d54a07/Untitled%2018.png)
            
- Multiplexing
    - About Multiplexing
        - Multiple link on 1 physical line
        - Common on long-haul, high capacity, links
        - Have FDM, TDM, STDM alternatives
    - Frequency Division Multiplexing (FDM)
        - Sent divided by frequencies
        - Diagram
            
            ![Untitled](Data%20Communication%205e17d8ab9d17423db87f671d88d54a07/Untitled%2019.png)
            
            ![Untitled](Data%20Communication%205e17d8ab9d17423db87f671d88d54a07/Untitled%2020.png)
            
        - Analog Carrier Systems
            - Long-distance links use an FDM hierarchy
            - AT&T (USA) and ITU-T (International) variants
            - Group
                - 12 voice channels (4kHz each) = 48kHz
                - range 60kHz to 108kHz
            - Supergroup
                - FDM of 5 group signals supports 60 channels
                - Carriers between 420kHz and 612kHz
            - Mastergroup
                - FDM of 10 supergroups supports 600 channels
            - Original signal can be modulated many times
        - Wavelength Division Multiplexing (WDM)
            - Multiple beams of light at different frequencies
            - Carried over optical fiber links
                - Commerical systems with 160 channels of 10 Gbps
                - Lab demo of 256 channels 39.8 Gbps
            - Architecture similar to other FDM systems
                - Multiplexer consolidates(통합) laser sources for transmission over single fiber
                - Optical amplifiers amplify all wavelengths
                - Demultiplexer separates channels at destination
            - Dense Wavelength Division Multiplexing (DWDM)
                - Use of more channels more closely spaced
    - Synchronous Time Division Multiplexing
        - Diagram
            
            ![Untitled](Data%20Communication%205e17d8ab9d17423db87f671d88d54a07/Untitled%2021.png)
            
        - TDM Link Control
            - No headers and trailers
            - Data link control protocols not needed
            - Flow Control
                - Data rate of multiplexed line is fixed
                - If one channel receiver can not receive data, the others must carry on
                - Corresponding source must be quenched (꺼지다)
                - Leaving empty slots
            - Error Control
                - Errors detected & handled on didividual channel
            
            ![Untitled](Data%20Communication%205e17d8ab9d17423db87f671d88d54a07/Untitled%2022.png)
            
        - Framing
            - No flag or SYNC chars bracketing TDM frames
            - Must still provide synchronizing mechanism between source and destination clokcs
            - Added digit framing is most common
                - One control bit added to each TDM frame
                - Identifiable bit pattern used as control channel
                - Alternating pattern 101010..unlikely to be sustained on a data channel
                - Receivers compare incoming bits of frame position to the expected pattern
        - Pulse Stuffing
            
            → Common Solution
            
            - Have outgoing data rate (excluding framing bits) higher than sum of incoming rates
            - Stuff extra dummy bits or pulses into each incoming signal until it matches local clock
            - Stuffed pulses inserted at fixed locations in frame and removed at demultiplexer
            - Problem of synchronizing various data sources
            - Variation among clokcs could cause loss of synchronization
            - Issue of data rates from different sources not related by a simple rational number
- Spread Spectrum
- Circuit / Packet Switching
- ATM
- Routing