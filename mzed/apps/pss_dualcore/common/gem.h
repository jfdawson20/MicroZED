#ifndef GEM_J_H
#define GEM_J_H

//include base addr stuff
#include "xparameters_ps.h"
#include "xil_io.h"

//api returns 
#define GEM_API_SUCCESS 0
#define GEM_API_FAILURE -1

//GEM register map 
#define XEMACPS_NWCTRL_OFFSET        0x00000000 /**< Network Control reg */
#define XEMACPS_NWCFG_OFFSET         0x00000004 /**< Network Config reg */
#define XEMACPS_NWSR_OFFSET          0x00000008 /**< Network Status reg */

#define XEMACPS_DMACR_OFFSET         0x00000010 /**< DMA Control reg */
#define XEMACPS_TXSR_OFFSET          0x00000014 /**< TX Status reg */
#define XEMACPS_RXQBASE_OFFSET       0x00000018 /**< RX Q Base address reg */
#define XEMACPS_TXQBASE_OFFSET       0x0000001C /**< TX Q Base address reg */
#define XEMACPS_RXSR_OFFSET          0x00000020 /**< RX Status reg */

#define XEMACPS_ISR_OFFSET           0x00000024 /**< Interrupt Status reg */
#define XEMACPS_IER_OFFSET           0x00000028 /**< Interrupt Enable reg */
#define XEMACPS_IDR_OFFSET           0x0000002C /**< Interrupt Disable reg */
#define XEMACPS_IMR_OFFSET           0x00000030 /**< Interrupt Mask reg */

#define XEMACPS_PHYMNTNC_OFFSET      0x00000034 /**< Phy Maintaince reg */
#define XEMACPS_RXPAUSE_OFFSET       0x00000038 /**< RX Pause Time reg */
#define XEMACPS_TXPAUSE_OFFSET       0x0000003C /**< TX Pause Time reg */

#define XEMACPS_HASHL_OFFSET         0x00000080 /**< Hash Low address reg */
#define XEMACPS_HASHH_OFFSET         0x00000084 /**< Hash High address reg */

#define XEMACPS_LADDR1L_OFFSET       0x00000088 /**< Specific1 addr low reg */
#define XEMACPS_LADDR1H_OFFSET       0x0000008C /**< Specific1 addr high reg */
#define XEMACPS_LADDR2L_OFFSET       0x00000090 /**< Specific2 addr low reg */
#define XEMACPS_LADDR2H_OFFSET       0x00000094 /**< Specific2 addr high reg */
#define XEMACPS_LADDR3L_OFFSET       0x00000098 /**< Specific3 addr low reg */
#define XEMACPS_LADDR3H_OFFSET       0x0000009C /**< Specific3 addr high reg */
#define XEMACPS_LADDR4L_OFFSET       0x000000A0 /**< Specific4 addr low reg */
#define XEMACPS_LADDR4H_OFFSET       0x000000A4 /**< Specific4 addr high reg */

#define XEMACPS_MATCH1_OFFSET        0x000000A8 /**< Type ID1 Match reg */
#define XEMACPS_MATCH2_OFFSET        0x000000AC /**< Type ID2 Match reg */
#define XEMACPS_MATCH3_OFFSET        0x000000B0 /**< Type ID3 Match reg */
#define XEMACPS_MATCH4_OFFSET        0x000000B4 /**< Type ID4 Match reg */

#define XEMACPS_STRETCH_OFFSET       0x000000BC /**< IPG Stretch reg */

#define XEMACPS_OCTTXL_OFFSET        0x00000100 /**< Octects transmitted Low
                                                      reg */
#define XEMACPS_OCTTXH_OFFSET        0x00000104 /**< Octects transmitted High
                                                      reg */

#define XEMACPS_TXCNT_OFFSET         0x00000108 /**< Error-free Frmaes
                                                      transmitted counter */
#define XEMACPS_TXBCCNT_OFFSET       0x0000010C /**< Error-free Broadcast
                                                      Frames counter*/
#define XEMACPS_TXMCCNT_OFFSET       0x00000110 /**< Error-free Multicast
                                                      Frame counter */
#define XEMACPS_TXPAUSECNT_OFFSET    0x00000114 /**< Pause Frames Transmitted
                                                      Counter */
#define XEMACPS_TX64CNT_OFFSET       0x00000118 /**< Error-free 64 byte Frames
                                                      Transmitted counter */
#define XEMACPS_TX65CNT_OFFSET       0x0000011C /**< Error-free 65-127 byte
                                                      Frames Transmitted
                                                      counter */
#define XEMACPS_TX128CNT_OFFSET      0x00000120 /**< Error-free 128-255 byte
                                                      Frames Transmitted
                                                      counter*/
#define XEMACPS_TX256CNT_OFFSET      0x00000124 /**< Error-free 256-511 byte
                                                      Frames transmitted
                                                      counter */
#define XEMACPS_TX512CNT_OFFSET      0x00000128 /**< Error-free 512-1023 byte
                                                      Frames transmitted
                                                      counter */
#define XEMACPS_TX1024CNT_OFFSET     0x0000012C /**< Error-free 1024-1518 byte
                                                      Frames transmitted
                                                      counter */
#define XEMACPS_TX1519CNT_OFFSET     0x00000130 /**< Error-free larger than
                                                      1519 byte Frames
                                                      transmitted counter */
#define XEMACPS_TXURUNCNT_OFFSET     0x00000134 /**< TX under run error
                                                      counter */

#define XEMACPS_SNGLCOLLCNT_OFFSET   0x00000138 /**< Single Collision Frame
                                                      Counter */
#define XEMACPS_MULTICOLLCNT_OFFSET  0x0000013C /**< Multiple Collision Frame
                                                      Counter */
#define XEMACPS_EXCESSCOLLCNT_OFFSET 0x00000140 /**< Excessive Collision Frame
                                                      Counter */
#define XEMACPS_LATECOLLCNT_OFFSET   0x00000144 /**< Late Collision Frame
                                                      Counter */
#define XEMACPS_TXDEFERCNT_OFFSET    0x00000148 /**< Deferred Transmission
                                                      Frame Counter */
#define XEMACPS_TXCSENSECNT_OFFSET   0x0000014C /**< Transmit Carrier Sense
                                                      Error Counter */

#define XEMACPS_OCTRXL_OFFSET        0x00000150 /**< Octects Received register
                                                      Low */
#define XEMACPS_OCTRXH_OFFSET        0x00000154 /**< Octects Received register
                                                      High */

#define XEMACPS_RXCNT_OFFSET         0x00000158 /**< Error-free Frames
                                                      Received Counter */
#define XEMACPS_RXBROADCNT_OFFSET    0x0000015C /**< Error-free Broadcast
                                                      Frames Received Counter */
#define XEMACPS_RXMULTICNT_OFFSET    0x00000160 /**< Error-free Multicast
                                                      Frames Received Counter */
#define XEMACPS_RXPAUSECNT_OFFSET    0x00000164 /**< Pause Frames
                                                      Received Counter */
#define XEMACPS_RX64CNT_OFFSET       0x00000168 /**< Error-free 64 byte Frames
                                                      Received Counter */
#define XEMACPS_RX65CNT_OFFSET       0x0000016C /**< Error-free 65-127 byte
                                                      Frames Received Counter */
#define XEMACPS_RX128CNT_OFFSET      0x00000170 /**< Error-free 128-255 byte
                                                      Frames Received Counter */
#define XEMACPS_RX256CNT_OFFSET      0x00000174 /**< Error-free 256-512 byte
                                                      Frames Received Counter */
#define XEMACPS_RX512CNT_OFFSET      0x00000178 /**< Error-free 512-1023 byte
                                                      Frames Received Counter */
#define XEMACPS_RX1024CNT_OFFSET     0x0000017C /**< Error-free 1024-1518 byte
                                                      Frames Received Counter */
#define XEMACPS_RX1519CNT_OFFSET     0x00000180 /**< Error-free 1519-max byte
                                                      Frames Received Counter */
#define XEMACPS_RXUNDRCNT_OFFSET     0x00000184 /**< Undersize Frames Received
                                                      Counter */
#define XEMACPS_RXOVRCNT_OFFSET      0x00000188 /**< Oversize Frames Received
                                                      Counter */
#define XEMACPS_RXJABCNT_OFFSET      0x0000018C /**< Jabbers Received
                                                      Counter */
#define XEMACPS_RXFCSCNT_OFFSET      0x00000190 /**< Frame Check Sequence
                                                      Error Counter */
#define XEMACPS_RXLENGTHCNT_OFFSET   0x00000194 /**< Length Field Error
                                                      Counter */
#define XEMACPS_RXSYMBCNT_OFFSET     0x00000198 /**< Symbol Error Counter */
#define XEMACPS_RXALIGNCNT_OFFSET    0x0000019C /**< Alignment Error Counter */
#define XEMACPS_RXRESERRCNT_OFFSET   0x000001A0 /**< Receive Resource Error
                                                      Counter */
#define XEMACPS_RXORCNT_OFFSET       0x000001A4 /**< Receive Overrun Counter */
#define XEMACPS_RXIPCCNT_OFFSET      0x000001A8 /**< IP header Checksum Error
                                                      Counter */
#define XEMACPS_RXTCPCCNT_OFFSET     0x000001AC /**< TCP Checksum Error
                                                      Counter */
#define XEMACPS_RXUDPCCNT_OFFSET     0x000001B0 /**< UDP Checksum Error
                                                      Counter */
#define XEMACPS_LAST_OFFSET          0x000001B4 /**< Last statistic counter
						      offset, for clearing */

#define XEMACPS_1588_SEC_OFFSET      0x000001D0 /**< 1588 second counter */
#define XEMACPS_1588_NANOSEC_OFFSET  0x000001D4 /**< 1588 nanosecond counter */
#define XEMACPS_1588_ADJ_OFFSET      0x000001D8 /**< 1588 nanosecond
						      adjustment counter */
#define XEMACPS_1588_INC_OFFSET      0x000001DC /**< 1588 nanosecond
						      increment counter */
#define XEMACPS_PTP_TXSEC_OFFSET     0x000001E0 /**< 1588 PTP transmit second
						      counter */
#define XEMACPS_PTP_TXNANOSEC_OFFSET 0x000001E4 /**< 1588 PTP transmit
						      nanosecond counter */
#define XEMACPS_PTP_RXSEC_OFFSET     0x000001E8 /**< 1588 PTP receive second
						      counter */
#define XEMACPS_PTP_RXNANOSEC_OFFSET 0x000001EC /**< 1588 PTP receive
						      nanosecond counter */
#define XEMACPS_PTPP_TXSEC_OFFSET    0x000001F0 /**< 1588 PTP peer transmit
						      second counter */
#define XEMACPS_PTPP_TXNANOSEC_OFFSET 0x000001F4 /**< 1588 PTP peer transmit
						      nanosecond counter */
#define XEMACPS_PTPP_RXSEC_OFFSET    0x000001F8 /**< 1588 PTP peer receive
						      second counter */
#define XEMACPS_PTPP_RXNANOSEC_OFFSET 0x000001FC /**< 1588 PTP peer receive
						      nanosecond counter */

                              
//function protos 

int32 GEMControllerInit(int32 base);
int32

#endif
