#!/usr/bin/python
import os
import argparse
import sys 

parser = argparse.ArgumentParser(description='Powerapp Parsing Utility')
parser.add_argument('-s','--sourcefile', help='Source powerapp output file', required=True)

args     = vars(parser.parse_args())
filename = args['sourcefile']

with open(filename) as f:
    lines = f.readlines()
   
dict = {"B.4":["AXI_HP",1,0x00000000],
        "B.5":["CAN",2, 0xE0008000,0xE0009000],
        "B.6":["DDR",1,0xF8006000],
        "B.7":["CTI",4,0xF8898000,0xF8899000,0xF9902000,0xF8809000],
        "B.8":["PMU",2,0xF8891000,0xF8893000],
        "B.9":["PTM",2,0xF889C000,0xF889D000],
        "B.10":["DAP",1,0xF8800000],
        "B.11":["ETB",1,0xF8801000],
        "B.12":["FTM",1,0xF880B000],
        "B.13":["FUNNEL",1,0xF8804000],
        "B.14":["CITM",1,0xF8805000],
        "B.15":["TPIU",1,0xF8803000],
        "B.16":["DEVCFG",1,0xF8007000],
        "B.17":["DMAC",2,0xF8004000,0xF8003000],
        "B.18":["GEM",2,0xE000B000,0xE000C000],
        "B.19":["GPIO",1,0xE000A000],
        "B.20":["QOS301",3,0xF8946000,0xF8947000,0xF8948000],
        "B.21":["NIC301",1,0xF8900000],
        "B.22":["I2C",2,0xE0004000,0xE00050000],
        "B.23":["L2CACHE",1,0xF8F02000],
        "B.24":["APU",1,0xF8F00000],
        "B.25":["OCM",1,0xF800C000],
        "B.26":["QSPI",1,0xE000D000],
        "B.27":["SDIO",2,0xE0100000,0xE0101000],
        "B.28":["SLCR",1,0xF8000000],
        "B.29":["PL353",1,0xE000E000],
        "B.30":["SPI",1,0xE0006000,0xE0007000],
        "B.31":["SWDT",1,0xF8005000],
        "B.32":["TTC",2,0xF8001000,0xF8002000],
        "B.33":["UART",2,0xE0000000,0xE0001000],
        "B.34":["USB",0xE0002000,0xE0003000]}

newSection = 0
for l in lines:
	if(newSection == 1):
		x = l.split()
		if (len(x) >2):
			print "Register: " + x[0] + "  address: " + x[1]
		else:
			newSection = -1
 
	if (l[0:2].find("B.") != -1):    
        	print dict[l[0:4].strip()]

	if (l.find("Register Name  Address  Width  Type  Reset Value  Description") != -1):
		newSection = 1




