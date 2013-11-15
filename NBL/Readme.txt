Subject: Readme file for NBL MIB AutoChecker
Author: Elia Chen
Version: 2007-0131

1. Preparation (before the test)

  1.1 Install net-snmp suite in your test PC platform
  1.2 Please prepare the files of MIB definitions (which is written in ASN.1)
      in the path 'C:\usr\share\snmp\mibs' to cover the objects under test

      Ex. to test MIB-2 group, you have to prepare "RFC1213-MIB.txt"

2. Execution Procedure

  2.1 Connect the test PC to the DUT (device under test)
  2.2 Edit the configuration file 'nblmib.ini'
  2.3 Run 'nblmib.exe' to start the test and it will call 'nblmib_report.exe'
      (or other program specified in 'REPORTER') to generate the report
